#!/bin/bash
g++ activity.cpp -std=c++11 -o activity
./activity > my_results.txt
echo
echo "Student Results"
echo
./activity
echo
echo "Solution"
echo
cat solution.txt
echo
diff -y -B -b --report-identical-files --suppress-common-lines my_results.txt solution.txt
echo
rm activity my_results.txt