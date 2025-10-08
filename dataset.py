from __future__ import annotations

import json
from dataclasses import dataclass, field
from pathlib import Path
from typing import Literal

import dacite


@dataclass(frozen=True)
class Design:
    top: str
    code: Path
    requirements: list[Requirement]


@dataclass(frozen=True)
class Requirement:
    description: str
    coverpoints: list[Coverpoint | Cross]
    target: Literal["bin", "sequence", "cross"]


@dataclass(frozen=True)
class Coverpoint:
    port: str
    values: list[Values] = field(default_factory=list)
    illegal_values: list[Values] = field(default_factory=list)
    sequences: list[Sequence] = field(default_factory=list)
    at_least: int = 1


@dataclass(frozen=True)
class Cross:
    cross: list[CrossEntry]


@dataclass(frozen=True)
class CrossEntry:
    port: str
    values: list[Values]


@dataclass(frozen=True)
class AllValues:
    all: tuple[int, int]


@dataclass(frozen=True)
class OneValue:
    one: tuple[int, int]


Values = AllValues | OneValue
Sequence = list[int]


@dataclass(frozen=True)
class _Design:
    top: str
    requirements: list[Requirement]


def load(dataset_file: Path) -> list[Design]:
    data = json.loads(dataset_file.read_text())
    config = dacite.Config(cast=[tuple])
    designs = [dacite.from_dict(_Design, entity, config) for entity in data]
    folder = dataset_file.resolve().parent
    return [
        Design(
            top=design.top,
            code=folder / f"{design.top}.sv",
            requirements=design.requirements,
        )
        for design in designs
    ]
