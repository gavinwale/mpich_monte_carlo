#!/bin/bash
###
###
#SBATCH --time=00:10:00
#SBATCH -N 3
#SBATCH -n 64
#SBATCH --partition=shortq
#SBATCH --job-name=monte
#SBATCH --output=weak.o%j

module load slurm
module load gcc
module load mpich
#source ~/.bashrc

mpirun -np 64 ./RunMonte 268435456
