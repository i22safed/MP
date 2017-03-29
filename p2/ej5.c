
/*

5.  Escribe un programa que lea una frase y, a partir de ella, cree un vector
dinámico de cadenas con las diferentes palabras de la frase. A partir de este
vector, el programa deberá:

     · Calcular la longitud media de las palabras de la frase, así como la
     longitud mayor y menor (usando paso de parámetros por referencia).
     · Construir un vector dinámico con la frecuencia de aparición de cada
     longitud.

Realiza una adecuada modularización, implementando todas las funciones que sean
necesarias.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){


     char cadena[100];
     int i=0,j=0,espacios=0;
     int caracteres[3];

     // Matriz de cadenas 

     char * caden2121a[4]={"Esto ","es ","una ","prueba"};

     printf("\nIntroduzca una cadena → ");
     gets(cadena);

     for(i=0;i<4;i++){

          printf("%s",caden2121a[i]);
     }


     for(i=0;i<strlen(cadena);i++){

          if(cadena[i]==' '){

               espacios++;

          }

     }

     // A partir de los espacios, el numero de palabras es espacios + 1
     // Contamos además el numero de letras de cada palabra

     for(i=0;i<strlen(cadena);i++){

          if(cadena[i]!=' '){

               caracteres[j]++;

          }else{

               j++;

          }

     }

     for(i=0;i<4;i++){

          printf("\nEl valor de la pos %d es %d \n",i,caracteres[i]);
     }




     return 0;
}
