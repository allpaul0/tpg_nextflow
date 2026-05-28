## build apptainer
apptainer build containers/gegelati-armlearn.sif containers/gegelati-armlearn.def

## enter apptainer
apptainer shell --bind armlearn-wrapper/params:/params/ --bind armlearn-wrapper/outLogs/:/outLogs containers/gegelati-armlearn.sif 

## Codegen
cd armlearn-wrapper/build/ &&
cmake .. &&
make CodeGen &&
cd .. &&
./build/CodeGen
" 

## Lancer prepare_inf
./launcher.sh --target=prepare_inference --mini_config=1 --slurm=false

## tester generation mapping: TPG -> UARCH
python3 pipeline/scripts/generate_TPG_ISA_UARCH_configs.py --tpg_folder model_tpg_l2e2_zmmul_compbare_compExpAr/training_results/useInstrTrig-False_useInstrLogExp-False_useInstrLog2Exp2-True_useInstrZmmul-True_useInstrExpensiveArithmetic-False_useInstrComparison-True_seed-0_instrType-fixedpt/ --minimal True