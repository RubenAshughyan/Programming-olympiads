
folder=$1
number=$2

solveCode=$folder/main.cpp


bruteCode=$folder/brute.cpp
testCode=$folder/testGen.cpp

# Compile codes
c++ --std=c++11 $solveCode -o $folder/solve
if [[ $? != '0' ]]; then
  echo "-Failed to compile main solution"
  exit 1;
fi


c++ --std=c++11 $bruteCode -o $folder/brute
if [[ $? != '0' ]]; then
  echo "-Failed to compile brute solution"
  exit 1;
fi


for i in $(seq 1 $number)
do
  echo "-------------------$i-------------------"

  python3.7 $folder/testGen.py > $folder/inputFile
  if [[ $? != '0' ]]; then
    echo "-Failed to generate test"
    exit 1;
  fi

  echo "Test:"
  cat $folder/inputFile

  $folder/solve < $folder/inputFile > $folder/outputSolve
  $folder/brute < $folder/inputFile > $folder/outputBrute

  if diff -q $folder/outputSolve $folder/outputBrute; then

    echo -n "Both solutions: "
    cat $folder/outputSolve
    echo "OK"

  else
    echo "WA!!!"

    echo -n "Main solutions:"
    cat $folder/outputSolve

    echo -n "Brute force:"
    cat $folder/outputBrute

    exit 1;
  fi


done


#
#rm solveCode
#rm bruteCode
#rm testCode