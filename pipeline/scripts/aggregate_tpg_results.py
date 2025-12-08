#!/usr/bin/env python3
# file: scripts/aggregate_tpg_results.py
"""
Aggregate TPG inference JSON results into CSV and plots.

Usage:
    python scripts/aggregate_tpg_results.py --root tpg_expe --out results_out

Behavior:
- Recursively finds JSON files under <root>/training_results/*/inference/results/*.json
- Option A TPG canonicalization: removes `_seed-<number>_` token (only when surrounded by underscores).
- Groups results by TPG config (seed-less) and by simulator (microarchitecture).
- Aggregates mean latencies across seeds (mean of means) and computes stddev of those means.
- Saves CSV summary and a combined matplotlib plot (one line per architecture across TPGs).
"""

from __future__ import annotations
import argparse
import json
import math
import os
import re
import sys
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from statistics import mean, pstdev
from typing import Dict, List, Optional, Tuple, Any

import matplotlib.pyplot as plt
import pandas as pd

# -----------------------------
# Data classes
# -----------------------------

@dataclass
class SeedResult:
    mean: float
    stddev: float
    source_file: Path
    seed_dir_name: str

@dataclass
class ArchGroup:
    simulator: str
    isa: str
    abi: str
    dtype: str
    seeds: List[SeedResult]

# -----------------------------
# Helpers
# -----------------------------

