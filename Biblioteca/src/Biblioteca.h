/*
 * Biblioteca.h
 *
 *  Created on: 7 sep. 2019
 *      Author: Juliana
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#endif /* BIBLIOTECA_H_ */

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>

#define CANTIDAD_NUMEROS 5
#define MAX_INT 65535
#define EXIT_ERROR -1



int getInt(int *resultado,
		  char *mensaje,
		  char *mensajeError,//se declara como puntero el char
		  int minimo,
		  int maximo,
		  int reintentos);

float getFloat(float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos);

char getChar (char *resultadoChar,
			  char *mensajeChar,
			  char *mensajeErrorChar,
			  char minimo,
			  char maximo,
			  int reintentos);

int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

int initArrayInt(int array[],int limite,int valor );

int imprimeArrayInt(int array[],int limite );

int sumaEnteros(int primerValorSumar, int segundoValorSumar, int *resultado);

int calcularNumeroMax(int numero, int *numeroMax);

int calcularMinimo(int numero, int *numeroMin,int *contador);

int maximoArrayInt(int array[],int limite,int *pResultadoPosMax, int *pResultadoMax);

int ordenarArrayIntAscendente(int array[],int limite);

int ordenarArrayIntDescendente(int array[],int limite);

int ordenarInsertionDescendente(int array[],int limite);

int ordenarInsertionAscentende(int array[],int limite);
