/*
 * Empleados.c
 *
 *  Created on: 17 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Empleados.h"



int initLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad)
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

int buscarLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad)
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

int buscarEmpleadoPorId(struct sEmpleado *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	//int libre = buscarLugarLibreEmpleado(aArray, cantidad);
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(id==aArray[i].idEmpleado)
		{
			retorno = i;
			break;
		}
	}
	}
	return retorno;
}


int bajaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,int id)
{
	int retorno =EXIT_ERROR;
	char respuesta;
	int i = buscarLugarLibreEmpleado(aArray,cantidad);
	int idCoincide= buscarEmpleadoPorId(aArray, cantidad,id);

	if(aArray != NULL && cantidad > 0 && i>=0 && idCoincide==0)
		{
			printf("ESta seguro quiere darlo de baja: s o n?");
			scanf("%c",respuesta);
			if(respuesta=="s")
			{
				aArray[i].status= STATUS_EMPTY;
				retorno=EXIT_SUCCESS;
			}

		}
	return retorno;
}

//int eliminarEmpleadoPorId(struct sEmpleado *aArray, int cantidad, int id)
//{
//	//tiene que buscar, si devuelve -1 no xiste, si devuelve un numero lo pongo en estado empty
//}
//
//

int altaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado)
{
	int retorno = -1;
	int i;
	i = buscarLugarLibreEmpleado(aArray,cantidad);
		if(aArray != NULL && cantidad > 0 && i>=0)
		{
			aArray[i]=empleado;
			aArray[i].status= STATUS_NOT_EMPTY;
			retorno = EXIT_SUCCESS;
		}
	return retorno;
}

int altaForzadaEmpleados(struct sEmpleado *aArray,int cantidad)
{
	int retorno;
	int id[]={1,5,6,7,8};
	char nombre [][25]= {"juan","pedro","maria","eva","abrahm"};
	char apellido[][25]={"gomez","perez","lopez","rodrigguez","peron"};
	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].status=STATUS_NOT_EMPTY;
		aArray[i].idEmpleado=id[i];
		strncpy(aArray[i].nombre,nombre[i],25);
		strncpy(aArray[i].apellido,apellido[i],25);
		retorno=0;

	}
	return retorno;
}


int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aEmpleado[i].status== STATUS_NOT_EMPTY)
			{
				printf("status %d - Id: %d - Nombre: %s - Apellido: %s  \n",aEmpleado[i].status,aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido);
			}

		}
	}
	return retorno;
}

int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	struct sEmpleado bEmpleados;
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,50)>0)
				{
					fSwap = 1;
					bEmpleados=aEmpleado[i];
					aEmpleado[i]=aEmpleado[i+1];
					aEmpleado[i+1]=bEmpleados;
				}
				else if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,50)==0)

				{
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,50)>0)
						{
							fSwap = 1;
							bEmpleados=aEmpleado[i];
							aEmpleado[i]=aEmpleado[i+1];
							aEmpleado[i+1]=bEmpleados;
						}
				}
			}
		}while(fSwap);
	}
	return retorno;
}
