#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ficha_alumno {

     char nombre[50];
     int DNI;
     float nota;

};

// Funciones del programa
void escribirFichero(char * nombreFichero, struct Ficha_alumno alumno);
int contarRegistros(char * nombreFichero);
void listarAlumnos(char * nombreFichero, struct Ficha_alumno * vector);
void descendente(char * nombreFichero);
void ascendente(char * nombreFichero);

// Funciones adicionales
struct Ficha_alumno * reservaVector(char * nombreFichero);


int main(int argc,char **argv){

     // Variables para funciones de escribir, contar, listar reservar memoria

     struct Ficha_alumno alumno;
     struct Ficha_alumno * vector;
     int nRegistros = 0, op = 1, i = 0;
     char nombreFichero[20],orden[12];

     // Puntero a funciones para el orden ascendente / descendente

     void (*or)(char *);


     if(argc != 3){

          printf("\nEl formato de los argumentos es ./salida.exe alumnos.bin ascendente/descendente\n");
          return 0;

     }

     strcpy(nombreFichero,argv[1]);
     printf("\nEl nombre del fichero es → %s\n",nombreFichero);
     strcpy(orden,argv[2]);
     printf("\nY el orden es %s \n",orden);


     while (op!=0) {

          printf("\n__________________MENU PRINCIPAL_____________________\n");

          printf("\nElija una opción:\n");
          printf("\n1. Añadir alumno.");
          printf("\n2. Listar alumnos. ");
          printf("\n3. Ordenar fichero.");
          printf("\n4. Eliminar alumno. ");
          printf("\n5. Ranking de notas. ");
          printf("\n0. Salir del programa. \n");
          printf("\nElija una opcion → ");
          scanf("%i",&op);
          getchar();

          switch (op) {
               case 1:

                    printf("\nIntroduzca el nombre del alumno → ");
                    gets(alumno.nombre);

                    if(alumno.nombre[strlen(alumno.nombre - 1 )] == '\n'){

                         alumno.nombre[strlen(alumno.nombre - 1 )] = '\0';

                    }

                    printf("\nIntroduzca el DNI → ");
                    scanf("%i",&alumno.DNI);
                    printf("\nIntroduzca la nota → ");
                    scanf("%f",&alumno.nota);

                    escribirFichero(nombreFichero,alumno);

                    nRegistros = contarRegistros(nombreFichero);
                    printf("\nEl numero de registros del fichero es %i \n",nRegistros);




               break;
               case 2:

                    vector = reservaVector(nombreFichero);

                    listarAlumnos(nombreFichero,vector);

               break;
               case 3:

                    if((strcmp(orden,"ascendente"))==0){

                         printf("\norden ascendente\n");
                         or = &ascendente;
                         (*or)(nombreFichero);
                         printf("\nEl fichero %s ha sido ordenado de manera %s por DNI\n",nombreFichero,orden);


                    }else{

                         printf("\norden descendente\n");
                         or = &descendente;
                         (*or)(nombreFichero);
                         printf("\nEl fichero %s ha sido ordenado de manera %s por DNI\n",nombreFichero,orden);


                    }

               break;
               case 4:



               break;
               case 5:



               break;
               case 0:

                    printf("\nAdioos\n");
                    exit(-1);

               break;
          }
     }


     return 0;
}

void escribirFichero(char * nombreFichero, struct Ficha_alumno alumno){

     FILE * f;

     if((f = fopen(nombreFichero,"rb")) == NULL){

          printf("\nEl fichero %s no existe, se creará a continuación \n",nombreFichero);
          f = fopen(nombreFichero,"wb");

          if(f != NULL){

               printf("\nEl fichero %s se ha creado correctamente\n",nombreFichero);

          }else{

               printf("\nError al crear el fichero\n");
               exit(-1);

          }


     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreFichero);
          fclose(f);
          f = fopen(nombreFichero,"ab");

     }


     fwrite(&alumno,sizeof(struct Ficha_alumno),1,f);


     fclose(f);

}

int contarRegistros(char * nombreFichero){

     FILE * f;

     int n=0;

     if((f = fopen(nombreFichero,"rb"))==NULL){

          printf("\nError al abrir el fichero %s \n",nombreFichero);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreFichero);

     }

     if(fseek(f,0L,SEEK_END)){

          printf("\nNo se puede abrir el fichero %s \n",nombreFichero);
          exit(-1);

     }

     n = ftell(f);

     fclose(f);

     return (n/sizeof(struct Ficha_alumno));

}

void listarAlumnos(char * nombreFichero, struct Ficha_alumno * vector){

     FILE * f;
     int i = 0;
     int nRegistros = contarRegistros(nombreFichero);

     if((f = fopen(nombreFichero,"rb"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreFichero);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreFichero);

     }

     while(fread(&vector[i],sizeof(struct Ficha_alumno),1,f)==1){

          printf("\n\nAlumno %i__________________________",i);
          printf("\nNombre → %s",vector[i].nombre);
          printf("\nDNI → %i",vector[i].DNI);
          printf("\nNota → %f",vector[i].nota);
          i++;

     }

     fclose(f);

}

