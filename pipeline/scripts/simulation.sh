#!/bin/bash
#
# Runs inference simulation + disassembly for a single (TPG, config) pair, but ONLY
# for the apps that are still missing. Apps are passed as a 4th arg (comma-separated
# short keys): default,teams,dispatch. If omitted, all three run (fresh full run).
#
#   key      | app dir                                    | codegen source                             | INSTR
#   ---------|--------------------------------------------|--------------------------------------------|------
#   default  | tpg_inference_instrTPG                     | codegen                                    | 0
#   teams    | tpg_inference_instrTeams_instrTPG          | codegen_TeamsInstrumented                  | 1
#   dispatch | tpg_inference_instrDispatch_instrTeams_... | codegen_DispatchInstrumented_TeamsInstru.. | 2
#
# MERGING: x-heep's parse_simulation_output.py already merges its run into
#   experimentations/simulations/<SIM>_<ISA>_<ABI>_<dtype>.json
# keyed by instrumentation level. That filename is identical to our result tag, so we
# SEED that file with the existing results/<tag>/latencies.json before running. The
# parser then adds only the missing instrumentation keys and preserves the rest.
# The file is copied back out after EACH app, so a failure part-way through still
# keeps the apps that already completed (detection picks up the remainder next run).
#
# DEV MODE: pass a host x-heep checkout as the 5th arg (or via XHEEP_DEV) to bind it
# at /opt/x-heep and run everything from there instead of the container's baked-in
# /x-heep. Lets you validate script changes before committing / rebuilding the .sif.
#
#   ./simulation.sh cfg.json /path/tpg /path/root default,teams /path/to/x-heep
#   XHEEP_DEV=/path/to/x-heep ./simulation.sh cfg.json /path/tpg /path/root
#
# Env knobs (dev only):
#   XHEEP_DEV_BIND_SIMULATORS=0  use the dev checkout's own simulators/ instead of
#                                bind-mounting the shared read-only ones on top
#   DRY_RUN=1                    print the apptainer invocation and exit, run nothing

set -euo pipefail

expe_json="$1"
tpg_folder="$2"
project_root="$3"
apps_arg="${4:-default,teams,dispatch}"   # which apps to run this invocation
dev_xheep="${5:-${XHEEP_DEV:-}}"          # optional host x-heep checkout (dev mode)

echo "Running inference with ${expe_json}"
echo "Apps requested: ${apps_arg}"

# ---- resolve x-heep root (dev vs baked-in) ----------------------------------
if [ -n "${dev_xheep}" ]; then
    if [ ! -d "${dev_xheep}" ]; then
        echo "ERROR: XHEEP_DEV path does not exist: ${dev_xheep}" >&2
        exit 1
    fi
    dev_xheep="$(realpath "${dev_xheep}")"
    XHEEP_ROOT="/opt/x-heep"
    echo "*** DEV MODE: binding ${dev_xheep} -> ${XHEEP_ROOT} (container /x-heep unused) ***"
else
    XHEEP_ROOT="/x-heep"
fi

# ---- read JSON config -------------------------------------------------------
tpg=$(jq -r '.tpg'      "${expe_json}")
uarch=$(jq -r '.uarch'  "${expe_json}")
isa=$(jq -r '.isa'      "${expe_json}")
abi=$(jq -r '.abi'      "${expe_json}")
compiler=$(jq -r '.compiler' "${expe_json}")
dtype_upper=$(jq -r '.dtype' "${expe_json}" | tr '[:lower:]' '[:upper:]')
dtype_lower=$(jq -r '.dtype' "${expe_json}" | tr '[:upper:]' '[:lower:]')

# ---- paths ------------------------------------------------------------------
params_dir="${tpg_folder}/params"
outlogs_dir="${tpg_folder}/outLogs"
inference_dir="${tpg_folder}/inference"
simulators_dir="${project_root}/x-heep/experimentations/microarchitectures/simulators"

# result tag == parser output filename (parser lowercases DTYPE)
tag="${uarch}_${isa}_${abi}_${dtype_lower}"
results_dir="${inference_dir}/results/${tag}"

echo "TPG folder: ${tpg_folder}"
echo "uarch=${uarch} isa=${isa} abi=${abi} dtype=${dtype_lower} compiler=${compiler}"
echo "tag=${tag}"
echo "x-heep root (in container): ${XHEEP_ROOT}"

