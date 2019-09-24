/*
 * biblioteca_validaciones.c
 *
 *  Created on: 21 sep. 2019
 *      Author: juliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "biblioteca_validaciones.h"

/**
 * \brief Valida si el dato es numerico y devuelve el exito o el facaso.
 * \param *resultado es el numero obtenido
 * \param *mensaje es el mensaje a ser mostrado
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad de numeros minimos que puede ingresar el usuario
 * \param maximo es la cantidad de numeros maximos que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar .
 * \return devuelve el -1 en caso de no ser un numero, o el 0 en caso de exito.
 *
 */

int isNumber(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno =EXIT_ERROR;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);//strncpy(buffer,resultado,maximo+1);
	int cantidad=0;
	int contador=0;
	cantidad=strlen(buffer);
   	while(buffer[i] != '\0' && (buffer[i] >= '0' && buffer[i] <= '9'))
		  {
   			contador++;
			i++;
		  }
   	if(contador==cantidad)
   	{

   		strncpy(resultado,buffer,maximo+1);
   		retorno = EXIT_SUCCESS;
   	}
   	else
   	{
   		printf("%s",mensajeError);

   	}
   	return retorno;
}

/**
 * \brief Valida si el dato es solo letras y devuelve el exito o el facaso.
 * \param *resultado son las letras obtenidas
 * \param *mensaje es el mensaje a ser mostrado.
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad de letras minimas que puede ingresar el usuario
 * \param maximo es la cantidad de letras maximas que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar .
 * \return devuelve el -1 en caso de no ser letras, o el 0 en caso de exito.
 *
 */

int esLetra(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno =-1;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);//strncpy(buffer,resultado,maximo+1);
   	int cantidad;
   	int contador=0;
   	cantidad=strlen(buffer);
   	while((buffer[i] != '\0' && buffer[i]== ' ') || (buffer[i] >= 'a' && buffer[i] <= 'z')|| (buffer[i] >= 'A' && buffer[i] <= 'Z'))
		  {
			contador++;
			i++;
		   }
if(cantidad==contador)
	{
	strncpy(resultado,buffer,maximo+1);
	retorno = 0;
	}
else
{
	printf("%s",mensajeError);
}
	return retorno;
}

/**
 * \brief Valida si el dato es alfanumerico y devuelve el exito o el facaso.
 * \param *resultado son las letras y/o numeros obtenidas
 * \param *mensaje es el mensaje a ser mostrado.
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad de letras y/o numeros minimos que puede ingresar el usuario
 * \param maximo es la cantidad de letras y/o numeros maximos que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar .
 * \return devuelve el -1 en caso de no ser letras y/o numeros, o el 0 en caso de exito.
 *
 */
int esAlfaNumerico(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno =-1;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);//strncpy(buffer,resultado,maximo+1);
   	int cantidad;
   	int contador=0;
   	cantidad=strlen(buffer);
   	while((buffer[0] != '\0' && buffer[i]== ' ') || (buffer[i] >= 'a' && buffer[i] <= 'z')|| (buffer[i] >= 'A' && buffer[i] <= 'Z')||(buffer[i] > '0' && buffer[i] < '9'))
		  {
			contador++;
			i++;
		   }
if(cantidad==contador)
	{
	strncpy(resultado,buffer,maximo+1);
	retorno = 0;
	}
else
{
	printf("%s",mensajeError);
}
	return retorno;
}

/**
 * \brief Valida si el dato es un numero de telefono y devuelve el exito o el facaso.
 * \param *resultado es el numero de telefono obtenido
 * \param *mensaje es el mensaje a ser mostrado.
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad de datos minimos que puede ingresar el usuario
 * \param maximo es la cantidad de datos maximos que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar .
 * \return devuelve el -1 en caso de no ser telefono, o el 0 en caso de exito.
 *
 */
int esTelefono(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno =-1;
	int i=0;
	char buffer[4096];
	strncpy(buffer,resultado,maximo+1);//strncpy(buffer,resultado,maximo+1);
   	int cantidad;
   	int contador=0;
   	int contadorGuion=0;
   	cantidad=strlen(buffer);
   	while(buffer[0] != '\0' && buffer[i]=='-' && (buffer[i] > '0' && buffer[i] < '9'))
		  {
			contador++;
			i++;
		   }
   	if(buffer[i]=='-')
   		{
   		contadorGuion++;
   		}
if(cantidad==contador && contadorGuion==1)
	{
	strncpy(resultado,buffer,maximo+1);
	retorno = EXIT_SUCCESS;
	}
else
{
	printf("%s",mensajeError);
}
	return retorno;
}


int esSiONo(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno =EXIT_ERROR;
	char buffer[4096];
	do
	{	getString(buffer,
				mensaje,
				mensajeError,
				minimo,
				maximo,
				reintentos);

		if(strncmp(buffer,"si",maximo+1)==0 || strncmp(buffer,"no",maximo+1)==0)
		{
   		strncpy(resultado,buffer,maximo+1);
   		retorno = EXIT_SUCCESS;
   		break;
   		}
		else
		{
			printf("%s",mensajeError);
			reintentos--;
		}
	}while(reintentos>=0);
   	return retorno;
}
