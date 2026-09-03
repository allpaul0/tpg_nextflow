#!/usr/bin/env bash
#
# clean_tpgs.sh — remove codegen / inference artifacts from armlearn-tpgs runs
#
# Layout assumed:
#   <BASE_DIR>/<tpg_folder>/training_results/<run_X>/outLogs/{codegen,codegen_TeamsInstrumented,codegen_DispatchInstrumented_TeamsInstrumented,precalcul}
#   <BASE_DIR>/<tpg_folder>/training_results/<run_X>/inference/{configs,results}/*
#
# Codegen deletion can target all variants at once, or only the ones selected
# with -C (see usage).
#
# Always prints a dry run first, then asks for confirmation (unless -y).

set -uo pipefail

# ----------------------------------------------------------------------------
# CONFIG — prefill these
# ----------------------------------------------------------------------------

BASE_DIR="armlearn-tpgs"

# TPG folders to clean (trailing slashes are fine)
TPG_FOLDERS=(
    # "tpg_float_iset32/tpg_float_iset32_compExpAr"  
    # "tpg_float_iset32/tpg_float_iset32_logexp"
    # "tpg_float_iset32/tpg_float_iset32_logexp_trig"  
    # "tpg_float_iset32/tpg_float_iset32_trig"
    # "tpg_l2e2_zmmul_compbare_compExpAr"
    "tpg_fixedpt_iset32/tpg_fixedpt_iset32_compExpAr_logexp_trigo_complete"
)

# What to delete
DELETE_CODEGEN=true
DELETE_INFERENCE=false

# Which codegen directories to delete: "all", or a comma separated list of
# names/aliases (see usage for the accepted values). Overridden by -C.
CODEGEN_SELECTION="all"

# ----------------------------------------------------------------------------
# Internals
# ----------------------------------------------------------------------------

# Every directory (removed entirely) that lives under <run>/outLogs/
ALL_CODEGEN_TARGETS=(
    codegen
    codegen_TeamsInstrumented
    codegen_DispatchInstrumented_TeamsInstrumented
    precalcul
)
# Directories emptied (kept, contents removed), under <run>/inference/
INFERENCE_TARGETS=(configs results)

CODEGEN_TARGETS=()

ASSUME_YES=false
SHOW_SIZES=false

usage() {
    cat <<EOF
Usage: ${0##*/} [options] [tpg_folder ...]

Options:
  -b DIR   base folder (default: ${BASE_DIR})
  -c       delete codegen artifacts only
  -i       delete inference artifacts only
  -a       delete both (default)
  -C LIST  which codegen dirs to delete (default: ${CODEGEN_SELECTION})
           comma separated, from:
             all             every entry below
             codegen         codegen                (aliases: plain, base)
             teams           codegen_TeamsInstrumented                       (ti)
             dispatch        codegen_DispatchInstrumented_TeamsInstrumented  (dti)
             instrumented    both instrumented dirs above
             precalcul       precalcul              (alias: pre)
           full directory names are accepted too
  -s       show size of each entry in the dry run (slower)
  -y       skip confirmation prompt
  -h       this help

Any tpg folders given as arguments override the TPG_FOLDERS list in the script.

Examples:
  ${0##*/} -c -C dispatch            # only codegen_DispatchInstrumented_TeamsInstrumented
  ${0##*/} -c -C teams,dispatch      # both instrumented codegen dirs
  ${0##*/} -c -C all                 # every codegen dir (incl. precalcul)
EOF
}

# add one codegen target, ignoring duplicates
add_codegen_target() {
    local wanted="$1" existing
    for existing in ${CODEGEN_TARGETS[@]+"${CODEGEN_TARGETS[@]}"}; do
        [[ $existing == "$wanted" ]] && return 0
    done
    CODEGEN_TARGETS+=("$wanted")
}

# expand CODEGEN_SELECTION into CODEGEN_TARGETS
resolve_codegen_selection() {
    local spec="$1" item
    CODEGEN_TARGETS=()
    for item in ${spec//,/ }; do
        case "${item,,}" in
            all)
                local t
                for t in "${ALL_CODEGEN_TARGETS[@]}"; do add_codegen_target "$t"; done
                ;;
            codegen|plain|base)
                add_codegen_target codegen ;;
            teams|ti|codegen_teamsinstrumented)
                add_codegen_target codegen_TeamsInstrumented ;;
            dispatch|dti|codegen_dispatchinstrumented_teamsinstrumented)
                add_codegen_target codegen_DispatchInstrumented_TeamsInstrumented ;;
            instrumented|instr)
                add_codegen_target codegen_TeamsInstrumented
                add_codegen_target codegen_DispatchInstrumented_TeamsInstrumented ;;
            pre|precalcul)
                add_codegen_target precalcul ;;
            *)
                echo "ERROR: unknown codegen selection: '$item'" >&2
                echo "       accepted: all, codegen, teams, dispatch, instrumented, precalcul" >&2
                exit 2 ;;
        esac
    done
    if ((${#CODEGEN_TARGETS[@]} == 0)); then
        echo "ERROR: empty codegen selection." >&2
        exit 2
    fi
}

while getopts ":b:C:ciasyh" opt; do
    case "$opt" in
        b) BASE_DIR="$OPTARG" ;;
        c) DELETE_CODEGEN=true;  DELETE_INFERENCE=false ;;
        i) DELETE_CODEGEN=false; DELETE_INFERENCE=true  ;;
        a) DELETE_CODEGEN=true;  DELETE_INFERENCE=true  ;;
        C) CODEGEN_SELECTION="$OPTARG" ;;
        s) SHOW_SIZES=true ;;
        y) ASSUME_YES=true ;;
        h) usage; exit 0 ;;
        \?) echo "Unknown option: -$OPTARG" >&2; usage >&2; exit 2 ;;
        :)  echo "Option -$OPTARG requires an argument" >&2; exit 2 ;;
    esac
