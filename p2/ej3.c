#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ficha_Jugador{

	char nombre[50];
	int dorsal;
	float peso;
	int estatura;

};
struct Ficha_Jugador * reservaVector(int nEle);


int main (){

	int nEle=0;
	struct Ficha_Jugador * jugador;
	struct Ficha_Jugador aux;

	printf("\nIntroduzca el numero de jugadores para la reserva: ");
	scanf("%i",&nEle);


	jugador = reservaVector(nEle);




	return 0;
}

struct Ficha_Jugador * reservaVector(int nEle){

	struct Ficha_Jugador * p;

	if((p=(struct Ficha_Jugador *) malloc(nEle*sizeof(struct Ficha_Jugador)))==NULL){


		printf("\nFallo en la reserva de memoria\n");
		exit(-1);

	}else{

		printf("\nLa reserva de memoria para %i elementos se ha realizado correctamente\n",nEle);

	}
}
