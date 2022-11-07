#!/bin/bash

numero=$(ps -eo %cpu,comm | wc -l)
echo "Numero total de procesos: " $numero


