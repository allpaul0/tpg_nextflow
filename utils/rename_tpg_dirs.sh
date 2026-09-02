# Script to rename directories for different instruction sets (iset). 
# If a directory was renamed to a specific iset_32 or iset_64 syntax, its subdirectories will be renamed accordingly.

cd /home/paulallaire/dev/modelization/tpg_nextflow
n=0
for iset in 64 32; do
  for d in armlearn-tpgs/tpg_double_iset${iset}/*/training_results/*_instrType-double; do
    [ -d "$d" ] || continue
    new="${d}_iset${iset}"
    if [ -e "$new" ]; then echo "SKIP (exists): $new"; continue; fi
    mv "$d" "$new"
    n=$((n+1))
  done
done
echo "renamed: $n"