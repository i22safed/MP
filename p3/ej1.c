

#include <stdio.h>

int funcionRecursiva(int inicio, int limite);


int main(){

     int inicio=0 , limite=0;
     int res=0;



     printf("\nIndicar el caso de parada de la función funcionRecursiva\n");
     printf("\nEl caso de parada de la funcionRecursiva es que el limite igual que inicio\n");

     printf("\nRealizar un esquema sobre las variaciones en la pila de control\n");
     printf("\nN/A \n");

     printf("\n¿Que resultado daría la llamada funcionRecursiva (14,10)?\n");
     res = funcionRecursiva(14,10);
     printf("\nEl resultado es → %i\n", res);


     printf("\n¿Que resultado daría la llamada funcionRecursiva (4,7)?\n");
     res=funcionRecursiva(4,7);
     printf("\nEl resultado es → %i\n", res);

     return 0;
}




int funcionRecursiva(int inicio, int limite){

     int retorno;

     if(inicio > limite){     // Manejo del error en el que inicio se mayor que
                              // limite

          retorno = -1;

     }else{

          if (inicio == limite ){       // Caso base

               retorno = 1;

          }else{                        // Lógica del programa

               retorno = inicio * funcionRecursiva(inicio+1,limite);

          }

     }

     return retorno;


}
