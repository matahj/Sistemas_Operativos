#!/bin/bash

read -s -p "Ingresa password : " password
echo ""
tam=${#password}
if [ "$tam" -lt "8" ]; then
          echo "EL TAMANIO ES MINIMO 8 "
          exit
fi 

digitos=$(echo $password  | grep -o "[0-9]*"|head -n 1)

if [ -z $digitos  ]; then
          echo "NO TIENE DIGITOS "
          exit
fi 

especiales=$(echo $password  | grep -o -E "@|#|$|%|&|*|+|-|="| head -n 1)

if [ -z $especiales  ]; then
          echo "NO TIENE SIMBOLOS ESPECIALES"
          exit
fi 

echo "Contrasenia válida!!!!!"


