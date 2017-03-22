#include <stdio.h>
#include <stdlib.h>

struct Ficha_Jugador{

	char nombre[50];
	int dorsal; 
	float peso; 
	int estatura; 
	
};
struct Ficha_Jugador * reservaVector(struct Ficha_Jugador * jugador, int nEle);


int main (){

	int nEle=0; 
	struct Ficha_Jugador * jugadores; 

	printf("\nIntroduzca el numero de jugadores para la reserva: ");
	scanf("%i",&nEle);









	return 0; 
}

struct Ficha_Jugador * reservaVector(struct Ficha_Jugador * jugador, int nEle){

	struct Ficha_Jugador * p; 

	if((p=(struct Ficha_Jugador *) calloc(nEle, sizeof(strutc Ficha_Jugador)))==NULL){


		printf("\nFallo en la reserva de memoria\n");
		exit(-1);

	}else{

		printf("\nLa reserva de memoria se ha realizado correctamente\n");

	}
}
