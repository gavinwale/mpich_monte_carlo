#!/bin/bash
###
###
#SBATCH --time=00:10:00
#SBATCH --tasks=1
#SBATCH --partition=shortq
#SBATCH --job-name=monte
#SBATCH --output=soutput.o%j

module load slurm
module load gcc
module load mpich
#source ~/.bashrc

mpirun -np 1 ./RunMonte 1000000000
