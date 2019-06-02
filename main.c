#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cliente.h"
#include "pila.h"

int main()
{
    int i,c,s,t,n,v;
    Banco *banco;
    Cliente pasa;//cliente que ya paso
    Cola *cc;
	cc= crearCola();
	Cliente *cliente;
	printf("\n\n********** S U C U R S A L  B A N C A R I A **********");
    printf("\nVentanillas que se encuentren en servicio: "); //Numero de ventanillas que estaran funcionando
    scanf("%i",&v);
    banco=crearBC(v);
    int folio=0;
    srand(time(NULL));
    		c = 1+rand()% 10; //si se crean o no
 			if ((c>=1)&&(c<=5))
 			{
 				s=rand()%v+1;
 				printf("Numero de clientes: %i \n", s); //Cantidad de clientes que esperaran por pasar
 				for(i=0;i<s;i++)
 				{
 					printf("\nCliente Nuevo\n"); //Cliente que este empezando a ser atendido en una de las ventanillas
 					cliente = crearCliente();
					capturarCliente(cliente);
					folio++;
    				cliente->fol=folio;
					insertar(cc,*cliente);
					listarCliente(cliente);
					printf("\n");
				}
				listar(cc);

				if(!validarVacio(*cc))
				{
					for(i=0;i<v && !validarVacio(*cc) ;i++)
					{
						t=1+rand()%10;
						if((t>=1)&&(t<=5))
						{
							pasa= borrarCC(cc);
							banco->arrBanco[i]=pasa;
							printf("\n--->Ventanilla %i abierta \n \n\t***Atendiendo a: ",i+1);
							listarCliente(&pasa);
					printf("\n");
							listar(cc);
						//	system("pause");
						}
						else
						{
						if((t>=6)&&(t<=10))
								printf("\nVentanilla %i cerrada\n",i+1);
						}
					}
				}
 			}
				else
				{
					printf("\nNo hay clientes...\n");
				}
	return 0;
}
