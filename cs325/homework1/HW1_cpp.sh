#!/bin/bash
echo "Insertion Sort"

g++ insertsort.cpp -std=c++11 -o insertsort
./insertsort > insert.txt
./insertsort
echo

echo "Merge Sort"
g++ mergesort.cpp -std=c++11 -o mergesort
./mergesort > merge.txt
./mergesort
echo
echo "Correctly sotred data"
cat sorted.txt
echo

diff -y -B -b --report-identical-files --suppress-common-lines insert.txt sorted.txt
echo
diff -y -B -b --report-identical-files --suppress-common-lines merge.txt sorted.txt
echo
echo "Insertion Sort times"
g++ insertTime.cpp -std=c++11 -o insertTime
./insertTime
echo
echo "Merge Sort times"
g++ mergeTime.cpp -std=c++11 -o mergeTime
./mergeTime

