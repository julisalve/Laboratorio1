/*
 ============================================================================
 Name        : clase_5.c
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

#define CANT_EMPLEADOS 1000

int initArrayInt( int array[],int limite,int valor);
int imprimirArray(int array[],int limite);




int getArrayInt(int array[],
		int limite,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos);

int main()
{
	int i;
	char respuesta = 'n';
		int retorno=-1;
		if(array !=NULL && limite>0)
		{
			do
			{
				limite--;

				//getChar
				printf("Continuar?");
				__fpurge(stdio);
				scanf("%c",&respuesta)
			}
			while(respuesta=='s' && limite >0);


		}
		return retorno;
} //esto es lo q hizo el profe.



int getArrayInt(int array[],
		int limite,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos) //pide dato al usuario hasta que quiera el usuario, CAUndo sale en el retorno indica cuantos datos ingreso el usuario.
{
	int i;
	int buffer;
	int retorno=-1;
	for(i=0;i<limite;i++)
	{
		if(getIn(&buffer,
			mensaje,
			mensajeError,
			minimo,
			maximo,
			reintentos)==0);
	}
	retorno =0;
	return retorno;
}




int maximoArrayInt(int array[],
		int limite,
		int cantidadElementos,
		int *resultado)

int minimoArrayInt(int array[],
		int limite,
		int cantidadElementos,
		int *resultado)

int promedioArrayInt(int array[],
		int limite,
		int cantidadElementos,
		float *resultado)

int main(void) {


	int edadesEmpleados[CANT_EMPLEADOS];
	if(initArrayInt(edadesEmpleados,CANT_EMPLEADOS,10)==0)
	{
		imprimirArray(edadesEmpleados,CANT_EMPLEADOS);
	}






	return EXIT_SUCCESS;
}



int initArrayInt( int array[],int limite,int valor) //siempre se pasa array y limite
{
	int i;
	int retorno=-1;
	if(array !=NULL && limite>0)
	{

	retorno=0;
	for(i=0;i<limite;i++)

		{
			array[i]=valor+i;
		}
	}
	return retorno;

}



int imprimirArray(int array[],int limite)
{

	int i;
		int retorno=-1;
		if(array !=NULL && limite>0)
		{

		retorno=0;
		for(i=0;i<limite;i++)

			{
				printf("%d \n",array[i]);
			}
		}
		return retorno;
}  //esta ok!


int maximoArray(int array[],int limite)
{

	int i;
		int retorno=-1;
		int maximo;
		if(array !=NULL && limite>0)
		{

		retorno=0;
		maximo=array[0];
		for(i=0;i<limite;i++)

			{

			}
		}
		return retorno;
}

en un double hacer promerçdio y pedir datos log long

