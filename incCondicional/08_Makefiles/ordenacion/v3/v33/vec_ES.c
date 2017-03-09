/********************************************************************/
// Fichero: funcsvec.c
// Contiene la definicion de las funciones usadas por la 
//    funcion "main()" del proyecto de la version 2, ademas de 
//    las constantes locales a este modulo 
// MAX_LINE y MY_MAX_RAND. 
// Los prototipos estan declarados en el fichero "funcsvec.h"
/********************************************************************/

#include <stdlib.h>     // Para manejar nums. aleatorios
#include <time.h>       // Para fijar la semilla del generador de nums. aleat. 

#include "vec_ES.h"

#define MAX_LINE     10 // Numero de valores por linea
#define MY_MAX_RAND 100 // Nums. aleatorios entre 0 y 99



/********************************************************************/
// Funcion:  llena_vector  
// Tarea:    Rellena un vector de enteros con numeros aleatorios. 
// Recibe:   int *p, vector a rellenar 
//           int tope, numero de elementos del vector p 
// Devuelve: void 
//           p (referencia), vector con tope nums. aleat. 
/********************************************************************/

void llena_vector  (int *p, int tope) 
{

   time_t t;         // tipo definido en time.h
   register int i;
   
   srand ((int) time(&t)); // Fija la semilla del generador: 
                           // Inicializa el generador de numeros 
                           // aleatorios con el reloj del sistema  

   for (i=0; i<tope; i++, p++) 
      *p = rand () % MY_MAX_RAND;  // 0 <= *p <= MY_MAX_RAND-1
}

/********************************************************************/
// Funcion:  pinta_vector  
// Tarea:    Muestra (tabulado), un vector con MAX_LINE numeros 
//           por linea.
// Recibe:   int *p, vector a mostrar
//           tope, numero de elementos del vector 
// Devuelve: void
/********************************************************************/

void pinta_vector  (int *p, int tope) 
{
   register int i;

   printf ("\n\n");

   for (i=0; i<tope; i++, p++) 

      printf ("%5d%c", *p, (((i+1) % MAX_LINE) == 0 || i == tope-1)? '\n' : ' ');

   printf ("\n\n\n");
}

