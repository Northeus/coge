# TODO: add documentation
from __future__ import annotations

from dataclasses import dataclass
from decimal import Decimal
from typing import Callable, Generic, Iterable, NamedTuple, TypeVar

import cocotb
from cocotb.handle import HierarchyObject, ModifiableObject
from cocotb.triggers import FallingEdge, Timer


####==============================================####
##                      Utils                       ##
####==============================================####

T = TypeVar('T')
U = TypeVar('U')
V = TypeVar('V')


class Iterator(NamedTuple, Generic[T]):
    iterable: Iterable[T]

    def first(self, fn: Callable[[T], bool]) -> T | None:
        return next((x for x in self.iterable if fn(x)), None)

    def filter(self, fn: Callable[[T], bool]) -> Iterator[T]:
        return Iterator(filter(fn, self.iterable))

    def map(self, fn: Callable[[T], U]) -> Iterator[U]:
        return Iterator(map(fn, self.iterable))

    def to_dict(self,
                fn_key: Callable[[T], U],
                fn_val: Callable[[T], V]
                ) -> dict[U, V]:
        return {fn_key(x): fn_val(x) for x in self.iterable}


####==============================================####
##                 Coverage Utils                   ##
####==============================================####

class Port(NamedTuple):
    # TODO: some port hooks to dut
    ...


class Default:
    pass


@dataclass
class Bin:
    # TODO: add sample condition
    target: range | int | Default
    at_least: int = 1
    hits: int = 0

    def __post_init__(self) -> None:
        # TODO: validation
        ...

    def check(self, value: int) -> bool:
        if isinstance(self.target, range) and value not in self.target:
            return False
        if isinstance(self.target, int) and value != self.target:
            return False

        self.hits += 1
        return True


class Sequence:
    # TODO: some sequence recognition with reset (trigered by ignore bins).
    ...


# WARNING: Not thread safe - use only within single test!
class CoverPoint(NamedTuple):
    port: Port
    bins: list[Bin]
    illegal_bins: list[Bin]
    ignored_bins: list[Bin]

    def __new__(cls, *args, **kwargs) -> CoverPoint:
        # TODO: validation
        return super().__new__(cls, *args, **kwargs)

    def sample(self) -> None:
        value = 1

        illegal_bin = Iterator(self.illegal_bins).first(lambda x: x.check(value))
        if illegal_bin is not None:
            # TODO: proper loggin to capture information and some way of fallback
            assert False

        ignored_bin = Iterator(self.ignored_bins).first(lambda x: x.check(value))
        if ignored_bin is not None:
            return

        _ = Iterator(self.ignored_bins).first(lambda x: x.check(value))


class Cross:
    # TODO: add cross over coverpoints with selections, negations and etc.
    ...


# TODO: some pretty prints


####==============================================####
##              Coverage Comparision                ##
####==============================================####

# TODO: Compare coverpoints:
#  - bins without conditions using range recreation and comparision.
#  - bins with condition some symbolic execution and range recreation?
#  - sequence bins using automata?


# TODO: some pretty prints


####==============================================####
##                   CoCoTB Utils                   ##
####==============================================####

def ports(dut: HierarchyObject) -> dict[str, ModifiableObject]:
    return (
        Iterator(dir(dut))
        .filter(lambda x: not x.startswith('_'))
        .map(lambda x: getattr(dut, x))
        .filter(lambda x: isinstance(x, ModifiableObject))
        .to_dict(lambda k: k._name,
                 lambda v: v)
    )

# TODO: some pretty prints


####==============================================####
##                       Tests                      ##
####==============================================####

# TODO: some better clock generation utility to cocotb utils?
async def generate_clock(dut: HierarchyObject):
    for _ in range(10):
        dut.clk.value = 0
        await Timer(Decimal(1), units='ns')
        dut.clk.value = 1
        await Timer(Decimal(1), units='ns')


# TODO: nicer test with reference model, more complex design,
#       random stimuli generation and multiple coverage reports.
@cocotb.test
async def test_something(dut: HierarchyObject):
    print(ports(dut))
    await cocotb.start(generate_clock(dut))

    await Timer(Decimal(4), units='ns')
    await FallingEdge(dut.clk)

    assert False
