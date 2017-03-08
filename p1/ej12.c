#include <stdio.h>
#include <stdlib.h>      // Para rand()
#include <time.h>        // Para time()

/*

12. Un proyecto informático requiere trabajar con vectores de números enteros
generados de manera aleatoria. Para hacer más rápido el acceso han decidido
crear dos índices que les permitan recorrer solamente las potencias de 2 o los
elementos impares. Un índice, es un vector de punteros, que almacena la dirección
de los elementos que se quieren recorrer. Escribe un programa que:

     ·Rellene un vector de enteros con números aleatorios (en un rango fijado
     por el usuario).
     ·Imprima el vector completo.
     ·Cree un índice con las direcciones de los elementos impares del vector
     original.
     ·Cree un índice con las direcciones de los divisibles por 3 que hay en el
     vector original.
     ·Imprima, usando los índices, los elementos impares y los divisibles por 3.

Para ello, implementa, al menos, las siguiente funciones: rellenarVectorAleatorio,
imprimirVector, crearndiceImpares, crearIndicesPotencias, imprimeIndice.

*/

void rellenaVectorAleatorio(int nEle,int * rango,int * vector);
void imprimeVector(int nEle, int * vector);
void crearIndiceImpares(int nEle, int * vector, int * vectorImpares);
void crearIndicesPotencias(int nEle, int * vector, int * vectorPotencias);
void imprimeIndice(int nEle, int * vector, int * vectorImpares, int * vectorPotencias);


int main (){

     int rango[1], nEle;
     srand(time(NULL));



     // Pedimos numero de elementos del vector
     printf("Introduzca el numero de elementos del vector: ");
     scanf("%i", &nEle);

     int vector[nEle];
     int vectorImpares[nEle];
     int vectorPotencias[nEle];

     // Pedimos rango
     printf("Introduzca el rango minimo: ");
     scanf("%i",&rango[0]);
     printf("Introduzca el rango maximo: ");
     scanf("%i",&rango[1]);


     // Rellenamos vector de numeros aleatorios
     rellenaVectorAleatorio(nEle,rango,vector);

     // Imprimimos el vector
     imprimeVector(nEle,vector);

     // Creamos los indices de los impares
     crearIndiceImpares(nEle, vector, vectorImpares);

     // Creamos los indices de las potencias
     crearIndicesPotencias(nEle,vector,vectorPotencias);

     // Imprimimos las potencias 
     imprimeIndice(nEle,vector,vectorImpares,vectorPotencias);

     return 0;
}


void rellenaVectorAleatorio(int nEle,int * rango,int * vector){

     int i=0;
     int nAle=0;

     for(i=0; i<nEle; i++){

          nAle = rand () % (rango[1]-rango[0]+1) + rango[0];
          vector[i] = nAle;

     }

}

void imprimeVector(int nEle, int * vector){

     int i=0;

     printf("\nLos elementos del vector son → ");
     for(i=0; i<nEle; i++){

          printf("%i ", vector[i]);

     }

     printf("\n\n");

}

void crearIndiceImpares(int nEle, int * vector, int * vectorImpares){

     int i=0,j=0;

     for(i=0; i<nEle; i++){

          if((vector[i]%2)!=0){
               vectorImpares[j]=i;
               j++;
          }

     }

}
void crearIndicesPotencias(int nEle, int * vector, int * vectorPotencias){

     int i=0 , j=0;

     for(i=0; i<nEle; i++){

          if((vector[i]%3)==0){

               vectorPotencias[j]=i;
               j++;

          }
     }
}

void imprimeIndice(int nEle, int * vector, int * vectorImpares, int * vectorPotencias){

     int i=0;

     printf("\nLos elementos impares del vector → ");

     for(i=0;i<nEle;i++){

      
          printf("%i ",vector[vectorImpares[i]]);
          

     }

     printf("\nLos elementos potencias de 3 del vector → ");

     for(i=0;i<nEle;i++){

      
          printf("%i ",vector[vectorPotencias[i]]);
          

     }


}
