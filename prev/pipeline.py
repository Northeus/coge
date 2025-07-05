import os
import subprocess
from pathlib import Path


ROOT = Path(__file__).parent.resolve()


for model in ('deepseek-r1_14b', 'gemma3_12b', 'qwen3_14b'):
    for i in range(5):
        args = [
            'python',
            'runner.py',
            '-S',
            '42',
            '-c',
            '1000',
            '-t',
            '10',
            '-o',
            f'generated/result_{model}_{i}.json',
            f'generated/coverage_{model}_{i}.json'
        ]
        subprocess.run(args, check=True)
