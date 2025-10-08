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
REQUIREMENT_TARGETS = ["bin", "sequence", "cross"]
DEFAULT_HEATMAP_KWARGS = {
    "cmap": "RdYlGn",
    "linewidths": 0.5,
    "annot_kws": {"fontweight": "bold"},
}
FLOAT_HEATMAP_KWARGS = {**DEFAULT_HEATMAP_KWARGS, "fmt": ".2f"}

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


def filter_range(value: Value, ignore: Value) -> list[Value]:
    unignored = []
    lover_ignore, upper_ignore = ignore
    lover_value, upper_value = value

    if lover_value <= upper_value < lover_ignore:
        unignored.append((lover_value, upper_value))
    elif lover_value < lover_ignore and lover_ignore <= upper_value <= upper_ignore:
        unignored.append((lover_value, lover_ignore - 1))
    elif lover_value < lover_ignore and upper_ignore < upper_value:
        unignored.append((lover_value, lover_ignore - 1))
        unignored.append((upper_ignore + 1, upper_value))
    elif lover_ignore <= lover_value <= upper_value <= upper_ignore:
        pass
    elif lover_ignore <= lover_value <= upper_ignore and upper_ignore < upper_value:
        unignored.append((upper_ignore + 1, upper_value))
    elif upper_ignore < lover_value <= upper_value:
        unignored.append((lover_value, upper_value))
    else:
        assert False

    return unignored


def normalize_coverage(
    coverpoints: list[coverage.Coverpoint], crosses: list[coverage.Cross]
) -> set[Bin | Sequence | Cross]:
    result = set()

    for coverpoint in coverpoints:
        for lower, upper in (x.value_range for x in coverpoint.illegal_bins):
            result |= {
                Bin("illegal", coverpoint.port, (x, x)) for x in range(lower, upper + 1)
            }

        for normal in coverpoint.bins:
            filtered = [normal.value_range]
            for ignore in coverpoint.ignore_bins:
                unignored = []
                for unfiltered_range in filtered:
                    unignored += filter_range(unfiltered_range, ignore.value_range)
                filtered = unignored

            result |= {
                Bin("normal", coverpoint.port, x, normal.at_least) for x in filtered
            }

        result |= {
            Sequence(coverpoint.port, tuple(s.sequence), s.at_least)
            for s in coverpoint.sequences
        }

    for cross in crosses:
        if not all(len({y.port for y in x}) == len(x) for x in cross.cross):
            continue

        data = [(x.port, set()) for x in cross.cross[0]]
        for line in cross.cross:
            for ignore, b in enumerate(line):
                data[ignore][1].add(b.value_range)

        data.sort(key=lambda x: x[0])
        result.add(
            Cross(
                tuple(sorted(x for x, _ in data)),
                tuple(tuple(sorted(x)) for _, x in data),
            )
        )

    return result


def desired_coverage(
    coverpoints: list[dataset.Coverpoint], crosses: list[dataset.Cross]
) -> set[Bin | Sequence | Cross]:
    result = set()
    for coverpoint in coverpoints:
        for illegal in coverpoint.illegal_values:
            lower, upper = (
                illegal.one if isinstance(illegal, dataset.OneValue) else illegal.all
            )
            result |= {
                Bin("illegal", coverpoint.port, (x, x)) for x in range(lower, upper + 1)
            }

        for normal in coverpoint.values:
            if isinstance(normal, dataset.OneValue):
                result.add(
                    Bin("normal", coverpoint.port, normal.one, coverpoint.at_least)
                )
            else:
                lower, upper = normal.all
                result |= {
                    Bin("normal", coverpoint.port, (x, x), coverpoint.at_least)
                    for x in range(lower, upper + 1)
                }

        for sequence in coverpoint.sequences:
            result.add(Sequence(coverpoint.port, tuple(sequence), coverpoint.at_least))

    for cross in crosses:
        cross_entries = sorted(cross.cross, key=lambda x: x.port)
        cross_values = []
        for entry in cross_entries:
            values = []
            for value in entry.values:
                if isinstance(value, dataset.AllValues):
                    lower, upper = value.all
                    values += [(x, x) for x in range(lower, upper + 1)]
                else:
                    values.append(value.one)
            cross_values.append(tuple(sorted(values)))

        result.add(Cross(tuple(x.port for x in cross_entries), tuple(cross_values)))

    return result


def load_coverage(code: str) -> set[Bin | Sequence | Cross]:
    locals = {}
    with (
        open(os.devnull, "w") as fnull,
        contextlib.redirect_stdout(fnull),
    ):
        exec(code, locals=locals)

    coverpoints = [x for x in locals.values() if isinstance(x, coverage.Coverpoint)]
    crosses = [x for x in locals.values() if isinstance(x, coverage.Cross)]

    return normalize_coverage(coverpoints, crosses)


