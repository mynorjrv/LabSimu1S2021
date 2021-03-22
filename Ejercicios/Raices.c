/*
Autor (usuario):  mynorjrv
Fecha:  Sun 21 Mar 2021 06:06:39 PM CST
compilador:  gcc (Debian 8.3.0-6) 8.3.0
Para Compilar: gcc -o Raices Raices.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Obtengo la raiz cuadrada entera por defecto
Entradas:  none
Salidas:  none
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>

float N;
int i;

int main(void){

  printf("Ingrese un número: ");
  scanf("%f", &N);

  i = 1; //pude inicializarla, es para seguir con el diagrama

  while( i*i <= N)
    i++;

  printf("La raíz cuadrada entera por defecto es: %i \n", i-1);
}
