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
struct Ficha_Jugador leerJugador();
struct Ficha_Jugador * rellenaVectorJugadores(struct Ficha_Jugador * jugador, int nEle);


int main (){

	int nEle=0, i=0;
	struct Ficha_Jugador * jugador;

	printf("\nIntroduzca el numero de jugadores para la reserva: ");
	scanf("%i",&nEle);
	getchar(); // Necesario para que no se salte scanf's en funciones

	jugador = reservaVector(nEle);
	jugador = rellenaVectorJugadores(jugador,nEle);


	return 0;
}

struct Ficha_Jugador * reservaVector(int nEle){

	struct Ficha_Jugador * p;

	if((p=(struct Ficha_Jugador *) malloc(nEle*sizeof(struct Ficha_Jugador)))==NULL){


		printf("\nFallo en la reserva de memoria\n");
		exit(-1);

	}else{

		printf("\nLa reserva de memoria para %i elementos se ha realizado correctamente\n",nEle);
		return (p);

	}
}

struct Ficha_Jugador leerJugador(){

	struct Ficha_Jugador aux;

	printf("\nIntroduzca el nombre del jugador → ");
	gets(aux.nombre);

	printf("\nIntroduzca el dorsal del jugador → ");
	scanf("%i", &aux.dorsal);

	printf("\nIntroduzca el peso del jugador → ");
	scanf("%f",&aux.peso);

	printf("\nIntroduzca la estatura del jugador → ");
	scanf("%i",&aux.estatura);


	return aux;

}

struct Ficha_Jugador * rellenaVectorJugadores(struct Ficha_Jugador * jugador, int nEle){

	int i=0;

	for(i=0;i<nEle;i++){

		printf("\nDatos para el jugador %i ______________________", i);

		*(jugador+i)=leerJugador();
		getchar();

	}

	return jugador;

}

void listarJugadores(struct Ficha_Jugador * jugador, int nEle){

	int i=0;

	for(i=0;i<nEle;i++){

		printf("\nDatos del jugador %i",i);
		printf("Nombre → %s",(jugador+i)->nombre);

	}


}
