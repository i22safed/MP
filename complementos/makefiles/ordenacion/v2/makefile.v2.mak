# Fichero: makefile.v2
# Ejemplo de makefile que genera un ejecutable a partir de dos 
# ficheros objeto: 
#   1) "ppal.o":codigo objeto del programa principal (de "ppal.c").  
#   2) "funcsvec.o": codigo objeto de las funciones 
#       auxiliares (de "funcsvec.c"). 

destinos:ordena2.exe clean
ordena2.exe:ppal.o funcsvec.o
	gcc -o ordena2.exe ppal.o funcsvec.o
ppal.o:ppal.c funcsvec.h
	gcc -c -o ppal.o -I. ppal.c 
funcsvec.o:funcsvec.c funcsvec.h
	gcc -c -o funcsvec.o -I. funcsvec.c
clean:
	del *.o