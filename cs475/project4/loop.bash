#!/bin/bash
echo Size, MegaMults, SimdMegaMults, MultsSpeedup, MegaSums, SimdMegaSums, SumsSpeedup
for s in 1024 524288 1048576 2097152 4194304 8388608
do
  g++ proj4.cpp -DARRAYSIZE=$s -o proj4 -lm -fopenmp
  ./proj4
done