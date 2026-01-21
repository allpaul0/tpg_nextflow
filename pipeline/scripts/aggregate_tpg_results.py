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
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from statistics import mean, pstdev
from typing import Dict, List, Optional, Tuple, Any

# -----------------------------
# Data classes
# -----------------------------

@dataclass
class Uarch_Ressources:
    dsps: int
    regs: int
    luts: int

@dataclass
class SeedResult:
    mean: float
    stddev: float
    seed: int
    source_file: Optional[Path] = None
    tpg_dir_name: Optional[str] = None
    avg_nb_instr: Optional[float] = None
    avg_nb_evaluated_programs: Optional[float] = None
    avg_nb_evaluated_teams: Optional[float] = None

@dataclass
class ArchGroup:
    tpg_canonical: str
    simulator: str
    isa: str
    abi: str
    iset: str
    dtype: str
    seeds: List[SeedResult]
    accuracy: Optional[float] = None
    uarch_ressources: Optional[Uarch_Ressources] = None 
    norm_ressource: Optional[float] = None
    

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

    # START LOADING SECTION

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

    def find_nbInstr_json_files(self) -> List[Path]:
        """
        Find JSON files under root/training_results/*/outLogs/precalcul/executionInfos.json        
        """
      
        files = []
        base = self.root / "training_results"
        if not base.exists():
            raise FileNotFoundError(f"Expected training_results under {self.root}, not found.")
        # Walk the tree under training_results
        for tpg_dir in base.iterdir():
            # Expect tpg_dir to be directories like ..._seed-0_instrType-float
            if not tpg_dir.is_dir():
                continue
            precalcul_files = tpg_dir / "outLogs" / "precalcul"
            if not precalcul_files.exists() or not precalcul_files.is_dir():
                continue
            for json_file in precalcul_files.glob("executionInfos.json"):
                files.append(json_file)

        print(f"{len(files)}" + " files")
        return files

    # END LOADING SECTION
    
    def assign_iset_function_nickname(self, tpg_canonical: str) -> str:
        """
        Produce a compact iset from a canonical TPG directory string.
        Patterns handled:
        A) Trig / LogExp / ExpensiveArithmetic / Comparison
        B) Log2Exp2 + Zmmul variant (Trig=False, LogExp=False)
        """

        def extract_flag(name: str) -> Optional[int]:
            m = re.search(rf"{name}-(True|False)", tpg_canonical)
            if not m:
                return None
            return 1 if m.group(1) == "True" else 0

        # Dtype
        dtype_m = re.search(r"instrType-(double|float|fixedpt)", tpg_canonical)
        dtype = dtype_m.group(1) if dtype_m else "unk"

        # Detect variant B (Log2Exp2/Zmmul)
        log2_m = re.search(r"useInstrLog2Exp2-(True|False)", tpg_canonical)
        zmmul_m = re.search(r"useInstrZmmul-(True|False)", tpg_canonical)

        if log2_m or zmmul_m:
            # B-pattern iset
            l2e2 = 1 if (log2_m and log2_m.group(1) == "True") else 0
            zmu = 1 if (zmmul_m and zmmul_m.group(1) == "True") else 0
            expari = extract_flag("useInstrExpensiveArithmetic") or 0
            #cmpf = extract_flag("useInstrComparison") or 0

            #return f"l2e2{l2e2}_zmu{zmu}_expari{expari}_cmp{cmpf}_{dtype}"
            return f"l2e2{l2e2}_zmu{zmu}_expari{expari}"

        # Default A-pattern iset
        trig = extract_flag("useInstrTrig") or 0
        logexp = extract_flag("useInstrLogExp") or 0
        expari = extract_flag("useInstrExpensiveArithmetic") or 0
        #cmpf = extract_flag("useInstrComparison") or 0

        #return f"trig{trig}_logexp{logexp}_expari{expari}_cmp{cmpf}_{dtype}"
        return f"trig{trig}_logexp{logexp}_expari{expari}"

    def assign_iset_operator_nickname(self, tpg_canonical: str) -> str:
        """ 
        Produce a compact iset from a canonical TPG directory string. 
        Patterns handled: A) Trig / LogExp / ExpensiveArithmetic / Comparison 
        B) Log2Exp2 + Zmmul variant (Trig=False, LogExp=False) 
        """
        def extract_flag(name: str) -> Optional[int]:
            m = re.search(rf"{name}-(True|False)", tpg_canonical)
            return 1 if (m and m.group(1) == "True") else 0

        # detect B-pattern
        log2_m = extract_flag("useInstrLog2Exp2")
        zmmul_m = extract_flag("useInstrZmmul")

        is_B = (log2_m == 1 or zmmul_m == 1)

        if is_B:
            ops = []
            if log2_m == 1:
                ops.append("log2,exp2")
            if extract_flag("useInstrExpensiveArithmetic"):
                ops.append("*,/")
            if zmmul_m == 1:
                ops.append("*")
            ops.append(">,-,+")
            return "{" + ",".join(ops) + "}"

        # A-pattern
        trig = extract_flag("useInstrTrig")
        logexp = extract_flag("useInstrLogExp")
        expari = extract_flag("useInstrExpensiveArithmetic")

        ops = []
        if trig:
            #ops.append("sin,cos,tan")
            ops.append("trig")
        if logexp:
            ops.append("log,exp") #log,exp
        if expari:
            ops.append("*,/")
        ops.append(">,-,+")
        return "{" + ",".join(ops) + "}"


    def assign_isa_nickname(self, isa: str) -> str:

        isa = self.reverse_replace_xpulp_extensions(isa)
        isa = isa.replace("_zicsr", "")
        #isa = isa.replace("_zmmul", "_z")
        return isa

    def assign_simulator_nickname(self, simulator: str) -> str:
        """
        Produce a compact nickname from a simulator string.
        Patterns handled:
        cv32e20 -> e2 
        cv32e40 -> e4
        ! Attention à l'ordre des règles !
        """
        
        simulator = simulator.replace("cv32e20", "e2") # simplifie
        simulator = simulator.replace("cv32e40", "e4") # simplifie
        simulator = simulator.replace("corev_pulp", "pulp") # simplifie
               
        # e4x_i-em0,1,2 -> renommage
        simulator = simulator.replace("e4x_im0", "e4x_im0d0") #  pas de mult, pas de div
        simulator = simulator.replace("e4x_im1", "e4x_im4d2") # change mult -> basé ressources, ajoute div
        simulator = simulator.replace("e4x_im2", "e4x_im4d0") # change mult -> basé ressources, ajoute div

        simulator = simulator.replace("e4x_em0", "e4x_em0d0") # pas de mult, pas de div
        simulator = simulator.replace("e4x_em1", "e4x_em4d2") # change mult -> basé ressources, ajoute div
        simulator = simulator.replace("e4x_em2", "e4x_em4d0") # change mult -> basé ressources, ajoute div

        simulator = simulator.replace("e4px", "e4x_im5d2") # ajout mult dsp -> basé ressources

        # e2_i-em0-3 -> add div
        simulator = simulator.replace("e2_im0", "e2_im0d1")
        simulator = simulator.replace("e2_im1", "e2_im1d1")
        simulator = simulator.replace("e2_im2", "e2_im2d1")
        simulator = simulator.replace("e2_im3", "e2_im3d1")

        simulator = simulator.replace("e2_em0", "e2_em0d1")
        simulator = simulator.replace("e2_em1", "e2_em1d1")
        simulator = simulator.replace("e2_em2", "e2_em2d1")
        simulator = simulator.replace("e2_em3", "e2_em3d1")

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
            tpg_canonical, seed = self.canonicalize_tpg_dir(tpg_dir_name)

            simulator = minimal["simulator"]
            isa=minimal["isa"]
            abi=minimal["abi"]
            dtype=minimal["dtype"]

            iset = self.assign_iset_operator_nickname(tpg_canonical)
            simulator_nickname = self.assign_simulator_nickname(simulator)
            isa_nickname = self.assign_isa_nickname(isa)
 
            # Initialize group if needed
            if isa_nickname not in data[tpg_canonical][simulator_nickname]:
                data[tpg_canonical][simulator_nickname][isa_nickname] = ArchGroup(
                    tpg_canonical=tpg_canonical,
                    simulator=simulator_nickname,
                    isa=isa_nickname,
                    abi=abi,
                    iset=iset,
                    dtype=dtype,
                    seeds=[],
                )

            # Append seed result
            seed_result = SeedResult(
                mean=minimal["tpg_mean_latency"],
                stddev=minimal["tpg_stddev_latency"],
                seed = seed
                #source_file=jf,
                #tpg_dir_name = tpg_dir_name
            )
            data[tpg_canonical][simulator_nickname][isa_nickname].seeds.append(seed_result)

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
                            "iset": group.iset,
                            "dtype": group.dtype,
                            "uarch": uarch,
                            "isa": isa,
                            "abi": group.abi,
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
                        "iset": group.iset,
                        "dtype": group.dtype,
                        "uarch": uarch,
                        "isa": isa,
                        "abi": group.abi,
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

    # === PLOT A: best architectures for a given TPG ===
    def plot_x_axis_uarchs_y_axis_one_tpg(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]):
        """
        Generate one figure per TPG.
        X-axis: uarch | ISA
        Y-axis: log-scale latency
        Points: mean latency, error bars = stddev
        Two ISAs per uarch: cross = compressed ISA ('c' extension), point = base ISA (without 'c')
        """
        USE_UARCH_ISA = False

        for tpg, uarch_map in data.items():

            # fetch tpg informations from any group under this TPG
            try:
                sample_group = next(iter(next(iter(uarch_map.values())).values()))
                iset = sample_group.iset
                dtype = sample_group.dtype
                tpg_canonical = sample_group.tpg_canonical
            except Exception:
                iset = ""
                dtype = ""
                tpg_canonical = tpg

            fig, ax = plt.subplots(figsize=(14, 6), constrained_layout=True)
            ax.set_title(f"Latency per uarch for TPG: {iset} {dtype}")
            if (USE_UARCH_ISA):
                ax.set_xlabel("uarch | isa")
            else:
                ax.set_xlabel("uarch")
            ax.set_ylabel("Latency CC")
            ax.set_yscale("log")

            uarchs_sorted = sorted(uarch_map.keys())
            x_ticks = []
            x_labels = []
            y_axis_all_vals = []

            # get the isa for dic[tpg][uarch]
            for xi, uarch in enumerate(uarchs_sorted):
                isa_map = uarch_map[uarch]
                if len(isa_map) != 2:
                    print(f"WARNING: uarch {uarch} does not have exactly 2 ISAs, skipping.")
                    continue

                isa_list = list(isa_map.keys())
                no_c_isa, with_c_isa = self.is_c_extension(isa_list[0], isa_list[1])

                # --- Compute both ISA stats first
                stats = {}
                for isa in [no_c_isa, with_c_isa]:
                    group = isa_map[isa]
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]
                    if not seed_means:
                        continue

                    stats[isa] = {
                        "mean": mean(seed_means),
                        "stddev": mean(seed_stddevs) if seed_stddevs else 0.0,
                    }

                if len(stats) != 2:
                    continue

                # --- Decide color logic
                base_better = stats[no_c_isa]["mean"] < stats[with_c_isa]["mean"]
                base_color = "red" if base_better else "black"

                # --- Plot
                for isa, marker, label in zip(
                    [no_c_isa, with_c_isa],
                    ["o", "x"],
                    ["base_isa", "compressed_isa"],
                ):
                    mean_latency = stats[isa]["mean"]
                    stddev_latency = stats[isa]["stddev"]

                    y_axis_all_vals.extend([
                        mean_latency + stddev_latency,
                        mean_latency - stddev_latency,
                    ])

                    offset = 0.1
                    x_pos = xi - offset if isa == no_c_isa else xi + offset
                    color = base_color if isa == no_c_isa else "black"

                    ax.errorbar(
                        x_pos,
                        mean_latency,
                        yerr=stddev_latency,
                        fmt=marker,
                        color=color,
                        capsize=5,
                        label=label,
                    )

                # X-axis label as "uarch | ISA"
                x_ticks.append(xi)

                if (USE_UARCH_ISA):
                    x_labels.append(f"{uarch}\n{no_c_isa}") #/{with_c_isa})
                else:
                    x_labels.append(f"{uarch}")
            
            # define y-axis start and end index
            if y_axis_all_vals:
                ymin = min(y_axis_all_vals)
                ymax = max(y_axis_all_vals)
                ax.set_ylim(ymin*0.9, ymax*1.1)

            ax.set_xticks(x_ticks)
            ax.set_xticklabels(x_labels, rotation=45, ha="right")

            # Only show base/compressed ISA in legend once
            handles, labels = ax.get_legend_handles_labels()
            by_label = {}
            for h, l in zip(handles, labels):
                by_label[l] = h

            ax.legend(
                by_label.values(),
                by_label.keys(),
                title="ISA",
                loc="center left",
                bbox_to_anchor=(1.02, 0.5),
            )

            fig.tight_layout()
            plt.show()

            safe_name = self.sanitize_filename(f"{tpg_canonical}_latency_per_uarch.png")
            fig_path = self.out / safe_name
            fig.savefig(fig_path)
            plt.close(fig)
            print(f"Saved plot for TPG {tpg_canonical} to {fig_path}")

    def plot_x_axis_tpgs_y_axis_one_uarch(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]):
        """
        data[tpg][uarch][isa]
        Generate one figure per uarch.
        X-axis: TPG (iset)
        Y-axis: log-scale latency
        Two ISAs per TPG: red = no 'c', blue = with 'c'
        """
        float_color = '#252323' # Shadow Grey
        fixedpt_color = '#540b0e' # Sate Grey

        # --- Gather all possible uarchs across all TPGs
        all_uarchs = set()
        for tpg, uarch_map in data.items():
            all_uarchs.update(uarch_map.keys())

        # --- Build one plot per uarch
        for uarch in sorted(all_uarchs):

            # Build TPG list that contains tpg using this uarch and iset, dtype informations for this tpg
            tpg_using_uarch = []

            # getting the tpgs that use this uarch only 
            for tpg, uarch_map in data.items():
                if uarch not in uarch_map:
                    continue

                # Extract iset, dtype
                try:
                    sample_group = next(iter(next(iter(uarch_map.values())).values()))
                    iset = sample_group.iset
                    dtype = sample_group.dtype
                except Exception:
                    iset = "unk"
                    dtype = "unk"

                tpg_using_uarch.append((tpg, iset, dtype))

            iset_custom_order = [
                "{*,/,>,-,+}",
                "{log,exp,*,/,>,-,+}",
                "{trig,*,/,>,-,+}",
                "{trig,log,exp,*,/,>,-,+}",
                "{log2,exp2,>,-,+}",
                "{log2,exp2,*,>,-,+}",
                "{log2,exp2,*,/,>,-,+}",
            ]

            # Map each string to its order index
            iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}

            # order the tpg list by dtype, iset 
            tpg_using_uarch.sort(key=lambda tup: (tup[2], iset_order_index[tup[1]])) #(tup[2], tup[1]) for dtype and then iset


            fig, ax = plt.subplots(figsize=(12, 6), constrained_layout=True)
            ax.set_title(f"Latency per TPG for uarch: {uarch}")
            ax.set_xlabel("TPG")
            ax.set_ylabel("Latency CC")
            ax.set_yscale("log")

            # X-axis = TPG nicknames
            x_ticks = range(len(tpg_using_uarch))
            ax.set_xticks(x_ticks)
            ax.set_xticklabels([x[1] for x in tpg_using_uarch], rotation=45, ha="right")

            # color each label based on dtype
            for tick_label, dtype in zip (ax.get_xticklabels(), [x[2] for x in tpg_using_uarch]):
                if dtype == "float":
                    tick_label.set_color(float_color)
                elif dtype == "fixedpt":
                    tick_label.set_color(fixedpt_color)
                else:
                    tick_label.set_color("black")   # fallback

            # --- Secondary X-axis for dtypes ---
            ax2 = ax.twiny()
            ax2.set_xlim(ax.get_xlim())
            ax2.set_xticks([])  # Hide default ticks

            # Group TPGs by dtype and compute positions for labels
            dtype_positions = {}
            for xi, dtype in enumerate([x[2] for x in tpg_using_uarch]):
                if dtype not in dtype_positions:
                    dtype_positions[dtype] = []
                dtype_positions[dtype].append(xi)

            # Add dtype labels at the center of each group with color
            for dtype, positions in dtype_positions.items():
                center_pos = sum(positions) / len(positions)
                color = float_color if dtype == "float" else fixedpt_color if dtype == "fixedpt" else "black"
                ax2.text(
                    center_pos, -0.40, dtype,
                    ha="center", va="top",
                    transform=ax.get_xaxis_transform(),
                    fontsize=10,
                    color=color
                )

            y_axis_all_vals = []
            # --- Plot each TPG
            for xi, tpg in enumerate([x[0] for x in tpg_using_uarch]):
                isa_map = data[tpg][uarch]
                if len(isa_map) != 2:
                    print(f"WARNING: In uarch {uarch}, TPG {tpg} does not have exactly 2 ISAs, skipping.")
                    continue

                isa_list = list(isa_map.keys())
                no_c_isa, with_c_isa = self.is_c_extension(isa_list[0], isa_list[1])

                # --- Compute both ISA stats first
                stats = {}
                for isa in [no_c_isa, with_c_isa]:
                    group = isa_map[isa]
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]
                    if not seed_means:
                        continue

                    stats[isa] = {
                        "mean": mean(seed_means),
                        "stddev": mean(seed_stddevs),
                    }

                if len(stats) != 2:
                    continue

                # --- Decide color logic
                base_better = stats[no_c_isa]["mean"] < stats[with_c_isa]["mean"]
                base_color = "red" if base_better else "black"

                # --- Plot
                for isa, marker in zip([no_c_isa, with_c_isa], ["o", "x"]):
                    mean_latency = stats[isa]["mean"]
                    stddev_latency = stats[isa]["stddev"]

                    y_axis_all_vals.extend([
                        mean_latency + stddev_latency,
                        mean_latency - stddev_latency,
                    ])

                    offset = 0.1
                    x_pos = xi - offset if isa == no_c_isa else xi + offset
                    color = base_color if isa == no_c_isa else "black"

                    ax.errorbar(
                        x_pos,
                        mean_latency,
                        yerr=stddev_latency,
                        fmt=marker,
                        color=color,
                        capsize=5,
                        label=isa,
                    )

            # define y-axis start and end index
            if y_axis_all_vals:
                ymin = min(y_axis_all_vals)
                ymax = max(y_axis_all_vals)
                ax.set_ylim(ymin*0.9, ymax*1.1)

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
            plt.show()

            safe_name = self.sanitize_filename(f"{uarch}_latency_per_tpg.png")
            fig_path = self.out / safe_name
            fig.savefig(fig_path, bbox_inches="tight")
            plt.close(fig)

            print(f"Saved plot for uarch {uarch} to {fig_path}")


    def plot_x_axis_tpgs_y_axis_all_uarchs(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]):
        """
        data[tpg][uarch][isa]
        Generate a figure, x-axis represents different tpgs, y-axis different uarchs for this tpg.
        X-axis: TPG (iset)
        Y-axis: log-scale latency
        Two ISAs per TPG: red = no 'c', blue = with 'c'
        
        1. get all possible tpg -> define x-axis length
        2. for each tpg, find its uarchs
            a. a new uarch gets a color attributed 
        """
        float_color = '#252323' # Shadow Grey
        fixedpt_color = '#540b0e' # Sate Grey

        # count nb_tpg
        nb_tpg = len(data)

        # prepare fig 
        # x-axis shows iset, dtype for each tpg
        
        # --- Gather all possible uarchs across all TPGs
        all_tpg = []
        for tpg, uarch_map in data.items():
            # find iset and type 
            try:
                sample_group = next(iter(next(iter(uarch_map.values())).values()))
                iset = sample_group.iset
                dtype = sample_group.dtype
            except Exception:
                iset = "unk"
                dtype = "unk"
                
            all_tpg.append((tpg, iset, dtype))

        iset_custom_order = [
            "{*,/,>,-,+}",
            "{log,exp,*,/,>,-,+}",
            "{trig,*,/,>,-,+}",
            "{trig,log,exp,*,/,>,-,+}",
            "{log2,exp2,>,-,+}",
            "{log2,exp2,*,>,-,+}",
            "{log2,exp2,*,/,>,-,+}",
        ]

        # Map each string to its order index
        iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}     

        # order the tpg list by dtype, iset 
        all_tpg.sort(key=lambda tup: (tup[2], iset_order_index[tup[1]])) #(tup[2], tup[1]) for dtype and then iset

        fig, ax = plt.subplots(figsize=(24, 6), constrained_layout=True)
        ax.set_title(f"Latency per TPG for all uarchs")
        ax.set_xlabel("TPG")
        ax.set_ylabel("Latency CC")
        ax.set_yscale("log")

        # X-axis = TPG nicknames
        x_ticks = range(nb_tpg)
        ax.set_xticks(x_ticks)
        ax.set_xticklabels([x[1] for x in all_tpg], rotation=45, ha="right")

        # color each label based on dtype
        for tick_label, dtype in zip (ax.get_xticklabels(), [x[2] for x in all_tpg]):
            if dtype == "float":
                tick_label.set_color(float_color)
            elif dtype == "fixedpt":
                tick_label.set_color(fixedpt_color)
            else:
                tick_label.set_color("black")   # fallback

        # --- Secondary X-axis for dtypes ---
        ax2 = ax.twiny()
        ax2.set_xlim(ax.get_xlim())
        ax2.set_xticks([])  # Hide default ticks

        # Group TPGs by dtype and compute positions for labels
        dtype_positions = {}
        for xi, dtype in enumerate([x[2] for x in all_tpg]):
            if dtype not in dtype_positions:
                dtype_positions[dtype] = []
            dtype_positions[dtype].append(xi)

        # Add dtype labels at the center of each group with color
        for dtype, positions in dtype_positions.items():
            center_pos = sum(positions) / len(positions)
            color = float_color if dtype == "float" else fixedpt_color if dtype == "fixedpt" else "black"
            ax2.text(
                center_pos, -0.40, dtype,
                ha="center", va="top",
                transform=ax.get_xaxis_transform(),
                fontsize=10,
                color=color
            )


        
         # Gather all y values
        y_axis_all_vals = []
        # Gather all x positions used
        x_axis_all_x_positions = []
        # dic that associate a color and id to each uarch
        uarchs_color = {}
        id_ku = 0
        offset_isa = 0.025
        offset_uarch = offset_isa * 2.5

        # --- Plot each TPG
        for xi, tpg in enumerate([x[0] for x in all_tpg]):
            for uarch in data[tpg]:

                # check if its a new uarch -> assign color
                if not uarch in uarchs_color:
                    color = np.random.rand(3,)
                    uarchs_color.update({uarch: (color, id_ku)})
                    id_ku +=1

                isa_map = data[tpg][uarch]
                if len(isa_map) != 2:
                    print(f"WARNING: In uarch {uarch}, TPG {tpg} does not have exactly 2 ISAs, skipping.")
                    continue

                isa_list = list(isa_map.keys())
                no_c_isa, with_c_isa = self.is_c_extension(isa_list[0], isa_list[1])

                x_offsets = []
                for isa, marker in zip([no_c_isa, with_c_isa], ["o", "x"]):
                    group = isa_map[isa]
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]

                    if not seed_means:
                        continue

                    mean_latency = mean(seed_means)
                    stddev_latency = mean(seed_stddevs)

                    y_axis_all_vals.append(mean_latency+stddev_latency)
                    y_axis_all_vals.append(mean_latency-stddev_latency)
                    
                    # display point on plot
                    offset = offset_isa # small jitter offset
                    x_pos = xi - offset if isa == no_c_isa else xi + offset
                    
                    index = uarchs_color[uarch][1]
                    center = True
                    if center:
                        if index%2 == 0:
                            x_pos = x_pos - index/2 * offset_uarch
                        else:
                            x_pos = x_pos + index/2 * offset_uarch
                    else:
                        x_pos = x_pos - index * offset_uarch
                    x_offsets.append(x_pos)
                    ax.errorbar(
                        x_pos, mean_latency,
                        yerr=stddev_latency,
                        fmt=marker,
                        color=uarchs_color[uarch][0],
                        capsize=5,
                        label=isa
                    )
                x_axis_all_x_positions.extend(x_offsets)
        # Set x-limits tightly around points 
        ax.set_xlim(min(x_axis_all_x_positions) - 0.05, max(x_axis_all_x_positions) + 0.05)

        # define y-axis start and end index
        if y_axis_all_vals:
            ymin = min(y_axis_all_vals)
            ymax = max(y_axis_all_vals)
            ax.set_ylim(ymin*0.9, ymax*1.1)

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

        safe_name = self.sanitize_filename(f"x-axis_tpgs_all_uarchs.png")
        fig_path = self.out / safe_name
        fig.savefig(fig_path, bbox_inches="tight")
        plt.close(fig)

        print(f"Saved plot for x-axis_tpgs_all_uarchs")

    def plot_x_axis_tpgs_y_axis_all_uarchs_min_max(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]):
        """
        data[tpg][uarch][isa]
        Generate a figure, x-axis represents different tpgs, y-axis different uarchs for this tpg.
        X-axis: TPG (iset)
        Y-axis: log-scale latency
        Two ISAs per TPG: red = no 'c', blue = with 'c'
        
        """
        float_color = '#252323' # Shadow Grey
        fixedpt_color = '#540b0e' # Sate Grey

        # count nb_tpg
        nb_tpg = len(data)

        # prepare fig 
        # x-axis shows iset, dtype for each tpg
        
        # --- Gather all possible uarchs across all TPGs
        all_tpg = []
        for tpg, uarch_map in data.items():
            # find iset and type 
            try:
                sample_group = next(iter(next(iter(uarch_map.values())).values()))
                iset = sample_group.iset
                dtype = sample_group.dtype
            except Exception:
                iset = "unk"
                dtype = "unk"
                
            all_tpg.append((tpg, iset, dtype))

        iset_custom_order = [
            "{*,/,>,-,+}",
            "{log,exp,*,/,>,-,+}",
            "{trig,*,/,>,-,+}",
            "{trig,log,exp,*,/,>,-,+}",
            "{log2,exp2,>,-,+}",
            "{log2,exp2,*,>,-,+}",
            "{log2,exp2,*,/,>,-,+}",
        ]

        # Map each string to its order index
        iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}     

        # order the tpg list by dtype, iset 
        all_tpg.sort(key=lambda tup: (tup[2], iset_order_index[tup[1]])) #(tup[2], tup[1]) for dtype and then iset

        fig, ax = plt.subplots(figsize=(12, 6), constrained_layout=True)
        ax.set_title(f"Latency per TPG for all uarchs")
        ax.set_xlabel("TPG")
        ax.set_ylabel("Latency CC")
        ax.set_yscale("log")

        # X-axis = TPG nicknames
        x_ticks = range(nb_tpg)
        ax.set_xticks(x_ticks)
        ax.set_xticklabels([x[1] for x in all_tpg], rotation=45, ha="right")

        # color each label based on dtype
        for tick_label, dtype in zip (ax.get_xticklabels(), [x[2] for x in all_tpg]):
            if dtype == "float":
                tick_label.set_color(float_color)
            elif dtype == "fixedpt":
                tick_label.set_color(fixedpt_color)
            else:
                tick_label.set_color("black")   # fallback

        # --- Secondary X-axis for dtypes ---
        ax2 = ax.twiny()
        ax2.set_xlim(ax.get_xlim())
        ax2.set_xticks([])  # Hide default ticks

        # Group TPGs by dtype and compute positions for labels
        dtype_positions = {}
        for xi, dtype in enumerate([x[2] for x in all_tpg]):
            if dtype not in dtype_positions:
                dtype_positions[dtype] = []
            dtype_positions[dtype].append(xi)

        # Add dtype labels at the center of each group with color
        for dtype, positions in dtype_positions.items():
            center_pos = sum(positions) / len(positions)
            color = float_color if dtype == "float" else fixedpt_color if dtype == "fixedpt" else "black"
            ax2.text(
                center_pos, -0.40, dtype,
                ha="center", va="top",
                transform=ax.get_xaxis_transform(),
                fontsize=10,
                color=color
            )

        # Gather all y values
        y_axis_all_vals = []
        # Gather all x positions used
        x_axis_all_x_positions = []
        # dic that associate a color and id to each uarch
        uarchs_color = {}
        offset_min_max = 0.025
        x_offsets = []

        # --- Plot each TPG
        for xi, tpg in enumerate([x[0] for x in all_tpg]):
            
            # uarch_vals to use (we keep only two uarchs (min, max) for readability of the plot)
            uarch_vals = []
            
            for uarch in data[tpg]:

                # check if its a new uarch -> assign color
                if not uarch in uarchs_color:
                    color = np.random.rand(3,)
                    uarchs_color.update({uarch: (color)})

                isa_map = data[tpg][uarch]
                if len(isa_map) != 2:
                    print(f"WARNING: In uarch {uarch}, TPG {tpg} does not have exactly 2 ISAs, skipping.")
                    continue

                isa_list = list(isa_map.keys())
                no_c_isa, with_c_isa = self.is_c_extension(isa_list[0], isa_list[1])

                for isa, marker in zip([no_c_isa, with_c_isa], ["o", "x"]):
                    group = isa_map[isa]
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]

                    if not seed_means:
                        continue

                    mean_latency = mean(seed_means)
                    stddev_latency = mean(seed_stddevs)

                    uarch_vals.append((mean_latency, stddev_latency, isa, marker, uarch, no_c_isa)) 

            if not uarch_vals:
                print("missing uarch_vals")
                continue
                
            uarchs_to_display = []    

            min_uarch = min(uarch_vals, key=lambda t: t[0])
            max_uarch = max(uarch_vals, key=lambda t: t[0])

            uarchs_to_display.append(min_uarch)
            uarchs_to_display.append(max_uarch)

            for i, uarch in enumerate(uarchs_to_display):

                mean_latency, stddev_latency, isa, marker, uarch_name, no_c_isa = uarch
                y_axis_all_vals.append(mean_latency+stddev_latency)
                y_axis_all_vals.append(mean_latency-stddev_latency)        

                # display point on plot
                x_pos = xi
            
                #deal with indexes 
                if i == 0:
                    x_pos = x_pos - offset_min_max
                else:
                    x_pos = x_pos + offset_min_max

                x_offsets.append(x_pos)
                ax.errorbar(
                    x_pos, mean_latency,
                    yerr=stddev_latency,
                    fmt=marker,
                    color=uarchs_color[uarch_name],
                    capsize=5,
                    label=uarch_name + "|" + isa
                )

        x_axis_all_x_positions.extend(x_offsets)
        # Set x-limits tightly around points 
        ax.set_xlim(min(x_axis_all_x_positions) - 0.05, max(x_axis_all_x_positions) + 0.05)

        # define y-axis start and end index
        if y_axis_all_vals:
            ymin = min(y_axis_all_vals)
            ymax = max(y_axis_all_vals)
            ax.set_ylim(ymin*0.9, ymax*1.1)

        # Unique legend (outside plot)
        handles, labels = ax.get_legend_handles_labels()
        by_label = dict(zip(labels, handles))

        ax.legend(
            by_label.values(),
            by_label.keys(),
            title="UARCH | ISA",
            loc="center left",
            bbox_to_anchor=(1.02, 0.5),
        )

        fig.tight_layout()

        safe_name = self.sanitize_filename(f"x-axis_tpgs_all_uarchs_min_max.png")
        fig_path = self.out / safe_name
        fig.savefig(fig_path, bbox_inches="tight")
        plt.close(fig)

        print(f"Saved plot for x-axis_tpgs_all_uarchs_min_max")

    
    def plot_x_axis_uarchs_y_axis_all_tpgs(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]]):
        """
        x-axis represents uarchs
        y-axis represents tpgs using this uarch
        1. find all uarchs to define x-axis
        2. for each uarch write every tpg on its column
        """
        fig, ax = plt.subplots(figsize=(28, 6), constrained_layout=True)
        ax.set_title(f"Latency per uarch for all TPG")
        ax.set_xlabel("uarch")
        ax.set_ylabel("Latency CC")
        ax.set_yscale("log")

        # find all uarchs to define x-axis
        all_uarchs = []

        for tpg, uarch_map in data.items():
            for uarch, isa_map in uarch_map.items():
                if uarch not in all_uarchs:
                    all_uarchs.append(uarch)

        uarch_custom_order = [
            "e2_em0d1",
            "e2_em1d1",
            "e2_em2d1",
            "e2_em3d1",
            
            "e2_im0d1",
            "e2_im1d1",
            "e2_im2d1",
            "e2_im3d1",
            
            "e4_em0d0",
            "e4_em4d0",
            "e4_em4d2",

            "e4_im0d0",
            "e4_im4d0",
            "e4_im4d2",
            
            "e4_im5d2",
            "e4_im5d2_pulp",
            "e4_im5d2_fpu",
            "e4_im5d2_pulp_fpu",
        ]

        # Map each string to its order index
        uarch_order_index = {s: i for i, s in enumerate(uarch_custom_order)}     

        # sort the all_uarchs list 
        # indexes will be used to find where to place each corresonding TPG on the figure 
        all_uarchs.sort(key=lambda e: uarch_order_index.get(e, len(uarch_custom_order)))


        x_ticks = range(len(all_uarchs))
        ax.set_xticks(x_ticks)
        ax.set_xticklabels(all_uarchs, rotation=45, ha="right")

        y_axis_all_vals = []
        tpg_colors = {}
        id_ku = 0
        # Gather all x positions used
        x_axis_all_x_positions = []
        offset_isa = 0.025
        offset_uarch = offset_isa * 2.5

        for tpg, uarch_map in data.items():

            if not tpg in tpg_colors:
                color = np.random.rand(3,)
                tpg_colors.update({tpg: (color, id_ku)})
                id_ku += 1

            # fetch tpg informations from any group under this TPG
            try:
                sample_group = next(iter(next(iter(uarch_map.values())).values()))
                iset = sample_group.iset
                dtype = sample_group.dtype
                tpg_canonical = sample_group.tpg_canonical
                    
            except Exception:
                print("Error on: " + tpg_canonical)
                iset = ""
                dtype = ""
                tpg_canonical = tpg

            uarchs_sorted = sorted(uarch_map.keys())

            # get the isa for dic[tpg][uarch]
            for uarch in uarchs_sorted:
                isa_map = uarch_map[uarch]
                if len(isa_map) != 2:
                    print(f"WARNING: uarch {uarch} does not have exactly 2 ISAs, skipping.")
                    continue

                isa_list = list(isa_map.keys())
                no_c_isa, with_c_isa = self.is_c_extension(isa_list[0], isa_list[1])

                # base and compressed ISA
                for isa, marker, label in zip([no_c_isa, with_c_isa], ["o", "x"], ["base_isa", "compressed_isa"]):
                    group = isa_map[isa]
                    seed_means = [s.mean for s in group.seeds]
                    seed_stddevs = [s.stddev for s in group.seeds]
                    if not seed_means:
                        continue
                    mean_latency = mean(seed_means)
                    stddev_latency = mean(seed_stddevs) if seed_stddevs else 0.0

                    y_axis_all_vals.append(mean_latency + stddev_latency)
                    y_axis_all_vals.append(mean_latency - stddev_latency)

                    # display point on plot
                    # xi is the position of the uarch in all_uarcchs sorted
                    xi = all_uarchs.index(uarch)
                    offset = offset_isa # small jitter offset
                    x_pos = xi - offset if isa == no_c_isa else xi + offset

                    index = tpg_colors[tpg][1]
                    if index%2 == 0:
                        x_pos = x_pos - index/2 * offset_uarch
                    else:
                        x_pos = x_pos + index/2 * offset_uarch

                    x_axis_all_x_positions.append(x_pos)
                    ax.errorbar(
                        x_pos, mean_latency,
                        yerr=stddev_latency,
                        fmt=marker,
                        color=tpg_colors[tpg][0],
                        capsize=5,
                        label=iset + ", " + dtype #+ "|" + isa
                    )
                    
        # define x-axis start and end index
        ax.set_xlim(min(x_axis_all_x_positions) - 0.05, max(x_axis_all_x_positions) + 0.05)

        # define y-axis start and end index
        if y_axis_all_vals:
            ymin = min(y_axis_all_vals)
            ymax = max(y_axis_all_vals)
            ax.set_ylim(ymin*0.9, ymax*1.1)


        ###### LEGEND ######    
        # Only show base/compressed ISA in legend once
        handles, labels = ax.get_legend_handles_labels()

        legend_entries = {}
        for h, l in zip(handles, labels):
            if l not in legend_entries:
                legend_entries[l] = h

        # --- custom iset order ---
        iset_custom_order = [
            "{*,/,>,-,+}",
            "{log,exp,*,/,>,-,+}",
            "{trig,*,/,>,-,+}",
            "{trig,log,exp,*,/,>,-,+}",
            "{log2,exp2,>,-,+}",
            "{log2,exp2,*,>,-,+}",
            "{log2,exp2,*,/,>,-,+}",
        ]
        iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}

        def legend_sort_key(label: str):
            # label = "{iset,...}, dtype"
            try:
                iset, dtype = [s.strip() for s in label.rsplit(",", 1)]
            except ValueError:
                print("valueError in sort key:", label)
                return ("", float("inf"))

            # 1. dtype 2. isets, unknown isets last
            return (dtype, iset_order_index.get(iset, len(iset_custom_order)))


        # sort legend entries
        sorted_items = sorted(
            legend_entries.items(),
            key=lambda item: legend_sort_key(item[0])
        )

        sorted_labels = [l for l, _ in sorted_items]
        sorted_handles = [h for _, h in sorted_items]


        ax.legend(
            sorted_handles,
            sorted_labels,
            title="TPG",
            loc="center left",
            bbox_to_anchor=(1.02, 0.5),
        )
        ###### END LEGEND ######    

        fig.tight_layout()
        safe_name = self.sanitize_filename(f"x-axis all uarchs_y-axis_all_tpgs.png")
        fig_path = self.out / safe_name
        fig.savefig(fig_path)
        plt.close(fig)
        print(f"Saved plot to {fig_path}")


    def sanitize_filename(self, s: str) -> str:
        """Make a safe filename from a string."""
        return re.sub(r'[^A-Za-z0-9._-]+', '_', s)[:200]

    def save_csv(self, df: pd.DataFrame, file_name: str):
        csv_path = self.out / file_name
        df.to_csv(csv_path, index=False)
        print(f"Saved aggregated CSV to {csv_path}")


    def import_tpg_accuracies(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]], csv_accuracies_path: str):
        """
        Import accuracies from a CSV file and integrate them into the data structure.
        The CSV is expected to have columns: 'tpg_canonical', 'accuracy'.
        """
        if not os.path.isfile(csv_accuracies_path):
            print(f"WARNING: Accuracy CSV file {csv_accuracies_path} not found.")
            return

        variable = 'vDistMax' # 'vSuccess'

        accuracies_df = pd.read_csv(csv_accuracies_path)

        # Keep only Gen == 99
        gen99 = accuracies_df[accuracies_df['Gen'] == 99]

        # One value per (instrType, instrSetName, seed)
        grouped = gen99.groupby(
            ['instrType', 'instrSetName', 'seed'],
            as_index=False
        )[variable].mean()

        accuracies_summary = grouped.groupby(['instrType', 'instrSetName'], 
            as_index=False)[variable].agg(mean='mean', std='std')

        instrType_order = ['double', 'float', 'fixedpt']

        instrSet_order = [
            'comp',
            'logexp',
            'trigo',
            'complete',
            'l2e2_compBare',
            'l2e2_compZmmul',
            'l2e2_compExpAr'
        ]

        instrSet_labels = {
            'comp': "{" + "*,/,>,-,+" + "}",
            'logexp': "{" + "log,exp," + "*,/,>,-,+" + "}",
            'trigo': "{" + "trig," + "*,/,>,-,+" + "}",
            'complete': "{" + "trig," + "log,exp," + "*,/,>,-,+" + "}",
            'l2e2_compBare': "{" + "log2,exp2," + ">,-,+" + "}",
            'l2e2_compZmmul': "{" + "log2,exp2," + "*," + ">,-,+" + "}",
            'l2e2_compExpAr': "{" + "log2,exp2," + "*,/," + ">,-,+" + "}"
        }

        accuracies_summary['instrSet_label'] = accuracies_summary['instrSetName'].map(instrSet_labels)

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    
                    # fetch in accuracies_summary 
                    for row in accuracies_summary.itertuples(index=False):
                        if row.instrSet_label + row.instrType == archgroup.iset + archgroup.dtype: 
                            archgroup.accuracy = row.mean
                            # archgroup.accuracy_std = row.std
                            #print(archgroup.iset, archgroup.dtype, row.mean)
    
    def is_pareto_efficient(self, costs):
        """
        Find the Pareto-efficient points (minimizing both objectives)
        """
        is_efficient = np.ones(costs.shape[0], dtype=bool)
        for i, c in enumerate(costs):
            if is_efficient[i]:
                # Remove dominated points (those worse in both dimensions)
                is_efficient[is_efficient] = np.any(costs[is_efficient] < c, axis=1)
                is_efficient[i] = True
        return is_efficient

    def plot_pareto_front_acc_lat(self, data):

        accuracies = []
        latencies = []
        points_meta = []   # full provenance per point

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    if archgroup.accuracy is not None:
                        # archgroup.iset + archgroup.dtype  
                        accuracies.append(archgroup.accuracy)
                        seed_means = [s.mean for s in archgroup.seeds]
                        #overall mean for this [tpg][uarch][isa] taking each seed into account (no stddev used)
                        latencies.append(mean(seed_means)) 
                        points_meta.append({
                            "tpg": tpg,
                            "uarch": uarch,
                            "isa": isa,
                            "iset": archgroup.iset,
                            "dtype": archgroup.dtype,
                        })

        X = np.array(accuracies)
        Y = np.array(latencies)
        
        categories = [(m["iset"], m["dtype"]) for m in points_meta]
        unique_cats = list(dict.fromkeys(categories))

        cmap = plt.get_cmap('tab20')
        color_map = {
            cat: cmap(i % cmap.N)
            for i, cat in enumerate(unique_cats)
        }

        colors = np.array([(*color_map[c][:3], 0.6) for c in categories])

        # Combine X and Y into a cost matrix
        costs = np.column_stack((X, Y))

        # Find Pareto-efficient points
        pareto_mask = self.is_pareto_efficient(costs)
        pareto_X = X[pareto_mask]
        pareto_Y = Y[pareto_mask]

        pareto_points = [
            meta
            for meta, is_pareto in zip(points_meta, pareto_mask)
            if is_pareto
        ]

        pareto_colors = [ color_map[c] for c, is_pareto in zip(categories, pareto_mask) if is_pareto ]
                
        # Sort Pareto points for proper line plotting
        sort_idx = np.argsort(pareto_X)
        pareto_X_sorted = pareto_X[sort_idx]
        pareto_Y_sorted = pareto_Y[sort_idx]

        # Create the plot
        plt.figure(figsize=(10, 7))

        # Plot all points
        plt.scatter(X[~pareto_mask],Y[~pareto_mask], c=colors[~pareto_mask], alpha=0.6, s=50, label='Dominated solutions', zorder=1)

        # Plot Pareto front points
        pareto_colors = [
            color_map[c]
            for c, is_pareto in zip(categories, pareto_mask)
            if is_pareto
        ]
        plt.scatter(pareto_X, pareto_Y, c=pareto_colors, s=100, label='Pareto front', zorder=3, edgecolors=pareto_colors, linewidth=1.5)

        # Connect Pareto front points with a line
        plt.plot(pareto_X_sorted, pareto_Y_sorted, 'r--', linewidth=2, alpha=0.7, zorder=2)

        # Styling
        plt.xlabel('Distance to objective', fontsize=12, fontweight='bold')
        plt.ylabel('Latency', fontsize=12, fontweight='bold')
        plt.title('Pareto Front Visualization', fontsize=14, fontweight='bold')
        plt.legend(fontsize=11, loc='upper right')
        plt.grid(True, alpha=0.3, linestyle='--')
        plt.tight_layout()

        # Add arrow annotations to show the improvement direction
        plt.annotate('', xy=(1, 1), xytext=(3, 3), arrowprops=dict(arrowstyle='->', lw=2, color='green', alpha=0.6))
        plt.text(2.5, 2.5, 'Better', fontsize=10, color='green', fontweight='bold', ha='center')

        plt.yscale('log')

        from matplotlib.lines import Line2D

        iset_custom_order = [
            "{*,/,>,-,+}",
            "{log,exp,*,/,>,-,+}",
            "{trig,*,/,>,-,+}",
            "{trig,log,exp,*,/,>,-,+}",
            "{log2,exp2,>,-,+}",
            "{log2,exp2,*,>,-,+}",
            "{log2,exp2,*,/,>,-,+}",
        ]
        iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}

        def legend_sort_key(cat):
            iset, dtype = cat
            return (
                dtype,  # primary: dtype
                iset_order_index.get(iset, len(iset_custom_order))  # secondary: iset
            )

        # Sort categories
        sorted_cats = sorted(unique_cats, key=legend_sort_key)

        iset_dtype_elements = [
            Line2D(
                [0], [0],
                marker='o',
                linestyle='',
                markerfacecolor=color_map[(iset, dtype)],
                markeredgewidth=0,      # no outline
                label=f"{iset}, {dtype}",
                markersize=9,
            )
            for (iset, dtype) in sorted_cats
        ]

        pareto_arch_elements = []
        seen = set()

        for meta in pareto_points:
            key = (meta["uarch"], meta["isa"])
            if key in seen:
                continue
            seen.add(key)

            pareto_arch_elements.append(
                Line2D(
                    [0], [0],
                    marker='o',
                    linestyle='',
                    markerfacecolor=color_map[(meta["iset"], meta["dtype"])],
                    markeredgewidth=0,
                    markersize=9,
                    label=f'{meta["uarch"]} | {meta["isa"]}'
                )
            )

        iset_header = Line2D(
            [], [], linestyle='none',
            label="Instruction set | dtype"
        )

        pareto_header = Line2D(
            [], [], linestyle='none',
            label="Pareto-efficient uarch | isa"
        )


        legend_elements = (
            [iset_header]
            + iset_dtype_elements
            + [Line2D([], [], linestyle='none', label="")]  # spacer
            + [pareto_header]
            + pareto_arch_elements
        )

        plt.legend(
            handles=legend_elements,
            fontsize=9,
            loc='best',
            frameon=True,
            handlelength=1.2,
            handletextpad=0.6
        )

        plt.show()

        # Print statistics
        print(f"Total points: {len(X)}")
        print(f"Pareto-efficient points: {np.sum(pareto_mask)}")
        print(f"Percentage on Pareto front: {100 * np.sum(pareto_mask) / len(X):.1f}%")

    def import_uarch_ressources(self, data: Dict[str, Dict[str, Dict[str, ArchGroup]]], uarchs_resources_path: str):
        """
        Import uarch resources from a CSV file and integrate them into the data structure.
        The CSV is expected to have columns: 'uarch', 'LUTs', 'FFs', 'BRAMs', 'DSPs'.
        """
        import pickle

        with open(uarchs_resources_path, "rb") as f:
            uarchs_ressources = pickle.load(f)

        tmp = {}
        for uarch, res in uarchs_ressources.items():
            uarch_nickname = self.assign_simulator_nickname(uarch)
            tmp.update({uarch_nickname: res})

        uarchs_ressources = tmp

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                if uarch in uarchs_ressources.keys():
                    res = uarchs_ressources[uarch]
                    for isa, archgroup in sorted(isa_map.items()):
                        
                        n_dsps = res.get('DSPs')[0]
                        n_luts= res.get("Slice LUTs")[0]
                        n_regs= res.get("Slice Registers")[0]
                       
                        archgroup.uarch_ressources = Uarch_Ressources(
                            dsps=n_dsps,
                            regs=n_regs,
                            luts=n_luts,
                        )   

    def find_baseline(self, data):
        """
        Find the uarch with the minimum LUTs.
        DSPs, LUTs, and Regs are fetched from this uarch.
        We do this since its possible the baseline uarch for LUTs is not the same as for DSPs or Regs.
        The uarch retunned dominates in all three ressources.
        """
        baseline_dsps = 0
        baseline_luts = 1e20
        baseline_regs = 0
        baseline_uarch_name = ""

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    if archgroup.uarch_ressources is not None:
                        res = archgroup.uarch_ressources
                        if res.luts < baseline_luts:
                            baseline_dsps = res.dsps
                            baseline_luts = res.luts
                            baseline_regs = res.regs
                            baseline_uarch_name = uarch

        print(f"Baseline uarch is {baseline_uarch_name} with DSPs: {baseline_dsps}, LUTs: {baseline_luts}, REGs: {baseline_regs}")

        return baseline_dsps, baseline_luts, baseline_regs

    def assign_normalized_ressources(self, data):
        """
        Assign normalized ressources to each archgroup based on the biggest uarch ressources.
        """

        # ------------------------------------------------------------
        # Define a resource cost model (adjustable)
        # ------------------------------------------------------------
        alpha = 0.5   # LUT weight
        beta  = 0.5   # FF weight

        # DSP equivalent cost expressed in LUT/REG terms
        DSP_LUT_EQ = 700 #1500 # 750 LUTs, 150 FFs is the diff btw cv32e20_em1 and cv32e20_em0
        DSP_FF_EQ  = 150 #0

        # Gamma expressed consistently with alpha/beta
        gamma = alpha * DSP_LUT_EQ + beta * DSP_FF_EQ

        baseline_dsps, baseline_luts, baseline_regs = self.find_baseline(data)
        if baseline_luts == 0 or baseline_regs == 0:
            # we use the gamma value for DSPs, so if DSPs is 0 its not a problem
            print("WARNING: One of the baseline ressources is zero, cannot normalize.")
            return

        baseline_cost = (alpha * baseline_luts) + (beta * baseline_regs) + (gamma * baseline_dsps)

        # normalize 
        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    if archgroup.uarch_ressources is not None:
                        res = archgroup.uarch_ressources
                        dsps = res.dsps    
                        luts = res.luts 
                        regs = res.regs 

                        # --------------------------------------------------------
                        # Resource cost
                        # Cost = α·LUT + β·FF + γ·DSP
                        # --------------------------------------------------------
                        cost = alpha * luts + beta * regs + gamma * dsps

                        normalized_cost = 100 * cost / baseline_cost        

                        archgroup.norm_ressource = normalized_cost
                    else:
                        print(f"uarch {uarch} | no ressources info, cannot normalize.")


    def select_best_isa_per_uarch(self, data):
        """
        For each (tpg, uarch), keep only the ISA with the best (lowest) mean latency.
        Returns a new data dict with the same structure.
        """
        filtered_data = {}

        for tpg, uarch_map in data.items():
            filtered_data[tpg] = {}

            for uarch, isa_map in uarch_map.items():
                best_isa = None
                best_latency = float("inf")

                for isa, archgroup in isa_map.items():
                    if not archgroup.seeds:
                        continue

                    seed_means = [s.mean for s in archgroup.seeds]
                    latency = mean(seed_means)

                    if latency < best_latency:
                        best_latency = latency
                        best_isa = isa

                if best_isa is not None:
                    filtered_data[tpg][uarch] = {
                        best_isa: isa_map[best_isa]
                    }

        return filtered_data


    def select_best_isa_for_all_uarchs(self, data):
        """
        For each uarch, find the ISA with the lowest latency (mean over its seeds)
        across ALL tpgs, then keep only that ISA for every tpg.
        """
        # Step 1: collect latencies per (uarch, isa)
        latency_by_uarch_isa = defaultdict(list)

        for tpg, uarch_map in data.items():
            for uarch, isa_map in uarch_map.items():
                for isa, archgroup in isa_map.items():
                    if not archgroup.seeds:
                        continue

                    latency = mean(s.mean for s in archgroup.seeds)
                    latency_by_uarch_isa[(uarch, isa)].append(latency)

        # Step 2: find best ISA per uarch, lowest latency over all tpgs
        best_isa_per_uarch = {}

        for (uarch, isa), latencies in latency_by_uarch_isa.items():

            for latency in latencies:
                if latency is None:
                    continue
                if uarch not in best_isa_per_uarch:
                    best_isa_per_uarch[uarch] = (isa, latency)
                else:
                    _, best_latency = best_isa_per_uarch[uarch]
                    if latency < best_latency:
                        best_isa_per_uarch[uarch] = (isa, latency)

        # Step 3: filter data using the selected ISA per uarch
        filtered_data = {}

        for tpg, uarch_map in data.items():
            filtered_data[tpg] = {}

            for uarch, isa_map in uarch_map.items():
                if uarch not in best_isa_per_uarch:
                    continue

                best_isa = best_isa_per_uarch[uarch][0]

                if best_isa in isa_map:
                    filtered_data[tpg][uarch] = {
                        best_isa: isa_map[best_isa]
                    }

        return filtered_data

    def plot_pareto_front_ress_lat(self, data):

        data = self.select_best_isa_for_all_uarchs(data)

        ressources = []
        latencies = []
        points_meta = []   # full provenance per point

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    if archgroup.norm_ressource is not None:
                        ressources.append(archgroup.norm_ressource)

                        #overall mean for this [tpg][uarch][isa] taking each seed into account (no stddev used)
                        seed_means = [s.mean for s in archgroup.seeds]
                        latencies.append(mean(seed_means)) 
                        points_meta.append({
                            "tpg": tpg,
                            "uarch": uarch,
                            "isa": isa,
                            "iset": archgroup.iset,
                            "dtype": archgroup.dtype,
                        })

        X = np.array(ressources)
        Y = np.array(latencies)

             
        categories = [(m["uarch"], m["isa"]) for m in points_meta]
        unique_cats = list(dict.fromkeys(categories))

        if len(unique_cats) > 20:
            cmaps = [
                plt.get_cmap("tab20"),
                plt.get_cmap("tab20b"),
                plt.get_cmap("tab20c"),
            ]

            def get_qualitative_colors(n):
                colors = []
                for cmap in cmaps:
                    for i in range(cmap.N):
                        colors.append(cmap(i))
                        if len(colors) >= n:
                            return colors
                raise ValueError("Not enough colors")

            colors = get_qualitative_colors(20)

            color_map = {
                cat: colors[i]
                for i, cat in enumerate(unique_cats)
            }
        else:
            cmap = plt.get_cmap('tab20')
        color_map = {
                cat: cmap(i % cmap.N)
                for i, cat in enumerate(unique_cats)
            }

        colors = np.array([(*color_map[c][:3], 0.6) for c in categories])

        # Assign markers based on microarchitecture prefixes
        marker_map = {
            'e2_em': '^',   # triangle up
            'e2_im': 'o',   # circle
            'e4_em': '*',   # star
            'e4_im': 's',   # square
        }

        def get_marker(uarch: str):
            for prefix, marker in marker_map.items():
                if uarch.startswith(prefix):
                    return marker
            return 'o'  # default marker

        
        
        # Combine X and Y into a cost matrix
        costs = np.column_stack((X, Y))

        # Find Pareto-efficient points
        pareto_mask = self.is_pareto_efficient(costs)
        pareto_X = X[pareto_mask]
        pareto_Y = Y[pareto_mask]

        pareto_points = [
            meta
            for meta, is_pareto in zip(points_meta, pareto_mask)
            if is_pareto
        ]

        pareto_colors = [ color_map[c] for c, is_pareto in zip(categories, pareto_mask) if is_pareto ]

        # Sort Pareto points for proper line plotting
        sort_idx = np.argsort(pareto_X)
        pareto_X_sorted = pareto_X[sort_idx]
        pareto_Y_sorted = pareto_Y[sort_idx]

        # Create the plot
        plt.figure(figsize=(10, 7))

        markers = [get_marker(meta["uarch"]) for meta in points_meta]

        for x, y, c, m, is_p in zip(X, Y, colors, markers, pareto_mask):
            if not is_p:
                plt.scatter(x, y, c=[c], marker=m, alpha=0.6, s=50, label='_nolegend_', zorder=1)


         # Plot Pareto front points
        pareto_colors = [
            color_map[c]
            for c, is_pareto in zip(categories, pareto_mask)
            if is_pareto
        ]
        
        pareto_markers = [get_marker(meta["uarch"]) for meta, is_p in zip(points_meta, pareto_mask) if is_p]

        for x, y, c, m in zip(pareto_X, pareto_Y, pareto_colors, pareto_markers):
            plt.scatter(x, y, c=[c], marker=m, s=100, edgecolors=[c], linewidth=1.5, label='_nolegend_', zorder=3)


        # Connect Pareto front points with a line
        plt.plot(pareto_X_sorted, pareto_Y_sorted, 'r--', linewidth=2, alpha=0.7, zorder=2)

        print("pareto ressource ", pareto_X_sorted)
        print("pareto latencies ", pareto_Y_sorted)

        # Styling
        plt.xlabel('Ressources (X)', fontsize=12, fontweight='bold')
        plt.ylabel('Latency (Y)', fontsize=12, fontweight='bold')
        plt.title('Pareto Front Visualization', fontsize=14, fontweight='bold')
        plt.legend(fontsize=11, loc='upper right')
        plt.grid(True, alpha=0.3, linestyle='--')
        plt.tight_layout()

        # Add arrow annotations to show the improvement direction
        # plt.annotate('', xy=(1, 1), xytext=(3, 3), arrowprops=dict(arrowstyle='->', lw=2, color='green', alpha=0.6))
        # plt.text(2.5, 2.5, 'Better', fontsize=10, color='green', fontweight='bold', ha='center')

        plt.yscale('log')

        from matplotlib.lines import Line2D

        uarch_custom_order = [
            "e2_em0d1",
            "e2_em1d1",
            "e2_em2d1",
            "e2_em3d1",
            
            "e2_im0d1",
            "e2_im1d1",
            "e2_im2d1",
            "e2_im3d1",
            
            "e4_em0d0",
            "e4_em4d0",
            "e4_em4d2",

            "e4_im0d0",
            "e4_im4d0",
            "e4_im4d2",

            "e4_im5d2",
            "e4_im5d2_pulp",
            "e4_im5d2_fpu",
            "e4_im5d2_pulp_fpu",
        ]

        # Map each string to its order index
        uarch_order_index = {s: i for i, s in enumerate(uarch_custom_order)}    

        def legend_sort_key(cat):
            uarch, isa = cat
            return (
                uarch_order_index.get(uarch, len(uarch_custom_order)),
                isa  
            )

        # Sort categories
        sorted_cats = sorted(unique_cats, key=legend_sort_key)        

        uarch_isa_elements = [
            Line2D(
                [0], [0],
                marker=get_marker(uarch),
                linestyle='',
                markerfacecolor=color_map[(uarch, isa)],
                markeredgewidth=0,      # no outline
                label=f"{uarch}, {isa}",
                markersize=9,
            )
            for (uarch, isa) in sorted_cats
        ]

        pareto_iset_dtype_groups = defaultdict(list)

        for meta in pareto_points:
            key = (meta["iset"], meta["dtype"])
            pareto_iset_dtype_groups[key].append((meta["uarch"], meta["isa"]))

        pareto_iset_dtype_elements = []
        
        for (iset, dtype), uarch_isa_list in pareto_iset_dtype_groups.items():
            for i, (uarch, isa) in enumerate(uarch_isa_list):
                pareto_iset_dtype_elements.append(
                    Line2D(
                        [0], [0],
                        marker='o',
                        linestyle='',
                        markerfacecolor=color_map[(uarch, isa)],
                        markeredgewidth=0,
                        markersize=9,
                        label=f'{iset} | {dtype}' 
                    )
                )

        uarch_header = Line2D(
            [], [], linestyle='none',
            label="uarch | isa"
        )

        pareto_header = Line2D(
            [], [], linestyle='none',
            label="Pareto-efficient iset | dtype"
        )


        legend_elements = (
            [uarch_header]
            + uarch_isa_elements
            + [Line2D([], [], linestyle='none', label="")]  # spacer
            + [pareto_header]
            + pareto_iset_dtype_elements
        )


        plt.legend(
            handles=legend_elements,
            fontsize=9,
            loc='best',
            frameon=True,
            handlelength=1.2,
            handletextpad=0.6
        )
        
        plt.show()

        # Print statistics
        print(f"Total points: {len(X)}")
        print(f"Pareto-efficient points: {np.sum(pareto_mask)}")
        print(f"Percentage on Pareto front: {100 * np.sum(pareto_mask) / len(X):.1f}%")


    def parse_tpgInfos(self, path_to_file: str):
        """
        Parse executioninfos.json to extract unique traceGroup entries
        based on their traceTeamIds. Used to calculate the TPG IPC. 
        """

        # Load the JSON file
        with open(path_to_file, "r") as f:
            data = json.load(f)

        # Result: keys = traceTeamIds, values = one representative traceGroup
        trace_groups = {}

        for node_id, entry in data.items():
            trace_team_ids = entry["traceTeamIds"]

            # If we haven't seen this traceTeamIds yet, store it
            if trace_team_ids not in trace_groups:
                trace_groups[trace_team_ids] = {
                    "traceTeamIds": trace_team_ids,
                    "nbEvaluatedPrograms": entry["nbEvaluatedPrograms"],
                    "nbEvaluatedTeams": entry["nbEvaluatedTeams"],
                    "nbExecutionForEachInstr": entry["nbExecutionForEachInstr"],
                    # optional: keep track of which original keys belong to this group
                    "sourceNodeIds": [node_id],
                }
            else:
                # Same traceTeamIds → same data, just record provenance if desired
                trace_groups[trace_team_ids]["sourceNodeIds"].append(node_id)

        #print(trace_groups)
        # trace_groups now contains the fully factored representation

        # compute nbInstr per trace group
        for trace_team_ids, group in trace_groups.items():
            nb_execution = group["nbExecutionForEachInstr"]
            total_nb_instr = sum(nb_execution.values())
            group["total_nb_instr"] = total_nb_instr
            #print(f"TraceTeamIds: {trace_team_ids}, nbEvaluatedPrograms: {group["nbEvaluatedPrograms"]}, Total nbInstr: {total_nb_instr}")

        # avg nbInstr per team, avg nbEvaluatedPrograms, avg nbEvaluatedTeams
        n_teams = len(trace_groups)
        if n_teams == 0:
            print("No trace groups found.")
            return
        total_nb_instr_all = sum(group["total_nb_instr"] for group in trace_groups.values())
        total_nb_evaluated_programs = sum(group["nbEvaluatedPrograms"] for group in trace_groups.values())
        total_nb_evaluated_teams = sum(group["nbEvaluatedTeams"] for group in trace_groups.values())
        avg_nb_instr = total_nb_instr_all / n_teams
        avg_nb_evaluated_programs = total_nb_evaluated_programs / n_teams
        avg_nb_evaluated_teams = total_nb_evaluated_teams / n_teams
        #print(f"Average nbInstr: {avg_nb_instr}")
        #print(f"Average nbEvaluatedPrograms: {avg_nb_evaluated_programs}")
        #print(f"Average nbEvaluatedTeams: {avg_nb_evaluated_teams}")

        return avg_nb_instr, avg_nb_evaluated_programs, avg_nb_evaluated_teams

    def import_tpg_nbInstr(self, data, nbInstr_json_files):
        """
        for each executionInfos:
            find the corresponding tpg canonical name
        for each executionInfos:
            associate the tpg name to a dict of trace_groups (parse_tpgInfos)
        for each executionInfos:
            find the corresponding place in the data dict using the 
            tpg canonical name 
        """

        for file in nbInstr_json_files:
            # find canonical tpg name 
            tpg_dir = file.parents[2]
            tpg_dir_name = tpg_dir.name
            (tpg, seed) = self.canonicalize_tpg_dir(tpg_dir_name)
            # print(tpg, seed)
            

        for file in nbInstr_json_files:
            (avg_nb_instr, avg_nb_evaluated_programs, avg_nb_evaluated_teams) = self.parse_tpgInfos(file)

        for tpg, uarch_map in data.items():
            for uarch, isa_map in uarch_map.items():
                for isa, archgroup in isa_map.items():
                    if archgroup.tpg_canonical == tpg:
                        archgroup.seeds[seed].avg_nb_instr = avg_nb_instr
                        archgroup.seeds[seed].avg_nb_evaluated_programs = avg_nb_evaluated_programs
                        archgroup.seeds[seed].avg_nb_evaluated_teams = avg_nb_evaluated_teams

    def plot_tpg_ipc_all_uarch_one_plot_each(self, data):
        """
        Plot IPC per TPG, with one figure per uarch.
        """
        from statistics import mean
        import matplotlib.pyplot as plt

        # Organize data by uarch
        uarch_tpg_ipc = {}

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                if uarch not in uarch_tpg_ipc:
                    uarch_tpg_ipc[uarch] = {"tpgs": [], "ipcs": []}

                for isa, archgroup in sorted(isa_map.items()):
                    # compute IPC for each seed and average
                    seed_ipcs = [
                        seed_obj.avg_nb_instr / seed_obj.mean
                        for seed_obj in archgroup.seeds
                        if seed_obj.avg_nb_instr is not None
                        and seed_obj.mean is not None
                        and seed_obj.mean > 0
                    ]
                    if seed_ipcs:
                        avg_ipc = mean(seed_ipcs)
                        uarch_tpg_ipc[uarch]["tpgs"].append(f"{archgroup.iset} {archgroup.dtype}")
                        uarch_tpg_ipc[uarch]["ipcs"].append(avg_ipc)

        # Plot one figure per uarch
        for uarch, vals in uarch_tpg_ipc.items():
            tpgs = vals["tpgs"]
            ipcs = vals["ipcs"]

            plt.figure(figsize=(10, 7))
            plt.bar(tpgs, ipcs, color='skyblue')
            plt.xlabel('TPG', fontsize=12, fontweight='bold')
            plt.ylabel('IPC', fontsize=12, fontweight='bold')
            plt.title(f'IPC per TPG on {uarch}', fontsize=14, fontweight='bold')
            plt.xticks(rotation=45, ha='right')
            plt.grid(axis='y', alpha=0.3, linestyle='--')

            # Give extra space for long x labels
            plt.subplots_adjust(bottom=0.35)

            plt.tight_layout()
            plt.show()

    def plot_tpg_ipc_across_uarchs_one_plot(self, data):
        """
        Plot IPC per TPG, all uarches on the same figure,
        using one color per uarch, ordered by iset then dtype (fixedpt before float).
        """
        from statistics import mean
        import matplotlib.pyplot as plt
        import numpy as np

        # --- custom iset order ---
        iset_custom_order = [
            "{*,/,>,-,+}",
            "{log,exp,*,/,>,-,+}",
            "{trig,*,/,>,-,+}",
            "{trig,log,exp,*,/,>,-,+}",
            "{log2,exp2,>,-,+}",
            "{log2,exp2,*,>,-,+}",
            "{log2,exp2,*,/,>,-,+}",
        ]
        iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}

        # Collect IPCs per uarch per TPG
        uarch_tpg_ipc = {}
        all_tpgs_set = set()  # use set first to avoid duplicates

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                if uarch not in uarch_tpg_ipc:
                    uarch_tpg_ipc[uarch] = {}

                for isa, archgroup in sorted(isa_map.items()):
                    tpg_label = f"{archgroup.iset} {archgroup.dtype}"
                    all_tpgs_set.add(tpg_label)

                    seed_ipcs = [
                        seed_obj.avg_nb_instr / seed_obj.mean
                        for seed_obj in archgroup.seeds
                        if seed_obj.avg_nb_instr is not None
                        and seed_obj.mean is not None
                        and seed_obj.mean > 0
                    ]

                    if seed_ipcs:
                        uarch_tpg_ipc[uarch][tpg_label] = mean(seed_ipcs)

        # Sort all_tpgs by dtype (fixedpt before float), then iset order
        def tpg_sort_key(tpg_label):
            iset, dtype = tpg_label.split(" ", 1)
            dtype_order = 0 if "fixedpt" in dtype.lower() else 1
            iset_index = iset_order_index.get(iset, 999)  # unknown isets go last
            return (dtype_order, iset_index, iset)

        all_tpgs = sorted(all_tpgs_set, key=tpg_sort_key)

        # --- Filter uarches to exclude "_em" ---
        filtered_uarches = [
            (uarch, tpg_ipcs)
            for uarch, tpg_ipcs in sorted(uarch_tpg_ipc.items())
            if "_em" not in uarch
        ]

        num_uarches = len(filtered_uarches)
        bar_width = 0.95 / num_uarches

        # Plot
        fig, ax = plt.subplots(figsize=(18, 10))
        x = np.arange(len(all_tpgs))

        for i, (uarch, tpg_ipcs) in enumerate(filtered_uarches):
            ipcs = [tpg_ipcs.get(tpg, 0) for tpg in all_tpgs]
            ax.bar(
                x + i * bar_width,
                ipcs,
                width=bar_width,
                label=uarch
            )

        ax.set_xlabel("TPG", fontsize=14, fontweight="bold")
        ax.set_ylabel("IPC", fontsize=14, fontweight="bold")
        ax.set_title("IPC per TPG across uarches", fontsize=16, fontweight="bold")

        ax.set_xticks(x + bar_width * (num_uarches - 1) / 2)
        ax.set_xticklabels(all_tpgs, rotation=45, ha="right")

        ax.grid(axis="y", alpha=0.3, linestyle="--")
        ax.legend(title="uarch", fontsize=12, title_fontsize=13)

        plt.subplots_adjust(bottom=0.35)
        plt.tight_layout()
        plt.show()


    def plot_tpg_ipc_all_uarch_averaged(self, data):
        """
        Plot a single figure: average IPC per TPG across all uarchs that implement it.
        """
        from statistics import mean
        import matplotlib.pyplot as plt
        from collections import defaultdict

        # Step 1: Collect IPCs per TPG per uarch
        tpg_uarch_ipc = defaultdict(list)

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    # compute IPC for each seed
                    seed_ipcs = [
                        seed_obj.avg_nb_instr / seed_obj.mean
                        for seed_obj in archgroup.seeds
                        if seed_obj.avg_nb_instr is not None
                        and seed_obj.mean is not None
                        and seed_obj.mean > 0
                    ]
                    if seed_ipcs:
                        avg_ipc = mean(seed_ipcs)
                        tpg_uarch_ipc[archgroup.iset + " " + archgroup.dtype].append(avg_ipc)

        # Step 2: Average IPC per TPG over uarchs implementing it
        tpg_avg_ipc = {}
        for tpg, ipc_list in tpg_uarch_ipc.items():
            tpg_avg_ipc[tpg] = sum(ipc_list) / len(ipc_list)

        # Step 3: Prepare for plotting
        tpgs = sorted(tpg_avg_ipc.keys())
        ipcs = [tpg_avg_ipc[tpg] for tpg in tpgs]

        # Step 4: Plot
        plt.figure(figsize=(12, 6))
        plt.bar(tpgs, ipcs, color='skyblue')
        plt.xlabel('TPG', fontsize=12, fontweight='bold')
        plt.ylabel('Average IPC', fontsize=12, fontweight='bold')
        plt.title('Average IPC per TPG across all uarchs', fontsize=14, fontweight='bold')
        plt.xticks(rotation=45, ha='right')
        plt.grid(axis='y', alpha=0.3, linestyle='--')
        plt.subplots_adjust(bottom=0.35)
        plt.tight_layout()
        plt.show()


    def plot_pareto_front_dist_lat_ress_3d(self, data):
        """
        3D Pareto front across:
        - Distance to objective (minimize)
        - Latency (minimize)
        - Resources (minimize)

        Color-coded by microarchitecture (uarch)
        Marker-coded by (iset | dtype)

        Only Pareto-dominant solutions are displayed.
        """

        from statistics import mean
        from collections import defaultdict
        import numpy as np
        import matplotlib.pyplot as plt
        from mpl_toolkits.mplot3d import Axes3D
        from matplotlib.lines import Line2D
        from itertools import cycle

        # ---------------------------------------------------------------
        # Pre-filter ISA
        # ---------------------------------------------------------------
        data = self.select_best_isa_for_all_uarchs(data)

        # ---------------------------------------------------------------
        # Custom legend orders
        # ---------------------------------------------------------------
        iset_custom_order = [
            "{*,/,>,-,+}",
            "{log,exp,*,/,>,-,+}",
            "{trig,*,/,>,-,+}",
            "{trig,log,exp,*,/,>,-,+}",
            "{log2,exp2,>,-,+}",
            "{log2,exp2,*,>,-,+}",
            "{log2,exp2,*,/,>,-,+}",
        ]
        iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}

        # ------------------------------------------------------------------
        # Collect data
        # ------------------------------------------------------------------
        dists = []
        latencies = []
        ressources = []
        points_meta = []

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    if (
                        archgroup.accuracy is not None
                        and archgroup.norm_ressource is not None
                        and archgroup.seeds
                    ):
                        dists.append(archgroup.accuracy)
                        latencies.append(mean(s.mean for s in archgroup.seeds))
                        ressources.append(archgroup.norm_ressource)

                        points_meta.append({
                            "tpg": tpg,
                            "uarch": uarch,
                            "isa": isa,
                            "iset": archgroup.iset,
                            "dtype": archgroup.dtype,
                        })

        X = np.array(dists)
        Y = np.array(latencies)
        Z = np.array(ressources)

        # ------------------------------------------------------------------
        # Pareto computation (all objectives minimized)
        # ------------------------------------------------------------------
        costs = np.column_stack((X, Y, Z))
        pareto_mask = self.is_pareto_efficient(costs)

        pareto_meta = [
            meta for meta, is_p in zip(points_meta, pareto_mask) if is_p
        ]

        # ------------------------------------------------------------------
        # Build Pareto-only semantic domains
        # ------------------------------------------------------------------

        # Unique Pareto microarchitectures (for colors)
        pareto_uarches = list(dict.fromkeys(
            meta["uarch"] for meta in pareto_meta
        ))

        # Unique Pareto (iset | dtype) pairs (for markers)
        pareto_iset_dtype = sorted(
            {(m["iset"], m["dtype"]) for m in pareto_meta},
            key=lambda t: (
                iset_order_index.get(t[0], len(iset_custom_order)),
                t[1],
            )
        )

        # ------------------------------------------------------------------
        # Color map: microarchitecture → color (Pareto only)
        # ------------------------------------------------------------------
        cmap = plt.get_cmap("tab20")

        color_map = {
            uarch: cmap(i % cmap.N)
            for i, uarch in enumerate(pareto_uarches)
        }

        # ------------------------------------------------------------------
        # Marker map: (iset | dtype) → marker (Pareto only)
        # ------------------------------------------------------------------
        marker_cycle = cycle([
            'X',  # x filled
            '^',  # triangle up
            '*',  # star
            's',  # square
            'v',  # triangle down
            'D',  # diamond
            'P',  # plus filled
            'o',  # circle
        ])

        marker_map = {
            key: next(marker_cycle)
            for key in pareto_iset_dtype
        }

        # ------------------------------------------------------------------
        # Plot
        # ------------------------------------------------------------------
        fig = plt.figure(figsize=(14, 10))
        ax = fig.add_subplot(111, projection="3d")

        # Pareto-dominant points only
        for x, y, z, meta in zip(
            X[pareto_mask],
            Y[pareto_mask],
            Z[pareto_mask],
            pareto_meta,
        ):
            ax.scatter(
                x, y, z,
                c=[color_map[meta["uarch"]]],
                marker=marker_map[(meta["iset"], meta["dtype"])],
                s=130,
                edgecolors='k',
                linewidth=0.6,
                depthshade=False,
                zorder=10,
            )

        # ------------------------------------------------------------------
        # Styling
        # ------------------------------------------------------------------
        ax.set_xlabel("Distance to objective ↓", fontsize=12, fontweight="bold")
        ax.set_ylabel("Latency ↓", fontsize=12, fontweight="bold")
        ax.set_zlabel("Resources ↓", fontsize=12, fontweight="bold")

        ax.set_title(
            "3D Pareto Front: Distance × Latency × Resources",
            fontsize=14,
            fontweight="bold",
        )

        ax.grid(True, alpha=0.3)

        # ------------------------------------------------------------------
        # Legend
        # ------------------------------------------------------------------

        # Iset | dtype (marker legend)
        iset_dtype_header = Line2D([], [], linestyle='none', label="Iset | dtype")

        iset_dtype_elements = [
            Line2D(
                [0], [0],
                marker=marker_map[(iset, dtype)],
                linestyle='',
                color='black',
                markersize=9,
                label=f"{iset} | {dtype}",
            )
            for (iset, dtype) in pareto_iset_dtype
        ]

        # Microarchitecture (color legend)
        uarch_header = Line2D([], [], linestyle='none', label="Microarchitecture")

        uarch_elements = [
            Line2D(
                [0], [0],
                marker='o',
                linestyle='',
                markerfacecolor=color_map[uarch],
                markeredgewidth=0,
                markersize=9,
                label=uarch,
            )
            for uarch in pareto_uarches
        ]

        legend_elements = (
            [iset_dtype_header]
            + iset_dtype_elements
            + [Line2D([], [], linestyle='none', label="")]
            + [uarch_header]
            + uarch_elements
        )

        ax.legend(
            handles=legend_elements,
            fontsize=9,
            loc="upper left",
            bbox_to_anchor=(1.02, 1.0),
            frameon=True,
            handlelength=1.2,
            handletextpad=0.6,
        )

        plt.tight_layout()
        plt.show()

        # ------------------------------------------------------------------
        # Stats
        # ------------------------------------------------------------------
        print(f"Total points: {len(X)}")
        print(f"Pareto-efficient points: {np.sum(pareto_mask)}")
        print(f"Percentage on Pareto front: {100 * np.sum(pareto_mask) / len(X):.1f}%")

    def plot_pareto_front_ress_lat_projection(self, data):

        from statistics import mean
        from itertools import cycle
        from collections import defaultdict
        import numpy as np
        import matplotlib.pyplot as plt
        from matplotlib.lines import Line2D

        # ---------------------------------------------------------------
        # Custom legend orders
        # ---------------------------------------------------------------
        iset_custom_order = [
            "{*,/,>,-,+}",
            "{log,exp,*,/,>,-,+}",
            "{trig,*,/,>,-,+}",
            "{trig,log,exp,*,/,>,-,+}",
            "{log2,exp2,>,-,+}",
            "{log2,exp2,*,>,-,+}",
            "{log2,exp2,*,/,>,-,+}",
        ]
        iset_order_index = {s: i for i, s in enumerate(iset_custom_order)}

        uarch_custom_order = [
            "e2_em0d1", "e2_em1d1", "e2_em2d1", "e2_em3d1",
            "e2_im0d1", "e2_im1d1", "e2_im2d1", "e2_im3d1",
            "e4_em0d0", "e4_em4d0", "e4_em4d2",
            "e4_im0d0", "e4_im4d0", "e4_im4d2",
            "e4_im5d2", "e4_im5d2_pulp",
            "e4_im5d2_fpu", "e4_im5d2_pulp_fpu",
        ]
        uarch_order_index = {s: i for i, s in enumerate(uarch_custom_order)}

        # ---------------------------------------------------------------
        # Pre-filter ISA
        # ---------------------------------------------------------------
        data = self.select_best_isa_for_all_uarchs(data)

        # ---------------------------------------------------------------
        # Collect data
        # ---------------------------------------------------------------
        dists, latencies, ressources = [], [], []
        points_meta = []

        for tpg, uarch_map in sorted(data.items()):
            for uarch, isa_map in sorted(uarch_map.items()):
                for isa, archgroup in sorted(isa_map.items()):
                    if (
                        archgroup.accuracy is not None
                        and archgroup.norm_ressource is not None
                        and archgroup.seeds
                    ):
                        dists.append(archgroup.accuracy)
                        latencies.append(mean(s.mean for s in archgroup.seeds))
                        ressources.append(archgroup.norm_ressource)

                        points_meta.append({
                            "uarch": uarch,
                            "iset": archgroup.iset,
                            "dtype": archgroup.dtype,
                            "accuracy": archgroup.accuracy
                        })

        Xd = np.array(dists)
        Yl = np.array(latencies)
        Zr = np.array(ressources)

        # ---------------------------------------------------------------
        # 3D Pareto (distance, latency, resources)
        # ---------------------------------------------------------------
        pareto_3d = self.is_pareto_efficient(
            np.column_stack((Xd, Yl, Zr))
        )

        pareto_lat = Yl[pareto_3d]
        pareto_res = Zr[pareto_3d]
        pareto_meta = [m for m, p in zip(points_meta, pareto_3d) if p]

        # ---------------------------------------------------------------
        # Semantic domains (Pareto only)
        # ---------------------------------------------------------------
        pareto_uarches = sorted(
            {m["uarch"] for m in pareto_meta},
            key=lambda u: uarch_order_index.get(u, len(uarch_custom_order))
        )

        pareto_tpgs = sorted(
            {(m["iset"], m["dtype"]) for m in pareto_meta},
            key=lambda t: (
                iset_order_index.get(t[0], len(iset_custom_order)),
                t[1],
            )
        )

        # ---------------------------------------------------------------
        # Color & marker maps
        # ---------------------------------------------------------------
        cmap = plt.get_cmap("tab20")
        color_map = {
            uarch: cmap(i % cmap.N)
            for i, uarch in enumerate(pareto_uarches)
        }

        marker_cycle = cycle([
            'X',  # x filled
            '^',  # triangle up
            '*',  # star
            's',  # square
            'v',  # triangle down
            'D',  # diamond
            'P',  # plus filled
            'o',  # circle
        ])

        marker_map = {tpg: next(marker_cycle) for tpg in pareto_tpgs}

        # ---------------------------------------------------------------
        # Group Pareto points by TPG family
        # ---------------------------------------------------------------
        tpg_groups = defaultdict(list)
        for res, lat, meta in zip(pareto_res, pareto_lat, pareto_meta):
            tpg_groups[(meta["iset"], meta["dtype"])].append((res, lat, meta))


        # ---------------------------------------------------------------
        # Plot
        # ---------------------------------------------------------------
        plt.figure(figsize=(18.5, 9))

        # --- thin per-TPG Pareto envelopes ---
        for tpg, pts in tpg_groups.items():
            if len(pts) < 2:
                continue

            # extract arrays
            res = np.array([p[0] for p in pts])
            lat = np.array([p[1] for p in pts])

            # 2D Pareto for this TPG family
            pareto_mask = self.is_pareto_efficient(
                np.column_stack((res, lat))
            )

            res_p = res[pareto_mask]
            lat_p = lat[pareto_mask]

            if len(res_p) < 2:
                continue

            # sort by resources
            idx = np.argsort(res_p)
            res_p = res_p[idx]
            lat_p = lat_p[idx]

            # build staircase
            step_res = [res_p[0]]
            step_lat = [lat_p[0]]

            for i in range(1, len(res_p)):
                # horizontal extension
                step_res.append(res_p[i])
                step_lat.append(step_lat[-1])

                # vertical drop
                step_res.append(res_p[i])
                step_lat.append(lat_p[i])

            plt.plot(
                step_res,
                step_lat,
                color="gray",
                linewidth=0.8,
                alpha=0.8,
                zorder=1,
            )

        # --- annotate TPG accuracy for all families ---
        for tpg, pts in tpg_groups.items():
            # extract arrays
            res = np.array([p[0] for p in pts])
            lat = np.array([p[1] for p in pts])
            meta_list = [p[2] for p in pts]

            # select the "best" point (minimal resources)
            best_idx = np.argmin(res)
            best_meta = meta_list[best_idx]

            # if lat is around 1e5, augment the offset
            offset = 0
            if lat[best_idx] > 1e5:
                offset = 8000
            elif lat[best_idx] > 1e4:
                offset = 1500
            elif lat[best_idx] > 1e3:
                offset = 500
            elif lat[best_idx] > 1e2:
                offset = 50
            
            # make this bigger
            plt.text(
                res[best_idx] - 2.7,
                lat[best_idx] + offset,
                f"dist to obj: {best_meta['accuracy']:.3f}",
                fontsize=10,
                # make bold
                #fontweight="bold",
                color="blue",
                ha="left",
                va="bottom",
                alpha=1.0,
                zorder=5
            )


        # --- scatter points ---
        for res, lat, meta in zip(pareto_res, pareto_lat, pareto_meta):
            plt.scatter(
                res, lat,
                c=[color_map[meta["uarch"]]],
                marker=marker_map[(meta["iset"], meta["dtype"])],
                s=160,
                edgecolors='k',
                linewidth=0.8,
                zorder=3,
            )

        # ---------------------------------------------------------------
        # 2D Pareto envelope (latency × resources ONLY)
        # ---------------------------------------------------------------
        costs_2d = np.column_stack((pareto_res, pareto_lat))
        pareto_2d = self.is_pareto_efficient(costs_2d)

        env_res = pareto_res[pareto_2d]
        env_lat = pareto_lat[pareto_2d]

        env_idx = np.argsort(env_res)
       

        # ---------------------------------------------------------------
        # Background (dominated) points — thin gray
        # ---------------------------------------------------------------
        non_pareto_mask = ~pareto_3d

        plt.scatter(
            Zr[non_pareto_mask],   # resources
            Yl[non_pareto_mask],   # latency
            c="gray",
            s=40,
            alpha=0.25,
            linewidths=0,
            zorder=0,
        )

        # ---------------------------------------------------------------
        # Styling
        # ---------------------------------------------------------------
        plt.xlabel("Resources ↓", fontsize=12, fontweight="bold")
        plt.ylabel("Latency ↓", fontsize=12, fontweight="bold")
        plt.yscale("log")
        plt.grid(True, alpha=0.3, linestyle="--")
        #plt.title("Projected Pareto Front (3D dominance → 2D view)",fontsize=14,fontweight="bold",)

        # ---------------------------------------------------------------
        # Legend
        # ---------------------------------------------------------------
        tpg_header = Line2D([], [], linestyle='none', label="TPG (ISGP | data type)")
        tpg_elements = [
            Line2D(
                [0], [0],
                marker=marker_map[tpg],
                linestyle='',
                color='black',
                markersize=10,
                label=f"{tpg[0]} | {tpg[1]}",
            )
            for tpg in pareto_tpgs
        ]

        uarch_header = Line2D([], [], linestyle='none', label="Microarchitecture")
        uarch_elements = [
            Line2D(
                [0], [0],
                marker='o',
                linestyle='',
                markerfacecolor=color_map[uarch],
                markeredgewidth=0,
                markersize=10,
                label=uarch,
            )
            for uarch in pareto_uarches
        ]

        plt.legend(
            handles=(
                [tpg_header]
                + tpg_elements
                + [Line2D([], [], linestyle='none', label="")]
                + [uarch_header]
                + uarch_elements
            ),
            fontsize=9,
            loc="best",
            frameon=True,
        )

        #plt.tight_layout()

        # ---- export to PDF ----
        plt.savefig(
            "pareto_front_ress_lat_projection.pdf",
            format="pdf",
            bbox_inches="tight"
        )


        plt.show()
    
