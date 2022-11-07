#!/bin/bash

numProcesos=$(ps -eo user,%cpu,comm | grep $USER | wc -l)

echo "Total de procesos de usuario: " $numProcesos
