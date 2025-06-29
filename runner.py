from __future__ import annotations

import argparse
import dataclasses
import json
from collections import deque
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path

import dacite
from cocotb.runner import get_runner

import generation
import testbench


# ─────────────────────────────[ ⚙️  Runner  ⚙️ ]─────────────────────────────

def run(dut: Path,
        top_level: str,
        coverage_snippets: list[str],
        *,
        seed: int | None = None,
        clock_limit: int = 10000,
        cover_step: int = 100
        ) -> testbench.Result:
    rood_dir = Path(__file__).parent.resolve()
    tmp_dir = rood_dir / 'tmp'
    tmp_dir.mkdir(parents=True, exist_ok=True)
    #date = datetime.now().now().strftime('%Y-%m-%d_%H-%S-%f')
    #test_dir = tmp_dir / f'test_{top_level}_{date}'
    #test_dir.mkdir(parents=True, exist_ok=False)
    test_dir = tmp_dir / 'alu'
    build_dir = test_dir / 'build'

    runner = get_runner('verilator')
    runner.build(sources=[dut],
                 hdl_toplevel=top_level,
                 build_dir=build_dir,
                 always=True,
                 clean=True,
                 build_args=['--coverage',
                             '-LDFLAGS',
                             f'-L{rood_dir} -ldpi'])

    coverage_file = test_dir / 'coverage.json'
    coverage_file.write_text(json.dumps(coverage_snippets))
    result_file = test_dir / 'result.json'
    env = {
        'TB_CODE': str(dut),
        'TB_COVERAGE': str(coverage_file),
        'TB_CLOCK_LIMIT': str(clock_limit),
        'TB_COVER_STEP': str(cover_step),
        'TB_RESULT': str(result_file)
    }
    if seed is not None:
        env['TB_SEED'] = str(seed)

    runner.test(hdl_toplevel=top_level,
                test_module='testbench',
                build_dir=build_dir,
                test_dir=test_dir,
                extra_env=env)

    return testbench.Result.load(result_file)


# ─────────────────────────────[ ⚙️  Process  ⚙️ ]─────────────────────────────

@dataclass(frozen=True)
class Results:
    results: list[testbench.Result]

    def save(self, data_file: Path) -> None:
        def deque_default(obj: object) -> object:
            if isinstance(obj, deque):
                return list(obj)
            raise TypeError

        data_file.write_text(json.dumps(dataclasses.asdict(self),
                                        default=deque_default))

    @classmethod
    def load(cls, data_file: Path) -> Results:
        data = json.loads(data_file.read_text())
        config = dacite.Config(cast=[tuple, deque])
        return dacite.from_dict(Results, data, config)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('coverage_file', type=Path)
    parser.add_argument('-S', '--seed', type=int)
    parser.add_argument('-o', '--output', type=Path, default='results.json')
    parser.add_argument('-c', '--clock_limit', type=int, default=1000)
    parser.add_argument('-t', '--cover_step', type=int, default=10)

    args = parser.parse_args()
    coverage_data = generation.DesignCoverage.load_data(args.coverage_file)
    results = []
    for design_data in coverage_data:
        snippets = [(x.code if x.code is not None and x.status == 'ok' else 'None')
                    for x in design_data.coverage]
        results.append(run(design_data.design,
                           design_data.top,
                           snippets,
                           seed=args.seed,
                           clock_limit=args.clock_limit,
                           cover_step=args.cover_step))

    Results(results).save(args.output)


if __name__ == '__main__':
    main()
