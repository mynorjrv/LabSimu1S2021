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
//Por que con funcion? para hacerlo para los tres
//Va a crecer el codigo? posiblemente
double datosAhMun(char a[]){
  if( a == "E0" )
    return(3*pow(10, 7));
  if( a == "TSFC")
    return(3.248*pow(10, -4));
  if( a== "CD" )
    return(61.27);
  if( a== "A" )
    return(201.06);
  if( a== "m0" )
    return( 1.1*pow(10, 5));
  if( a== "mf0" )
    return(1.5*pow(10, 6));
}

double datosAhauKin(char a[]){
  if( a == "E0" )
    return(2.7*pow(10, 7));
  if( a == "TSFC")
    return(2.248*pow(10, -4));
  if( a== "CD" )
    return(61.27);
  if( a== "A" )
    return(201.06);
  if( a== "m0" )
    return( 1.1*pow(10, 5));
  if( a== "mf0" )
    return(1.5*pow(10, 6));
}


double datosChac(char a[]){
  if( a == "E0" )
    return(2.5*pow(10, 7));
  if( a == "TSFC")
    return(2.248*pow(10, -4));
  if( a== "CD" )
    return(70.25);
  if( a== "A" )
    return(215);
  if( a== "m0" )
    return(1.8*pow(10, 5));
  if( a== "mf0" )
    return(2.1*pow(10, 6));
}

/*
double dato(char a[], char b[]){
  if( a == "AhMun")
    return datosAhMun(b);
  if( a == "AhauKin")
    return datosAhauKin(b);
  if( a == "Chac")
    return datosChac(b);
}
*/

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

//pero por la separacion... toca definir una por cohete
//un gran clavo
//esto no funciono :(
//char nave[] = "AhMun";

//Esto no sirve, no funciona el dato(nave, "")
/*double mc(float tiempo){
  return( dato(nave, "m0") + dato(nave, "mf0") - dato(nave, "TSFC")*dato(nave, "E0")*tiempo );
}

//uso fa y no Fa porque no estoy incluyendo las derivadas
double fa(float yt){
  float retorno = (1/2)*rho(yt)*dato(nave, "CD")*dato(nave, "A");
  }*/
//Ya seee, para esto debi usar mejor variables...
//Pero bueno, estees el mc
//evalua si ya se paso el tiempo para que no me de masas negativas
double mc_AhMun(double tiempo){
  if( datosAhMun("mf0") - datosAhMun("TSFC")*datosAhMun("E0")*tiempo > 0)
    return( datosAhMun("m0") + datosAhMun("mf0") - datosAhMun("TSFC")*datosAhMun("E0")*tiempo);
  return( datosAhMun("m0") );
}

double E_AhMun(double tiempo){
  if( datosAhMun("mf0") - datosAhMun("TSFC")*datosAhMun("E0")*tiempo > 0)
    return( datosAhMun("E0"));
  return 0;
}

double fa_AhMun(double yt){
  return( (1/2)*rho(yt)*datosAhMun("CD")*datosAhMun("A") );
}

double acel(double mc, double E, double fa, double v, double y, double t){
  return( (1/mc)*(E - fa*v*fabs(v) - mc*g(y)) );
}

/*double acel(double tiempo, double altura, double velocidad, double m0, double mf0, double TSFC, double E0, double CD, double A){
  return( (1/mc(tiempo, m0, mf0, TSFC, E0)) * (E(tiempo, mf0, TSFC, E0) + fa(altura, CD, A)*velocidad*fabs(velocidad) + mc(tiempo, m0, mf0, TSFC, E0)*g(altura) )
}*/


int main(void){

  //char otranave[] = "AhMun";
  //printf("%e\n", dato(otranave, "m0"));
  //Aca solo imprimire los datos

  //El tiempo en agotar combustible se obtiene de la ecuacion mf
  //mf(t) = mf0 - TSFC*E0*t
  //el combustible se agota en mf = 0
  //por tanto t = mf0/(TSFC*E0)

  //Y supongo que esto pudo ser un bule :/
  puts("Información de Ah Mun");
  printf("Empuje del cohete E0: %.2e\n", datosAhMun("E0"));
  printf("Consumo especifico del empuje: %.2e\n", datosAhMun("TSFC"));
  printf("Coeficiente de fomra CD: %.2e\n", datosAhMun("CD"));
  printf("Seción transversal del cohete A: %.2e\n", datosAhMun("A"));
  printf("Masa del propulsor m0: %.2e\n", datosAhMun("m0"));
  printf("Masa inicial del combustible mf0: %.2e\n", datosAhMun("mf0"));
  puts("");
  printf("Tiempo en agotar combustible: %.2e\n", datosAhMun("mf0")/(datosAhMun("TSFC")*datosAhMun("E0")) );
  puts("");

  puts("Información de Ahau Kin");
  printf("Empuje del cohete E0: %.2e\n", datosAhauKin("E0"));
  printf("Consumo especifico del empuje: %.2e\n", datosAhauKin("TSFC"));
  printf("Coeficiente de fomra CD: %.2e\n", datosAhauKin("CD"));
  printf("Seción transversal del cohete A: %.2e\n", datosAhauKin("A"));
  printf("Masa del propulsor m0: %.2e\n", datosAhauKin("m0"));
  printf("Masa inicial del combustible mf0: %.2e\n", datosAhauKin("mf0"));
  puts("");
  printf("Tiempo en agotar combustible: %.2e\n", datosAhauKin("mf0")/(datosAhauKin("TSFC")*datosAhauKin("E0")) );
  puts("");

  puts("Información de Chac");
  printf("Empuje del cohete E0: %.2e\n", datosChac("E0"));
  printf("Consumo especifico del empuje: %.2e\n", datosChac("TSFC"));
  printf("Coeficiente de fomra CD: %.2e\n", datosChac("CD"));
  printf("Seción transversal del cohete A: %.2e\n", datosChac("A"));
  printf("Masa del propulsor m0: %.2e\n", datosChac("m0"));
  printf("Masa inicial del combustible mf0: %.2e\n", datosChac("mf0"));
  puts("");
  printf("Tiempo en agotar combustible: %.2e\n", datosChac("mf0")/(datosChac("TSFC")*datosChac("E0")) );
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
  double a_AhMun = acel( mc_AhMun(t_AhMun), E_AhMun(t_AhMun), fa_AhMun(h_AhMun), v_AhMun, h_AhMun, t_AhMun);

  FILE *pf =fopen("Info_Ah_Mun","wt");
  
  double h_max_ahmun = h_AhMun;
  double aux;

  while(h_AhMun > 0){
    fprintf(pf,"%.2f\t%.2f\t%.2f\t%.2f\n",h_AhMun,v_AhMun,t_AhMun, a_AhMun);

    v_AhMun += a_AhMun*0.1;

    aux = h_AhMun;
    h_AhMun += v_AhMun*0.1;
    if( h_AhMun > aux)
      h_max_ahmun = h_AhMun;

    t_AhMun += 0.1;

    a_AhMun = acel( mc_AhMun(t_AhMun), E_AhMun(t_AhMun), fa_AhMun(h_AhMun), v_AhMun, h_AhMun, t_AhMun);
}
    
//cerrar archivo
  fclose(pf);

  return 0;
}