def load_desired() -> dict[str, list[set[Bin | Sequence | Cross]]]:
    data = dataset.load(Path(__file__).parent.resolve() / "dataset" / "data.json")
    desired = {}
    for design in data:
        desired[design.top] = [
            desired_coverage(
                [x for x in req.coverpoints if isinstance(x, dataset.Coverpoint)],
                [x for x in req.coverpoints if isinstance(x, dataset.Cross)],
            )
            for req in design.requirements
        ]
    return desired


def load_results(folder: Path) -> dict[str, list[pipeline.Result]]:
    results = {}
    for result_file in folder.iterdir():
        if result_file.suffix != ".json":
            continue

        results[result_file.name.removesuffix(".json")] = pipeline.Result.load_data(
            result_file
        )

    return results


def compute_accuracies(
    results: dict[str, list[pipeline.Result]],
    designs: list[dataset.Design],
    desired: dict[str, list[set[Bin | Sequence | Cross]]],
    match_exactly: bool = False,
) -> tuple[
    dict[str, list[int]],
    dict[str, list[int]],
    dict[str, list[int]],
]:
    model_accuracy = {}
    targets_accuracies = {}
    model_requirement_accuracy = {}
    for model, batch in results.items():
        accuracy = []
        targets_accuracy = [0] * len(REQUIREMENT_TARGETS)
        for data in batch:
            accurate_code = 0
            port_widths = {port: size for port, size in data.simulation.ports.sizes}
            coverage.register_port_width(lambda x: port_widths[x])
            design = next(d for d in designs if d.top == data.top)

            requirement_target_id_map = {
                i: next(j for j, y in enumerate(REQUIREMENT_TARGETS) if y == x.target)
                for i, x in enumerate(design.requirements)
            }

            for i, gen, sim in zip(count(), data.coverage, data.simulation.status):
                if not (sim == "ok" and gen.code[-1][0] == "ok"):
                    continue

                generated = load_coverage(gen.code[-1][1])
                target = desired[data.top][i]

                ok = generated == target if match_exactly else generated >= target

                accurate_code += ok
                targets_accuracy[requirement_target_id_map[i]] += ok
                model_requirement_accuracy.setdefault(
                    model, [0] * len(requirement_target_id_map)
                )
                model_requirement_accuracy[model][i] += ok

            accuracy.append(accurate_code)

        model_accuracy[model] = accuracy
        targets_accuracies[model] = targets_accuracy

    return model_accuracy, targets_accuracies, model_requirement_accuracy


def code_summary_table(
    results: dict[str, list[pipeline.Result]], models: list[str]
) -> None:
    print("=" * 80)
    print("Syntax and feasibility+ports table (max, min, avg)")
    print("-" * 80)

    for model in models:
        result = results[model]
        correct_syntax = [
            sum(y != "code error" for y in x.simulation.status) for x in result
        ]
        feasible_complexity = [
            sum(y == "ok" for y in x.simulation.status) for x in result
        ]
        print(
            f"{model}:",
            (
                max(correct_syntax),
                min(correct_syntax),
                avg(correct_syntax),
            ),
            ",",
            (
                max(feasible_complexity),
                min(feasible_complexity),
                avg(feasible_complexity),
            ),
        )


def coverage_complexity_table(
    results: dict[str, list[pipeline.Result]], models: list[str]
) -> None:
    print("=" * 80)
    print("Complexity (total instances complex enough out of 5)")
    print("-" * 80)

    for model in models:
        feasible_complexity = 0
        for result in results[model]:
            if isinstance(result.simulation.coverage, list):
                feasible_complexity += all(
                    x.statement > x.functional and x.functional != 0
                    for x in result.simulation.coverage
                    if x.statement >= 0.9
                )
        print(model, "|", feasible_complexity)

    print("-" * 80)
    print("In convergence region (managed to obtain 0.9 functional coverage)")
    print("-" * 80)

    for model in models:
        over_threshold = 0
        for result in results[model]:
            if isinstance(result.simulation.coverage, list):
                over_threshold += any(
                    x.functional >= 0.9 for x in result.simulation.coverage
                )
        print(f"{model}: {over_threshold} / {len(results[model])}")


def categories_count_table(categories: dict[str, int]) -> None:
    print("=" * 80)
    print("Number of requirements per category")
    print("-" * 80)

    for category, count in categories.items():
        print(category, count)


