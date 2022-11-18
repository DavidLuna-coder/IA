#include "puzle.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

tEstado *estadoInicial()
{
    return crearEstado(puzleInicial);
}

tEstado *estadoFinal()
{
    return crearEstado(puzleFinal);
}

tEstado *crearEstado(const int matriz[N][N])
{
    tEstado *estado = (tEstado *)malloc(sizeof(tEstado));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            estado->celdas[i][j] = matriz[i][j];
            if (matriz[i][j] == 0)
            {
                estado->fil = i;
                estado->col = j;
            }
        }
    }
    return estado;
}

int esValido(unsigned op, tEstado *estado)
{
    int valido = 0;
    switch (op)
    {
    case ARRIBA:
        valido = (estado->fil > 0);
        break;
    case ABAJO:
        valido = (estado->fil < N - 1);
        break;
    case DERECHA:
        valido = (estado->col < N - 1);
        break;
    case IZQUIERDA:
        valido = (estado->col > 0);
        break;
    default:
        valido = 0;
    }
}

tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
    tEstado *nuevoEstado = (tEstado *)malloc(sizeof(tEstado));
    memcpy(nuevoEstado, estado, sizeof(tEstado));
    int inifil = estado->fil;
    int inicol = estado->col;
    switch (op)
    {
    case ARRIBA:
        nuevoEstado->fil--;
        break;
    case ABAJO:
        nuevoEstado->fil++;
        break;
    case DERECHA:
        nuevoEstado->col++;
        break;
    case IZQUIERDA:
        nuevoEstado->col--;
        break;
    }

    nuevoEstado->celdas[nuevoEstado->fil][nuevoEstado->col] = 0;
    nuevoEstado->celdas[inifil][inicol] = estado->celdas[nuevoEstado->fil][nuevoEstado->col];
    return nuevoEstado;
}

void dispOperador(unsigned op)
{
    switch (op)
    {
    case ARRIBA:
        printf("Movimiento ARRIBA:\n");
        break;
    case ABAJO:
        printf("Movimiento ABAJO:\n");
        break;
    case IZQUIERDA:
        printf("Movimiento IZQUIERDA:\n");
        break;
    case DERECHA:
        printf("Movimiento DERECHA:\n");
        break;
    }
}

void dispEstado(tEstado *estado)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        printf("[ ");
        for (j = 0; j < N; j++)
            printf("%d ", estado->celdas[i][j]);
        printf("]\n");
    }
}

int testObjetivo(tEstado *estado)
{
    tEstado *final;
    final = crearEstado(puzleFinal);

    return iguales(estado, final);
}

int iguales(tEstado *estado, tEstado *final)
{
    int i = 0;
    int j = 0;
    int value = 1;
    while (i < N && value)
    {
        while (j < N && value)
        {
            if (estado->celdas[i][j] != final->celdas[i][j])
            {
                value = 0;
            }

            j++;
        }
        j = 0;
        i++;
    }

    return value;
}

int coste(int op, tEstado *estado)
{
    return 1;
}

int heuristica(const tEstado *estado)
{
    int piezasMal = 0;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            piezasMal += (estado->celdas[i][j] != 0 && estado->celdas[i][j] != puzleFinal[i][j]);
        }
    }
    return piezasMal;
}