# -----------------------------
# Class-based aggregator
# -----------------------------
class TPGResultsAggregator:

    TPG_SEED_PATTERN = re.compile(r'_seed-\d+_')  # Option A: remove only when surrounded by underscores

    def __init__(self, root: str):
        self.root = Path(root).resolve()

    def canonicalize_tpg_dir(self, dir_name: str) -> str:
        """
        Apply Option A canonicalization:
        - Remove the substring matching `_seed-<digits>_` if present.
        - Collapse adjacent underscores and trim leading/trailing underscores.
        """
        # Replace only occurrences of _seed-<number>_
        new = self.TPG_SEED_PATTERN.sub('_', dir_name)
        # collapse multiple underscores, strip edges
        new = re.sub(r'_+', '_', new).strip('_')
        return new

    def make_key(self, p: Path) -> str:
        parts = list(p.parts)

        if "configs" in parts:
            idx = parts.index("configs")
        elif "results" in parts:
            idx = parts.index("results")
        else:
            raise ValueError(f"No configs/results directory in: {p}")

        prefix = Path(*parts[:idx])
        return str(prefix / p.stem)


    def find_missing_results(self, config_paths, result_paths):

        # Maps: key → path (same style for both)
        result_map = {self.make_key(Path(p)): p for p in result_paths}
        config_map = {self.make_key(Path(p)): p for p in config_paths}

        # Missing keys = config keys that are not in result keys
        missing_keys = config_map.keys() - result_map.keys()

        # Return the original config paths
        return list(map(lambda k: config_map[k], missing_keys))


    def find_json_files(self, folder_type) -> List[Path]:
        """
        Find JSON files under root/training_results/*/inference/results/*.json
        or 
        Find JSON files under root/training_results/*/inference/configs/*.json
        """
        if folder_type != "results" and folder_type != "configs":
            raise ValueError("folder_type must be either 'results' or 'configs'")
        
        files = []
        base = self.root / "training_results"
        if not base.exists():
            raise FileNotFoundError(f"Expected training_results under {self.root}, not found.")
        # Walk the tree under training_results
        for tpg_dir in base.iterdir():
            # Expect tpg_dir to be directories like ..._seed-0_instrType-float
            if not tpg_dir.is_dir():
                continue
            inf_files = tpg_dir / "inference" / folder_type
            if not inf_files.exists() or not inf_files.is_dir():
                continue
            for json_file in inf_files.glob("*.json"):
                files.append(json_file)
        return files

    def load_json_minimal(self, path: Path) -> Optional[Dict[str, Any]]:
        """
        Load JSON and validate required keys. Return minimal dict or None on failure.
        """
        required = {"simulator", "isa", "abi", "dtype", "tpg_mean_latency", "tpg_stddev_latency"}
        try:
            with path.open("r", encoding="utf-8") as f:
                data = json.load(f)
        except Exception as e:
            print(f"WARNING: Failed to load JSON {path}: {e}", file=sys.stderr)
            return None
        if not required.issubset(data.keys()):
            print(f"WARNING: JSON {path} missing required keys {required - set(data.keys())}", file=sys.stderr)
            return None
        # Try to coerce numeric fields
        try:
            mean_val = float(data["tpg_mean_latency"])
            std_val = float(data["tpg_stddev_latency"])
        except Exception as e:
            print(f"WARNING: Can't parse latency numbers in {path}: {e}", file=sys.stderr)
            return None
        # Normalized metadata values
        return {
            "simulator": str(data["simulator"]),
            "isa": str(data["isa"]),
            "abi": str(data["abi"]),
            "dtype": str(data["dtype"]),
            "tpg_mean_latency": mean_val,
            "tpg_stddev_latency": std_val,
        }

    # -----------------------------
    # Core pipeline
    # -----------------------------

    def build_hierarchical_data(self, json_files: List[Path]) -> Dict[str, Dict[str, ArchGroup]]:
        """
        Build data[tpg_config][arch_key] -> ArchGroup
        arch_key is simulator name (can be extended).
        seed_dir_name is the immediate parent directory name of the `inference` folder (i.e., the TPG+seed folder)
        """
        data: Dict[str, Dict[str, ArchGroup]] = defaultdict(dict)
        skipped = 0
        for jf in json_files:
            minimal = self.load_json_minimal(jf)
            if minimal is None:
                skipped += 1
                continue
            # Determine the tpg folder (parent of "inference")
            # expected path .../<tpg_dir>/inference/results/file.json
            # go up 3 levels to reach the TPG dir
            try:
                # Correct path climbing:
                # jf: .../tpg_dir/inference/results/file.json
                tpg_dir = jf.parents[2]  # this is the TPG dir
            except Exception:
                print(f"WARNING: Unexpected path structure for {jf}, skipping.", file=sys.stderr)
                skipped += 1
                continue
            tpg_dir_name = tpg_dir.name
            canonical_tpg = self.canonicalize_tpg_dir(tpg_dir_name)
            simulator = minimal["simulator"]
            arch_key = simulator  # using simulator as architecture identifier
            # Initialize group if needed
            if arch_key not in data[canonical_tpg]:
                data[canonical_tpg][arch_key] = ArchGroup(
                    simulator=simulator,
                    isa=minimal["isa"],
                    abi=minimal["abi"],
                    dtype=minimal["dtype"],
                    seeds=[]
                )
            # Append seed result
            seed_result = SeedResult(
                mean=minimal["tpg_mean_latency"],
                stddev=minimal["tpg_stddev_latency"],
                source_file=jf,
                seed_dir_name=tpg_dir_name
            )
            data[canonical_tpg][arch_key].seeds.append(seed_result)
        if skipped:
            print(f"INFO: skipped {skipped} files due to parse errors or unexpected structure", file=sys.stderr)
        return data

    def aggregate_data(self, data: Dict[str, Dict[str, ArchGroup]]) -> pd.DataFrame:
        """
        Aggregates by taking mean of seed means and stddev across those means (population std).
        Returns a DataFrame with rows per (tpg_config, arch_key).
        """
        rows = []
        for tpg, arch_map in sorted(data.items()):
            for arch_key, group in sorted(arch_map.items()):
                seed_means = [s.mean for s in group.seeds]
                if not seed_means:
                    continue
                avg = float(mean(seed_means))
                # population stddev for spread of means; if single seed -> 0.0
                stddev = float(pstdev(seed_means)) if len(seed_means) > 1 else 0.0
                rows.append({
                    "tpg_config": tpg,
                    "arch_key": arch_key,
                    "simulator": group.simulator,
                    "isa": group.isa,
                    "abi": group.abi,
                    "dtype": group.dtype,
                    "mean_latency_avg": avg,
                    "mean_latency_stddev": stddev,
                    "n_seeds": len(seed_means),
                })
        df = pd.DataFrame(rows)
        if df.empty:
            print("WARNING: aggregated DataFrame is empty", file=sys.stderr)
        return df

    # -----------------------------
    # Plotting
    # -----------------------------

    def plot_combined(df: pd.DataFrame, out_path: Path) -> None:
        """
        Combined line+errorbar plot:
        - X axis: sorted TPG configs
        - One line per architecture (arch_key)
        """
        if df.empty:
            print("INFO: No data to plot", file=sys.stderr)
            return
        # pivot table: index=tpg_config, columns=arch_key, values=mean_latency_avg
        tpgs = sorted(df["tpg_config"].unique())
        archs = sorted(df["arch_key"].unique())
        # Build mapping for each arch: list of means in tpgs order, fill NaN for missing
        plot_df = pd.DataFrame(index=tpgs, columns=archs, dtype=float)
        plot_err = pd.DataFrame(index=tpgs, columns=archs, dtype=float)
        for _, row in df.iterrows():
            plot_df.at[row["tpg_config"], row["arch_key"]] = row["mean_latency_avg"]
            plot_err.at[row["tpg_config"], row["arch_key"]] = row["mean_latency_stddev"]
        # Plot
        fig, ax = plt.subplots(figsize=(max(8, len(tpgs)*0.6), 6))
        x_pos = list(range(len(tpgs)))
        for arch in archs:
            y = plot_df[arch].tolist()
            yerr = plot_err[arch].tolist()
            # Convert None/NaN to numpy.nan so matplotlib handles gaps
            ax.errorbar(x_pos, y, yerr=yerr, marker='o', linestyle='-', label=arch, capsize=3)
        ax.set_xticks(x_pos)
        ax.set_xticklabels(tpgs, rotation=45, ha='right', fontsize=8)
        ax.set_xlabel("TPG configuration")
        ax.set_ylabel("Mean TPG latency (cycles)")
        ax.set_title("TPG mean latency by TPG config and microarchitecture")
        ax.legend(loc="upper left", bbox_to_anchor=(1.02, 1.0))
        fig.tight_layout()
        fig.savefig(out_path, dpi=200)
        plt.close(fig)

    def plot_per_tpg_bar(df: pd.DataFrame, out_dir: Path, max_plots: int = 20) -> None:
        """
        Create per-TPG bar plots comparing architectures for that TPG.
        Limit number of plots to avoid huge output.
        """
        tpgs = sorted(df["tpg_config"].unique())
        made = 0
        for tpg in tpgs:
            sub = df[df["tpg_config"] == tpg].sort_values(by="mean_latency_avg")
            if sub.empty:
                continue
            fig, ax = plt.subplots(figsize=(8, max(4, len(sub)*0.4)))
            ax.bar(range(len(sub)), sub["mean_latency_avg"], yerr=sub["mean_latency_stddev"], capsize=4)
            ax.set_xticks(range(len(sub)))
            ax.set_xticklabels(sub["arch_key"].tolist(), rotation=45, ha='right', fontsize=8)
            ax.set_ylabel("Mean TPG latency (cycles)")
            ax.set_title(f"TPG: {tpg} (n_arch={len(sub)})")
            fig.tight_layout()
            out_file = out_dir / f"per_tpg_{sanitize_filename(tpg)}.png"
            fig.savefig(out_file, dpi=200)
            plt.close(fig)
            made += 1
            if made >= max_plots:
                break

    def sanitize_filename(s: str) -> str:
        """Make a safe filename from a string."""
        return re.sub(r'[^A-Za-z0-9._-]+', '_', s)[:200]

