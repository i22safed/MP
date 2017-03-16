#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS____________________________________________________

int ** reservarMemoria(int nFil, int nCol);


//MAIN__________________________________________________________

int main (){

     int nFil=0 , nCol=0;
     int ** matriz=NULL;

     printf("Introduzca el numero de filas. ");
     scanf("%i",&nFil);
     printf("Introduzca el numero de columnas: ");
     scanf("%i",&nCol);

     matriz=reservarMemoria(nFil,nCol);



     return 0;
}

//FUNCIONES_____________________________________________________

int ** reservarMemoria(int nFil, int nCol){

     int ** M;
     int i, j, error=0;

     M = (int **)malloc(nFil*sizeof(int*));

     for(i=0; i<nFil;i++){

          M[i]=(int *)malloc(nCol*sizeof(int));

     }

     printf("\nLa memoria ha sido reservada correctamente\n");
     return (M);

}
