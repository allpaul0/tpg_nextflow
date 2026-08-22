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

set -euo pipefail

expe_json="$1"
tpg_folder="$2"
project_root="$3"
apps_arg="${4:-default,teams,dispatch}"   # which apps to run this invocation

echo "Running inference with ${expe_json}"
echo "Apps requested: ${apps_arg}"

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

copy_cmds=""
run_cmds=""
ran_any=0

for a in "${APPS[@]}"; do
    a="$(echo "$a" | tr -d '[:space:]')"
    [ -z "$a" ] && continue
    if [ -z "${APP_DIR[$a]:-}" ]; then
        echo "ERROR: unknown app key '$a' (expected default|teams|dispatch)" >&2
        exit 1
    fi
    ran_any=1
    app="${APP_DIR[$a]}"
    cg="${APP_CODEGEN[$a]}"
    instr="${APP_INSTR[$a]}"

    # stage codegen + LE states for this app
    copy_cmds+=" && cp /outLogs/${cg}/TPG* /x-heep/sw/applications/tpg_modelization/${app}/codegen/."
    copy_cmds+=" && cp /outLogs/precalcul/LE_states.h /x-heep/sw/applications/tpg_modelization/${app}/precalcul/."

    # simulate -> disassemble -> export, per app, so partial progress survives
    run_cmds+=" && echo '=== app ${app} (INSTR=${instr}) ==='"
    run_cmds+=" && ./scripts/automatic-simulation/simulation.sh tpg_modelization/${app} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler} ${instr}"
    run_cmds+=" && ./scripts/compile_disassemble/compile_disassemble.sh tpg_modelization/${app} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler}"
    run_cmds+=" && mv experimentations/compilations/disassembly_${app}.txt /inference/results/${tag}/."
    run_cmds+=" && cp experimentations/simulations/${tag}.json /inference/results/${tag}/latencies.json"
done

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
overlay_img="${inference_dir}/overlays/overlay_${tag}.img"
mkdir -p "${inference_dir}/overlays"
rm -f "${overlay_img}"
apptainer overlay create --size 512 "${overlay_img}"
realpath "${project_root}/containers/x-heep.sif"

# ---- assemble the single in-container command -------------------------------
CMD="export XDG_CACHE_HOME=/inference/cache && mkdir -p /inference/cache"
CMD+="${copy_cmds}"
CMD+=" && cd /x-heep"
CMD+=" && mkdir -p experimentations/simulations"
CMD+="${seed_cmd}"
CMD+="${run_cmds}"

apptainer exec \
    --overlay "${overlay_img}" \
    --bind "$params_dir":/params/ \
    --bind "$outlogs_dir":/outLogs/ \
    --bind "$inference_dir":/inference/ \
    --bind "$simulators_dir":/x-heep/experimentations/microarchitectures/simulators/:ro \
    --bind .:/opt/x-heep \
    "${project_root}/containers/x-heep.sif" \
    /bin/bash -c "${CMD}"

rm -f "${overlay_img}"

echo "Done. Apps [${apps_arg}] merged into ${results_dir}/latencies.json"