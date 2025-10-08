from __future__ import annotations

import builtins
import dataclasses
import json
import os
import random
import re
import signal
import subprocess
from collections import deque
from dataclasses import dataclass
from datetime import datetime
from decimal import Decimal
from functools import partial
from itertools import chain, cycle
from pathlib import Path
from types import ModuleType
from typing import Literal

import cocotb
import dacite
from alive_progress import alive_it
from cocotb.handle import HierarchyObject, ModifiableObject
from cocotb.runner import get_runner
from cocotb.triggers import Timer, RisingEdge

import coverage
from coverage import Coverage, CoverageSizeError, Coverpoint, Cross


@dataclass(frozen=True)
class Params:
    duv: Path
    top_level: str
    coverage_snippets: list[str]
    seed: int | None
    clock_limit: int
    coverage_step: int
    reset_probability: float = 0.01


@dataclass(frozen=True)
class _Params:
    duv: Path
    result: Path
    coverage: Path
    top_level: str
    seed: int | None
    clock_limit: int
    coverage_step: int
    reset_probability: float = 0.1

    def to_env(self) -> dict[str, str]:
        seed = {"TB_SEED": str(self.seed)} if self.seed is not None else {}
        return {
            "TB_DUV": str(self.duv),
            "TB_RES": str(self.result),
            "TB_COV": str(self.coverage),
            "TB_TOP": self.top_level,
            "TB_CLOCK_LIM": str(self.clock_limit),
            "TB_COV_STEP": str(self.coverage_step),
            "TB_RST_PROB": str(self.reset_probability),
        } | seed

    @classmethod
    def from_env(cls) -> _Params:
        seed = int(os.environ["TB_SEED"]) if "TB_SEED" in os.environ else None
        return _Params(
            duv=Path(os.environ["TB_DUV"]),
            result=Path(os.environ["TB_RES"]),
            coverage=Path(os.environ["TB_COV"]),
            top_level=os.environ["TB_TOP"],
            seed=seed,
            clock_limit=int(os.environ["TB_CLOCK_LIM"]),
            coverage_step=int(os.environ["TB_COV_STEP"]),
            reset_probability=float(os.environ["TB_RST_PROB"]),
        )


@dataclass(frozen=True)
class Ports:
    sizes: list[tuple[str, int]]
    clock_port: str | Literal["not found"]
    reset_port: str | Literal["not found"]
    reset_n_port: str | Literal["not found"]
    stimulated_ports: list[str]


@dataclass(frozen=True)
class CoverageInfo:
    timestamp: int
    statement: float
    functional: float


@dataclass(frozen=True)
class Result:
    ports: Ports
    coverage: list[CoverageInfo] | CoverageError
    status: list[CoverageError | Literal["ok"]]

    def save(self, data_file: Path) -> None:
        def deque_default(obj: object) -> object:
            if isinstance(obj, deque):
                return list(obj)
            raise TypeError

        data_file.write_text(
            json.dumps(dataclasses.asdict(self), default=deque_default)
        )

    @classmethod
    def load(cls, data_file: Path) -> Result:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[tuple, deque])
        return dacite.from_dict(Result, data, config)


CLOCK_NAMES = ("clk", "clock")
RESET_NAMES = ("rst", "reset")
RESET_N_NAMES = ("rstn", "rst_n", "rst_neg", "resetn", "reset_n", "reset_neg")
COVERAGE_NAMES = ("COVERAGE_CAPTURE",)


@dataclass(frozen=True)
class _Port:
    name: str
    width: int
    direction: Literal["input", "output", "inout"]
    handle: ModifiableObject


def _find_ports(dut: HierarchyObject, code: Path) -> list[_Port]:
    names = filter(lambda x: not x.startswith("_"), dir(dut))
    objects = filter(
        lambda x: isinstance(x, ModifiableObject), map(partial(getattr, dut), names)
    )

    pattern = re.compile(
        r"\b(input|output|inout)\b"
        r"\s+(?:logic|wire|reg)?"
        r"(?:\s*\[\s*[^\]]*\s*\])?"
        r"\s+(\w+)",
        re.IGNORECASE,
    )
    matches = pattern.findall(code.read_text())
    directions = {port: direction for direction, port in matches}

    return [
        _Port(x._name, int(x.__len__()), directions[x._name], x)
        for x in objects
        if x._name in directions
    ]


def _find_port(ports: list[_Port], names: tuple[str, ...]) -> _Port | None:
    targets = set(chain(names, map(lambda x: x.upper(), names)))
    return next((port for port in ports if port.name in targets), None)


def _set_value(port: _Port | None, value: int) -> None:
    if port is not None:
        port.handle.value = value


CoverageError = Literal["code error", "unknown port", "too large", "timeout"]
CoverageStatus = CoverageError | Literal["ok"]


def _timeout_handler(_arg1, _arg2) -> None:
    raise TimeoutError("Execution timed out!")


def _custom_import(
    name: str,
    globals: dict | None = None,
    locals: dict | None = None,
    fromlist: tuple[str, ...] = (),
    level: int = 0,
) -> ModuleType:
    assert name == "coverage"
    return __import__(name, globals, locals, fromlist, level)


