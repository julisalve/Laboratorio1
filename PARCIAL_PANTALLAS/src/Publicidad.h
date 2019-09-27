/*
 * Publicidad.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define STATUS_NOT_EMPTY 1
#define STATUS_EMPTY 0




struct sPublicidad
{
	int idPublicidad;
	int statusPublicidad;
	int idPantalla;
	char cuit[50];
	int dias;
	char nombreArchivo[50];
};

#endif /* PUBLICIDAD_H_ */
