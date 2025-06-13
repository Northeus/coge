from __future__ import annotations

import dataclasses
import json
import os
import random
import re
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


# ───────────────────────────[ ⚙️  Test set-up  ⚙️ ]──────────────────────────

CLOCK_NAMES = ('clk', 'clock')
RESET_NAMES = ('rst', 'reset')
RESET_N_NAMES = ('rstn', 'rst_n', 'rst_neg', 'resetn', 'reset_n', 'reset_neg')


@dataclass(frozen=True)
class Config:
    seed: int | None
    code: Path

    @classmethod
    def load_from_env(cls) -> Config:
        assert 'TB_CODE' in os.environ

        _seed = os.environ.get('TB_SEED')
        seed = int(_seed) if _seed is not None else 0

        code = Path(os.environ['TB_CODE'])
        assert code.exists()

        return Config(seed, code)


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
    hits: int = field(default=1, hash=False)
    at_least: int = 1

    def sample(self, value: int) -> bool:
        lower, upper = self.value_range
        did_hit = lower <= value <= upper
        self.hits += did_hit
        return did_hit


@dataclass
class Sequence:
    port: str
    sequence: list[int]
    index: int = 0
    hits: int = 0
    at_least: int = 1

    def sample(self, value: int) -> bool:
        if value != self.sequence[self.index]:
            self.index = 0
            return False

        self.index = (self.index + 1) % len(self.sequence)
        did_hit = self.index == 0
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
        data_file.write_text(json.dumps(dataclasses.asdict(self)))

    @classmethod
    def load(cls, data_file: Path) -> Coverage:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[tuple])
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
                print(f'  * Sequence {str(sequence.sequence):>50}'
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
    seq = Sequence(coverpoint.port, sequence, at_least=at_least)
    coverpoint.sequences.append(seq)
    return seq


def cross(bin_groups: list[list[Bin]]) -> Cross:
    return Cross(list(product(*bin_groups)))


# ──────────────────────────────[ ⚙️  Test  ⚙️ ]──────────────────────────────

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
    if reset is not None or reset_n is not None:
        for value in (0, 1, 0):
            _set_value(reset, value)
            _set_value(reset_n, not value)
            await _next_clock_tick(clock)


    ...
    # TODO: remove this hardcoded coverage
    movi_cp = coverpoint('MOVI')
    movi_bins = normal_bins(movi_cp, (0, 3))
    op_cp = coverpoint('OP')
    op_bins = normal_bins(op_cp, (0, 3))
    normal_bin(op_cp, 2, at_least=5)
    for op1, op2 in product(range(5, 8), range(5, 8)):
        sequence(op_cp, [op1, op2])
    op_movi_cross = cross([op_bins, movi_bins])
    coverage = Coverage([op_cp, movi_cp], [op_movi_cross])
    ...

    input_ports = list(filter(lambda x: x.direction == 'input', ports))
    for _ in range(1000):
        values = {port.name: random.randint(0, 2**port.width - 1)
                  for port in input_ports}

        for port in input_ports:
            port.handle.value = values[port.name]

        coverage.sample_all(values)
        await _next_clock_tick(clock)

    coverage.save(Path(__file__).resolve().parent / 'data.json')


"""
@cocotb.test
async def test_random_stimuli(dut: HierarchyObject) -> None:
    # Init testbench environment.
    random.seed(42)
    transactions = TRANSACTIONS
    max_transaction_length = 10
    ports = {k: v for k, v in extract_ports(dut).items()
             if k in ('OP_CODE', 'MOVI', 'REG_A', 'REG_B', 'MEM', 'IMM', 'ACT')}
    stop = asyncio.Event()
    log_transactions = False

    # Define functional coverage.
    coverpoints = [coverpoint('OP_CODE'), coverpoint('REG_A')]
    for i in range(4):
        normal_bin(coverpoints[0], i)
    for i in range(4):
        for j in range(4):
            if i != j:
                sequence(coverpoints[0], [i, j])
    normal_bin(coverpoints[1], (0, 2**30))
    normal_bin(coverpoints[1], (2**30, 2**31))
    normal_bin(coverpoints[1], (2**31, 2**32))
    crosses = [cross([(cp, cp.bins) for cp in coverpoints])]

    # Start clock.
    await cocotb.start(generate_clock(dut, stop))

    # Reset DUT.
    dut.RST.value = 0
    await Timer(Decimal(3), units='ns')
    dut.RST.value = 1
    await Timer(Decimal(4), units='ns')
    dut.RST.value = 0
    await Timer(Decimal(3), units='ns')

    # Perform transactions.
    await RisingEdge(dut.CLK)
    for _ in range(transactions):
        stimuli = random_inputs(ports)
        for name, value in stimuli.items():
            ports[name].value = value
        await RisingEdge(dut.CLK)

        values = {'OP_CODE': stimuli['OP_CODE'],
                  'REG_A': stimuli['REG_A']}
        sample(values, coverpoints, crosses)

        if log_transactions:
            print(f'[INFO] Transaction inputs (#{i})')
            print(f'        OP_CODE = {ports['OP_CODE'].value.integer}')
            print(f'        MOVI    = {ports['MOVI'].value.integer}')
            print(f'        REG_A   = {ports['REG_A'].value.integer}')
            print(f'        REG_B   = {ports['REG_B'].value.integer}')
            print(f'        MEM     = {ports['MEM'].value.integer}')
            print(f'        IMM     = {ports['IMM'].value.integer}')

    stop.set()

    print_coverage(coverpoints, crosses)
    result = Result(coverpoints, crosses)
    result_json = json.dumps(dataclasses.asdict(result), indent=2)

    functional_coverage_file = Path(__file__).resolve().parent / 'func.json'
    functional_coverage_file.write_text(result_json)









from __future__ import annotations

import asyncio
import dataclasses
import random
import json
import os
from dataclasses import dataclass
from decimal import Decimal
from functools import partial
from itertools import product
from pathlib import Path

import cocotb
from cocotb.handle import HierarchyObject, ModifiableObject
from cocotb.triggers import Timer, RisingEdge


TRANSACTIONS = 10
TRANSACTIONS = int(os.getenv('TRANSACTIONS', TRANSACTIONS))




def random_inputs(ports: dict[str, ModifiableObject]) -> dict[str, int]:
    return {name: random.randint(0, 2**port_width(port) - 1)
            for name, port in ports.items()}


async def generate_clock(dut: HierarchyObject, stop: asyncio.Event) -> None:
    while not stop.is_set():
        dut.CLK.value = 0
        await Timer(Decimal(1), units='ns')
        dut.CLK.value = 1
        await Timer(Decimal(1), units='ns')


@dataclass
class Bin:
    value_range: tuple[int, int]
    hits: int = 0

    def sample(self, value: int) -> bool:
        lower, upper = self.value_range
        did_hit = lower <= value <= upper
        self.hits += int(did_hit)
        return did_hit


@dataclass
class Sequence:
    sequence: list[int]
    index: int = 0
    hits: int = 0

    def sample(self, value: int) -> bool:
        if value != self.sequence[self.index]:
            self.index = 0
            return False

        self.index += 1

        if self.index < len(self.sequence):
            return False

        self.index = 0
        self.hits += 1
        return True


@dataclass
class Coverpoint:
    port: str
    bins: list[Bin]
    ignore_bins: list[Bin]
    sequences: list[Sequence]


@dataclass
class Cross:
    coverpoints: list[Coverpoint]
    cross: list[tuple[Bin, ...]]
    hits: list[int]


def coverpoint(port: str) -> Coverpoint:
    return Coverpoint(port, [], [], [])


def normal_bin(coverpoint: Coverpoint, values: tuple[int, int] | int) -> Bin:
    bin = Bin((values, values) if isinstance(values, int) else values)
    coverpoint.bins.append(bin)
    return bin


def ignore_bin(coverpoint: Coverpoint, values: tuple[int, int] | int) -> Bin:
    bin = Bin((values, values) if isinstance(values, int) else values)
    coverpoint.ignore_bins.append(bin)
    return bin


def sequence(coverpoint: Coverpoint, sequence: list[int]) -> Sequence:
    _sequence = Sequence(sequence)
    coverpoint.sequences.append(_sequence)
    return _sequence


def cross(bin_groups: list[tuple[Coverpoint, list[Bin]]]) -> Cross:
    # TODO: might remove duplicities in product...
    assert all(b in cp.bins for cp, bins in bin_groups for b in bins)
    coverpoints = list(x[0] for x in bin_groups)
    cross = list(product(*(x[1] for x in bin_groups)))
    return Cross(coverpoints, cross, [0] * len(cross))


def sample(values: dict[str, int],
           coverpoints: list[Coverpoint],
           crosses: list[Cross]
           ) -> None:
    hits_id: set[int] = set()

    for coverpoint in coverpoints:
        value = values[coverpoint.port]

        for sequence in coverpoint.sequences:
            sequence.sample(value)

        if any(ignore_bin.sample(value)
               for ignore_bin in coverpoint.ignore_bins):
            continue

        for bin in coverpoint.bins:
            if bin.sample(value):
                hits_id.add(id(bin))

    for cross in crosses:
        for i, bins in enumerate(cross.cross):
            if all(id(b) in hits_id for b in bins):
                cross.hits[i] += 1


def print_coverage(coverpoints: list[Coverpoint],
                   crosses: list[Cross]
                   ) -> None:
    print('[INFO] Coverage:')

    for coverpoint in coverpoints:
        print(f'\tCoverpoint [{coverpoint.port}]:')

        for bin in coverpoint.bins:
            print(f'\t\tBin {bin.value_range}: {bin.hits}')

        for sequence in coverpoint.sequences:
            print(f'\t\tSequence {sequence.sequence}: {sequence.hits}')

    for cross in crosses:
        print(f'\tCross {list(x.port for x in cross.coverpoints)}:')

        for i, target in enumerate(cross.cross):
            print(f'\t\tTarget {target}: {cross.hits[i]}')


@dataclass
class Result:
    coverpoints: list[Coverpoint]
    crosses: list[Cross]


@cocotb.test
async def test_random_stimuli(dut: HierarchyObject) -> None:
    # Init testbench environment.
    random.seed(42)
    transactions = TRANSACTIONS
    max_transaction_length = 10
    ports = {k: v for k, v in extract_ports(dut).items()
             if k in ('OP_CODE', 'MOVI', 'REG_A', 'REG_B', 'MEM', 'IMM', 'ACT')}
    stop = asyncio.Event()
    log_transactions = False

    # Define functional coverage.
    coverpoints = [coverpoint('OP_CODE'), coverpoint('REG_A')]
    for i in range(4):
        normal_bin(coverpoints[0], i)
    for i in range(4):
        for j in range(4):
            if i != j:
                sequence(coverpoints[0], [i, j])
    normal_bin(coverpoints[1], (0, 2**30))
    normal_bin(coverpoints[1], (2**30, 2**31))
    normal_bin(coverpoints[1], (2**31, 2**32))
    crosses = [cross([(cp, cp.bins) for cp in coverpoints])]

    # Start clock.
    await cocotb.start(generate_clock(dut, stop))

    # Reset DUT.
    dut.RST.value = 0
    await Timer(Decimal(3), units='ns')
    dut.RST.value = 1
    await Timer(Decimal(4), units='ns')
    dut.RST.value = 0
    await Timer(Decimal(3), units='ns')

    # Perform transactions.
    await RisingEdge(dut.CLK)
    for _ in range(transactions):
        stimuli = random_inputs(ports)
        for name, value in stimuli.items():
            ports[name].value = value
        await RisingEdge(dut.CLK)

        values = {'OP_CODE': stimuli['OP_CODE'],
                  'REG_A': stimuli['REG_A']}
        sample(values, coverpoints, crosses)

        if log_transactions:
            print(f'[INFO] Transaction inputs (#{i})')
            print(f'        OP_CODE = {ports['OP_CODE'].value.integer}')
            print(f'        MOVI    = {ports['MOVI'].value.integer}')
            print(f'        REG_A   = {ports['REG_A'].value.integer}')
            print(f'        REG_B   = {ports['REG_B'].value.integer}')
            print(f'        MEM     = {ports['MEM'].value.integer}')
            print(f'        IMM     = {ports['IMM'].value.integer}')

    stop.set()

    print_coverage(coverpoints, crosses)
    result = Result(coverpoints, crosses)
    result_json = json.dumps(dataclasses.asdict(result), indent=2)

    functional_coverage_file = Path(__file__).resolve().parent / 'func.json'
    functional_coverage_file.write_text(result_json)
"""
