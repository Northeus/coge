from pathlib import Path

from cocotb.runner import get_runner

from testbench import Coverage


# ───────────────────────────────[ ⚙️  .  ⚙️ ]───────────────────────────────

SIM = 'verilator'
ROOT = Path(__file__).resolve().parent
SOURCES = [ROOT / 'dataset' / 'designs' / 'ALU.sv']
TOPLEVEL = 'ALU'


def run() -> None:
    rslt_file = ROOT / 'data.json'

    runner = get_runner(SIM)
    runner.build(sources=SOURCES, hdl_toplevel=TOPLEVEL,
                 always=False, clean=False,
                 build_args=['--coverage'])
    x = runner.test(hdl_toplevel=TOPLEVEL,
                    test_module='testbench',
                    extra_env={'TB_CODE': str(SOURCES[0]),
                               'TB_RESULT': str(rslt_file)})
    print(f'Tests done, result ({type(x)}): {x}')
    data = Coverage.load(rslt_file)
    data.print()


def main() -> None:
    run()


if __name__ == '__main__':
    main()


"""
# TODO:
# - [ ] Create demo that:
#   * Create some coverage examples (multiple)
#   * Generate some testbenches for DUT arithmetic_unit using that coverage.
#   * Create reports.
import json
import subprocess
from pathlib import Path

import dacite
import matplotlib.pyplot as plt
from cocotb.runner import get_runner

from test_arithmetic_unit import Bin, Sequence, Coverpoint, Cross, Result
from test_arithmetic_unit import print_coverage


SIM = 'verilator'
ROOT = Path(__file__).resolve().parent
CLEAN = False
SOURCES = [ROOT / 'arithmetic_unit.sv']
TOPLEVEL = 'arithmetic_unit'


def run(*, transactions: int = 100) -> list[int]:
    # Run tests.
    runner = get_runner(SIM)
    runner.build(sources=SOURCES, hdl_toplevel=TOPLEVEL,
                 always=CLEAN, clean=CLEAN,
                 build_args=['--coverage'])

    x = runner.test(hdl_toplevel=TOPLEVEL,
                    test_module='test_arithmetic_unit',
                    extra_env={'TRANSACTIONS': str(transactions)})
    print(f'Tests done, result ({type(x)}): {x}')

    # Generate code coverage.
    cmd = ('verilator_coverage --annotate logs '
           'sim_build/coverage.dat --annotate-min 1 '
           '--annotate-all')
    subprocess.run(cmd.split(' '), check=True)

    # Process code coverage.
    def process_line(line: str) -> int | None:
        if line[0:1] not in ' %~+-':
            return None
        line = line[1:]
        hits, _, _ = line.partition(' ')
        return int(hits) if hits.isdecimal() else None
    code_coverage_logs = (ROOT / 'logs' / 'arithmetic_unit.sv').read_text()
    code_coverage_all= map(process_line, code_coverage_logs.splitlines())
    code_coverage = [x for x in code_coverage_all if x is not None]
    print('Code coverage:')
    print(f'\tMin: {min(code_coverage)}')
    print(f'\tMax: {max(code_coverage)}')
    print(f'\tAvg: {sum(code_coverage) / len(code_coverage)}')
    return code_coverage


def load_func_cov() -> Result:
    func_dict = json.loads((ROOT / 'func.json').read_text())
    return dacite.from_dict(data_class=Result,
                            data=func_dict,
                            config=dacite.Config(cast=[tuple]))


def compute_func_cov(data: Result) -> float:
    total = 0
    covered = 0

    for coverpoint in data.coverpoints:
        total += len(coverpoint.bins)
        total += len(coverpoint.sequences)
        covered += sum(x.hits > 0 for x in coverpoint.bins)
        covered += sum(x.hits > 0 for x in coverpoint.sequences)

    for cross in data.crosses:
        total += len(cross.hits)
        covered += sum(x > 0 for x in cross.hits)

    return covered / total


def multiple_runs():
    transactions_list = list(range(50))
    code_cov = []
    func_cov = []
    for transactions in transactions_list:
        code_cov_data = run(transactions=transactions)
        code_cov.append(sum(x > 0 for x in code_cov_data) / len(code_cov_data))
        func_cov_data = load_func_cov()
        func_cov.append(compute_func_cov(func_cov_data))

    plt.plot(transactions_list, code_cov, label='code')
    plt.plot(transactions_list, func_cov, label='func')
    plt.xlabel('Transactions')
    plt.ylabel('Coverage')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    # run(transactions=1000000)
    multiple_runs()
"""
