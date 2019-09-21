/*
 * biblioteca_validaciones.h
 *
 *  Created on: 21 sep. 2019
 *      Author: juliana
 */

#ifndef BIBLIOTECA_VALIDACIONES_H_
#define BIBLIOTECA_VALIDACIONES_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

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

#endif /* BIBLIOTECA_VALIDACIONES_H_ */
