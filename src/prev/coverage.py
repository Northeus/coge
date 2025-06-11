# TODO:
# - [ ] Validation for covergroups checking for possible generated nonsense.
#       (e.g., cross is too large, bin contains value otside registers range)
# - [ ] Add documentation.
from __future__ import annotations

import dataclasses
import json
from dataclasses import dataclass
from itertools import chain, product
from pathlib import Path

import dacite


@dataclass
class Bin:
    value_range: tuple[int, int]
    hits: int = 0

    def sample(self, value: int) -> bool:
        return self.value_range[0] <= value <= self.value_range[1]


@dataclass
class Sequence:
    sequence: list[int]
    index: int = 0

    def sample(self, value: int) -> bool:
        if value != self.sequence[self.index]:
            self.index = 0
            return False

        self.index = (self.index + 1) % len(self.sequence)
        return self.index == 0


@dataclass
class Coverpoint:
    port: str
    bins: list[tuple[Bin, int]]
    ignore_bins: list[Bin]
    sequences: list[tuple[Sequence, int]]


@dataclass
class Cross:
    cross: list[tuple[tuple[Bin, ...], int]]


@dataclass
class Covergroup:
    name: str
    coverpoints: list[Coverpoint]
    crosses: list[Cross]


def covergroup(name: str) -> Covergroup:
    return Covergroup(name, [], [])


def coverpoint(covergroup: Covergroup, port: str) -> Coverpoint:
    coverpoint = Coverpoint(port, [], [], [])
    covergroup.coverpoints.append(coverpoint)
    return coverpoint


def normal_bin(coverpoint: Coverpoint, values: tuple[int, int] | int) -> Bin:
    bin = Bin((values, values) if isinstance(values, int) else values)
    coverpoint.bins.append((bin, 0))
    return bin


def ignore_bin(coverpoint: Coverpoint, values: tuple[int, int] | int) -> Bin:
    bin = Bin((values, values) if isinstance(values, int) else values)
    coverpoint.ignore_bins.append(bin)
    return bin


def sequence(coverpoint: Coverpoint, sequence: list[int]) -> Sequence:
    seq = Sequence(sequence)
    coverpoint.sequences.append((seq, 0))
    return seq


def cross(bin_groups: list[list[Bin]]) -> Cross:
    return Cross([(y, 0) for y in product(*bin_groups)])


def store_covergroups(path: Path, covergroups: list[Covergroup]) -> None:
    data = json.dumps(list(map(dataclasses.asdict, covergroups)))
    path.write_text(data)


@classmethod
def load_covergroups(cls, path: Path) -> list[Covergroup]:
    data = json.loads(path.read_text())
    return [dacite.from_dict(data_class=cls,
                             data=covergroup,
                             config=dacite.Config(cast=[tuple]))
            for covergroup in data]


def sample(values: dict[str, int], covergroups: list[Covergroup]) -> None:
    hitted_bins_id: set[int] = set()

    for coverpoint in chain(*(cg.coverpoints for cg in covergroups)):
        value = values[coverpoint.port]

        coverpoint.sequences = [(seq, hit + int(seq.sample(value)))
                                for seq, hit in coverpoint.sequences]

        if any(ignored.sample(value) for ignored in coverpoint.ignore_bins):
            continue

        coverpoint.bins = [(bin, hit + int(bin.sample(value)))
                           for bin, hit in coverpoint.bins]
        hitted_bins_id |= {id(bin)
                           for bin, _ in coverpoint.bins if bin.sample(value)}

    for cross in chain(*(cg.crosses for cg in covergroups)):
        for i, data in enumerate(cross.cross):
            bins, hits = data
            if all(id(bin) in hitted_bins_id for bin in bins):
                cross.cross[i] = (bins, hits + 1)


def cover_exact_values(covergroup: Covergroup,
                       port: str,
                       values: tuple[int, int] | int
                       ) -> bool:
    value_range = (values, values) if isinstance(values, int) else values
    coverpoints = filter(lambda x: x.port == port, covergroup.coverpoints)
    return any(bin.value_range == value_range
               for coverpoint in coverpoints
               for bin, _ in coverpoint.bins)


def cover_sequence(covergroup: Covergroup,
                   port: str,
                   sequence: list[int]
                   ) -> bool:
    coverpoints = filter(lambda x: x.port == port, covergroup.coverpoints)
    return any(seq == sequence
               for coverpoint in coverpoints
               for seq, _ in coverpoint.sequences)


def print_coverage(covergroups: list[Covergroup]) -> None:
    bin_port_map = {bin: coverpoint.port
                    for covergroup in covergroups
                    for coverpoint in covergroup.coverpoints
                    for bin, _ in coverpoint.bins}

    for covergroup in covergroups:
        print(f'Covergroup {covergroup.name}:')

        for coverpoint in covergroup.coverpoints:
            print(f' - Coverpoint for port {coverpoint.port}]:')
            for bin, hits in coverpoint.bins:
                print(f'   * Bin {bin.value_range:>50} {hits:>10} hits')
            for sequence, hits in coverpoint.sequences:
                print(f'   * Sequence {sequence.sequence:>50} {hits:>10} hits')

        for cross in covergroup.crosses:
            ports = ' '.join(bin_port_map[bin] for bin in cross.cross[0][0])
            print(f' - Cross for ports {ports}:')
            for target, hits in enumerate(cross.cross):
                print(f'   * Target {target:>50} {hits:>10} hits')
