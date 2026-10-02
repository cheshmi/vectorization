#!/bin/bash

##################### SLURM (do not change) v  #####################
#SBATCH --export=ALL
#SBATCH --job-name="tut02"
#SBATCH --nodes=1
#SBATCH --output="tut02.%j.%N.out"
#SBATCH -t 00:45:00
##################### SLURM (do not change) ^  #####################

# Above are SLURM directives for job scheduling on a cluster,
export SLURM_CONF=/etc/slurm/slurm.conf


echo "----- Building -----"
# Do not change below, it is fixed folder everyone
SHAREDDIR=/home/coe4sp4/

cmake -S . -B $(pwd)/build -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=${SHAREDDIR}/libpfm4/ -DPROFILING_ENABLED=ON
cmake --build $(pwd)/build -- -j8
make -j8



echo "---- Running ----"

mkdir -p $(pwd)/logs
$(pwd)/build/vec_add_driver --benchmark_out="$(pwd)/logs/lab02-part1.json" --benchmark_out_format=json
$(pwd)/build/mat_vec_driver --benchmark_out="$(pwd)/logs/lab02-part2.json" --benchmark_out_format=json
