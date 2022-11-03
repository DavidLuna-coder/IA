#include "3puzle.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
tEstado *crearEstado(int puzle[N][N], int filas[N_PIEZAS + 1], int columnas[N_PIEZAS + 1])
{
    tEstado *estado = (tEstado *)malloc(sizeof(tEstado));
    memcpy(estado->celdas, puzle, sizeof(int[N][N]));
    memcpy(estado->filas, filas, sizeof(int[N_PIEZAS + 1]));
    memcpy(estado->columnas, columnas, sizeof(int[N_PIEZAS + 1]));

    return estado;
}

int esValido(unsigned op, tEstado *estado)
{
    int valido = 0;
    int test = 0;
    switch (op)
    {
    case ARRIBA_A:
        valido = (estado->filas[A] - 1) > 0 &&
                 (estado->celdas[estado->filas[A] - 2][estado->columnas[A]]) == 0 &&
                 (estado->celdas[estado->filas[A] - 1][estado->columnas[A] - 1] == 0) &&
                 (estado->celdas[estado->filas[A] - 1][estado->columnas[A] + 1] == 0);

        test = (estado->celdas[estado->filas[A] - 2][estado->columnas[A]]) == 0;
        break;

    case ABAJO_A:
        valido = (estado->filas[A] + 2) < N &&
                 (estado->celdas[estado->filas[A] + 2][estado->columnas[A]]) == 0 &&
                 (estado->celdas[estado->filas[A] + 1][estado->columnas[A] - 1] == 0) &&
                 (estado->celdas[estado->filas[A] + 1][estado->columnas[A] + 1] == 0);
        break;

    case IZQUIERDA_A:
        valido = (estado->columnas[A] - 2) > 0 &&
                 (estado->celdas[estado->filas[A]][estado->columnas[A] - 2]) == 0 &&
                 (estado->celdas[estado->filas[A] + 1][estado->columnas[A] - 1] == 0) &&
                 (estado->celdas[estado->filas[A] - 1][estado->columnas[A] - 1] == 0);
        break;

    case DERECHA_A:
        valido = (estado->columnas[A] + 2) < N &&
                 (estado->celdas[estado->filas[A]][estado->columnas[A] + 2]) == 0 &&
                 (estado->celdas[estado->filas[A] + 1][estado->columnas[A] + 1] == 0) &&
                 (estado->celdas[estado->filas[A] - 1][estado->columnas[A] + 1] == 0);
        break;

    case ARRIBA_B:
        valido = (estado->filas[B] - 2) >= 0 &&
                 (estado->celdas[estado->filas[B] - 2][estado->columnas[B]]) == 0 &&
                 (estado->celdas[estado->filas[B] - 1][estado->columnas[B] - 1] == 0) &&
                 (estado->celdas[estado->filas[B] - 1][estado->columnas[B] + 1] == 0);
        break;

    case ABAJO_B:
        valido = (estado->filas[B] + 1) < N &&
                 (estado->celdas[estado->filas[B] + 1][estado->columnas[B]]) == 0 &&
                 (estado->celdas[estado->filas[B] + 1][estado->columnas[B] - 1] == 0) &&
                 (estado->celdas[estado->filas[B] + 1][estado->columnas[B] + 1] == 0);
        break;

    case IZQUIERDA_B:
        valido = (estado->columnas[B] - 1) > 0 &&
                 (estado->celdas[estado->filas[B]][estado->columnas[B] - 2]) == 0 &&
                 (estado->celdas[estado->filas[B] - 1][estado->columnas[B] - 1] == 0);
        break;

    case DERECHA_B:
        valido = (estado->columnas[B] + 2) < N &&
                 (estado->celdas[estado->filas[B]][estado->columnas[B] + 2]) == 0 &&
                 (estado->celdas[estado->filas[B] - 1][estado->columnas[B] + 1] == 0);
        break;

    case ARRIBA_C:
        valido = (estado->filas[C] - 2) >= 0 &&
                 (estado->celdas[estado->filas[C] - 2][estado->columnas[C]]) == 0;
        break;
    case ABAJO_C:
        valido = (estado->filas[C] + 2) < N &&
                 (estado->celdas[estado->filas[C] + 2][estado->columnas[C]] == 0);
        break;

    case IZQUIERDA_C:
        valido = (estado->columnas[C] - 1) >= 0 &&
                 (estado->celdas[estado->filas[C]][estado->columnas[C] - 1]) == 0 &&
                 (estado->celdas[estado->filas[C] - 1][estado->columnas[C] - 1] == 0) &&
                 (estado->celdas[estado->filas[C] + 1][estado->columnas[C] - 1] == 0);
        break;
    case DERECHA_C:
        valido = (estado->columnas[C] + 1) < N &&
                 (estado->celdas[estado->filas[C]][estado->columnas[C] + 1]) == 0 &&
                 (estado->celdas[estado->filas[C] - 1][estado->columnas[C] + 1] == 0) &&
                 (estado->celdas[estado->filas[C] + 1][estado->columnas[C] + 1] == 0);
        break;

    default:
        break;
    }

    return valido;
}

