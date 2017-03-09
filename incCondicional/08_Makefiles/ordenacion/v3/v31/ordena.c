/********************************************************************/
// Funcion: ordena_vector 
// Tarea:    Ordena un vector de forma ascendente (burbuja) 
// Recibe:   int *p, vector a ordenar
//           tope, numero de elementos del vector 
// Devuelve: void 
//           p (referencia), vector p ordenado. 
/********************************************************************/
#include "ordena.h"

void ordena_vector (int *p, int tope) 
{
   int i, j;

   // La funcion "swap()" solo se usa en "ordena_vector()", 
   // por eso su declaracion se encuentra dentro de la definicion 
   // de "ordena_vector()" 
 
   void swap (int *, int *);  

   for (i=0; i<tope-1; i++)
      for (j=0; j<tope-1; j++)
         if (*(p+j) > *(p+j+1))
            swap (p+j, p+j+1);

}

/********************************************************************/
// Funcion: swap  
// Tarea:   Intercambia los valores de dos variables enteras
// Recibe:  int *a, direccion de a
//          int *b, direccion de b  
// Devuelve: void
//           a y b (referencia)
/********************************************************************/

void swap (int *a, int *b) 
{
   int tmp;
 
   tmp = *a;
   *a = *b;
   *b = tmp;
}

