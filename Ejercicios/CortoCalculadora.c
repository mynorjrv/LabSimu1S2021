/*
Autor (usuario):  mynorjrv
Fecha:  Tue 06 Apr 2021 10:08:51 PM CST
compilador:  gcc (Debian 8.3.0-6) 8.3.0
Para Compilar: gcc -o CortoCalculadora CortoCalculadora.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Una calculadora que hace operaciones entre dos números según número de entrada
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>

//Varibales
int operacion; //para lo que voy a obtener
int control = 1; //para salir del programa
int reingreso = 0; //para pedir numeros
float A;
float B;

//Declaracion de funciones
//Las defino luego
int suma(float a,float b);
int resta(float a,float b);
int multi(float a,float b);
int divi(float a,float b);


int main(void){
  printf("* * * Calculadora basiquita * * * \n");

  //Loop principal
  //Solo sesale cuando es especificado
  while (control != 0){

    //Cndicion para volvera meter los numeros
    if (reingreso == 0){
      printf("Ingrese primer número: ");
      scanf("%f", &A);

      printf("Ingrese segundo número: ");
      scanf("%f", &B);

      reingreso = 1;

      printf("Qué quiere realizar?\n");
      printf("0: Salir del programa. \n");
      printf("1: Sumar los valores.\n");
      printf("2: Restar los valores. \n");
      printf("3: Multiplicar los valores. \n");
      printf("4: Dividir los valores.\n");
      printf("5: Cambiar los valores.\n");
      
    }
    
    printf("Opción: ");
    scanf("%i", &operacion);

    //esto se podia hacer con switch pero igual se ve bien asi
    if (operacion == 0)
      control = 0;
    else if (operacion == 1)
      suma( A, B);
    else if (operacion == 2)
      resta( A, B);
    else if (operacion == 3)
      multi( A, B);
    else if (operacion == 4)
      divi( A, B);
    else if (operacion == 5)
      reingreso = 0;
  }

  printf("Bye! \n");
  return 0;
}

//Definición de funciones
//Las funciones son enteras porque lo que me interesa es que me
//de el resultado en consola
int suma(float a,float b){
  printf("La suma es: %f \n", a + b);
  return 0;
}
int resta(float a,float b){
  printf("La resta es: %f \n", a - b);
  return 0;
}
int multi(float a,float b){
  printf("La multiplicación es: %f \n", a*b);
  return 0;
}
int divi(float a,float b){
  printf("La división es: %f \n", a/b);
  return 0;
}