# -----------------------------
# CLI / main
# -----------------------------

def main(argv: Optional[List[str]]=None):
    parser = argparse.ArgumentParser(description="Aggregate TPG inference JSON results.")
    parser.add_argument("--root", type=str, default=".", help="Root path containing training_results (default: .)")
    parser.add_argument("--out", type=str, default="results_out", help="Output directory for CSV and plots.")
    parser.add_argument("--save-per-tpg", action="store_true", help="Save per-TPG bar plots (may produce many files).")
    parser.add_argument("--max-per-tpg", type=int, default=20, help="Max per-TPG plots to generate.")
    args = parser.parse_args(argv)

    agg = TPGResultsAggregator(args.root)

    root = Path(args.root).resolve()
    out_dir = Path(args.out).resolve()
    out_dir.mkdir(parents=True, exist_ok=True)

    print(f"INFO: Searching JSON CONFIG files under {root}/training_results/.../inference/configs/...")
    json_config_files = agg.find_json_files("configs")
    print(f"INFO: found {len(json_config_files)} JSON CONFIG files")

    print(f"INFO: Searching JSON RESULT files under {root}/training_results/.../inference/results/...")
    json_result_files = agg.find_json_files("results")
    print(f"INFO: found {len(json_result_files)} JSON RESULT files")
    
    missing = agg.find_missing_results(json_config_files, json_result_files)
    print(f"missing {len(missing)} result files for config files")

    
    data = agg.build_hierarchical_data(json_result_files)
    df = agg.aggregate_data(data)
    # Save CSV
    csv_path = out_dir / "aggregated_tpg_results.csv"
    df.to_csv(csv_path, index=False)
    print(f"INFO: saved aggregated CSV to {csv_path}")

#     # Combined plot
#     combined_png = out_dir / "combined_latency_by_tpg.png"
#     plot_combined(df, combined_png)
#     print(f"INFO: saved combined plot to {combined_png}")

#     if args.save_per_tpg:
#         plot_per_tpg_bar(df, out_dir, max_plots=args.max_per_tpg)
#         print(f"INFO: saved up to {args.max_per_tpg} per-TPG plots in {out_dir}")

#     # quick summary printed
#     n_tpgs = df["tpg_config"].nunique() if not df.empty else 0
#     n_archs = df["arch_key"].nunique() if not df.empty else 0
#     print(f"SUMMARY: TPGs={n_tpgs}, architectures={n_archs}, total_rows={len(df)}")

# scripts/aggregate_tpg_results.py --root tpg_expe --out results_out

if __name__ == "__main__":
    main()
