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
echo "Correctly sorted data"
cat sorted.txt
echo

diff -y -B -b --report-identical-files --suppress-common-lines insert.txt sorted.txt
echo
diff -y -B -b --report-identical-files --suppress-common-lines merge.txt sorted.txt
echo
echo "Insertion Sort times"
g++ insertTime.cpp -std=c++11 -o insertTime
./insertTime 5000 10000 15000 20000 25000 30000 40000 50000 #Add array sizes here
echo
echo "Merge Sort times"
g++ mergeTime.cpp -std=c++11 -o mergeTime
./mergeTime 5000 10000 15000 20000 25000 30000 40000 50000 #Add array sizes here

echo "Graphed timings are found in plot.jpg"
generate_plot_from_tsv

rm merge.txt mergeTime mergesort insert.txt insertTime insertsort