# -----------------------------
# CLI / main
# -----------------------------

def main(argv: Optional[List[str]]=None):
    agg = TPGResultsAggregator("tpg_expe", "results_out")

    json_config_files = agg.find_json_files("configs")
    json_result_files = agg.find_json_files("results")
    csv_accuracies_path = "tpg_expe/parsed_results/results.csv"
    uarchs_ressources_path = "tpg_expe/uarch_results/uarchs_ressources.pkl"
        
    data = agg.build_hierarchical_data(json_result_files)

    df = agg.aggregate_data(data)
    df_avg = agg.aggregate_averaged_data(data)

    #agg.save_csv(df, "aggregated_tpg_results.csv")
    #agg.save_csv(df_avg, "aggregated_averaged_tpg_results.csv")

    agg.plot_x_axis_uarchs_y_axis_one_tpg(data)
    agg.plot_x_axis_tpgs_y_axis_one_uarch(data)

    #agg.plot_x_axis_tpgs_y_axis_all_uarchs(data)
    #agg.plot_x_axis_tpgs_y_axis_all_uarchs_min_max(data)

    # agg.plot_x_axis_uarchs_y_axis_all_tpgs(data)

    agg.import_tpg_accuracies(data, csv_accuracies_path)
    #agg.plot_pareto_front_acc_lat(data)

    agg.import_uarch_ressources(data, uarchs_ressources_path)
    agg.assign_normalized_ressources(data)
    #agg.plot_pareto_front_ress_lat(data)

    


    # Building IPC analysis 

    # 1. get a list of path towards nbInstr json files 
    nbInstr_json_files = agg.find_nbInstr_json_files()

    # 2. Enrich the data dict with IPC informations 
    # nbInstr infos are tpg dependent. 
    # data[tpg][uarch][isa] -> will not vary for uarch and isa
    agg.import_tpg_nbInstr(data, nbInstr_json_files)

    # 3. plot 
    # agg.plot_tpg_ipc_all_uarch_one_plot_each(data)
    # agg.plot_tpg_ipc_all_uarch_averaged(data)
    #agg.plot_tpg_ipc_across_uarchs_one_plot(data)

    # 4. 3D pareto front acc, lat, ress
    #agg.plot_pareto_front_dist_lat_ress_3d(data)
    agg.plot_pareto_front_ress_lat_projection(data)




    # Combined plot ?? Not sure what this is 
    # combined_png = out_dir / "combined_latency_by_tpg.png"
    # agg.plot_combined(df, combined_png)
    # print(f"INFO: saved combined plot to {combined_png}")

    # agg.plot_per_tpg_bar(df, out_dir, max_plots=args.max_per_tpg)
    # print(f"INFO: saved up to {args.max_per_tpg} per-TPG plots in {out_dir}")



    

    # quick summary printed
    n_tpgs = df["iset"].nunique() if not df.empty else 0
    n_archs = df["uarch"].nunique() if not df.empty else 0
    #for isa in df["isa"].unique():
    #    print(isa)
    print(f"SUMMARY: TPGs={n_tpgs}, architectures={n_archs}, total_rows={len(df)}")

if __name__ == "__main__":
    main()
