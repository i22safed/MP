/*

     Un programa de C contiene las siguientes sentencias
          int i, j = 25;
          int *pi, *pj = &i;
          *pj = j + 5;
          i = *pj + 5;
          pi = pj;
          *pi = i + j;

     Si el valor asignado a i empieza en la dirección F9C (hexadecimal) y el valor asignado a j empieza
     en FE9 entonces:

          a) ¿Qué valor es representado por &i?
          b) ¿Qué valor es representado por &j?
          c) ¿Qué valor es asignado a pj?
          d) ¿Qué valor es asignado a *pj?
          e) ¿Qué valor es asignado a i?
          f) ¿Qué valor es representado por pi?
          g) ¿Qué valor es asignado a *pi?
          h) ¿Qué valor es representado por la expresión (*pi + 2)?

*/

#include <stdio.h>

int main (){

     int i, j = 25;           // Declara 2 variables y a j le asigna 25
     int *pi, *pj = &i;       // Declara 2 punteros asignandole a *pj la
                              // la referencia de i
     *pj = j + 5;             // A *pj le asigna 25 + 5
     i = *pj + 5;             // A i le asigna 30 + 5
     pi = pj;                 // pi posee el valor de pj
     *pi = i + j;             // El puntero de pi guarda 35 + 25

     printf("Valor de i: %i \n",i);
     printf("Valor de j: %i \n",j);
     printf("Valor de pi: %i \n",pi);
     printf("Valor de pj: %i \n",pj);



     return 0;
}
