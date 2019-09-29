/*
 * utn.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


#define MAX_INT 65535
#define EXIT_ERROR -1
#define CANTIDAD_NUMEROS 5
#define MAX_INT 65535

struct sArray
{
	int id;
	int status;
	char tipo[50];
	char nombre[50];
	long precio;
	char direccion[50];
};


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

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

#define EXIT_ERROR -1

int isNumber(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos);

int esLetra(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int esAlfaNumerico(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int esTelefono(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int esSiONo(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getTipo(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);


int getNombre(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

int getDni(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

int getDomicilio(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

int getTelefono(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

int initLugarLibre(struct sArray *aArray, int cantidad);

#endif /* UTN_H_ */
