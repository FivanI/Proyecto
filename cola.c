#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"

Cola *crearCola()
{
	Cola *cola;
	cola= (Cola *)calloc(1,sizeof(Cola));
	if(cola==NULL)
	{
		printf("\nERROR: La cola no fue creada.\n");
		return cola;
	}
	cola->h=cola->t=NULL;
	return cola;
}

int validarVacio(Cola cola)
{
	return (cola.h==NULL);
}


void listar(Cola *cola)
{
	Nodo *nuevoN;
	Cliente cliente;
	printf("\n============================================\n");
	printf("\nFILA DE CLIENTES EN ESPERA\n");
    for(nuevoN=cola->h;nuevoN!=NULL;nuevoN=nuevoN->siguiente)
    {
        cliente= nuevoN->info;
        listarCliente(&cliente);
        printf("\n");
    }
	printf("\n============================================\n");

}

void insertar(Cola *cola, Cliente cliente)
{
	Nodo *nuevoN;
	nuevoN = (Nodo *)malloc(1*sizeof(Nodo));
    if (nuevoN == NULL)
    {
       printf("\nError: memoria insuficiente...\n");
       return;
    }
    if (validarVacio(*cola))
        cola->h= cola->t= nuevoN;
	else {
        cola->t->siguiente=nuevoN;
        cola->t=nuevoN;
    }
    nuevoN->info = cliente;
    nuevoN->siguiente=NULL;
}

Cliente borrarCC(Cola *cola)
{
	Nodo *nuevoN=cola->h;
	Cliente cliente;
	if (!validarVacio(*cola))
	{
		if(cola->h==cola->t)
       		cola->h=cola->t=NULL;
		else
			cola->h=cola->h->siguiente;
		cliente=nuevoN->info;
		free(nuevoN);
		return cliente;
	}
}
