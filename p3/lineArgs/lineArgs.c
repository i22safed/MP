#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char ** argv){

     int i=0;


     printf("\nEl numero de argumentos es → %i",argc);

     for(i=1;i<argc;i++){

          printf("\nNumero %i es → %i",i,atoi(argv[i]));
          
     }

     printf("\n");


     return 0;
}
