/*
 * Pantallas.h
 *
 *  Created on: 2 oct. 2019
 *      Author: juliana
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

//#include "Publicidad.h"
#include "general.h"

typedef struct
		{
		int id;
		int status;
		int tipo;
		char nombre[50];
		char direccion[50];
		float precio;

		}Pantallas;

static int generarId();
int initLugarLibrePantallas(Pantallas *aArray, int cantidad);
int buscarLugarPantalla(Pantallas *aArray, int cantidad);
int altaPantallaPorId(Pantallas *aArray, int cantidad,Pantallas buffer);
int imprimirArrayPantallas(Pantallas *aArray, int cantidad);
int buscarPantallaPorId(Pantallas *aArray, int cantidad, int id);
int imprimirDatosPantallaPorId(Pantallas *aArray, int cantidad, int id);
int modificacionPantallaPorIdCamposPuntuales(Pantallas *aArray, int cantidad, int index);
int imprimirDatosEstructuraPorCoincidenciaIdConOtraEtructura(Pantallas *aArray, int cantidad,ArrayEnteros *auxArray, int cantAuxArray);
//int bajaPantallaPorId(Pantallas *aArray, int cantidad,Publicidades *aArrayPub, int cantPub, int id);
#endif /* PANTALLAS_H_ */
