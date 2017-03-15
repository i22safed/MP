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

int suma(int a, int b)
{
  return(a+b);
}

int multiplica(int a, int b)
{
  return(a*b);	
}

float divide (int a, int b)
{
  return((a*1.0)/b);
}

int resta(int a, int b)
{
  return(a-b);	
}