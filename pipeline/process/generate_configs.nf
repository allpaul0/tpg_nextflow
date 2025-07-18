process generate_configs {

    input:
    val(instruction_set)

    output:
    path "trainParams_${instruction_set.instrSetName}.json"

    script:
    """
    echo "Generating configuration for instruction set: ${instruction_set.instrSetName}"
    touch trainParams_${instruction_set.instrSetName}.json
    """
}