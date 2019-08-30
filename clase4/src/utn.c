
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
		__fpurge(stdin); //en windows funciona __fflush para limpiar el buffer y que no salga muchas veces el mensaje
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
			__fpurge(stdin);
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno =EXIT_SUCCESS;
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
			__fpurge(stdin);
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






