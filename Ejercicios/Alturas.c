/*
Autor (usuario):  mynorjrv
Fecha:  Sun 21 Mar 2021 04:18:07 PM CST
compilador:  gcc (Debian 8.3.0-6) 8.3.0
Para Compilar: gcc -o Alturas Alturas.c
Version: 1.0
librerias: stdio (u otras)
Resumen: Este programa pide "alturas" (numeros), al ingresar
         un numero negativo termina y promedia los pbtenidos
	 y da el maximo y minimo.
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>

int n = 0;
float med = 0;

float x;
float max;
float min;


int main(void){

  printf("Ingrese un dato: ");
  scanf("%f", &x);

  max = x;
  min = x;

  //While si obtuvimos una entrada positiva
  while (x>=0){
    //actualiza los datos
    n = n + 1;
    med = med + x;

    //compara con el maximo, si es mas grande lo cambia
    if (x>max)
      max = x;

    //analogo pero con el minimo
    if (x<min)
      min = x;

    printf("Ingrese un dato: ");
    scanf("%f", &x);
  }

  //si  no se ingrsaron datos regresa No positivos
  //si tenemos datos regresa Media, maximo y minimo
  if (n==0){
    printf("No positivos\n");
  }
  else{
    //los imprimo con tres decimales
    printf("Media: %.3f, Máximo: %.3f, Mínimo: %.3f \n", med/n, max, min);
  }

  return 0;

}

