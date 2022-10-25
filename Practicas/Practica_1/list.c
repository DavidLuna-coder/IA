#include "list.h"

void insertFirst(tEstado *estado)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->siguiente = head;
    if (head == NULL)
    {
        tail = nuevoNodo;
    }

    head = nuevoNodo;
    nuevoNodo->estado = estado;
}

void insertLast(tEstado *estado)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    if (tail == NULL)
        head = nuevoNodo;

    else
    {
        tail->siguiente = nuevoNodo;
    }
    tail = nuevoNodo;

    nuevoNodo->estado = estado;
}

nodo *getFirst()
{
    return head;
}

nodo *getNext(nodo *p)
{
    return p->siguiente;
}

int listaVacia()
{
    return head == NULL;
}