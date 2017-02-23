
#include <string.h>
#include <stdio.h>

int main()
{
   char pre[10] = "pp";
   char post[10] = "tt";
   char cadena[100] = "ppholacomoandadstt";
   char * c = cadena;
   c += strlen(pre);
   c[strlen(c) - strlen(post)] = '\0';
   printf("%s\n",c);
   return 0;

}
