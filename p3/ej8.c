#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calcularMedia(char * nombre);


int main(int argc, char ** argv){

     if(argc==1){

          printf("Error. No se ha introducido ningun paramentro\n");
          exit (-1);

     }


     float media = 0;
     char nombre[20];

     strcat(argv[1],".txt\0");
     strcpy(nombre,argv[1]);

     printf("\nEl nombre del fichero es %s \n",nombre);

     media = calcularMedia(nombre);

     printf("\nLa media de los elementos del fichero es → %.3f\n",media);



     return 0;
}

float calcularMedia(char * nombre){

     FILE * fichero;

     float media = 0;
     int num = 0, nEle=0 ;

     if((fichero = fopen(nombre,"r"))==NULL){

          printf("\nError al abrir el fichero %s \n",nombre);
          exit(-1);

     }else{

          printf("\nEl fichero %s ha sido abierto correctamente\n",nombre);

     }

     // Leemos el fichero

     while((fscanf(fichero,"%i ",&num))!=EOF){

          printf("\nEl numero actual es → %d\n", num);
          media = media + num;
          nEle++;
     }

     printf("\nEl numero de elemetos es → %i\n",nEle);

     fclose(fichero);

     return media/nEle;

}