void ascendente(char * nombreFichero){

     FILE * f, *aux;         // Fichero original y binario

     int registros = 0, menor = 0;
     int i = 0, k = 0;

     struct Ficha_alumno * alumnos;
     struct Ficha_alumno auxiliar;

     char ficheroAux[20] = "alumnosAux.bin";

     // Abrimos el fichero original

     if((f = fopen(nombreFichero,"rb"))==NULL){

          printf("\nError al abrir el archivo %s \n",nombreFichero);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto co1rrectamente\n",nombreFichero);

     }

     // Abrimos el fichero auxiliar

     if((aux = fopen(ficheroAux,"rb"))==NULL){

          printf("\nError al abrir el archivo %s, se creará\n",ficheroAux);

          if(( aux = fopen(ficheroAux,"wb"))==NULL){

               printf("\nNo se ha podido crear el fichero %s \n",ficheroAux);

          }else{

               printf("\nSe ha creado el fichero %s correctamente \n",ficheroAux);

          }


     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",ficheroAux);
          fclose(aux);
          aux = fopen(ficheroAux,"wb");

     }


     // Declaramos el vector auxiliar para volcarlos y leemos el fichero y un
     // vector auxiliar para ordenarlos

     registros = contarRegistros(nombreFichero);
     alumnos = reservaVector(nombreFichero);


     // Bucle para la lectura

     while (fread(&alumnos[i],sizeof(struct Ficha_alumno),1,f)==1) {

          i++;
     }

     // Bucle para la ordenación

     for(i=1; i<registros; i++){

          menor = i;

               for(k=i+1 ; k < registros ; k++){

                    if(alumnos[k].DNI < alumnos[menor].DNI){

                         menor = k;

                    }

               }

          auxiliar = alumnos[menor];
          alumnos[menor] = alumnos[i];
          alumnos[i] = auxiliar;

     }

     // Escribimos en el fichero

     for(i=0;i<registros;i++){

          fwrite(&alumnos[i],sizeof(struct Ficha_alumno),1,aux);

     }


     free(alumnos);
     fclose(f);
     fclose(aux);

     if(remove(nombreFichero)==0){

          printf("\nEl fichero %s se ha borrado correctamente\n", nombreFichero);

     }else{

          printf("\nError al borrar el fichero %s\n",nombreFichero);

     }

     if((rename(ficheroAux,nombreFichero))==0){

          printf("\nSe ha cambiado el nombre de %s a %s \n",ficheroAux,nombreFichero);

     }else{

          printf("\nError al renombrar el fichero %s\n",ficheroAux);

     }

}

void descendente(char * nombreFichero){

     FILE * f;

/*  Parte copiada y modificada de la funcion ascendente

     → ARREGLAR PARTE DEL BUCLE DE ORDENACION

          FILE * f, *aux;         // Fichero original y binario

          int registros = 0, menor = 0;
          int i = 0, k = 0;

          struct Ficha_alumno * alumnos;
          struct Ficha_alumno auxiliar;

          char ficheroAux[20] = "alumnosAux.bin";

          // Abrimos el fichero original

          if((f = fopen(nombreFichero,"rb"))==NULL){

               printf("\nError al abrir el archivo %s \n",nombreFichero);
               exit(-1);

          }else{

               printf("\nEl fichero %s se ha abierto co1rrectamente\n",nombreFichero);

          }

          // Abrimos el fichero auxiliar

          if((aux = fopen(ficheroAux,"rb"))==NULL){

               printf("\nError al abrir el archivo %s, se creará\n",ficheroAux);

               if(( aux = fopen(ficheroAux,"wb"))==NULL){

                    printf("\nNo se ha podido crear el fichero %s \n",ficheroAux);

               }else{

                    printf("\nSe ha creado el fichero %s correctamente \n",ficheroAux);

               }


          }else{

               printf("\nEl fichero %s se ha abierto correctamente\n",ficheroAux);
               fclose(aux);
               aux = fopen(ficheroAux,"wb");

          }


          // Declaramos el vector auxiliar para volcarlos y leemos el fichero y un
          // vector auxiliar para ordenarlos

          registros = contarRegistros(nombreFichero);
          alumnos = reservaVector(nombreFichero);


          // Bucle para la lectura

          while (fread(&alumnos[i],sizeof(struct Ficha_alumno),1,f)==1) {

               i++;
          }

          // Bucle para la ordenación

          for(i=1; i<registros; i++){

               menor = i;

                    for(k=i+1 ; k < registros ; k++){

                         if(alumnos[k].DNI > alumnos[menor].DNI){

                              k = menor;

                         }

                    }

               auxiliar = alumnos[k];
               alumnos[k] = alumnos[i];
               alumnos[i] = auxiliar;

          }

          // Escribimos en el fichero

          for(i=0;i<registros;i++){

               fwrite(&alumnos[i],sizeof(struct Ficha_alumno),1,aux);

          }


          free(alumnos);
          fclose(f);
          fclose(aux);

          if(remove(nombreFichero)==0){

               printf("\nEl fichero %s se ha borrado correctamente\n", nombreFichero);

          }else{

               printf("\nError al borrar el fichero %s\n",nombreFichero);

          }

          if((rename(ficheroAux,nombreFichero))==0){

               printf("\nSe ha cambiado el nombre de %s a %s \n",ficheroAux,nombreFichero);

          }else{

               printf("\nError al renombrar el fichero %s\n",ficheroAux);

          }

*/

}

struct Ficha_alumno * reservaVector(char * nombreFichero){

     struct Ficha_alumno * aux;
     int nRegs = 0;

     nRegs = contarRegistros(nombreFichero);

     if((aux = (struct Ficha_alumno *)calloc(sizeof(struct Ficha_alumno),nRegs))==NULL){

          printf("\nNo ha sido posible la reserva de memoria para %i elementos \n",nRegs);

     }else{

          printf("\nSe ha reservado memoria para %i elementos \n",nRegs);

     }

     return aux;

}
