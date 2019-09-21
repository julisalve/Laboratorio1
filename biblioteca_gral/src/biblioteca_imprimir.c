/*
 * biblioteca_imprimir.c
 *
 *  Created on: 21 sep. 2019
 *      Author: juliana
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "biblioteca_solicitud_datos.h"
#include "biblioteca_validaciones.h"
#include "biblioteca_get.h"
#include "biblioteca_ordenamientos.h"
#include "biblioteca_imprimir.h"

int initArrayInt(int array[],int limite,int valor ) //permite inicializar en un valor y le suma 1 al valor de cada posicion del array.
{
	int i;
	int retorno = EXIT_ERROR;
	if(array != NULL && limite > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<limite;i++)
		{
			array[i]=valor+i;
		}

	}
	return retorno;
}

int imprimeArrayInt(int array[],int limite )
{
	int i;
	int retorno = EXIT_ERROR;
	if(array != NULL && limite > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}
		system("pause");//esto en linux no va
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
			printf("Id: %d - Nombre: %s - Apellido: %s - dni: %s - Domicilio %s - Telefono %s \n",aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido,aEmpleado[i].dni,aEmpleado[i].domicilio,aEmpleado[i].telefono);
		}
	}
	return retorno;
}




