#!/usr/bin/env python3
import argparse
import shutil
import json
from pathlib import Path

# --------------------------------------------------------------
# DETERMINE COMPILER BASED ON ISA
# --------------------------------------------------------------
def determine_compiler(isa: str) -> str:
    """
    Return the compiler path based on the ISA:
    - If 'xpulp' in ISA -> /opt/tools/corev
    - Otherwise -> /opt/tools/riscv
    """
    if "xpulp" in isa.lower():
        return "/opt/tools/corev"
    return "/opt/tools/riscv"


# --------------------------------------------------------------
# FUNCTION TO EXPAND ISA ARGUMENTS
# (c) → c AND non-c
# --------------------------------------------------------------
def expand_isa(isa):
    """
    Expand RISC-V compressed ISA `(c)` correctly:
    - rv32im(c)          -> rv32im, rv32imc
    - rv32im(c)_zicsr    -> rv32im_zicsr, rv32imc_zicsr
    """
    if "(c)" not in isa:
        return [isa]

    # Split at '(c)' into base and remainder
    parts = isa.split("(c)")
    base = parts[0]  # 'rv32im'
    suffix = "".join(parts[1:])  # everything after '(c)', e.g., '_zicsr'

    return [base + suffix, base + "c" + suffix]


# --------------------------------------------------------------
# MICROARCHITECTURES 
# Each entry: uarch → (isa, abi)
# --------------------------------------------------------------
UARCH_CONFIGS_RAW = {
    "cv32e20_im0": ("rv32i(c)_zicsr", "ilp32"),
    "cv32e20_im1": ("rv32im(c)_zicsr", "ilp32"),
    "cv32e20_im2": ("rv32im(c)_zicsr", "ilp32"),
    "cv32e20_im3": ("rv32im(c)_zicsr", "ilp32"),

    "cv32e20_em0": ("rv32e(c)_zicsr", "ilp32e"),
    "cv32e20_em1": ("rv32em(c)_zicsr", "ilp32e"),
    "cv32e20_em2": ("rv32em(c)_zicsr", "ilp32e"),
    "cv32e20_em3": ("rv32em(c)_zicsr", "ilp32e"),

    "cv32e40x_im0": ("rv32i(c)_zicsr", "ilp32"),
    "cv32e40x_im1": ("rv32i(c)_zicsr_zmmul", "ilp32"),
    "cv32e40x_im2": ("rv32im(c)_zicsr", "ilp32"),

    "cv32e40x_em0": ("rv32e(c)_zicsr", "ilp32e"),
    "cv32e40x_em1": ("rv32e(c)_zicsr_zmmul", "ilp32e"),
    "cv32e40x_em2": ("rv32em(c)_zicsr", "ilp32e"),

    "cv32e40px": ("rv32im(c)_zicsr", "ilp32"),
    "cv32e40px_fpu": ("rv32imf(c)_zicsr", "ilp32f"),
    "cv32e40px_corev_pulp": ("rv32im(c)_zicsr_xpulp", "ilp32f"),
    "cv32e40px_corev_pulp_fpu": ("rv32imf(c)_zicsr_xpulp", "ilp32f"),

    "cv32e40p": ("rv32im(c)_zicsr", "ilp32"),
    "cv32e40p_corev_pulp": ("rv32im(c)_zicsr_xpulp", "ilp32"),
}


# --------------------------------------------------------------
# FPU RULE: derived from microarchitecture name
# --------------------------------------------------------------
def microarch_has_fpu(uarch_name: str):
    return "fpu" in uarch_name.lower()


# --------------------------------------------------------------
# dtype detection from tpg folder name
# --------------------------------------------------------------
def infer_dtype(folder_name):
    if "instrType-float" in folder_name:
        return "float"
    if "instrType-double" in folder_name:
        return "double"
    if "instrType-fixedpt" in folder_name:
        return "fixedpt"
    raise ValueError(f"Cannot detect dtype from folder name: {folder_name}")


# --------------------------------------------------------------
# Validity rules based on dtype and uarch FPU
# --------------------------------------------------------------
def is_valid_combination(dtype, uarch_has_fpu):
    if dtype in ("fixedpt", "double") and microarch_has_fpu(uarch_has_fpu):
        return False
    return True


# --------------------------------------------------------------
# Main generator
# --------------------------------------------------------------
def generate(tpg_folder):
    tpg_folder = Path(tpg_folder)
    outdir = tpg_folder / "inference" / "configs"
    outdir.mkdir(exist_ok=True, parents=True)
    outdir_results = tpg_folder / "inference" / "results"
    outdir_results.mkdir(exist_ok=True, parents=True)
    outdir_overlays = tpg_folder / "inference" / "overlays"
    outdir_overlays.mkdir(exist_ok=True, parents=True)
    outdir_overlays = tpg_folder / "inference" / "tpg_inference_expe"
    outdir_overlays.mkdir(exist_ok=True, parents=True)

    dtype = infer_dtype(tpg_folder.name)

    for uarch, (isa_raw, abi) in UARCH_CONFIGS_RAW.items():

        if not is_valid_combination(dtype, uarch):
            print(f"[SKIP] {tpg_folder.name} on {uarch} (dtype={dtype})")
            continue

        expanded_isas = expand_isa(isa_raw)

        for isa in expanded_isas:
            compiler = determine_compiler(isa)

            filename = f"{uarch}_{isa}_{abi}_{dtype}.json"
            filepath = outdir / filename

            # JSON content
            config = {
                "tpg": tpg_folder.name,
                "uarch": uarch,
                "isa": isa,
                "abi": abi,
                "dtype": dtype,
                "compiler": compiler
            }

            with open(filepath, "w") as f:
                json.dump(config, f, indent=4)

            print(f"[OK] Created {filename}")

# --------------------------------------------------------------
# CLI
# --------------------------------------------------------------
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--tpg_folder", required=True)
    args = parser.parse_args()
    generate(args.tpg_folder)