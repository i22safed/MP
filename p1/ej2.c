#include <stdio.h>

/*

2. Explica el significado de cada una de las siguientes declaraciones, 
así como el valor inicial que  toman las variables en cada caso:

	a) int *px;
	b) float a, b;
	c) float *pa, *pb;
	d) float a=­0.167;
	e) float *pa =&a;
	f) char c1, c2, c3;
	g) char *pcl, *pc2, *pc3 =&cl

*/

int main(){

	int *px;					// Declara un puntero de tipo entero, el cual
							// daría error ya que no está inicializado
							// (Violación del segmento)

	float a, b;				// Declara dos floats, los cuales tienen por
							// defecto el valor 0.0000

	float *pa, *pb;			// Declara dos punteros de tipo float sin
							// inicializar, dando como en el primer caso
							// una violación del segmento

	float a =­ 0.167;			 // Asigna a la variable a el valor 0.167

	float *pa =&a;				// Introduce como contenido en *pa la dirección
							// de a (&a)

	char c1, c2, c3;			// Declara 3 variables de tipo char

	char *pc1, *pc2, *pc3 =&c1;	// Declara 3 punteros de tipo char y al
							// y al último le asigna la dirección de c1 (&c1).
							// Los dos primeros punteros no están inicializados
							// dando una violación del segmento

	

	return 0;
}
