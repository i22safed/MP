#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ej9.h"

int existeLibro(char * nombreRegistro,char * nombreLibro){

     FILE * f;
     char aux[50];
     int i = 0;

     if((f=fopen(nombreRegistro,"r"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }


     while((fgets(aux,50,f))!=NULL){

          if(i%3==0){

               if(strstr(aux,nombreLibro)!=NULL){

                    return 1;

               }
          }

     i++;

     }

     fclose(f);

}

void introducirLibro(char * nombreRegistro){

     FILE * f;
     struct libro aux;

     printf("\nIntroduzca el titulo del libro → ");
     gets(aux.titulo);
     printf("\nIntroduzca el autor → ");
     gets(aux.autor);
     printf("\nIntroduzca el precio → ");
     scanf("%f",&aux.precio);
     printf("\nIntroduzca las unidades → ");
     scanf("%i",&aux.unidades);

     if((f=fopen(nombreRegistro,"a"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     fprintf(f, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades);

     fclose(f);

}

int conteoLibros(char * nombreRegistro){

     FILE * f;
     int i = 0;
     char aux[50];

     if((f=fopen(nombreRegistro,"r"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     while((fgets(aux,50,f))!=NULL){

          i++;

     }

     fclose(f);

     return i/3;

}

void listarLibros(char * nombreRegistro,int nLibros,struct libro * vector){

     FILE * f;
     int i = 0;
     float precio = 0; int unidades = 0;
     char cad[50];

     if((f=fopen(nombreRegistro,"r"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     vector = reservaMemoria(nLibros);

     while((fgets(cad,50,f))!=NULL){    // Para el titulo

          if(cad[strlen(cad)-1]=='\n'){

               cad[strlen(cad)-1]='\0';

          }
          strcpy(vector[i].titulo,cad);

          // Para el autor

          fgets(cad,50,f);
          if(cad[strlen(cad)-1]=='\n'){

               cad[strlen(cad)-1]='\0';

          }
          strcpy(vector[i].autor,cad);

          // Precio y unidades

          fgets(cad,50,f);
          sscanf(cad,"%f %i",&precio,&unidades);
          vector[i].precio = precio;
          vector[i].unidades = unidades;

          i++;

     }

     for(i=0;i<nLibros;i++){

          printf("\nLibro %i _____________________________________________\n",i);
          printf("\nTitulo → %s\n",vector[i].titulo);
          printf("\nAutor → %s\n", vector[i].autor);
          printf("\nPrecio → %.2f€\n", vector[i].precio);
          printf("\nUnidades → %i\n", vector[i].unidades);
          printf("_____________________________________________________\n" );

     }

     free(vector);
     fclose(f);

}

void venderLibro(char * nombreRegistro,char * nombreLibro){

     FILE * f, * fAux;
     char nombreAux[]="auxiliar.txt";
     int i = 0, match = 0;
     float precio = 0; int unidades = 0;
     char cad[50];
     struct libro aux;

     // Abrimos el fichero para leerlo

     if((f=fopen(nombreRegistro,"r"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     // creamos un fichero auxiliar para ir volcando la información

     if((fAux=fopen(nombreAux,"w"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreAux);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreAux);

     }


     while((fgets(cad,50,f))!=NULL){    // Para el titulo

          if(cad[strlen(cad)-1]=='\n'){

               cad[strlen(cad)-1]='\0';

          }

          strcpy(aux.titulo,cad);
          // Para el autor
          fgets(cad,50,f);

          if(cad[strlen(cad)-1]=='\n'){

               cad[strlen(cad)-1]='\0';

          }

          strcpy(aux.autor,cad);
          // Precio y unidades
          fgets(cad,50,f);
          sscanf(cad,"%f %i",&precio,&unidades);
          aux.precio = precio;
          aux.unidades = unidades;

          // En caso de que no sea el libro para vender

          if((strstr(aux.titulo,nombreLibro))!=NULL){

               if(aux.unidades!=0){

                    printf("\nEl libro %s ha sido vendido\n",nombreLibro);
                    fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades-1);
                    match = 1;

               }else{

                    printf("\nEl libro %s posee 0 unidades\n",nombreLibro);
                    fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades);
                    match = 1;

               }

          }else{


               fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades);

          }


          i++;

     }

     if(match==1){

          printf("\nEl libro %s se ha vendido correctamente\n",nombreLibro);

     }else{

          printf("\nEl libro %s no se ha encontrado en el stock\n",nombreLibro);

     }


     fclose(f);
     fclose(fAux);

     // Borrado y renombrado de ficheros

     if(remove(nombreRegistro)!=0){

          printf("\nEl fichero %s no se ha podido borrar\n",nombreRegistro);

     }else{

          printf("\nOperacion de borrado de fichero realizada con exito\n");

     }
     if((rename(nombreAux,nombreRegistro))!=0){

          printf("\nError en la operacion de renombrado\n");

     }else{

          printf("\nNombre de fichero cambiado %s → %s \n",nombreAux,nombreRegistro);

     }


}

void limpiarStock(char * nombreRegistro){

     FILE * f, * fAux;
     char nombreAux[]="auxiliar.txt";
     int i = 0, match = 0;
     float precio = 0; int unidades = 0;
     char cad[50];
     struct libro aux;

     // Abrimos el fichero para leerlo

     if((f=fopen(nombreRegistro,"r"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     // creamos un fichero auxiliar para ir volcando la información

     if((fAux=fopen(nombreAux,"w"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreAux);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreAux);

     }


     while((fgets(cad,50,f))!=NULL){    // Para el titulo

          if(cad[strlen(cad)-1]=='\n'){

               cad[strlen(cad)-1]='\0';

          }

          strcpy(aux.titulo,cad);
          // Para el autor
          fgets(cad,50,f);

          if(cad[strlen(cad)-1]=='\n'){

               cad[strlen(cad)-1]='\0';

          }

          strcpy(aux.autor,cad);
          // Precio y unidades
          fgets(cad,50,f);
          sscanf(cad,"%f %i",&precio,&unidades);
          aux.precio = precio;
          aux.unidades = unidades;

          // En caso de que no sea el libro para vender

          if(aux.unidades!=0){

               fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades);

          }else{

               printf("\nEl libro %s se ha borrado\n",aux.titulo);
               match = 1;

          }


          i++;

     }

     if(match == 0){

          printf("\nEl stock no ha sido modificado\n");

     }

     fclose(f);
     fclose(fAux);

     // Borrado y renombrado de ficheros

     if(remove(nombreRegistro)!=0){

          printf("\nEl fichero %s no se ha podido borrar\n",nombreRegistro);

     }else{

          printf("\nOperacion de borrado de fichero realizada con exito\n");

     }
     if((rename(nombreAux,nombreRegistro))!=0){

          printf("\nError en la operacion de renombrado\n");

     }else{

          printf("\nNombre de fichero cambiado %s → %s \n",nombreAux,nombreRegistro);

     }


}

struct libro * reservaMemoria(int nLibros){

     struct libro * aux;

     if((aux = (struct libro *)calloc(sizeof(struct libro), nLibros))==NULL){

          printf("\nError en la reserva\n");
          exit(-1);

     }else{

          printf("\nSe ha reservado memoria para %i elementos \n",nLibros);

     }

     return aux;


}
