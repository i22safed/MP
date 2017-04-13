#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
     minMayus(nombre,cadena);

     return 0;
}

void guardarFichero(char * nombre, char * cadena){     // Escribe la cadena que
                                                       // recibe y cierra el fichero

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

void minMayus(char * nombre, char * cadena){           // Abre el fichero coge la
                                                       // lee caracter a caracter
                                                       // y lo cambia a mayuscula
     int i=0;

     FILE * fichero;          // Declaramos el puntero del fichero
     FILE * ficheroMayus;     // Declaramos el fichero donde irán con mayusculas
     char  nombreSalida[50]="mayusculas-";
     strcat(nombreSalida,nombre);
     char aux[strlen(cadena)];
     char c; 

     printf("\nEl nombre de fichero de salida es → %s\n",nombreSalida);

     if((fichero = fopen(nombre,"r"))==NULL){

          printf("\nError al abrir el fichero %s\n",nombre);
          exit (-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente \n",nombre);

     }

     // Leemos la linea del fichero

	while(fgets(aux,100,fichero)!=NULL){

		if(aux[strlen(aux)-1]=='\n'){

			cadena[strlen(cadena)-1]='\0'; // Esto es importante
		}

	}

	printf("\nLa cadena es: %s\n",aux);

     for(i=0;i<(strlen(aux));i++){

          
          aux[i]=toupper(aux[i]);

     }

     if((ficheroMayus = fopen(nombreSalida,"w"))==NULL){
          printf("\nError al abrir el fichero %s\n",nombreSalida);
          exit (-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente \n",nombreSalida);

     }

     fputs(aux,ficheroMayus);      // Escribimos en el fichero la cadena
                                   // fgets guarda el \n y \0
                                   // recomendable fgets pero hay que cambiar \n por \0

     fclose(fichero);
     fclose(ficheroMayus);

}
