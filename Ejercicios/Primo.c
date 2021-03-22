/*
Autor (usuario):  mynorjrv
Fecha:  Sun 21 Mar 2021 06:55:10 PM CST
compilador:  gcc (Debian 8.3.0-6) 8.3.0
Para Compilar: gcc -o Primo Primo.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Determina si un número es primo o no.
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>

int N;
int i;
int primo;

int main(void){

  printf("Determinando si es primo \n");
  printf("Ingrese un entero: ");
  scanf("%i", &N);

  i = 2;
  primo = 1;

  /*okey :) es un programa bonito
  va probando los números menores a N
  si alguno es divisible cambia el valor de primo
  si llega a N-1 y no hay valor pues es primo*/
  //De hecho se puede detener en sqrt(N)
  while ( i<(N-1) && (primo==1) ){
    if (N%i==0)
      primo = 0;

    i++;
  }


  if (primo==0)
    printf("No es primo. \n");
  else
    printf("Es primo. \n");

  return 0;
}
