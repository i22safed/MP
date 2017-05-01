#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ej9.h"

int main(int argc, char ** argv){

     FILE * registro;
     struct libro * vector, unidad;
     int opcion = 1, match = 0, nLibros = 0;
     char nombreLibro[50];

     /// Comprobamos el numero de argumentos que se le han pasado al fichero

     if(argc==1){

          printf("Error. No se ha pasado ningun parametro\n");
          exit(-1);

     }

     char nombreRegistro[20];           // Para mantener el nombre del fichero
     strcpy(nombreRegistro,argv[1]);    // El nombre del registro será pasado
     strcat(nombreRegistro,".txt\0");   // por linea de ordenes

     printf("\nEl nombre del fichero es %s\n",nombreRegistro);


     /// Comprobamos la existencia del fichero

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

     /// Menú del programa

     while(opcion!=0){

          printf("\n_________MENU PRINCIPAL_________\n");

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


                    printf("\nIntroduzca nombre del libro → ");
                    gets(nombreLibro);

                    match = existeLibro(nombreRegistro,nombreLibro);

                    if(match==1){

                         printf("\nEl libro %s existe\n",nombreLibro);

                    }else{

                         printf("\nNo se ha encontrado el libro: %s\n",nombreLibro);

                    }

               break;

               case 2:

                    introducirLibro(nombreRegistro);

               break;

               case 3:

                    nLibros = conteoLibros(nombreRegistro);
                    printf("\nEl numero de libros en stock es → %i\n",nLibros);


               break;

               case 4:


                    listarLibros(nombreRegistro,nLibros,vector);


               break;

               case 5:

                    printf("\nIntroduzca el nombre del libro que desea vender → ");
                    gets(nombreLibro);
                    venderLibro(nombreRegistro,nombreLibro);

               break;

               case 6:

                    limpiarStock(nombreRegistro);

               break;

               case 0:

                    printf("\nAdioos!\n");
                    exit(-1);

               break;
          }
     }

     return 0;

}
