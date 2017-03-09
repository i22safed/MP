/*************************************************************/
// Fichero: ppal.c
// Contiene la funcion "main()" del proyecto de la version 2.
// Los prototipos de las funciones y constantes que usa estan 
// declarados en el fichero "funcsvec.h"
/*************************************************************/ 

#include <stdio.h>
#include "funcsvec.h"

/******************************************************/

int main (void)
{
   int m [MAX];       // vector de trabajo

   /* Rellena completamente el vector m */

   llena_vector (m, MAX); 

   /* Muestra el vector m antes de ordenarlo */

   printf ("\n\nVector original (Antes de ordenar): \n\n");
   pinta_vector (m, MAX);

   /* Ordena el vector m */

   ordena_vector (m, MAX);

   /* Muestra el vector m despues de ordenarlo */

   printf ("\n\nVector final (Despues de ordenar): \n\n");
   pinta_vector (m, MAX);
   printf ("\n\n\n");

   return (0);
}

