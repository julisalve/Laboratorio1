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

int buscarPorId(struct sArray *aArray, int cantidad, int id)
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

int imprimirDatosPorId(struct sArray *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int indice =buscarPorId( aArray,cantidad, id);
	if(aArray != NULL && cantidad > 0)
	{

		if(indice>=0)
		{
			retorno = indice;
			printf("Status %d - Id: %d  \n",aArray[indice].status,aArray[indice].id);

		}
	}
	return retorno;
}


int modificacionPorIdCamposPuntuales(struct sArray *aArray, int len, int index)
{
	int retorno =EXIT_ERROR;
	char datoAModificar;
	struct sArray bArray;

		if(getChar(&datoAModificar,
				"Seleccione dato a modificar: a)TIPO, b)NOMBRE, c)DIRECCION d) PRECIO \n",
				"NO es una opcion valida \n",
				'a',
				'z',
				2)!=0)
		{
			printf("ERROR");
		}
		else
		{
			switch(datoAModificar)
			{
			case 'a':

				if(getTipo(bArray.tipo,
						"Ingrese el tipo a) LED, a)LCD  \n",
						"NO es un tipo valido \n",
						'a',
						'z',
						2)!=0)
				{
					printf("ERROR \n");
				}
				else
				{
					aArray[index].tipo==bArray.tipo;
					retorno =EXIT_SUCCESS;
				}
				break;
			case 'b':

				if(getApellido(bEmpleado.lastName,
						"Ingrese el apellido \n",
						"NO es un apellido valido \n",
						2,
						16,
						2)!=0)
				{
					printf ("Error\n");
				}
				else
				{
					strncpy(list[index].lastName,bEmpleado.lastName,50);
					retorno =EXIT_SUCCESS;
				}

				break;
			case 'c':

				if(getFloat(&bEmpleado.salary,
						"Ingrese el salario \n",
						"NO es un dato valido \n",
						0.01,
						1000000.0,
						2)!=0)
				{
					printf ("Error\n");
				}
				else
				{
					list[index].salary=bEmpleado.salary;
					retorno =EXIT_SUCCESS;
				}

				break;

			case 'd':

				if(getInt(&bEmpleado.sector,
						"Ingrese el sector 1) produccion, 2) ventas, 3) administracion \n",
						"NO es un sector valido\n",
						1,
						3,
						2)!=0)
				{
					printf ("Error\n");
				}
				else
				{
					list[index].sector=bEmpleado.sector;
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
