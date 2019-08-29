/*
 * utn.c
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

//int saludarAlUsuario(void)
//{
//	printf("Hola");
//	return 0;
//}



int getIn(int *resultado,
		  char *mensaje,
		  char *mensajeError,
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
		__fpurge(stdin); //en windows funciona __fflush
		if(scanf("%d",&buffer)==1)
		{
			if(buffer >= minimo && buffer <= maximo)
			{
				retorno =EXIT_SUCCESS;
				*resultado=buffer; //caso de exito
				break; //de aca salgo del while y evito poner el else
			}
		}
		printf("%s", mensajeError);
		reintentos--;



	}while(reintentos >= 0);


	}
	return retorno;
}
