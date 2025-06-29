from __future__ import annotations

import builtins
import dataclasses
import json
from operator import sub
import os
import random
import re
import signal
import subprocess
from collections import deque
from dataclasses import dataclass
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
from cocotb.triggers import Timer, RisingEdge

import coverage
from coverage import Coverage, CoverageSizeError, Coverpoint, Cross

# ─────────────────────────────[ ⚙️  Config  ⚙️ ]─────────────────────────────

@dataclass(frozen=True)
class Config:
    code: Path
    seed: int | None
    clock_limit: int
    cover_step: int
    result_path: Path
    coverage_path: Path
    reset_prob: float = 0.01

    @classmethod
    def load_from_env(cls) -> Config:
        code = Path(os.environ['TB_CODE'])
        coverage = Path(os.environ['TB_COVERAGE'])
        assert code.exists() and coverage.exists()

        seed_str = os.environ.get('TB_SEED')
        seed = int(seed_str) if seed_str is not None else None

        clock_limit = int(os.environ['TB_CLOCK_LIMIT'])
        cover_step = int(os.environ['TB_COVER_STEP'])

        result_path = Path(os.environ['TB_RESULT'])

        return Config(code=code,
                      seed=seed,
                      clock_limit=clock_limit,
                      cover_step=cover_step,
                      result_path=result_path,
                      coverage_path=coverage)


# ──────────────────────────────[ ⚙️  Ports  ⚙️ ]──────────────────────────────

CLOCK_NAMES = ('clk', 'clock')
RESET_NAMES = ('rst', 'reset')
RESET_N_NAMES = ('rstn', 'rst_n', 'rst_neg', 'resetn', 'reset_n', 'reset_neg')
COVERAGE_NAMES = ('COVERAGE_CAPTURE',)


@dataclass(frozen=True)
class _Port:
    name: str
    width: int
    direction: Literal['input', 'output', 'inout']
    handle: ModifiableObject


def _find_ports(dut: HierarchyObject, code: Path) -> list[_Port]:
    names = filter(lambda x: not x.startswith('_'), dir(dut))
    objects =  filter(lambda x: isinstance(x, ModifiableObject),
                      map(partial(getattr, dut), names))

    pattern = re.compile(
        r'\b(input|output|inout)\b'
        r'\s+(?:logic|wire|reg)?'
        r'(?:\s*\[\s*[^\]]*\s*\])?'
        r'\s+(\w+)',
        re.IGNORECASE)
    matches = pattern.findall(code.read_text())
    directions = {port: direction for direction, port in matches}

    return [_Port(x._name, int(x.__len__()), directions[x._name], x)
            for x in objects
            if x._name in directions]


def _find_port(ports: list[_Port], names: tuple[str, ...]) -> _Port | None:
    targets = set(chain(names, map(lambda x: x.upper(), names)))
    return next((port for port in ports if port.name in targets), None)


def _set_value(port: _Port | None, value: int) -> None:
    if port is not None:
        port.handle.value = value


# ────────────────────────────[ ⚙️  Coverage  ⚙️ ]────────────────────────────

@dataclass(frozen=True)
class CoverageError:
    cause: Literal['code error', 'too large', 'timeout']
    message: str = ''


def _timeout_handler(_arg1, _arg2) -> None:
    raise TimeoutError('Execution timed out!')


def _custom_import(name: str,
                  globals: dict | None = None,
                  locals: dict | None = None,
                  fromlist: tuple[str, ...] = (),
                  level: int = 0
                  ) -> ModuleType:
    assert name == 'coverage'
    return __import__(name, globals, locals, fromlist, level)


def _load_coverage(code_file: Path,
                   port_widths: dict[str, int]
                   ) -> tuple[Coverage, list[CoverageError | Literal['ok']]]:
    snippets = json.loads(code_file.read_text())

    coverage.register_port_width(lambda x: port_widths[x])
    globals = {
        '__builtins__': {**builtins.__dict__, '__import__': _custom_import}
    }
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
        except TimeoutError as e:
            errors.append(CoverageError('timeout'))
            continue
        except CoverageSizeError:
            errors.append(CoverageError('too large'))
            continue
        except Exception as e:
            errors.append(CoverageError('code error', f'Exception: {e}'))
            continue
        finally:
            signal.alarm(0)

        coverpoints += [x for x in locals.values()
                        if isinstance(x, Coverpoint)]
        crosses += [x for x in locals.values() if isinstance(x, Cross)]
        errors.append('ok')

    return Coverage(coverpoints, crosses), errors


