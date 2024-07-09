#!/bin/bash
#SBATCH -J AutoCorr
#SBATCH -A cs475-575
#SBATCH -p classmpitest
#SBATCH -N 8 # number of nodes
#SBATCH -n 8 # number of tasks
#SBATCH -o mpiproject.out
#SBATCH -e mpiproject.err
#SBATCH --mail-type=END,FAIL
#SBATCH --mail-user=largenet@oregonstate.edu
module load openmpi
mpic++ proj7.cpp -o proj7 -lm
mpiexec -mca btl self,tcp -np 1 ./proj7
mpiexec -mca btl self,tcp -np 2 ./proj7
mpiexec -mca btl self,tcp -np 4 ./proj7
mpiexec -mca btl self,tcp -np 8 ./proj7
mpiexec -mca btl self,tcp -np 16 ./proj7
mpiexec -mca btl self,tcp -np 32 ./proj7
mpiexec -mca btl self,tcp -np 64 ./proj7
mpiexec -mca btl self,tcp -np 128 ./proj7