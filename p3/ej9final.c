#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct libro{

     char titulo[50];
     char autor[50];
     float precio;
     int unidades;

};

// Funciones del programa

int existeLibro(char * nombreRegistro,char * nombreLibro);
void introducirLibro(char * nombreRegistro);
int conteoLibros(char * nombreRegistro);
void listarLibros(char * nombreRegistro,int nLibros);
struct libro * reservaMemoria(int nLibros);

int main(int argc, char ** argv){

     FILE * registro;
     struct libro * vector, unidad ;
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

                    listarLibros(nombreRegistro,nLibros);

               break;

               case 5:

               break;

               case 6:



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
     struct libro aux;

     if((f=fopen(nombreRegistro,"r"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     vector = reservaMemoria(nLibros);

     while((fscanf(f,"%s\n%s\n%f %i\n",aux.titulo,aux.autor,&aux.precio,&aux.unidades))!=EOF){

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

     free(vector);
     fclose(f);

}

struct libro * reservaMemoria(int nLibros){

     struct libros * aux;

     if((aux = (struct libro *)calloc(sizeof(struct libro), nLibros))==NULL){

          printf("\nError en la reserva \n");
          exit(-1);

     }else{

          printf("\nSe ha reservado memoria para %i elementos\n",nLibros);

     }

     return aux;

}
