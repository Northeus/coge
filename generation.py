from __future__ import annotations

import argparse
import dataclasses
import json
import logging
import re
from dataclasses import dataclass
from functools import partial
from pathlib import Path

import dacite
from alive_progress import alive_it
from ollama import chat

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
    op_bins = normal_bins(\'OP\', (0, 7))
    zero_bin = normal_bin(\'REG_A\', 1)
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

Example of the conversation:
User: Ensure all values of OP port are checked
Assistant: ```python
max_op = 2 ** port_width('OP') - 1
op_bins = normal_bins('OP', (0, max_op))
```"""

TASK_PROMPT_TEMPLATE = """Description of the module:
#[DESCRIPTION]

The requirement is:
#[REQUIREMENT]"""


# ───────────────────────────[ ⚙️  Generation  ⚙️ ]───────────────────────────

def generate_coverage(model: str, description: str, requirement: str) -> str:
    prompt = (TASK_PROMPT_TEMPLATE.replace('#[DESCRIPTION]', description)
              .replace('#[REQUIREMENT]', requirement))
    response = chat(model=model,
                    messages=[{'role': 'system', 'content': SYSTEM_PROMPT},
                              {'role': 'user', 'content': prompt}])

    message = response.message.content
    assert message is not None

    pattern = r'```(?:\w+\n)(.*?)```'
    snippets = re.findall(pattern, message, re.DOTALL)
    assert len(snippets) > 0
    if len(snippets) > 1:
        logger = logging.getLogger(__name__)
        logger.warning(f'Multiple snippets found:\n{message}')
    return snippets[-1]


@dataclass
class DesignCoverage:
    design: Path
    top: str
    snippets: list[str]

    @classmethod
    def load_data(cls, data_file: Path) -> list[DesignCoverage]:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[Path])
        return [dacite.from_dict(cls, x, config) for x in data]


def generate(dataset_file: Path, model: str) -> list[DesignCoverage]:
    data = dataset.load(dataset_file)
    coverage = {}
    for design, requirement in alive_it([(d, r)
                                         for d in data
                                         for r in d.requirements]):
        code = generate_coverage(model,
                                 design.description,
                                 requirement.description)
        coverage.setdefault(id(design), []).append(code)

    return [DesignCoverage(d.design, d.name, coverage[id(d)]) for d in data]


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
