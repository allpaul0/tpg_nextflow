#!/usr/bin/env python3
"""Look for Dispatch/Team latency stat collisions inside latencies.json files.

Scans every <root>/**/inference/results/*/latencies.json (the usual layout being
<root>/<tpg>/training_results/<params>/inference/results/<config>/) and, for each
file, checks whether a Dispatch entry has exactly the same (AvgCycles, StddevCycles,
CoefficientVariation) triplet as a Team entry of the same file. DispatchSize and
Count are ignored on purpose.

Such an exact match is suspicious: the per-dispatch stats should never coincide
digit for digit with per-team stats, so a hit usually means the profiling code
mixed up the two counters.

Usage:
    python check_dispatch_team_collisions.py <root> [--same-section-only]
                                             [--skip-degenerate] [--json]

    <root>                path holding the TPG folders (e.g. armlearn-tpgs)
    --same-section-only   only compare a Dispatch with the Teams of the very same
                          section (default: compare against every Teams list of
                          the file, e.g. instrTeams_instrTPG too)
    --skip-degenerate     drop matches with stddev == 0 and coefvar == 0: a team
                          made of a single dispatch legitimately produces those,
                          so they are coincidences rather than bugs
    --json                dump the matches as JSON instead of the text report
"""

import argparse
import glob
import json
import os
import sys
from typing import Dict, List


DISPATCH_KEYS = ("AvgCyclesPerDispatch", "StddevCyclesPerDispatch", "CoefficientVariation")
TEAM_KEYS = ("AvgCyclesPerTeam", "StddevCyclesPerTeam", "CoefficientVariation")


def find_latencies_files(root: str) -> List[str]:
    pattern = os.path.join(root, "**", "inference", "results", "*", "latencies.json")
    return sorted(glob.glob(pattern, recursive=True))


def stats(entry: Dict, keys) -> tuple:
    """(avg, stddev, coefvar) triplet of an entry, None if a field is missing."""
    if any(k not in entry for k in keys):
        return None
    return tuple(entry[k] for k in keys)


def collect(data: Dict, list_name: str) -> List[tuple]:
    """[(section, index, entry)] for every section of the file holding list_name."""
    out = []
    for section, content in data.items():
        if not isinstance(content, dict):
            continue
        for i, entry in enumerate(content.get(list_name, []) or []):
            if isinstance(entry, dict):
                out.append((section, i, entry))
    return out


def is_degenerate(d_stats: tuple) -> bool:
    """A zero stddev and zero coefvar match tells nothing: only the avg really matches."""
    return d_stats[1] == 0 and d_stats[2] == 0


def check_file(path: str, same_section_only: bool, skip_degenerate: bool) -> List[Dict]:
    with open(path) as fd:
        data = json.load(fd)

    dispatches = collect(data, "Dispatches")
    teams = collect(data, "Teams")

    matches = []
    for d_section, d_idx, dispatch in dispatches:
        d_stats = stats(dispatch, DISPATCH_KEYS)
        if d_stats is None or (skip_degenerate and is_degenerate(d_stats)):
            continue
        for t_section, t_idx, team in teams:
            if same_section_only and t_section != d_section:
                continue
            if stats(team, TEAM_KEYS) == d_stats:
                matches.append({
                    "file": path,
                    "avg": d_stats[0],
                    "stddev": d_stats[1],
                    "coefficient_variation": d_stats[2],
                    "dispatch_section": d_section,
                    "dispatch_index": d_idx,
                    "dispatch": dispatch,
                    "team_section": t_section,
                    "team_index": t_idx,
                    "team": team,
                })
    return matches


def main(argv: List[str] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("root", help="path holding the TPG folders (e.g. armlearn-tpgs)")
    parser.add_argument("--same-section-only", action="store_true",
                        help="only compare a Dispatch with the Teams of the same section")
    parser.add_argument("--skip-degenerate", action="store_true",
                        help="drop matches whose stddev and coefficient of variation are both 0")
    parser.add_argument("--json", dest="as_json", action="store_true", help="dump matches as JSON")
    args = parser.parse_args(argv)

    files = find_latencies_files(args.root)
    if not files:
        print(f"ERROR: no latencies.json found under {args.root}", file=sys.stderr)
        return 2

    all_matches = []
    files_with_dispatches = 0
    unreadable = []
    for path in files:
        try:
            with open(path) as fd:
                has_dispatch = any(
                    isinstance(v, dict) and v.get("Dispatches") for v in json.load(fd).values()
                )
        except (json.JSONDecodeError, OSError) as err:
            unreadable.append((path, str(err)))
            continue
        if has_dispatch:
            files_with_dispatches += 1
        all_matches.extend(check_file(path, args.same_section_only, args.skip_degenerate))

    if args.as_json:
        json.dump(all_matches, sys.stdout, indent=2)
        print()
        return 1 if all_matches else 0

    scope = "same section" if args.same_section_only else "whole file"
    filtered = ", zero-stddev matches dropped" if args.skip_degenerate else ""
    print(f"Scanned {len(files)} latencies.json ({files_with_dispatches} with Dispatches) under {args.root}")
    print(f"Comparison scope: {scope}{filtered}\n")

    for path, err in unreadable:
        print(f"WARNING: could not read {path}: {err}", file=sys.stderr)

    if not all_matches:
        print("No Dispatch/Team stat collision found.")
        return 0

    current = None
    for m in all_matches:
        if m["file"] != current:
            current = m["file"]
            print(current)
        print(f"  avg={m['avg']} stddev={m['stddev']} coefvar={m['coefficient_variation']}")
        print(f"    Dispatch[{m['dispatch_index']}] in {m['dispatch_section']}: {m['dispatch']}")
        print(f"    Team[{m['team_index']}] in {m['team_section']}: {m['team']}")

    hit_files = len({m["file"] for m in all_matches})
    print(f"\n{len(all_matches)} collision(s) in {hit_files} file(s).")
    return 1


if __name__ == "__main__":
    sys.exit(main())
