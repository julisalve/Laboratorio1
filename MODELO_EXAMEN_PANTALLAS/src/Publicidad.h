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

#include "general.h"
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

static int generarId();
int initLugarLibrePublicidad(Publicidades *aArray, int cantidad);
int buscarLugarPublicidad(Publicidades *aArray, int cantidad);
int buscarPantallaPorIdEnPublicidad(Publicidades *aArray, int cantidad, int idPant);
int altaPublicidad(Publicidades *aArrayPub, int cantidad, Publicidades buffer);
int imprimirArrayPublicidad(Publicidades *aArray, int cantidad);
int buscarPublicidadPorIdPantalla(Publicidades*aArray, int cantidad, int id);
int imprimirDatosPublicidadPorId(Publicidades *aArray, int cantidad, int id,int caso);
int modificacionPublicidadPorIdCamposPuntuales(Publicidades *aArray, int cantidad, int index, int caso);
int imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(Publicidades *aArray, int cantidad, char *item);
int buscarPublicidadPorIdYCuit(Publicidades *aArray,int cantidad,int id,char *item);
int buscarDatoStringValido(Publicidades *aArray, int cantidad, char *item, ArrayEnteros *auxArray, int cantAuxArray);
int buscarPublicidadIdPantallaPorCuit(Publicidades *aArray, int cantidad, char *cuit, Publicidades *aArayAux);
int buscarPublicidadPorCuit(Publicidades *aArray, int cantidad, char *item, Publicidades *auxPubl, int cantAux);
int imprimirPrecioPublicidad(Publicidades *auxArray, int cantAux, Pantallas *aArrayPant,int cantPant);
#endif /* PUBLICIDAD_H_ */
