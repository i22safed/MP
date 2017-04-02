#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ej6headers.h"

int ** multiplicaMatriz(int ** matrizA, int ** matrizB, int nFilA, int nColA, int nFilB, int nColB);

int main(){

     int nFilA=0,nColA=0;
     int nFilB=0,nColB=0;
     int ** matrizA, **matrizB;
     int **  matrizResultado;

     printf("\nIntroduzca el numero de filas de la matriz A → ");
     scanf("%i",&nFilA);
     printf("\nIntroduzca el numero de columnas de la matriz A → ");
     scanf("%i",&nColA);
     printf("\nIntroduzca el numero de filas de la matriz B → ");
     scanf("%i",&nFilB);
     printf("\nIntroduzca el numero de columnas de la matriz B → ");
     scanf("%i",&nColB);


     if(nColA!=nFilA){

          printf("\nEl numero de columnas de A es distinto que el numero de filas de B");
          exit (-1);
     }

     matriz1 = reservarMemoria(nFil,nCol);
     matriz2 = reservarMemoria(nFil,nCol);

     rellenaMatriz(int ** matrizA, int nFilA, int nColA);
     rellenaMatriz(int ** matrizB, int nFilB, int nColB);

     printf("\nLa matriz A es : ");
     imprimeMatriz(int ** matrizA, int nFilA, int nColA);

     printf("\nLa matriz B es : ");
     imprimeMatriz(int ** matrizB, int nFilB, int nColB);

     matrizResultado = multiplicaMatriz( matrizA, matrizB, nFilA, nColA, nFilB, nColB);

     return 0;

}

int ** multiplicaMatriz(int ** matrizA, int ** matrizB, int nFilA, int nColA, int nFilB, int nColB){

     int i=0,j=0;
     int res=0;

     int ** matrizRes;
     reservarMemoria(nFilA,nColB);

     for(i=0;i<nFilA;i++){

          for(j=0;j<nColA;j++){

               res = res + matrizA[i][j]*matriz[j][i];

          }

     }

     return matrizRes;

}
