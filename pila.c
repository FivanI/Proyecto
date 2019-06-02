#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "pila.h"

MovimientosB *crearPila()
{
    MovimientosB *pila;
    //CREAR LA PILA
    pila= (MovimientosB*)calloc(1, sizeof(MovimientosB));
    if (pila == NULL)
    {
        printf("\nERROR: No hay suficiente espacio.\n");
        return pila;
    }
    //INICIALIZA LA PILA
    pila->tope = NULL;
     return pila;
}

int vacioPila(MovimientosB pila)
{
    return (pila.tope == NULL);
}

void push(MovimientosB *pila, char dato[])
{
	Nodo2 *nuevoN;
	nuevoN=(Nodo2 *)calloc(1,sizeof(Nodo2));
	strcpy(nuevoN->info,dato);
	nuevoN->siguiente=pila->tope;
	pila->tope=nuevoN;
}

Nodo2 *pop(MovimientosB *pila)
{
	Nodo2 *aux= pila->tope;
	if(!vacioPila(*pila))
	{
		pila->tope=pila->tope->siguiente;
		aux->siguiente=NULL;
	}
	printf("\nNo hay datos en la pila.\n");
	return aux;
}

void listarPila(MovimientosB pila)
{
	Nodo2 *nuevoN;
	nuevoN=pila.tope;
	if(!vacioPila(pila))
	{
		while(nuevoN!=NULL)
		{
			printf("\n%s",nuevoN->info);
			nuevoN=nuevoN->siguiente;
		}
	}
}
