/*
Codifica un programa denominado vector.c que usando funciones de aritmetica de
punteros:

     · Lea un vector de elementos de tipo double (leerVector)
     · Imprima los datos del vector por pantalla (escribeVector)
     · Sume los elementos mayores que cero (sumaPositivos)

*/

#include <stdio.h>

void leerVector(int nEle, double *vector);
void escribeVector(int nEle, double *vector);
void sumaPositivos(int nEle, double *vector, double *suma);

int main(){

     int nEle;
     double suma=0;

     printf("Introduzca el numero de elementos del vector: ");
     scanf("%d", &nEle);

     double vector[nEle];

     leerVector(nEle, vector);

     escribeVector(nEle, vector);

     sumaPositivos(nEle, vector, &suma);

     printf("Suma de todos los elemetos positivos del vecto → %lf\n", suma);


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

          printf("El valor del vector en la posicion %i es → %lf\n",i,(*(vector+i)));

     }


}

void sumaPositivos(int nEle, double *vector, double *suma){

     int i=0;
     double aux=0;

     for(i=0;i<nEle;i++){

          aux=*(vector+i);

          if(aux>=0){
               *suma = *suma + aux;
          }

     }

}
