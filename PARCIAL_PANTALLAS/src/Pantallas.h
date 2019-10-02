/*
 * Pantallas.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"

#define STATUS_NOT_EMPTY 1
#define STATUS_EMPTY 0

struct sPantallas
{
	int idPantallas;
	int statusPantalla;
	char tipoPantalla[50];
	char nombrePantalla[50];
	long precioPantalla;
	char direccionPantalla[50];
};

int initLugarLibre(struct sArray *aArray, int cantidad);  // con control f hace un refactor.
int buscarLugarLibre(struct sArray *aArray, int cantidad);
int buscarPorId(struct sArray *aArray, int cantidad, int id);
int imprimirDatosPorId(struct sArray *aArray, int cantidad, int id);
int altaPorId(struct sArray *aArray, int cantidad,struct sArray item);
int imprimirArray(struct sArray *aArray, int cantidad);
static int generarId(void);

#endif /* PANTALLAS_H_ */
