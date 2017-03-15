REM generamos los ficheros.o
gcc -c *.c
REM generamos la biblioteca
ar -rsv libopers.a opers.o
REM generamos el ejecutable
gcc -o main.exe main.o libopers.a