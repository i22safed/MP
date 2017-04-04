#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Creamos fichero
// Metemos contenido
// Cerramos fichero
// Abrimos fichero
// Cogemos contenido
// Ponemos en mayusculas
// Copiamos dentro del fichero
// Cerramos fichero

void guardarFichero(char * nombre, char * cadena);
void minMayus(char * nombre, char * cadena);


int main(){

     char cadena[100];
     char nombre[100];


     printf("\nIntroduzca el nombre para el fichero → ");
     gets(nombre);
     printf("\nIntroduzca contenido para el fichero → ");
     gets(cadena);

     strcat(nombre,".txt\0");

     guardarFichero(nombre,cadena);

     return 0;
}

void guardarFichero(char * nombre, char * cadena){

     FILE * fichero;


     if((fichero = fopen(nombre,"w"))==NULL){
          printf("\nError al abrir el fichero %s\n",nombre);
          exit (-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente \n",nombre);

     }

     fputs(cadena,fichero);   // Escribimos en el fichero la cadena
                              // fgets guarda el \n y \0
                              // recomendable fgets pero hay que cambiar \n por \0

     fclose(fichero);

}

void minMayus(char * nombre, char * cadena){





}
