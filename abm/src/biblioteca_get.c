#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "biblioteca_get.h"

// FUNCIONES GET IN - FLOAT - CHAR - ARRAY INT - STRING

/**
 * \brief Solicita un entero al usuario y devuelve el exito o el facaso.
 * \param *resultado es el entero obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el entero
 * \param *mensajeError es el mensaje  de error
 * \param minimo es el numero minimo que puede ingresar el usuario
 * \param maximo es el numero maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el entero.
 * \return devuelve el -1 en caso de no haber podido obtener el numero, o el 0 en caso de exito.
 *
 */
int getInt(int *resultado,
		  char *mensaje,
		  char *mensajeError,//se declara como puntero el char
		  int minimo,
		  int maximo,
		  int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(resultado !=NULL &&
	    mensaje !=NULL &&
		mensajeError != NULL &&
		minimo<maximo &&
		reintentos >= 0)
	{
		do
		{
		printf("%s",mensaje);
		__fpurge(stdin);//fflush(stdin); //en windows funciona __fflush para limpiar
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
			{
				retorno =EXIT_SUCCESS;
				*resultado=buffer; //caso de exito
				break; //de aca salgo del while y evito poner el else
			}
		printf("%s", mensajeError);
		reintentos--;
	}while(reintentos >= 0);
	}return retorno;
}


/**
 * \brief Solicita un flotante al usuario y devuelve el exito o el facaso.
 * \param *resultado es el flotante obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el flotante.
 * \param *mensajeError es el mensaje  de error
 * \param minimo es el numero minimo que puede ingresar el usuario
 * \param maximo es el numero maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el flotante.
 * \return devuelve el -1 en caso de no haber podido obtener el numero, o el 0 en caso de exito.
 *
 */

float getFloat(float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos)
{
	int retorno= EXIT_ERROR;
	float buffer;
	if(resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		maximo>minimo &&
		reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);//fflush(stdin);
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno =0; //EXIT_SUCCESS;
					*resultado=buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}


/**
 * \brief Solicita un dato char al usuario y devuelve el exito o el facaso.
 * \param *resultadoChar es el char obtenido
 * \param *mensajeChar es el mensaje a ser mostrado para solicitar el char
 * \param *mensajeErrorChar es el mensaje  de error
 * \param minimo es el char minimo que puede ingresar el usuario
 * \param maximo es el char maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el char.
 * \return devuelve el -1 en caso de no haber podido obtener el dato, o el 0 en caso de exito.
 *
 */
char getChar (char *resultadoChar,
			  char *mensajeChar,
			  char *mensajeErrorChar,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char bufferChar;
	if(resultadoChar != NULL &&
		mensajeChar != NULL &&
		mensajeErrorChar != NULL &&
		minimo<maximo &&
		reintentos >=0)
	{
		do
		{
			printf("%s",mensajeChar);
			__fpurge(stdin);//fflush(stdin);
			if(scanf("%c",&bufferChar)==1)
			{
				if(bufferChar >= minimo && bufferChar <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultadoChar = bufferChar;
					break;
				}
			}
			printf("%s", mensajeErrorChar);
			reintentos--;
		}while (reintentos >=0 );
	}
	return retorno;
}


/**
 * \brief Solicita un aray de numeros enteros al usuario y devuelve el exito o el facaso.
 * \param array[] es el array obtenido
 * \param limite es el limite del array.
 * \param *pMensaje es el mensaje a ser mostrado para solicitar el array de enteros
 * \param *pMensajeError es el mensaje  de error
 * \param minimo es el numero minimo que puede ingresar el usuario
 * \param maximo es el numero maximo que puede ingresar el usuario
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el entero dentro del array.
 * \return devuelve el -1 en caso de no haber podido obtener el dato, o la cantidad de datos ingresados en el array.
 *
 */
int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos) //carga hasta que el usuario quiera, sin necesidad de utilizar el limite del array.
{
	int i=0;
	int buffer;
	char respuesta = 'n';
	int retorno = EXIT_ERROR;
	if(array != NULL && limite > 0)
	{
		do
		{
			if(getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				array[i] = buffer;
				i++;
				limite--;
			}
			printf("Continuar? (s/n)");
			__fpurge(stdin);//fflush(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = i;
	}
	return retorno;
}

/**
 * \brief Solicita una cadena de caracteres al usuario y devuelve el exito o el facaso.
 * \param *resultado es el string obtenido
 * \param *mensaje es el mensaje a ser mostrado para solicitar el string
 * \param *mensajeError es el mensaje  de error
 * \param minimo es la cantidad minima de carateres que puede tener el string
 * \param maximo es la cantidad maxima de carateres que puede tener el string
 * \param reintentos es la cantidad de veces que el usuario puede reintentar cargar el string.
 * \return devuelve el -1 en caso de no haber podido obtener el string, o el 0 en caso de exito.
 *
 */

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=EXIT_ERROR;
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
			retorno =EXIT_SUCCESS;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);
	}
	return retorno;
}

