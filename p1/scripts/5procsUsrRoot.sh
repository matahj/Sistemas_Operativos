#!/bin/bash

numeroUsr=$(ps -eo user,%cpu,comm | grep $USER | wc -l)
echo "Procesos de usuario: " $numeroUsr

numeroRoot=$(ps -eo user,%cpu,comm | grep root | wc -l)
echo "Procesos de root: " $numeroRoot