# ---- app metadata (keep in sync with detect_inference_work.py) --------------
declare -A APP_DIR=(
    [default]="tpg_inference_instrTPG"
    [teams]="tpg_inference_instrTeams_instrTPG"
    [dispatch]="tpg_inference_instrDispatch_instrTeams_instrTPG"
)
declare -A APP_CODEGEN=(
    [default]="codegen"
    [teams]="codegen_TeamsInstrumented"
    [dispatch]="codegen_DispatchInstrumented_TeamsInstrumented"
)
# Instrumentation level passed to x-heep's simulation.sh / parse_simulation_output.py
declare -A APP_INSTR=(
    [default]="0"
    [teams]="1"
    [dispatch]="2"
)

# ---- parse requested apps, build per-app command blocks ---------------------
IFS=',' read -ra APPS <<< "${apps_arg}"
# ^ Split "teams,dispatch" into the array APPS=(teams dispatch).
#   IFS=','  -> split on commas instead of the default whitespace. Written as a
#               prefix assignment, so it applies to THIS command only and the rest
#               of the script keeps a normal IFS.
#   read -a  -> store the fields in an array;  -r -> don't eat backslashes.
#   <<<      -> "herestring": feed the given string to read's stdin.

# Command fragments accumulated below and later glued into one `bash -c` chain.
# Must be initialised: `set -u` makes reading an unset variable fatal.
copy_cmds=""      # cp of codegen + LE_states, done up-front for every app
run_cmds=""       # simulate -> disassemble -> export, one block per app
ran_any=0         # did we see at least one valid app? checked after the loop

# "${APPS[@]}" in quotes expands to one word per element (unlike [*], which would
# join them into a single word).
for a in "${APPS[@]}"; do
    # Tolerate "teams, dispatch": strip any whitespace, else the lookup below
    # would miss on " dispatch" and abort over a purely cosmetic difference.
    a="$(echo "$a" | tr -d '[:space:]')"

    # Skip empty fields produced by a trailing/doubled comma ("teams," -> teams,"").
    [ -z "$a" ] && continue

    # Reject anything that isn't a known key.
    # ${...:-} supplies an empty default: without it, looking up a MISSING key in
    # an associative array under `set -u` kills the script with an opaque
    # "unbound variable" instead of the readable error below.
    if [ -z "${APP_DIR[$a]:-}" ]; then
        echo "ERROR: unknown app key '$a' (expected default|teams|dispatch)" >&2
        exit 1
    fi
    ran_any=1

    # Same short key indexes all three parallel dictionaries, so adding a 4th app
    # later means adding three entries and nothing else.
    app="${APP_DIR[$a]}"        # e.g. tpg_inference_instrTeams_instrTPG
    cg="${APP_CODEGEN[$a]}"     # e.g. codegen_TeamsInstrumented
    instr="${APP_INSTR[$a]}"    # e.g. 1

    # `+=` APPENDS to the string; it never overwrites. Each app therefore adds its
    # own block and the fragments accumulate across iterations.
    # Every fragment starts with " && " so the final chain aborts at the first
    # failure rather than charging on with a broken state.

    # stage codegen + LE states for this app
    copy_cmds+=" && cp /outLogs/${cg}/TPG* ${XHEEP_ROOT}/sw/applications/tpg_modelization/${app}/codegen/."
    copy_cmds+=" && cp /outLogs/precalcul/LE_states.h ${XHEEP_ROOT}/sw/applications/tpg_modelization/${app}/precalcul/."

    # simulate -> disassemble -> export, per app, so partial progress survives:
    # results are copied out after EACH app, so if app 3 dies, apps 1-2 are already
    # on disk and detect_inference_work.py will only schedule the remainder.
    run_cmds+=" && echo '=== app ${app} (INSTR=${instr}) ==='"
    run_cmds+=" && ./scripts/automatic-simulation/simulation.sh tpg_modelization/${app} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler} ${instr}"
    run_cmds+=" && ./scripts/compile_disassemble/compile_disassemble.sh tpg_modelization/${app} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler}"
    run_cmds+=" && mv experimentations/compilations/disassembly_${app}.txt /inference/results/${tag}/."
    run_cmds+=" && cp experimentations/simulations/${tag}.json /inference/results/${tag}/latencies.json"
