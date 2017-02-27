<<<<<<< HEAD
#include <stdio.h>
#include <string.h>


int es_sufijo(char * cadena, char * sufijo);

int main (){

     char cadena[20];
     char sufijo[4];

     printf("Introduce una cadena a comparar: ");
     scanf("%s", cadena);
     printf("Introduce ahora el sufijo: ");
     scanf("%s", sufijo);

     int res=es_sufijo(cadena, sufijo);

     if(res == 1 ){

          printf("Ha habido coincidencia\n");

     }else{

          printf("No ha habido coincidencia\n");

     }


     return 0;
}


int es_sufijo(char * cadena, char * sufijo){


     if(strstr(cadena,sufijo)!=NULL){

          return 1;

     }else{

          return 0;

     }

}
