#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "pila.h"

typedef struct
{
	char *apellido2;
	char *apellido;
}Apellidos;

typedef struct
{
	char *nombre;
	Apellidos *apellido;
}Nombre;

typedef struct
{
	Nombre *nom;
	int fol;
	MovimientosB *movi;
}Cliente;

typedef struct nodo
{
	Cliente info;
	struct nodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *h,*t;
}Cola;

typedef struct
{
	Cliente *arrBanco;
}Banco;

Banco *crearBC(int ventanillas);
Cola *crearCola();
int validarVacio(Cola cola);
void listar(Cola *cola);
void insertar(Cola *q,Cliente cliente);
Cliente borrarCC(Cola *cola);
Cliente *crearCliente();
void capturarCliente(Cliente *cliente);
void listarCliente(Cliente *cliente);
void push(MovimientosB *pila, char dato[]);



#endif // CLIENTE_H_INCLUDED
