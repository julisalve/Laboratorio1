/*
 ============================================================================
 Name        : Clase_3.c
 Author      : juliana
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 5
#define MAX_INT 65535

int calcularNumeroInt(long numeroLong, int *numeroInt);

int main(void) {
	long numeroLong;
	int numero;
	int i;
	int contador=0;
	int Maximo;
	for(i=0; i<5; i++)
	{
		printf("Ingrese un numero: \n");
		scanf("%ld",&numeroLong);
		if(calcularNumeroInt(numeroLong, &numero)==0)
		{

		}
		while(calcularNumeroInt(numeroLong, &numero)!=0)
		{
			printf("Error, indique otro numero");
			scanf("%ld", &numeroLong);
		}
		if(calcularMaximo(numero, *Maximo,int *contador))

	}


}


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
		*contador++;
	}
	return retorno;
}
