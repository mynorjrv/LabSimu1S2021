/*
Autor (usuario):  mynorjrv
Fecha:  mar 04 may 2021 00:02:42 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o biseccion biseccion.c -lm
Version: 1.0
librerias: stdio, stdlib (creo que para el exit), math
Resumen:  Implementacion del metodo de biseccion
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>
#include <stdlib.h> //esta es necesaria para el exit
#include <math.h>

//Varibales
float a=-0.5, b=0.7;
int NMAX = 10000;
float TOL = 0.000001;

//funcion a encontrar raiz
double f(float x)
  return (asin(x));

//funciones a utilizar
void checkeando(float i, float j); //Solo sirve para que los datos de entrada esten correctos

int main(void){
  //chequeando que los datos funcionen
  checkeando(a, b);
  int N = 1;//variable de control
  float c;//variable que ira cambiando el limite
  printf("Rango: [%.2f,%.2f]\n", a, b); //imprime el rango elegido
  
  //Esto es lo importante
  while (N<=NMAX){
    c = (a + b)/2; //punto medio del rango

    if ((f(c)==0)||( ((b-a)/2)<TOL )){
      //si el punto medio hace cero la funcion o llega mas cerca que la tolerancia termina
      printf( "Una raíz es %.6f.\n", c);
      return 0;
    }

    //imprimo la interacion, cambio el valor del limite y sumo la iteracion
    printf("%d %f %f %f\n", N, a, b, f(c));
    (f(c)*f(a)>0) ? (a=c) : (b=c);
    N++;
  }

  puts("Se alcanzó el máximo de iteraciones.");
  return 0;
}

//y esta es la que chequeaba
void checkeando(float i, float j){
  char dummy[30];
  if (j<=i){
    puts("El segundo límite del intervalo debe ser mayor.");
    exit(0);
  }

  if (f(i)*f(j) > 0){
    puts("No parece que haya una raíz en ese intervalo, cambie los límites");
    exit(0);
  }

  if (isnan(f(i))||isnan(f(j))){
    puts("Alguno de los limites esta fuera del dominio de la funcion.");
    exit(0);
  }
}
