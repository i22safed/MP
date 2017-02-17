#include <stdio.h>

/*

1.  Codifica un programa que utilice la sentencia printf para escribir
el tamaño de los tipos de las  siguientes variables:   
	
	int a, *b, **c; 
	double d, *e, **f; 
	char g, *h, **i;

*/



int main (){

	int a, *b, **c;
	double d, *e, **f;
	char g, *h, **i; 

	printf("\nEl tamaño de a: %i bytes\n", sizeof(a));
	printf("El tamaño de *b: %i bytes\n", sizeof(*b));
	printf("El tamaño de **c: %i bytes\n\n", sizeof(**c));

	printf("El tamaño de a: %i bytes\n", sizeof(d));
	printf("El tamaño de *b: %i bytes\n", sizeof(*e));
	printf("El tamaño de **c: %i bytes\n\n", sizeof(**f));

	printf("El tamaño de a: %i bytes\n", sizeof(g));
	printf("El tamaño de *b: %i bytes\n", sizeof(*h));
	printf("El tamaño de **c: %i bytes\n\n", sizeof(**i));



	return 0; 
}
