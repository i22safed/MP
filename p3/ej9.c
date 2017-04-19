#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct libro{

     char titulo[24];
     char autor[24];
     float precio;
     int unidades;

};

int existenciaLibro(char * nombreRegistro,char * nombreLibro);
void introducirLibro(char * nombreRegistro);

int main(int argc, char ** argv){

     FILE * registro;
     int opcion = 1;
     int match = 0;
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

               break;

               case 4:

               break;

               case 5:

               break;

               case 6:

               break;

               case 0:

                    printf("\nAdioos!\n");
                    exit(-1);

               break;
          }
     }

     return 0;
}

// Funciones de basicas

// Funciones especificas

int existenciaLibro(char * nombreRegistro, char * nombreLibro){

     struct libro aux;
     int m = 0;

     FILE * f;

     f = fopen(nombreRegistro,"r");

     if(f==NULL){

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     // Leemos el fichero

     while((fscanf(f,"%s\n%s\n%f %i",aux.titulo,aux.autor,&aux.precio,&aux.unidades))!=EOF){

          if((strstr(aux.titulo,nombreLibro))!=NULL){

               m = 1;

          }

     }

     fclose(f);

     return m;

}

void introducirLibro(char * nombreRegistro){

     FILE * f;

     struct libro aux;

     printf("\nIntroduzca el nombre del libro → \n");
     gets(aux.titulo);
     printf("\nIntroduzca el autor del libro → \n");
     gets(aux.autor);
     printf("\nIntroduzca el precio del libro → \n");
     scanf("%f",&aux.precio);
     printf("\nIntroduzca las unidades del libro → \n");
     scanf("%i",&aux.unidades);

     f = fopen(nombreRegistro,"a");

     if(f == NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);
     }

     fprintf(f, "%s\n%s\n%.2f %i",aux.titulo,aux.autor,aux.precio,aux.unidades );

     fclose(f);

}
