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
void listarJugadores(struct Ficha_Jugador * jugador, int nEle);
struct Ficha_Jugador * borraJugadores(struct Ficha_Jugador * jugador, int nEle, char * caracter, int * match);
void liberarMemoria(struct Ficha_Jugador * jugador);

int main (){

	// variables iniciales
	int nEle=0, i=0;

	// Almacenamos el caracter para borrar los que lo contengan
	// y el nunmero de coincidencias de para hacer el realloc
	char caracter[1]="a"; int match=0;

	// Vector de tipo struct Ficha_Jugador
	struct Ficha_Jugador * jugador;

	printf("\nIntroduzca el numero de jugadores para la reserva: ");
	scanf("%i",&nEle);
	getchar(); // Necesario para que no se salte scanf's en funciones

	jugador = reservaVector(nEle);
	jugador = rellenaVectorJugadores(jugador,nEle);

	listarJugadores(jugador,nEle);

	printf("\nIntroduzca el caracter a eliminar → ");
	scanf("%c",caracter);
	printf("\n");

	jugador = borraJugadores(jugador,nEle,caracter,&match);

	printf("\n\nLos jugadores que no poseen una %c en su nombre son %i → ", caracter[0], (nEle-match));

	listarJugadores(jugador,(nEle-match));

	liberarMemoria(jugador);

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

		printf("\nDatos para el jugador %i ______________________\n", i);

		*(jugador+i)=leerJugador();

		printf("______________________________________________\n");

		getchar();



	}

	return jugador;

}

void listarJugadores(struct Ficha_Jugador * jugador, int nEle){

	int i=0;

	for(i=0;i<nEle;i++){

		printf("\nDatos del jugador %i",i);
		printf("\n    Nombre → %s \n",(jugador+i)->nombre);
		printf("\n    Dorsal → %i \n",(jugador+i)->dorsal);
		printf("\n    Peso → %f Kg.\n",(jugador+i)->peso);
		printf("\n    Estatura → %i cm.\n",(jugador+i)->estatura);

	}


}

struct Ficha_Jugador * borraJugadores(struct Ficha_Jugador * jugador, int nEle, char * caracter, int * match){

	// CAMBIAR FUNCION

	int i=0,j=0;

	// Buscamos el numero de apariciones para calcular el nuevo nEle

	for(i=0;i<nEle;i++){

		if(strstr(((jugador+i)->nombre),caracter)!=NULL){

			*match = *match + 1;

		}
	}

	// Declaramos un  vector auxiliar para almacenar los que no poseen coincidencia

	struct Ficha_Jugador aux[nEle-(*match)];

	// Almacenamos los que no poseen coincidencia

	for(i=0;i<nEle;i++){

		if(strstr(((jugador+i)->nombre),caracter)==NULL){

			aux[j]=jugador[i];
			j++;

		}

	}

	// Realizamos un realloc a nEle-match

	if((jugador=(struct Ficha_Jugador *)realloc(jugador,(nEle-*match)*sizeof(struct Ficha_Jugador)))==NULL){

		printf("\nError. No ha sido posible recolocar la memoria");
		exit (-1);

	}else{

		printf("El realloc de memoria ha sido realizado correctamente");

	}

	// Volcamos del auxiliar al vector reorganizado

	for(i=0;i<nEle-*match;i++){

		jugador[i]=aux[i];

	}


	return jugador;

}

void liberarMemoria(struct Ficha_Jugador * jugador){

	free(jugador);
	jugador = NULL;
}
