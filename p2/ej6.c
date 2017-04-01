/**

     @author David Sánchez
     @date 01/03/2017
     @file ej6.c
     @version 1.0
     @brief Programa que utilizando matrices dinámicas realice de manera
     secuencial las siguientes funciones

          · Reservar memoria para una matriz de ```nFilas x nColumnas```

          · Función que rellene una matriz con valores aleatorios en el intervalo
          [1,20]

          · Función que imprima una matriz por pantalla, que utilice la aritmética
          de punteros para recorrer la matriz

          · Función que devuelva un vector dinámico con los mínimos de cada colmna

          · Función que libere la memoria de la matriz

     El funcinamiento del programa será el siguiente:

          · Se iniciará la semilla para la generación de números aleatorios

          · Se le pedirá al usuario que introduzca el numero de filas además de
          el numero de columnas

          · Una vez obtenido los parámetros anteriores, se procederá a la reserva
          de memoria de ```nFil x nCol```

          · Se reservará tambien un vector llamado minimos cuya dimensión será
          nCol, que almacenará el minimo de cada columna

          · Una vez reservada la memoria para ```nFil x nCol```, rellenaremos la
          matriz de valores aleatorios pertenecientes al rango especificado

          · El siguiente paso será recorrer la matriz de manera que por cada
          iteracción de columna recorra todas las filas

          · Finalmente se devolverá dicho vector con los minimos de cada columna
          al main donde será imprimido por pantalla


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ej6headers.h"


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
