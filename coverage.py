from collections import deque
from dataclasses import dataclass, field
from functools import reduce
from itertools import product
from operator import mul
from typing import Callable


# ──────────────────────────[ ⚙️  Hidden logic  ⚙️ ]──────────────────────────

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

    def percentage(self) -> float:
        total = 0
        done = 0

        for cp in self.coverpoints:
            total += len(cp.bins)
            total += len(cp.sequences)
            done += sum(x.hits >= x.at_least for x in cp.bins)
            done += sum(x.hits >= x.at_least for x in cp.sequences)

        for cross in self.crosses:
            total += len(cross.cross)
            done += sum(x > 0 for x in cross.hits)

        return done / total

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


class CoverageSizeError(Exception):
    pass


def _bin(coverpoint: Coverpoint,
         target: list[Bin],
         values: tuple[int, int] | int,
         at_least: int = 1,
         *,
         limit_count: int = 1000
         ) -> Bin:
    bin = Bin(coverpoint.port,
              (values, values) if isinstance(values, int) else values,
              at_least=at_least)
    target.append(bin)

    if sum((len(coverpoint.bins),
           len(coverpoint.ignore_bins),
           len(coverpoint.illegal_bins),
           len(coverpoint.sequences))) > limit_count:
        raise CoverageSizeError

    return bin


# ───────────────────────────[ ⚙️  Public API  ⚙️ ]───────────────────────────

def coverpoint(port: str) -> Coverpoint:
    coverpoint = Coverpoint(port)
    return coverpoint


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


def cross(bin_groups: list[list[Bin]], *, count_limit: int = 1000) -> Cross:
    if reduce(mul, map(len, bin_groups)) > count_limit:
        raise CoverageSizeError

    return Cross(list(product(*bin_groups)))


_PORT_WIDTH_CALLBACK: Callable[[str], int] | None = None
def register_port_width(callback: Callable[[str], int]) -> None:
    global _PORT_WIDTH_CALLBACK
    _PORT_WIDTH_CALLBACK = callback


def port_width(port: str) -> int:
    # For static analysis purposes only, replaced in the testbench environment
    global _PORT_WIDTH_CALLBACK
    assert _PORT_WIDTH_CALLBACK is not None
    return _PORT_WIDTH_CALLBACK(port)

