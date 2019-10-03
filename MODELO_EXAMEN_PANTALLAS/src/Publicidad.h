/*
 * Publicidad.h
 *
 *  Created on: 2 oct. 2019
 *      Author: juliana
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

typedef struct
		{
		int id;
		int status;
		int idPantalla;
		char nombreArchivo[50];
		int dias;
		char cuit [50];

		}Publicidades;

int initLugarLibrePublicidad(Publicidades *aArray, int cantidad);

#endif /* PUBLICIDAD_H_ */
