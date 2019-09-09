/*
 ============================================================================
 Name        : Biblioteca.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include "Biblioteca.h"

// FUNCIONES GET

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
		fflush(stdin);//__fpurge(stdin); //en windows funciona __fflush para limpiar
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
			fflush(stdin);//__fpurge(stdin);
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
			fflush(stdin);//__fpurge(stdin);
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
			fflush(stdin);//__fpurge(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = i;
	}
	return retorno;
}


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


int sumaEnteros(int primerValorSumar, int segundoValorSumar, int *resultadoInt) // int* llama a direccion de memoria. LAS FUNCIONES, SUMAR, CALCULAR, ETC NO INTERACTUAN CON EL USUARIO
{
	int retorno =EXIT_ERROR; //inicializo en retorno con error
	long resultadoLong;
	resultadoLong =primerValorSumar + segundoValorSumar;
	if (resultadoLong <= MAX_INT)
	{
		retorno =EXIT_SUCCESS;
		*resultadoInt = (int)resultadoLong; //esto se llama casting, cuando queres guardar un tipo de dato en otro tipo de dato, esto es para evitar que salga el warning
	}
	return retorno; //EL VALOR DE RETORNO TIENE QEU SER SI SALIO BIEN 0 O NUMERO POSITIVO, SI SALIO MAL NUMEROS NEGATIVOS.
}

//int calcularNumeroMax(int numero, int *numeroMax)
//{
//	int retorno=EXIT_ERROR;
//	int contador=0;
//	long numeroLong;
//	if(numeroLong<=MAX_INT && (contador==0 || numeroLong>numeroMax))
//	{
//		retorno=EXIT_SUCCESS;
//		numero=numeroLong;
//		*numeroMax=numero;
//	}
//	contador++;
//	return retorno;
//}
//
//int calcularMinimo(int numero, int *numeroMin,int *contador)
//{
//	int retorno=-1;
//	if(*contador==0 || numero<*numeroMin)
//	{
//		retorno=0;
//		*numeroMin=numero;
//		*contador=*contador+1;
//	}
//	return retorno;
//}

//
//int sacarPromedio(int acumulador, float *promedio)
//{
//    int retorno=0;
//    *promedio=(float)acumulador/CANTIDAD_NUMEROS;
//
//    return retorno;
//}

int maximoArrayInt(int array[],int limite,int *pResultadoPosMax, int *pResultadoMax)
{
	int i;
	int retorno = EXIT_ERROR;
	int maximo;
	int posMaximo;
	if(array != NULL && limite > 0)
	{
		retorno = EXIT_SUCCESS;
		maximo = array[0];
		posMaximo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]>maximo)
			{
				maximo = array[i];
				posMaximo=i;
			}
		}
		*pResultadoPosMax = posMaximo;
		*pResultadoMax = maximo;
	}
	return retorno;
}

int ordenarArrayIntAscendente(int array[],int limite)
{
	int i;
	int retorno = EXIT_ERROR;
	int bufferInt;
	int flagSwap;
	if(array != NULL && limite > 0)
	{
		retorno=EXIT_SUCCESS;
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
				{
					if(array[i]>array[i+1])
					{
						flagSwap=1;
						bufferInt=array[i];
						array[i]=array[i+1];
						array[i+1]=bufferInt;
						}
					}
			}while(flagSwap==1);
		}return retorno;
}

int ordenarArrayIntDescendente(int array[],int limite)
{
	int i;
	int retorno = EXIT_ERROR;
	int bufferInt;
	int flagSwap;
	if(array != NULL && limite > 0)
	{
		retorno=EXIT_SUCCESS;
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
				{
					if(array[i]<array[i+1])
					{
						flagSwap=1;
						bufferInt=array[i];
						array[i]=array[i+1];
						array[i+1]=bufferInt;
						}
					}
			}while(flagSwap==1);
		}return retorno;
}

int ordenarInsertionDescendente(int array[],int limite)
{
 int i;
 int retorno =EXIT_ERROR;
 int bufferInt;
 int j;

 if(array != NULL && limite > 0)
 {retorno =EXIT_SUCCESS;
 	 	 for(i=1;i<limite;i++)
 	 	 {
 	 		j=i;

 	 		 while(array[j]<array[j-1] && j>0)
 	 		 {
 	 			 bufferInt=array[j-1];
 	 			 array[j-1]=array[j];
 	 			 array[j]=bufferInt;
 	 			j--;
 	 		 }
 	 	 }
 	 }return retorno;
}

//
//int ordenarInsertionAscentende(int array[],int limite)
//{
// int i;
// int retorno =EXIT_ERROR;
// int bufferInt;
// int j;
//
// if(array != NULL && limite > 0)
// {retorno =EXIT_SUCCESS;
// 	 	 for(i=1;i<limite;i++)
// 	 	 {
// 	 		j=i;
// 	 		 while(array[j]>array[j-1] && j>=1)
// 	 		 {
// 	 			 bufferInt=array[j-1];
// 	 			 array[j-1]=array[j];
// 	 			 array[j]=bufferInt;
//  	 		 }j--;
// 	 	 }
// 	 }return retorno;
//}



//int getString(char *resultado,
//				char *mensaje,
//				char *mensajeError,
//				int minimo,
//				int maximo,
//				int reintentos)
//{
//	int retorno=-1;
//	char buffer[4096];
//	if(resultado!=NULL &&
//		mensaje !=NULL &&
//		mensajeError !=NULL &&
//		maximo>minimo &&
//		reintentos>0)
//	{
//	do
//	{
//		printf("%s", mensaje);
//		fflush(stdin);//__fpurge(stdin); //limpia el teclado
//		fgets(buffer,sizeof(buffer),stdin); //toma lo del teclado de manera segura
//		buffer[strlen(buffer)-1]='\0'; //en buffer se toma hasta lo anterior en \0
//		if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
//		{
//			strncpy(resultado,buffer,maximo+1);
//			retorno =0;
//			break;
//		}
//		printf("%s",mensajeError);
//		reintentos--;
//
//	}while(reintentos>=0);
//	}
//	return retorno;
//}


//int calcularNumeroInt(long numeroLong, int *numeroInt)
//{
//	int retorno =-1;
//	if(numeroLong<=MAX_INT)
//	{
//		*numeroInt= (int) numeroLong;
//		retorno=0;
//	}
//	return retorno;
//
//}
