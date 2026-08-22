#!/usr/bin/env python3
"""
detect_inference_work.py

Given a single TPG training folder, decide what inference work is still missing.

Advancement detection has two layers:

  Step 1 (config generation)  -> does inference/configs/ contain config JSONs?
                                 (the actual output of generate_TPG_ISA_UARCH_configs.py,
                                  which already encodes the inference.config uarch_list rules)

  Step 2 (per-app simulation) -> for each existing config, which of the three apps
                                 (default / teams / dispatch) are already done?
                                 An app is DONE iff BOTH:
                                    - its key is present in results/<tag>/latencies.json
                                    - its results/<tag>/disassembly_<app>.txt exists
                                 An app is RUNNABLE iff its codegen output exists in outLogs/
                                 (produced by the prepare_inference phase) and LE_states.h exists.

Output (stdout), one line per config that still has work, TAB-separated:

    <absolute_config_json_path>\t<comma_separated_apps_to_run>

e.g.
    /.../inference/configs/cv32e40x_im1_zba_zbb_rv32im_zicsr_zba_zbb_ilp32_fixedpt.json\tdispatch

Diagnostics (missing configs, un-runnable apps, counts) go to stderr so they don't
pollute the work list that Nextflow parses.
"""

import argparse
import json
import sys
from pathlib import Path

# Canonical run order. default first so it maps to the original script's behaviour.
APPS = ["default", "teams", "dispatch"]

# short key -> top-level key inside latencies.json
APP_KEY = {
    "default":  "instrTPG",
    "teams":    "instrTeams_instrTPG",
    "dispatch": "instrDispatch_instrTeams_instrTPG",
}

# short key -> disassembly filename dropped into results/<tag>/
APP_DIS = {
    "default":  "disassembly_tpg_inference_instrTPG.txt",
    "teams":    "disassembly_tpg_inference_instrTeams_instrTPG.txt",
    "dispatch": "disassembly_tpg_inference_instrDispatch_instrTeams_instrTPG.txt",
}

# short key -> codegen source folder under outLogs/ (produced by prepare_inference)
# NOTE: 'dispatch' is lowercase-d here to match what the codegen script actually writes
# (mv /outLogs/codegen /outLogs/codegen_dispatchInstrumented_TeamsInstrumented).
# Keep this in sync with simulation.sh.
APP_CODEGEN = {
    "default":  "codegen",
    "teams":    "codegen_TeamsInstrumented",
    "dispatch": "codegen_DispatchInstrumented_TeamsInstrumented",
}


def _valid_uarchs_for(tpg_folder: Path, uarch_list):
    """Subset of uarch_list that should yield a config for this TPG (valid dtype/iset combos).

    Returns None if the generator module can't be imported (then the caller skips the check).
    """
    try:
        sys.path.insert(0, str(Path(__file__).resolve().parent))
        from generate_TPG_ISA_UARCH_configs import (
            infer_dtype, infer_iset, is_valid_combination, UARCH_CONFIGS_RAW,
        )
    except Exception as e:  # noqa: BLE001 - best-effort, warning-only feature
        print(f"[INFO] step-1 per-uarch check skipped (cannot import generator: {e})",
              file=sys.stderr)
        return None

    try:
        dtype = infer_dtype(tpg_folder.name)
        iset = infer_iset(tpg_folder.name)
    except ValueError:
        return None

    return {
        u for u in uarch_list
        if u in UARCH_CONFIGS_RAW and is_valid_combination(dtype, iset, u)
    }


def apps_status(tpg_folder: Path, tag: str):
    """Return (need, blocked, le_ok) for one result tag.

    need    : apps that are missing AND runnable  -> should be executed
    blocked : apps that are missing but NOT runnable (codegen / LE_states missing)
    le_ok   : whether precalcul/LE_states.h exists
    """
    results_dir = tpg_folder / "inference" / "results" / tag
    latencies = results_dir / "latencies.json"

    present_keys = set()
    if latencies.is_file():
        try:
            data = json.loads(latencies.read_text())
            present_keys = set(data.keys())
        except (json.JSONDecodeError, OSError) as e:
            print(f"[WARN] {tpg_folder.name}/{tag}: could not parse latencies.json ({e}); "
                  f"treating all apps as not-done", file=sys.stderr)

    le_ok = (tpg_folder / "outLogs" / "precalcul" / "LE_states.h").is_file()

    need, blocked = [], []
    for a in APPS:
        dis = results_dir / APP_DIS[a]
        done = (APP_KEY[a] in present_keys) and dis.is_file()
        if done:
            continue
        codegen_ok = (tpg_folder / "outLogs" / APP_CODEGEN[a]).is_dir()
        if le_ok and codegen_ok:
            need.append(a)
        else:
            blocked.append(a)
    return need, blocked, le_ok


def main(argv=None):
    parser = argparse.ArgumentParser()
    parser.add_argument("--tpg_folder", required=True)
    parser.add_argument("--uarch_list", nargs="+", default=None,
                        help="Requested uarchs (from inference.config). Used only for a "
                             "coarse step-1 completeness warning.")
    args = parser.parse_args(argv)

    tpg = Path(args.tpg_folder).resolve()
    configs_dir = tpg / "inference" / "configs"

    # ---- Step 1 detection -------------------------------------------------
    if not configs_dir.is_dir():
        print(f"[WARN] {tpg.name}: no inference/configs/ dir — step 1 (config generation) "
              f"not done; nothing to schedule", file=sys.stderr)
        return
    configs = sorted(configs_dir.glob("*.json"))
    if not configs:
        print(f"[WARN] {tpg.name}: inference/configs/ is empty — step 1 not done", file=sys.stderr)
        return

    # Per-uarch step-1 sanity check. Only warn about uarchs that SHOULD have a config
    # for this TPG (valid dtype/iset combos), so invalid combos (e.g. fpu + fixedpt)
    # don't produce false "incomplete" warnings. The validity rules are imported from
    # the generator so the two stay in sync; if that import fails we just skip the check.
    if args.uarch_list:
        expected_uarchs = _valid_uarchs_for(tpg, args.uarch_list)
        if expected_uarchs is not None:
            for uarch in sorted(expected_uarchs):
                if not any(c.name.startswith(uarch + "_") for c in configs):
                    print(f"[WARN] {tpg.name}: no config found for requested uarch '{uarch}' — "
                          f"step 1 may be incomplete", file=sys.stderr)

    # ---- Step 2 detection -------------------------------------------------
    emitted = 0
    for cfg in configs:
        tag = cfg.stem  # result folder name == config filename stem
        need, blocked, le_ok = apps_status(tpg, tag)

        if blocked:
            reason = ("missing precalcul/LE_states.h" if not le_ok
                      else "missing codegen for " + ",".join(blocked))
            print(f"[WARN] {tpg.name}/{tag}: cannot run {blocked} ({reason}) — "
                  f"re-run prepare_inference for this TPG", file=sys.stderr)

        if need:
            print(f"{cfg.resolve()}\t{','.join(need)}")
            emitted += 1

    print(f"[INFO] {tpg.name}: {emitted}/{len(configs)} config(s) still need work",
          file=sys.stderr)


if __name__ == "__main__":
    main(sys.argv[1:])
