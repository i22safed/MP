/*
Codifica un programa denominado vector.c que usando funciones de aritmetica de
punteros:

     · Lea un vector de elementos de tipo double (leerVector)
     · Imprima los datos del vector por pantalla (escribeVector)
     · Sume los elementos mayores que cero (sumaPositivos)


     FUNCIONA SOLO PARA 2 ELEMENTOS , CORREGIR !!

*/

#include <stdio.h>

void leerVector(int nEle, double *vector);
void escribeVector(int nEle, double *vector);

int main(){

     int nEle;
     double vector[nEle];

     printf("Introduzca el numero de elementos del vector: ");
     scanf("%i", &nEle);

     leerVector(nEle, vector);

     escribeVector(nEle, vector);


     return 0;
}

void leerVector(int nEle, double *vector){

     int i=0;
     double valor = 0;

     for(i=0;i<nEle;i++){

          printf("Introduce un numero para la pos. %i: ", i );
          scanf("%lf", &valor);
          *(vector+i)=valor;

     }
}

void escribeVector(int nEle, double *vector){

     int i=0;
     double aux = 0;

     for(i=0;i<nEle;i++){

          printf("El valor del vector en la posicion %i es → %lf\n",i,(*vector+i));
     }


}
