/*
 * Pantallas.c
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */


#include "Pantallas.h"

static int generarId(void)
{
	static int contadorId=0; //es como seria global pero solo aplica para el scoup.
	contadorId++;
	return contadorId;
}

int initLugarLibre(struct sArray *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
	{
		aArray[i].status=STATUS_EMPTY;
	}
		}
		return retorno;
}

int buscarLugarLibre(struct sArray *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaPorId(struct sArray *aArray, int cantidad,struct sArray item)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarLibre(aArray,cantidad);
		if(aArray != NULL && cantidad > 0 && i!=-1)
		{
			aArray[i]=item;
			aArray[i].status= STATUS_NOT_EMPTY;
			aArray[i].id = generarId();
			retorno = EXIT_SUCCESS;
		}
	return retorno;
}

int imprimirArray(struct sArray *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status== STATUS_NOT_EMPTY)
			{
				printf(" status : %d - Id: %d \n",aArray[i].status,aArray[i].id);
			}

		}
	}
	return retorno;
}
