#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos __________________________________________________________________

struct Ficha_alumno {

     char nombre[50];
     int DNI;
     float nota;

};
int contarRegistros(char * nombreFichero);
struct Ficha_alumno * reservaVector(int numeroRegistros);
void leerAlumnos(char * nombreFichero, struct Ficha_alumno * vector);
void listarAlumnos(struct Ficha_alumno * vector, int numeroRegistros);
void seleccionDirecta(struct Ficha_alumno * vector,int numeroRegistros, int (*orden)(int, int));
int mayor(int a, int b);
int menor(int a, int b);
void liberarMemoria(struct Ficha_alumno * vector);

// Main ________________________________________________________________________

int main(int argc,char **argv){

     // Variables

     char nombreFichero[20], or[20];
     int numeroRegistros = 0;
     struct Ficha_alumno * vector;

     // Puntero a funcion

     int (*orden)(int, int);

     if(argc != 3){
          printf("\nEjecución ./salida.exe alumnos.bin ascendente/descendente\n");
          return 0;
     }

     strcpy(nombreFichero,argv[1]);
     printf("\nEl nombre del fichero es → %s\n",nombreFichero);
     strcpy(or,argv[2]);
     printf("\nY el orden es %s \n",or);

     if((strcmp(or,"ascendente"))==0){
          orden = &menor;
     }else{
          orden = &mayor;
     }

     // Leemos el fichero para averiguar el numero de registros del mismo
     numeroRegistros = contarRegistros(nombreFichero);
     printf("\nEl numero de registros es → %i\n",numeroRegistros);
     // Reservamos para poder listar
     vector = reservaVector(numeroRegistros);
     // Rellenamos el vector con los elemetos del fichero
     leerAlumnos(nombreFichero,vector);
     // Listamos los elementos del vector
     listarAlumnos(vector,numeroRegistros);
     // Ordenamos el vector con el algoritmo de selección directa
     seleccionDirecta(vector,numeroRegistros,orden);

     printf("\nLista de alumnos ordenados por seleccion directa de manera %s\n",argv[2]);

     listarAlumnos(vector,numeroRegistros);

     liberarMemoria(vector);



     return 0;
}

// Funciones ___________________________________________________________________

int contarRegistros(char * nombreFichero){

     FILE * f;

     int nRegistros = 0;

     if((f=fopen(nombreFichero,"rb"))==NULL){
          printf("\nError al abrir el fichero %s \n",nombreFichero);
          exit(-1);
     }else{
          printf("\nEl fichero %s se ha abierto correctamente\n",nombreFichero);
     }

     if(fseek(f,0L,SEEK_END)){
          printf("\nNo se ha podido manipular el fichero %s\n",nombreFichero);
     }

     nRegistros = ftell(f);
     fclose(f);

     return nRegistros/sizeof(struct Ficha_alumno);

}

struct Ficha_alumno * reservaVector(int numeroRegistros){

     struct Ficha_alumno * aux;

     if((aux = (struct Ficha_alumno *)calloc(sizeof(struct Ficha_alumno),numeroRegistros))==NULL){
          printf("\nError al reservar memoria\n");
          exit(-1);
     }else{
          printf("\nMemoria reservada correctamente para %i elementos\n",numeroRegistros);
     }

     return aux;

}

void leerAlumnos(char * nombreFichero, struct Ficha_alumno * vector){

     FILE * f;
     int i = 0;

     if((f = fopen(nombreFichero,"rb"))==NULL){
          printf("\nError al abrir el fichero %s\n",nombreFichero);
          exit(-1);
     }else{
          printf("\nEl fichero %s se ha abierto correctamente\n",nombreFichero);
     }

     while (fread(&vector[i],sizeof(struct Ficha_alumno),1,f)==1){
          i++;
     }

     fclose(f);

}

void seleccionDirecta(struct Ficha_alumno * vector,int numeroRegistros, int (*orden)(int, int)){

     int i=0,k=0,menor=0;
     struct Ficha_alumno auxiliar;

     for(i=0;i<numeroRegistros-1;i++){
          menor = i;

          for(k=i+1;k<numeroRegistros;k++){
               if((*orden)(vector[k].DNI,vector[menor].DNI)){
                    menor = k;
               }
          }

          auxiliar = vector[i];
          vector[i] = vector[menor];
          vector[menor] = auxiliar;

     }

}

void listarAlumnos(struct Ficha_alumno * vector, int numeroRegistros){

     int i = 0;

     for(i=0;i<numeroRegistros;i++){

          printf("\n\nPersona %i___________",i);
          printf("\nNombre → %s",vector[i].nombre);
          printf("\nDNI → %i",vector[i].DNI);
          printf("\nNota → %.2f",vector[i].nota);

     }

     printf("\n");

}

int mayor(int a, int b){

     if(a>b){
          return 1;
     }else{
          return 0;
     }

}

int menor(int a, int b){

     if(a<b){
          return 1;
     }else{
          return 0;
     }

}

void liberarMemoria(struct Ficha_alumno * vector){

     free(vector);
     vector = NULL;

}
