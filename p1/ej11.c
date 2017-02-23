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
=======

#include <string.h>
#include <stdio.h>

int main()
{
   char pre[10] = "pp";
   char post[10] = "tt";
   char cadena[100] = "ppholacomoandadstt";
   char * c = cadena;
   c += strlen(pre);
   c[strlen(c) - strlen(post)] = '\0';
   printf("%s\n",c);
   return 0;
>>>>>>> ef7c9678b74262b858ad30af66aad1518210dd11

}
