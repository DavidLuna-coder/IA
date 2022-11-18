/*******************************************/
/*             MAIN.C                      */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"

int main()
{
    //Está implementada la búsqueda en anchura, en profundidad se produciría un bucle al no haber control de estados repetidos. Añadiendo un control de estados repetidos se arregla
    solucionFin(busquedaVoraz());
    solucionFin(busquedaAEstrella());
    return 0;
}
