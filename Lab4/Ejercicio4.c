/*
Autor (usuario):  mynorjrv
Fecha:  vie 07 may 2021 23:50:20 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o Ejercicio4 Ejercicio4.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Operaciones con matrices
Entradas:  dos matrices y un escalar
Salidas:  distintas salidas
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>

//Varibales
float a;
float dummy;
float matA[3][3];
float matB[3][3];

//funciones
float filacolumna(float A[3][3], float B[3][3], int a, int b);
float det(float A[3][3]);

int main(void){
  
  //Ingresando valores a matrices
  puts("Ingrese los valores para la matriz A.");
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("A(%d,%d)= ", i+1, j+1);
      scanf("%f", &matA[i][j]);
    }
  }

  puts("Ingrese los valores para la matriz B.");
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("B(%d,%d)= ", i+1, j+1);
      scanf("%f", &matB[i][j]);
    }
  }

  printf("Ingrese una cosntante: ");
  scanf("%f", &a);
  
  //contante por matriz A
  puts("a*A =");
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%8.3f", a*matA[i][j]);
    }
    printf("\n");
  }

  //Suma de las dos matrices
  puts("A+B =");
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%8.3f", matA[i][j]+matB[i][j]);
    }
    printf("\n");
  }

  //Resta de las dos matrices
  puts("A-B =");
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%8.3f", matA[i][j]-matB[i][j]);
    }
    printf("\n");
  }
  
  //multiplicacion de matrices
  puts("AB =");
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%8.3f", filacolumna(matA,matB,i,j) );
    }
    printf("\n");
  }

  //determinante de A
  printf("det(A)= %f\n", det(matA) );

  //traspuesta de B
  //traspuesta de B
  puts("B^T =");
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%8.3f", matB[j][i]);
    }
    printf("\n");
  }
  

  return 0;
}

float filacolumna(float A[3][3], float B[3][3], int a,  int b){
  float suma = 0;
  for(int i=0; i<3; i++){
    suma += A[a][i]*B[i][b];
  }
  return suma;
}

float det(float A[3][3]){
  int suma = 0;
  int resta = 0;

  for(int i=0; i<3; i++){
    suma += A[0][i%3]*A[1][(i+1)%3]*A[2][(i+2)%3];
    resta+= A[0][(4-i)%3]*A[1][(3-i)%3]*A[2][(2-i)%3];
  }

  return( suma - resta);
}
