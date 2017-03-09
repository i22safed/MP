
#include <stdio.h>

/*

1.  Supón una matriz dinámica (float ** tabla) de 2x3 elementos, con los
siguientes valores. { {1.1, 1.2, 1.3}, {2.1.,2.2, 2.3}}

     · ¿Cual es el significado de tabla?
     · ¿Cual es el significado de (tabla+1)?
     · ¿Cual es el significado de *(tabla+1)?
     · ¿Cual es el significado de (*(tabla+1)+1)?
     · ¿Cual es el significado de (*(tabla)+1)?
     · ¿Cual es el valor de *(*(tabla+1)+1)?
     · ¿Cual es el valor de *(*(tabla)+1)?
     · ¿Cual es el valor de *(*(tabla+1))?

*/


int main(){

     float ** tabla[2][3]={{1.1,2.1,3.1},{1.2,2.2,2.3}};

     printf("\n¿Cual es el significado de tabla?\n");
     printf("Es una matriz bidimensional de 2x3 expresada con aritmetica de punteros\n\n");

     printf("¿Cual es el significado de (tabla+1)?\n");
     printf(" \n\n");

     printf("¿Cual es el significado de *(tabla+1)?\n");
     printf(" \n\n");

     printf("¿Cual es el significado de (*(tabla+1)+1)?\n");
     printf(" \n\n");

     printf("¿Cual es el significado de (*(tabla)+1)?\n");
     printf(" \n\n");

     printf("¿Cual es el valor de *(*(tabla+1)+1)?\n");
     printf(" \n\n");

     printf("¿Cual es el valor de *(*(tabla)+1)?\n");
     printf(" \n\n");

     printf("¿Cual es el valor de *(*(tabla+1))?\n");
     printf("El valor de *(*(tabla+1)) es → %p\n\n", *(*(tabla+1)));




     return 0;

}
