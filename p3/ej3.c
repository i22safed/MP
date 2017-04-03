#include <stdio.h>


int divisionRecursiva(int dividendo,int divisor, int cociente, int resto);


int main(){


     int dividendo=0,divisor=0,cociente=0,resto=0;

     printf("\nIntroduzca el dividendo → ");
     scanf("%i",&dividendo);
     printf("\nIntroduzca el divisor → ");
     scanf("%i",&divisor);

     cociente = divisionRecursiva(dividendo,divisor,cociente,resto);

     printf("\nEl resultado de la división de %i entre %i es → %i\n",  dividendo,divisor,cociente);

     return 0;

}


int divisionRecursiva(int dividendo,int divisor, int cociente, int resto){

     if(dividendo < divisor){

          return cociente;

     }else{

          dividendo = divisionRecursiva((dividendo - divisor),divisor,cociente+1,resto);

     }



}
