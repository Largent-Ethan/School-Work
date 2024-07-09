#!/bin/bash
#SBATCH  -J  Proj06
#SBATCH  -A  cs475-575
#SBATCH  -p  classgputest
#SBATCH  --constraint=v100
#SBATCH  --gres=gpu:1
#SBATCH  -o  proj06.out
#SBATCH  -e  proj06.err
#SBATCH  --mail-type=BEGIN,END,FAIL
#SBATCH  --mail-user=joeparallel@oregonstate.edu

for s in 4096 16384 65536 262144 1048576 4194304
do
        for b in 8 32 64 128 256
        do
                g++ -DDATASIZE=$s -DLOCALSIZE=$b -o proj6 proj6.cpp /usr/local/apps/cuda/11.7/lib64/libOpenCL.so.1  -lm -fopenmp
                ./proj6
        done
done