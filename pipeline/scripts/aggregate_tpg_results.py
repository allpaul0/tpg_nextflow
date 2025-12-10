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
    seed: int
    tpg_dir_name: str

@dataclass
class ArchGroup:
    simulator: str
    isa: str
    abi: str
    dtype: str
    seeds: List[SeedResult]
    tpg_nickname: str

# -----------------------------
# Helpers
# -----------------------------

# -----------------------------
# Class-based aggregator
# -----------------------------
class TPGResultsAggregator:

    # compile this regular expression into a regex object. Avoids re-compiling on each call.
    TPG_SEED_PATTERN = re.compile(r'_seed-(\d+)_')  

    def __init__(self, root: str):
        self.root = Path(root).resolve()

    def reverse_replace_xpulp_extensions(self, isa: str) -> str:
        """
        Replace
        '_xcvalu_xcvbi_xcvbitmanip_xcvhwlp_xcvmac_xcvmem_xcvsimd' with '_xpulp' 
        """
        XPULP_EXT = "_xcvalu_xcvbi_xcvbitmanip_xcvhwlp_xcvmac_xcvmem_xcvsimd"

        if XPULP_EXT in isa:
            return isa.replace(XPULP_EXT, "_xpulp",)

        return isa

    def canonicalize_tpg_dir(self, tpg_dir_name: str) -> str:
        """
        - Remove the substring matching `_seed-<digits>_` from tpg_dir_name.
        - Collapse adjacent underscores and trim leading/trailing underscores.
        """
        # find the seed
        seed_match = self.TPG_SEED_PATTERN.search(tpg_dir_name).group(1)
        seed = int(seed_match) if seed_match else None

        # Replace only occurrences of _seed-<number>_
        new = self.TPG_SEED_PATTERN.sub('_', tpg_dir_name)
        # collapse multiple underscores, strip edges
        new = re.sub(r'_+', '_', new).strip('_')
        return new, seed 

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

        isa = self.reverse_replace_xpulp_extensions(str(data["isa"]))

        # Normalized metadata values
        return {
            "simulator": str(data["simulator"]),
            "isa": isa,
            "abi": str(data["abi"]),
            "dtype": str(data["dtype"]),
            "tpg_mean_latency": mean_val,
            "tpg_stddev_latency": std_val,
        }
    
    def assign_nickname(self, canonical_tpg: str) -> str:
        """
        Produce a compact nickname from a canonical TPG directory string.
        Patterns handled:
        A) Trig / LogExp / ExpensiveArithmetic / Comparison
        B) Log2Exp2 + Zmmul variant (Trig=False, LogExp=False)
        """

        def extract_flag(name: str) -> Optional[int]:
            m = re.search(rf"{name}-(True|False)", canonical_tpg)
            if not m:
                return None
            return 1 if m.group(1) == "True" else 0

        # Dtype
        dtype_m = re.search(r"instrType-(double|float|fixedpt)", canonical_tpg)
        dtype = dtype_m.group(1) if dtype_m else "unk"

        # Detect variant B (Log2Exp2/Zmmul)
        log2_m = re.search(r"useInstrLog2Exp2-(True|False)", canonical_tpg)
        zmmul_m = re.search(r"useInstrZmmul-(True|False)", canonical_tpg)

        if log2_m or zmmul_m:
            # B-pattern nickname
            #l2e2 = 1 if (log2_m and log2_m.group(1) == "True") else 0
            #zmu = 1 if (zmmul_m and zmmul_m.group(1) == "True") else 0
            l2e2 = extract_flag("useInstrLog2Exp2") or 0
            zmu = extract_flag("useInstrZmmul") or 0
            expari = extract_flag("useInstrExpensiveArithmetic") or 0
            #cmpf = extract_flag("useInstrComparison") or 0

            #return f"l2e2{l2e2}_zmu{zmu}_expari{expari}_cmp{cmpf}_{dtype}"
            return f"l2e2{l2e2}_zmu{zmu}_expari{expari}-{dtype}"

        # Default A-pattern nickname
        trig = extract_flag("useInstrTrig") or 0
        logexp = extract_flag("useInstrLogExp") or 0
        expari = extract_flag("useInstrExpensiveArithmetic") or 0
        #cmpf = extract_flag("useInstrComparison") or 0

        #return f"trig{trig}_logexp{logexp}_expari{expari}_cmp{cmpf}_{dtype}"
        return f"trig{trig}_logexp{logexp}_expari{expari}-{dtype}"

    # -----------------------------
    # Core pipeline
    # -----------------------------

    def build_hierarchical_data(self, json_files: List[Path]) -> Dict[str, Dict[Tuple[str, str], ArchGroup]]:
        """
        Build data[tpg_config][(uarch,isa)] -> ArchGroup
        uarch is simulator name
        """
        data: Dict[str, Dict[Tuple[str, str], ArchGroup]] = defaultdict(dict)
        skipped = 0
        for jf in json_files:
            minimal = self.load_json_minimal(jf)
            if minimal is None:
                skipped += 1
                continue
            try:
                # Determine the tpg folder associated to the json tpg_expe/training_results/<tpg_dir>/inference/results/file.json
                tpg_dir = jf.parents[2]
            except Exception:
                print(f"WARNING: Unexpected path structure for {jf}, skipping.", file=sys.stderr)
                skipped += 1
                continue

            tpg_dir_name = tpg_dir.name
            canonical_tpg, seed = self.canonicalize_tpg_dir(tpg_dir_name)

            simulator = minimal["simulator"]
            isa=minimal["isa"]
            abi=minimal["abi"]
            dtype=minimal["dtype"]
            nickname = self.assign_nickname(canonical_tpg)

            # tuple key 
            uarch = simulator  
            key = (uarch, isa)

            # Initialize group if needed
            if key not in data[canonical_tpg]:
                data[canonical_tpg][key] = ArchGroup(
                    simulator=simulator,
                    isa=isa,
                    abi=abi,
                    dtype=dtype,
                    seeds=[],
                    tpg_nickname=nickname
                )

            # Append seed result
            seed_result = SeedResult(
                mean=minimal["tpg_mean_latency"],
                stddev=minimal["tpg_stddev_latency"],
                source_file=jf,
                seed = seed,
                tpg_dir_name = tpg_dir_name
            )
            data[canonical_tpg][key].seeds.append(seed_result)

        if skipped:
            print(f"INFO: skipped {skipped} files due to parse errors or unexpected structure", file=sys.stderr)
        return data

    def aggregate_data(self, data: Dict[str, Dict[Tuple[str, str], ArchGroup]]) -> pd.DataFrame:
        """
        Aggregates data 
        Returns a DataFrame with rows per (tpg_config, uarch, seed).
        """
        rows = []
        for tpg, arch_map in sorted(data.items()):
            for key, group in sorted(arch_map.items()):
                for seed in group.seeds:
                    rows.append({
                        #"tpg_config": tpg,
                        "tpg_nickname": group.tpg_nickname,
                        "uarch": key[0],
                        "isa": group.isa,
                        "abi": group.abi,
                        "dtype": group.dtype,
                        "seed": seed.seed,
                        "tpg_mean_latency": seed.mean,
                        "tpg_stddev_latency": seed.stddev
                    })
        df = pd.DataFrame(rows)
        if df.empty:
            print("WARNING: aggregated DataFrame is empty", file=sys.stderr)
        return df

    def aggregate_averaged_data(self, data):
        """
        Build a dataframe with one row per (tpg_config, uarch).
        mean_latency_avg  = mean of seed.means
        mean_latency_stddev = mean of seed.stddevs
        """
        rows = []
        for tpg, arch_map in data.items():
            for (uarch, isa), group in arch_map.items():
                seed_means = [s.mean for s in group.seeds]
                seed_stddevs = [s.stddev for s in group.seeds]

                if not seed_means:
                    continue

                mean_latency_avg = round(float(mean(seed_means)), 2)
                mean_latency_stddev = round(float(mean(seed_stddevs)), 2) if seed_stddevs else 0.0

                rows.append({
                    #"tpg_config": tpg,
                    "tpg_nickname": group.tpg_nickname,
                    "uarch": uarch,
                    "isa": group.isa,
                    "abi": group.abi,
                    "dtype": group.dtype,
                    "mean_latency_avg": mean_latency_avg,
                    "mean_latency_stddev": mean_latency_stddev,
                })
        return pd.DataFrame(rows)


    # -----------------------------
    # Plotting
    # -----------------------------

    # === PLOT A: best architectures per TPG ===
    def plot_best_per_tpg(self, df, out_dir):
        """
        One plot per TPG, showing best architectures (uarch+isa) sorted by latency.
        """
        tpgs = sorted(df["tpg_nickname"].unique())
        for tpg in tpgs:
            sub = df[df["tpg_nickname"] == tpg].copy()
            if sub.empty:
                continue

            sub["label"] = sub["uarch"] + " | " + sub["isa"]
            sub = sub.sort_values("mean_latency_avg")

            fig, ax = plt.subplots(figsize=(9, max(4, len(sub)*0.4)))
            x_pos = range(len(sub))
            y = sub["mean_latency_avg"].tolist()
            yerr = sub["mean_latency_stddev"].tolist()
            ax.errorbar(x_pos, y, yerr=yerr, fmt='o', capsize=4, markersize=6, linestyle='None', color='C0')
            ax.set_xticks(x_pos)
            ax.set_xticklabels(sub["label"], rotation=45, ha="right", fontsize=8)
            ax.set_ylabel("Mean latency (cycles)")
            ax.set_title(f"Best architectures for TPG: {tpg}")
            fig.tight_layout()

            filename = f"best_arch_for_tpg_{self.sanitize_filename(tpg)}.png"
            fig.savefig(out_dir / filename, dpi=200)
            plt.close(fig)

    # === PLOT B: best TPG/ISA per Architecture ===
    def plot_best_per_arch(self, df, out_dir):
        """
        One plot per architecture, showing best (TPG, ISA).
        """
        archs = sorted(df["uarch"].unique())
        for arch in archs:
            sub = df[df["uarch"] == arch].copy()
            if sub.empty:
                continue

            sub["label"] = sub["tpg_nickname"] + " | " + sub["isa"]
            sub = sub.sort_values("mean_latency_avg")

            fig, ax = plt.subplots(figsize=(9, max(4, len(sub)*0.4)))
            x_pos = range(len(sub))
            y = sub["mean_latency_avg"].tolist()
            yerr = sub["mean_latency_stddev"].tolist()
            ax.errorbar(x_pos, y, yerr=yerr, fmt='o', capsize=4, markersize=6, linestyle='None', color='C1')
            ax.set_xticks(x_pos)
            ax.set_xticklabels(sub["label"], rotation=45, ha="right", fontsize=8)
            ax.set_ylabel("Mean latency (cycles)")
            ax.set_title(f"Best TPG/ISA combinations for architecture: {arch}")
            fig.tight_layout()

            filename = f"best_tpg_for_arch_{self.sanitize_filename(arch)}.png"
            fig.savefig(out_dir / filename, dpi=200)
            plt.close(fig)

    def sanitize_filename(self, s: str) -> str:
        """Make a safe filename from a string."""
        return re.sub(r'[^A-Za-z0-9._-]+', '_', s)[:200]

