#!/usr/bin/env python3
import argparse
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
        return "/opt/tools/corev/corev-openhw-gcc-ubuntu2204-20240530"
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
# XPULP REPLACEMENT FUNCTION 
# --------------------------------------------------------------
def replace_xpulp_extensions(isa: str) -> str:
    """
    Replace '_xpulp' with:
    _xcvalu_xcvbi_xcvbitmanip_xcvhwlp_xcvmac_xcvmem_xcvsimd
    """
    XPULP_EXT = "_xcvalu_xcvbi_xcvbitmanip_xcvhwlp_xcvmac_xcvmem_xcvsimd"

    if "_xpulp" in isa:
        return isa.replace("_xpulp", XPULP_EXT)

    return isa


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
    "cv32e40x_im1": ("rv32im(c)_zicsr", "ilp32"),
    "cv32e40x_im1_zba_zbb": ("rv32im(c)_zicsr_zba_zbb", "ilp32"),
    "cv32e40x_im2": ("rv32i(c)_zicsr_zmmul", "ilp32"),
    "cv32e40x_im2_zba_zbb": ("rv32i(c)_zicsr_zmmul_zba_zbb", "ilp32"),
    
    "cv32e40x_em0": ("rv32e(c)_zicsr", "ilp32e"),
    "cv32e40x_em1": ("rv32em(c)_zicsr", "ilp32e"),
    "cv32e40x_em2": ("rv32e(c)_zicsr_zmmul", "ilp32e"),

    "cv32e40px": ("rv32im(c)_zicsr", "ilp32"),
    "cv32e40px_fpu": ("rv32imf(c)_zicsr", "ilp32f"),
    "cv32e40px_corev_pulp": ("rv32im(c)_zicsr_xpulp", "ilp32"),
    "cv32e40px_corev_pulp_fpu": ("rv32imf(c)_zicsr_xpulp", "ilp32f"),

    #"cv32e40p": ("rv32im(c)_zicsr", "ilp32"),
    #"cv32e40p_corev_pulp": ("rv32im(c)_zicsr_xpulp", "ilp32"),
}


# --------------------------------------------------------------
# FPU / DIV RULES: derived from microarchitecture name
# --------------------------------------------------------------
def microarch_has_fpu(uarch_name: str):
    return "fpu" in uarch_name.lower()

def microarch_has_div(uarch_name: str):
    if uarch_name in ("cv32e20_im1", "cv32e20_im2", "cv32e20_im3", 
                    "cv32e20_em1", "cv32e20_em2", "cv32e20_em3",
                    "cv32e40x_im1", "cv32e40x_im1_zba_zbb",
                    "cv32e40x_em1", "cv32e40x_em1_zba_zbb",
                    "cv32e40px", "cv32e40px_fpu",
                    "cv32e40px_corev_pulp", "cv32e40px_corev_pulp_fpu"):
        return True
    return False

# --------------------------------------------------------------
# dtype / iset detection from tpg folder name
# --------------------------------------------------------------
def infer_dtype(folder_name):
    if "instrType-float" in folder_name:
        return "float"
    if "instrType-double" in folder_name:
        return "double"
    if "instrType-fixedpt" in folder_name:
        return "fixedpt"
    raise ValueError(f"Cannot detect dtype from folder name: {folder_name}")

def infer_iset(folder_name):
    # useInstrTrig-False_useInstrLogExp-False_useInstrExpensiveArithmetic-True_useInstrComparison-True
    # useInstrTrig-False_useInstrLogExp-False_useInstrLog2Exp2-True_useInstrZmmul-False_useInstrExpensiveArithmetic-False_useInstrComparison-True
    iset = ""
    if "useInstrTrig-True" in folder_name:
        iset += "sin,cos,tan,"
    if "useInstrLogExp-True" in folder_name:
        iset += "log,exp,"
    if "useInstrLog2Exp2-True" in folder_name:
        iset += "log2,exp2,"
    if "useInstrZmmul-True" in folder_name:
        iset += "zmmul,"
    if "useInstrExpensiveArithmetic-True" in folder_name:
        iset += "*,/,"
    if "useInstrComparison-True" in folder_name:
        iset += ">,"
    iset += "+,-"
    return iset

