#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pol1(int x);
float pol2(int x);
float pol3(int x);

int main(){


     // Variables iniciales
     int n = 0, op = 0;
     // Variables para funciones
     float res = 0, inc = 0, i = 0;
     // Puntero a funcion
     float (*pf)(int);

     printf("\nIntroduzca el valor de N → ");
     scanf("%i",&n);

     printf("\nIntroduzca la función a evaluar: \n");
     printf("\n1. f(x) = 3e^x - 2x");
     printf("\n2. g(x) = -x * sin(x) + 1.5");
     printf("\n3. z(x) = x^3 - 2x + 1\n");
     printf("\nLa opcion elegida es → ");
     scanf("%i",&op);

     switch (op) {
          case 1:

               printf("\nPara un valor de N → %i \n",n);
               printf("\nValor de x\tValor de f(x)\n");

               i = 0;

               while(i<n){

                    pf = &pol1;
                    printf("\n%.1f\t\t%.3f",i,(*pf)(i));
                    i = i + 0.2;

               }

               printf("\n");


          break;
          case 2:

               printf("\nPara un valor de N → %i \n",n);
               printf("\nValor de x\tValor de f(x)\n");

               i = 0;

               while(i<n){

                    pf = &pol2;
                    printf("\n%.1f\t\t%.3f",i,(*pf)(i));
                    i = i + 0.2;

               }

               printf("\n");


          break;
          case 3:

               printf("\nPara un valor de N → %i \n",n);
               printf("\nValor de x\tValor de f(x)\n");

               i = 0;

               while(i<n){

                    pf = &pol3;
                    printf("\n%.1f\t\t%.3f",i,(*pf)(i));
                    i = i + 0.2;

               }

               printf("\n");


          break;
     }


     return 0;

}

float pol1(int x){

     return (3*pow(2.7182,x)-2*x);

}


float pol2(int x){

     return (-x * sin(x) + 1.5);

}

float pol3(int x){

     return (pow(x,3) - 2*x + 1);

}
