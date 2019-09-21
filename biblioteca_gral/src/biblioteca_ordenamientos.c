/*
 * biblioteca_ordenamientos.c
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


int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	struct sEmpleado bEmpleados;
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,50)>0)
				{
					fSwap = 1;
					bEmpleados=aEmpleado[i];
					aEmpleado[i]=aEmpleado[i+1];
					aEmpleado[i+1]=bEmpleados;
				}
				else if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,50)==0)

				{
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,50)>0)
						{
							fSwap = 1;
							bEmpleados=aEmpleado[i];
							aEmpleado[i]=aEmpleado[i+1];
							aEmpleado[i+1]=bEmpleados;
						}
				}
			}
		}while(fSwap);
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


