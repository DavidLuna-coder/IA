#include "jarras.h"
#include <stdio.h>
#include <stdlib.h>
tEstado *estadoInicial()
{
    tEstado *estado = (tEstado *)malloc(sizeof(tEstado));
    estado->jarra3 = 0;
    estado->jarra4 = 0;
    return estado;
}

int esValido(unsigned op, tEstado *estado)
{
    int valido;
    switch (op)
    {
    case LLENAR3:
        valido = (estado->jarra3 < 3);
        break;
    case LLENAR4:
        valido = (estado->jarra4 < 4);
        break;
    case VACIAR3:
        valido = (estado->jarra3 > 0);
        break;
    case VACIAR4:
        valido = (estado->jarra4 > 0);
        break;
    case PASAR3A4:
        valido = (estado->jarra3 > 0 && estado->jarra4 < 4);
        break;
    case PASAR4A3:
        valido = (estado->jarra4 > 0 && estado->jarra3 < 3);
        break;
    default:
        valido = 0;
    }

    return valido;
}

tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
    tEstado *nuevoEstado = (tEstado *)malloc(sizeof(tEstado));
    nuevoEstado->jarra3 = estado->jarra3;
    nuevoEstado->jarra4 = estado->jarra4;
    switch (op)
    {
    case LLENAR3:
        nuevoEstado->jarra3 = 3;
        break;
    case LLENAR4:
        nuevoEstado->jarra4 = 4;
        break;
    case VACIAR3:
        nuevoEstado->jarra3 = 0;
        break;
    case VACIAR4:
        nuevoEstado->jarra4 = 0;
        break;
    case PASAR3A4:
        if (estado->jarra3 <= 4 - estado->jarra4)
        {
            nuevoEstado->jarra3 = 0;
            nuevoEstado->jarra4 = estado->jarra3 + estado->jarra4;
        }
        else
        {
            nuevoEstado->jarra3 = estado->jarra3 - (4 - estado->jarra4);
            nuevoEstado->jarra4 = 4;
        }

        break;
    case PASAR4A3:
        if (estado->jarra4 <= 3 - estado->jarra3)
        {
            nuevoEstado->jarra4 = 0;
            nuevoEstado->jarra3 = estado->jarra4 + estado->jarra3;
        }
        else
        {
            nuevoEstado->jarra4 = estado->jarra4 - (3 - estado->jarra3);
            nuevoEstado->jarra3 = 3;
        }
        break;
    default:
    }
    return nuevoEstado;
}

int testObjetivo(tEstado *estado)
{
    return (estado->jarra4 == 2);
}

void dispOperador(unsigned op)
{
    switch (op)
    {
    case LLENAR3:
        printf("LLENAR 3\n");
        break;
    case LLENAR4:
        printf("LLENAR 4\n");
        break;
    case VACIAR3:
        printf("VACIAR 3\n");
        break;
    case VACIAR4:
        printf("VACIAR 4\n");
        break;
    case PASAR3A4:
        printf("PASAR 3 A 4\n");
        break;
    case PASAR4A3:
        printf("PASAR 4 A 3\n");
        break;
    default:
        printf("Operador %d Invalido", op);
    }
}

void dispEstado(tEstado *estado)
{
    printf("Jarra de 3l: %d\tJarra de 4l: %d\n", estado->jarra3, estado->jarra4);
}