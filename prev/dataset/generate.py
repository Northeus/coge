from dataclasses import dataclass
from typing import Literal


# ──────────────────────────────[ ⚙️  Utils  ⚙️ ]──────────────────────────────

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


# ───────────────────────────[ ⚙️  Computation  ⚙️ ]───────────────────────────

@dataclass(frozen=True)
class ALU:
    @dataclass(frozen=True)
    class SimpleOperations:
        names: list[str]

    @dataclass(frozen=True)
    class ComplexOperations:
        names: list[str]
        activate: str
        valid: str

    @dataclass(frozen=True)
    class SimpleOperands:
        first: str
        second: str

    @dataclass(frozen=True)
    class ComplexOperands:
        names: list[str]
        selector: str

    operations: SimpleOperations | ComplexOperations
    operations_selector: str
    operands: SimpleOperands | ComplexOperands
    result: str
    width: int
    clock: str
    reset: str | None

    def generate_requirements(self) -> list[Requirement]:
        # Cross cover all MOVI with all OP
        # Check all OP were used
        #
        #
        #
        #
        #
        #
        #
        #
        #
        #
        #
        #
        #
        #
        ...

    def generate_design(self) -> str:
        ...


# ─────────────────────────────[ ⚙️  Control  ⚙️ ]─────────────────────────────

@dataclass(frozen=True)
class FSM:
    states: int
    inputs: list[str]
    outputs: list[str]
    trigger: str
    clock: str
    reset: str

    def generate_requirements(self) -> list[Requirement]:
        ...

    def generate_design(self) -> str:
        # generate random ifs... from inputs to outputs and states
        ...


# ──────────────────────────[ ⚙️  Communication  ⚙️ ]──────────────────────────

@dataclass(frozen=True)
class Bus:
    inputs: list[str]
    outputs: list[str]
    messages: list[int]
    trigger: str
    clock: str
    reset: str
    width: int

    def generate_requirements(self) -> list[Requirement]:
        ...

    def generate_design(self) -> str:
        # generate random ifs... from inputs based on messages
        # some chachance for chained signals (dependence between)
        ...


# ───────────────────────────[ ⚙️  Generation  ⚙️ ]───────────────────────────
