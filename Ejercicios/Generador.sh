#!/bin/bash

: << 'Header'
Autor:              Mynor Rodriguez
Fecha:              12-03-2021
Tipo de archivo:    Script de Bash
Para ejecutar:      ./Gernerador.sh
Resumen:            Generador automatico de comentarios para scripts de C.
Header

#bienvenida
#hay que ser honesto, practiamente copie el de clase
#no se si esa era la idea
echo "* * * * Generador de archivos de C * * * * "
#obtener y validar el nombre del archivo
read -p "Ingrese el nombre del archivo: " nombre
fnombre=$nombre".c"

#z es un empty string, le añadi el mismo nombre para no sobrescribir
#creo que no era necesario
if [ -z $nombre ]; then
    echo "No ingreso un nombre valido"
    exit 2
fi

if [ -e $fnombre ]; then
    echo "El archivo ya existe"
    exit 2
fi

#obtener informacion del sistema
autor=$(whoami)
fecha=$(date)
version=$(gcc --version | head -n 1)
#crear nuestro contenido dentro del archivo .c
echo "/*" > $fnombre
echo "Autor (usuario): " $autor >> $fnombre
echo "Fecha: " $fecha >> $fnombre
echo "compilador: " $version >> $fnombre
echo Para Compilar: gcc -o $nombre $fnombre >> $fnombre
#esto lo lleno yo
echo "Version: 1.0" >> $fnombre
echo "librerias: stdio (u otras)" >> $fnombre

#resumen, entradas, salidas
#Supngo que pude hacer un if bonito
echo; echo #no se lo de insertar linea :(
echo "Se puede ingresar Resumen, entradas y salidas"
echo "Pueden ingresarse o editarse luego"
echo "" #no se muy bien cual es el caracter de linea

read -p "Escriba un resumen: " resumen
echo "Resumen: " $resumen >> $fnombre

read -p "Escriba las entradas del programa: " resumen
echo "Entradas: " $resumen >> $fnombre

read -p "Escriba las salidas del programa: " resumen
echo "Salidas: " $resumen >> $fnombre
echo "*/" >> $fnombre

#librerias
echo "" >> $fnombre
echo "//Librerias" >> $fnombre
echo "//Recuerde añadirlas al header" >> $fnombre
echo "#include <stdio.h>" >> $fnombre