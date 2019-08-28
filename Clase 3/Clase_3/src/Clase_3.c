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
int calcularMaximo(int numero, int *numeroMax,int *contador);
int calcularMinimo(int numero, int *numeroMin,int *contador);
int acumularNumeros(int numero, int *acumuladorNumeros);
int main(void) {
	long numeroLong;
	int numero;
	int i;
	int contador=0;
	int maximo;
	int minimo;
	int acumulador=0;
	float promedio;
	for(i=0; i<CANTIDAD_NUMEROS; i++)
	{
		printf("Ingrese un numero: \n");
		scanf("%ld",&numeroLong);
		if(calcularNumeroInt(numeroLong, &numero)==0)
		{

            if(calcularMaximo(numero,&maximo,&contador)==0)
            {

            }
            if(calcularMinimo(numero, &minimo,&contador)==0)
            {

            }
            if(acumularNumeros(numero,&acumulador)==0)
            {

            }
		}

		while(calcularNumeroInt(numeroLong, &numero)!=0)
		{
			printf("Error, indique otro numero \n");
			scanf("%ld", &numeroLong);
		}


	}
    promedio=(float)acumulador/CANTIDAD_NUMEROS;
    printf("El numero maximo es : %d \n",maximo);
    printf("El numero minimo es: %d \n",minimo);
    printf("El promedio es: %2.f \n",promedio);

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

int acumularNumeros(int numero, int *acumuladorNumeros)
{
    int retorno=0
    *acumuladorNumeros=*acumuladorNumeros+numero;


}
