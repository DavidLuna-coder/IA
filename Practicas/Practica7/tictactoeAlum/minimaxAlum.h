/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

tNodo *jugadaAdversario(tNodo *t);
tNodo *PSEUDOminimax(tNodo *Nodo);
int min(int a, int b);
int max(int a, int b);
int valorMax(tNodo *nodo);
int valorMin(tNodo *nodo);
tNodo *minimax(tNodo *t);