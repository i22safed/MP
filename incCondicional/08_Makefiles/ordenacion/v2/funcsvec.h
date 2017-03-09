/********************************************************************/
// Fichero: funcsvec.h
// Contiene los prototipos de las funciones usadas por la funcion 
// "main()" del proyecto de la version 2, asi como la definicion de 
// la constante MAX. 
/********************************************************************/

#ifndef FUNCSVEC
#define FUNCSVEC

#define MAX          25 // Tamanio del vector

/********************************************************************/
// Funcion:  llena_vector  
// Tarea:    Rellena un vector de enteros con numeros aleatorios. 
// Recibe:   int *p, vector a rellenar 
//           int tope, numero de elementos del vector p 
// Devuelve: void 
//           p (referencia), vector con tope nums. aleat. 
/********************************************************************/

void llena_vector  (int *p, int tope); 

/********************************************************************/
// Funcion:  pinta_vector  
// Tarea:    Muestra (tabulado), un vector con MAX_LINE nums. por linea.
// Recibe:   int *p, vector a mostrar
//           tope, numero de elementos del vector 
// Devuelve: void
/********************************************************************/

void pinta_vector  (int *p, int tope); 

/********************************************************************/
// Funcion: ordena_vector 
// Tarea:    Ordena un vector de forma ascendente (burbuja) 
// Recibe:   int *p, vector a ordenar
//           tope, numero de elementos del vector 
// Devuelve: void 
//           p (referencia), vector p ordenado. 
/********************************************************************/

void ordena_vector (int *p, int tope); 

#endif
