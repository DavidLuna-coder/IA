/*******************************************/
/* 		    BUSQUEDA.C                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"

void solucionFin(int res)
{
    printf("\nFin de la busqueda\n");
    if (res)
        printf("Se ha llegado al objetivo\n");
    else
        printf("No se ha llegado al objetivo\n");
}
void dispNodo(tNodo *nodo)
{
    dispEstado(nodo->estado);
    printf("\n");
}
void dispCamino(tNodo *nodo)
{
    if (nodo->padre == NULL)
    {
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else
    {
        dispCamino(nodo->padre);
        dispOperador(nodo->operador);
        dispEstado(nodo->estado);
    }
}

void dispSolucion(tNodo *nodo)
{
    printf("Profundidad=%d\n", nodo->profundidad);
    printf("Coste=%d\n", nodo->costeCamino);
    dispCamino(nodo);
}

/* Crea el nodo raíz. */
tNodo *nodoInicial()
{
    tNodo *inicial = (tNodo *)malloc(sizeof(tNodo));
    inicial->estado = estadoInicial();
    inicial->padre = NULL;
    inicial->costeCamino = 0;
    inicial->profundidad = 0;
    return inicial;
}

LISTA expandir(tNodo *nodo)
{
    unsigned op;
    LISTA sucesores = VACIA;
    tNodo *nuevo = calloc(1, sizeof(tNodo));
    tEstado *s;
    for (op = 1; op <= NUM_OPERADORES; op++)
    {
        if (esValido(op, nodo->estado))
        {
            // s=(tEstado *)calloc(1,sizeof(tEstado));
            s = aplicaOperador(op, nodo->estado);
            nuevo->estado = s;
            nuevo->padre = nodo;
            nuevo->operador = op;
            nuevo->costeCamino = nodo->costeCamino + coste(op, nodo->estado);
            nuevo->profundidad = nodo->profundidad + 1;
            InsertarUltimo(&sucesores, (tNodo *)nuevo, (sizeof(tNodo)));
        }
    }
    return sucesores;
}

int buscarRepe(tNodo *nodo, LISTA Cerrados)
{
    int repetido = 0;
    tNodo *n = (tNodo *)calloc(1, sizeof(tNodo));
    LISTA p = Cerrados;
    while (p != NULL && !repetido)
    {
        ExtraerPrimero(p, n, sizeof(tNodo));
        repetido = iguales(nodo->estado, n->estado);
        p = p->next;
    }

    return repetido;
}

int busquedaProfundidad()
{
    int objetivo = 0, visitados = 0;
    tNodo *Actual = (tNodo *)calloc(1, sizeof(tNodo));
    tNodo *Inicial = nodoInicial();

    LISTA Abiertos = VACIA;
    LISTA Cerrados = VACIA;
    LISTA Sucesores = VACIA;
    InsertarPrimero(&Abiertos, (tNodo *)Inicial, sizeof(tNodo));
    
        while (!esVacia(Abiertos) && !objetivo)
        {
            Actual = (tNodo *)calloc(1, sizeof(tNodo));
            ExtraerPrimero(Abiertos, Actual, sizeof(tNodo));
            EliminarPrimero(&Abiertos);
            visitados++;

            objetivo = testObjetivo(Actual->estado);
            if (!buscarRepe(Actual,Cerrados)&&!objetivo)
            {
                Sucesores = expandir(Actual);
                //Abiertos = Concatenar(Abiertos, Sucesores); // ANCHURA
                Abiertos=Concatenar(Sucesores,Abiertos); //Profundidad
                InsertarUltimo(&Cerrados, Actual, sizeof(tNodo));
            }
    } // while

    
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    // free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}


int busquedaAnchura()
{
    int objetivo = 0, visitados = 0;
    tNodo *Actual = (tNodo *)calloc(1, sizeof(tNodo));
    tNodo *Inicial = nodoInicial();

    LISTA Abiertos = VACIA;
    LISTA Cerrados = VACIA;
    LISTA Sucesores = VACIA;
    InsertarPrimero(&Abiertos, (tNodo *)Inicial, sizeof(tNodo));
    
        while (!esVacia(Abiertos) && !objetivo)
        {
            Actual = (tNodo *)calloc(1, sizeof(tNodo));
            ExtraerPrimero(Abiertos, Actual, sizeof(tNodo));
            EliminarPrimero(&Abiertos);
            visitados++;

            objetivo = testObjetivo(Actual->estado);
            if (!buscarRepe(Actual,Cerrados)&&!objetivo)
            {
                Sucesores = expandir(Actual);
                Abiertos = Concatenar(Abiertos, Sucesores); // ANCHURA
                //Abiertos=Concatenar(Sucesores,Abiertos); //Profundidad
                InsertarUltimo(&Cerrados, (tNodo*)Actual, sizeof(tNodo));
            }
    } // while

    
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    // free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busquedaProfundidadLimitada(int limite)
{
    
    int objetivo = 0, visitados = 0;
    tNodo *Actual = (tNodo *)calloc(1, sizeof(tNodo));
    tNodo *Inicial = nodoInicial();

    LISTA Abiertos = VACIA;
    LISTA Cerrados = VACIA;
    LISTA Sucesores = VACIA;
    InsertarPrimero(&Abiertos, (tNodo *)Inicial, sizeof(tNodo));
        while (!esVacia(Abiertos) && !objetivo)
        {
            Actual = (tNodo *)calloc(1, sizeof(tNodo));
            ExtraerPrimero(Abiertos, Actual, sizeof(tNodo));
            EliminarPrimero(&Abiertos);
            visitados++;

            objetivo = testObjetivo(Actual->estado);
            if (Actual->profundidad<limite&&!buscarRepe(Actual,Cerrados)&&!objetivo)
            {
                Sucesores = expandir(Actual);
                //Abiertos = Concatenar(Abiertos, Sucesores); // ANCHURA
                Abiertos=Concatenar(Sucesores,Abiertos); //Profundidad
                InsertarUltimo(&Cerrados, Actual, sizeof(tNodo));
            }
    } // while
    
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    // free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

int busquedaProfundidadLimitadaIterativa(int limite)
{
    int objetivo = 0;
    int i = 0;

    while (!objetivo && i <= limite)
    {
        objetivo = busquedaProfundidadLimitada(i);
        i++;
    }
    
    return objetivo;
}