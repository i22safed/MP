#include <stdio.h>


void leerVector(int nEle, int *vector);
void mostrarVector(int nEle, int *vector);

int main(){


     int nEle;
     int vector[nEle];


     printf("Introduzca el número de elementos del vector: ");
     scanf("%i",&nEle);

     leerVector(nEle, vector);
     mostrarVector(nEle,vector);

     return 0;
}


void leerVector(int nEle, int *vector){

     int i=0;

     for(i=0;i<nEle;i++){

          printf("Introduce un valor para la posición %i del vector: ",i);
          scanf("%i",&vector[i]);

     }
}

void mostrarVector(int nEle, int *vector){

     int i=0;

     for(i=0;i<nEle;i++){

          printf("El valor para la posición %i del vector: ",vector[i]);
          printf("\n");

     }
}
