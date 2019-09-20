/*
 * Modelo_parcial.c
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Modelo_parcial.h"

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=-1;
	char buffer[4096];
	if(resultado!=NULL &&
		mensaje !=NULL &&
		mensajeError !=NULL &&
		maximo>minimo &&
		reintentos>0)
	{
	do
	{
		printf("%s", mensaje);
		__fpurge(stdin); //fflush(stdin) EN WINDOWS . limpia el teclado
		fgets(buffer,sizeof(buffer),stdin); //toma lo del teclado de manera segura
		buffer[strlen(buffer)-1]='\0'; //en buffer se toma hasta lo anterior en \0
		if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
		{
			strncpy(resultado,buffer,maximo+1);
			retorno =0;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);
	}
	return retorno;
}




int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
	{
		aArray[i].statusPantalla=STATUS_EMPTY;
	}
		}
		return retorno;
}



int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].statusPantalla == STATUS_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla)
{
	int retorno = -1;
	int i;
	i = buscarLugarLibrePantalle(aArray,cantidad);
		if(aArray != NULL && cantidad > 0 && i>=0)
		{
			aArray[i]=pantalla;
			aArray[i].statusPantalla= STATUS_NOT_EMPTY;
			retorno = EXIT_SUCCESS;
		}
	return retorno;
}





