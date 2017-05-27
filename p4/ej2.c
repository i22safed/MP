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
void ordenar(char * nombreFichero, char * orden);

// Funciones adicionales
struct Ficha_alumno * reservaVector(char * nombreFichero);


int main(int argc,char **argv){

     struct Ficha_alumno alumno;
     struct Ficha_alumno * vector;
     int nRegistros = 0, op = 1, i = 0;
     char nombreFichero[20],orden[12];


     if(argc != 3){

          printf("\nEl formato de los argumentos es ./salida.exe alumnos.bin ascendente/descendente\n");
          return 0;

     }

     strcpy(nombreFichero,argv[1]);
     printf("\nEl nombre del fichero es → %s\n",nombreFichero);


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

                    ordenar(nombreFichero,orden);

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

void ordenar(char * nombreFichero, char * orden){

     void (*or)(char *);

     if((strcmp(orden,"ascendente"))!=0){

          printf("\norden ascendente\n");
          or = &ascendente


     }else{

          printf("\norden descendente\n");
          or = &descendente;

     }

}

void ascendente(char * nombreFichero){

     FILE * f, * aux;              // Fichero original y binario

     ficheroAux[20] = "alumnosAux.bin";

     if((f = fopen(nombreFichero,"rb"))==NULL){

          

     }


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
