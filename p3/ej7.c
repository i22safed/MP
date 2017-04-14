#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void rellenaFichero(char * nombreFichero,int * limite, int nEle);

int main(){


	int nEle = 0;
	int limite[1];
	char nombreFichero[50];

	printf("\nIntroduzca el nombre del fichero: ");
	gets(nombreFichero);

	strcat(nombreFichero,".txt\0");

	printf("\nIntroduzca el numero de elementos del fichero: ");
	scanf("%i",&nEle);

	printf("\nIntroduzca el limite inferior de los numeros: ");
	scanf("%i",&limite[0]);

	printf("\nIntroduzca el limite superior de los numeros: ");
	scanf("%i",&limite[1]);

	rellenaFichero(nombreFichero,limite,nEle);

	return 0;
}

void rellenaFichero(char * nombreFichero,int * limite, int nEle){

	// Generamos la semilla y abrimos fichero
	// Generamos nEle elementos entre limite[0] y limite[1]

	FILE * fichero;	// Puntero al fichero
	int num = 0;
	int i = 0; 		// Numero que se irá introduciendo en el fichero

	if((fichero=fopen(nombreFichero,"w"))!=NULL){

		printf("\nEl fichero %s ha sido abierto correctamente\n",nombreFichero);

	}else{

		printf("\nError. El fichero %s no se ha podido abrir\n",nombreFichero);
		exit(-1);

	}

	for(i=0;i<nEle;i++){

		num = limite[0] + rand() % (limite[1] + 1 - limite[0]);
		printf("\nEl numero a introducir es → %i \n",num);
		fprintf(fichero,"%i ",num);



	}

	fclose(fichero);

}
