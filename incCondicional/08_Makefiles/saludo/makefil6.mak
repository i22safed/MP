# Fichero: makefil6.mak
# Ejemplo de fichero makefile con un destino simbolico llamado "saludos"
saludos: saludo.exe saludo2.exe saludo3.exe clean salva
saludo.exe : saludo.c
	@echo Creando saludo.exe...
	gcc saludo.c -o saludo.exe
saludo2.exe : saludo2.c
	@echo Creando saludo2.exe...
	gcc saludo2.c -o saludo2.exe
saludo3.exe : saludo3.c
	@echo Creando saludo3.exe...
	gcc saludo3.c -o saludo3.exe
.PHONY: clean
clean :
	@echo Borrando ficheros .o...
	del *.o
salva : saludo.exe saludo2.exe saludo3.exe
	@echo Creando directorio resultado
	-md result
	@echo Moviendo los .exe a resultado
	copy *.exe result
	del *.exe
# move *.exe funciona en la ventana de MS-DOS
# pero no desde el make
