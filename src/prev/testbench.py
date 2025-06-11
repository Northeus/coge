import asyncio
import subprocess
from decimal import Decimal
from dataclasses import dataclass
from pathlib import Path

from cocotb.runner import get_runner
from cocotb.triggers import Timer
from cocotb.handle import HierarchyObject, ModifiableObject

TEMPLATE = """import asyncio

import cocotb
from cocotb.handle import HierarchyObject, ModifiableObject

import coverage
import testbench
#[IMPORTS]

@cocotb.test
async def #[TEST_NAME](dut: HierarchyObject) -> None:
    random.seed(#[SEED])

    ports = testbench.ports(dut)
    covergroups = #[COVERGROUPS_CALL]

    clock_port = #[CLOCK_PORT]
    clock_stop = asyncio.Event()
    await cocotb.start(testbench.clock(clock_port, clock_stop))

    #[RESET_CALL]
    #[TRANSACTION_AWAIT_CALL]
    for _ in range(#[TRANSACTIONS_COUNT]):
        #[GENERATE_STIMULI_CALL]
        #[TRANSACTION_START_CALL]
        #[TRANSACTION_AWAIT_CALL]

        values = {port.name: port.handle.value.integer for port in ports}
        coverage.sample(values, covergroups)

    clock_stop.set()
"""


@dataclass
class Config:
    name: str
    imports: str = ''
    seed: int | None = None
    clock_port: str = 'None'
    transactions_count: int = 100
    reset_call: str = 'pass'
    covergroups_call: str = '[]'
    generate_stimuli_call: str = 'pass'
    transaction_start_call: str = 'pass'
    transaction_await_call: str = 'pass'


def generate(filename: str, config: Config) -> None:
    code = (TEMPLATE
            .replace('#[TEST_NAME]', config.name)
            .replace('#[IMPORTS]', config.imports)
            .replace('#[SEED]', str(config.seed))
            .replace('#[CLOCK_PORT]', config.clock_port)
            .replace('#[TRANSACTIONS_COUNT]', str(config.transactions_count))
            .replace('#[RESET_CALL]', config.reset_call)
            .replace('#[COVERGROUPS_CALL]', config.covergroups_call)
            .replace('#[GENERATE_STIMULI_CALL]', config.generate_stimuli_call)
            .replace('#[TRANSACTION_START_CALL]', config.transaction_start_call)
            .replace('#[TRANSACTION_AWAIT_CALL]', config.transaction_await_call))
    path = Path(__file__).resolve().parent / filename
    path.write_text(code)


def run(source_filename: str, top_level: str, module: str) -> None:
    source = Path(__file__).resolve().parent / source_filename
    runner = get_runner('verilator')
    runner.build(sources=[source], hdl_toplevel=top_level,
                 always=True, clean=True,
                 build_args=['--coverage'])

    x = runner.test(hdl_toplevel=top_level,
                    test_module=module)
    print(f'Tests done, result ({type(x)}): {x}')

    # Generate code coverage.
    cmd = ('verilator_coverage --annotate logs '
           'sim_build/coverage.dat --annotate-min 1 '
           '--annotate-all')
    subprocess.run(cmd.split(' '), check=True)


@dataclass
class Port:
    name: str
    width: int
    handle: ModifiableObject


def ports(dut: HierarchyObject) -> dict[str, Port]:
    ports = {}

    for name in dir(dut):
        if not name.startswith('_'):
            continue

        port = getattr(dut, name)
        if not isinstance(port, ModifiableObject):
            continue

        width = port.__len__()
        assert isinstance(width, int)

        ports[name] = Port(name, width, port)

    return ports


async def clock(port: Port | None, stop: asyncio.Event) -> None:
    while not stop.is_set():
        if port is not None:
            port.handle.value = 0
        await Timer(Decimal(1), units='ns')

        if port is not None:
            port.handle.value = 0
        await Timer(Decimal(1), units='ns')
