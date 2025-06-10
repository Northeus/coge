# TODO:
# - [ ] Create plot consisting of code and functional coverage closure over time.
# - [ ] Add automatic DUT connection - find all necessary ports and keep them in dict.
# - [ ] Automatic clock generation - create clock provided clock signal name.
# - [ ] Automatic transaction generation - create transaction provided inputs & action.
# - [ ] Automatic random stimuli generation using data from generated transactions.
# - [ ] Check that functional coverage contains some specific values, ranges, sequences.
# - [ ] REFACTOR. ^^
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


def parse_port(dut: HierarchyObject, name: str) -> ModifiableObject | None:
    if name.startswith('_'):
        return None
    port = getattr(dut, name)
    return port if isinstance(port, ModifiableObject) else None


def port_width(port: ModifiableObject) -> int:
    width = port.__len__()
    assert isinstance(width, int)
    return width


def extract_ports(dut: HierarchyObject) -> dict[str, ModifiableObject]:
    return {x._name: x
            for x in map(partial(parse_port, dut), dir(dut))
            if x is not None}


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
            print(f'\t\tBin {bin.values}: {bin.hits}')

        for sequence in coverpoint.sequences:
            print(f'\t\tSequence {sequence.sequence}: {sequence.hits}')

    for cross in crosses:
        print(f'\tCross {list(x.port for x in cross.coverpoints)}:')

        for i, target in enumerate(cross.cross):
            print(f'\t\tTarget {target}: {cross.hits[i]}')


@cocotb.test
async def test_random_stimuli(dut: HierarchyObject) -> None:
    # Init testbench environment.
    random.seed(42)
    transactions = TRANSACTIONS
    max_transaction_length = 10
    ports = {k: v for k, v in extract_ports(dut).items()
             if k in ('OP_CODE', 'MOVI', 'REG_A', 'REG_B', 'MEM', 'IMM')}
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
    for i in range(1, transactions + 1):
        stimuli = random_inputs(ports)
        for name, value in stimuli.items():
            ports[name].value = value
        dut.ACT.value = 1

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

        for i in range(1, max_transaction_length + 1):
            await RisingEdge(dut.CLK)
            dut.ACT.value = 0

            if dut.DATA_VALID == 1:
                break

            if i == max_transaction_length:
                stop.set()
                print('[ERROR] Transaction did not finish in time.')
                return

            if log_transactions:
                print('[INFO] Transaction outputs:')
                print(f'        DATA    = {dut.DATA.value.integer}')

    stop.set()

    # print_coverage(coverpoints, crosses)
    @dataclass
    class Result:
        coverpoints: list[Coverpoint]
        crosses: list[Cross]
    result = Result(coverpoints, crosses)
    result_json = json.dumps(dataclasses.asdict(result), indent=2)

    functional_coverage_file = Path(__file__).resolve().parent / 'func.json'
    functional_coverage_file.write_text(result_json)
