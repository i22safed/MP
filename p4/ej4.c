#include <stdio.h>
#include <stdlib.h>

struct lista{

     int a, e;
     struct lista * siguiente;

};
struct lista * nuevoElemento();
void insertarDetras(struct lista ** cabeza, int a, int e);
void imprimirLista(struct lista * cabeza);


int main(){

     int nMonomios = 0, a=0, e=0, i=0;

     struct lista * cabeza = NULL;

     printf("Introduzca el numero de monomios del polinomio → ");
     scanf("%i",&nMonomios);


     for(i=0;i<nMonomios;i++){

          printf("Introduzca un valor para la base[%i] → ",i);
          scanf("%i",&a);
          printf("Introduzca un valor para el exponente[%i] → ",i);
          scanf("%i",&e);
          insertarDetras(&cabeza,a,e);

     }

     imprimirLista(cabeza);

     return 0;
}




struct lista * nuevoElemento(){

     return ((struct lista *)malloc(sizeof(struct lista)));

}

void insertarDetras(struct lista ** cabeza, int a, int e){

     struct lista * nuevo = NULL;
     struct lista * aux = NULL;

     nuevo = nuevoElemento();

     nuevo->a = a;
     nuevo->e = e;
     nuevo->siguiente = NULL;

     if(*cabeza==NULL){

          *cabeza = nuevo;

     }else{

          aux = *cabeza;

          while(aux->siguiente!=NULL){

               aux = aux->siguiente;

          }

          aux->siguiente = nuevo;

     }

}

void imprimirLista(struct lista * cabeza){

     struct lista * aux = NULL;
     aux = cabeza;

     printf("\nEl polinomio es → ");

     while(aux != NULL){

          if((aux->a)>0){

               printf("+ %i^%i ",aux->a,aux->e);

          }else{

               printf("- %i^%i ",aux->a,aux->e);

          }


          aux = aux->siguiente;

     }

     printf("\n");

}
