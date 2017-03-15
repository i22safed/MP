

## Documentación

- Documentación externa → Ajeno al programa Markdown, Doxygen  
- Documentación interna → Interno al programa
     - Comentarios

#### Cabecera de las funciones o procedimientos  
- Nombre, Proposito, Autor  
- Parametros de entrada/salida   
- Precondición   
- Valor devuelto  
- Funciones a las que llama   
- Declaraciones de variables o tipos compuestos
- Esquemas condicionales e iterativos

#### Presentación  
- Sangrado

### Principios del programador
- Principio de carácter personal   
- Principio de la estética  
- Principio de la claridad  
- Principio de la distribuición
- Principio de lo explícito
- Principio de los Comentarios
- Principio de las suposiciones
- Principio de la interfaz con el usuario
- Principio de volver atrás
- El principio del Tiempo y el Dinero de otros


### Doxygen

Para realizar la documentación en doxygen

1. Para crear el fichero de configuración  

     ``` doxygen -g ficheroDeConfiguración ```  

2. Editar el fichero de configuración  
3. No se que del fichero de configuracion  

#### Comentarios en Doxygen

Una linea → ///  
Varias lineas → /** Texto */

... Y si es después del código  

Una linea → ///< "Codigo"  
Varias lineas → /**< "Codigo" */  


#### Descripción breve y descripción detallada

- Tipo 1 →
- Tipo 2 →

#### Comandos estructurales

Comandos precedidos de \ o @

```
/**
     @struct punto
     @brief Definición breve de una estructura de tipo punto
*/
```

#### Comentarios en los ficheros

Incluir:

- @file
- @brief
- @author
- @date
- @version

#### Documentación de función
- @fn → Function
- @param → comentario de un parametro
- @return → comentario sobre el valor devuelto 
