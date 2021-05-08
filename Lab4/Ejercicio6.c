/*
Autor (usuario):  mynorjrv
Fecha:  vie 07 may 2021 12:27:16 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o Ejercicio6 Ejercicio6.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Distintas sumatorias
Entradas:  numero hasta el que se sume, numero de sumatoria
Salidas:  resultado de la sumatoria
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Varibales
char eleccion;
int limite;

//Funciones
long funcionA(int n);
float funcionB(int n);
float funcionC(int n);
float funcionD(int n);


int main(void){
  printf("Ingrese A, B, C o D par aelegir una funcion a evaluar: ");
  scanf("%c", &eleccion);

  printf("Ingrese un limite valido: ");
  scanf("%d", &limite);

  switch(eleccion) {
  case 'A':
    printf("%ld\n", funcionA(limite) );
    break;
  case 'B':
    printf("%f\n", funcionB(limite) );
    break;
  case 'C':
    printf("%f\n", funcionC(limite) );
    break;
  case 'D':
    printf("%f\n", funcionD(limite) );
    break;
  default:
    puts("No selecciono una funcion, bye.");
  }
    
  return 0;
}



long funcionA(int n){
  long suma = 0;
  if(n<1){
    puts("Ingresar limite valido");
    exit(0);
  }
  for(int i=1; i<=n; i++){
    suma += i*i*(i-3);
  }
  return suma;
}


float funcionB(int n){
  float suma = 0;
  if(n<2){
    puts("Ingrear limite valido");
    exit(0);
  }
  for(int i=2; i<=n; i++)
    suma += 3/((float)i-1);
  return suma;
}


float funcionC(int n){
  float suma = 0;
  if(n<1){
    puts("Ingresar limite valido.");
    exit(0);
  }
  for(int i=1; i<=n; i++){
    suma += (1/sqrt(5)) * ( pow( (1+sqrt(5))/2 ,i) - pow( (1-sqrt(5))/2,i) );
    //printf("",
  }
  return suma;
}

float funcionD(int n){
  float suma=0;
  if(n<2){
    puts("Ingresar limite valido.");
    exit(0);
  }
  for(int i=2; i<=n; i++)
    suma += 0.1*( 3*pow(2, i-2) + 4);
  return suma;
}
