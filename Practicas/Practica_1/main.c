#include "puzle.h"
#include <string.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    tEstado *estado_Inicial = estadoInicial();
    dispEstado(estado_Inicial);
    tEstado *EstadoCambio;

    tEstado* Abiertos[100];
    Abiertos[0] = estado_Inicial;
    int pos = 0;
    int objetivo = 0;
    
    insertFirst(estado_Inicial);
    for (int op = 1; op <= NUM_OPERADORES; op++)
    {
        if (esValido(op, estado_Inicial))
        {
            EstadoCambio = aplicaOperador(op, estado_Inicial);
            dispOperador(op);
            dispEstado(EstadoCambio);
        } 
    }    

    return 0;
}