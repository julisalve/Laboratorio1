/*
 * biblioteca_solicitud_datos.c
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


int getNombre(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=-1;
	char buffer[4096];
	do
		{
		getString(buffer,

					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);
		}while(esLetra(buffer,
				mensaje,
				mensajeError,
				minimo,
				maximo,
				reintentos)!=0);

		 if(esLetra(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos)==0)
			 {
			 	 strncpy(resultado,buffer,maximo+1);
		       	  retorno = 0;}
	return retorno;
	}


int getDni(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];

	do{
		getString(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);
		}while (isNumber(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)!=0);


			if(isNumber(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos)==0)
			{
		       	  strncpy(resultado,buffer,maximo+1);
		       	  retorno = EXIT_SUCCESS;

			}
	return retorno;
	}

int getDomicilio(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];

	do{
		getString(buffer,

					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);
		}while (esAlfaNumerico(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)!=0);


			if(esAlfaNumerico(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos)==0)
			{
		       	  strncpy(resultado,buffer,maximo+1);
		       	  retorno = 0;

			}
	return retorno;
	}

int getTelefono(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
	char buffer[4096];

	do{
		getString(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);
		}while (esTelefono(buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)!=0);


			if(esTelefono(buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos)==0)
			{
		       	  strncpy(resultado,buffer,maximo+1);
		       	  retorno = 0;

			}
	return retorno;
	}




