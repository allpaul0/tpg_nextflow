process detect_inference_work {
    cpus 1
    memory '1 GB'
    time '5min'

    input:
    path tpg_folder
    val uarch_list

    output:
    path 'todo.tsv'

    script:
    def uarch_str = (uarch_list instanceof List) ? uarch_list.join(" ") : uarch_list
    """
    python3 ${params.projectRoot}/pipeline/scripts/detect_inference_work.py \
        --tpg_folder ${tpg_folder} \
        --uarch_list ${uarch_str} \
        > todo.tsv
    """
}
