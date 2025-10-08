# TODO: refactor this mess


import contextlib
import os
from argparse import ArgumentParser
from itertools import count
from pathlib import Path
from typing import Literal, NamedTuple

import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from natsort import natsorted

import coverage
import dataset
import pipeline


ATTEMPTS = 5


Value = tuple[int, int]


class Bin(NamedTuple):
    cat: Literal["normal", "illegal"]
    port: str
    value: Value
    at_least: int = 1


class Sequence(NamedTuple):
    port: str
    sequence: tuple[int, ...]
    at_least: int = 1


class Cross(NamedTuple):
    ports: tuple[str, ...]
    bins: tuple[tuple[Value, ...], ...]


def avg(data: list[int]) -> float:
    return 0 if len(data) == 0 else sum(data) / len(data)


def cov_from_sim(
    cp: list[coverage.Coverpoint], crosses: list[coverage.Cross]
) -> set[Bin | Sequence | Cross]:
    result = set()
    for c in cp:
        for i in c.illegal_bins:
            lower, upper = i.value_range
            result |= {Bin("illegal", c.port, (x, x)) for x in range(lower, upper + 1)}
        for n in c.bins:
            filtered = [n.value_range]
            for i in c.ignore_bins:
                unignored = []
                for f in filtered:
                    li, ui = i.value_range
                    lf, uf = f
                    if lf <= uf < li:
                        unignored.append((lf, uf))
                    elif lf < li and li <= uf <= ui:
                        unignored.append((lf, li - 1))
                    elif lf < li and ui < uf:
                        unignored.append((lf, li - 1))
                        unignored.append((ui + 1, uf))
                    elif li <= lf <= uf <= ui:
                        pass
                    elif li <= lf <= ui and ui < uf:
                        unignored.append((ui + 1, uf))
                    elif ui < lf <= uf:
                        unignored.append((lf, uf))
                    else:
                        assert False
                filtered = unignored
            result |= {Bin("normal", c.port, x, n.at_least) for x in filtered}
        for s in c.sequences:
            result.add(Sequence(c.port, tuple(s.sequence), s.at_least))
    for c in crosses:
        if not all(len({y.port for y in x}) == len(x) for x in c.cross):
            continue
        data = [(x.port, set()) for x in c.cross[0]]
        for line in c.cross:
            for i, b in enumerate(line):
                data[i][1].add(b.value_range)
        data.sort(key=lambda x: x[0])
        result.add(
            Cross(
                tuple(sorted(x for x, _ in data)),
                tuple(tuple(sorted(x)) for _, x in data),
            )
        )
    return result


def cov_from_dataset(
    cp: list[dataset.Coverpoint], crosses: list[dataset.Cross]
) -> set[Bin | Sequence | Cross]:
    result = set()
    for c in cp:
        for i in c.illegal_values:
            lower, upper = i.one if isinstance(i, dataset.OneValue) else i.all
            result |= {Bin("illegal", c.port, (x, x)) for x in range(lower, upper + 1)}
        for n in c.values:
            if isinstance(n, dataset.OneValue):
                result.add(Bin("normal", c.port, n.one, c.at_least))
            else:
                lower, upper = n.all
                result |= {
                    Bin("normal", c.port, (x, x), c.at_least)
                    for x in range(lower, upper + 1)
                }
        for s in c.sequences:
            result.add(Sequence(c.port, tuple(s), c.at_least))
    for _c in crosses:
        c = sorted(_c.cross, key=lambda x: x.port)
        cross_values = []
        for e in c:
            values = []
            for v in e.values:
                if isinstance(v, dataset.AllValues):
                    lower, upper = v.all
                    values += [(x, x) for x in range(lower, upper + 1)]
                else:
                    values.append(v.one)
            cross_values.append(tuple(sorted(values)))
        result.add(Cross(tuple(x.port for x in c), tuple(cross_values)))
    return result


