#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int * reservaMemoria(int nEle);
void rellenaFichero(char * nombreFichero,int * limite, int nEle);
void leerFichero(char * nombreFichero,int nEle);

int main(int argc, char ** argv){

     if(argc==1){

          printf("\nNo se han pasado argumentos\n");
          exit(-1);

     }

     char nombreFichero[20];
     strcpy(nombreFichero,argv[1]);
     strcat(nombreFichero,".bin\0");

     int limite[1], nEle = 0, * vector;

     nEle = atoi(argv[2]);

     limite[0] = atoi(argv[3]);
     limite[1] = atoi(argv[4]);

     rellenaFichero(nombreFichero,limite,nEle);

     leerFichero(nombreFichero,nEle);

     return 0;
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

void rellenaFichero(char * nombreFichero,int * limite, int nEle){

	// Generamos la semilla y abrimos fichero
	// Generamos nEle elementos entre limite[0] y limite[1]

	FILE * fichero;	// Puntero al fichero
	int i = 0, * vector;

	if((fichero=fopen(nombreFichero,"wb"))!=NULL){

		printf("\nEl fichero %s ha sido abierto correctamente\n",nombreFichero);

	}else{

		printf("\nError. El fichero %s no se ha podido abrir\n",nombreFichero);
		exit(-1);

	}

     vector = reservaMemoria(nEle);

	for(i=0;i<nEle;i++){

		vector[i] = limite[0] + rand() % (limite[1] + 1 - limite[0]);
		printf("\nEl numero a introducir es → %i \n",vector[i]);

	}

     fwrite(vector,sizeof(int),nEle,fichero);

	fclose(fichero);
     free(vector);

}

void leerFichero(char * nombreFichero,int nEle){

     FILE * fichero;
     int i = 0, * vector;
     int num = 0;


     if((fichero=fopen(nombreFichero,"rb"))!=NULL){

          printf("\nEl fichero %s ha sido abierto correctamente\n",nombreFichero);

     }else{

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreFichero);
          exit(-1);

     }


     vector = reservaMemoria(nEle);


     * vector = fread(vector,sizeof(int),nEle,fichero);

     for(i=0;i<nEle;i++){

          printf("\nEl valor del vector es → %i\n",vector[i]);

     }

     fclose(fichero);
     free(vector);

}
