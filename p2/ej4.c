#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//PROTOTIPOS____________________________________________________

int ** reservarMemoria(int nFil, int nCol);
int * reservaVector(int nCol);
void rellenaMatriz(int ** matriz, int nFil, int nCol);
void imprimeMatriz(int ** matriz, int nFil, int nCol);
int * minCol(int ** matriz, int nFil, int nCol, int * minimos);
void imprimeVector(int * minimos, int nCol);
void liberarMemoria(int ** matriz, int nFil);


//MAIN__________________________________________________________

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

     liberarMemoria(matriz,nFil);

     return 0;
}

//FUNCIONES_____________________________________________________

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

void liberarMemoria(int ** matriz, int nFil){

     int i=0;

     for(i=0;i<nFil;i++){
          free(*(matriz+i));
     }
     free(matriz);
}
