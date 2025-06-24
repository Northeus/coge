from __future__ import annotations

import dataclasses
import json
import os
import random
import re
import signal
from collections import deque
from dataclasses import dataclass, field
from decimal import Decimal
from functools import partial, reduce
from itertools import chain, cycle, product
from operator import mul
from pathlib import Path
from typing import Callable, Literal

import cocotb
import dacite
from cocotb.handle import HierarchyObject, ModifiableObject
from cocotb.triggers import Timer, RisingEdge
from cocotb.utils import get_sim_time


# WIP
# WIP
# WIP
# WIP
# WIP


@dataclass
class Ports:
    sizes: list[tuple[str, int]]
    clock_port: str | None
    reset_port: str | None
    reset_n_port: str | None
    stimulated_ports: list[str]


@dataclass
class Result:
    ports: Ports
    coverage: Coverage | CoverageError

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


async def _generate_clock(clock: _Port | None) -> None:
    if clock is None:
        return

    for value in cycle((0, 1)):
        clock.handle.value = value
        await Timer(Decimal(1), units='ns')


async def _next_clock_tick(clock: _Port | None) -> None:
    if clock is not None:
        await RisingEdge(clock.handle)
    else:
        await Timer(Decimal(1), units='ns')


def _set_value(signal: _Port | None, value: int) -> None:
    if signal is not None:
        signal.handle.value = value


@cocotb.test
async def test_module(dut: HierarchyObject) -> None:
    config = Config.load_from_env()
    random.seed(config.seed)

    ports = _find_ports(dut, config.code)
    clock = _find_clock(ports)
    await cocotb.start(_generate_clock(clock))

    reset = _find_reset(ports)
    reset_n = _find_reset_n(ports)

    clock_port_name = clock and clock.name
    reset_port_name = reset and reset.name
    reset_n_port_name = reset_n and reset_n.name
    input_ports = [x for x in ports
                   if (x.direction == 'input'
                       and x.name not in {clock_port_name,
                                          reset_port_name,
                                          reset_n_port_name})]

    ports_info = Ports([(port.name, port.width) for port in ports],
                       clock_port_name,
                       reset_port_name,
                       reset_n_port_name,
                       [port.name for port in input_ports])

    port_width = _make_port_width({port.name: port for port in ports})
    coverage = _load_coverage(config, port_width)
    if isinstance(coverage, CoverageError):
        result = Result(ports_info, coverage)
        result.save(config.result_path)
        return

    should_reset_iter = map(lambda x: random.random() < x,
                            cycle((config.reset_prob,)))
    should_reset_iter = chain((False, True, False), should_reset_iter)

    while get_sim_time(units='ns') < config.time_limit:
        should_reset = next(should_reset_iter)
        _set_value(reset, int(should_reset))
        _set_value(reset_n, not int(should_reset))

        for port in input_ports:
            port.handle.value = random.randint(0, 2**port.width - 1)

        values = {port.name: int(port.handle.value) for port in ports}
        coverage.sample_all(values)
        await _next_clock_tick(clock)

    result = Result(ports_info, coverage)
    result.save(config.result_path)























# ───────────────────────────[ ⚙️  Test set-up  ⚙️ ]──────────────────────────
# TODO: remove coverage clock limit

MAX_SEQUENCE_SIZE = 8
MAX_CROSS_SIZE = 100
MAX_BINS_COUNT = 100
MAX_SEQUENCE_COUNT = 10

CLOCK_NAMES = ('clk', 'clock')
RESET_NAMES = ('rst', 'reset')
RESET_N_NAMES = ('rstn', 'rst_n', 'rst_neg', 'resetn', 'reset_n', 'reset_neg')


@dataclass(frozen=True)
class Config:
    seed: int | None
    code: Path
    coverage: Path
    result_path: Path
    reset_prob: float = 0.0
    time_limit: int = 1000
    coverage_time_limit: int = 5

    @classmethod
    def load_from_env(cls) -> Config:
        assert 'TB_CODE' in os.environ

        _seed = os.environ.get('TB_SEED')
        seed = int(_seed) if _seed is not None else 0

        code = Path(os.environ['TB_CODE'])
        assert code.exists()
        coverage = Path(os.environ['TB_COVERAGE'])
        assert coverage.exists()

        reset_prob = float(os.environ.get('TB_RESER_PROB', '0'))
        time_limit = int(os.environ.get('TB_TIME_LIMIT', '1000'))

        result_path = Path(os.environ['TB_RESULT'])

        coverage_time_limit = int(os.environ.get('TB_COVERAGE_TIME', '5'))

        return Config(seed=seed,
                      code=code,
                      coverage=coverage,
                      result_path=result_path,
                      reset_prob=reset_prob,
                      time_limit=time_limit,
                      coverage_time_limit=coverage_time_limit)


@dataclass(frozen=True)
class _Port:
    name: str
    width: int
    direction: Literal['input', 'output', 'inout']
    handle: ModifiableObject


def _find_port(ports: list[_Port], names: tuple[str, ...]) -> _Port | None:
    targets = set(chain(names, map(lambda x: x.upper(), names)))
    return next((port for port in ports if port.name in targets), None)


