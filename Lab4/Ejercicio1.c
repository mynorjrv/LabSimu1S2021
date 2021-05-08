/*
Autor (usuario):  mynorjrv
Fecha:  mié 05 may 2021 17:17:28 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o Ejercicio1 Ejercicio1.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Imprime un vector, de manera ascendente o descendente.
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>
#include <math.h>

//Varibales
int A[]={2,4,6,8,10,12,14,16,18,20};
//traté de hacer esto una función pero me mandó a la chingada
//porque debo declarar antes :(
int Largo = sizeof(A)/sizeof(A[0]);

//Declaracion de funciones
//así que como no pude hacer la función incluí un parámetro
//para usar las dos funciones
void crecendo(int a[], int lenght);
void decrecendo(int a[], int lenght);

int main(void){
  char letra = 'x';
    
  while(1){
    printf("Ingrese 'a' si quiere ver los datos ascendentes o 'd' si los quiere ver descendentes: ");
    
    scanf("%s", &letra);
    
    if( letra == 'a' ){
      crecendo(A, Largo);
      break;
    }
    if( letra == 'd' ){
      decrecendo(A, Largo);
      break;
    }

    printf("Ingrese un valor valido.\n");
  }

  return 0;
}

void crecendo(int a[], int lenght){
  for(int i=0; i<lenght; i++){
    //hay 10 posiciones pero empieza por 0 así que uso meno que
    printf("%d ", a[i]);
  }
  printf("\n");
}

void decrecendo(int a[], int lenght){
  for(int i=lenght; i>0; i--){
    //Uso menos uno para no hacer mas complicado el condicional
    printf("%d ", a[i-1]);
  }
  printf("\n");
}
