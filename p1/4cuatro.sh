#!/bin/bash

if [ "$1" == "" ]; then
    echo "Debe indicar el nombre del directorio a utilizar"
    exit;
fi

if [ -e $1 ]
then
    echo "OK: el directorio existe"
else
    mkdir $1
    echo "Creando el directorio: " $1
fi

echo "Accediento al directorio..."
cd $1

url="https://www.debian.org/logos/openlogo-nd-100.jpg"

wget -q $url

if [ $? -ne 0 ]
then
    echo "Archivo no descargado: Error"
else
    echo "Archivo descargado: OK"
fi

echo "Saliendo del directorio..."
cd ..











  
