#include "jarras.h"

int main()
{
    tEstado *Inicial = estadoInicial();
    tEstado *Variable;
    dispEstado(Inicial);
    for (unsigned op = LLENAR3; op <= NUM_OPERADORES; op++)
    {
        if (esValido(op, Inicial))
        {
            dispOperador(op);
            Variable = aplicaOperador(op, Inicial);
            dispEstado(Variable);
        }
    }

    return 0;
}