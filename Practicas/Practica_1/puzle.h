/*******************************************/
/* 		      PUZLE.H                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#ifndef __PUZLE__
#define __PUZLE__
#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4

#define NUM_OPERADORES 4
#define N 3

#ifndef _tEstado_
#define _tEstado_
typedef struct
{
    int celdas[N][N];
    int fil; // Fila del Hueco
    int col; // Fila de la Columna
} tEstado;
#endif

static const int puzleInicial[N][N] =
    {
        {1, 7, 3},
        {6, 0, 4},
        {2, 5, 8}};

static const int puzleFinal[N][N] =
    {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}};

tEstado *estadoInicial();
tEstado *crearEstado(const int[N][N]);
int testObjetivo(tEstado *estado); // Boolean
int esValido(unsigned op, tEstado *estado);
tEstado *aplicaOperador(unsigned op, tEstado *estado);
void dispOperador(unsigned op);
void dispEstado(tEstado *estado);

#endif