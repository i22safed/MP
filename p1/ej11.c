#include <stdio.h>
#include <string.h>


// CORREGIR LA FUNCION


int es_sufijo(char * cadena, char * suprefijo);
int es_prefijo(char * cadena, char * suprefijo);

int main (){

     char cadena[20];
     char suprefijo[4];

     printf("Introduce una cadena a comparar: ");
     scanf("%s", cadena);
     printf("Introduce ahora el sufijo/prefijo: ");
     scanf("%s", suprefijo);

     int res=es_sufijo(cadena, suprefijo);

     if(res == 1 ){

          printf("Hay coincidencia → %s es sufijo de %s\n", suprefijo, cadena);

     }else{

          printf("No hay coincidencia → %s no es sufijo de %s\n", suprefijo, cadena);

     }

     res=es_prefijo(cadena, suprefijo);

     if(res == 1 ){

          printf("Hay coincidencia → %s es prefijo de %s\n", suprefijo, cadena);

     }else{

          printf("No hay coincidencia → %s no es prefijo de %s\n", suprefijo, cadena);

     }


     return 0;
}


int es_sufijo(char * cadena, char * suprefijo){


     int i=0;

     // Declaramos un aux para guardar el final de la cadena

     char aux[strlen(suprefijo)];

     // Declaramos el final de la cadena

     int final=strlen(cadena);

     // Contador para la cadena

     int j=final-strlen(suprefijo);

     // Guardamos en aux el comienzo de final menos la longuitud del sufijo

     for(i=0;i<strlen(suprefijo);i++){

          aux[i]=cadena[j];
          j++;

     }

     if(strstr(aux,suprefijo)!=NULL){

          return 1;

     }else{

          return 0;
     }


}

int es_prefijo(char * cadena, char * suprefijo){


     int i=0;

     // Declaramos un aux para guardar el final de la cadena

     char aux[strlen(suprefijo)];

     // Guardamos en aux el comienzo de final menos la longuitud del sufijo

     for(i=0;i<strlen(suprefijo);i++){

          aux[i]=cadena[i];

     }

     if(strstr(aux,suprefijo)!=NULL){

          return 1;

     }else{

          return 0;
     }


}
