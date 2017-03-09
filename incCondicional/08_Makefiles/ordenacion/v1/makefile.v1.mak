# Fichero: makefile.v1
# Generacion del ejecutable a partir de un unico fuente: "ordena1.c"
destinos: ordena1.exe 
ordena1.exe : ordena1.c
	gcc ordena1.c -o ordena1.exe