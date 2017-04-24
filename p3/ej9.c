#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ej9.h"

int main(int argc, char ** argv){

     struct libro * vector;
     FILE * registro;
     int opcion = 1,match = 0, nLibros=0;
     char nombreLibro[24];

     // Comprobamos si han pasado el nombre del fichero por linea de ordenes

     if(argc==1){

          printf("Error. No se ha pasado ningun parametro\n");
          exit(-1);

     }

     char nombreRegistro[20];           // Para mantener el nombre del fichero
     strcpy(nombreRegistro,argv[1]);    // El nombre del registro será pasado
     strcat(nombreRegistro,".txt\0");   // por linea de ordenes

     printf("\nEl nombre del fichero es: %s\n",nombreRegistro);

     // Comprobamos la existencia del fichero

     if((registro = fopen(nombreRegistro,"r"))==NULL){

          printf("\nEl fichero no existe %s, será creado\n",nombreRegistro);
          registro = fopen(nombreRegistro,"w");

          if(registro!=NULL){

               printf("\nEl fichero %s se ha creado correctamente\n",nombreRegistro);
               fclose(registro);

          }else{

               printf("Error. El fichero %s no ha sido posible crearlo \n",nombreRegistro);
               exit(-1);
          }


     }else{

          fclose(registro);

     }

     // Menu del programa

     while(opcion!=0){

          printf("\n1. Comprobar existencia del libro en el stock");
          printf("\n2. Introducir nuevo libro en el stock");
          printf("\n3. Contar el numero de libros de diferentes del stock");
          printf("\n4. Listar libros del stock");
          printf("\n5. Vender libro del stock ");
          printf("\n6. Borrar libro que no tenga unidades en stock");
          printf("\n0. Salir\n");

          printf("\nElija una opcion → ");
          scanf("%i",&opcion);
          getchar();

          switch (opcion) {

               case 1:

                    printf("\nIntroduzca el nombre del libro a buscar → ");
                    gets(nombreLibro);
                    match = existenciaLibro(nombreRegistro,nombreLibro);
                    if(match == 1){

                         printf("\nEl libro %s existe \n",nombreLibro);

                    }else{

                         printf("\nEl libro %s no existe \n",nombreLibro);

                    }

               break;

               case 2:

                    introducirLibro(nombreRegistro);

               break;

               case 3:

                    nLibros = contarLibros(nombreRegistro);
                    printf("\nEl numero de libros es %i\n",nLibros);

               break;

               case 4:

                    // Primeramente comprobamos que el numero de libros es dto 0

                    if(nLibros!=0){

                         vector = reservaMemoria(nLibros);
                         listarLibros(nombreRegistro,nLibros,vector);


                    }else{

                         printf("\nNo se han encontrado libros\n");
                         exit(-1);

                    }


               break;

               case 5:

                    printf("\nIntroduzca el nombre del libro: ");
                    gets(nombreLibro);
                    venderLibro(nombreRegistro,nombreLibro);


               break;

               case 6:

                    printf("\nSe van a borrar los libros que no poseen unidades\n");
                    borrarLibros(nombreRegistro);

               break;

               case 0:

                    printf("\nAdioos!\n");
                    free(vector);
                    exit(-1);

               break;
          }
     }



     return 0;
}
