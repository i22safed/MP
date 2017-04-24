#ifndef __STOCK__
#define __STOCK__



struct libro{

     char titulo[24];
     char autor[24];
     float precio;
     int unidades;

};

int existenciaLibro(char * nombreRegistro,char * nombreLibro);
void introducirLibro(char * nombreRegistro);
int contarLibros(char * nombreRegistro);
void listarLibros(char * nombreRegistro, int nLibros, struct libro * vector);
void venderLibro(char * nombreRegistro, char * nombreLibro);
void borrarLibros(char * nombreRegistro);

struct libro * reservaMemoria(int nLibros);

#endif
