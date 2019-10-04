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

#include "Pantallas.h"

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
int buscarLugarPublicidad(Publicidades *aArray, int cantidad);
int buscarPantallaPorIdEnPublicidad(Publicidades *aArray, int cantidad, int idPant);
int altaPublicidad(Publicidades *aArrayPub, int cantidad, Publicidades buffer,Pantallas *aArray, int cantidadPant,int index);
int imprimirDatosPantallasPorCuitPublicidades(Pantallas *aArray, int cantidad, Publicidades *aArrayAux, int cantArrayAux);
int buscarPublicidadIdPantallaPorCuit(Publicidades *aArray, int cantidad, char cuit, Publicidades *aArayAux);
#endif /* PUBLICIDAD_H_ */
