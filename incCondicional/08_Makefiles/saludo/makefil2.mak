# Fichero: makefil2.mak
# Por defecto, Construye el ejecutable "saludo.exe" a partir de "saludo.c"
# Tambien puede construirse el objeto "saludo.o" a partir de "saludo.c"
saludo.exe : saludo.o
	gcc saludo.o -o saludo.exe
# Esta regla especifica un destino que no es un fichero ejecutable
saludo.o : saludo.c
	@gcc -c saludo.c -o saludo.o
