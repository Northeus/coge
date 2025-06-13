import json
from dataclasses import dataclass
from pathlib import Path
from textwrap import shorten

import dacite


# ──────────────────────────[ ⚙️  Raw Dataset  ⚙️ ]──────────────────────────

DATASET_FOLDER = Path(__file__).resolve().parent / 'dataset'
DATASET_FILENAME = 'dataset.json'


@dataclass(frozen=True)
class _CrossEntry:
    port: str | None = None
    value: tuple[int, int] | None = None
    values: list[int] | None = None


@dataclass(frozen=True)
class _Coverpoint:
    port: str | None = None
    value: tuple[int, int] | None = None
    values: list[int] | None = None
    sequence: list[int] | None = None
    cross: list[_CrossEntry] | None = None
    at_least: int | None = None


@dataclass(frozen=True)
class _Requirement:
    description: str
    coverpoints: list[_Coverpoint]


@dataclass(frozen=True)
class _Design:
    name: str
    description_file: str
    design_file: str
    requirements: list[_Requirement]


# ────────────────────────────[ ⚙️  Dataset  ⚙️ ]────────────────────────────

@dataclass(frozen=True)
class CoverValue:
    port: str
    value_range: tuple[int, int]
    at_least: int = 1


@dataclass(frozen=True)
class CoverValues:
    port: str
    values: list[int]
    at_least: int = 1


@dataclass(frozen=True)
class CoverSequence:
    port: str
    sequence: list[int]
    at_least: int = 1


@dataclass(frozen=True)
class CoverCross:
    coverpoints: list[CoverValue | CoverValues]


Coverpoint = CoverValue | CoverValues | CoverSequence | CoverCross


@dataclass(frozen=True)
class Requirement:
    description: str
    coverpoints: list[Coverpoint]


@dataclass(frozen=True)
class Design:
    name: str
    description: str
    design: Path
    requirements: list[Requirement]


def _parse_entry(_entry: _CrossEntry) -> CoverValue | CoverValues:
    types = (_entry.value, _entry.values)
    assert sum(x is not None for x in types) == 1

    if _entry.value is not None:
        assert _entry.port is not None
        return CoverValue(_entry.port, _entry.value)
    if _entry.values is not None:
        assert _entry.port is not None
        return CoverValues(_entry.port, _entry.values)

    assert False


def _parse_coverpoint(_cp: _Coverpoint) -> Coverpoint:
    types = (_cp.value, _cp.values, _cp.sequence, _cp.cross)
    assert sum(x is not None for x in types) == 1

    if _cp.value is not None:
        assert _cp.port is not None
        return CoverValue(_cp.port, _cp.value, _cp.at_least or 1)
    if _cp.values is not None:
        assert _cp.port is not None
        return CoverValues(_cp.port, _cp.values, _cp.at_least or 1)
    if _cp.sequence is not None:
        assert _cp.port is not None
        return CoverSequence(_cp.port, _cp.sequence, _cp.at_least or 1)
    if _cp.cross is not None:
        assert _cp.port is None
        return CoverCross(list(map(_parse_entry, _cp.cross)))

    assert False


def _parse_design(_design: _Design, folder: Path) -> Design:
    description = (folder / _design.description_file).read_text()
    code_file = folder / _design.design_file
    requirements = [Requirement(req.description,
                                list(map(_parse_coverpoint, req.coverpoints)))
                    for req in _design.requirements]
    assert code_file.exists()
    return Design(_design.name, description, code_file, requirements)


def load(dataset_file: Path) -> list[Design]:
    raw_json = json.loads(dataset_file.read_text())
    config=dacite.Config(cast=[tuple])
    _designs = [dacite.from_dict(_Design, entity, config)
                for entity in raw_json]
    folder = dataset_file.resolve().parent
    return [_parse_design(_design, folder) for _design in _designs]


# ─────────────────────────[ ⚙️  Print dataset  ⚙️ ]─────────────────────────

def _print_coverpoint(cp: Coverpoint, prefix: str = '') -> None:
    at_least = lambda x: f'at least {x.at_least}' if x.at_least > 1 else ''
    print(prefix, end='')
    match cp:
        case CoverValue():
            print(f'[{cp.port}] value in {cp.value_range} {at_least(cp)}')
        case CoverValues():
            print(f'[{cp.port}] values {cp.values} {at_least(cp)}')
        case CoverSequence():
            print(f'[{cp.port}] sequence {cp.sequence} {at_least(cp)}')
        case CoverCross():
            print('Cross:')
            for cross_cp in cp.coverpoints:
                _print_coverpoint(cross_cp, prefix + '  ')


def main() -> None:
    dataset = load(DATASET_FOLDER / DATASET_FILENAME)
    cut = lambda x: shorten(x, width=65, placeholder='...')

    for design in dataset:
        print(f'Design {design.name}:')
        print(f'  "{cut(design.description)}"')
        print(f'  at "{design.design}"')

        if design.requirements:
            print('  Requirements:')
        for req in design.requirements:
            print(f'    {cut(req.description)}')
            for cp in req.coverpoints:
                _print_coverpoint(cp, '      ')


if __name__ == '__main__':
    main()
