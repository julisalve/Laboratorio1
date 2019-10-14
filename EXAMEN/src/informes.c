#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "informes.h"





int menuInformes(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes)
{
	int retorno= EXIT_ERROR;
	char opcion;
	float acumulador;
	while(getChar(&opcion, "Ingrese una opcion de informes\n  a)Cantidad maxima de desechos\n", "NO es una opcion valida.",'a','z',3)!=0)
			{
				printf("ERROR.\n ");
			}
	switch (opcion)
	{
	case 'a':
		//buscarPedidoConMasDesechos(aArrayPed,cantPed);
		buscarCuitConMasDesechos (aArrayClientes, cantClientes, aArrayPed,cantPed);
		break;
	case 'b':
		acumulador= sumaTotalesDeDesechos(aArrayPed,cantPed);
		printf("La suma total de desechos es: %.2f \n",acumulador);
		break;
	case 'c':
		ordenarPorIdCliente(aArrayPed,cantPed);

		break;
	break;
	}
	return retorno;
}

/**
 * \brief BUsca el primer lugar de pedido completo/procesado y devuelve el fracaso o la posicion
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o la primer posicion del array procesado/completo, para ser utilizado
 *
 */

int buscarPrimerLugarPedidoCompletoProcesado(Pedidos *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_COMPLETO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Busca e imprime el id Cliente con mayor cantidad de desechos
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve el id maximo en caso de exito
 *
 */
int buscarPedidoConMasDesechos(Pedidos *aArray, int cantidad)
{
	int retorno=EXIT_ERROR;
	float maximosKilosDesechos;
	int maximoIdCliente;
	int primerPosicionOcupada= buscarPrimerLugarPedidoCompletoProcesado(aArray,cantidad);
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		maximosKilosDesechos=aArray[primerPosicionOcupada].kilosDesecho_4;
		maximoIdCliente=aArray[primerPosicionOcupada].idCliente;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].kilosDesecho_4>maximosKilosDesechos && aArray[i].status==STATUS_COMPLETO)
			{
				maximosKilosDesechos=aArray[i].kilosDesecho_4;
				maximoIdCliente=aArray[i].idCliente;
			}
		}
		printf("La cantidad maxima de desechos es %.2f ",maximosKilosDesechos);
		retorno=maximoIdCliente;
	}
	return retorno;
}


int buscarCuitConMasDesechos (Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPedidos, int cantPed)
{
	int retorno=EXIT_ERROR;
	int id;
	int index;
	if(aArrayClientes != NULL && cantClientes > 0 &&aArrayPedidos != NULL && cantPed > 0)
	{
		id=buscarPedidoConMasDesechos(aArrayPedidos, cantPed);
		index=buscarClientePorId(aArrayClientes,cantClientes,id);
		printf(" y el cuit es %s \n",aArrayClientes[index].cuit);
	}
	return retorno;
}


int sumaTotalesDeDesechos(Pedidos *aArrayPed, int cantPed)
{
	int retorno =EXIT_ERROR;
	int i;
	float acumulador=0.00;
	if(aArrayPed != NULL && cantPed > 0)
	{
		for(i=0;i<cantPed;i++)
		{
			if(aArrayPed[i].status==STATUS_COMPLETO)
			{
				acumulador=acumulador+aArrayPed[i].kilosDesecho_4;
			}
		}
		retorno=acumulador;
	}
	return retorno;
}
