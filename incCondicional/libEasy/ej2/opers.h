/*------------------------------------------------------------------*/
/* EJEMPLO BASICO DE GESTION DE BIBLIOTECAS CON EL PROGRAMA ar      */
/*------------------------------------------------------------------*/
/*Cuando se tienen diferentes ficheros con m�dulos es posible
  que varios llamen a uno determinado. Si cada uno de estos
  incluye el fichero de prototipos, el compilador dar� un error,
  pues se estar� intentando incluir un mismo m�dulo m�s de una vez.
  Para evitar este problema hay que utilizar las directivas
  #IFNDEF, #DEFINE y #ENDIF
*/
#ifndef OPERS
#define OPERS

/********************************************************************/
/*
   Nombre: factorial.
   Tipo: int.
   Objetivo: Calcula el factorial de un numero.	     
   Parametros de entrada: 
      - int n: el numero para el que se calcula el factorial
   Precondiciones: Ninguna.
   Devuelve:
      - int: el valor del factorial de n
   Fecha de creaci�n: 6-03-05.
   Autor: Eva Gibaja Galindo
*/
/*******************************************************************/
int factorial(int n);

/********************************************************************/
/*
   Nombre: suma.
   Tipo: int.
   Objetivo: Calcula la suma de dos numeros.	     
   Parametros de entrada: 
      - int a,b: los sumandos
   Precondiciones: Ninguna.
   Devuelve:
      - int: el valor de la suma a+b
   Fecha de creaci�n: 6-03-05.
   Autor: Eva Gibaja Galindo
*/
/*******************************************************************/
int suma(int a, int b);

/********************************************************************/
/*
   Nombre: multiplica.
   Tipo: int.
   Objetivo: Calcula la multiplicaci�n de dos numeros.	     
   Parametros de entrada: 
      - int a,b: los operandos
   Precondiciones: Ninguna.
   Devuelve:
      - int: el valor de la multiplicacion a*b
   Fecha de creaci�n: 6-03-05.
   Autor: Eva Gibaja Galindo
*/
/*******************************************************************/
int multiplica(int a, int b);

/********************************************************************/
/*
   Nombre: divide.
   Tipo: int.
   Objetivo: Calcula la divisi�n de un n�mero entre otro.	     
   Parametros de entrada: 
      - int a: el dividendo.
      - int b: el divisor.
   Precondiciones: Ninguna.
   Devuelve:
      - int: el valor de la divisi�n a/b
   Fecha de creaci�n: 6-03-05.
   Autor: Eva Gibaja Galindo
*/
/*******************************************************************/
float divide (int a, int b);

/********************************************************************/
/*
   Nombre: resta.
   Tipo: int.
   Objetivo: Calcula la resta de dos numeros.	     
   Parametros de entrada: 
      - int a,b: los operandos
   Precondiciones: Ninguna.
   Devuelve:
      - int: el valor de la resta a-b
   Fecha de creaci�n: 6-03-05.
   Autor: Eva Gibaja Galindo
*/
/*******************************************************************/
int resta(int a, int b);

#endif


