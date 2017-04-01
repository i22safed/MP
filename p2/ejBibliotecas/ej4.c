#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"


int main (){

     srand(time(NULL));
     int nFil=0 , nCol=0;
     int ** matriz=NULL;
     int * minimos=NULL;


     printf("Introduzca el numero de filas: ");
     scanf("%i",&nFil);
     printf("Introduzca el numero de columnas: ");
     scanf("%i",&nCol);

     matriz=reservarMemoria(nFil,nCol);
     minimos=reservaVector(nCol);

     rellenaMatriz(matriz,nFil,nCol);

     printf("\n\nLa matriz es: \n");
     imprimeMatriz(matriz,nFil,nCol);

     minimos = minCol(matriz,nFil,nCol,minimos);

     printf("El vector con los minimos de cada columna es → ");
     imprimeVector(minimos,nCol);

     liberarMemoria(&matriz,nFil);

     return 0;
}




