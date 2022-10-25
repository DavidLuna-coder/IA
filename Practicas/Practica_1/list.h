#ifndef _LIST_
#define _LIST_
#include "puzle.h"
#include <stdlib.h>
typedef struct nodo
{
    tEstado* estado;
    struct nodo* siguiente;
} nodo;

static nodo* head = NULL;
static nodo* tail = NULL;
static nodo* current = NULL;

/*Inserta una celda en la primera posicion de la lista, si está vacía la crea*/
void insertFirst(tEstado* estado);

/*Inserta una celda en la última posición de la lista si está vacía la crea*/
void insertLast(tEstado* estado);

/*Devuelve la primera posición de la lista*/
nodo* getFirst();

/*Devuelve la siguiente posición al nodo que hemos pasado*/
nodo* getNext(nodo* p);
int listaVacia();
#endif