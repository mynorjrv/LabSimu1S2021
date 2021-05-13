/*
Autor (usuario):  mynorjrv
Fecha:  Thu 13 May 2021 10:39:59 AM CST
compilador:  gcc (Debian 8.3.0-6) 8.3.0
Para Compilar: gcc -o Final Final.c
Version: 1.0
librerias: stdio (u otras)
Resumen:  Programa para cohetitos
Entradas: 
Salidas: 
*/

//Librerias
//Recuerde añadirlas al header
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Varibales
//Constantes
double G = 6.693*pow(10, -11);
double MT = 5.9736*pow(10, 24);
double RT = 6.378*pow(10, 6);
double R = 287.06;
double L = 6.5*pow(10, -3);
double g0 = 9.81;
double T0 = 288.15;
double P0 = 101325;


//Voy a definir los datos

double E0_AhMun = 3*pow(10, 7);
double TSFC_AhMun = 3.248*pow(10, -4);
double CD_AhMun = 61.27;
double A_AhMun = 201.06;
double m0_AhMun = 1.1*pow(10, 5);
double mf0_AhMun = 1.5*pow(10, 6);

double E0_AhauKin = 2.7*pow(10, 7);
double TSFC_AhauKin = 2.7*pow(10, 7);
double CD_AhauKin = 61.27;
double A_AhauKin = 201.06;
double m0_AhauKin = 1.1*pow(10, 5);
double mf0_AhauKin = 1.5*pow(10, 6);

double E0_Chac = 2.5*pow(10, 7);
double TSFC_Chac = 2.248*pow(10, 7);
double CD_Chac = 70.25;
double A_Chac = 215;
double m0_Chac = 1.8*pow(10, 5);
double mf0_Chac = 2.1*pow(10, 6);

//Aca vere funciones
double g( double yt){
  return( (G*MT)/pow((RT + yt), 2));
}

double rho(double yt){
  if( yt < (T0/L)){
    double retorno = (P0/(R*T0)) * pow(( 1-((L*yt)/T0) ), g0/(R*L) );
    return retorno;
  }
  return 0;
}

double mc(double tiempo, double m0, double mf0, double TSFC, double E0){
  if( mf0 > TSFC*E0*tiempo )
     return( m0 + mf0 - TSFC*E0*tiempo );
  return m0;
}

double E(double tiempo, double mf0, double TSFC, double E0){
  if( mf0 > TSFC*E0*tiempo )
     return(E0);
  return 0;
}

double fa(double altura, double CD, double A){
  return( (1/2)*rho(altura)*CD*A );
}

//es una funcion complicada, tiene la intención de ser general
//es la unica vez que usaré las funciones anteriores
double acel(double tiempo, double altura, double velocidad, double m0, double mf0, double TSFC, double E0, double CD, double A){
  return( (1/mc(tiempo, m0, mf0, TSFC, E0)) * (E(tiempo, mf0, TSFC, E0) - fa(altura, CD, A)*velocidad*fabs(velocidad) - mc(tiempo, m0, mf0, TSFC, E0)*g(altura) ) );
}

