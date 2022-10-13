#include "puzle.h"
#include <string.h>
#include <stdlib.h>
int main()
{
    tEstado *estado_Inicial = estadoInicial();
    dispEstado(estado_Inicial);
    tEstado *EstadoCambio;

    for (int op = 1; op <= NUM_OPERADORES; op++)
    {
        if (esValido(op, estado_Inicial))
        {
            EstadoCambio = aplicaOperador(op, estado_Inicial);
            dispOperador(op);
            dispEstado(EstadoCambio);
        } // if
    }     // for

    return 0;
}