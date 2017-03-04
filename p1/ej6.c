#include <stdio.h>

// Prototipos de las funciones

int minimo(int num1,int num2);
void minimo_referencia(int num1,int num2,int *min);

// Cuerpo del main

int main(){

  // Aqui lo declaramos del tipo que corresponda

  int a, b, min;

  printf("Introduce el valor del numero 1: ");
  scanf("%d",&a);

  printf("Introduce el valor del numero 2: ");
  scanf("%d",&b);

  min = minimo(a, b);
  printf("\nMinimo (%d,%d): %d", a,b,min);

  minimo_referencia(a, b, &min);
  printf("\nMinimo (%d,%d): %d\n", a,b, min);

  return 0;

}

/// Cuerpos de las funciones

int minimo(int num1,int num2){

      if(num1<=num2){
        return num1;
      }else{
        return num2;
      }
}

void minimo_referencia(int num1,int num2,int *min){

  if(num1<=num2){

     *min= num1;

  }else{

     *min = num2;

  }

}
