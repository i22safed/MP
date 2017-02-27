#include <stdio.h>


int main(){


     int x[8]={10,20,30,40,50,70,80};

     printf("\nx → (%p) es el comienzo en memoria del vector\n",x);
     printf("x+2 → (%p) es el comienzo en memoria del vector + 2\n",x+2);
     printf("Accede a la primera posición del vector → %d\n",*x);
     printf("A la primera posición del vector le suma 2 → %d\n",(*x+2));
     printf("Accede a la posicion de comienzo + 2, es decir a la 3 → %d\n",*(x+2));

     return 0;
}
