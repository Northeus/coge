from __future__ import annotations

import argparse
import dataclasses
import io
import json
import logging
import re
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Literal

import dacite
from alive_progress import alive_it
from mypy import api
from ollama import chat
from pylint import lint
from pylint.reporters import text

import dataset


# ─────────────────────────────[ ⚙️  Prompts  ⚙️ ]─────────────────────────────

SYSTEM_PROMPT = """You are a verification engineer whose goal is to \
implement a functional coverage code snippet using the provided API \
in a Python based on the provided requirement. Provide just \
the snippet based on the requirement without any additional \
functionality, DO NOT IMPLEMENT THE API!

The API for the functional coverage is as follows:
def coverpoint(port: str) -> Coverpoint:
    \"\"\"Create coverpoint for a port given its name.\"\"\"

def normal_bin(coverpoint: Coverpoint,
               values: tuple[int, int] | int,
               at_least: int = 1
               ) -> Bin:
    \"\"\"
    Create bin for a coverpoint checking that a single
    value (int) or a value within a range represented
    using tuple (including both sides) is sampled during
    the test.
    \"\"\"

def normal_bins(coverpoint: Coverpoint,
                values_range: tuple[int, int],
                at_least: int = 1
                ) -> list[Bin]:
    \"\"\"
    Create bins for a coverpoint checking that all
    values within a range represented by tuple
    (including both sides) is sampled during the test.
    \"\"\"

def ignore_bin(coverpoint: Coverpoint,
               values: tuple[int, int] | int,
               at_least: int = 1
               ) -> Bin:
    \"\"\"
    Create bin for a coverpoint ignoring a single
    value (int) or a value within a range represented
    using tuple (including both sides) is sampled during
    the test, making the values unable to be sampled by
    a `normal_bin`.
    \"\"\"

def illegal_bin(coverpoint: Coverpoint,
                values: tuple[int, int] | int,
                at_least: int = 1
                ) -> Bin:
    \"\"\"
    Create bin for a coverpoint checking that a single
    value (int) or a value within a range represented
    using tuple (including both sides) is never sampled
    during the test as it resemble an error.
    \"\"\"

def sequence(coverpoint: Coverpoint,
             sequence: list[int],
             at_least: int = 1,
             ) -> Sequence:
    \"\"\"
    Create sequence for a coverpoint checking that
    a transition between values specified as list of ints
    is sampled during the test.
    \"\"\"

def cross(bin_groups: list[list[Bin]]) -> Cross:
    \"\"\"
    Create a cross coverage, checking that all
    combinations of bins produced by a cartesian product
    on the list of lists of bins. Example of usage:
    ```python
    op = coverpoint('OP')
    op_bins = normal_bins(op, (0, 7))
    reg_a = coverpoint('REG_A')
    zero_bin = normal_bin(reg_a, 1)
    op_x_zero = cross([op_bins, [zero_bin]])
    ```
    \"\"\"

def port_width(name: str) -> int:
    \"\"\"
    Return the size of port in bits given its name.
    To get the max value of a given port, you can do:
    ```python
    2 ** port_width(\'REG_A\') - 1
    ```
    \"\"\"

Please ensure all functional coverage objects returned \
by the API are stored in variables to be used later! \
Provide just the required code!

Examples of the conversation:
User: Ensure all values of OP port are checked, furthermore check that all values OP were checked against one fromt the first 3 values of SEL.
Assistant: ```python
from coverage import *

op = coverpoint('OP')
max_op = 2 ** port_width('OP') - 1
op_bins = normal_bins(op, (0, max_op))

sel = coverpoint('SEL')
sel_bin = normal_bin(sel, (0, 2))

op_sel_cross = cross([op_bins, [sel_bin]])
```

User: Checks the transition 0 > 1 > 3 > 2 on DATA signal.
Assistant: ```python
from coverage import *

data = coverpoint('DATA')
seq = sequence(data, [0, 1, 3, 2])
```"""


