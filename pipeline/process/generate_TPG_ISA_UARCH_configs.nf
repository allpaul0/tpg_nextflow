process generate_TPG_ISA_UARCH_configs {
  cpus = 1
  memory = '1 GB'
  time = '5min'
  
  input:
  path tpg_folder

  output:
  path tpg_folder

  script:
  """
  python3 ${params.projectRoot}/pipeline/scripts/generate_TPG_ISA_UARCH_configs.py --tpg_folder ${tpg_folder}
  """
}