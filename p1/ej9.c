#include <stdio.h>

struct polinomio{

     int coeficiente;
     int grado;

};
void leerMonomio(struct polinomio *pol);
void imprimirMonomio(struct polinomio *pol);
void gradoMaxMin();



int main(){

     struct polinomio pol;
     int terminos;

     struct polinomio vector[terminos];

     leerMonomio(&pol);
     imprimirMonomio(&pol);

     return 0;
}



void leerMonomio(struct polinomio *pol){

     printf("Introduzca un valor del coeficiente: ");
     scanf("%d", &pol->coeficiente);

     printf("Introduzca un valor de grado: ");
     scanf("%d", &pol->grado);


}

void imprimirMonomio(struct polinomio *pol){

     printf("%dx^%d \n", pol->coeficiente, pol->grado);

}

void gradoMaxMin(){




}
