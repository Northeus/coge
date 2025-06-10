import subprocess
from pathlib import Path

from cocotb.runner import get_runner


TEST = True
TRANSACTIONS = 1000

SIM = 'verilator'
ROOT = Path(__file__).resolve().parent
SOURCES = [ROOT / 'arithmetic_unit.sv']
TOPLEVEL = 'arithmetic_unit'


def run():
    if TEST:
        # Run tests.
        runner = get_runner(SIM)
        runner.build(sources=SOURCES, hdl_toplevel=TOPLEVEL,
                     always=True, clean=True,
                     build_args=['--coverage'])

        x = runner.test(hdl_toplevel=TOPLEVEL,
                        test_module='test_arithmetic_unit',
                        extra_env={'TRANSACTIONS': str(TRANSACTIONS)})
        print(f'Tests done, result ({type(x)}): {x}')

        # Generate code coverage.
        cmd = ('verilator_coverage --annotate logs '
               'sim_build/coverage.dat --annotate-min 1 '
               '--annotate-all')
        subprocess.run(cmd.split(' '), check=True)

    # Process code coverage.
    def process_line(line: str) -> int | None:
        if not line.startswith(' '):
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


if __name__ == '__main__':
    run()