def _find_clock(ports: list[_Port]) -> _Port | None:
    return _find_port(ports, CLOCK_NAMES)


def _find_reset(ports: list[_Port]) -> _Port | None:
    return _find_port(ports, RESET_NAMES)


def _find_reset_n(ports: list[_Port]) -> _Port | None:
    return _find_port(ports, RESET_N_NAMES)


def _timeout_handler(_arg1, _arg2) -> None:
    raise TimeoutError('Execution timed out!')


@dataclass
class CoverageError:
    cause: Literal['time', 'code', 'coverage size']
    message: str = ''


def _load_coverage(config: Config,
                   port_width: Callable[[str], int]
                   ) -> Coverage | CoverageError:
    code = config.coverage.read_text()
    globals = {'list': list,
               'range': range,
               'tuple': tuple,
               'coverpoint': coverpoint,
               'sequence': sequence,
               'normal_bin': normal_bin,
               'normal_bins': normal_bins,
               'illegal_bin': illegal_bin,
               'ignore_bin': ignore_bin,
               'cross': cross,
               'port_width': port_width
    }
    locals = {}

    signal.signal(signal.SIGALRM, _timeout_handler)
    try:
        signal.alarm(config.coverage_time_limit)
        exec(code, globals, locals)
        signal.alarm(0)
    except TimeoutError as e:
        return CoverageError(
            'time',
            f'Execution time took more than {config.coverage_time_limit}s')
    except _CoverageSizeError:
        return CoverageError('coverage size')
    except Exception as e:
        return CoverageError('code', f'Exception: {e}')
    finally:
        signal.alarm(0)

    coverpoints = [x for x in locals.values() if isinstance(x, Coverpoint)]
    crosses = [x for x in locals.values() if isinstance(x, Cross)]
    return Coverage(coverpoints, crosses)

# ────────────────────────────[ ⚙️  Coverage  ⚙️ ]────────────────────────────

@dataclass(unsafe_hash=True)
class Bin:
    port: str
    value_range: tuple[int, int]
    hits: int = field(default=0, hash=False)
    at_least: int = 1

    def sample(self, value: int) -> bool:
        lower, upper = self.value_range
        did_hit = lower <= value <= upper
        self.hits += did_hit
        return did_hit


@dataclass
class Sequence:
    port: str
    sequence: deque
    captured: deque
    hits: int = 0
    at_least: int = 1

    def sample(self, value: int) -> bool:
        self.captured.append(value)
        did_hit = self.captured == self.sequence
        self.hits += did_hit
        return did_hit


@dataclass
class Coverpoint:
    port: str
    bins: list[Bin] = field(default_factory=list)
    ignore_bins: list[Bin] = field(default_factory=list)
    illegal_bins: list[Bin] = field(default_factory=list)
    sequences: list[Sequence] = field(default_factory=list)

    def sample_all(self, value: int) -> list[Bin | Sequence]:
        hits = [seq for seq in self.sequences if seq.sample(value)]
        hits += [bin for bin in self.illegal_bins if bin.sample(value)]
        ignored = [bin for bin in self.ignore_bins if bin.sample(value)]
        if len(ignored) == 0:
            hits += [bin for bin in self.bins if bin.sample(value)]
        return hits


@dataclass
class Cross:
    cross: list[tuple[Bin, ...]]
    hits: list[int] = field(default_factory=list)

    def __post_init__(self) -> None:
        if len(self.hits) != len(self.cross):
            self.hits = [0] * len(self.cross)

    def sample_all(self, hits: set[Bin]) -> None:
        for i, cross in enumerate(self.cross):
            if all(x in hits for x in cross):
                self.hits[i] += 1


@dataclass
class Coverage:
    coverpoints: list[Coverpoint]
    crosses: list[Cross]

    def sample_all(self, values: dict[str, int]) -> None:
        bin_hits = set()
        for coverpoint in self.coverpoints:
            coverpoint_hits = coverpoint.sample_all(values[coverpoint.port])
            bin_hits |= set(hit for hit in coverpoint_hits if isinstance(hit, Bin))

        for cross in self.crosses:
            cross.sample_all(bin_hits)

    def print(self) -> None:
        for coverpoint in self.coverpoints:
            print(f'[{coverpoint.port}] Coverpoint:')
            for name, bins in (('Illegal bins', coverpoint.illegal_bins),
                               ('Ignore bins', coverpoint.ignore_bins),
                               ('Bins', coverpoint.bins)):
                for bin in bins:
                    print(f'  * {name} {str(bin.value_range):>50}'
                          f' {bin.hits:>10} hits')
            for sequence in coverpoint.sequences:
                print(f'  * Sequence {str(list(sequence.sequence)):>50}'
                      f' {sequence.hits:>10} hits')

        for cross in self.crosses:
            ports = [bin.port for bin in cross.cross[0]]
            print(f'[{ports}] Cross:')
            for bins, hits in zip(cross.cross, cross.hits):
                bins_str = f'[{', '.join(f'{x.port}={x.value_range}'
                                         for x in bins)}]'
                print(f'   * Target {bins_str:>50} {hits:>10} hits')