def load_desired() -> dict[str, list[set[Bin | Sequence | Cross]]]:
    data = dataset.load(Path(__file__).parent.resolve() / "dataset" / "data.json")
    desired = {}
    for design in data:
        cov = []
        for req in design.requirements:
            cov.append(
                cov_from_dataset(
                    [x for x in req.coverpoints if isinstance(x, dataset.Coverpoint)],
                    [x for x in req.coverpoints if isinstance(x, dataset.Cross)],
                )
            )
        desired[design.top] = cov
    return desired


def main() -> None:
    parser = ArgumentParser()
    parser.add_argument("results_dir", type=Path)
    args = parser.parse_args()
    assert isinstance(args.results_dir, Path) and args.results_dir.is_dir()

    results = {}
    for result_file in args.results_dir.iterdir():
        results[result_file.name.removesuffix(".json")] = pipeline.Result.load_data(
            result_file
        )
    ordered_model_names = natsorted(results.keys())

    # syntactically correct table
    print("=" * 80)
    print("Syntax and feasibility+ports table (max, min, avg):")
    print("-" * 80)
    for model in ordered_model_names:
        _data = results[model]
        synt = [sum(y != "code error" for y in x.simulation.status) for x in _data]
        comp = [sum(y == "ok" for y in x.simulation.status) for x in _data]
        print(
            model,
            "|",
            max(synt),
            min(synt),
            avg(synt),
            "|",
            max(comp),
            min(comp),
            avg(comp),
        )
    print("=" * 80)

    # Required static analysis plot
    model_correct_result = {}
    for model, batch in results.items():
        stats = [0] * 4
        for _data in batch:
            for gen, sim in zip(_data.coverage, _data.simulation.status):
                if sim == "ok":
                    stats[len(gen.code) - 1] += 1
        model_correct_result[model] = stats

    x = np.array([0, 1, 2, 3])
    groups_n = len(model_correct_result)
    bar_width = 0.1
    mid = (groups_n - 1) / 2
    offsets = np.linspace(-mid * bar_width, mid * bar_width, groups_n)
    colors = sns.color_palette("pastel", groups_n)
    for i, model in enumerate(ordered_model_names):
        heights = model_correct_result[model]
        plt.bar(x + offsets[i], heights, width=bar_width, label=model, color=colors[i])
    plt.xticks(x, list(map(str, x)))
    plt.xlabel("Number of retries with provided logs")
    plt.ylabel("Number of syntactically correct code instances")
    plt.legend(title="Models")
    plt.tight_layout()
    plt.show()

    # Complexity table
    print("=" * 80)
    print("Complexity (out of 5)")
    print("-" * 80)
    for model in ordered_model_names:
        comp = 0
        for _data in results[model]:
            if isinstance(_data.simulation.coverage, list):
                comp += all(
                    x.statement > x.functional and x.functional != 0
                    for x in _data.simulation.coverage
                    if x.statement >= 0.9
                )
        print(model, "|", comp)
    print("-" * 80)
    print("In convergence region:")
    for model in ordered_model_names:
        for _data in results[model]:
            if isinstance(_data.simulation.coverage, list):
                if any(x.functional >= 0.9 for x in _data.simulation.coverage):
                    print(model, "managed to obtain 0.9 functional coverage.")
    print("=" * 80)

    # Statistics about requirements category
    print("=" * 80)
    print("Number of requirements per category:")
    print("-" * 80)
    categories_cnt = {}
    designs = dataset.load(Path(__file__).parent.resolve() / "dataset" / "data.json")
    for design in designs:
        for req in design.requirements:
            categories_cnt[req.target] = categories_cnt.get(req.target, 0) + 1
    for category, cnt in categories_cnt.items():
        print(category, cnt)
    print("=" * 80)

    # Accuracy histograms
    desired = load_desired()
    model_accuracy = {}
    requirement_accuracy = {}
    req_targets = ["bin", "sequence", "cross"]
    model_req_acc = {}
    for model, batch in results.items():
        accuracy = []
        req_acc = [0] * len(req_targets)
        for _data in batch:
            port_widths = {port: size for port, size in _data.simulation.ports.sizes}
            coverage.register_port_width(lambda x: port_widths[x])
            accurate = 0
            design = next(d for d in designs if d.top == _data.top)
            req_targets_id_map = {
                i: next(j for j, y in enumerate(req_targets) if y == x.target)
                for i, x in enumerate(design.requirements)
            }
            for i, gen, sim in zip(count(), _data.coverage, _data.simulation.status):
                if sim == "ok" and gen.code[-1][0] == "ok":
                    locals = {}
                    with (
                        open(os.devnull, "w") as fnull,
                        contextlib.redirect_stdout(fnull),
                    ):
                        exec(gen.code[-1][1], locals=locals)
                    coverpoints = [
                        x for x in locals.values() if isinstance(x, coverage.Coverpoint)
                    ]
                    crosses = [
                        x for x in locals.values() if isinstance(x, coverage.Cross)
                    ]
                    generated = cov_from_sim(coverpoints, crosses)
                    target = desired[_data.top][i]
                    ok = generated >= target
                    accurate += ok
                    req_acc[req_targets_id_map[i]] += ok
                    model_req_acc.setdefault(model, [0] * len(req_targets_id_map))
                    model_req_acc[model][i] += ok
            accuracy.append(accurate)
        model_accuracy[model] = accuracy
        requirement_accuracy[model] = req_acc
    print("=" * 80)
    print("Accuracy and more table (max, min, avg):")
    print("-" * 80)
    _data = []
    _data_req = []
    x_labels = ["best", "worst", "mean"]
    for model in ordered_model_names:
        acc = model_accuracy[model]
        print(model, "|", max(acc), min(acc), avg(acc))
        _data.append([max(acc), min(acc), avg(acc)])
        _data_req.append(requirement_accuracy[model])
    print("=" * 80)

    _data = np.array(_data) * 100.0 / 16.0
    plt.figure(figsize=(6, 5))
    sns.heatmap(
        _data,
        annot=True,
        cmap="RdYlGn",
        fmt=".2f",
        linewidths=0.5,
        xticklabels=x_labels,
        yticklabels=ordered_model_names,
        cbar_kws={"label": "Accuracy (%)"},
        cbar=True,
        vmax=100,
        annot_kws={"fontweight": "bold"},
    )
    plt.title("Accuracy of LLMs per generated instances")
    plt.ylabel("LLM")
    plt.xlabel("Considered instances")
    plt.tight_layout()
    plt.show()

    req_norm = np.array([categories_cnt[x] for x in req_targets]) * ATTEMPTS
    _data_req = np.array(_data_req) * 100.0 / req_norm
    plt.figure(figsize=(6, 5))
    sns.heatmap(
        _data_req,
        annot=True,
        cmap="RdYlGn",
        fmt=".2f",
        linewidths=0.5,
        xticklabels=req_targets,
        yticklabels=ordered_model_names,
        cbar_kws={"label": "Accuracy (%)"},
        cbar=True,
        vmax=100,
        annot_kws={"fontweight": "bold"},
    )
    plt.title("Accuracy of LLMs per requirement target")
    plt.ylabel("LLM")
    plt.xlabel("Targeted functional coverage constructs")
    plt.tight_layout()
    plt.show()

    _data_model_req = []
    x_labels_req = list(map(str, range(1, 17)))
    for model in ordered_model_names:
        _data_model_req.append(model_req_acc[model])
    plt.figure(figsize=(6, 5))
    sns.heatmap(
        _data_model_req,
        annot=True,
        cmap="RdYlGn",
        linewidths=0.5,
        xticklabels=x_labels_req,
        yticklabels=ordered_model_names,
        cbar=False,
        vmax=ATTEMPTS,
        annot_kws={"fontweight": "bold"},
    )
    plt.title("Accuracy of LLMs per requirement")
    plt.ylabel("LLM")
    plt.xlabel("Requirement id")
    plt.tight_layout()
    plt.show()
    # Based on previous plot
    print("=" * 80)
    print("Selected requirements:")
    print("-" * 80)
    design = designs[0]
    for i, req in enumerate(design.requirements):
        print(f"{i}.", req.description)
    print("=" * 80)


if __name__ == "__main__":
    main()