def plot_retries(results: dict[str, list[pipeline.Result]], models: list[str]) -> None:
    retries = {}
    for model, batch in results.items():
        retrie_counts = [0] * 4
        for data in batch:
            for gen, sim in zip(data.coverage, data.simulation.status):
                if sim == "ok":
                    retrie_counts[len(gen.code) - 1] += 1

        retries[model] = retrie_counts

    x_axis = np.array([0, 1, 2, 3])
    groups_n = len(retries)

    bar_width = 0.1
    mid = (groups_n - 1) / 2
    offsets = np.linspace(-mid * bar_width, mid * bar_width, groups_n)
    colors = sns.color_palette("pastel", groups_n)

    for i, model in enumerate(models):
        y_axis = retries[model]
        plt.bar(
            x_axis + offsets[i], y_axis, width=bar_width, label=model, color=colors[i]
        )

    plt.xticks(x_axis, list(map(str, x_axis)))
    plt.xlabel("Number of retries with provided logs")
    plt.ylabel("Number of syntactically correct code instances")
    plt.legend(title="Models")
    plt.tight_layout()
    plt.show()


def accuracy_table(
    model_accuracy: dict[str, list[int]],
    models: list[str],
) -> None:
    print("=" * 80)
    print("Accuracy table (max, min, avg)")
    print("-" * 80)

    for model in models:
        acc = model_accuracy[model]
        print(f"{model}:", (max(acc), min(acc), avg(acc)))


def requirements_table(
    designs: list[dataset.Design],
) -> None:
    for design in designs:
        print("=" * 80)
        print(f"Requirements for {design.top}")
        print("-" * 80)

        for i, req in enumerate(design.requirements):
            print(f"{i}.", req.description)


def plot_accuracies(
    model_accuracy: dict[str, list[int]],
    models: list[str],
) -> None:
    data = []
    for model in models:
        acc = model_accuracy[model]
        data.append([max(acc), min(acc), avg(acc)])

    x_labels = ["best", "worst", "mean"]
    data = np.array(data) * 100.0 / 16.0

    plt.figure(figsize=(6, 5))
    sns.heatmap(
        data,
        annot=True,
        xticklabels=x_labels,
        yticklabels=models,
        cbar_kws={"label": "Accuracy (%)"},
        cbar=True,
        vmax=100,
        **FLOAT_HEATMAP_KWARGS,
    )

    plt.title("Accuracy of LLMs per generated instances")
    plt.ylabel("LLM")
    plt.xlabel("Considered instances")
    plt.tight_layout()
    plt.show()


def plot_target_accuracies(
    categories_count: dict[str, int],
    targets_accuracies: dict[str, list[int]],
    models: list[str],
) -> None:
    data = [targets_accuracies[model] for model in models]
    req_norm = np.array([categories_count[x] for x in REQUIREMENT_TARGETS]) * ATTEMPTS
    data = np.array(data) * 100.0 / req_norm

    plt.figure(figsize=(6, 5))
    sns.heatmap(
        data,
        annot=True,
        xticklabels=REQUIREMENT_TARGETS,
        yticklabels=models,
        cbar_kws={"label": "Accuracy (%)"},
        cbar=True,
        vmax=100,
        **FLOAT_HEATMAP_KWARGS,
    )

    plt.title("Accuracy of LLMs per requirement target")
    plt.ylabel("LLM")
    plt.xlabel("Targeted functional coverage constructs")
    plt.tight_layout()
    plt.show()


def plot_requirement_accuracies(
    model_requirement_accuracy: dict[str, list[int]],
    models: list[str],
) -> None:
    data = [model_requirement_accuracy[model] for model in models]
    x_labels = list(map(str, range(1, 17)))

    plt.figure(figsize=(6, 5))
    sns.heatmap(
        np.array(data),
        annot=True,
        xticklabels=x_labels,
        yticklabels=models,
        cbar=False,
        vmax=ATTEMPTS,
        **DEFAULT_HEATMAP_KWARGS,
    )

    plt.title("Accuracy of LLMs per requirement")
    plt.ylabel("LLM")
    plt.xlabel("Requirement id")
    plt.tight_layout()
    plt.show()


def main() -> None:
    parser = ArgumentParser()
    parser.add_argument("results_dir", type=Path)
    args = parser.parse_args()
    assert isinstance(args.results_dir, Path) and args.results_dir.is_dir()

    results = load_results(args.results_dir)
    ordered_model_names = natsorted(results.keys())
    designs = dataset.load(Path(__file__).parent.resolve() / "dataset" / "data.json")
    desired = load_desired()
    model_accuracy, targets_accuracies, model_requirement_accuracy = compute_accuracies(
        results, designs, desired
    )

    categories_count = {}
    for design in designs:
        for requirement in design.requirements:
            categories_count[requirement.target] = (
                categories_count.get(requirement.target, 0) + 1
            )

    code_summary_table(results, ordered_model_names)
    coverage_complexity_table(results, ordered_model_names)
    categories_count_table(categories_count)
    accuracy_table(model_accuracy, ordered_model_names)
    requirements_table(designs)

    plot_retries(results, ordered_model_names)
    plot_accuracies(model_accuracy, ordered_model_names)
    plot_target_accuracies(categories_count, targets_accuracies, ordered_model_names)
    plot_requirement_accuracies(model_requirement_accuracy, ordered_model_names)


if __name__ == "__main__":
    main()
