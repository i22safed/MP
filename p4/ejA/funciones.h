#ifndef FUNCIONES_H
#define FUNCIONES_H
//! Definición de la estructura Ficha_alumno
struct Ficha_alumno{
	char nombre[50]; // Nombre del alumno
	int DNI; // DNI del alumno
	float nota; // Nota del alumno
};
int mayor(int a, int b);
int menor(int a, int b);
int contarAlumnosFicheroBinario(char * nombreFichero);
void leerAlumnosFicheroBinario(char * nombreFichero, struct Ficha_alumno * v, int n);
void reservarMemoriaVectorAlumnos(struct Ficha_alumno ** v, int n);
void liberarMemoriaVectorAlumnos(struct Ficha_alumno ** v);
void escribirAlumnos(struct Ficha_alumno * v, int n);
void seleccionDirecta(struct Ficha_alumno * v, int n, int (*comparar)(int, int));
void shell(struct Ficha_alumno * v, int n, int (*comparar)(int, int));
void quicksort(struct Ficha_alumno * v, int izquierda, int derecha, int (*comparar)(int, int));
#endif
