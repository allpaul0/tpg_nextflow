process generate_configs {
    cpus = 1
    memory = '1 GB'
    time = '1h'

    input:
    val parameters

    output:
    path "*"

    // This script generates the Learning Environment initial states for inference.  
    script:
    """
    ruby /home-reseau/pallaire/tpg_nextflow/pipeline/scripts/generate_seeds.rb true 0 
    """
}