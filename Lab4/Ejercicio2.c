/*
Autor (usuario):  mynorjrv
Fecha:  mié 05 may 2021 20:43:20 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o Ejercicio2 Ejercicio2.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Ordanamiento de un vector mediante metodo de burbuja.
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>
#define numerodeDatos 5 //con el afan de hacerlo in poco mas general

//Varibales
int vectorDatos[numerodeDatos];

int main(void){
  puts("Puede ingresar 5 datos cualesquiera.");
  for( int i=0; i<numerodeDatos; i++){
    printf("Ingrese numero %d: ", i+1);
    scanf("%d", &vectorDatos[i]);
  }

  //ahora burbujeamos
  int length = numerodeDatos - 1; //no necesito el sizeof, ya se cuanto mide
  int swap; //variable de control, si se reordenan datos no sale de bucle
  int aux = 0; //para cambiar el orden
  
  do{
    swap = 0; //se reestablece la de pasadas
    
    for( int j=0; j<numerodeDatos-1; j++){
      if( vectorDatos[j] > vectorDatos[j+1]){
	aux = vectorDatos[j];
	vectorDatos[j] = vectorDatos[j+1];
	vectorDatos[j+1] = aux;
	swap = 1;
      }
    }
  } while( swap!=0 );

  for(int j=0; j<numerodeDatos; j++)
    printf("%d ", vectorDatos[j]);
  printf("\n");
  

  return 0;
}

