
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

     float tabla[2][3]={{1.1,1.2,1.3},{2.1,2.2,2.3}};

     printf("El valor de tabla es → %p ", tabla);

     printf("\n¿Cual es el significado de tabla?\n");
     printf("Es una matriz bidimensional de 2x3 expresada con aritmetica de punteros\n\n");

     printf("¿Cual es el significado de (tabla+1)?\n");
     printf("La dirección de comienzo de la tabla + 1 → %p\n\n", (tabla+1));

     printf("¿Cual es el significado de *(tabla+1)?\n");
     printf("Es un puntero a la fila 1 → %p\n\n",*(tabla+1));

     printf("¿Cual es el significado de (*(tabla+1)+1)?\n");
     printf("Puntero que apunta a la dirección de memoria tabla[1][1] → %p\n\n",(*(tabla+1)+1));

     printf("¿Cual es el significado de (*(tabla)+1)?\n");
     printf("Apuntar a la fila 0 col 1 → %p\n\n",(*(tabla)+1));

     printf("¿Cual es el valor de *(*(tabla+1)+1)?\n");
     printf("Contenido de la posición de tabla [1][1] → %f \n\n",*(*(tabla+1)+1));

     printf("¿Cual es el valor de *(*(tabla)+1)?\n");
     printf("Posición [0][1] → %f\n\n",*(*(tabla)+1));

     printf("¿Cual es el valor de *(*(tabla+1))?\n");
     printf("El valor de *(*(tabla+1)) es (pos [1][0]) → %f\n\n", *(*(tabla+1)));




     return 0;

}
