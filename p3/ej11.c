#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * ficheroVector(char * nombreFichero,int nEle);
int * reservaMemoria(int nEle);

int main (){

     char nombreFichero[24];
     int nEle = 6;
     int * vector;
     int i=0;

     printf("\nEn el ej10.c se guardaron 6 numeros\n");
     printf("\nIntroduzca el nombre del fichero → ");
     gets(nombreFichero);
     strcat(nombreFichero,".bin\0");

     vector = ficheroVector(nombreFichero,nEle);

     printf("\nLos elementos del vector son → ");

     for(i=0;i<nEle;i++){

          printf(" %i",vector[i]);

     }

     printf("\n");

     free(vector);

     return 0;
}

int * ficheroVector(char * nombreFichero, int nEle){


	FILE * fichero;	// Puntero al fichero
	int i = 0, *vector;

	if((fichero=fopen(nombreFichero,"rb"))!=NULL){

		printf("\nEl fichero %s ha sido abierto correctamente\n",nombreFichero);

	}else{

		printf("\nError. El fichero %s no se ha podido abrir\n",nombreFichero);
		exit(-1);

	}

     vector = reservaMemoria(nEle);

     fread(vector,sizeof(int),nEle,fichero);

     fclose(fichero);

     return vector;


}

int * reservaMemoria(int nEle){

     int * aux;

     if((aux = (int *)calloc(sizeof(int),nEle))==NULL){

          printf("\nError en la reserva de memoria\n");
          exit(-1);

     }else{

          printf("\nSe ha reservado memoria para %i elementos\n",nEle);

     }

     return aux;

}
