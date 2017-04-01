#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ej6headers.h"
/**

     @author David Sánchez
     @date 01/03/2017
     @file ej6func.c
     @brief Fichero de funciones del ej6.c

*/

/**

     @fn int ** reservarMemoria(int nFil, int nCol)
     @param int nFil → Especifica el numero de filas que va a poseer la matriz
     @param int nCol → Especifica el numero de columnas que va a poseer la matriz
     @return matriz → Una matriz reservada de nFil x nCol
     @post N/A
     @pre nFil > 0 y nCol > 0
     @brief Función cuyo objetivo es reservar memoria para una matriz de nFil x nCol.
     Inicialmente se reserva para el número de filas en:

          ```M = (int **)malloc(nFil*sizeof(int*));```

     Para luego reservar en cada fila nCol elementos

*/


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

/**

     @fn int * reservaVector(int nCol)
     @param int nCol → Especifica el numero de columnas de la matriz
     @return v → Vector reservado dinamicamente
     @post N/A
     @pre nCol > 0
     @brief Reserva tantos elementos como columnas tenga la matriz original

*/


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

/**

     @fn void rellenaMatriz(int ** matriz, int nFil, int nCol)
     @param int ** matriz → Matriz original
     @param int nFil → Especifica el numero de filas de la matriz
     @param int nCol → Especifica el numero de columnas de la matriz
     @return N/A (tipo void)
     @post N/A
     @pre nFil && nCol > 0 y la reserva de la matriz != NULL
     @brief Función cuyo objetivo es recorrer la matriz por filas y columnas
     rellenando con valores aleatorios cada posición

*/

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

/**

     @fn void imprimeMatriz(int ** matriz, int nFil, int nCol)
     @param int ** matriz → Matriz original
     @param int nFil → Especifica el numero de filas de la matriz
     @param int nCol → Especifica el numero de columnas de la matriz
     @return N/A (tipo void)
     @post N/A
     @pre nFil && nCol > 0 y la reserva de la matriz != NULL
     @brief Imprime la en cuestión matriz por pantalla

*/



void imprimeMatriz(int ** matriz, int nFil, int nCol){

     int i=0,j=0;

     for(i=0;i<nFil;i++){

          for(j=0;j<nCol;j++){


               printf("%i ",*(*(matriz+i)+j));

          }

          printf("\n");
     }

}

/**

     @fn int * minCol(int ** matriz, int nFil, int nCol, int * minimos)
     @param int ** matriz → Matriz original
     @param int nFil → Especifica el numero de filas de la matriz
     @param int nCol → Especifica el numero de columnas de la matriz
     @param int * minimos → vector que almacena el minimo de cada columna
     @return minimos → Vector con los minimos de cada columna
     @post
     @pre nFil && nCol > 0 y la reserva de la matriz != NULL
     @brief Recorremos la matriz de manera tal que por cada iteración de columna
     se recorra todas las filas comprobando en cada columna el menor elemento.
     Finalmente se devolverá un vector con cada minimo de cada columna

*/

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

/**

     @fn void imprimeVector(int * minimos, int nCol)
     @param int * minimos → Vector con los minimos de cada columna
     @param int nCol → Especifica el numero de columnas de la matriz
     @return N/A (tipo void)
     @post N/A
     @pre N/A
     @brief Imprime el vector con los minimos de cada columna por pantalla

*/

void imprimeVector(int * minimos, int nCol){


     int i=0;

     for(i=0;i<nCol;i++){

          printf("%i ", *(minimos+i));

     }

     printf("\n");

}

/**

     @fn void liberarMemoria(int ** matriz, int nFil)
     @param int ** matriz → Matriz original
     @param int nFil → Especifica el numero de filas de la matriz
     @return N/A (tipo void)
     @post N/A
     @pre N/A
     @brief Funcion que libera memoria por filas de la matriz

*/

void liberarMemoria(int ** matriz, int nFil){

     int i=0;

     for(i=0;i<nFil;i++){
          free(*(matriz+i));
     }
     free(matriz);
}
