#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ej9.h"



// FUNCIONES ESPECIFICAS ////////////////////////////////////////////


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

     printf("\nIntroduzca el nombre del libro → ");
     gets(aux.titulo);
     printf("\nIntroduzca el autor del libro → ");
     gets(aux.autor);
     printf("\nIntroduzca el precio del libro → ");
     scanf("%f",&aux.precio);
     printf("\nIntroduzca las unidades del libro → ");
     scanf("%i",&aux.unidades);

     f = fopen(nombreRegistro,"a");

     if(f == NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);
     }

     fprintf(f, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades );

     fclose(f);

}

int contarLibros(char * nombreRegistro){

     FILE * f;
     int n = 0;
     struct libro aux;

     f = fopen(nombreRegistro,"r");

     if(f==NULL){

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     while((fscanf(f,"%s\n%s\n%f %i",aux.titulo,aux.autor,&aux.precio,&aux.unidades))!=EOF){

               n++;

     }

     fclose(f);

     return n;


}

void listarLibros(char * nombreLibro, int nLibros, struct libro * vector){

     FILE * f;

     int i = 0;
     struct libro aux;

     f = fopen(nombreLibro,"r");

     if(f==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreLibro);
          exit(-1);

     }

     while((fscanf(f,"%s\n%s\n%f %i",aux.titulo,aux.autor,&aux.precio,&aux.unidades))!=EOF){

          strcpy(vector[i].titulo,aux.titulo);
          strcpy(vector[i].autor,aux.autor);
          vector[i].precio = aux.precio;
          vector[i].unidades = aux.unidades;
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

     fclose(f);

}

void venderLibro(char * nombreRegistro, char * nombreLibro){

     FILE * f;
     FILE * fAux;
     struct libro aux;
     int match = 0;

     char  nombreAux[]="librosAux.txt";

     // Abrimos los ficheros

     f = fopen(nombreRegistro,"r");

     if((fAux = fopen(nombreAux,"w"))==NULL){

          printf("Error. El fichero %s no existe\n",nombreAux);
          exit(-1);

     }else{

          fclose(fAux);
          fAux = fopen(nombreAux,"w");

     }


     while((fscanf(f,"%s\n%s\n%f %i",aux.titulo,aux.autor,&aux.precio,&aux.unidades))!=EOF){

          if((strstr(aux.titulo,nombreLibro))!=NULL){

               if(aux.unidades!=0){

                    printf("\nEl libro %s ha sido vendido\n",nombreLibro);
                    fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades-1);
                    match = 1;

               }else{

                    printf("\nEl libro %s posee 0 unidades\n",nombreLibro);
                    fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades);

               }

          }else{


               fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades);

          }

     }

     if(match == 0){

          printf("\nEl libro %s no se ha encontrado\n",nombreLibro);

     }


     fclose(f);
     fclose(fAux);

     if(remove(nombreRegistro)!=0){

          printf("\nError al borrar\n");

     }else{

          printf("\nSe ha borrado el fichero \n");

     }
     if(rename(nombreAux,nombreRegistro)!=0){

          printf("\nError al cambiar el nombre\n");

     }else{

          printf("\nSe ha cambiado el nombre del fichero\n");

     }

}

void borrarLibros(char * nombreRegistro){

     FILE * f;
     FILE * fAux;
     struct libro aux;
     int match = 0;

     char  nombreAux[]="librosAux.txt";

     // Abrimos los ficheros

     f = fopen(nombreRegistro,"r");

     if((fAux = fopen(nombreAux,"w"))==NULL){

          printf("Error. El fichero %s no existe\n",nombreAux);
          exit(-1);

     }else{

          fclose(fAux);
          fAux = fopen(nombreAux,"w");

     }


     while((fscanf(f,"%s\n%s\n%f %i",aux.titulo,aux.autor,&aux.precio,&aux.unidades))!=EOF){


          if(aux.unidades==0){

               printf("\nEl libro %s ha sido eliminado del stock\n",aux.titulo);

          }else{

               fprintf(fAux, "%s\n%s\n%.2f %i\n",aux.titulo,aux.autor,aux.precio,aux.unidades);

          }

     }

     fclose(f);
     fclose(fAux);

     if(remove(nombreRegistro)!=0){

          printf("\nError al borrar\n");

     }else{

          printf("\nSe ha borrado el fichero \n");

     }
     if(rename(nombreAux,nombreRegistro)!=0){

          printf("\nError al cambiar el nombre\n");

     }else{

          printf("\nSe ha cambiado el nombre del fichero\n");

     }

}

// FUNCIONES BASICAS ////////////////////////////////////////////////


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
