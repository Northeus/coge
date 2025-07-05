from __future__ import annotations

from dataclasses import dataclass
from itertools import chain, cycle
from typing import Literal, TypeVar, TYPE_CHECKING

if TYPE_CHECKING:
    from _typeshed import DataclassInstance


# ───────────────────────[ ⚙️  Coverage Comparision ⚙️ ]──────────────────────











ValueRange = tuple[int, int]
ComparisonResult = Literal['==', '>=', 'other']


@dataclass(frozen=True)
class Bins:
    port: str
    illegal: list[ValueRange]
    ignored: list[ValueRange]
    normal: list[ValueRange]






    def illegal_values(self) -> set[int]:
        return {i for r in self.illegal for i in range(r[0], r[1] + 1)}

    # Return set of unignored values ensuring the values that were
    # in a single range (one of) are kept in a single item.
    # (value ranges are split into multiple values that are ordered)
    # TODO: Might be optimized to work using intervals.
    def unignored_values(self) -> set[tuple[int, ...]]:
        ignored = set(chain.from_iterable((range(x, y + 1)
                                           for x, y in self.ignored)))
        unignored = set()
        for x, y in self.normal:
            values = set(range(x, y + 1))
            unignored.add(tuple(sorted(values - ignored)))
        return unignored

    @classmethod
    def compare(cls, a: list[Bins], b: list[Bins]) -> ComparisonResult:
        illegal_a = {}
        illegal_b = {}
        for values, result in ((a, illegal_a), (b, illegal_b)):
            for bins in values:
                result.setdefault(bins.port, set()).update(
                        bins.unignored_values())
        if illegal_a != illegal_b:
            return 'other'

        unignored_a = {}
        unignored_b = {}
        for values, result in ((a, unignored_a), (b, unignored_b)):
            for bins in values:
                result.setdefault(bins.port, set()).update(
                        bins.unignored_values())

        if unignored_a == unignored_b:
            return '=='

        for port, values in unignored_b.items():
            for value in values:
                value = set(value)
                if not any(x >= value for x in map(set, unignored_a.get(port, []))):
                    return 'other'

        return '>='


T = TypeVar('T', bound=DataclassInstance)


def compare(a: list[T], b: list[T]) -> ComparisonResult:
    used_exact_indices = set()
    found_exact = 0
    for seq_b in b:
        exact = [i for i, seq_a in enumerate(a) if seq_a == seq_b]
        found_exact += len(exact) > 0
        used_exact_indices |= set(exact)

    if found_exact == len(b):
        return '==' if len(used_exact_indices) == len(a) else '>='
    return 'other'


@dataclass(frozen=True)
class Sequence:
    port: str
    sequence: list[int]
    at_least: int

    @classmethod
    def compare(cls, a: list[Sequence], b: list[Sequence]) -> ComparisonResult:
        return compare(a, b)


@dataclass(frozen=True)
class Cross:
    ports: tuple[str, ...]
    values: tuple[list[ValueRange], ...]

    # Order each value in item in cross based on port names and values.
    def normalize(self) -> Cross:
        assert len(self.values) == len(self.ports)
        assert len(self.ports) == len(set(self.ports))
        data = sorted(zip(self.ports, self.values), key=lambda x: x[0])
        data = [(port, sorted(values)) for port, values in data]
        ports, values = zip(*data)
        return Cross(ports, values)

    @classmethod
    def compare(cls,
                a: list[Cross],
                b: list[Cross],
                ports_width: dict[str, int]
                ) -> ComparisonResult:
        a = [x.normalize() for x in a]
        b = [x.normalize() for x in b]
        return compare(a, b)


# ───────────────────────────────[ ⚙️    ⚙️ ]───────────────────────────────


# ───────────────────────────────[ ⚙️  TMP  ⚙️ ]───────────────────────────────

from pathlib import Path

import runner
import generation
import coverage as cg
import dataset


models = ('deepseek-r1_14b', 'gemma3_12b', 'qwen3_14b')
root = Path(__file__).parent.resolve()

