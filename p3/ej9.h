#ifndef __STOCK_H__
#define __STOCK_H__

struct libro{

     char titulo[50];
     char autor[50];
     float precio;
     int unidades;

};

// Funciones del programa

int existeLibro(char * nombreRegistro,char * nombreLibro);
void introducirLibro(char * nombreRegistro);
int conteoLibros(char * nombreRegistro);
void listarLibros(char * nombreRegistro,int nLibros, struct libro * vector);
void venderLibro(char * nombreRegistro, char * nombreLibro);
void limpiarStock(char * nombreRegistro);

struct libro * reservaMemoria(int nLibros);


#endif 
