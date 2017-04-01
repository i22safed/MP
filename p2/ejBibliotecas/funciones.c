#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"


int ** reservarMemoria(int nFil, int nCol){

     int ** M;
     int i, j, error=0;

     M = (int **)malloc(nFil*sizeof(int*));

     for(i=0; i<nFil;i++){

          M[i]=(int *)malloc(nCol*sizeof(int));

     }

     printf("\nLa memoria para la matriz de %ix%i ha sido reservada correctamente\n",nFil,nCol);
     return (M);

}

int * reservaVector(int nCol){					// No utilizamos referencia

	int * v;

	if((v=(int*)calloc(nCol,sizeof(int)))==NULL){

		printf("\nError en la reserva de memoria\n");
		exit(-1);

	}else{

		printf("\nLa reserva para %i elementos se ha realizado correctamente", nCol);
	}

	return (v);

}

void rellenaMatriz(int ** matriz, int nFil, int nCol){

     int i=0, j=0;
     int nAle=0;


     for(i=0;i<nFil;i++){


          for(j=0;j<nCol;j++){

               nAle = rand () % (20-1+1) + 1;
               *(*(matriz+i)+j)=nAle;

          }
     }
}

void imprimeMatriz(int ** matriz, int nFil, int nCol){

     int i=0,j=0;

     for(i=0;i<nFil;i++){

          for(j=0;j<nCol;j++){


               printf("%i ",*(*(matriz+i)+j));

          }

          printf("\n");
     }

}

int * minCol(int ** matriz, int nFil, int nCol, int * minimos){

     int i=0, j=0;
     int minimo=20;

     for(j=0;j<nCol;j++){

          for(i=0;i<nFil;i++){

               if((*(*(matriz+i)+j))<=minimo){

                    minimo = (*(*(matriz+i)+j));

               }
          }

          *(minimos+j)=minimo;
          minimo = 20;

     }

     return (minimos);
}

void imprimeVector(int * minimos, int nCol){


     int i=0;

     for(i=0;i<nCol;i++){

          printf("%i ", *(minimos+i));

     }

     printf("\n");

}

void liberarMemoria(int *** matriz, int nFil){

     int i=0;

     for(i=0;i<nFil;i++){
          free(*(matriz+i));
     }
}
