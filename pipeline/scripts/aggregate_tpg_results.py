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

    def __init__(self, root: str, out: str):
        self.root = Path(root).resolve()
        self.out = Path(out).resolve()
        self.out.mkdir(parents=True, exist_ok=True)

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

        print(f"{len(files)} " + folder_type + " files")
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
    
    def assign_tpg_nickname(self, canonical_tpg: str) -> str:
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
            l2e2 = 1 if (log2_m and log2_m.group(1) == "True") else 0
            zmu = 1 if (zmmul_m and zmmul_m.group(1) == "True") else 0
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

    def assign_isa_nickname(self, isa: str) -> str:

        isa = self.reverse_replace_xpulp_extensions(isa)
        isa = isa.replace("_zicsr", "")
        isa = isa.replace("_zmmul", "_z")
        return isa

    def assign_simulator_nickname(self, simulator: str) -> str:
        """
        Produce a compact nickname from a simulator string.
        Patterns handled:
        cv32e20 -> S2 
        cv32e40 -> S4
        ! Attention à l'ordre des règles !
        """
        
        simulator = simulator.replace("cv32e20", "S2") # simplifie
        simulator = simulator.replace("cv32e40", "S4") # simplifie
        simulator = simulator.replace("corev_pulp", "pulp") # simplifie
               
        # S4x_i-em0,1,2 -> renommage
        simulator = simulator.replace("S4x_im0", "S4x_im0d2") # ajoute div
        simulator = simulator.replace("S4x_im1", "S4x_im4d2") # change mult -> basé ressources, ajoute div
        simulator = simulator.replace("S4x_im2", "S4x_im4d0") # change mult -> basé ressources, ajoute div

        simulator = simulator.replace("S4x_em0", "S4x_em0d2") # ajoute div
        simulator = simulator.replace("S4x_em1", "S4x_em4d2") # change mult -> basé ressources, ajoute div
        simulator = simulator.replace("S4x_em2", "S4x_em4d0") # change mult -> basé ressources, ajoute div

        simulator = simulator.replace("S4px", "S4x_im4d2") # ajout mult -> basé ressources

        # S2_i-em0-3 -> add div
        simulator = simulator.replace("S2_im0", "S2_im0d1")
        simulator = simulator.replace("S2_im1", "S2_im1d1")
        simulator = simulator.replace("S2_im2", "S2_im2d1")
        simulator = simulator.replace("S2_im3", "S2_im3d1")

        simulator = simulator.replace("S2_em0", "S2_em0d1")
        simulator = simulator.replace("S2_em1", "S2_em1d1")
        simulator = simulator.replace("S2_em2", "S2_em2d1")
        simulator = simulator.replace("S2_em3", "S2_em3d1")

        simulator = simulator.replace("px", "") # rassemble px, x
        simulator = simulator.replace("x", "") # rassemble px, x

        return simulator

    # -----------------------------
    # Core pipeline
    # -----------------------------

    def build_hierarchical_data(self, json_files: List[Path]) -> Dict[str, Dict[str, Dict[str, ArchGroup]]]:
        
        """
        Build data[tpg_config][uarch][isa] -> ArchGroup
        each tpg is evaluated on multiple uarchs -> dic
        each of those uarchs is evaluated on multiple isa -> dic 
        """
        data: Dict[str, Dict[str, Dict[str, ArchGroup]]] = defaultdict(lambda: defaultdict(dict))

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

            tpg_nickname = self.assign_tpg_nickname(canonical_tpg)
            simulator_nickname = self.assign_simulator_nickname(simulator)
            isa_nickname = self.assign_isa_nickname(isa)
 
            # Initialize group if needed
            if isa_nickname not in data[tpg_nickname][simulator_nickname]:
                data[tpg_nickname][simulator_nickname][isa_nickname] = ArchGroup(
                    simulator=simulator_nickname,
                    isa=isa_nickname,
                    abi=abi,
                    dtype=dtype,
                    seeds=[],
                    tpg_nickname=tpg_nickname
                )

            # Append seed result
            seed_result = SeedResult(
                mean=minimal["tpg_mean_latency"],
                stddev=minimal["tpg_stddev_latency"],
                source_file=jf,
                seed = seed,
                tpg_dir_name = tpg_dir_name
            )
            data[tpg_nickname][simulator_nickname][isa_nickname].seeds.append(seed_result)

        if skipped:
            print(f"INFO: skipped {skipped} files due to parse errors or unexpected structure", file=sys.stderr)
        return data

    def aggregate_data(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]) -> pd.DataFrame:
        """
        Aggregates data 
        Returns a DataFrame with rows per (tpg_config, uarch, seed).
        """
        rows = []
        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, group in sorted(isa_map.items()):
                    for seed in group.seeds:
                        rows.append({
                            #"tpg_config": tpg,
                            "tpg_nickname": group.tpg_nickname,
                            "uarch": uarch,
                            "isa": isa,
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

    def aggregate_averaged_data(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]) -> pd.DataFrame:
        """
        Build a dataframe with one row per (tpg_config, uarch).
        mean_latency_avg  = mean of seed.means
        mean_latency_stddev = mean of seed.stddevs
        """
        rows = []
        for tpg, uarch_map in data.items():
            for uarch, isa_map in uarch_map.items():
                for isa, group in isa_map.items():
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]

                    if not seed_means:
                        continue

                    mean_latency_avg = round(float(mean(seed_means)), 2)
                    mean_latency_stddev = round(float(mean(seed_stddevs)), 2) if seed_stddevs else 0.0

                    # stddev of latency means across seeds
                    # "mean_latency_stddev": stddev,
                    # stddev = float(pstdev(seed_means)) if len(seed_means) > 1 else 0.0

                    # mean of stddevs across seeds
                    # stddevs = [s.stddev for s in group.seeds]
                    # stddev = float(mean(stddevs)) if stddevs else 0.0

                    rows.append({
                        #"tpg_config": tpg,
                        "tpg_nickname": group.tpg_nickname,
                        "uarch": uarch,
                        "isa": isa,
                        "abi": group.abi,
                        "dtype": group.dtype,
                        "mean_latency_avg": mean_latency_avg,
                        "mean_latency_stddev": mean_latency_stddev,
                    })
        return pd.DataFrame(rows)


    # -----------------------------
    # Plotting
    # -----------------------------

    def is_c_extension(self, isa1: str, isa2: str) -> Tuple[str, str]:
        """
        Given two ISAs, return (no_c_isa, with_c_isa)
        """
        if "c_" in isa1 and "c_" not in isa2:
            return isa2, isa1
        elif "c_" in isa2 and "c_" not in isa1:
            return isa1, isa2
        #check if one ends with 'c'
        if isa1.endswith("c") and not isa2.endswith("c"):
            return isa2, isa1
        elif isa2.endswith("c") and not isa1.endswith("c"):
            return isa1, isa2
        else:
            # fallback if the difference is not the 'c' extension
            # no_c_isa, c_isa 
            return isa1, isa2

    # === PLOT A: best architectures per TPG ===
    def plot_best_per_tpg(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]):
        """
        Generate one figure per TPG.
        X-axis: uarch
        Y-axis: log-scale latency
        Points: mean latency, error bars = stddev
        Two ISAs per uarch: color red for without 'c' extension, blue for with 'c'
        """

        for tpg, uarch_map in data.items():

            # fetch nickname from any group under this TPG
            try:
                # get first element from uarch_map dict -> isa_map
                # get first element from isa_map dict -> Archgroup
                sample_group = next(iter(next(iter(uarch_map.values())).values()))
                tpg_nickname = sample_group.tpg_nickname
            except Exception:
                tpg_nickname = tpg

            fig, ax = plt.subplots(figsize=(14, 6), constrained_layout=True)
            ax.set_title(f"Latency per uarch for TPG: {tpg_nickname}")
            ax.set_xlabel("uarch")
            ax.set_ylabel("Latency CC")
            ax.set_yscale("log")

            uarchs_sorted = sorted(uarch_map.keys())
            x_ticks = range(len(uarchs_sorted))
            ax.set_xticks(x_ticks)
            ax.set_xticklabels(uarchs_sorted, rotation=45, ha="right")

            for xi, uarch in enumerate(uarchs_sorted):
                isa_map = uarch_map[uarch]
                if len(isa_map) != 2:
                    print(f"WARNING: uarch {uarch} does not have exactly 2 ISAs, skipping.")
                    continue

                isa_list = list(isa_map.keys())
                no_c_isa, with_c_isa = self.is_c_extension(isa_list[0], isa_list[1])

                # Plot each ISA
                for isa, color in zip([no_c_isa, with_c_isa], ["red", "blue"]):
                    group = isa_map[isa]
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]
                    if not seed_means:
                        continue
                    mean_latency = mean(seed_means)
                    stddev_latency = mean(seed_stddevs) if seed_stddevs else 0.0

                    ax.errorbar(
                        xi, mean_latency,
                        yerr=stddev_latency,
                        fmt="o",
                        color=color,
                        capsize=5,
                        label=f"{isa}"  # label for legend
                    )

            # Only show each ISA in legend once
            handles, labels = ax.get_legend_handles_labels()
            by_label = dict(zip(labels, handles))
            ax.legend(
                by_label.values(),
                by_label.keys(),
                title="ISA",
                loc="center left",
                bbox_to_anchor=(1.02, 0.5),
            )
            fig.tight_layout()
            safe_name = self.sanitize_filename(f"{tpg_nickname}_latency_per_uarch.png")
            fig_path = self.out / safe_name
            fig.savefig(fig_path)
            plt.close(fig)
            print(f"Saved plot for TPG {tpg_nickname} to {fig_path}")
    
    def plot_best_per_uarch(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]):
        """
        Generate one figure per uarch.
        X-axis: TPG (nickname)
        Y-axis: log-scale latency
        Two ISAs per TPG: red = no 'c', blue = with 'c'
        """

        # --- Gather all possible uarchs across all TPGs
        all_uarchs = set()
        for tpg, uarch_map in data.items():
            all_uarchs.update(uarch_map.keys())

        # --- Build one plot per uarch
        for uarch in sorted(all_uarchs):

            # Build TPG list that contains this uarch
            tpgs_with_uarch = []
            tpg_nicknames = []

            for tpg, uarch_map in data.items():
                if uarch not in uarch_map:
                    continue

                # Extract nickname
                try:
                    sample_group = next(iter(next(iter(uarch_map.values())).values()))
                    nickname = sample_group.tpg_nickname
                except Exception:
                    nickname = tpg

                tpgs_with_uarch.append(tpg)
                tpg_nicknames.append(nickname)

            if not tpgs_with_uarch:
                continue

            fig, ax = plt.subplots(figsize=(12, 6), constrained_layout=True)
            ax.set_title(f"Latency per TPG for uarch: {uarch}")
            ax.set_xlabel("TPG")
            ax.set_ylabel("Latency CC")
            ax.set_yscale("log")

            # X-axis = TPG nicknames
            x_ticks = range(len(tpgs_with_uarch))
            ax.set_xticks(x_ticks)

            ax.set_xticklabels(tpg_nicknames, rotation=45, ha="right")

            # --- Plot each TPG
            for xi, tpg in enumerate(tpgs_with_uarch):
                isa_map = data[tpg][uarch]
                if len(isa_map) != 2:
                    print(f"WARNING: In uarch {uarch}, TPG {tpg} does not have exactly 2 ISAs, skipping.")
                    continue

                isa_list = list(isa_map.keys())
                no_c_isa, with_c_isa = self.is_c_extension(isa_list[0], isa_list[1])

                for isa, color in zip([no_c_isa, with_c_isa], ["red", "blue"]):
                    group = isa_map[isa]
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]

                    if not seed_means:
                        continue

                    mean_latency = mean(seed_means)
                    stddev_latency = mean(seed_stddevs) if seed_stddevs else 0.0

                    ax.errorbar(
                        xi, mean_latency,
                        yerr=stddev_latency,
                        fmt="o",
                        color=color,
                        capsize=5,
                        label=isa
                    )

            # Unique legend (outside plot)
            handles, labels = ax.get_legend_handles_labels()
            by_label = dict(zip(labels, handles))

            ax.legend(
                by_label.values(),
                by_label.keys(),
                title="ISA",
                loc="center left",
                bbox_to_anchor=(1.02, 0.5),
            )

            fig.tight_layout()

            safe_name = self.sanitize_filename(f"{uarch}_latency_per_tpg.png")
            fig_path = self.out / safe_name
            fig.savefig(fig_path, bbox_inches="tight")
            plt.close(fig)

            print(f"Saved plot for uarch {uarch} to {fig_path}")

    
    def sanitize_filename(self, s: str) -> str:
        """Make a safe filename from a string."""
        return re.sub(r'[^A-Za-z0-9._-]+', '_', s)[:200]

    def save_csv(self, df: pd.DataFrame, file_name: str):
        csv_path = self.out / file_name
        df.to_csv(csv_path, index=False)
        print(f"Saved aggregated CSV to {csv_path}")


