/*
 * Modelo_parcial.h
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */

#ifndef MODELO_PARCIAL_H_
#define MODELO_PARCIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sPantalla
{
	int idPantalla;
	int statusPantalla;
	char tipoPantalla[4];
	char nombrePantalla[50];
	char direccionPantalla[50];
	char precioPantalla[50];
};


struct sContrato
{
	int idContrato;
	int statusContrato;
	int idPantalla;
	char idClienteCuit[14];
	char diasContrato[10];
	char archivo[50];

};

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad);
int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad);
int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla);

#endif /* MODELO_PARCIAL_H_ */
