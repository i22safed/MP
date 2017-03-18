#include <stdio.h>
#include <stdlib.h>


void reservarMemoriaVector(int nEle, int ** vector);
void rellenarVector(int nEle, int * vector);
void imprimeVector(int nEle, int * vector);
void mayorMenorVector(int nEle, int num, int * vector, int * mayor, int * menor, int * mayores, int * menores);

// Pasados por referencia


int main (){

     // Declaraciones de varibales
     int nEle = 0, num=0;
     int * vector = NULL, * mayores = NULL, * menores = NULL;
     int mayor, menor;

     // Entrada de los datos iniciales
     printf("Introduzca el numero de elementos del vector → ");
     scanf("%i", &nEle);
     printf("Introduzca un numero → ");
     scanf("%i",&num);

     // Funciones de reserva y E/S
     reservarMemoriaVector(nEle, &vector);
     rellenarVector(nEle, vector);
     // imprimeVector(nEle, vector);


     // Funciones de obtencion del numero de mayores y menores y sus respectivas
     // funciones de reserva
     mayorMenorVector(nEle,num,vector,&mayor,&menor,mayores,menores);

     // Imprimimos el vector original
     printf("El numero de elementos son → %i ", nEle );
     printf("Los elemetos del vector original son → ");
     imprimeVector(nEle,vector);



     return 0;
}


void reservarMemoriaVector(int nEle, int ** vector){      // Reserva por ref

     if((*vector=(int *)calloc(nEle, sizeof(int)))==NULL){

          printf("\nNo ha sido posible la reserva de memoria\n");
          exit (-1);

     }

     printf("\nReserva de memoria realizada correctamente\n");

}

void rellenarVector(int nEle, int * vector){

     int i=0;

     for(i=0;i<nEle;i++){

          printf("\nIntroduzca un elemento para la pos. %d → ",i);
          scanf("%i", (vector+i));
     }
}

void mayorMenorVector(int nEle, int num, int * vector, int * mayor, int * menor, int * mayores, int * menores){

     int i=0,j=0,k=0;

     // Obtenemos primeramente el numero de mayores y menores para la reserva

     for(i=0;i<nEle;i++){

          if(*(vector+i) < num ){
               *menor = *menor + 1;
          }
     }

     *mayor = nEle - *menor;

     // Reservamos memoria para los vectores de mayor y menor

     reservarMemoriaVector(*mayor,&mayores);
     reservarMemoriaVector(*menor,&menores);

     for(i=0;i<nEle;i++){

          if(*(vector+i) < num ){

               *(menores+j) = *(vector+i) ;
               j++;

          }else{

               *(mayores+k) = *(vector+i);
               k++;

          }
     }

}


void imprimeVector(int nEle, int * vector){

     int i=0;

     printf("Los elemetos del vector son → ");

     for(i=0;i<nEle;i++){

          printf("%i ", vector[i]);

     }

     printf("\n");

}
