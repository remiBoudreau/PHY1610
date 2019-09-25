#!/bin/bash
# clearingtime.sh - ants average clearing time
#
# first argument is number of processes to use concurrently
# optional second argument is the number of cases (100 if absent).
#

p=${1:-1}   # number of processes, given on command line, or 1
n=${2:-32}  # number of cases, given as second parameter, or 32

# generate list of cases and starting chunk size
seeds=($(seq ${n}))       
starts=$(seq 0 ${p} ${n}) 

# where to put intermediate results
mytempdir=/dev/shm/${USER}
mkdir -p ${mytempdir}

# go over chunks by iterating over the starts and launch p processes in parallel
for start in ${starts}
do
    echo "${seeds[@]:$start:$p}"
    for seed in ${seeds[@]:$start:$p}
    do
       ./ants ${seed} > $mytempdir/${seed}.out &
    done
    wait
done

# collect first lines with zero ants
for seed in ${seeds[@]}
do
    grep ' 0$' ${mytempdir}/${seed}.out | head -n 1
done > ${mytempdir}/firstzeros.dat

# compute averages
awk '{a+=$1;n+=1.0}END{print a/n}' ${mytempdir}/firstzeros.dat
rm -rf ${mytempdir}
