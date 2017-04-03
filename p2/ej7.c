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


     if(nColA!=nFilB){

          printf("\nEl numero de columnas de A es distinto que el numero de filas de B");
          exit (-1);
     }

     matrizA = reservarMemoria(nFilA,nColA);
     matrizB = reservarMemoria(nFilB,nColB);

     rellenaMatriz( matrizA, nFilA, nColA);
     rellenaMatriz( matrizB, nFilB, nColB);

     printf("\nLa matriz A es : \n");
     imprimeMatriz(matrizA,nFilA,nColA);

     printf("\nLa matriz B es : \n");
     imprimeMatriz(matrizB,nFilB,nColB);

     matrizResultado = multiplicaMatriz( matrizA, matrizB, nFilA, nColA, nFilB, nColB);

     printf("\nLa matriz resultante es: \n");
     imprimeMatriz(matrizResultado,nFilA,nColB);

     liberarMemoria(matrizA,nFilA);
     liberarMemoria(matrizB,nFilB);


     return 0;

}

int ** multiplicaMatriz(int ** matrizA, int ** matrizB, int nFilA, int nColA, int nFilB, int nColB){

     int i=0,j=0,k=0;
     int res=0;

     int ** matrizRes;
     matrizRes = reservarMemoria(nFilA,nColB);


       for(i=0;i<nFilA;i++){
           for(j=0;j<nColB;j++){
               matrizRes[i][j]=0;
               for(k=0;k<nColA;k++){
                   matrizRes[i][j]=(matrizRes[i][j]+(matrizA[i][k]*matrizB[k][j]));
               }
           }
       }

     return matrizRes;

}

/*

     Matriz A       Matriz B       MatrizRes

     2x3            3x2            2x2


     Iteraciones → nFilA x nColA

     1ra Iteracion       [0][0] * [0][0]         2ra Iteracion       [0][0] * [0][1]
                         [0][1] * [1][0]                             [0][1] * [1][1]
                         [0][2] * [2][0]                             [0][2] * [2][1]

     fila 0 x columna 0 → pos [0][0]              fila 0 columna 1 → pos [0][1]


     3ra Iteracion       [1][0] * [0][0]         4ra Iteracion       [1][0] * [0][1]
                         [1][1] * [1][0]                             [1][1] * [1][1]
                         [1][2] * [2][0]                             [1][2] * [2][1]

     fila 1 x columna 0 → pos [1][0]              fila 1 columna 1 → pos [1][1]


     · Algoritmo

          for(i=0;i<nFilA;i++){
              for(j=0;j<nColB;j++){
                  matrizRes[i][j]=0;
                  for(k=0;k<nColA;k++){
                      matrizRes[i][j]=(matrizRes[i][j]+(matrizA[i][k]*matrizB[k][j]));
                  }
              }
          }




*/