"""
# stddev of latency means across seeds
#"mean_latency_stddev": stddev,
#stddev = float(pstdev(seed_means)) if len(seed_means) > 1 else 0.0

#mean of stddevs across seeds
stddevs = [s.stddev for s in group.seeds]
stddev = float(mean(stddevs)) if stddevs else 0.0
"""

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

    out_dir = Path(args.out).resolve()
    out_dir.mkdir(parents=True, exist_ok=True)

    json_config_files = agg.find_json_files("configs")
    print(f"{len(json_config_files)} Json config files")

    json_result_files = agg.find_json_files("results")
    print(f"{len(json_result_files)} Json result files")
        
    data = agg.build_hierarchical_data(json_result_files)
    df = agg.aggregate_data(data)
    df2 = agg.aggregate_averaged_data(data)

    # Save CSV
    csv_path = out_dir / "aggregated_tpg_results.csv"
    df.to_csv(csv_path, index=False)
    print(f"Saved aggregated CSV to {csv_path}")

    csv_path2 = out_dir / "aggregated_averaged_tpg_results.csv"
    df2.to_csv(csv_path2, index=False)
    print(f"Saved aggregated CSV to {csv_path2}")

    agg.plot_best_per_tpg(df2, out_dir)
    agg.plot_best_per_arch(df2, out_dir)

    # Combined plot
    # combined_png = out_dir / "combined_latency_by_tpg.png"
    # agg.plot_combined(df, combined_png)
    # print(f"INFO: saved combined plot to {combined_png}")

    # if args.save_per_tpg:
    #     agg.plot_per_tpg_bar(df, out_dir, max_plots=args.max_per_tpg)
    #     print(f"INFO: saved up to {args.max_per_tpg} per-TPG plots in {out_dir}")

#     # quick summary printed
#     n_tpgs = df["tpg_config"].nunique() if not df.empty else 0
#     n_archs = df["uarch"].nunique() if not df.empty else 0
#     print(f"SUMMARY: TPGs={n_tpgs}, architectures={n_archs}, total_rows={len(df)}")

# scripts/aggregate_tpg_results.py --root tpg_expe --out results_out

if __name__ == "__main__":
    main()
