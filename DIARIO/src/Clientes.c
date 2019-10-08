#include "Clientes.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "general.h"
/**
 * \brief Inicializa todas las posiciones del array con el estado "vacio".
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */
int initLugarLibreClientes(Clientes *aArray, int cantidad)
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
 * \brief Imprime un array de string, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayClientes(Clientes *aArray, int cantidad)
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
				printf("Id: %d - Status %d - NOmbre: %s - Apellido: %s - Cuit: %s \n",aArray[i].id,aArray[i].status,aArray[i].nombre,aArray[i].apellido,aArray[i].cuit);
			}

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
int buscarLugarCliente(Clientes *aArray, int cantidad)
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
 * \brief Carga datos en un array, cambiandole el estado a NO vacio y asignandole un id irrepetible, devuelve el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param buffer
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya lugar libre o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int altaClientePorId(Clientes *aArray, int cantidad,Clientes buffer)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarCliente(aArray,cantidad);

		if(aArray != NULL && cantidad > 0 && i!=EXIT_ERROR)
		{
			aArray[i]=buffer;
			aArray[i].id = generarId();
			aArray[i].status = STATUS_NOT_EMPTY;
			retorno = EXIT_SUCCESS;
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
 * \brief Busca la posicion de un id ingresado por un usuario
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param id
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el id buscado
 *
 */
int buscarClientePorId(Clientes *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(aArray[i].status== STATUS_NOT_EMPTY && id==aArray[i].id)
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
int imprimirDatosClientePorId(Clientes *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i =buscarClientePorId(aArray,cantidad, id);
	if(aArray != NULL && cantidad > 0)
	{
		if(i>=0)
		{
			retorno = i;
			printf("Id: %d - Status %d - NOmbre: %s - apellido: %s - cuit %s\n",aArray[i].id,aArray[i].status,aArray[i].nombre,aArray[i].apellido,aArray[i].cuit);
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
int modificacionClientePorIdCamposPuntuales(Clientes *aArray, int cantidad, int index)
{
	int retorno =EXIT_ERROR;
	char datoAModificar;
	Clientes bCliente;
		if(getChar(&datoAModificar,	"Seleccione dato a modificar: a)nombre, b)apellido, c)cuit \n","NO es una opcion valida \n",	'a','z',2)!=0)
		{
			printf("ERROR");
		}
		else
		{
			switch(datoAModificar)
			{
			case 'a':

				if(getDatoSoloLetras(bCliente.nombre,"Ingrese el nombre \n","NO es un nombre valido \n",2,16,2)!=0)
				{
					printf("ERROR \n");
					break;
				}
				else
				{
					strncpy(aArray[index].nombre,bCliente.nombre,50);
					retorno =EXIT_SUCCESS;
				}
				break;
			case 'b':

				if(getDatoSoloLetras(bCliente.apellido,"Ingrese el apellido \n","NO es un apellido valido \n",2,16,2)!=0)
								{
									printf("ERROR \n");
									break;
								}
								else
								{
									strncpy(aArray[index].apellido,bCliente.apellido,50);
									retorno =EXIT_SUCCESS;
								}
								break;
			case 'c':

				if(getSoloNumeros(bCliente.cuit,"INgrese numero de cuit \n","NO es un cuit valido \n",10,17,2)!=0)
												{
													printf("ERROR.\n");
													break;
												}
				else
				{
					strncpy(aArray[index].cuit,bCliente.cuit,50);
														retorno =EXIT_SUCCESS;
				}

				break;

			default:
				printf("Error, opcion invalida \n");
				break;
			}
			}
			return retorno;
		}



int imprimirDatosEstructuraPorCoincidenciaIdConOtraEtructura(Clientes *aArray, int cantidad,ArrayEnteros *auxArray, int cantAuxArray)
{
	int retorno =EXIT_ERROR;
	int i;
	int j=0;
	int id;
	if(auxArray != NULL && cantAuxArray > 0 && aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			for(j=0;j<cantAuxArray;j++)
			{
				if(aArray[i].id==auxArray[j].entero)
				{
					id=aArray[i].id;
					imprimirDatosClientePorId(aArray,cantidad,id);
					retorno = EXIT_SUCCESS;
				}
			}
		}
	}
	return retorno;
}


