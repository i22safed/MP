#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct libro {

     char titulo[100];
     char autor[50];
     float precio;
     int unidades;

};

int conteoRegistros(char * nombreRegistro);
void introducirLibro(char * nombreRegistro);
void listarLibros(char * nombreRegistro);


int main(){

     FILE * fichero;
     char nombreRegistro[24];
     int nRegistros = 0;

     printf("\nIntroduzca el nombre del fichero → ");
     gets(nombreRegistro);

     strcat(nombreRegistro,".bin\0");

     printf("\nEl nombre del fichero es %s\n",nombreRegistro);

     // Comprobamos si el fichero existe

     if((fichero = fopen(nombreRegistro,"rb"))==NULL){

          printf("\nEl fichero %s no existe, se creará\n",nombreRegistro);
          fichero = fopen(nombreRegistro,"wb");
          fclose(fichero);

     }else{

          fclose(fichero);

     }

     // Contamos el numero de registros para mantenerlos en el main

     nRegistros = conteoRegistros(nombreRegistro);
     printf("\nEl numero de registros en el fichero es → %i\n",nRegistros);

     // Introducimos algun libro en el registro

     //introducirLibro(nombreRegistro);

     listarLibros(nombreRegistro);


     return 0;
}

int conteoRegistros(char * nombreRegistro){

     FILE * fichero;
     int nRegs = 0;

     if((fichero = fopen(nombreRegistro,"rb"))!=NULL){

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);


     }else{

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }

     if(fseek(fichero, 0L, SEEK_END)){

          fprintf(stderr, "\nError: no puedo usar el fichero <%s>", nombreRegistro);
          exit(-1);
     }

     nRegs = ftell(fichero);

     fclose(fichero);

     return (nRegs/sizeof(struct libro));


}

void introducirLibro(char * nombreRegistro){

     FILE * fichero;
     struct libro stock;

     printf("\nIntroduzca el titulo del libro → ");
     gets(stock.titulo);
     printf("\nIntroduzca el autor → ");
     gets(stock.autor);
     printf("\nIntroduzca el precio → ");
     scanf("%f",&stock.precio);
     printf("\nIntroduzca las unidades → ");
     scanf("%i",&stock.unidades);

     if((fichero = fopen(nombreRegistro,"ab"))!=NULL){

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);


     }else{

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }

     fwrite(&stock,sizeof(struct libro),1,fichero);

     fclose(fichero);

}

void listarLibros(char * nombreRegistro){

     FILE * fichero;
     int i = 0;
     struct libro aux;
     int numeroRegs = 0;

     if((fichero = fopen(nombreRegistro,"rb"))!=NULL){

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);


     }else{

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }

     while(fread(&aux, sizeof(struct libro), 1, fichero)==1){

          printf("\nLibro %i _____________________________________________\n",i);
          printf("\nTitulo → %s\n",aux.titulo);
          printf("\nAutor → %s\n",aux.autor);
          printf("\nPrecio → %f\n",aux.precio);
          printf("\nUnidades → %i\n",aux.unidades);
          printf("_____________________________________________________\n" );
          i++;

     }

     printf("\n");

}
