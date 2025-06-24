"""
Keep all the code in the `evaluation.py` file for now.

Prepare data from evaluateion:
 - [ ] Load data produced from the datatest.
 - [ ] Make run function to process dataset.
 - [ ] Load data produced from the testbenches.
 - [ ] Mark ground truth (our) data and generated (for now again our) data.
 - [ ] Check that proposed requirements in dataset are in our and generated data.
 - [ ] Gather statistics about complexity including:
   * Number of bins and sequences including their size or length.
   * Size of the cross.
   * Number of cross inputs.
   * Counts per port (including name and direction).
 - [ ] Statistic about syntax and other errors causing problems.
 - [ ] Do not forget about code and functional coverage total statistic (counts).

Prepare for LLM evaluation:
 - [ ] Add callback to generate data, for now just copy our data.

Present the data:
 - [ ] Plot code vs functional coverage for each evalued thing.
 - [ ] Create table containing all numeric and categoric stuff.
 - [ ] Create evaluation function, that take statistics and return value.
 - [ ] Create graph from the evaluation function.

Document the results:
 - [ ] Final results structure.
"""


from dataclasses import dataclass
from pathlib import Path

import dataset
import runner


# ───────────────────────────[ ⚙️  Evaluation  ⚙️ ]───────────────────────────

@dataclass(frozen=True)
class CoverageCode:
    design: str
    code: str


def evaluate(dataset_file: Path,
             coverages: list[CoverageCode],
             config: runner.Config = runner.Config()) -> None:
    designs = dataset.load(dataset_file)
    design_name_coverages = {}
    for cov in coverages:
        design_name_coverages.setdefault(cov.design, list()).append(cov.code)

    dataset_dir = dataset_file.parent
    params = [runner.TestParams(dataset_dir / design.design,
                                design.name,
                                design_name_coverages[design.name])
              for design in designs]
    results = runner.run_all(params, config)



    ...
    print(results)


# ────────────────────────────[ ⚙️  Example  ⚙️ ]────────────────────────────

def main() -> None:
    dataset_file = dataset.DATASET_FOLDER / dataset.DATASET_FILENAME
    evaluate(dataset_file, [CoverageCode('ALU', runner.COVERAGE)])


if __name__ == '__main__':
    main()
