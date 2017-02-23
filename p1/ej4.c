/*

4.  Un programa de C contiene las siguientes sentencias

     float a = 0.001;
     float b = 0.003;
     float c, *pa, *pb
     pa = &a;
     *pa = 2 * a;
     pb = &b;
     c = 3 * (*pb + *pa );

Si el valor asignado a “a” empieza en la dirección 1130 (hexadecimal) y el valor asignado a “b”
empieza en 1134 y el valor asignado a “c” empieza en 1138, entonces:

     a) ¿Qué valor es representado por &a?

          El comienzo de la dirección de memoria de la variable a

     b) ¿Qué valor es representado por &b?

          El comienzo de la dirección de memoria de la variable b

     c) ¿Qué valor es representado por &c?

          El comienzo de la dirección de memoria de la variable c

     d) ¿Qué valor es asignado a pa?

          A pa se le asigna la dirección de comienzo de la variable

     e) ¿Qué valor es representado por *pa?

          El contenido de la dirección de memoria que almacena

     f) ¿Qué valor es representado por &(*pa)?



     g) ¿Qué valor es asignado a pb?
     h) ¿Qué valor es representado por *pb?
     i) ¿Qué valor es asignado a c?


*/

#include <stdio.h>


int main (){

     float a = 0.001;
     float b = 0.003;
     float c, *pa, *pb;
     pa = &a;
     *pa = 2 * a;
     pb = &b;
     c = 3 * (*pb + *pa );

          printf("%p \n", &(*pa));

     return 0;
}
