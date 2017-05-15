#include <stdio.h>
#include <stdlib.h>

/*

     Declarar el tipo de dato y el puntero de cabeLa o primero

     Asignar memoria para un elemento del tipo definido anteriormente
     utilizando alguna de las funciones de asignación de memoria
     (mallloc () , calloc (), realloc ())

     Crear iterativamente el primer elemento (cabeza) y los elementos
     sucesivos de una lista enlazada simplemente.

     Repetir hasta que no haya más entrada para el elemento.

*/

struct lista{

     int n;
     struct lista * siguiente;

};

struct lista * nuevoElemento();
void insertarDelante(struct lista ** cabeza, int num);
void imprimirLista(struct lista * cabeza);
void borrarLista(struct lista ** cabeza);

int main(){

     int num;
     struct lista * cabeza = NULL;       // Lista vacia

     printf("\nIntroduzca el nuevo elemento para insertar → ");
     scanf("%i",&num);

     insertarDelante(&cabeza,num);

     printf("\nIntroduzca el nuevo elemento para insertar → ");
     scanf("%i",&num);

     insertarDelante(&cabeza,num);

     printf("\nIntroduzca el nuevo elemento para insertar → ");
     scanf("%i",&num);

     insertarDelante(&cabeza,num);
     imprimirLista(cabeza);
     borrarLista(&cabeza);

     if(cabeza == NULL){

          printf("\nLa lista está vacia\n");

     }else{

          printf("\nLa lista contiene elementos\n");

     }


     return 0;
}

struct lista * nuevoElemento(){

     return ((struct lista *)malloc(sizeof(struct lista)));

}
void insertarDelante(struct lista ** cabeza, int num){

     struct lista * nuevo;

     nuevo = nuevoElemento();
     nuevo->n = num;

     nuevo->siguiente = *cabeza;
     *cabeza = nuevo;

}

void borrarElemento

void imprimirLista(struct lista * cabeza){

     struct lista * aux = NULL;
     int i = 0;
     aux = cabeza;

     while(aux != NULL){

          printf("Elemento %i: %i\n",i,aux->n);
          i++;
          aux = aux->siguiente;

     }

}

void borrarLista(struct lista ** cabeza){

     struct lista *  aux, * sig;

     aux = * cabeza;

     while(aux!=NULL){

          sig = aux->siguiente;
          free(aux);
          aux = sig;

     }

     * cabeza = NULL;

}