def _load_coverage(
    code_file: Path, port_widths: dict[str, int]
) -> tuple[Coverage, list[CoverageError | Literal["ok"]]]:
    snippets = json.loads(code_file.read_text())

    coverage.register_port_width(lambda x: port_widths[x])
    globals = {"__builtins__": {**builtins.__dict__, "__import__": _custom_import}}
    locals = {}

    coverpoints = []
    crosses = []
    errors = []

    for code in snippets:
        signal.signal(signal.SIGALRM, _timeout_handler)
        try:
            signal.alarm(5)
            exec(code, globals, locals)
            signal.alarm(0)
        except TimeoutError:
            errors.append("timeout")
            continue
        except CoverageSizeError:
            errors.append("too large")
            continue
        except Exception:
            errors.append("code error")
            continue
        finally:
            signal.alarm(0)

        new_coverpoints = [x for x in locals.values() if isinstance(x, Coverpoint)]
        new_crosses = [x for x in locals.values() if isinstance(x, Cross)]
        locals = {}

        names = (x.port for x in new_coverpoints)
        names = chain(names, (x.port for c in new_crosses for b in c.cross for x in b))
        names = list(names)

        if any(name not in port_widths.keys() for name in names):
            errors.append("unknown port")
            continue

        coverpoints += new_coverpoints
        crosses += new_crosses

        errors.append("ok")

    return Coverage(coverpoints, crosses), errors


def run(params: Params) -> Result:
    rood_dir = Path(__file__).parent.resolve()
    tmp_dir = rood_dir / "tmp"
    tmp_dir.mkdir(parents=True, exist_ok=True)
    date = datetime.now().now().strftime("%Y-%m-%d_%H-%S-%f")
    test_dir = tmp_dir / f"test_{params.top_level}_{date}"
    test_dir.mkdir(parents=True, exist_ok=False)
    build_dir = test_dir / "build"

    for var in ("PYTHONPATH", "LD_LIBRARY_PATH"):
        os.environ[var] = f"{rood_dir}:{os.environ.get(var), ''}"

    runner = get_runner("verilator")
    runner.build(
        sources=[params.duv],
        hdl_toplevel=params.top_level,
        build_dir=build_dir,
        always=True,
        clean=True,
        build_args=["--coverage", "-LDFLAGS", f"-L{rood_dir} -ldpi"],
    )

    coverage_file = test_dir / "coverage.json"
    coverage_file.write_text(json.dumps(params.coverage_snippets))
    result_file = test_dir / "result.json"

    _params = _Params(
        duv=params.duv,
        result=result_file,
        coverage=coverage_file,
        top_level=params.top_level,
        seed=params.seed,
        clock_limit=params.clock_limit,
        coverage_step=params.coverage_step,
    )
    runner.test(
        hdl_toplevel=params.top_level,
        test_module="testbench",
        build_dir=build_dir,
        test_dir=test_dir,
        extra_env=_params.to_env(),
    )

    return Result.load(result_file)


def process_line(line: str) -> int | None:
    if line[0:1] not in " %~+-" or "// ignore coverage" in line:
        return None
    line = line[1:]
    hits, _, _ = line.partition(" ")
    return int(hits) if hits.isdecimal() else None


def _statement_coverage(dir: Path) -> float:
    coverage_cmd = [
        "verilator_coverage",
        str(dir / "coverage.dat"),
        "--annotate",
        str(dir / "logs"),
        "--annotate-min",
        "1",
        "--annotate-all",
    ]
    subprocess.run(
        coverage_cmd, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL
    )

    coverage_log = next(x for x in (dir / "logs").iterdir() if x.is_file())
    code_coverage_log = coverage_log.read_text()

    coverage_raw = [process_line(x) for x in code_coverage_log.splitlines()]
    coverage = [x for x in coverage_raw if x is not None]
    return sum(x > 0 for x in coverage) / len(coverage)


async def _generate_clock(clock: _Port) -> None:
    for value in cycle((0, 1)):
        clock.handle.value = value
        await Timer(Decimal(1), units="ns")


@cocotb.test
async def test_module(dut: HierarchyObject) -> None:
    params = _Params.from_env()
    random.seed(params.seed)

    ports = _find_ports(dut, params.duv)
    clock = _find_port(ports, CLOCK_NAMES)

    assert clock is not None
    await cocotb.start(_generate_clock(clock))

    reset = _find_port(ports, RESET_NAMES)
    reset_n = _find_port(ports, RESET_N_NAMES)

    coverage_trigger = _find_port(ports, COVERAGE_NAMES)
    assert coverage_trigger is not None

    ignored = {x and x.name for x in (clock, reset, reset_n, coverage_trigger)}
    input_ports = [x for x in ports if x.direction == "input" and x.name not in ignored]

    ports_info = Ports(
        sizes=[(x.name, x.width) for x in ports],
        clock_port=clock.name,
        reset_port=reset.name if reset else "not found",
        reset_n_port=reset_n.name if reset_n else "not found",
        stimulated_ports=[x.name for x in input_ports],
    )

    _coverage, _status = _load_coverage(
        params.coverage, {x.name: x.width for x in ports}
    )
    coverages = []

    reset_gen = map(lambda x: random.random() < x, cycle((params.reset_probability,)))
    reset_gen = chain((False, True, False), reset_gen)

    for i in alive_it(range(1, params.clock_limit + 1)):
        store_coverage = i % params.coverage_step == 0
        coverage_trigger.handle.value = store_coverage
        should_reset = next(reset_gen)
        _set_value(reset, int(should_reset))
        _set_value(reset_n, not int(should_reset))

        for port in input_ports:
            port.handle.value = random.randint(0, 2**port.width - 1)

        await RisingEdge(clock.handle)

        values = {port.name: int(port.handle.value) for port in ports}
        if (reset is None or reset.handle.value == 0) and (
            reset_n is None or reset_n.handle.value == 1
        ):
            _coverage.sample_all(values)

        if store_coverage:
            statement = _statement_coverage(params.coverage.parent)
            functional = _coverage.percentage()
            coverages.append(
                CoverageInfo(i, statement=statement, functional=functional)
            )

    result = Result(ports_info, coverages, _status)
    result.save(params.result)
