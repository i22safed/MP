#include <stdio.h>

struct polinomio{

     int coeficiente;
     int grado;

};
void leerMonomio(struct polinomio *pol);
void imprimirMonomio(struct polinomio *pol);
void gradoMaxMin();
void leerPolinomio(int nGrado, struct polinomio *vector);
void escribirPolinomio(int nGrado , struct polinomio *vector);
void hallarMaxMin(int nGrado, struct polinomio *vector,int *candidatoMin, int *candidatoMax);



int main(){

     struct polinomio pol;
     int nGrado=0;
     
     int candidatoMax=0; 
     int candidatoMin=0;

     printf("Introduzca el numero de terminos del polinomio: ");
     scanf("%d", &nGrado);

     struct polinomio vector[nGrado];

     leerPolinomio(nGrado, vector);
     escribirPolinomio(nGrado, vector);
     hallarMaxMin(nGrado, vector, &candidatoMin, &candidatoMax);

     printf("El monomio de cuyo grado es mayor es: ");
     imprimirMonomio(vector[candidatoMax]);     



     return 0;
}


// Apartado a leerMonomio

void leerMonomio(struct polinomio *pol){

     printf("Introduzca un valor del coeficiente: ");
     scanf("%d", &pol->coeficiente);

     printf("Introduzca un valor de grado: ");
     scanf("%d", &pol->grado);


}

// Apartado b imprimirMonomio

void imprimirMonomio(struct polinomio *pol){

     printf("%dx^%d ", pol->coeficiente, pol->grado);

}

// Apartado c leerVector y escribirVector de monomios 

void leerPolinomio(int nGrado, struct polinomio *vector){

     int i=0; 

     for(i=0; i<nGrado; i++){

          printf("Para el valor en %i \n",i);
          leerMonomio(&vector[i]);

     }


}

void escribirPolinomio(int nGrado , struct polinomio *vector){

     
     int i=0; 

     for (i=nGrado-1 ; i>=0; i--){

          if(i==nGrado-1){     // Primera posición del monomio 
                               // empezando por la izquierda 
               
               imprimirMonomio(&vector[i]);
          
          }else{
          
               if(vector[i].coeficiente<0){
          
                    printf("- ");
                    imprimirMonomio(&vector[i]);
          
               }else{
          
                    printf("+ ");
                    imprimirMonomio(&vector[i]);
          
               }
          }          
     
     }

}

// Apartado d función que devuelva el monomio de menor y mayor grado 

void hallarMaxMin(int nGrado, struct polinomio *vector,int *candidatoMin, int *candidatoMax){

     int i=0; 
     int maximo=0;
     int minimo=0; 


     for(i=0; i<nGrado; i++){

          if(maximo<vector[i].grado){
               maximo=vector[i].grado;
               *candidatoMax=i; 

          }

     }
    
     minimo=maximo; 
    
     for(i=0; i<nGrado; i++){

          if(minimo>vector[i].grado){
               minimo=vector[i].grado;
               *candidatoMin=i; 

          }

     }


}