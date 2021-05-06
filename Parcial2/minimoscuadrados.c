/*
Autor (usuario):  mynorjrv
Fecha:  lun 03 may 2021 19:56:03 CST
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o minimoscuadrados minimoscuadrados.c -lm
Version: 1.0
librerias: stdio, math
Resumen:  Implementación del método de mínimos cuadrados, copiado del 
          archivo de Maynor xd.
Entradas: No pide entradas pero se debe ingresar a pata los vectores
          con datos.
Salidas: 
*/
//Tengo que ser honesto y decir que solo comente el hecho en clase xd

//Librerias
#include <stdio.h>
#include <math.h>

//Datos ingresados, por ahora se meten a pata
float x[]={1,2,3,4,5,6,7}, y[]={20,26,31,38,45,49,54};
//ese n es muy creativo, y nos sirve en las funciones
int n = sizeof(x)/sizeof(x[0]);

//prototipo de funciones
//sólo es la declaración, para que funcionen
void imprimirvec(float datos[]);
float sumdata(float datos[]);
float sumdatamul(float datos1[], float datos2[]);


void main(){
    //se inicializa las variables necesarias
    float b, m, r;
          
    //impresion de los datos
    imprimirvec(x);
    imprimirvec(y);
          
    //valores de cada parte de la ecuacion lineal
    m=( n*sumdatamul(x,y) - sumdata(x)*sumdata(y) )/( n*sumdatamul(x,x) - sumdata(x)*sumdata(x) );
    b=( sumdata(y) - m*sumdata(x) )/n;
          
    //se obtiene el coeficiente de correlacion
    r=(n*sumdatamul(x,y)-sumdata(x)*sumdata(y))/sqrt((n*sumdatamul(x,x)-sumdata(x)*sumdata(x))*(n*sumdatamul(y,y)-sumdata(y)*sumdata(y)));
          
    printf("y = %f x + %f\n",m,b);
    //Esto si lo cambie, de una vez me regresa los resultados que esperaba
    printf("para 5 meses tendremos %f, y para 10 %f.\n", 20*m + b, 40*m + b); 
    //el coeficiente de determinacion es el cuadrado de r
    printf("Coeficciente de determinacion: %f\n",r*r);
}



//Estoy cambiando un poco los comentarios
//aca si creo las funciones
void imprimirvec(float datos[]){
    puts("valor de datos");
    for (int i = 0; i < n; i++)
    {
        printf("%f ",datos[i]);
    }
    puts("\n");
}

//se realiza la suma de un vector determinado
float sumdata(float datos[]){
    float rep=0;
    for (int i = 0; i < n; i++)
    {
        rep += datos[i];
    }
    return rep;
}

//se realiza la suma de dos vectores, multiplicando cada uno de sus valores  de forma consecurtiva
float sumdatamul(float datos1[], float datos2[]){
    float rep=0;
    for (int i = 0; i < n; i++)
    {
        rep += datos1[i]*datos2[i];
    }
    return rep;
}