for model in models:
    for i in range(5):
        print(f'{model} ({i}):')
        result = runner.Results.load(root
                                     / 'generated'
                                     / f'result_{model}_{i}.json').results[0]
        coverage = generation.DesignCoverage.load_data(root
                                                       / 'generated'
                                                       / f'coverage_{model}_{i}.json')[0]

        ports = {x[0]: x[1] for x in result.ports.sizes}
        _dataset = dataset.load(root / 'dataset' / 'dataset.json')[0]

        good = 0
        for j, s in enumerate(result.status):
            if s != 'ok':
                continue
            code = coverage.coverage[j].code
            assert code
            locals = {}
            exec(code, None, locals)
            coverpoints = [x for x in locals.values()
                           if isinstance(x, cg.Coverpoint)]
            crosses = [x for x in locals.values() if isinstance(x, cg.Cross)]

            generated = []
            for value in locals:
                match value:
                    case cg.Coverpoint():
                        # Values -> Value
                        #
                    case cg.Cross():
                        ...

            desired = [] ... # change CoverValues into CoveraValue


            # comparison

            bins_a = [Bins(cp.port,
                           [],
                           [],
                           [])
                      for cp in coverpoints]
            sequences_a = [Sequence(s.port, list(s.sequence), s.at_least)
                           for s in chain.from_iterable(x.sequences
                                                        for x in coverpoints)]
            crosses_a = []

            print(f'code:\n{code}')
            print('---------------')
            print(f'desired: {_dataset.requirements[j].coverpoints}')
            print('---------------')
            print(f'result: {result}')
            print('===============')
            input()




"""
from operator import eq
from pathlib import Path

import runner
import generation
import coverage as cg
import dataset


models = ('deepseek-r1_14b', 'gemma3_12b', 'qwen3_14b')
root = Path(__file__).parent.resolve()

for model in models:
    complex_coverage = 0
    coverage_status = [0] * 16
    status_stats = {}
    print(model)
    for i in range(5):
        data = runner.Results.load(root
                                   / 'generated'
                                   / f'result_{model}_{i}.json')
        assert len(data.results) == 1
        data = data.results[0]

        if isinstance(data.coverage, str):
            print(model, f'{i}: problem with coverage')
        else:
            # print(data.coverage[-1])
            was_ok = True
            for info in data.coverage:
                if info.statement < 0.9:
                    continue

                if info.statement < info.functional:
                    was_ok = False
                    break

            if not was_ok:
                print(model, f'{i}: weak coverage')

            complex_coverage += 1

        good = 0
        for j, s in enumerate(data.status):
            #good += s in ('ok', 'too large', 'timeout')
            good += s == 'ok'
            # coverage_status[j] += s in ('ok', 'too large', 'timeout')
            coverage_status[j] += s == 'ok'
            status_stats[s] = status_stats.setdefault(s, 0) + 1
        print(f'{i}:', good)

        coverage = generation.DesignCoverage.load_data(root
                                       / 'generated'
                                       / f'coverage_{model}_{i}.json')[0]
        ports = {x[0]: x[1] for x in data.ports.sizes}
        gm = dataset.load(root / 'dataset' / 'dataset.json')

        exact = 0
        good = 0
        for j, s in enumerate(data.status):
            if s != 'ok':
                continue
            code = coverage.coverage[j].code
            assert code
            locals = {}
            exec(code, None, locals)

            coverpoints = [x for x in locals.values()
                           if isinstance(x, cg.Coverpoint)]
            crosses = [x for x in locals.values() if isinstance(x, cg.Cross)]

            done = 0
            used = set()
            for cp in gm[0].requirements[j].coverpoints:
                if isinstance(cp, dataset.CoverSequence):
                    for ii, c in enumerate(coverpoints):
                        for s in c.sequences:
                            if s.port != c.port:
                                continue
                            if list(s.sequence) == cp.sequence:
                                done += 1
                                used.add(s)
                                break
                    continue

                if isinstance(cp, dataset.CoverValue):
                    # not entirely true, what if it is split, can still be good...
                    for ii, c in enumerate(coverpoints):
                        for b in c.bins:
                            if b.port != c.port:
                                continue
                            if b.value_range == cp.value_range:
                                done += 1
                                used.add(b)
                                break
                    continue

                if isinstance(cp, dataset.CoverValues):
                    found = 0
                    for val in cp.values:
                        for ii, c in enumerate(coverpoints):
                            for b in c.bins:
                                if b.port != c.port:
                                    continue
                                if b.value_range == (val, val):
                                    found += 1
                                    used.add(b)
                                    break
                    done += found == len(cp.values)
                    continue

                if isinstance(cp, dataset.CoverCross):
                    # also wrong
                    for cc in crosses:
                        break
                    continue


                assert False


            if done == len(gm[0].requirements[j].coverpoints):
                good += 1
                # not entirely true, if duplicites occure, or is it?
                if len(used) == (sum(len(x.bins)
                                     + len(x.sequences) for x in coverpoints)
                                 + len(crosses)):
                    exact += 1

        print(good, exact)

    for code in snippets:
        signal.signal(signal.SIGALRM, _timeout_handler)
        try:
            signal.alarm(5)
            signal.alarm(0)
        except TimeoutError as e:
            errors.append('timeout')
            continue
        except CoverageSizeError:
            errors.append('too large')
            continue
        except Exception as e:
            errors.append('code error')
            continue
        finally:
            signal.alarm(0)

    print(coverage_status)
    print(status_stats)
    print()
    # print(model, 'complex coverage', complex_coverage)
"""
