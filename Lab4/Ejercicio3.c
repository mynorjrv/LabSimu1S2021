/*
Autor (usuario):  mynorjrv
Fecha:  jue 06 may 2021 16:36:15 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o Ejercicio3 Ejercicio3.c -lm
Version: 1.0
librerias: stdio, math
Resumen:  Operaciones con vectores
Entradas:  Dos vecotres
Salidas:  Resultado de operaciones
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>
#include <math.h>

//Varibales
char names[]="xyz";
float V1[3];
float V2[3];
int dim = sizeof(V1)/sizeof(V1[0]);

/*no puedo definir suma ni producto punto porque las funciones
  no devulven arrays :( creo de hecho que no vlae la pena
  definir funciones*/
//va pueees, definire magnitud y producto puuuunto
float magnitud(float A[], int lenght);
float punto(float A[], float B[], int lenght);

int main(void){
  puts("Ingrese dos vectores.");

  //Entrada de vectores
  for( int i=0; i<dim; i++){
    printf("Ingrese %c de V1: ", names[i]);
    scanf("%f", &V1[i]);
  }
  for( int i=0; i<dim; i++){
    printf("Ingrese %c de V2: ", names[i]);
    scanf("%f", &V2[i]);
  }

  //Esto no lo ped[ia pero impresion de vectores
  printf("V1 = (%.2f, %.2f, %.2f)\n", V1[0], V1[1], V1[2]);
  printf("V2 = (%.2f, %.2f, %.2f)\n", V2[0], V2[1], V2[2]);

  //Magnitud de vectores
  printf("|V1| = %f\n", magnitud(V1, dim) );
  printf("|V2| = %f\n", magnitud(V2, dim) );

  //Suma de vectores
  //la verdad no me termina de agradar... pude solo sumar en el argumentoxd
  //Lo que podria hacer es una suma de componentes... pero meh, aguanta
  float Suma[dim];
  for(int i=0; i<dim; i++)
    Suma[i] = V1[i] + V2[i];

  printf("V1+V2 = (%.2f, %.2f, %.2f)\n", Suma[0], Suma[1], Suma[2]);

  //Producto punto
  printf("V1 * V2 = %f\n", punto(V1, V2, dim));

  //Producto cruz
  //esto servira en el determinante :)
  float Cruz[dim];
  for(int i=0; i<dim; i++)
    Cruz[i] = V1[(i+1)%3]*V2[(i+2)%3] - V2[(i+1)%3]*V1[(i+2)%3];

  printf("V1 x V2 = (%.2f, %.2f, %.2f)\n", Cruz[0], Cruz[1], Cruz[2]);
  
  return 0;
}

float magnitud(float A[], int lenght){
  int suma = 0;
  for(int i=0; i<lenght; i++)
    suma += pow( A[i], 2);
  return sqrt( suma );
}

float punto(float A[], float B[], int lenght){
  int suma = 0;
  for(int i=0; i<lenght; i++)
    suma += A[i]*B[i];
  return suma;
}
