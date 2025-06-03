# TODO: finish todos
# TODO: equivalence can be done using sat solver (ranges, comparision, and, ors)
from __future__ import annotations

from dataclasses import dataclass, field
from decimal import Decimal
from itertools import chain, product
from typing import (Annotated, Callable, Generic, Iterable, Literal,
                    NamedTuple, TypeVar)

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

    # Concat
    def concat(self, other: Iterator[U]) -> Iterator[T | U]:
        return Iterator(chain(self.iterable, other.iterable))

    # Accessors
    def first(self, fn: Callable[[T], bool]) -> T | None:
        return next((x for x in self.iterable if fn(x)), None)

    # Transformers
    def filter(self, fn: Callable[[T], bool]) -> Iterator[T]:
        return Iterator(filter(fn, self.iterable))

    def map(self, fn: Callable[[T], U]) -> Iterator[U]:
        return Iterator(map(fn, self.iterable))

    # Aggregators.
    def all(self, fn: Callable[[T], bool]) -> bool:
        return all(map(fn, self.iterable))

    def any(self, fn: Callable[[T], bool]) -> bool:
        return any(map(fn, self.iterable))

    # Casters.
    def to_dict(self,
                fn_key: Callable[[T], U],
                fn_val: Callable[[T], V]
                ) -> dict[U, V]:
        return {fn_key(x): fn_val(x) for x in self.iterable}

    def to_list(self) -> list[T]:
        return list(self.iterable)

    # Others.
    def for_each(self, fn: Callable[[T], None]) -> None:
        for x in self.iterable:
            fn(x)


def always_true() -> bool:
    return True


####==============================================####
##                 Coverage Utils                   ##
####==============================================####
# WARNING: Not thread safe - use each instance
#          only within a single test!
# WARNING: Implementation is not yet optimized making
#          it unsuitable for very large tests.
# TODO: Add validation and maybe interface for LLMs.

Default = Annotated[None, 'Default']


class DUT(NamedTuple):
    ports: dict[str, Port]

    @classmethod
    def from_dut(cls, dut: HierarchyObject) -> DUT:
        return DUT({k: Port.from_hook(v) for k, v in ports(dut).items()})


class Port(NamedTuple):
    name: str
    width: int
    hook: ModifiableObject

    @classmethod
    def from_hook(cls, hook: ModifiableObject) -> Port:
        width = hook.__len__()
        assert isinstance(width, int)
        return Port(hook._name, width, hook)

    def read(self) -> int:
        return self.hook.value


@dataclass
class CoverGroup:
    dut: DUT
    cover_points: dict[Port, list[CoverPoint]] = field(default_factory=dict)
    crosses: list[Cross] = field(default_factory=list)

    def add_cover_point(self,
                        port: Port,
                        condition: Callable[[], bool] = always_true
                        ) -> CoverPoint:
        assert port in self.dut.ports.values()
        cover_point = CoverPoint(port, condition)
        self.cover_points.setdefault(port, []).append(cover_point)
        return cover_point

    def add_cross(self,
                  targets: list[CoverPoint | Bin | Sequence],
                  condition: Callable[[], bool] = always_true
                  ) -> None:
        _targets = []
        for target in targets:
            assert target.port in self.dut.ports.values()
            if isinstance(target, CoverPoint):
                _targets.extend(target.bins)
                _targets.extend(target.sequences)
            else:
                _targets.append(target)

        self.crosses.append(Cross.from_targets(_targets, condition))

    def sample(self) -> None:
        values = {port: port.read() for port in self.cover_points}
        hits = set()

        for port, cover_points in self.cover_points.items():
            for cover_point in cover_points:
                hits |= cover_point.sample(values[port])

        Iterator(self.crosses).for_each(lambda x: x.sample(values, hits))

    def report(self) -> str:
        # TODO:
        ...
        return 'TODO: report'


class IllegalBinException(Exception):
    pass


