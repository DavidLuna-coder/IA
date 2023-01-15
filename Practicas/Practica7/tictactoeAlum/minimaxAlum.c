/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"
#include "minimaxAlum.h"
tNodo *PSEUDOminimax(tNodo *t)
{
      int mejorJugada = -1;
      int puntos = -2;
      int i, temp;
      tNodo *intento = malloc(sizeof(tNodo));
      printf("\n Mi turno: \n");
      for (i = 0; i < 9; ++i)
      {
            if (esValida(t, i))
            {
                  intento = aplicaJugada(t, 1, i); // Intenta jugada
                  temp = terminal(intento);        // Calcula el valor minimax
                  if (temp > puntos)
                  {
                        puntos = temp;
                        mejorJugada = i;
                  }
            }
      } // for
      t = aplicaJugada(t, 1, mejorJugada);
      return t;
}

tNodo *minimax(tNodo *nodo)
{
      int max, max_actual, jugada, mejorJugada;
      tNodo *intento = malloc(sizeof(tNodo));
      max = -10000;
      for (jugada = 0; jugada < N; jugada++)
      {
            if (esValida(nodo, jugada))
            {
                  intento = aplicaJugada(nodo, 1, jugada);
                  max_actual = valorMin(intento);
                  if (max_actual > max)
                  {
                        max = max_actual;
                        mejorJugada = jugada;
                  }
            }
      }
      nodo = aplicaJugada(nodo, 1, mejorJugada);
      return nodo;
}
tNodo *jugadaAdversario(tNodo *t)
{
      int jugada = 0;
      printf("\nJugada ([0..8])?: ");
      scanf("%d", &jugada);
      while (!esValida(t, jugada))
      {
            printf("\n Intenta otra posicion del tablero \n");
            printf("\n");
            printf("\nJugada ([0..8])?: ");
            scanf("%d", &jugada);
      }
      t = aplicaJugada(t, -1, jugada);
      return t;
}

int valorMin(tNodo *nodo)
{
      int valor_min, jugada, jugador = -1;

      if (terminal(nodo) || lleno(nodo))
      {
            valor_min = terminal(nodo);
      }
      else
      {
            valor_min = 100000;

            for (jugada = 0; jugada < N; jugada++)
            {
                  if (esValida(nodo, jugada))
                  {
                        valor_min = min(valor_min, valorMax(aplicaJugada(nodo, jugador, jugada)));
                  }
            }
      }

      return valor_min;
}

int valorMax(tNodo *nodo)
{
      int valor_max, jugada, jugador = 1;

      if (terminal(nodo) || lleno(nodo))
      {
            valor_max = terminal(nodo);
      }
      else
      {
            valor_max = -100000;

            for (jugada = 0; jugada < N; jugada++)
            {
                  if (esValida(nodo, jugada))
                  {
                        valor_max = max(valor_max, valorMin(aplicaJugada(nodo, jugador, jugada)));
                  }
            }
      }

      return valor_max;
}

int min(int a, int b)
{
      int minimo;
      if (a <= b)
            minimo = a;
      else
            minimo = b;

      return minimo;
}

int max(int a, int b)
{
      int maximo;
      if (a >= b)
            maximo = a;
      else
            maximo = b;

      return maximo;
}