
### Ruleta UCO  

#### Funciones para ```ruleta.h```  

El nombre del jugador deberá de ser pasado por lineas de ordenes para
realizar las operaciones pertinentes  

· Añadir jugadores: Esta función creará un fichero con los parametros (que
serán recogidos en el main) de struct jugador (nombre, jugador, DNI, saldo
3 strings y 1 int). El formato del fichero sera DNINombre.txt (```46XXXJose.txt```).  
· CambiarJugador: Cambia el jugador activo  
· Listar jugadores: Lista los jugadores y todos sus respectivos datos,reservando
previamente vector de tipo struct. Será necesario tener los nombres almacenados
en un ficheros para contar el numero de estos (vease funciones adicionales)
· Recargar saldo: Recarga el saldo de los usuario que estén en negativo  
· datos2Binario: Pasa los ficheros .txt a .bin  

#### Funciones para ```jugador.h```  

· Hacer Apuesta: Realiza una apuesta  
- Tipo 1 → 1-18 / 19-36 (Sin contar el 0)  
- Tipo 2 → Par / Impar  
- Tipo 3 → Numero  

Se debera almacenar las apuestas realizadas por el usuario activo almacenandolas
en el fichero pertinente a continuación de los datos del mismo con el formato
siguiente:  

| Tipo | Beneficio |
| :-----: | :----------: |
|  2  | +1000 |
| 1   | +205  |
|  4  | -80   |
|  5  | +100  |

· Historial de apuestas: Listar las apuestas del usuario activo  
· Salir: Finaliza la ejecución del programa  

#### Funciones adicionales

· ReservaVector: Reservará memoria para el numero de jugadores que haya en la
base de datos para poder listarlos  
· LimpiarLinea: Borra el ```\n``` de las cadenas recogidas con gets y lo sustituye por
 ```\0```
· Numero de Jugadores: Fichero que almacena el nombre de los jugadores

Todo ello deberá ir acompañado por un ```makefile``` que compile todo el programa y
cree bibliotecas con todos sus ```.o``` pertinentes y un destino ```clean``` que
limpie los ```.o``` resultantes.
