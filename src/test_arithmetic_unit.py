# TODO:
# - [x] Implement simple design (arithmetic unit with delayed multiplication).
# - [x] Implement simple CoCoTB random stimuli testbanch.
# - [x] Log code coverage information in the testbench.
# - [ ] Create functional coverage API for CoCoTB.
# - [ ] Log functional coverage information in the testbench.
# - [ ] Plot functional vs code coverage information.
# - [ ] Generate functional coverage using LLMs.
# - [ ] Log syntax errors contained in the generated code.
# - [ ] Transform CoCoTB testbench into UVM.
# - [ ] Chack that functional coverage contains specific values.
from __future__ import annotations

import asyncio
import random
from decimal import Decimal
from functools import partial

import cocotb
from cocotb.handle import HierarchyObject, ModifiableObject
from cocotb.triggers import Timer, RisingEdge


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


@cocotb.test
async def test_random_stimuli(dut: HierarchyObject) -> None:
    # Init testbench environment.
    random.seed(42)
    transactions = 10000
    max_transaction_length = 10
    ports = {k: v for k, v in extract_ports(dut).items()
             if k in ('OP_CODE', 'MOVI', 'REG_A', 'REG_B', 'MEM', 'IMM')}
    stop = asyncio.Event()

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
        for name, value in random_inputs(ports).items():
            ports[name].value = value
        dut.ACT.value = 1
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
                print('[INFO] Transaction outputs:')
                print(f'        DATA    = {dut.DATA.value.integer}')
                break

            if i == max_transaction_length:
                stop.set()
                print('[ERROR] Transaction did not finish in time.')
                return

    stop.set()

    # To get coverage info, run and check newly created dir `logs`.
    # `verilator_coverage --annotate logs coverage.dat --annotate-min 1`
