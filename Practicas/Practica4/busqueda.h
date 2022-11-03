/*******************************************/
/* 		    BUSQUEDA.H                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include "3puzle.h"
#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado;
    unsigned operador;
    int costeCamino;
    int profundidad;
    int valHeuristica;
    struct NodoBusqueda_ *padre;
} tNodo;

#endif
int busquedaAnchura(void);
int busquedaProfundidad(void);
int busquedaProfundidadLimitada(int limite);
void solucionFin(int res);
int buscarRepe(tNodo* estado, LISTA Cerrados);
int busquedaProfundidadLimitadaIterativa(int limite);
