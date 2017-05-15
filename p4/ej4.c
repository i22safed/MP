#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct lista{

     int a, e;
     struct lista * siguiente;

};
struct lista * nuevoElemento();
void insertarDelante(struct lista ** cabeza, int a, int e);
void imprimirLista(struct lista * cabeza);
void borrarElemento(struct lista ** cabeza, int e);
float evaluarPolinomio(struct lista * cabeza, float x);



int main(){

     int nMonomios = 0, a=0, e=0, i=0;
     float suma = 0, x = 0;

     struct lista * cabeza = NULL;

     printf("\nIntroduzca el numero de monomios del polinomio → ");
     scanf("%i",&nMonomios);
     printf("\n");



     for(i=0;i<nMonomios;i++){

          printf("Introduzca un valor para la base[%i] → ",i);
          scanf("%i",&a);
          printf("Introduzca un valor para el exponente[%i] → ",i);
          scanf("%i",&e);
          insertarDelante(&cabeza,a,e);

     }

     imprimirLista(cabeza);

     printf("\nIntroduzca un numero para borrar el monomio → ");
     scanf("%i",&e);
     borrarElemento(&cabeza,e);

     printf("\nSe han borrado los monomios cuyo exponente era 2\n");
     imprimirLista(cabeza);

     printf("\nValor de X\t\tEvalución de polinomio\n");
     printf("----------------------------------------------\n");

     for(i=0;i<20;i++){

          suma = evaluarPolinomio(cabeza,x);
          printf("%.1f\t→\t%.3f\n",x,suma);
          x = x + 0.5;

     }

     printf("\n");




     return 0;
}


struct lista * nuevoElemento(){

     return ((struct lista *)malloc(sizeof(struct lista)));

}

void insertarDelante(struct lista ** cabeza, int a, int e){

     struct lista * nuevo;

     nuevo = nuevoElemento();
     nuevo->a = a;
     nuevo->e = e;

     nuevo->siguiente = *cabeza;
     *cabeza = nuevo;

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

void borrarElemento(struct lista ** cabeza, int e){

     struct lista * anterior = NULL;
     struct lista * aux = NULL;
     int match = 0;

     aux = *cabeza;

     while(aux->e != e){

          anterior = aux;
          aux = aux->siguiente;

     }

     if(aux == *cabeza){

          *cabeza = aux->siguiente;
          free(aux);

     }else{

          anterior->siguiente = aux->siguiente;
          free(aux);

     }

}

float evaluarPolinomio(struct lista * cabeza, float x){

     struct lista * aux = NULL;
     aux = cabeza;
     float suma = 0;

     while(aux != NULL){

          suma = suma + aux->a*(pow(x,aux->e));
          aux = aux->siguiente;

     }

     return suma;

}