int main(void){
  puts("Información de Ah Mun");
  printf("Empuje del cohete E0: %.2e\n", E0_AhMun);
  printf("Consumo especifico del empuje: %.2e\n", TSFC_AhMun);
  printf("Coeficiente de fomra CD: %.2e\n", CD_AhMun);
  printf("Seción transversal del cohete A: %.2e\n", A_AhMun);
  printf("Masa del propulsor m0: %.2e\n", m0_AhMun);
  printf("Masa inicial del combustible mf0: %.2e\n", mf0_AhMun);
  puts("");
  printf("Tiempo en agotar combustible: %.2e\n", mf0_AhMun/(TSFC_AhMun*E0_AhMun) );
  puts("");

  puts("Información de Ahau Kin");
  printf("Empuje del cohete E0: %.2e\n", E0_AhauKin);
  printf("Consumo especifico del empuje: %.2e\n", TSFC_AhauKin);
  printf("Coeficiente de fomra CD: %.2e\n", CD_AhauKin);
  printf("Seción transversal del cohete A: %.2e\n", A_AhauKin);
  printf("Masa del propulsor m0: %.2e\n", m0_AhauKin);
  printf("Masa inicial del combustible mf0: %.2e\n", mf0_AhauKin);
  puts("");
  printf("Tiempo en agotar combustible: %.2e\n", mf0_AhauKin/(TSFC_AhauKin*E0_AhauKin) );
  puts("");

  puts("Información de Chac");
  printf("Empuje del cohete E0: %.2e\n", E0_Chac);
  printf("Consumo especifico del empuje: %.2e\n", TSFC_Chac);
  printf("Coeficiente de fomra CD: %.2e\n", CD_Chac);
  printf("Seción transversal del cohete A: %.2e\n", A_Chac);
  printf("Masa del propulsor m0: %.2e\n", m0_Chac);
  printf("Masa inicial del combustible mf0: %.2e\n", mf0_Chac);
  puts("");
  printf("Tiempo en agotar combustible: %.2e\n", mf0_Chac/(TSFC_Chac*E0_Chac) );
  puts("");

  //La implementacion
  //no tengo idea de como no usar un metodo numerico
  //de entrada no se usa Euler, porque es de grado dos...

  //De hecho hay un (y')^2 :(

  //me interesa saber cuando V es 0

  //Es que eso de suponer V = at, mmmm es que solo funciona en aceleracion constante y esta no es constante no?

  //Pero dijimos algo como que a=v/t y v=h/t.
  //Probemos uno con Ah Mun

  double h_AhMun = 0.73; //es la atura inicial
  double v_AhMun = 0;
  double t_AhMun = 0;
  double a_AhMun = acel(t_AhMun, h_AhMun, v_AhMun, m0_AhMun, mf0_AhMun, TSFC_AhMun, E0_AhMun, CD_AhMun, A_AhMun);

  //Abre el archivo
  FILE *pf =fopen("Info_Ah_Mun","wt");
  
  double h_max_AhMun = h_AhMun;
  double aux;

  while(h_AhMun > 0){
    fprintf(pf,"%.2f\t%.2f\t%.2f\t%.2f\n",h_AhMun,v_AhMun,t_AhMun, a_AhMun);

    v_AhMun += a_AhMun*0.1;

    aux = h_AhMun;
    h_AhMun += v_AhMun*0.1;
    if( h_AhMun > aux)
      h_max_AhMun = h_AhMun;

    t_AhMun += 0.1;

    a_AhMun = acel(t_AhMun, h_AhMun, v_AhMun, m0_AhMun, mf0_AhMun, TSFC_AhMun, E0_AhMun, CD_AhMun, A_AhMun);
}
//cerrar archivo
  fclose(pf);


  //Y creo que los datos nada que ver... pero a ver...
  //Probemos uno con AhauKin
  double h_AhauKin = 0.73; //es la atura inicial
  double v_AhauKin = 0;
  double t_AhauKin = 0;
  double a_AhauKin = acel(t_AhauKin, h_AhauKin, v_AhauKin, m0_AhauKin, mf0_AhauKin, TSFC_AhauKin, E0_AhauKin, CD_AhauKin, A_AhauKin);

  //Abre el archivo
  FILE *pf2 =fopen("Info_Ahau_Kin","wt");
  
  double h_max_AhauKin = h_AhauKin;
  double aux2;

  while(h_AhauKin > 0){
    fprintf(pf2,"%.2f\t%.2f\t%.2f\t%.2f\n",h_AhauKin,v_AhauKin,t_AhauKin, a_AhauKin);

    v_AhauKin += a_AhauKin*0.1;

    aux2 = h_AhauKin;
    h_AhauKin += v_AhauKin*0.1;
    if( h_AhauKin > aux)
      h_max_AhauKin = h_AhauKin;

    t_AhauKin += 0.1;

    a_AhauKin = acel(t_AhauKin, h_AhauKin, v_AhauKin, m0_AhauKin, mf0_AhauKin, TSFC_AhauKin, E0_AhauKin, CD_AhauKin, A_AhauKin);
}
//cerrar archivo
  fclose(pf2);

  //Y creo que los datos nada que ver... pero a ver...
  //Probemos uno con Chac
  double h_Chac = 0.73; //es la atura inicial
  double v_Chac = 0;
  double t_Chac = 0;
  double a_Chac = acel(t_Chac, h_Chac, v_Chac, m0_Chac, mf0_Chac, TSFC_Chac, E0_Chac, CD_Chac, A_Chac);

  //Abre el archivo
  FILE *pf3 =fopen("Info_Chac","wt");
  
  double h_max_Chac = h_Chac;
  double aux3;

  while(h_Chac > 0){
    fprintf(pf3,"%.2f\t%.2f\t%.2f\t%.2f\n",h_Chac,v_Chac,t_Chac, a_Chac);

    v_Chac += a_Chac*0.1;

    aux3 = h_Chac;
    h_Chac += v_Chac*0.1;
    if( h_Chac > aux)
      h_max_Chac = h_Chac;

    t_Chac += 0.1;

    a_Chac = acel(t_Chac, h_Chac, v_Chac, m0_Chac, mf0_Chac, TSFC_Chac, E0_Chac, CD_Chac, A_Chac);
}
//cerrar archivo
  fclose(pf3);

  printf("Alturas máximas respectivas: %.2f, %.2f y %.2f.\n", h_max_AhMun, h_max_AhauKin, h_max_Chac);
  printf("Tiempos de vuelo respectivos (en minutos): %.2f, %.2f y %.2f.\n", t_AhMun/60, t_AhauKin/60, t_Chac/60);

  return 0;
}
