#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos{

     char nombre[20];
     char apellido[20];
     char DNI[10];
     int edad;

};

void escribePersona(char * nombreFichero);
void listarPersonas(char * nombreFichero);
int nRegistros(char * nombreFichero);
void borrarPersona(char * nombreFichero, char * nombrePersona);

int main (){

     char nombreFichero[]="personas.bin\0";
     int nReg;
     char nombrePersona[20];


     escribePersona(nombreFichero);
     listarPersonas(nombreFichero);
     nReg = nRegistros(nombreFichero);

     printf("\nEl numero de registros en el fichero es → %i\n",nReg);

     printf("\nIntroduzca el nombre de la persona → ");
     getchar();
     gets(nombrePersona);

     borrarPersona(nombreFichero, nombrePersona);

     nReg = nRegistros(nombreFichero);

     printf("\nEl registro de %s ha sido eliminado y el numero de registros es %i\n",nombrePersona,nReg);

}


void escribePersona(char * nombreFichero){

     FILE * f;
     struct datos persona;


     if((f=fopen(nombreFichero,"rb"))==NULL){

          printf("\nError al abrir el fichero\n");
          exit(-1);

     }else{

          printf("\nEl fichero se ha abierto correctamente\n");
          fclose(f);
          f = fopen(nombreFichero,"ab");

     }


     printf("\nIntroduzca el nombre de la persona: ");
     gets(persona.nombre);
     printf("\nIntroduzca el apellido de la persona: ");
     gets(persona.apellido);
     printf("\nIntroduzca el DNI de la persona: ");
     gets(persona.DNI);
     printf("\nIntroduzca la edad de la persona: ");
     scanf("%i",&persona.edad);

     fwrite(&persona,sizeof(struct datos),1,f);

     fclose(f);


}
void listarPersonas(char * nombreFichero){

     FILE * f;
     struct datos aux;

     if((f = fopen(nombreFichero,"rb"))==NULL){

          printf("\nNo se ha podido abrir el fichero\n");
          exit(-1);

     }else{

          printf("\nEl fichero se ha abierto correctamente\n");

     }

     while(fread(&aux,sizeof(struct datos),1,f)==1){

          printf("\nEl nombre de la persona es → %s\n",aux.nombre);
          printf("\nEl apellido de la persona es → %s\n",aux.apellido);
          printf("\nEl DNI de la persona es → %s\n",aux.DNI);
          printf("\nLa edad de la persona es → %i\n",aux.edad);

     }

     fclose(f);

}

int nRegistros(char * nombreFichero){

     FILE * f;

     int nRegistros = 0;

     if((f = fopen(nombreFichero,"rb"))==NULL){

          printf("\nNo se ha podido abrir el fichero\n");
          exit(-1);

     }else{

          printf("\nEl fichero se ha abierto correctamente\n");

     }


     if(fseek(f,0L,SEEK_END)){

          printf("\nEl fichero no se ha podido utilizar\n");
          exit(-1);

     }

     nRegistros = ftell(f);

     fclose(f);

     return nRegistros/sizeof(struct datos);

}

void borrarPersona(char * nombreFichero, char * nombrePersona){

     FILE * f;
     FILE * aux;
     struct datos persona;

     char nombreAux[]="auxiliar.bin";

     if((f = fopen(nombreFichero,"rb"))==NULL){

          printf("\nError al abrir el fichero\n");
          exit(-1);

     }else{

          printf("\nEl fichero %s ha sido abierto correctamente\n",nombreFichero);

     }


     if((aux = fopen(nombreAux,"wb"))==NULL){

          printf("\nError al abrir el fichero\n");
          exit(-1);

     }else{

          printf("\nEl fichero %s ha sido abierto correctamente\n",nombreAux);

     }

     while(fread(&persona,sizeof(struct datos),1,f)==1){

               if(strstr(persona.nombre,nombrePersona)==NULL){

                    fwrite(&persona,sizeof(struct datos),1,aux);

               }

     }

     fclose(f);
     fclose(aux);

     if(remove(nombreFichero)!=0){

          printf("\nError en la operacion de borrado \n");
          exit(-1);

     }
     if((rename(nombreAux,nombreFichero))!=0){

          printf("\nError en la operacion de renombrado\n");

     }

}
