#!/usr/bin/env bash
#
# set_instrtype.sh — rewrite the "instrType" value in trainParams.json files
#
# Layout assumed:
#   <BASE_DIR>/<tpg_set>/<tpg_folder>/training_results/<run_X>/params/trainParams.json
#
# Default: under armlearn-tpgs/tpg_float_iset32, change "float" -> "float_iset32".
# Only the exact old value is touched, so re-running is a no-op.
#
# Always prints a dry run first, then asks for confirmation (unless -y).
#
# Example usage: ./pipeline/set_instrtype.sh -t tpg_float_iset64 -n float_iset64

set -uo pipefail

# ----------------------------------------------------------------------------
# CONFIG — prefill these
# ----------------------------------------------------------------------------

BASE_DIR="armlearn-tpgs"
TPG_SET="tpg_fixedpt_iset64"
OLD_VALUE="fixedpt"
NEW_VALUE="fixedpt_iset64"

# ----------------------------------------------------------------------------
# Internals
# ----------------------------------------------------------------------------

DTYPE=fixedpt
KEY="instrType"
PARAMS_FILE="params/trainParams.json"

ASSUME_YES=false

usage() {
    cat <<EOF
Usage: ${0##*/} [options]

Options:
  -b DIR   base folder (default: ${BASE_DIR})
  -t SET   tpg set folder under the base folder (default: ${TPG_SET})
  -o VAL   old ${KEY} value to replace (default: ${OLD_VALUE})
  -n VAL   new ${KEY} value (default: ${NEW_VALUE})
  -y       skip confirmation prompt
  -h       this help

Example (the iset64 set):
  ${0##*/} -t tpg_float_iset64 -n float_iset64
EOF
}

while getopts ":b:t:o:n:yh" opt; do
    case "$opt" in
        b) BASE_DIR="$OPTARG" ;;
        t) TPG_SET="$OPTARG" ;;
        o) OLD_VALUE="$OPTARG" ;;
        n) NEW_VALUE="$OPTARG" ;;
        y) ASSUME_YES=true ;;
        h) usage; exit 0 ;;
        \?) echo "Unknown option: -$OPTARG" >&2; usage >&2; exit 2 ;;
        :)  echo "Option -$OPTARG requires an argument" >&2; exit 2 ;;
    esac
done
shift $((OPTIND - 1))

BASE_DIR="${BASE_DIR%/}"
TPG_SET="${TPG_SET%/}"
SET_DIR="$BASE_DIR/$TPG_SET"

if [[ ! -d $SET_DIR ]]; then
    echo "ERROR: tpg set folder not found: $SET_DIR" >&2
    exit 1
fi
if [[ -z $OLD_VALUE || -z $NEW_VALUE ]]; then
    echo "ERROR: old and new values must not be empty." >&2
    exit 1
fi
if [[ $OLD_VALUE == "$NEW_VALUE" ]]; then
    echo "ERROR: old and new values are identical ('$OLD_VALUE')." >&2
    exit 1
fi

shopt -s nullglob dotglob

# Matches e.g.:    "instrType": "float",
OLD_PATTERN="\"$KEY\"[[:space:]]*:[[:space:]]*\"$OLD_VALUE\""
NEW_PATTERN="\"$KEY\": \"$NEW_VALUE\""

TO_EDIT=()      # files holding the old value
already=0       # files already on the new value
missing=0       # files without the key at all
n_files=0

for file in "$SET_DIR"/*/training_results/*/"$PARAMS_FILE"; do
    ((n_files++))
    if grep -Eq "$OLD_PATTERN" "$file"; then
        TO_EDIT+=("$file")
    elif grep -Eq "\"$KEY\"[[:space:]]*:[[:space:]]*\"$NEW_VALUE\"" "$file"; then
        ((already++))
    else
        ((missing++))
        echo "WARNING: no '$KEY' = '$OLD_VALUE' or '$NEW_VALUE' in $file" >&2
    fi
done

# ----------------------------------------------------------------------------
# Dry run
# ----------------------------------------------------------------------------

echo "=============================================================="
echo " DRY RUN — nothing has been modified yet"
echo "=============================================================="
echo " tpg set     : $SET_DIR"
echo " change      : \"$KEY\": \"$OLD_VALUE\"  ->  \"$KEY\": \"$NEW_VALUE\""
echo " files found : $n_files"
echo " to edit     : ${#TO_EDIT[@]}   (already done: $already, key not found: $missing)"
echo "--------------------------------------------------------------"

if ((n_files == 0)); then
    echo "ERROR: no $PARAMS_FILE found under $SET_DIR/*/training_results/*/" >&2
    exit 1
fi
if ((${#TO_EDIT[@]} == 0)); then
    echo "Nothing to change."
    exit 0
fi

current_tpg=""
for file in "${TO_EDIT[@]}"; do
    tpg="${file#"$SET_DIR"/}"
    tpg="${tpg%%/training_results/*}"
    if [[ $tpg != "$current_tpg" ]]; then
        current_tpg="$tpg"
        echo
        echo "[tpg] $current_tpg"
    fi
    run="${file#"$SET_DIR/$current_tpg"/training_results/}"
    run="${run%/$PARAMS_FILE}"
    printf '    %s\n' "$run"
done

echo
echo "--------------------------------------------------------------"
echo " ${#TO_EDIT[@]} file(s) would be modified."
echo "=============================================================="

# ----------------------------------------------------------------------------
# Confirmation + edit
# ----------------------------------------------------------------------------

if ! $ASSUME_YES; then
    read -r -p "Proceed with the rewrite? [y/N] " answer
    case "$answer" in
        y|Y|yes|YES) ;;
        *) echo "Aborted — nothing modified."; exit 0 ;;
    esac
fi

failed=0
for file in "${TO_EDIT[@]}"; do
    if sed -i -E "s|$OLD_PATTERN|$NEW_PATTERN|g" "$file" && grep -q "$NEW_PATTERN" "$file"; then
        echo "updated: $file"
    else
        echo "FAILED : $file" >&2
        ((failed++))
    fi
done

echo "--------------------------------------------------------------"
if ((failed > 0)); then
    echo "Done with $failed failure(s)."
    exit 1
fi
echo "Done — ${#TO_EDIT[@]} file(s) updated."
