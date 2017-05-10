# Fichero: makefile
# Desc: Makfile para el ejercicio 6

destinos: main.exe

libMemoria.a : reservaMemoria.o liberaMemoria.o
	ar -rsv libMemoria.a reservaMemoria.o liberaMemoria.o

main.exe : libMemoria.a main.o ficheros.o crucigrama.o
	gcc -o main.exe  main.o ficheros.o crucigrama.o libMemoria.a

clean :
	@echo Borrando ficheros objeto ...
	rm *.o

# Ordenes para los objetos

reservaMemoria.o : reservaMemoria.c memoria.h
	gcc -c reservaMemoria.c

liberaMemoria.o : liberaMemoria.c memoria.h
	gcc -c liberaMemoria.c

main.o : main.c
	gcc -c main.c

ficheros.o : ficheros.c ficheros.h
	gcc -c ficheros.c

crucigrama.o : crucigrama.c crucigrama.h
	gcc -c crucigrama.c
