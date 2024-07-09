#!/bin/bash
echo "Threads,    Size,  MegaMults,    SIMDMMs, MMSpeedup,   MegaSums,    SIMDMSs, MSSpeedup"
for t in 1 2 4
do
  for s in 1024 8192 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608
  do
    g++ proj42.cpp -DARRAYSIZE=$s -DNUMT=$t -o proj42 -lm -fopenmp
    ./proj42
  done
done