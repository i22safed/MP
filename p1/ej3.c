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

            Representa el comienzo de la variable i

          b) ¿Qué valor es representado por &j?

            Representa el comienzo de la variable j

          c) ¿Qué valor es asignado a pj?

            El valor asignado es uno aleatorio, que cambia en cada ejecución
            del programa

          d) ¿Qué valor es asignado a *pj?

            Introduce mediante el operador de contenido la suma de i y j, es
            decir, introduce el valor 60

          e) ¿Qué valor es asignado a i?

            A la variable i se le asigna el contenido de pj + 5

          f) ¿Qué valor es representado por pi?

            Valor asignado aleatorio ya que no ha sido inicializado

          g) ¿Qué valor es asignado a *pi?

            Contenido de la direccion de pi

          h) ¿Qué valor es representado por la expresión (*pi + 2)?

            El contenido de pi + 2

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

     printf("Valor de &i: %p \n", &i);
     printf("Valor de &j: %p \n", &j);

     printf("Valor de pj: %i \n", pj);
     printf("Valor de *pj: %i \n", *pj);

     printf("Valor de i: %i \n", i);

     printf("Valor de pi: %i \n", pi);
     printf("Valor de *pi: %i \n", *pi);

     printf("Valor de (*pi+2): %i \n", (*pi+2));

     return 0;
}
