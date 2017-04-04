#include <stdio.h>
#include <string.h>


int contarCaracter(char * cadena,char caracter, int n,int i);

int main (){

     char cadena[100];
     int i=0,n=0;
     char caracter='a';

     printf("\nIntroduzca una cadena → ");
     gets(cadena);
     printf("\nIntroduzca un caracter → ");
     scanf("%c",&caracter);

     n = contarCaracter(cadena,caracter,n,i);

     printf("\nEl numero de apariciones del caracter %c es → %i\n",caracter,n);

     return 0;
}


int contarCaracter(char * cadena,char caracter, int n, int i){


     if(*(cadena+i)=='\0'){

          return n;

     }else{

          if(*(cadena+i)==caracter){


               n = contarCaracter(cadena,caracter,n+1,i+1);

          }else{

               n = contarCaracter(cadena,caracter,n,i+1);

          }

     }

}
