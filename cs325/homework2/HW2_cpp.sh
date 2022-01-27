#!/bin/bash
echo "Knapsack DP vs Recursive"

g++ knapsack.cpp -std=c++11 -o knapsack
./knapsack 10 10 10 15 #max item value, max item weight, num items in scenario 1, knapsack weight in scenario 1, num items in scenario 2, weight in scenario 2, etc.
echo
echo

echo "Shopping Spree"

g++ shopping.cpp -std=c++11 -o shopping
./shopping > my_results.txt
./shopping

echo "Comparing results "
diff -y -B -b --report-identical-files --suppress-common-lines my_results.txt HW2Solution.txt
echo

rm knapsack shopping my_results.txt