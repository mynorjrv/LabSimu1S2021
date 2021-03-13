#!/bin/bash

curl -s -o dummy wttr.in/Guatemala
#s es de silence, no muestra la informacion de descarga
#o es para guardar los datos recibidos, es analogo a hacer un > dummy. Puede ser sustituido por:
#curl -s wttr.in/Guatemala > dummy
#dummy es el nombre del archivo donde se guardara lo descargado
#wttr.in/Guatemala es la pagina

head -n 7 dummy
rm dummy
#tomo las lineas de dummy y lo borra