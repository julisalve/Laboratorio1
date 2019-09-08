/*
 * prueba_biblioteca.c
 *
 *  Created on: 7 sep. 2019
 *      Author: Juliana
 */

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include "Biblioteca.h"

#define CANT_ARRAY 11
#define CANT_NUMEROS 3

int main()
{
	//int resultado;
//	float resultadoFloat;
//	char resultadoChar;
	int array[CANT_ARRAY];
	int datosIngresadosAlArray;
	//int legajos;
	//int valor=1;
	//int arrayLegajos[valor];
//	int resultadoSuma;
//	int primerValor;
//	int segundoValor;
	//int numero;
	//int i;
	//int buffer;
	int numeroMaxArray;
	int posNumeroMaxArray;
	//int numeroMin;
//	getInt(&primerValor,
//			  "Ingrese un numero \n",
//			  "no es un numero \n",//se declara como puntero el char
//			  0,
//			  10,
//			  2);
//
//		printf("el numero ingresado es %d \n",primerValor);
//		system("pause");
//
//	getInt(&segundoValor,
//				  "Ingrese un numero \n",
//				  "no es un numero \n",//se declara como puntero el char
//				  0,
//				  10,
//				  2);
//
//	printf("el numero ingresado es %d \n",segundoValor);
//	system("pause");
//
//	if(sumaEnteros(primerValor, segundoValor, &resultadoSuma)==0)
//	{
//		printf("la suma es %d \n",resultadoSuma);
//		system("pause");
//	}
//
//		if(getFloat(&resultadoFloat,
//						"Ingrese un numero decimal\n",
//						"No es un numero valido\n",
//						0.01,
//						0.99,
//						2)==0)
//	{
//		printf("el numero ingresado es %.2f \n",resultadoFloat);
//		system("pause");
//	}
//
//	if(getChar(&resultadoChar,
//				  "Ingrese una letra \n",
//				  "No es una letra valida \n",
//				  'b',
//				  'y',
//				  1)==1)
//	{
//		printf("La letra ingresada es %c \n",resultadoChar);
//		system("pause");
//	}

	datosIngresadosAlArray=	getArrayInt(array,
					CANT_ARRAY,
					"Ingrese un entero \n",
					"No es un entero valido \n" ,
						0,
						100,
						2);
	if(datosIngresadosAlArray>0)
	{
		imprimeArrayInt(array, datosIngresadosAlArray);

	}

//	legajos = initArrayInt(array,CANT_ARRAY,valor);
//
//	if(legajos==0)
//	{
//		imprimeArrayInt(array, datosIngresadosAlArray);
//
//	}

//	for(i=0;i<CANT_NUMEROS;i++)
//	{
//		getInt(&numero,"Ingrese un numero \n","No es un numero valido \n",0,100,2);
//		buffer=numero;
//		calcularNumeroMax(buffer, &numeroMax);
//		//calcularMinimo(buffer,&numeroMin,&contador);
//	}
//	printf("El numero maximo es %d \n",numeroMax);
//	system("pause");

	maximoArrayInt(array,datosIngresadosAlArray,&posNumeroMaxArray, &numeroMaxArray);
	printf("El numero maximo es %d \n",numeroMaxArray);
	printf("La posicion max es %d \n",posNumeroMaxArray);
	system("pause");

//	if(ordenarArrayIntAscendente(array,datosIngresadosAlArray)==0)
//	{
//		imprimeArrayInt(array, datosIngresadosAlArray);
//	}
//
//	if(ordenarArrayIntDescendente(array,datosIngresadosAlArray)==0)
//	{
//		imprimeArrayInt(array, datosIngresadosAlArray);
//	}

	if(ordenarInsertionDescendente(array,datosIngresadosAlArray)==0)
	{
		imprimeArrayInt(array, datosIngresadosAlArray);
	}

//	if(ordenarInsertionAscentende(array,datosIngresadosAlArray)==0)
//	{
//		imprimeArrayInt(array, datosIngresadosAlArray);
//	}
}

