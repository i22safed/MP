
/*

5.  Escribe un programa que lea una frase y, a partir de ella, cree un vector
dinámico de cadenas con las diferentes palabras de la frase. A partir de este
vector, el programa deberá:

     · Calcular la longitud media de las palabras de la frase, así como la
     longitud mayor y menor (usando paso de parámetros por referencia).
     · Construir un vector dinámico con la frecuencia de aparición de cada
     longitud.

Realiza una adecuada modularización, implementando todas las funciones que sean
necesarias.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** reservarMemoria(char * cadena, int * palabras, int * caracteres);
void rellenaMatriz(char ** vCad,char * cadena, int palabras, int * caracteres);
void imprimeMatriz(char ** vCad, int palabras, int * caracteres);
float calcularMedia(int * caracteres, int palabras);
int * vectorFrec(int * caracteres, int palabras);



int main(){

     // Declaramos la cadena y tambien declaramos la matriz que  se reservará
     // de manera irregular

     char cadena[100];
     char ** vCad;
     float media=0;
     int palabras=0;
     int caracteres[10],i=0;
     int * vFrec;

     // Declaramos una matriz que se asignará de manera irregular

     printf("Introduzca una frase → ");
     gets(cadena);

     vCad = reservarMemoria(cadena,&palabras,caracteres);

     rellenaMatriz(vCad,cadena,palabras,caracteres);
     imprimeMatriz(vCad,palabras,caracteres);
     media = calcularMedia(caracteres,palabras);

     printf("\nLa media es de la longuitud de las palabras es → %.2f letras\n",media);

     vFrec = vectorFrec(caracteres,palabras);

     return 0;
}

char ** reservarMemoria(char * cadena, int * palabras, int * caracteres){

     int i=0,j=0;
     int espacios=0;
     char ** tabla;

     // Primeramente hallamos los espacios de la cadena para hallar en numero
     // de palabras

     for(i=0;i<strlen(cadena);i++){

          if(cadena[i]==' '){

               espacios++;

          }
     }


     *palabras = espacios + 1;

     for(i=0;i<*palabras;i++){

          caracteres[i]=0;

     }


     // Detectamos todos los parametros adicionales para la reserva de memoria

     for (i=0;i<strlen(cadena);i++){

          if(cadena[i]!=' '){

               caracteres[j] = caracteres[j] + 1;

          }else{

               j++;

          }
     }

     // Reservamos memoria para la matriz irregular

     printf("\nEl numero de espacios es → %i",espacios );

     for(i=0;i<*palabras;i++){

          printf("\nEl numero de caracteres de %i es → %i",i,caracteres[i]);

     }

     printf("\n");


     if((tabla = (char **)malloc((*palabras)* sizeof(int*)))==NULL){


          printf("\nError. No ha sido posibe la reserva de memoria");
          exit (-1);

     }else{

          printf("\nLa reserva de memoria para %d elementos se ha realizado correctamente\n",*palabras);

     }

     for(i=0;i<*palabras;i++){

          if((tabla[i]=(char*)malloc(caracteres[i]*sizeof(char)))==NULL){

               printf("\nError. Fallo en la reserva de memoria");
               exit (-1);

          }else{

               printf("\nLa reserva de memoria para %i elementos se ha realizado de manera correcta\n",caracteres[i]);

          }

     }



     return (tabla);

}

void rellenaMatriz(char ** vCad,char * cadena, int palabras, int * caracteres){

     int i=0,j=0,k=0;


     for(i=0;i<palabras;i++){

          for(j=0;j<caracteres[i];j++){

               if(cadena[k]!=' '){

                    vCad[i][j]=cadena[k];
                    k++;

               }else{

                    k++;
               }
          }
     }

}

void imprimeMatriz(char ** vCad, int palabras, int * caracteres){


     int i=0,j=0;

     for(i=0;i<palabras;i++){

          for(j=0;j<caracteres[i];j++){

               printf("%c",vCad[i][j]);
          }

          printf("\n");
     }

}

float calcularMedia(int * caracteres, int palabras){

     int i=0;
     float med=0;


     for(i=0;i<palabras;i++){

          med = med + caracteres[i];

     }

     return (med/palabras);

}

int * vectorFrec(int * caracteres, int palabras){

     int i=0;
     int * vFrec;

     if((vFrec=(int *)malloc(palabras*sizeof(int)))==NULL){

          printf("\nError no ha sido posible la reserva para %i elementos\n",palabras);

     }else{

          printf("\nLa reserva para %i elementos se ha realizado de manera correcta",palabras);
     }


     return vFrec;
}
