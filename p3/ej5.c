#include <stdio.h>



int sumaDigitos(int numero,int suma);


int main(){

     int numero=0;
     int suma=0;

     printf("\nIntroduzca un numero → ");
     scanf("%i",&numero);


     suma = sumaDigitos(numero,suma);

     printf("\nLa suma de los digitos del numero %i es → %i \n",numero,suma);


     return 0;
}


int sumaDigitos(int numero, int suma){


     if(numero==0){

          return 0;

     }else{

          suma = suma + (numero % 10);

          if(numero/10 == 0 ){

               return suma;

          }else{

               suma = sumaDigitos(numero/10,suma);

          }
     }
}
