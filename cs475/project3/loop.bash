#!/bin/bash
for t in 1 2 4 6 8
do
  for n in 2 3 4 5 10 15 20 30 40 50
  do
     g++ proj3.cpp -DNUMT=$t -DNUMCAPITALS=$n -o proj3 -lm -fopenmp
    ./proj3
  done
done