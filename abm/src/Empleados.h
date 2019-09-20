/*
 * Empleados.h
 *
 *  Created on: 17 sep. 2019
 *      Author: alumno
 */
#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define EXIT_ERROR -1
#define EXIT_SUCCESS 1
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sEmpleado
{
	int idEmpleado;
	int status;
	char nombre[50];
	char apellido[50];
	//char dni[50];
};
int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
int altaForzadaEmpleados(struct sEmpleado *aArray,int cantidad);
int initLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad);
int buscarLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad);
int buscarEmpleadoPorId(struct sEmpleado *aArray, int cantidad,int id);
int bajaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,int id);
int modificarEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado);
int altaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado);
int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);

#endif /* EMPLEADOS_H_ */
