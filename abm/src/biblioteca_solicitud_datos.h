/*
 * biblioteca_solicitud_datos.h
 *
 *  Created on: 21 sep. 2019
 *      Author: juliana
 */

#ifndef BIBLIOTECA_SOLICITUD_DATOS_H_
#define BIBLIOTECA_SOLICITUD_DATOS_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define CANTIDAD_NUMEROS 5
#define MAX_INT 65535
#define EXIT_ERROR -1
//#define
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

//struct sEmpleado
//{
//	int idEmpleado;
//	int status;
//	//***************
//	char nombre[50];
//	char apellido[50];
//	char domicilio[50];
//	char codigoPostal[50];
//	char dni[50];
//	char cuil[50];
//	char telefono[50];
//	char fechaNacimiento[50];
//	char correoElectronico[50];
//	long sueldo;
//};


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


#endif /* BIBLIOTECA_SOLICITUD_DATOS_H_ */
