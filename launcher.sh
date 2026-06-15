#!/bin/bash

# =========================
# Defaults
# =========================
mini_config=0
slurm=false

# =========================
# Parse command line arguments
# =========================
while [[ $# -gt 0 ]]; do
    case "$1" in
        --mini_config=*)
            mini_config="${1#*=}"
            ;;
        --target=*)
            target="${1#*=}"
            ;;
        --slurm=*)
            slurm="${1#*=}"
            ;;
        --slurm)
            slurm=true
            ;;
        *)
            # Pass unknown args through to Nextflow
            extra_args+=("$1")
            ;;
    esac
    shift
done

# =========================
# Validate flags
# =========================
case "$slurm" in
    true|false) ;;
    *)
        echo "Error: --slurm must be 'true' or 'false'"
        exit 1
        ;;
esac

# =========================
# Build Nextflow profile list
# executor profile: local (default) or slurm
# =========================
if [ "$slurm" = "true" ]; then
    profile="slurm"
else
    profile="local"
fi

# mini profile stacks on top when mini_config is active
if [ "$mini_config" -gt 0 ] 2>/dev/null; then
    profile="${profile},mini"
fi

# =========================
# Resolve target pipeline
# =========================
if [ -z "$target" ]; then
    if [ -t 0 ]; then
        echo "Select target pipeline:"
        echo "  1) train"
        echo "  2) prepare_inference"
        echo "  3) inference"
        read -rp "Enter choice (train/prepare_inference/inference): " target
    else
        echo "Error: --target must be provided in non-interactive mode."
        echo "       Allowed: train, prepare_inference, inference"
        exit 1
    fi
fi

case "$target" in
    train|train.nf)
        target_file="./pipeline/train.nf"
        selected_config="./configs/trainings.config"
        ;;
    prepare_inference|prepare_inference.nf)
        target_file="./pipeline/prepare_inference.nf"
        selected_config="./configs/prepare_inference.config"
        ;;
    inference|inference.nf)
        target_file="./pipeline/inference.nf"
        selected_config="./configs/inference.config"
        ;;
    *)
        echo "Error: Invalid target '$target'."
        echo "       Allowed: train, prepare_inference, inference"
        exit 1
        ;;
esac

# =========================
# Logging helper
# =========================
log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*"
}

# =========================
# Graceful SIGINT handling
# =========================
trap 'log "Terminating Nextflow..."; pids=$(pgrep -f nextflow); [ -n "$pids" ] && kill "$pids"; exit 0' SIGINT

# Set working directory to the script's location
cd "$(dirname "$0")" || exit 1

# =========================
# Build containers
# =========================
log "Checking containers..."

container_defs=()
for def_file in containers/*.def; do
    [ -e "$def_file" ] || continue
    container_defs+=("$(basename "$def_file" .def)")
done
log "Found container definitions: ${container_defs[*]}"

for container in "${container_defs[@]}"; do
    sif_file="containers/${container}.sif"
    def_file="containers/${container}.def"
    if [ ! -f "$sif_file" ] || [ "$def_file" -nt "$sif_file" ]; then
        log "Building container: $container"
        apptainer build --force "$sif_file" "$def_file"
    else
        log "Container up-to-date: $container"
    fi
done

# =========================
# Apptainer bind options
# (SLURM requires munge/slurm sockets; local needs nothing extra)
# =========================
apptainer_binds=()
if [ "$slurm" = "true" ]; then
    apptainer_binds+=(
        "--bind" "/etc/munge:/etc/munge"
        "--bind" "/run/munge:/run/munge"
        "--bind" "/etc/slurm:/etc/slurm"
    )
fi

# =========================
# Summary
# =========================
log "Target   : $target_file"
log "Config   : $selected_config"
log "Profile  : $profile"
log "mini_config: $mini_config"
[ ${#extra_args[@]} -gt 0 ] && log "Extra NF args: ${extra_args[*]}"

# =========================
# Launch
# =========================
apptainer exec \
    "${apptainer_binds[@]}" \
    containers/nextflow-insa.sif \
    nextflow run "$target_file" \
        --mini_config="${mini_config}" \
        --projectRoot "$(pwd)" \
        -c ./configs/nextflow.config \
        -c "$selected_config" \
        -profile "$profile" \
        -with-report \
        -with-dag \
        "${extra_args[@]}"