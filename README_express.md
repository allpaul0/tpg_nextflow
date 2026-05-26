## 1
apptainer build containers/gegelati-armlearn.sif containers/gegelati-armlearn.def

## 2
apptainer shell --bind armlearn-wrapper/params:/params/ --bind armlearn-wrapper/outLogs/:/outLogs containers/gegelati-armlearn.sif 

## 3
codegen
  
alias codegen="
cd armlearn-wrapper/build/ &&
cmake .. &&
make CodeGen &&
cd .. &&
./build/CodeGen
" 