#!/bin/bash

cores=$(cat /proc/cpuinfo  | grep "cpu cores" | awk '{print $4}' | tail -n 1)
echo "TOTAL DE CORES: "$cores

procs=$(cat /proc/cpuinfo  | grep "processor" | awk '{print $3}' | tail -n 1)
numProces=$(echo $procs "+1" | bc)
echo "TOTAL DE PROCESADORES: "$numProces
