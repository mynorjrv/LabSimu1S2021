/*
Autor (usuario):  mynorjrv
Fecha:  vie 07 may 2021 11:25:53 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o Ejercicio5 Ejercicio5.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Calculamos el facotrial usando recursividad
Entradas:  Un numero
Salidas:  El factorial del numero
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>

//Varibales
unsigned int dato;

//funciones
//estaba haciendo cosas raras con ints xd supongo que es mucho?
unsigned long factorial(unsigned int n);

int main(void){
  printf("Ingrese numero a calcular factorial: ");
  scanf("%u", &dato);

  printf("%d! = %lu\n", dato, factorial(dato));
  
  return 0;
}

unsigned long factorial(unsigned int n){
  if(n==0 || n==1)
    return 1;
  else
    return(n*factorial(n-1));
}
