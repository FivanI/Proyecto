#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "pila.h"
#define MAXTXT 30

Cliente *crearCliente()
{
	Cliente *nuevoC;
	nuevoC= (Cliente *)calloc(1,sizeof(Cliente));
	if(nuevoC==NULL){
		printf("\nError: no se puede crear...\n");
		return nuevoC;
	}
	nuevoC->nom = (Nombre *)calloc(1,sizeof(Nombre));
	nuevoC->nom->nombre = (char *)calloc(MAXTXT,sizeof(char));
	nuevoC->nom->apellido = (Apellidos *)calloc(1,sizeof(Apellidos));
	nuevoC->nom->apellido->apellido2 = (char *)calloc(MAXTXT,sizeof(char));
	nuevoC->nom->apellido->apellido= (char*)calloc(MAXTXT,sizeof(char));
	nuevoC->movi=crearPila();
	return nuevoC;
}

void capturarCliente(Cliente *cliente)
{
	char nombres[5][MAXTXT]={"Juan","Jose","Marco","Mariana","Julieta"};
	char apellido[5][MAXTXT]={"Marquez","Juarez","Gonzalez","Hernandez","Perez"};
	char apellidos2[5][MAXTXT]={"Martinez","Venegas","Fuentes", "Ramirez", "Cortes"};
	char movimientos[5][20] = {"Deposito", "Retiro","Pago de tarjeta","Pago de servicios", "Consulta de saldo"};
	int n,mov,num;
	n = rand()%4;
	strcpy(cliente->nom->nombre,nombres[n]);
	n= rand()%4;
	strcpy(cliente->nom->apellido->apellido,apellido[n]);
	n= rand()%4;
	strcpy(cliente->nom->apellido->apellido2,apellidos2[n]);

	num=rand()%5 + 1; //numero de movimientos
	printf("Numero de movimientods: %i", num);
		for(n=1;n<=num;n++){
			    mov=rand()%4;
				push(cliente->movi,movimientos[mov]);
			}
}

void listarCliente(Cliente *cliente)
{
	printf("\nNombre:\t %s %s %s\nFolio:\t %i",cliente->nom->nombre,cliente->nom->apellido->apellido,
        cliente->nom->apellido->apellido2,cliente->fol,cliente->movi->tope->info);
	printf("\nMovimientos: ");
	listarPila(*cliente->movi);
}

Banco *crearBC(int ventanillas)
{
	Banco *banco;
	banco= (Banco *)calloc(1,sizeof(Banco));
	if(banco==NULL)
		printf("\nError: No hay ventanillas...\n");
	banco->arrBanco=(Cliente *)calloc(ventanillas,sizeof(Cliente));
}
