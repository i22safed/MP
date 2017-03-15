#include "opers.h"

int factorial(int n)
{
  int resultado;
  
  if (n==0)
    /*Caso base*/    
    resultado = 1;    
  else
    /*Cuerpo*/
    resultado = n*factorial(n-1);
  return(resultado);
}