done

# Nothing valid was requested (e.g. apps_arg was "" or just commas). Exit 0, not 1:
# "no work to do" is a normal outcome and must not fail the Nextflow task.
if [ "$ran_any" -eq 0 ]; then
    echo "No apps requested for ${tag}; nothing to do."
    exit 0
fi

mkdir -p "${results_dir}"

# ---- seed the parser's merge target with previous results -------------------
# Decided host-side so no conditional is needed inside the container command.
seed_cmd=""
if [ -f "${results_dir}/latencies.json" ]; then
    echo "Seeding parser with existing results: ${results_dir}/latencies.json"
    seed_cmd=" && cp /inference/results/${tag}/latencies.json experimentations/simulations/${tag}.json"
else
    echo "No previous latencies.json for ${tag}; parser will create a fresh one."
fi

# ---- build 512MB Apptainer overlay -----------------------------------------
# Still used in dev mode: it provides a writable layer for the /opt/x-heep mount
# point and any other container-side writes.
overlay_img="${inference_dir}/overlays/overlay_${tag}.img"
mkdir -p "${inference_dir}/overlays"
rm -f "${overlay_img}"
apptainer overlay create --size 512 "${overlay_img}"
realpath "${project_root}/containers/x-heep.sif"

# ---- assemble binds ---------------------------------------------------------
binds=(
    --bind "${params_dir}:/params/"
    --bind "${outlogs_dir}:/outLogs/"
    --bind "${inference_dir}:/inference/"
)

if [ -n "${dev_xheep}" ]; then
    # dev checkout replaces the baked-in tree
    binds+=( --bind "${dev_xheep}:${XHEEP_ROOT}" )
    # Nested bind: only mount the shared simulators on top if the dev checkout has
    # the target dir (apptainer needs it to exist inside the outer bind source).
    if [ "${XHEEP_DEV_BIND_SIMULATORS:-1}" = "1" ]; then
        if [ -d "${dev_xheep}/experimentations/microarchitectures/simulators" ]; then
            binds+=( --bind "${simulators_dir}:${XHEEP_ROOT}/experimentations/microarchitectures/simulators/:ro" )
        else
            echo "WARN: ${dev_xheep}/experimentations/microarchitectures/simulators does not exist;" >&2
            echo "      skipping the shared simulators bind. Create the dir, or set" >&2
            echo "      XHEEP_DEV_BIND_SIMULATORS=0 to silence this and use the checkout's own." >&2
        fi
    else
        echo "Using dev checkout's own simulators (XHEEP_DEV_BIND_SIMULATORS=0)"
    fi
else
    binds+=( --bind "${simulators_dir}:${XHEEP_ROOT}/experimentations/microarchitectures/simulators/:ro" )
fi

# ---- assemble the single in-container command -------------------------------
CMD="export XDG_CACHE_HOME=/inference/cache && mkdir -p /inference/cache"
CMD+="${copy_cmds}"
CMD+=" && cd ${XHEEP_ROOT}"
CMD+=" && mkdir -p experimentations/simulations"
CMD+="${seed_cmd}"
# Generate the MCU for this microarchitecture. Runs ONCE per invocation, not per
# app: a single call to this script always targets one uarch (it comes from the
# config JSON), and all requested apps are simulated on that same MCU.
# Must come before any simulation.sh call.
CMD+=" && ./scripts/generate-mcu/generate-mcu.sh ${uarch}"
CMD+="${run_cmds}"

if [ "${DRY_RUN:-0}" = "1" ]; then
    echo
    echo "=== DRY RUN: apptainer invocation ==="
    printf 'apptainer exec \\\n'
    printf '    --overlay %s \\\n' "${overlay_img}"
    printf '    %s %s \\\n' "${binds[@]}"
    printf '    %s \\\n' "${project_root}/containers/x-heep.sif"
    printf '    /bin/bash -c "%s"\n' "${CMD}"
    rm -f "${overlay_img}"
    exit 0
fi

apptainer exec \
    --overlay "${overlay_img}" \
    "${binds[@]}" \
    "${project_root}/containers/x-heep.sif" \
    /bin/bash -c "${CMD}"

rm -f "${overlay_img}"

echo "Done. Apps [${apps_arg}] merged into ${results_dir}/latencies.json"