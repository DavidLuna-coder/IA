#include "busqueda.h"

int main()
{
    printf("Busqueda en Anchura\n");
    solucionFin(busquedaAnchura());

    printf("Busqueda en Profundidad\n");
    solucionFin(busquedaProfundidad());

    printf("Busqueda en Profundida Limitada\n");
    solucionFin(busquedaProfundidadLimitada(4));

    printf("Busqueda en Profundida Limitada Iterativa\n");
    solucionFin(busquedaProfundidadLimitadaIterativa(10));
    return 0;
}