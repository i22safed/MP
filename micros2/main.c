#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos{

     char nombre[20], apellidos[40],  DNI[9];
     int saldo;

};


// Funciones de Ruleta.h
void addPlayer(struct datos jugador, char * jugadores);
void listarJugadores(char * jugadores, int * numeroJugadores);
char * activarJugador(char * jugadores, int opJugador);
// Funciones adicionales
struct datos limpiarCadena(struct datos jugador);


int main (int argc,char ** argv){

     int opcion = 1;
     struct datos jugador;
     char jugadores[]="Jugadores.txt";
     char jugadorActivo[30];
     int numeroJugadores = 0,opJugador=0;

     while (opcion!=0) {

          printf("\n________________MENU DE LA RULETA________________\n");

          printf("\n1. Introducir jugador");
          printf("\n2. Listar jugadores");
          printf("\n3. Cambiar jugador");
          printf("\n4. Hacer apuesta");
          printf("\n5. Consultar historial de apuestas");
          printf("\n6. Balance de jugadores");
          printf("\n0. Salir");

          printf("\n_________________________________________________\n");

          printf("\nElija una opción: ");
          scanf("%d",&opcion);
          getchar();


          switch (opcion) {

               case 1:

                    printf("\nIntroduzca el nombre del jugador → ");
                    gets(jugador.nombre);
                    printf("\nIntroduzca los apellidos del jugador → ");
                    gets(jugador.apellidos);
                    printf("\nIntroduzca el DNI del jugador → ");
                    gets(jugador.DNI);
                    printf("\nIntroduzca el saldo del jugador → ");
                    scanf("%i",&jugador.saldo);

                    addPlayer(jugador,jugadores);

                    printf("\nEl jugador %s %s ha sido añadido\n",jugador.nombre,jugador.apellidos);

               break;
               case 2:

                    printf("\n____________________JUGADORES____________________\n");

                    listarJugadores(jugadores,&numeroJugadores);

                    printf("\n_________________________________________________\n");


               break;
               case 3:

                    printf("\n¿ Que jugador desea activar ?\n");

                    listarJugadores(jugadores,&numeroJugadores);

                    printf("\nOpcion → \n");
                    scanf("%i",&opJugador);

                    jugadorActivo = activarJugador(jugadores,opJugador);

                    printf("\nEl jugador activo ahora es → %s \n",jugadorActivo);


               break;
               case 4:

               break;
               case 5:

                    exit(-1);

               break;


          }

     }


     return 0;

}

void addPlayer(struct datos jugador,char * jugadores){

     /*

          Esta funcion se encargará de crear un fichero por cada jugador añadido
          en dicho fichero se mantendrán los datos personales como el balance del
          saldo del jugador

          Tambien se almacenarán los jugadores en un fichero para listarlos

          El identificativo de cada jugador (y a su vez el nombre del fichero)
          será el DNI

          primero tomaremos las cadenas y le quitaremos el \n y le pondremos
          \0

     */

     FILE * f;                // Puntero del fichero del jugador
     FILE * nJugadores;       // Puntero de la base de datos de la Ruleta

     struct datos aux;
     char nombreFichero[40];

     aux = limpiarCadena(jugador);

     strcpy(nombreFichero,aux.DNI);
     strcat(nombreFichero,aux.nombre);
     strcat(nombreFichero,".txt");

     printf("\nEl nombre del fichero es %s\n",nombreFichero);

     // Abrimos el fichero para escribir los datos de los jugadores

     if((f=fopen(nombreFichero,"r"))==NULL){

          printf("\nEl fichero %s no existe, se creará\n",nombreFichero);
          f = fopen(nombreFichero,"w");


     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreFichero);
          fclose(f);
          f = fopen(nombreFichero,"a");

     }

     // Escribimos los datos de los jugadores

     fprintf(f, "%s\n%s\n%s %i\n",aux.nombre,aux.apellidos,aux.DNI,jugador.saldo);

     // Escribimos los nombres de los jugadores en un fichero a modo de base de
     // datos

     if(( nJugadores = fopen(jugadores,"r"))==NULL){

          printf("\nEl fichero %s no existe, se creará\n",jugadores);
          nJugadores = fopen(jugadores,"a");

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",jugadores);
          fclose(nJugadores);
          nJugadores = fopen(jugadores,"a");

     }

     // Escribimos los nombres de los distintos jugadores (suponemos que no hay
     // repetidos)

     fprintf(nJugadores,"%s %s %s %i\n",aux.nombre,aux.apellidos,aux.DNI,jugador.saldo);

     fclose(nJugadores);
     fclose(f);

}

void listarJugadores(char * jugadores, int * numeroJugadores){


     FILE * nJugadores;
     struct datos aux;
     char cad[100];
     int i=0;


     if((nJugadores = fopen(jugadores,"r"))==NULL){

          printf("\nError al abrir el fichero %s \n",jugadores);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",jugadores);

     }

     while((fgets(cad,100,nJugadores))!=NULL){

          *numeroJugadores = *numeroJugadores + 1;

          sscanf(cad,"%s %s %s %i\n",aux.nombre,aux.apellidos,aux.DNI,&aux.saldo);
          printf("\nJugador %i:\n\n",i);
          printf("Nombre → %s\n",aux.nombre);
          printf("Apellidos → %s\n",aux.apellidos);
          printf("DNI → %s\n",aux.DNI);
          printf("Saldo → %i\n",aux.saldo);
          i++;

     }

}

char * activarJugador(char * jugadores, int opJugador){

     FILE * f;
     char cad[100];
     char id[30];
     int i = 0;
     struct datos aux;


     if((f = fopen(jugadores,"r"))==NULL){

          printf("\nError al abrir el fichero %s\n",jugadores);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",jugadores);

     }

     while((fgets(cad,"%s %s %s %i\n",f))!=NULL){

          sscanf(cad,"%s %s %s %i\n",aux.nombre,aux.apellidos,aux.DNI,&aux.saldo);

               if(i == opJugador){

                    strcpy(id,aux.DNI);
                    strcat(id,aux.nombre);

                    return id;

               }

          i++;

     }




}

struct datos limpiarCadena(struct datos jugador){

     struct datos aux;

     // Para nombre

     strcpy(aux.nombre,jugador.nombre);

     if(aux.nombre[strlen(aux.nombre)-1]=='\n'){

          aux.nombre[strlen(aux.nombre)-1]='\0';

     }

     // Para apellidos

     strcpy(aux.apellidos,jugador.apellidos);

     if(aux.apellidos[strlen(aux.apellidos)-1]=='\n'){

          aux.apellidos[strlen(aux.apellidos)-1]='\0';

     }

     // Para DNI

     strcpy(aux.DNI,jugador.DNI);

     if(aux.DNI[strlen(aux.DNI)-1]=='\n'){

          aux.DNI[strlen(aux.DNI)-1]='\0';

     }

     return aux;

}