# ───────────────────────────[ ⚙️  Generation  ⚙️ ]───────────────────────────

def _extract_code(message: str) -> str | None:
    pattern = r'```(?:\w+\n)(.*?)```'
    snippets = re.findall(pattern, message, re.DOTALL)

    if len(snippets) == 0:
        return None
    if len(snippets) > 1:
        logger = logging.getLogger(__name__)
        logger.warning(f'Multiple snippets found:\n{message}')

    return snippets[-1]


def _check_code(code: str) -> None | str:
    with tempfile.NamedTemporaryFile(mode='w', dir='./', suffix='.py') as tmp:
        logs = ''
        tmp.write(code)
        tmp.flush()

        buffer = io.StringIO()
        reporter = text.TextReporter(buffer)
        lint.Run([tmp.name, '--errors-only'], reporter=reporter, exit=False)
        if (pylint_log := buffer.getvalue()) != '':
            logs += f'Pylint logs:\n{pylint_log}'

        mypy_log_1, mypy_log_2, status = api.run([tmp.name,
                                                  '--follow-imports=silent'])
        if status != 0:
            mypy_log = mypy_log_1 + '\n' + mypy_log_2
            logs += ('' if logs == '' else '\n') + f'Mypy logs:\n{mypy_log}'

        return None if logs == '' else logs


@dataclass(frozen=True)
class Message:
    role: Literal['system', 'assistant', 'user']
    content: str


@dataclass(frozen=True)
class GeneratedCoverage:
    code: str | None
    messages: list[Message]
    status: Literal['ok', 'no code', 'invalid code'] = 'ok'


def generate_coverage(model: str, requirement: str) -> GeneratedCoverage:
    retries = 3
    messages = [
        Message('system', SYSTEM_PROMPT),
        Message('user', requirement)
    ]

    code = None
    status: Literal['ok', 'no code', 'invalid code'] = 'ok'
    for _ in range(1 + retries):
        response = chat(model=model,
                        messages=list(map(dataclasses.asdict, messages)))
        message = response.message.content
        assert message is not None
        messages.append(Message('assistant', message))

        code = _extract_code(message)
        if code is None:
            status = 'no code'
            messages.append(Message('user',
                                     'Please provide the code in ```py...```'))
            continue

        errors = _check_code(code)
        if errors is not None:
            status = 'invalid code'
            messages.append(Message('user', errors))
            continue

        break

    return GeneratedCoverage(code, messages, status)


@dataclass
class DesignCoverage:
    design: Path
    top: str
    coverage: list[GeneratedCoverage]

    @classmethod
    def load_data(cls, data_file: Path) -> list[DesignCoverage]:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[Path])
        return [dacite.from_dict(cls, x, config) for x in data]


def generate(dataset_file: Path, model: str) -> list[DesignCoverage]:
    data = dataset.load(dataset_file)
    coverages: dict[int, list[GeneratedCoverage]] = {}
    designs_requirements = [(d, r) for d in data for r in d.requirements]
    for design, requirement in alive_it(designs_requirements):
        coverage = generate_coverage(model, requirement.description)
        coverages.setdefault(id(design), []).append(coverage)

    return [DesignCoverage(d.design, d.name, coverages[id(d)]) for d in data]


def main() -> None:
    def _path_default(obj: object) -> object:
        if isinstance(obj, Path):
            return str(obj)
        raise TypeError

    parser = argparse.ArgumentParser()
    parser.add_argument('dataset_file', type=Path)
    parser.add_argument('-m', '--model', type=str, required=True)
    parser.add_argument('-o', '--output', type=Path, default='coverage.json')

    args = parser.parse_args()
    assert args.dataset_file.exists()

    coverage = generate(args.dataset_file, args.model)
    args.output.write_text(json.dumps(list(map(dataclasses.asdict, coverage)),
                                      default=_path_default))
    print(f'Stored generated coverage results in: {args.output}')


if __name__ == '__main__':
    main()
