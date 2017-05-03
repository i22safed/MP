#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct libro {

     char titulo[100];
     char autor[50];
     float precio;
     int unidades;

};

int comprobarExistencia(char * nombreRegistro,char * nombreLibro);
int conteoRegistros(char * nombreRegistro);
void introducirLibro(char * nombreRegistro);
void listarLibros(char * nombreRegistro,int nRegistros);
void venderLibro(char * nombreRegistro,char * nombreLibro);
void limpiarStock(char * nombreRegistro);

struct libro * reservaMemoria(int nRegistros);


int main(){

     FILE * fichero;
     char nombreRegistro[24], nombreLibro[100];
     int nRegistros = 0, opcion = 1, match = 0;

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
     

	while(opcion!=0){

	          printf("\n__________________MENU PRINCIPAL_____________________\n");

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

	               		printf("\nIntroduce el nombre del libro: ");
	               		gets(nombreLibro);
	               		
	               		match = comprobarExistencia(nombreRegistro,nombreLibro);
	               		
	               		if( match == 1 ){

	               			printf("\nEl libro %s existe en el stock\n",nombreLibro);

	               		}else{

	               			printf("\nEl libro %s no existe en el stock\n",nombreLibro);

	               		}

	               break;

	               case 2:

	                    introducirLibro(nombreRegistro);

	               break;

	               case 3:

	                    nRegistros = conteoRegistros(nombreRegistro);
	     				printf("\nEl numero de libros en el fichero es → %i\n",nRegistros);


	               break;

	               case 4:

	                    listarLibros(nombreRegistro,nRegistros);

	               break;

	               case 5:

	               	    printf("\nIntroduce el nombre del libro para vender: ");
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


int comprobarExistencia(char * nombreRegistro,char * nombreLibro){

     FILE * fichero;
     int i = 0;
     struct libro aux;

     if((fichero = fopen(nombreRegistro,"rb"))!=NULL){

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);


     }else{

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }

     while(fread(&aux, sizeof(struct libro), 1, fichero)==1){

     	if(strstr(aux.titulo,nombreLibro)!=NULL){

     		fclose(fichero);
     		return 1; 

     	}

          i++;

     }

     fclose(fichero);
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

void listarLibros(char * nombreRegistro,int nRegistros){

     FILE * fichero;
     int i = 0;
     struct libro * aux;
     int numeroRegs = 0;


     if((fichero = fopen(nombreRegistro,"rb"))!=NULL){

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);


     }else{

          printf("\nError. El fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }

     aux = reservaMemoria(nRegistros);

     while(fread(&aux[i], sizeof(struct libro), 1, fichero)==1){

          printf("\nLibro %i _____________________________________________\n",i);
          printf("\nTitulo → %s\n",aux[i].titulo);
          printf("\nAutor → %s\n",aux[i].autor);
          printf("\nPrecio → %.2f\n",aux[i].precio);
          printf("\nUnidades → %i\n",aux[i].unidades);
          printf("_____________________________________________________\n" );
          i++;

     }

     printf("\n");

     free(aux);

}


void venderLibro(char * nombreRegistro,char * nombreLibro){

	 FILE * fichero, * ficheroAux;
     char nombreAux[]="auxiliar.bin\0";
     int i = 0;
     struct libro aux;

     // Abrimos el fichero para leerlo

     if((fichero=fopen(nombreRegistro,"rb"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     // creamos un fichero auxiliar para ir volcando la información

     if((ficheroAux=fopen(nombreAux,"wb"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreAux);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreAux);

     }


     while(fread(&aux, sizeof(struct libro), 1, fichero)==1){

  		if(strstr(aux.titulo,nombreLibro)!=NULL){

  			if(aux.unidades==0){

				fwrite(&aux,sizeof(struct libro),1,ficheroAux);
				printf("\nEl libro %s posee 0 unidades\n",nombreLibro);  				

  			}else{

  				aux.unidades = aux.unidades - 1; 
  				fwrite(&aux,sizeof(struct libro),1,ficheroAux);
  				printf("\nSe ha venido una unidad del libro %s\n",nombreLibro);

  			}

  		}else{

  			fwrite(&aux,sizeof(struct libro),1,ficheroAux);
  			
  		}

     }


     fclose(fichero);
     fclose(ficheroAux);

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

	 FILE * fichero, * ficheroAux;
     char nombreAux[]="auxiliar.bin\0";
     int i = 0;
     struct libro aux;

     // Abrimos el fichero para leerlo

     if((fichero=fopen(nombreRegistro,"rb"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreRegistro);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreRegistro);

     }

     // creamos un fichero auxiliar para ir volcando la información

     if((ficheroAux=fopen(nombreAux,"wb"))==NULL){

          printf("\nEl fichero %s no se ha podido abrir\n",nombreAux);
          exit(-1);

     }else{

          printf("\nEl fichero %s se ha abierto correctamente\n",nombreAux);

     }


     while(fread(&aux, sizeof(struct libro), 1, fichero)==1){

  		if(aux.unidades==0){

  			printf("\nEl libro %s se ha eliminado del stock\n",aux.titulo);


  		}else{

  			fwrite(&aux,sizeof(struct libro),1,ficheroAux);
  			
  		}

     }


     fclose(fichero);
     fclose(ficheroAux);

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


struct libro * reservaMemoria(int nRegistros){

	struct libro * aux; 

	if((aux = (struct libro *)calloc(sizeof(struct libro),nRegistros))==NULL){

		printf("\nError en la reserva\n");
		exit(-1);

	}else{

		printf("\nSe ha reservado memoria para %i elementos\n",nRegistros);

	}

	return aux; 


}