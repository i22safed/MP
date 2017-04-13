#include <stdio.h>
#include <time.h>




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
	


	return 0; 
}