done
shift $((OPTIND - 1))

(($# > 0)) && TPG_FOLDERS=("$@")

BASE_DIR="${BASE_DIR%/}"

resolve_codegen_selection "$CODEGEN_SELECTION"

if [[ ! -d $BASE_DIR ]]; then
    echo "ERROR: base folder not found: $BASE_DIR" >&2
    exit 1
fi
if ! $DELETE_CODEGEN && ! $DELETE_INFERENCE; then
    echo "ERROR: nothing selected (codegen and inference both disabled)." >&2
    exit 1
fi
if ((${#TPG_FOLDERS[@]} == 0)); then
    echo "ERROR: no tpg folders given." >&2
    exit 1
fi

shopt -s nullglob dotglob

TO_DELETE=()   # paths to rm -rf
n_runs=0

for tpg in "${TPG_FOLDERS[@]}"; do
    tpg="${tpg%/}"
    tr_dir="$BASE_DIR/$tpg/training_results"

    if [[ ! -d $tr_dir ]]; then
        echo "WARNING: skipping '$tpg' — no such directory: $tr_dir" >&2
        continue
    fi

    runs=("$tr_dir"/*/)
    if ((${#runs[@]} == 0)); then
        echo "WARNING: no run folders under $tr_dir" >&2
        continue
    fi

    for run in "${runs[@]}"; do
        run="${run%/}"
        ((n_runs++))

        if $DELETE_CODEGEN; then
            for target in "${CODEGEN_TARGETS[@]}"; do
                path="$run/outLogs/$target"
                [[ -e $path ]] && TO_DELETE+=("$path")
            done
        fi

        if $DELETE_INFERENCE; then
            for target in "${INFERENCE_TARGETS[@]}"; do
                dir="$run/inference/$target"
                [[ -d $dir ]] || continue
                for child in "$dir"/*; do
                    TO_DELETE+=("$child")
                done
            done
        fi
    done
done

# ----------------------------------------------------------------------------
# Dry run
# ----------------------------------------------------------------------------

selection=""
$DELETE_CODEGEN   && selection+="codegen "
$DELETE_INFERENCE && selection+="inference "

echo "=============================================================="
echo " DRY RUN — nothing has been deleted yet"
echo "=============================================================="
echo " base folder : $BASE_DIR"
echo " tpg folders : ${TPG_FOLDERS[*]}"
echo " selection   : ${selection% }"
$DELETE_CODEGEN && echo " codegen dirs: ${CODEGEN_TARGETS[*]}"
echo " runs found  : $n_runs"
echo "--------------------------------------------------------------"

if ((${#TO_DELETE[@]} == 0)); then
    echo "Nothing to delete — already clean."
    exit 0
fi

current_run=""
for path in "${TO_DELETE[@]}"; do
    run="${path%%/outLogs/*}"
    run="${run%%/inference/*}"
    if [[ $run != "$current_run" ]]; then
        current_run="$run"
        echo
        echo "[run] $current_run"
    fi
    rel="${path#"$current_run"/}"
    suffix=""
    [[ -d $path ]] && suffix="/"
    if $SHOW_SIZES; then
        size=$(du -sh "$path" 2>/dev/null | cut -f1)
        printf '    %-8s %s%s\n' "${size:--}" "$rel" "$suffix"
    else
        printf '    %s%s\n' "$rel" "$suffix"
    fi
done

echo
echo "--------------------------------------------------------------"
echo " ${#TO_DELETE[@]} entries would be deleted."
if $SHOW_SIZES; then
    total=$(du -sch "${TO_DELETE[@]}" 2>/dev/null | tail -n 1 | cut -f1)
    echo " total size  : ${total:-unknown}"
fi
echo "=============================================================="

# ----------------------------------------------------------------------------
# Confirmation + deletion
# ----------------------------------------------------------------------------

if ! $ASSUME_YES; then
    read -r -p "Proceed with deletion? [y/N] " answer
    case "$answer" in
        y|Y|yes|YES) ;;
        *) echo "Aborted — nothing deleted."; exit 0 ;;
    esac
fi

failed=0
for path in "${TO_DELETE[@]}"; do
    if rm -rf -- "$path"; then
        echo "deleted: $path"
    else
        echo "FAILED : $path" >&2
        ((failed++))
    fi
done

echo "--------------------------------------------------------------"
if ((failed > 0)); then
    echo "Done with $failed failure(s)."
    exit 1
fi
echo "Done — ${#TO_DELETE[@]} entries deleted."