tEstado *aplicaOperador(unsigned op, const tEstado *estado)
{
    tEstado *nuevoEstado = (tEstado *)malloc(sizeof(tEstado));
    memcpy(nuevoEstado, estado, sizeof(tEstado));

    switch (op)
    {
    case ARRIBA_A:
        nuevoEstado->celdas[nuevoEstado->filas[A] - 2][nuevoEstado->columnas[A]] =
            nuevoEstado->celdas[nuevoEstado->filas[A] - 1][nuevoEstado->columnas[A] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[A] - 1][nuevoEstado->columnas[A] + 1] = A;

        nuevoEstado->celdas[nuevoEstado->filas[A] + 1][nuevoEstado->columnas[A]] =
            nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] + 1] = 0;

        nuevoEstado->filas[A]--;
        break;

    case ABAJO_A:
        nuevoEstado->celdas[nuevoEstado->filas[A] + 2][nuevoEstado->columnas[A]] =
            nuevoEstado->celdas[nuevoEstado->filas[A] + 1][nuevoEstado->columnas[A] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[A] + 1][nuevoEstado->columnas[A] + 1] = A;

        nuevoEstado->celdas[nuevoEstado->filas[A] - 1][nuevoEstado->columnas[A]] =
            nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] + 1] = 0;

        nuevoEstado->filas[A]++;
        break;

    case IZQUIERDA_A:
        nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] - 2] =
            nuevoEstado->celdas[nuevoEstado->filas[A] + 1][nuevoEstado->columnas[A] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[A] - 1][nuevoEstado->columnas[A] - 1] = A;

        nuevoEstado->celdas[nuevoEstado->filas[A] + 1][nuevoEstado->columnas[A]] =
            nuevoEstado->celdas[nuevoEstado->filas[A] - 1][nuevoEstado->columnas[A]] =
                nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] + 1] = 0;

        nuevoEstado->columnas[A]--;

        break;

    case DERECHA_A:

        nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] + 2] =
            nuevoEstado->celdas[nuevoEstado->filas[A] + 1][nuevoEstado->columnas[A] + 1] =
                nuevoEstado->celdas[nuevoEstado->filas[A] - 1][nuevoEstado->columnas[A] + 1] = A;

        nuevoEstado->celdas[nuevoEstado->filas[A] + 1][nuevoEstado->columnas[A]] =
            nuevoEstado->celdas[nuevoEstado->filas[A] - 1][nuevoEstado->columnas[A]] =
                nuevoEstado->celdas[nuevoEstado->filas[A]][nuevoEstado->columnas[A] - 1] = 0;

        nuevoEstado->columnas[A]++;
        break;
    case ARRIBA_B:
        nuevoEstado->celdas[nuevoEstado->filas[B] - 2][nuevoEstado->columnas[B]] =
            nuevoEstado->celdas[nuevoEstado->filas[B] - 1][nuevoEstado->columnas[B] + 1] =
                nuevoEstado->celdas[nuevoEstado->filas[B] - 1][nuevoEstado->columnas[B] - 1] = B;

        nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B]] =
            nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] + 1] =
                nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] - 1] = 0;

        nuevoEstado->filas[B]--;
        break;

    case ABAJO_B:
        nuevoEstado->celdas[nuevoEstado->filas[B] + 1][nuevoEstado->columnas[B]] =
            nuevoEstado->celdas[nuevoEstado->filas[B] + 1][nuevoEstado->columnas[B] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[B] + 1][nuevoEstado->columnas[B] + 1] = B;

        nuevoEstado->celdas[nuevoEstado->filas[B] - 1][nuevoEstado->columnas[B]] =
            nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] + 1] = 0;

        nuevoEstado->filas[B]++;
        break;

    case IZQUIERDA_B:
        nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] - 2] =
            nuevoEstado->celdas[nuevoEstado->filas[B] - 1][nuevoEstado->columnas[B] - 1] = B;

        nuevoEstado->celdas[nuevoEstado->filas[B] - 1][nuevoEstado->columnas[B]] =
            nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] + 1] = 0;

        nuevoEstado->columnas[B]--;

        break;

    case DERECHA_B:
        nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] + 2] =
            nuevoEstado->celdas[nuevoEstado->filas[B] - 1][nuevoEstado->columnas[B] + 1] = B;

                nuevoEstado->celdas[nuevoEstado->filas[B] - 1][nuevoEstado->columnas[B]] =
                    nuevoEstado->celdas[nuevoEstado->filas[B]][nuevoEstado->columnas[B] - 1] = 0;

        nuevoEstado->columnas[B]++;

        break;

    case ARRIBA_C:
        nuevoEstado->celdas[nuevoEstado->filas[C] - 2][nuevoEstado->columnas[C]] = C;

        nuevoEstado->celdas[nuevoEstado->filas[C] + 1][nuevoEstado->columnas[C]] = 0;

        nuevoEstado->filas[C]--;

        break;

    case ABAJO_C:
        nuevoEstado->celdas[nuevoEstado->filas[C] + 2][nuevoEstado->columnas[C]] = C;

        nuevoEstado->celdas[nuevoEstado->filas[C] - 1][nuevoEstado->columnas[C]] = 0;

        nuevoEstado->filas[C]++;

        break;

    case IZQUIERDA_C:
        nuevoEstado->celdas[nuevoEstado->filas[C] - 1][nuevoEstado->columnas[C] - 1] =
            nuevoEstado->celdas[nuevoEstado->filas[C]][nuevoEstado->columnas[C] - 1] =
                nuevoEstado->celdas[nuevoEstado->filas[C] + 1][nuevoEstado->columnas[C] - 1] = C;

        nuevoEstado->celdas[nuevoEstado->filas[C] - 1][nuevoEstado->columnas[C]] =
            nuevoEstado->celdas[nuevoEstado->filas[C]][nuevoEstado->columnas[C]] =
                nuevoEstado->celdas[nuevoEstado->filas[C] + 1][nuevoEstado->columnas[C]] = 0;

        nuevoEstado->columnas[C]--;
        break;

    case DERECHA_C:
        nuevoEstado->celdas[nuevoEstado->filas[C] - 1][nuevoEstado->columnas[C] + 1] =
            nuevoEstado->celdas[nuevoEstado->filas[C]][nuevoEstado->columnas[C] + 1] =
                nuevoEstado->celdas[nuevoEstado->filas[C] + 1][nuevoEstado->columnas[C] + 1] = C;

        nuevoEstado->celdas[nuevoEstado->filas[C] - 1][nuevoEstado->columnas[C]] =
            nuevoEstado->celdas[nuevoEstado->filas[C]][nuevoEstado->columnas[C]] =
                nuevoEstado->celdas[nuevoEstado->filas[C] + 1][nuevoEstado->columnas[C]] = 0;

        nuevoEstado->columnas[C]++;
        break;
    default:
        break;
    }
}

