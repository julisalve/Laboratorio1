/*
 * Pantallas.c
 *
 *  Created on: 2 oct. 2019
 *      Author: juliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantallas.h"

/**
 * \brief Inicializa todas las posiciones del array con el estado "vacio".
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int initLugarLibrePantallas(Pantallas *aArray, int cantidad)
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

/**
 * \brief BUsca un lugar libre y devuelve el fracaso o la posicion
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o la posicion del array con espacio libre, para ser utilizado
 *
 */
int buscarLugarPantalla(Pantallas *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
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

/**
 * \brief Genera ID irrepetiblre
 *
 * \return devuelve el numero de ID
 *
 */
static int generarId(void)
{
	static int contadorId=0; //es como seria global pero solo aplica para el scoup.
	contadorId++;
	return contadorId;
}

/**
 * \brief Carga datos en un array, cambiandole el estado a NO vacio y asignandole un id irrepetible, devuelve el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param buffer
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya lugar libre o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int altaPantallaPorId(Pantallas *aArray, int cantidad,Pantallas buffer)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarPantalla(aArray,cantidad);
		if(aArray != NULL && cantidad > 0 && i!=-1)
		{
			aArray[i]=buffer;
			aArray[i].status= STATUS_NOT_EMPTY;
			aArray[i].id = generarId();
			retorno = EXIT_SUCCESS;
		}
	return retorno;

}



/**
 * \brief Imprime un array de string, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayPantallas(Pantallas *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status!=STATUS_NOT_EMPTY)
			{
				printf("Id: %d - Status %d - NOmbre: %s - Direccion: %s - Precio: %.2f - Tipo %d\n",aArray[i].id,aArray[i].status,aArray[i].nombre,aArray[i].direccion,aArray[i].precio,aArray[i].tipo);
			}

		}
	}
	return retorno;
}
