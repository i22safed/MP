
#### Funciones de ficheros

##### 1. Flujos de entrada/salida

· *stdin* → entrada estándar → teclado  
· *stdout* → salida estándar → pantalla  
· *stderr* → salida de errores estándar → pantalla

##### 2. Declaración de un fichero

La declaración de un fichero se realiza mediante el siguiente puntero ```FILE * f;```
dicho puntero pertenece al tipo FILE. Es una estructura que posee los siguientes
campos:

```C

typedef struct{

     int _cnt;
     char *_ptr;
     char *_base;
     int _bufsiz;
     int _flag;
     int _file;
     char *_name_to_remove;
     int _fillsize;

} FILE;

```

##### 3. Apertura y cierre de ficheros de texto

La estructura para abrir un fichero es la siguiente → FILE * fopen (const * char nombre, const char * modo);

Un ejemplo de apertura de un fichero en modo lectura es →

```C

// Declaramos primero el puntero con el que trabajaremos y el nombre del
// fichero

     FILE * fichero;
     char * nombre="ficheroEjemplo.txt"

     if((fichero = fopen(nombre,"r"))==NULL){          // Abre el fichero en modo lectura

          printf("\nNo se ha podido abrir el fichero %s\n",nombre);
          exit -1;

     }else{

          printf("\nEl fichero %s se ha abierto correctamente \n",nombre);

     }

// Y para el cierre del fichero

     fclose(fichero);


```

Existe tambien otra funcion que devuelve el puntero al principio del archivo, dicha
función posee el siguiente prototipo:

```C

     void rewind(FILE * fichero);

```


###### 3.1. Modos de apertura del fichero

| Modo | Acciones | Cursor | Si existe | Si no existe |
| :-----: | :-----: | :-----: | :-----: | :-----: |
|r|Lectura|Inicio|Abre|Codigo error|
|w|Escritura|Inicio|Borra contenido|Crea|
|a|Adición|Final|Abre. Agrega al final|Crea|
|r|L/E|Inicio|Inicio|Codigo error|
|w+|L/E|Inicio|Borra contenido|Crea|
|a+|L/Adición|Final|Abre. Agrega al final|Crea|

##### 4. Lectura

| Funcion| Prototipo | Definición | Valor de retorno |
| :-----: | :-----: | :-----: | :-----: | :-----: |
|fgetc|char fgetc(FILE *archivo);|Esta función lee un caracter a la vez del archivo que esta siendo señalado con el puntero *archivo. |En caso de que la lectura sea exitosa devuelve el caracter leído y en caso de que no lo sea o de encontrar el final del archivo devuelve EOF.|
|fgets|char \*fgets(char \*buffer, int tamaño, FILE *archivo);|Esta función está diseñada para leer cadenas de caracteres. Leerá hasta n-1 caracteres o hasta que lea un cambio de línea '\n' o un final de archivo EOF. |N/A|
|fread|size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );|Esta función lee un bloque de una "stream" de datos. Efectúa la lectura de un arreglo de elementos "count", cada uno de los cuales tiene un tamaño definido por "size". Luego los guarda en el bloque de memoria especificado por "ptr". El indicador de posición de la cadena de caracteres avanza hasta leer la totalidad de bytes. |Si esto es exitoso la cantidad de bytes leídos es (size*count).|
|fscanf|int fscanf(FILE *fichero, const char *formato, argumento, ...);|La función fscanf funciona igual que scanf en cuanto a parámetros, pero la entrada se toma de un fichero en lugar del teclado.|N/A|


##### 5. Escritura

| Funcion| Prototipo | Definición | Valor de retorno |
| :-----: | :-----: | :-----: | :-----: | :-----: |
|fputc|int fputc(int caracter, FILE *archivo);| Esta función escribe un carácter a la vez del archivo que esta siendo señalado con el puntero *archivo. |El valor de retorno es el carácter escrito, si la operación fue completada con éxito, en caso contrario será EOF.|
|fputs|char \*fgets(char \*buffer, int tamaño, FILE *archivo);|Esta función está diseñada para leer cadenas de caracteres. Leerá hasta n-1 caracteres o hasta que lea un cambio de línea '\n' o un final de archivo EOF. |N/A|
|fwrite|size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );|Esta función lee un bloque de una "stream" de datos. Efectúa la lectura de un arreglo de elementos "count", cada uno de los cuales tiene un tamaño definido por "size". Luego los guarda en el bloque de memoria especificado por "ptr". El indicador de posición de la cadena de caracteres avanza hasta leer la totalidad de bytes. |Si esto es exitoso la cantidad de bytes leídos es (size*count).|
|fprintf|int fscanf(FILE *fichero, const char *formato, argumento, ...);|La función fscanf funciona igual que scanf en cuanto a parámetros, pero la entrada se toma de un fichero en lugar del teclado.|N/A|