class _CoverageSizeError(Exception):
    pass


def coverpoint(port: str) -> Coverpoint:
    coverpoint = Coverpoint(port)
    return coverpoint


def _bin(coverpoint: Coverpoint,
         target: list[Bin],
         values: tuple[int, int] | int,
         at_least: int = 1
         ) -> Bin:
    bin = Bin(coverpoint.port,
              (values, values) if isinstance(values, int) else values,
              at_least=at_least)
    target.append(bin)

    if max(len(coverpoint.bins),
           len(coverpoint.ignore_bins),
           len(coverpoint.illegal_bins)) > MAX_BINS_COUNT:
        raise _CoverageSizeError

    return bin


def normal_bin(coverpoint: Coverpoint,
               values: tuple[int, int] | int,
               at_least: int = 1
               ) -> Bin:
    return _bin(coverpoint, coverpoint.bins, values, at_least)


def normal_bins(coverpoint: Coverpoint,
                values_range: tuple[int, int],
                at_least: int = 1
                ) -> list[Bin]:
    return [_bin(coverpoint, coverpoint.bins, value, at_least)
            for value in range(values_range[0], values_range[1] + 1)]


def ignore_bin(coverpoint: Coverpoint,
               values: tuple[int, int] | int,
               at_least: int = 1
               ) -> Bin:
    return _bin(coverpoint, coverpoint.ignore_bins, values, at_least)


def illegal_bin(coverpoint: Coverpoint,
                values: tuple[int, int] | int,
                at_least: int = 1
                ) -> Bin:
    return _bin(coverpoint, coverpoint.illegal_bins, values, at_least)


def sequence(coverpoint: Coverpoint,
             sequence: list[int],
             at_least: int = 1
             ) -> Sequence:
    seq = Sequence(coverpoint.port,
                   deque(sequence),
                   deque(maxlen=len(sequence)),
                   at_least=at_least)
    coverpoint.sequences.append(seq)

    if (len(sequence) > MAX_SEQUENCE_SIZE
        or len(coverpoint.sequences) > MAX_SEQUENCE_COUNT):
        raise _CoverageSizeError

    return seq


def cross(bin_groups: list[list[Bin]]) -> Cross:
    if reduce(mul, map(len, bin_groups)) > MAX_CROSS_SIZE:
        raise _CoverageSizeError

    return Cross(list(product(*bin_groups)))


def _make_port_width(ports: dict[str, _Port]) -> Callable[[str], int]:
    def port_size(name: str) -> int:
        return ports[name].width
    return port_size


# ──────────────────────────────[ ⚙️  Test  ⚙️ ]──────────────────────────────


@dataclass
class Ports:
    sizes: list[tuple[str, int]]
    clock_port: str | None
    reset_port: str | None
    reset_n_port: str | None
    stimulated_ports: list[str]


@dataclass
class Result:
    ports: Ports
    coverage: Coverage | CoverageError

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


async def _generate_clock(clock: _Port | None) -> None:
    if clock is None:
        return

    for value in cycle((0, 1)):
        clock.handle.value = value
        await Timer(Decimal(1), units='ns')


async def _next_clock_tick(clock: _Port | None) -> None:
    if clock is not None:
        await RisingEdge(clock.handle)
    else:
        await Timer(Decimal(1), units='ns')


def _set_value(signal: _Port | None, value: int) -> None:
    if signal is not None:
        signal.handle.value = value


@cocotb.test
async def test_module(dut: HierarchyObject) -> None:
    config = Config.load_from_env()
    random.seed(config.seed)

    ports = _find_ports(dut, config.code)
    clock = _find_clock(ports)
    await cocotb.start(_generate_clock(clock))

    reset = _find_reset(ports)
    reset_n = _find_reset_n(ports)

    clock_port_name = clock and clock.name
    reset_port_name = reset and reset.name
    reset_n_port_name = reset_n and reset_n.name
    input_ports = [x for x in ports
                   if (x.direction == 'input'
                       and x.name not in {clock_port_name,
                                          reset_port_name,
                                          reset_n_port_name})]

    ports_info = Ports([(port.name, port.width) for port in ports],
                       clock_port_name,
                       reset_port_name,
                       reset_n_port_name,
                       [port.name for port in input_ports])

    port_width = _make_port_width({port.name: port for port in ports})
    coverage = _load_coverage(config, port_width)
    if isinstance(coverage, CoverageError):
        result = Result(ports_info, coverage)
        result.save(config.result_path)
        return

    should_reset_iter = map(lambda x: random.random() < x,
                            cycle((config.reset_prob,)))
    should_reset_iter = chain((False, True, False), should_reset_iter)

    while get_sim_time(units='ns') < config.time_limit:
        should_reset = next(should_reset_iter)
        _set_value(reset, int(should_reset))
        _set_value(reset_n, not int(should_reset))

        for port in input_ports:
            port.handle.value = random.randint(0, 2**port.width - 1)

        values = {port.name: int(port.handle.value) for port in ports}
        coverage.sample_all(values)
        await _next_clock_tick(clock)

    result = Result(ports_info, coverage)
    result.save(config.result_path)
