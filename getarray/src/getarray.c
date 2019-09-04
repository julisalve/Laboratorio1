/*
 ============================================================================
 Name        : getarray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "utn.h"


int getArrayInt(int array[],
		int limite,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos);



int main()
{

	int array[5];

	getArrayInt(array,
			3,
			"Ingrese un numero \n",
			"NO es un numero\n",
			0,
			100,
			0);
}



int getArrayInt(int array[],
		int limite,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos) //pide dato al usuario hasta que quiera el usuario, CAUndo sale en el retorno indica cuantos datos ingreso el usuario.
{
	int i;
	int resultado;
	int retorno=-1;

//	while(resultado<minimo || resultado>maximo)
//		{
//			printf("s%",mensajeError);
//		}
	for(i=0;i<limite;i++)
	{
		getIn(&resultado,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos);

	}
	retorno =0;
	return retorno;
}
