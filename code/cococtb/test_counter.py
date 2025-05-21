from decimal import Decimal

import cocotb
from cocotb.triggers import FallingEdge, Timer


print('[TEST]')


async def generate_clock(dut):
    for _ in range(10):
        dut.clk.value = 0
        await Timer(Decimal(1), units='ns')
        dut.clk.value = 1
        await Timer(Decimal(1), units='ns')


@cocotb.test()
async def test_something(dut):
    print(dut.cnt.value.__dict__)
    print(len(dut.cnt.value))
    await cocotb.start(generate_clock(dut))

    await Timer(Decimal(4), units='ns')
    await FallingEdge(dut.clk)

    assert False
