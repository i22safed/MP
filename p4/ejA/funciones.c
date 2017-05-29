#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void reservarMemoriaVectorAlumnos(struct Ficha_alumno ** v, int n){
	*v = (struct Ficha_alumno *) malloc(sizeof(struct Ficha_alumno) * n);
	if(*v == NULL){
		printf("\aError al reservar memoria\n");
		exit(-1);
	}
}
void liberarMemoriaVectorAlumnos(struct Ficha_alumno ** v){
	free(*v);
	*v = NULL;
}
int contarAlumnosFicheroBinario(char * nombreFichero){
	int N;
	int tam;
	FILE * ficheroEntrada;
	ficheroEntrada=fopen(nombreFichero, "rb");
	if(ficheroEntrada==NULL){
		printf("\aError al abrir el fichero %s\n", nombreFichero);
		exit(-1);
	}
	//Se cuentan los registros del fichero
	fseek(ficheroEntrada, 0L, SEEK_END);
	tam=ftell(ficheroEntrada);
	N=tam/sizeof(struct Ficha_alumno);
	fclose(ficheroEntrada);
	return N;
}
void leerAlumnosFicheroBinario(char * nombreFichero, struct Ficha_alumno * v, int N){
	FILE * ficheroEntrada;
	ficheroEntrada=fopen(nombreFichero, "rb");
	if(ficheroEntrada==NULL){
		printf("\aError al abrir el fichero %s\n", nombreFichero);
		exit(-1);
	}
	//Se leen todos los registros a la vez
	fread(v, sizeof(struct Ficha_alumno), N, ficheroEntrada);
	fclose(ficheroEntrada);
}
void escribirAlumnos(struct Ficha_alumno * v, int N){
	int i;
	printf("\tLista de alumnos:\n");
	for(i=0; i<N; i++){
		printf("\n\tNombre = %s", v[i].nombre);
		printf("\n\tDNI = %d", v[i].DNI);
		printf("\n\tNota = %.2f\n", v[i].nota);
	}
}
int mayor(int a, int b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	}
}
int menor(int a, int b){
	if(a<b){
		return 1;
	}
	else{
		return 0;
	}
}
void seleccionDirecta(struct Ficha_alumno * v, int n, int (*comparar)(int, int)){
	int i, k, menor;
	struct Ficha_alumno auxiliar;
	for(i=0; i<n-1; i++){
		menor=i;
		for(k=i+1; k<n; k++){
			//Si se encuentra un elemento mejor
			if((* comparar)((v+k)->DNI, (v+menor)->DNI)){
				//Se toma la posición
				menor=k;
			}
		}
		//El elemento elegido se coloca en la componente nº i
		auxiliar=v[i];
		v[i]=v[menor];
		v[menor]=auxiliar;
	}
}
