/*
 * Publicidad.c
 *
 *  Created on: 2 oct. 2019
 *      Author: juliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Publicidad.h"


/**
 * \brief Inicializa todas las posiciones del array con el estado "vacio".
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */

int initLugarLibrePublicidad(Publicidades *aArray, int cantidad)
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
 * \brief BUsca el primer lugar libre y devuelve el fracaso o la posicion
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o la posicion del array con espacio libre, para ser utilizado
 *
 */

int buscarLugarPublicidad(Publicidades *aArray, int cantidad)
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
 * \brief Busca la posicion de un id ingresado por un usuario
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param id
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el id buscado
 *
 */
int buscarPantallaPorIdEnPublicidad(Publicidades *aArray, int cantidad, int idPant)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(idPant==aArray[i].idPantalla)
		{
			retorno = i;
			break;
		}
	}
	}
	return retorno;
}


/**
 * \brief Carga datos en un array, cambiandole el estado a NO vacio y asignandole un id irrepetible, devuelve el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param buffer
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya lugar libre o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int altaPublicidad(Publicidades *aArrayPub, int cantidad, Publicidades buffer,Pantallas *aArray, int cantidadPant,int index)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarPublicidad(aArrayPub,cantidad);

		if(aArrayPub != NULL && cantidad > 0 && i!=EXIT_ERROR)
		{
			aArrayPub[i]=buffer;
			aArrayPub[i].id = generarId();
			aArrayPub[i].status = STATUS_NOT_EMPTY;
			aArrayPub[i].idPantalla=aArray[index].id;
			retorno = EXIT_SUCCESS;
		}
	return retorno;

}


/**
 * \brief Busca la posicion de un cuit ingresado por un usuario
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param id
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el id buscado
 *
 */
int buscarPublicidadIdPantallaPorCuit(Publicidades *aArray, int cantidad, char cuit, Publicidades *aArayAux)
{
	int retorno =EXIT_ERROR;
	int i;
	int j=0;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(aArray[i].status== STATUS_NOT_EMPTY && cuit==aArray[i].cuit)
		{
			aArayAux[j].idPantalla = aArray[i].idPantalla;
			j++;
			retorno=EXIT_SUCCESS;
		}
	}
	}
	return retorno;
}


int imprimirDatosPantallasPorCuitPublicidades(Pantallas *aArray, int cantidad, Publicidades *aArrayAux, int cantArrayAux)
{
	int retorno =EXIT_ERROR;
	int i;
	int j;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantArrayAux;i++)
	{
			for(j=0;j<cantidad;j++)
			{
				if(aArrayAux[i].idPantalla==aArray[j].id)
						{
					 	 imprimirDatosPantallaPorId(aArray,cantidad,aArray[j].id);
							retorno=EXIT_SUCCESS;
						}
			}

	}
	}
	return retorno;
}


