import argparse
import json
import subprocess
import timeit
from dataclasses import dataclass
from datetime import datetime, timedelta
from pathlib import Path
from typing import Literal

import dacite
from cocotb.runner import get_runner

import generation
import testbench


# ─────────────────────────────[ ⚙️  Config  ⚙️ ]─────────────────────────────

# Project structure.
ROOT_DIR = Path(__file__).resolve().parent
TMP_DIR = ROOT_DIR / 'tmp'

# Simulation.
SIMULATOR = 'verilator'


# ─────────────────────────────[ ⚙️  Runner  ⚙️ ]─────────────────────────────


@dataclass(frozen=True)
class Result:
    result: testbench.Result
    code_coverage: list[int | None]

TestResult = Result | Literal['test failed', 'code coverage failed']


def _load_line_code_coverage(file: Path) -> list[int | None] | None:
    def process_line(line: str) -> int | None:
        if line[0:1] not in ' %~+-':
            return None
        line = line[1:]
        hits, _, _ = line.partition(' ')
        return int(hits) if hits.isdecimal() else None

    try:
        code_coverage_log = file.read_text()
        return [process_line(x) for x in code_coverage_log.splitlines()))
    except Exception:
        return None


def run(dut: Path,
        top_level: str,
        coverage_snippets: list[str],
        *,
        seed: int | None = None,
        reset_probability: float | None,
        clock_limit: int = 1000,
        clock_steps: int = 1
        ) -> list[TestResult]:
    TMP_DIR.mkdir(parents=True, exist_ok=True)
    date = datetime.now().now().strftime('%Y-%m-%d_%H-%S-%f')
    test_dir = TMP_DIR / f'test_{top_level}_{date}'
    test_dir.mkdir(parents=True, exist_ok=False)
    build_dir = test_dir / 'build'

    runner = get_runner(SIMULATOR)
    runner.build(sources=[dut],
                 hdl_toplevel=top_level,
                 build_dir=build_dir,
                 always=True,
                 clean=True,
                 build_args=['--coverage'])

    env = {
        'TB_CODE': str(dut),
        'TB_RESET_PROB': str(reset_probability or 0.0),
    }
    if seed is not None:
        env['TB_SEED'] = str(seed)
    max_i = len(str(len(coverage_snippets)))

    results = []
    for i, snippet in enumerate(coverage_snippets):
        step = clock_limit // clock_steps
        for limit in range(step, clock_limit + 1, step):
            work_dir = test_dir / f'snippet_{str(i).zfill(max_i)}_{limit}'
            work_dir.mkdir(parents=True)
            cov_file = work_dir / 'coverage.py'
            cov_file.write_text(snippet)
            result_file = work_dir / 'result.json'

            try:
                runner.test(hdl_toplevel=top_level,
                            test_module='testbench',
                            build_dir=build_dir,
                            test_dir=work_dir,
                            extra_env=_env)
            except Exception:
                results.append('test failed')
                continue

            coverage_cmd = ['verilator_coverage', f'{build_dir}/coverage.dat',
                            '--annotate-min', '1', '--annotate-all']

            if subprocess.run(coverage_cmd, check=True).returncode != 0:
                results.append('code coverage failed')
                continue

            code_coverage = _load_line_code_coverage(work_dir / 'logs' / dut.name)
            result = testbench.Result.load(result_file)

            if code_coverage is None:
                results.append('code coverage failed')
                continue

            results.append(Result(result, code_coverage))

    assert len(results) == len(coverage_snippets)
    return results


# ───────────────────────────────[ ⚙️  Run  ⚙️ ]───────────────────────────────

def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('coverage_file', type=Path)
    parser.add_argument('-S', '--seed', type=int)
    parser.add_argument('-r', '--reset_probability', type=float, default=0.0)
    parser.add_argument('-c', '--clock_limit', type=int, default=1000)
    parser.add_argument('-t', '--clock_steps', type=int, default=1)

    args = parser.parse_args()
    print('Executing testbench with following params')
    print(f' Coverage    = {args.coverage_file}')
    print(f' Seed        = {args.seed if args.seed is not None else 'None'}')
    print(f' Reset prob. = {args.reset_probability}')
    print(f' Clock limit = {args.clock_limit}')
    print(f' Clock steps = {args.clock_steps}')

    coverage_file = args.coverage_file
    coverage_data = generation.DesignCoverage.load_data(coverage_file)

    for design_coverage in coverage_data:
        result = run(design_coverage.design,
                     design_coverage.top,
                     design_coverage.snippets,
                     seed=args.seed,
                     reset_probability=args.reset_probability,
                     clock_limit=args.clock_limit,
                     clock_steps=args.clock_steps)

    ...


if __name__ == '__main__':
    main()
