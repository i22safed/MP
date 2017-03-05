#include <stdio.h>
#include <string.h>


// CORREGIR LA FUNCION


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

          printf("Hay coincidencia → %s es sufijo de %s\n", sufijo, cadena);

     }else{

          printf("Hay coincidencia → %s no es sufijo de %s\n", sufijo, cadena);

     }


     return 0;
}


int es_sufijo(char * cadena, char * sufijo){


     int i=0;

     // Declaramos un aux para guardar el final de la cadena

     char aux[strlen(sufijo)];

     // Declaramos el final de la cadena

     int final=strlen(cadena);

     // Contador para la cadena

     int j=final-strlen(sufijo);

     // Guardamos en aux el comienzo de final menos la longuitud del sufijo

     for(i=0;i<strlen(sufijo);i++){

          aux[i]=cadena[j];
          j++;

     }

     if(strstr(aux,sufijo)!=NULL){

          return 1;

     }else{

          return 0;
     }


}
