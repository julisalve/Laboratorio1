/*
 ============================================================================
 Name        : Clase_2_proyecto_propio.c
 Author      : juliana
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 65535

int calcularNumeroMax(int *numeroMax, int numero);

int main(void)
{

	int respuesta=0;
	int numeroIngresado;
	int numeroMax;




	while(respuesta==0)
	{
		printf("Ingrese un numero \n");
		scanf("%d", &numeroIngresado);

		if(calcularNumeroMax(numeroIngresado, &numeroMax)==0)
		{
			printf("El resultado es %d",numeroMax);
		}
		else
		{
			printf("Error");
		}

		printf("Desea continuar cargando? 0\n");
		scanf("%d", &flag);


	}



int calcularNumeroMax(int numero, int *numeroMax)
{
	int retorno=-1;
	int contador=0;
	long numeroLong;

	if(numeroLong<=MAX_INT && (contador==0 || numeroLong>numeroMax))
	{


		retorno=0;
		numero=numeroLong;
		*numeroMax=numero;
	}
	contador++;

	return retorno;
}
