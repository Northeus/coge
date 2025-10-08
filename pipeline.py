from __future__ import annotations

import json
from argparse import ArgumentParser
from collections import deque
from dataclasses import asdict, dataclass
from pathlib import Path

import dacite
from alive_progress import alive_bar

import dataset
import generation
import testbench


@dataclass(frozen=True)
class Result:
    top: str
    coverage: list[generation.GeneratedCoverage]
    simulation: testbench.Result

    @staticmethod
    def save_data(data_file: Path, data: list[Result]) -> None:
        def deque_default(obj: object) -> object:
            if isinstance(obj, deque):
                return list(obj)
            raise TypeError

        data_file.write_text(json.dumps(list(map(asdict, data)), default=deque_default))

    @staticmethod
    def load_data(data_file: Path) -> list[Result]:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[tuple, deque])
        return [dacite.from_dict(Result, x, config) for x in data]


def main() -> None:
    parser = ArgumentParser()
    parser.add_argument("model", type=str)
    parser.add_argument("-o", "--output", type=Path, default="results.json")
    args = parser.parse_args()

    data_file = Path(__file__).parent.resolve() / "dataset" / "data.json"
    data = dataset.load(data_file)
    for design in data:
        print(f"Design: {design.top} ({len(design.requirements)} req.)")
    print()

    generated_per_design = []
    attempts = 5
    total = sum(len(x.requirements) for x in data) * attempts
    with alive_bar(total, title="Generating requirements") as bar:
        for design in data:
            for _ in range(attempts):
                generated = []
                for req in [x.description for x in design.requirements]:
                    generated.append(generation.generate(req, args.model))
                    bar()
                generated_per_design.append((design, generated))

    seed = 42
    results = []
    data_dir = Path(__file__).parent.resolve()
    for design, coverage in generated_per_design:
        snippets = [
            (x.code[-1][1] if x.code[-1][0] == "ok" else "invalid=code")
            for x in coverage
        ]
        rslt = testbench.run(
            testbench.Params(
                duv=data_dir / design.code,
                top_level=design.top,
                coverage_snippets=snippets,
                seed=seed,
                clock_limit=10000,
                coverage_step=100,
            )
        )
        results.append(Result(top=design.top, coverage=coverage, simulation=rslt))
    Result.save_data(args.output, results)


if __name__ == "__main__":
    main()
