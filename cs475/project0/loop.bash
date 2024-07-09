#!/bin/bash

#number of threads:
for t in 1 4
do
   echo ""
   echo NUMT = $t
	g++ -DNUMT=$t proj0.cpp -o proj0 -lm -fopenmp
   ./proj0
done
echo ""
make clean