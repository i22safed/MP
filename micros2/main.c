#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos{

     char nombre[20], apellidos[40],  DNI[9];
     int saldo;

};
/*
Ruleta UCO

Funciones para ruleta.h

     · Añadir jugadores: Esta función creará un fichero con los parametros (que
     serán recogidos en el main) de struct jugador (nombre, jugador, DNI, saldo
     3 strings y 1 int). El formato del fichero sera DNINombre.txt (46XXXJose.txt).

     El nombre del jugador deberá de ser pasado por lineas de ordenes para
     realizar las operaciones pertinentes

     · CambiarJugador: Cambia el jugador activo

     · Listar jugadores: Lista los jugadores y todos sus respectivos datos,
     reservando previamente vector de tipo struct

     · Recargar saldo: Recarga el saldo de los usuario que estén en negativo

     · datos2Binario: Pasa los ficheros .txt a .bin

Funciones para jugador.h

     · Hacer Apuesta: Realiza una apuesta

          · Tipo 1 → 1-18 / 19-36 (Sin contar el 0)
          · Tipo 2 → Par / Impar
          · Tipo 3 → Numero

     Se debera almacenar las apuestas realizadas por el usuario activo almacenan
     dolas en el fichero pertinente a continuación de los datos del mismo con el
     formato siguiente:

          Tipo | Beneficio
          --------------------------
            2  | +1000
            1  | +205
            4  | -80
            5  | +100

     · Historial de apuestas: Listar las apuestas del usuario activo

     · Salir: Finaliza la ejecución del programa

Funciones adicionales

     · ReservaVector: Reservará memoria para el numero de jugadores que haya en
     la base de datos para poder listarlos

     · LimpiarLinea: Borra el \n de las cadenas recogidas con gets y lo sustituye
     por \0

Todo ello deberá ir acompañado por un makefile que compile todo el programa y
cree bibliotecas con todos sus .o pertinentes y limpie los .o resultantes.


*/

struct datos limpiarCadena(struct datos jugador);


int main (int argc,char ** argv){

     int opcion = 1;
     struct datos jugador;

     while (opcion!=0) {

          printf("\n________________MENU DE LA RULETA________________\n");

          printf("\n1. Introducir jugador");
          printf("\n2. Hacer apuesta");
          printf("\n3. Consultar historial de apuestas");
          printf("\n4. Balance de jugadores");
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

                    addPlayer(jugador);

                    printf("\nEl jugador %s %s ha sido añadido\n",jugador.nombre,jugador.apellidos);

               break;
               case 2:


               break;
               case 3:


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

void addPlayer(struct datos jugador){

     /*

          Esta funcion se encargará de crear un fichero por cada jugador añadido
          en dicho fichero se mantendrán los datos personales como el balance del
          saldo del jugador

          El identificativo de cada jugador (y a su vez el nombre del fichero)
          será el DNI

          primero tomaremos las cadenas y le quitaremos el \n y le pondremos
          \0

     */

     FILE * f;      // Puntero del jugador
     struct datos aux;
     char nombreFichero[40];

     aux = limpiarCadena(jugador);

     strcpy(nombreFichero,aux.DNI);
     strcat(nombreFichero,aux.nombre);
     strcat(nombreFichero,".txt");

     printf("\nEl nombre del fichero es %s\n",nombreFichero);

     if((f=fopen(nombreFichero,"r"))==NULL){

          printf("\nEl fichero %s no existe, se creará\n",nombreFichero);
          f = fopen(nombreFichero,"w");


     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreFichero);
          fclose(f);
          f = fopen(nombreFichero,"a");

     }

     fprintf(f, "%s\n%s\n%s %i\n",aux.nombre,aux.apellidos,aux.DNI,jugador.saldo);

     fclose(f);

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
