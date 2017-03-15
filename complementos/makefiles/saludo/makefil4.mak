# Fichero: makefil4.mak
# Por defecto, construye el ejecutable "saludo.exe" a partir de "saludo.c"
# Incorpora dos reglas mas: 
#   1) Crear el objeto "saludo.o" a partir de "saludo.c"
#   2) Novedad: Regla sin lista de dependencia. 

saludo.exe : saludo.c
	echo Creando saludo.exe...
	gcc saludo.c -o saludo.exe

# Esta regla especifica un destino que no es un fichero ejecutable. 

saludo.o : saludo.c
	@echo Creando saludo.o solamente...
	gcc -c saludo.c -o saludo.o

# Esta regla especifica un destino sin lista de dependencia

clean :
	@echo Borrando ficheros .o...
	@del *.o
