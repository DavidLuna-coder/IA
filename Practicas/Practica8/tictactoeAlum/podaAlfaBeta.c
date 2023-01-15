#include "minimaxAlum.h"
#include "podaAlfaBeta.h"

int valorMax_ab(tNodo *nodo, int prof, int alfa, int beta)
{
    int vmax, jugada = 0;
    tNodo *intento;

    if (terminal(nodo) || lleno(nodo))
    {
        vmax = terminal(nodo);
    }
    else if (prof == LIMITE)
    {
        vmax = heuristica(nodo);
    }
    else
    {
        while (jugada < N && alfa < beta)
        {
            if (esValida(nodo, jugada))
            {
                intento = aplicaJugada(nodo, MAX, jugada);
                alfa = max(alfa, valorMin_ab(nodo, prof + 1, alfa, beta));
            }
            jugada++;
        }
        vmax = alfa;
    }

    return vmax;
}

int valorMin_ab(tNodo *nodo, int prof, int alfa, int beta)
{
    int vmin, jugada = 0;
    tNodo *intento;

    if (terminal(nodo) || lleno(nodo))
    {
        vmin = terminal(nodo);
    }
    else if (prof == LIMITE)
    {
        vmin = heuristica(nodo);
    }
    else
    {
        while (jugada < N && alfa < beta)
        {
            if (esValida(nodo, jugada))
            {
                intento = aplicaJugada(nodo, MAX, jugada);
                beta = min(alfa, valorMax_ab(nodo, prof + 1, alfa, beta));
            }
            jugada++;
        }
        vmin = beta;
    }

    return vmin;
}

tNodo *poda_ab(tNodo *nodo)
{
    int max_actual, jugada = 0, mejorJugada, prof, v;
    tNodo *intento;

    int alfa = -100000;
    int beta = +100000;

    for (jugada = 0; jugada < N; jugada++)
    {
        if (esValida(nodo, jugada))
        {
            intento = aplicaJugada(nodo, MAX, jugada);
            v = 0; // TODO valorMin_ab(intento, prof + 1, alfa, beta)
            if (v > alfa)
            {
                alfa = v;
                mejorJugada = jugada;
            }
        }

        nodo = aplicaJugada(nodo, MAX, mejorJugada);

        return nodo;
    }
}
