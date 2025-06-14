from __future__ import annotations

import dataclasses
import json
import os
import random
import re
from collections import deque
from dataclasses import dataclass, field
from decimal import Decimal
from functools import partial
from itertools import chain, cycle, product
from pathlib import Path
from typing import Literal

import cocotb
import dacite
from cocotb.handle import HierarchyObject, ModifiableObject
from cocotb.triggers import Timer, RisingEdge
from cocotb.utils import get_sim_time


# ───────────────────────────[ ⚙️  Test set-up  ⚙️ ]──────────────────────────

CLOCK_NAMES = ('clk', 'clock')
RESET_NAMES = ('rst', 'reset')
RESET_N_NAMES = ('rstn', 'rst_n', 'rst_neg', 'resetn', 'reset_n', 'reset_neg')


@dataclass(frozen=True)
class Config:
    seed: int | None
    code: Path
    coverage: Path
    result_path: Path
    time_limit: int = 1000
    reset_prob: float = 0.0

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

        return Config(seed, code, coverage, result_path,
                      time_limit, reset_prob)


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


    def save(self, data_file: Path) -> None:
        def deque_default(obj: object) -> object:
            if isinstance(obj, deque):
                return list(obj)
            raise TypeError

        data_file.write_text(json.dumps(dataclasses.asdict(self),
                                        default=deque_default))

    @classmethod
    def load(cls, data_file: Path) -> Coverage:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[tuple, deque])
        return dacite.from_dict(Coverage, data, config)

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
    return seq


def cross(bin_groups: list[list[Bin]]) -> Cross:
    return Cross(list(product(*bin_groups)))


# ──────────────────────────────[ ⚙️  Test  ⚙️ ]──────────────────────────────

def _find_ports(dut: HierarchyObject, code: Path) -> list[_Port]:
    names = filter(lambda x: not x.startswith('_'), dir(dut))
    objects =  filter(lambda x: isinstance(x, ModifiableObject),
                      map(partial(getattr, dut), names))

    # TODO: mention this requirement of module ports in datasets README.md
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

    ...
    # TODO: remove this hardcoded coverage
    code = config.coverage.read_text()
    print(code)
    globals = {'list': list,
               'range': range,
               'tuple': tuple,
               'coverpoint': coverpoint,
               'sequence': sequence,
               'normal_bin': normal_bin,
               'normal_bins': normal_bins,
               'illegal_bin': illegal_bin,
               'ignore_bin': ignore_bin,
               'cross': cross
    }
    locals = {}
    try:
        exec(code, globals, locals)
    except Exception as e:
        print(e)
        # TODO: LOG FAIL
        return
    print(locals)
    ...
    coverpoints = [x for x in locals.values() if isinstance(x, Coverpoint)]
    crosses = [x for x in locals.values() if isinstance(x, Cross)]
    coverage = Coverage(coverpoints, crosses)
    ...

    should_reset_iter = map(lambda x: random.random() < x,
                            cycle((config.reset_prob,)))
    should_reset_iter = chain((False, True, False), should_reset_iter)

    ignored_ports = {reset and reset.name, reset_n and reset_n.name}
    input_ports = filter(
        lambda x: x.direction == 'input' and x.name not in ignored_ports,
        ports)

    while get_sim_time(units='ns') < config.time_limit:
        should_reset = next(should_reset_iter)
        _set_value(reset, int(should_reset))
        _set_value(reset_n, not int(should_reset))

        for port in input_ports:
            port.handle.value = random.randint(0, 2**port.width - 1)

        values = {port.name: int(port.handle.value) for port in ports}
        coverage.sample_all(values)
        await _next_clock_tick(clock)

    coverage.save(config.result_path)