int iguales(tEstado *e, tEstado *f)
{
    int igual = 1;
    int i = 1;
    while (i <= N_PIEZAS && igual)
    {
        igual = e->filas[i] == f->filas[i] && e->columnas[i] == f->columnas[i];
        i++;
    }

    return igual;
}

int testObjetivo(tEstado* estado)
{
    tEstado* estadoFinal = crearEstado(puzleFinal,filasFinal,columnasFinal);
    return iguales(estado,estadoFinal);
}
void dispEstado(const tEstado *estado)
{
    for (size_t i = 0; i < N; i++)
    {
        printf("[ ");
        for (size_t j = 0; j < N; j++)
        {
            printf("%d ", estado->celdas[i][j]);
        }
        printf("]\n");
    }
}

void dispOperador(unsigned op)
{
    switch (op)
    {
    case ARRIBA_A:
        printf("ARRIBA A:\n");
        break;

    case ABAJO_A:
        printf("ABAJO A:\n");
        break;

    case IZQUIERDA_A:
        printf("IZQUIERDA A:\n");
        break;
    case DERECHA_A:
        printf("DERECHA A:\n");
        break;

    case ARRIBA_B:
        printf("ARRIBA B:\n");
        break;

    case ABAJO_B:
        printf("ABAJO B:\n");
        break;

    case IZQUIERDA_B:
        printf("IZQUIERDA B:\n");
        break;
    case DERECHA_B:
        printf("DERECHA B:\n");
        break;

    case ARRIBA_C:
        printf("ARRIBA C:\n");
        break;

    case ABAJO_C:
        printf("ABAJO C:\n");
        break;

    case IZQUIERDA_C:
        printf("IZQUIERDA C:\n");
        break;
    case DERECHA_C:
        printf("DERECHA C:\n");
        break;
    default:
        break;
    }
}


int coste(unsigned op,tEstado* estado)
{
    return 1;
}


tEstado* estadoInicial()
{
    tEstado* e = crearEstado(puzleInicial,filasInicial,columnasInicial);
    return e;
}
