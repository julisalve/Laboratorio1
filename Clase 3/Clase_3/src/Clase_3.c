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
#include "clase3_Max_Min_Prom.h"

//int acumularNumeros(int numero, int *acumuladorNumeros);
int main(void) {
	long numeroLong;
	int numero;
	int i;
	int contadorMax=0;
	int contadorMin=0;
	int maximo;
	int minimo;
	int acumulador=0;
	float promedio;
	for(i=0; i<CANTIDAD_NUMEROS; i++)
	{
		printf("Ingrese un numero: \n");
		scanf("%ld",&numeroLong);
		while(calcularNumeroInt(numeroLong, &numero)!=0)
			{
				printf("Error, indique otro numero \n");
				scanf("%ld", &numeroLong);
			}


            calcularMaximo(numero,&maximo,&contadorMax);


            calcularMinimo(numero, &minimo,&contadorMin);




		acumulador=acumulador+numero;


	}
	if(sacarPromedio(acumulador, &promedio)==0)
	            {

	            }

    printf("El numero maximo es : %d \n",maximo);
    printf("El numero minimo es: %d \n",minimo);
    printf("El promedio es: %2.f \n",promedio);

}


