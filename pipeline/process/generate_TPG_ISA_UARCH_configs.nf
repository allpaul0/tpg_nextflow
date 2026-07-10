process generate_TPG_ISA_UARCH_configs {
  cpus 1
  memory '1 GB'
  time '5min'

  input:
  path tpg_folder
  val uarch_list

  output:
  path tpg_folder

  script:
  def uarch_str = (uarch_list instanceof List) ? uarch_list.join(" ") : uarch_list
  """
  python3 ${params.projectRoot}/pipeline/scripts/generate_TPG_ISA_UARCH_configs.py \
    --tpg_folder ${tpg_folder} \
    --uarch_list ${uarch_str}
  """
}