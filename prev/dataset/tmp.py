from dataclasses import dataclass
from typing import Literal


@dataclass(frozen=True)
class Coverpoint:
    @dataclass(frozen=True)
    class Cross:
        port: str
        value: tuple[int, int] | None = None
        values: list[int] | None = None

    port: str
    value: tuple[int, int] | None = None
    values: list[int] | None = None
    sequence: list[int] | None = None
    cross: list[Cross] | None = None
    at_least: int | None = None
    bin_type: Literal['normal', 'illegal', 'ignore'] | None = None


@dataclass(frozen=True)
class Requirement:
    description: str
    coverpoints: list[Coverpoint]


@dataclass(frozen=True)
class ALU:
    @dataclass(frozen=True)
    class Operation:
        name: str
        output_length: int = 1
        compute_duration: int = 1

    @dataclass(frozen=True)
    class SimpleOperands:
        first: str
        second: str
        width: int

    @dataclass(frozen=True)
    class ComplexOperands:
        names: list[str]
        selector: str

    operations: list[Operation]
    operation_selector: str
    operands: SimpleOperands | ComplexOperands
    result: str
    operands_width: int



    activate: str
    valid: str


    def generate_requirements(self) -> list[Requirement]:
        ...



## Verification requirements:

# Generic:
'Check result contained smallest and largest value.'
''
''
''

# If more than two operands:
''
''
''
''

#  If operation with duration > 1:
''
''
''
''

#
''
''
''
''
''
