#ifndef __EJ_6__
#define __EJ_6__


int ** reservarMemoria(int nFil, int nCol);
int * reservaVector(int nCol);
void rellenaMatriz(int ** matriz, int nFil, int nCol);
void imprimeMatriz(int ** matriz, int nFil, int nCol);
int * minCol(int ** matriz, int nFil, int nCol, int * minimos);
void imprimeVector(int * minimos, int nCol);
void liberarMemoria(int ** matriz, int nFil);


#endif
