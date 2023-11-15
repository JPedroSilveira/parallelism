#!/bin/bash
#SBATCH --job-name=superstring
#SBATCH --partition=hype
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --time=01:00:00
#SBATCH --output=%x_%j.out
#SBATCH --error=%x_%j.err

./shsupopt < ./input-8000.txt