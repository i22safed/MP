#include <stdio.h>
#include <stdlib.h>


int * reservaVector(int nEle);
void rellenaVector(int nEle, int * vector,int num, int * mayor, int *menor);
void mayorMenorVector(int nEle, int * vector,int *mayores, int *menores, int num);
void imprimeVector(int nEle, int * vector);

int main (){

	// Declaramos las variables necesarias 

	int nEle=0, num=0;
	int * vector,* menores,* mayores; 
	int menor=0, mayor=0;

	// Pedimos el numero de elementos del vector 

	printf("\nIntroduzca el numero de elemetos del vector: ");
	scanf("%i", &nEle);

	// A continuación reservamos memoria para el vector

	vector = reservaVector(nEle);

	// Ahora pedimos el numero para separar en mayor y menor 

	printf("\n\nIntroduzca el numero para hallar los mayores/menores: ");
	scanf("%i", &num); 

	// Rellenamos el vector con valores y determinamos cuantos valores menores y mayores
	// que num hay 

	rellenaVector(nEle,vector,num,&mayor,&menor);

	// Reservamos memoria para los vectores de mayores y menores	

	menores=reservaVector(menor);
	mayores=reservaVector(mayor);

	// Metemos en cada uno de los vectores reservados los elementos correspondientes

	mayorMenorVector(nEle,vector,mayores,menores,num);

	// Imprimimos cada uno de los vectores de elemetos 

	printf("\n\nLos valores del vector original son: ",num);
	imprimeVector(nEle,vector);
	printf("\n\nLos valores menores que %i son: ",num);
	imprimeVector(menor,menores);
	printf("\nLos valores mayores o iguales que %i son: ",num);
	imprimeVector(mayor,mayores);

	// Liberamos memoria para cada uno de los vectores reservados y ponemos los 
	// respectivos punteros a NULL

	free(vector);
	vector = NULL; 
	free(mayores);
	mayores = NULL; 
	free(menores);
	menores = NULL; 

	return 0; 
}





int * reservaVector(int nEle){					// No utilizamos referencia

	int * v; 

	if((v=(int*)calloc(nEle,sizeof(int)))==NULL){

		printf("\nError en la reserva de memoria\n");
		exit(-1);

	}else{

		printf("\nLa reserva para %i elementos se ha realizado correctamente", nEle);
	}

	return (v);

}




void rellenaVector(int nEle, int * vector,int num, int *mayor, int *menor){

	int i=0; 

	// Bucle para rellenar el vector

	for(i=0;i<nEle;i++){

		printf("\nIntroduzca un valor para la pos. %i del vector: ",i);
		scanf("%i",(vector+i));

	}
	
	// Comprobamos la cantidad de numeros mayores y menores que num hay 

	for(i=0;i<nEle;i++){

		if(*(vector+i)<num){
			*menor = *menor + 1;
		}else{
			*mayor = *mayor + 1;
		}	
	}
}

void mayorMenorVector(int nEle, int * vector,int *mayores, int *menores, int num){

	int i=0,j=0,k=0; 

	for(i=0;i<nEle;i++){
		
		if(*(vector+i)<num){

			*(menores+j) = *(vector+i); 
			j++;

		}else{

			*(mayores+k) = *(vector+i); 
			k++;
		}
	}

}

void imprimeVector(int nEle, int *vector){

	int i=0; 

	for(i=0;i<nEle;i++){

		printf(" %i", *(vector+i));

	}
	printf("\n");
}