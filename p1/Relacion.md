2. Explica el significado de cada una de las siguientes declaraciones, 
así como el valor inicial que  toman las variables en cada caso:

	a) int *px;
	b) float a, b;
	c) float *pa, *pb;
	d) float a=­0.167;
	e) float *pa =&a;
	f) char c1, c2, c3;
	g) char *pcl, *pc2, *pc3 =&cl


3.Un programa de C contiene las siguientes sentencias
     int i, j = 25;
     int *pi, *pj = &i;
     *pj = j + 5;
     i = *pj + 5;
     pi = pj;
     *pi = i + j;

Si el valor asignado a i empieza en la dirección F9C (hexadecimal) y el valor asignado a j empieza
en FE9 entonces:     

a) ¿Qué valor es representado por &i?

  Representa el comienzo de la variable i

b) ¿Qué valor es representado por &j?

  Representa el comienzo de la variable j

c) ¿Qué valor es asignado a pj?

  El valor asignado es uno aleatorio, que cambia en cada ejecución
  del programa

d) ¿Qué valor es asignado a *pj?

  Introduce mediante el operador de contenido la suma de i y j, es
  decir, introduce el valor 60

e) ¿Qué valor es asignado a i?

  A la variable i se le asigna el contenido de pj + 5

f) ¿Qué valor es representado por pi?

  Valor asignado aleatorio ya que no ha sido inicializado

g) ¿Qué valor es asignado a *pi?

  Contenido de la direccion de pi

h) ¿Qué valor es representado por la expresión (*pi + 2)?

  El contenido de pi + 2


  4.  Un programa de C contiene las siguientes sentencias

       float a = 0.001;
       float b = 0.003;
       float c, *pa, *pb
       pa = &a;
       *pa = 2 * a;
       pb = &b;
       c = 3 * (*pb + *pa );

  Si el valor asignado a “a” empieza en la dirección 1130 (hexadecimal) y el valor asignado a “b”
  empieza en 1134 y el valor asignado a “c” empieza en 1138, entonces:

       a) ¿Qué valor es representado por &a?

            El comienzo de la dirección de memoria de la variable a

       b) ¿Qué valor es representado por &b?

            El comienzo de la dirección de memoria de la variable b

       c) ¿Qué valor es representado por &c?

            El comienzo de la dirección de memoria de la variable c

       d) ¿Qué valor es asignado a pa?

            A pa se le asigna la dirección de comienzo de la variable

       e) ¿Qué valor es representado por *pa?

            El contenido de la dirección de memoria que almacena

       f) ¿Qué valor es representado por &(*pa)?
       g) ¿Qué valor es asignado a pb?
       h) ¿Qué valor es representado por *pb?
       i) ¿Qué valor es asignado a c?
