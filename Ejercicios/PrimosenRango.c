/*
Autor (usuario):  mynorjrv
Fecha:  Sun 21 Mar 2021 09:52:47 PM CST
compilador:  gcc (Debian 8.3.0-6) 8.3.0
Para Compilar: gcc -o PrimosenRango PrimosenRango.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Muestra los primos en un rango de números.
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>

int N1, N2;
int i, j;
int primo;

int main(void){

  printf("Primos en un intervalo \n");
  printf("Ingrese el límite inferior del intervalo: ");
  scanf("%i", &N1);
  printf("Ingrese el límite superior del intervalo: ");
  scanf("%i", &N2);

  printf("Primos en este intervalo: ");

  i = N1;
  
  //Lo único diferente es meter lo de primo a un while 
  while( i <= N2){

    //Empieza subproceso, esliteralmente Primo cambiando variables
    j = 2;
    primo = 1;
    while ( j<(i-1) && (primo==1) ){
      if (i%j==0)
	primo = 0;

      j++;
    }
    //Termina subproceso

    //Imprime sólo si es primo
    if (primo==1)
      printf("%i ", i);

    i++;
  }

  //una línea extra por estética
  printf("\n");
  return 0;
}