# -----------------------------
# CLI / main
# -----------------------------

def main(argv: Optional[List[str]]=None):
    parser = argparse.ArgumentParser(description="Aggregate TPG inference JSON results.")
    parser.add_argument("--root", type=str, default=".", help="Root path containing training_results (default: .)")
    parser.add_argument("--out", type=str, default="results_out", help="Output directory for CSV and plots.")
    args = parser.parse_args(argv)

    agg = TPGResultsAggregator(args.root, args.out)

    json_config_files = agg.find_json_files("configs")
    json_result_files = agg.find_json_files("results")
        
    data = agg.build_hierarchical_data(json_result_files)

    df = agg.aggregate_data(data)
    df_avg = agg.aggregate_averaged_data(data)

    agg.save_csv(df, "aggregated_tpg_results.csv")
    agg.save_csv(df_avg, "aggregated_averaged_tpg_results.csv")

    agg.plot_best_per_tpg(data)
    agg.plot_best_per_uarch(data)

    # Combined plot
    # combined_png = out_dir / "combined_latency_by_tpg.png"
    # agg.plot_combined(df, combined_png)
    # print(f"INFO: saved combined plot to {combined_png}")

    # agg.plot_per_tpg_bar(df, out_dir, max_plots=args.max_per_tpg)
    # print(f"INFO: saved up to {args.max_per_tpg} per-TPG plots in {out_dir}")

    # quick summary printed
    n_tpgs = df["tpg_nickname"].nunique() if not df.empty else 0
    n_archs = df["uarch"].nunique() if not df.empty else 0
    #for isa in df["isa"].unique():
    #    print(isa)
    print(f"SUMMARY: TPGs={n_tpgs}, architectures={n_archs}, total_rows={len(df)}")

# scripts/aggregate_tpg_results.py --root tpg_expe --out results_out

if __name__ == "__main__":
    main()
