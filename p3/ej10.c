#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*

10. Codifica un programa en C que, utilizando funciones, cree un fichero
binario  con números enteros   generados   aleatoriamente   en   un   intervalo
especificado   por   el   usuario.   El   programa guardará los números en un
vector dinámico antes de volcarlo a disco. El programa recibirá 4 parámetros
como argumentos en la línea de órdenes: nombre del fichero a crear, número de
elementos que contendrá el fichero y los extremos superior e inferior del
intervalo.

*/


int main(int argc, char ** argv){

     char nombreFichero[20];
     strcpy(nombreFichero,argv[1]);
     strcat(nombreFichero,".txt\0");

     

     return 0;
}
