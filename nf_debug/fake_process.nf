#!/usr/bin/env nextflow

nextflow.enable.dsl=2

workflow {

    def channels = Channel.from(0..20)

    dummyProcess(channels)
}

process dummyProcess {

    cpus = 1
    memory = '16 MB'
    time = '00:01:00'

    

    queueSize = 16

    input:
    val id

    output:
    stdout

    """
    echo "Running a single dummy process with id: ${id}"
    sleep 20
    """
}
