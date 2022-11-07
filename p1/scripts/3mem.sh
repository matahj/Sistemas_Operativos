#!/bin/bash

memoria=$(grep MemTotal /proc/meminfo | awk '{print $2}')
total=$(echo "scale=5 ;$memoria.0/1024/1024"|bc -l)

echo "TOTAL DE MEMORIA: "$total


