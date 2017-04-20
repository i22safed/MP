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
int contarLibros(char * nombreRegistro);
void listarLibros(char * nombreRegistro, int nLibros, struct libro * vector);
void venderLibro(char * nombreRegistro, char * nombreLibro);

struct libro * reservaMemoria(int nLibros);


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

                    printf("\nIntroduzca el nombre del libro\n");
                    gets(nombreLibro);



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
