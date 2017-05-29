#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(int argc, char * argv[]){
	/* Declaración de variables */
	struct Ficha_alumno *vectorAlumnos;
	int numero;
	char *nombreFichero;
	int sentido;
	/*	Variable de tipo puntero a función para comparar dos números según el sentido de la ordenación */
	int(*comparar)(int, int);
	/* Control de argumentos */
	if(argc!=3){
		printf("\aNúmero incorrecto de argumentos\n ");
		printf("Sintaxis correcta: \n <%s> <nombre de fichero binario> <sentido de ordenación>\n", argv[0]);
		printf("Sentido de ordenación\n");
		printf("\t 1.- Ascendente\n");
		printf("\t 2.- Descendente\n");
		exit(-1);
	}
	/* Se toma el nombre del fichero binario de alumnos */
	nombreFichero=argv[1];
	/* Se comprueba que la opción elegida es correcta */
	sentido=atoi(argv[2]);
	if(sentido!=1&&sentido!=2){
		printf("\aEl sentido de ordenación no es correcto: %d\n", sentido);
		printf("Valores permitidos:\n");
		printf("\t 1.- Ascendente\n");
		printf("\t 2.- Descendente\n");
		exit(-1);
	}
	/* Se elige la función de comparación */
	if(sentido==1){
		/* Ordenación ascendente */
		comparar=&menor;
	}
	else{
		/* Ordenación descendente */
		comparar=&mayor;
	}
	/* Se cuentan los alumnos del fichero binario */
	numero = contarAlumnosFicheroBinario(nombreFichero);
	/* Se reserva memoria para el vector de alumnos */
	reservarMemoriaVectorAlumnos(&vectorAlumnos, numero);
	/* Se leen los alumnos del fichero binario */
	leerAlumnosFicheroBinario(nombreFichero, vectorAlumnos, numero);
	/* Se muestran por pantalla los alumnos leídos */
	printf("\nLista de estudiantes antes de ser ordenados por DNI:\n");
	escribirAlumnos(vectorAlumnos, numero);
	/* Se ordenan los alumnos */
	seleccionDirecta(vectorAlumnos, numero, comparar);
	/* Se muestran por pantalla los alumnos ordenados */
	printf("\nLista de estudiantes después de ser ordenados:\n");
	escribirAlumnos(vectorAlumnos, numero);
	/* Se libera la memoria del vector de alumnos */
	liberarMemoriaVectorAlumnos(&vectorAlumnos);
	/* Fin */
	return 0;
}
