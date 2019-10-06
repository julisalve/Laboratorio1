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
int altaPublicidad(Publicidades *aArrayPub, int cantidad, Publicidades buffer)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarPublicidad(aArrayPub,cantidad);

		if(aArrayPub != NULL && cantidad > 0 && i!=EXIT_ERROR)
		{
			aArrayPub[i]=buffer;
			aArrayPub[i].id = generarId();
			aArrayPub[i].status = STATUS_NOT_EMPTY;
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
int buscarPublicidadIdPantallaPorCuit(Publicidades *aArray, int cantidad, char *cuit, Publicidades *aArayAux)
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


/**
 * \brief Genera ID irrepetiblre
 *
 * \return devuelve el numero de ID
 *
 */
static int generarId()
{
	static int contadorId=0; //es como seria global pero solo aplica para el scoup.
	contadorId++;
	return contadorId;
}

/**
 * \brief Imprime un array de string, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayPublicidad(Publicidades *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY)
			{
				printf("Id: %d - Status %d - IDPantalla: %d - NOmbre archivo: %s - dias: %d - cuit %s\n",aArray[i].id,aArray[i].status,aArray[i].idPantalla,aArray[i].nombreArchivo,aArray[i].dias,aArray[i].cuit);
			}

		}
	}
	return retorno;
}

/**
 * \brief Busca las posiciones de array en las que se encuentra un dato
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param item dato a buscar en el array
 * \param auxArray array de enteros
 * \param cantAuxArray tamaño del array auxiliar
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya coincidencia entra dato buscado y dato del array devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int buscarDatoStringValido(Publicidades *aArray, int cantidad, char *item, ArrayEnteros *auxArray, int cantAuxArray)
{
	int retorno= EXIT_ERROR;
	int i;
	int j=0;
	if(aArray != NULL && cantidad>0)
		{
		for(i=0;i<cantidad;i++)
		{
			if(strncmp(aArray[i].cuit,item,50)==0)
			{
				retorno=EXIT_SUCCESS;
				auxArray[j].entero=aArray[i].idPantalla;
				auxArray[j].status=STATUS_NOT_EMPTY;
				j++;
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
int buscarPublicidadPorIdPantalla(Publicidades*aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(aArray[i].status== STATUS_NOT_EMPTY && id==aArray[i].idPantalla)
		{
			retorno = i;
			break;
		}
	}
	}
	return retorno;
}


/**\brief Imprime datos de un id en particular
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param id es el id solicitado
 * \return int DEvuelve(EXIT_ERROR -1) en caso de que el array sea nulo o sea invalido el tamaño o devuelve la posicion del id en caso de exito
 *
 */
int imprimirDatosPublicidadPorId(Publicidades *aArray, int cantidad, int index,int caso)
{
	int retorno =EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		if(index>=0)
		{
			switch(caso)
			{
			case 1:
				retorno = EXIT_SUCCESS;
				printf("La cantidad de dias contratados para esta publicidad es: %d \n",aArray[index].dias);
				break;
			case 2:
				retorno = EXIT_SUCCESS;
				printf("NOmbre del archivo : %s - CAntidad de dias %d \n \n",aArray[index].nombreArchivo,aArray[index].dias);
				break;

			}

		}
	}
	return retorno;
}


/**\brief Modifica el dato que se desee de los campos de la estructura del srray
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param index posicion del array
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o EXIT SUCCESS (0) en caso de exito
 *
 */
int modificacionPublicidadPorIdCamposPuntuales(Publicidades *aArray, int cantidad, int index, int caso)
{
	int retorno =EXIT_ERROR;
	Publicidades bPublicidad;
	switch(caso)
	{
	case 1:
		if(getInt(&bPublicidad.dias,"Ingrese la nueva cant de dias de la publicidad \n","NO es un dato valido \n",1,1000000,2)!=0)
	{
		printf ("Error\n");
	}
		else
		{
			aArray[index].dias=bPublicidad.dias;
								retorno =EXIT_SUCCESS;

		}
		break;
	case 2:
		aArray[index].status=STATUS_EMPTY;
			retorno =EXIT_SUCCESS;
break;
	}

					return retorno;
		}



int imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(Publicidades *aArray, int cantidad, char *item)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY && strncmp(aArray[i].cuit,item,50)==0)
			{
				printf("Id: %d - Status %d - IDPantalla: %d - NOmbre archivo: %s - dias: %d - cuit %s\n",aArray[i].id,aArray[i].status,aArray[i].idPantalla,aArray[i].nombreArchivo,aArray[i].dias,aArray[i].cuit);
			}

		}
	}
	return retorno;
}



int buscarPublicidadPorIdYCuit(Publicidades *aArray,int cantidad,int id,char *item)
{
	int retorno =EXIT_ERROR;
		int i;
		if(aArray != NULL && cantidad > 0)
		{
			for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status== STATUS_NOT_EMPTY && id==aArray[i].idPantalla && strncmp(item,aArray[i].cuit,50)==0)
			{
				retorno = EXIT_SUCCESS;
			}
		}
		}
		return retorno;
}




int buscarPublicidadPorCuit(Publicidades *aArray, int cantidad, char *item, Publicidades *auxPubl, int cantAux)
{
	int retorno= EXIT_ERROR;
	Publicidades bPubl[]={1,1,2,"juli",3,"33333333333"};
	int i;
	int j=0;
	if(aArray != NULL && cantidad>0)
		{
		for(i=0;i<cantidad;i++)
		{
			if(strncmp(aArray[i].cuit,item,50)==0)
			{
				 //aArray[i];
				retorno=EXIT_SUCCESS;
				auxPubl[j]=bPubl; //aArray[i].dias;
				//aArray[i].dias=6;

				j++;
				printf("nombre archivo %s - dias %d \n ",auxPubl[j].nombreArchivo,auxPubl[j].dias);
			}
		}
		}

	return retorno;
}

int imprimirPrecioPublicidad(Publicidades *auxArray, int cantAux, Pantallas *aArrayPant,int cantPant)
{
	int retorno= EXIT_ERROR;
	int i;
	int j=0;
	float resultado;
	if(auxArray != NULL && cantAux>0 && aArrayPant != NULL && cantPant>0)
		{
		for(i=0;i<cantPant;i++)
		{
			for(j=0;j<cantAux;j++)
			{
				if(aArrayPant[i].id,auxArray[j].idPantalla && auxArray[j].status==STATUS_NOT_EMPTY)
							{
								retorno=EXIT_SUCCESS;
								resultado=aArrayPant[i].precio*auxArray[j].dias;
								printf("NOmbre del archivo : %s - CAntidad de dias %d - Precio %.2f \n \n",auxArray[j].nombreArchivo,auxArray[j].dias,resultado);

							}
			}

		}
		}

	return retorno;
}
