REM generamos los ficheros.o
gcc -c *.c
REM generamos la biblioteca
ar -rsv libopers.a suma.o resta.o mult.o fact.o divide.o
REM generamos el ejecutable
gcc -o main.exe main.o libopers.a