@dataclass
class CoverPoint:
    port: Port
    condition: Callable[[], bool] = always_true
    bins: dict[Bin, int] = field(default_factory=dict)
    ignored_bins: list[Bin] = field(default_factory=list)
    illegal_bins: list[Bin] = field(default_factory=list)
    sequences: dict[Sequence, int] = field(default_factory=dict)
    ignored_sequences: list[Sequence] = field(default_factory=list)
    illegal_sequences: list[Sequence] = field(default_factory=list)

    def add_bin(self,
                values: list[range | int] | Default,
                category: Literal['normal', 'ignore', 'illegal'] = 'normal',
                condition: Callable[[], bool] = always_true
                ) -> Bin:
        bin = Bin(self.port, values, condition=condition)
        match category:
            case 'normal': self.bins[bin] = 0
            case 'ignore': self.ignored_bins.append(bin)
            case 'illegal': self.illegal_bins.append(bin)
        return bin

    def add_sequence(self,
                     sequence: list[range | int] | Default,
                     category: Literal['normal', 'ignore', 'illegal'] = 'normal'
                     ) -> Sequence:
        _sequence = Sequence(self.port, sequence)
        match category:
            case 'normal': self.sequences[_sequence] = 0
            case 'ignore': self.ignored_sequences.append(_sequence)
            case 'illegal': self.illegal_sequences.append(_sequence)
        return _sequence

    def sample(self, value: int) -> set[Bin]:
        if (Iterator(self.illegal_bins)
                .concat(Iterator(self.illegal_sequences))
                .any(lambda x: x.sample(value))):
            raise IllegalBinException()

        if (Iterator(self.ignored_bins)
                .concat(Iterator(self.ignored_sequences))
                .any(lambda x: x.sample(value))):
            return set()

        hits = set()
        (Iterator(self.bins.keys())
            .concat(Iterator(self.sequences.keys()))
            .filter(lambda x: x.sample(value))
            .for_each(hits.add))
        for bin in hits:
            self.bins[bin] += 1
        return hits


@dataclass
class Cross:
    @dataclass
    class Target:
        requires: tuple[Bin | Sequence]
        hits: int = 0

    targets: list[Target]
    condition: Callable[[], bool] = always_true
    ignored_targets: list[Bin | Sequence] = field(default_factory=list)
    ignored_values: dict[Port, set[int | range]] = field(default_factory=dict)

    def ignore_bin(self, bin: Bin) -> None:
        if bin not in self.ignored_targets:
            self.ignored_targets.append(bin)

    def ignore_sequence(self, sequence: Sequence) -> None:
        if sequence not in self.ignored_targets:
            self.ignored_targets.append(sequence)

    def ignore_values(self, port: Port, values: list[int | range]) -> None:
        self.ignored_values.setdefault(port, set()).union(values)

    def sample(self,
               values: dict[Port, int],
               hits: set[Bin | Sequence]
               ) -> None:
        if not self.condition():
            return

        _hits = set()
        for hit in hits:
            if hit in self.ignored_targets:
                continue

            ignored = self.ignored_values.get(hit.port, set())
            value = values[hit.port]

            if any((isinstance(ignored, range) and value in ignored)
                   or (isinstance(ignored, int) and value == ignored)
                   for ignored in ignored):
                continue
            _hits.add(hit)

        for target in self.targets:
            if all(x in _hits for x in target.requires):
                target.hits += 1

    @classmethod
    def from_targets(cls,
                     targets: list[Bin | Sequence],
                     condition: Callable[[], bool] = always_true
                     ) -> Cross:
        grouped = {}
        for target in targets:
            grouped.setdefault(target.port, list()).append(target)

        _targets = [Cross.Target(x) for x in product(*grouped.values())]
        return Cross(_targets, condition)


@dataclass
class Bin:
    port: Port
    target: list[range | int] | Default
    condition: Callable[[], bool] = always_true
    at_least: int = 1

    def sample(self, value: int) -> bool:
        if not self.condition():
            return False

        if (isinstance(self.target, list)
            and any(((isinstance(x, range) and value not in x)
                     or (isinstance(x, int) and value != x))
                    for x in self.target)):
            return False

        return True


@dataclass
class Sequence:
    port: Port
    target: list[range | int] | Default
    at_least: int = 1
    condition: Callable[[], bool] = always_true
    _idx = 0

    def reset(self) -> None:
        self._idx = 0

    def sample(self, value: int) -> bool:
        if not self.condition():
            return False

        if isinstance(self.target, list):
            current = self.target[self._idx]
            if ((isinstance(current, range) and value not in current)
                or (isinstance(current, int) and value != current)):
                self._idx = 0
                return False

            if self._idx < len(self.target) - 1:
                self._idx += 1
                return False

        self._idx = 0
        return True


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
    cg = CoverGroup(DUT.from_dut(dut))


    await cocotb.start(generate_clock(dut))

    await Timer(Decimal(4), units='ns')
    await FallingEdge(dut.clk)


    print(cg.report())