def process_line(line: str) -> int | None:
    if line[0:1] not in ' %~+-' or '// ignore coverage' in line:
        return None
    line = line[1:]
    hits, _, _ = line.partition(' ')
    return int(hits) if hits.isdecimal() else None


def _statement_coverage(dir: Path) -> float:
    coverage_cmd = ['verilator_coverage', str(dir / 'coverage.dat'),
                    '--annotate', str(dir / 'logs'),
                    '--annotate-min', '1', '--annotate-all']
    subprocess.run(coverage_cmd,
                   check=True,
                   stdout=subprocess.DEVNULL,
                   stderr=subprocess.DEVNULL)

    coverage_log = next(x for x in (dir / 'logs').iterdir()
                        if x.is_file())
    code_coverage_log = coverage_log.read_text()

    coverage_raw = [process_line(x) for x in code_coverage_log.splitlines()]
    coverage = [x for x in coverage_raw if x is not None]
    return sum(x > 0 for x in coverage) / len(coverage)


# ─────────────────────────────[ ⚙️  Results  ⚙️ ]─────────────────────────────

@dataclass(frozen=True)
class Ports:
    sizes: list[tuple[str, int]]
    clock_port: str | Literal['not found']
    reset_port: str | Literal['not found']
    reset_n_port: str | Literal['not found']
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
    status: list[CoverageError | Literal['ok']]

    def save(self, data_file: Path) -> None:
        def deque_default(obj: object) -> object:
            if isinstance(obj, deque):
                return list(obj)
            raise TypeError

        data_file.write_text(json.dumps(dataclasses.asdict(self),
                                        default=deque_default))

    @classmethod
    def load(cls, data_file: Path) -> Result:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[tuple, deque])
        return dacite.from_dict(Result, data, config)



# ────────────────────────────[ ⚙️  Testbench  ⚙️ ]────────────────────────────

async def _generate_clock(clock: _Port) -> None:
    for value in cycle((0, 1)):
        clock.handle.value = value
        await Timer(Decimal(1), units='ns')


@cocotb.test
async def test_module(dut: HierarchyObject) -> None:
    config = Config.load_from_env()
    random.seed(config.seed)

    ports = _find_ports(dut, config.code)
    clock = _find_port(ports, CLOCK_NAMES)

    assert clock is not None
    await cocotb.start(_generate_clock(clock))

    reset = _find_port(ports, RESET_NAMES)
    reset_n = _find_port(ports, RESET_N_NAMES)

    coverage_trigger = _find_port(ports, COVERAGE_NAMES)
    assert coverage_trigger is not None

    ignored = {x and x.name for x in (clock, reset, reset_n, coverage_trigger)}
    input_ports = [x for x in ports
                   if x.direction == 'input' and x.name not in ignored]

    ports_info = Ports(sizes=[(x.name, x.width) for x in ports],
                       clock_port=clock.name,
                       reset_port=reset.name if reset else 'not found',
                       reset_n_port=reset_n.name if reset_n else 'not found',
                       stimulated_ports=[x.name for x in input_ports])

    _coverage, _status = _load_coverage(config.coverage_path,
                                        {x.name: x.width for x in ports})
    coverages = []

    reset_gen = map(lambda x: random.random() < x,
                            cycle((config.reset_prob,)))
    reset_gen = chain((False, True, False), reset_gen)

    for i in alive_it(range(1, config.clock_limit + 1)):
        store_coverage = i % config.cover_step == 0
        coverage_trigger.handle.value = store_coverage
        should_reset = next(reset_gen)
        _set_value(reset, int(should_reset))
        _set_value(reset_n, not int(should_reset))

        for port in input_ports:
            port.handle.value = random.randint(0, 2**port.width - 1)

        await RisingEdge(clock.handle)

        values = {port.name: int(port.handle.value) for port in ports}
        _coverage.sample_all(values)

        if store_coverage:
            statement = _statement_coverage(config.coverage_path.parent)
            functional = _coverage.percentage()
            coverages.append(CoverageInfo(i,
                                          statement=statement,
                                          functional=functional))

    _coverage.print()

    result = Result(ports_info, coverages, _status)
    result.save(config.result_path)
