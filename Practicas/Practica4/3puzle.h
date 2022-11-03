#ifndef __3PUZLE__
#define __3PUZLE__

#define A 1
#define B 2
#define C 3

#define ARRIBA_A 1
#define ABAJO_A 2
#define IZQUIERDA_A 3
#define DERECHA_A 4

#define ARRIBA_B 5
#define ABAJO_B 6
#define IZQUIERDA_B 7
#define DERECHA_B 8

#define ARRIBA_C 9
#define ABAJO_C 10
#define IZQUIERDA_C 11
#define DERECHA_C 12

#define NUM_OPERADORES 12

#define N 6
#define N_PIEZAS 3

typedef struct tEstado
{
    int celdas[N][N];
    int filas[N_PIEZAS + 1];
    int columnas[N_PIEZAS + 1];
} tEstado;

static int puzleInicial[N][N] = {
    {-1, 0, 0, C, 0, 0},
    {-1, 0, 0, C, 0, 0},
    {0, A, 0, C, 0, 0},
    {A, A, A, -1, B, 0},
    {0, A, 0, B, B, B},
    {0, 0, 0, 0, 0, 0},
};

static int puzleFinal[N][N] = {
    {-1, 0, 0, 0, 0, 0},
    {-1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, A, 0, -1, 0, C},
    {A, A, A, B, 0, C},
    {0, A, B, B, B, C},
};

static int filasInicial[N_PIEZAS + 1] = {-1, 3, 4, 1};
static int columnasInicial[N_PIEZAS + 1] = {-1, 1, 4, 3};

static int filasFinal[N_PIEZAS + 1] = {-1, 4, 5, 4};
static int columnasFinal[N_PIEZAS + 1] = {-1, 1, 3, 5};

tEstado *crearEstado(int puzle[N][N], int filas[N_PIEZAS + 1], int columnas[N_PIEZAS + 1]);
int esValido(unsigned op, tEstado *);
tEstado *aplicaOperador(unsigned op, const tEstado *);
int testObjetivo(tEstado *);
int iguales(tEstado *, tEstado *);
int coste(unsigned op,tEstado* estado);
void dispEstado(const tEstado *);
void dispOperador(unsigned op);
tEstado* estadoInicial();
#endif