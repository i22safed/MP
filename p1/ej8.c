#include <stdio.h>
#include <ctype.h>
#include <string.h>


void estadisticasCadena(char * cadena, int *digitos, int *espacios, int *mayus, int *minus);

int main (){


     char cadena[256];

     int digitos, espacios, mayus, minus;

     printf("Introduzca una cadena: ");
     gets(cadena);

     estadisticasCadena(cadena ,&digitos, &espacios, &mayus, &minus);

     printf("La cadena introducida posee: \n");
     printf("Digitos → %d\n", digitos);
     printf("Espacios → %d\n", espacios);
     printf("Mayusculas → %d\n", mayus);
     printf("Minusculas → %d\n", minus);

     return 0;

}


void estadisticasCadena(char * cadena, int *digitos, int *espacios, int *mayus, int *minus){

     int i=0;

     *digitos=0;
     *espacios=0;
     *mayus=0;
     *minus=0;



     for(i=0; i<strlen(cadena); i++){

          if(isspace(cadena[i])){
               *espacios = *espacios + 1;
          }
          if(isdigit(cadena[i])){
               *digitos = *digitos + 1;
          }
          if(isalpha(cadena[i])){
               if(islower(cadena[i])){
                    *minus = *minus + 1;
               }else{
                    *mayus = *mayus + 1;
               }

          }
     }
}
