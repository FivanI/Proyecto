#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "cliente.h"
#define MAXT 30

typedef struct nodo2
{
	char info[MAXT];
	struct nodo2 *siguiente;
}Nodo2;

typedef struct
{
	Nodo2 *tope;
}MovimientosB;

MovimientosB *CrearPila();
void listarPila(MovimientosB pila);
int vacioPila(MovimientosB p);
Nodo2 *pop(MovimientosB *pila);



#endif // PILA_H_INCLUDED
