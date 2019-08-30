/*
 * clase3_Max_Min_Prom.c
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */


#include <stdio.h>
#include <stdlib.h>
#include "clase3_Max_Min_Prom.h"

int calcularNumeroInt(long numeroLong, int *numeroInt)
{
	int retorno =-1;
	if(numeroLong<=MAX_INT)
	{
		*numeroInt= (int) numeroLong;
		retorno=0;
	}
	return retorno;

}



int calcularMaximo(int numero, int *numeroMax,int *contador)
{
	int retorno=-1;
	if(*contador==0 || numero>*numeroMax)
	{
		retorno=0;
		*numeroMax=numero;
		*contador=*contador+1;
	}
	return retorno;
}



int calcularMinimo(int numero, int *numeroMin,int *contador)
{
	int retorno=-1;
	if(*contador==0 || numero<*numeroMin)
	{
		retorno=0;
		*numeroMin=numero;
		*contador=*contador+1;
	}
	return retorno;
}


int sacarPromedio(int acumulador, float *promedio)
{
    int retorno=0;
    *promedio=(float)acumulador/CANTIDAD_NUMEROS;

    return retorno;


}









