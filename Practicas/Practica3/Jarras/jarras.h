#define LLENAR3 1
#define LLENAR4 2
#define VACIAR3 3
#define VACIAR4 4
#define PASAR3A4 5
#ifndef JARRAS
#define JARRAS
#define PASAR4A3 6
#define NUM_OPERADORES 6
typedef struct
{
    int jarra4, jarra3;
} tEstado;

tEstado *estadoInicial();
int esValido(unsigned op , tEstado *estado);
tEstado *aplicaOperador(unsigned op , tEstado *estado);
int testObjetivo(tEstado *estado);
void dispOperador(unsigned op);
void dispEstado(tEstado *estado);
int coste(int op, tEstado*);
int iguales(tEstado*,tEstado*);
#endif