# --------------------------------------------------------------
# Validity rules based on dtype and uarch FPU
# --------------------------------------------------------------
def is_valid_combination(dtype, iset, uarch):
    # fpu only for float
    if dtype in ("fixedpt", "double") and microarch_has_fpu(uarch):
        return False
    # no soft float for float
    if dtype == "float" and not microarch_has_fpu(uarch):
        return False
    # those op/func uses division, which is not supported on some uarchs
    iset = set(iset.split(","))   # {"tan", "log", "exp", "/", "+", "-"}
    if {"/", "tan", "log", "exp"} & iset and not microarch_has_div(uarch):
        return False 
    return True


# --------------------------------------------------------------
# Expected configs (single source of truth for both writing and
# step-1 completeness detection)
# --------------------------------------------------------------
def expected_configs(tpg_folder, uarch_list=None, verbose=False):
    """
    Return a list of (config_dict, filepath) for every valid (uarch, isa) combo.
    Pure: computes paths, does not create or write anything.
    """
    tpg_folder = Path(tpg_folder)
    outdir = tpg_folder / "inference" / "configs"

    dtype = infer_dtype(tpg_folder.name)
    iset = infer_iset(tpg_folder.name)

    target_configs = (
        {k: v for k, v in UARCH_CONFIGS_RAW.items() if k in uarch_list}
        if uarch_list
        else UARCH_CONFIGS_RAW
    )
    if uarch_list:
        missing = set(uarch_list) - set(UARCH_CONFIGS_RAW.keys())
        if missing:
            raise ValueError(f"Unknown uarchs requested: {missing}")

    results = []
    for uarch, (isa_raw, abi) in target_configs.items():
        if not is_valid_combination(dtype, iset, uarch):
            if verbose:
                print(f"[SKIP] {tpg_folder.name} on {uarch} (dtype={dtype}) (iset={iset})")
            continue

        expanded_isas = expand_isa(isa_raw)
        # only the non-c version for modelization v1 (preserved from original)
        expanded_isas = [expanded_isas[0]] if len(uarch) != 0 else expanded_isas

        for isa in expanded_isas:

            compiler = determine_compiler(isa) #uses xpulp 

            isa = replace_xpulp_extensions(isa) # replaces xpulp

            filename = f"{uarch}_{isa}_{abi}_{dtype}.json"
            config = {
                "tpg": tpg_folder.name,
                "uarch": uarch,
                "isa": isa,
                "abi": abi,
                "dtype": dtype,
                "compiler": compiler
            }
            results.append((config, outdir / filename))
    return results


# --------------------------------------------------------------
# Main generator (idempotent, skips if already complete)
# --------------------------------------------------------------
def generate(tpg_folder, uarch_list=None, force=False):
    tpg_folder = Path(tpg_folder)

    # create the inference subtree
    for sub in ("configs", "results", "overlays", "tpg_inference_expe"):
        (tpg_folder / "inference" / sub).mkdir(exist_ok=True, parents=True)

    configs = expected_configs(tpg_folder, uarch_list, verbose=True)

    # Step-1 detection: if every expected config already exists, skip.
    if not force and configs and all(p.exists() for _, p in configs):
        print(f"[SKIP-ALL] {tpg_folder.name}: {len(configs)} config(s) already present")
        return

    for config, filepath in configs:
        with open(filepath, "w") as f:
            json.dump(config, f, indent=4)
        print(f"[OK] Created {filepath.name}")


# --------------------------------------------------------------
# CLI
# --------------------------------------------------------------
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--tpg_folder", required=True)
    parser.add_argument(
        "--uarch_list",
        required=False,
        nargs="+",
        default=None,
        help="List of target uarchs to generate configs for. If not provided, all uarchs are used."
    )
    parser.add_argument(
        "--force",
        action="store_true",
        help="Regenerate configs even if all expected files already exist."
    )
    args = parser.parse_args()
    generate(args.tpg_folder, args.uarch_list, force=args.force)