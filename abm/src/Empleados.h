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
#include "biblioteca_validaciones.h"
#include "biblioteca_get.h"
#include "biblioteca_solicitud_datos.h"

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sEmpleado
{
	int idEmpleado;
	int status;
	char nombre[50];
	char apellido[50];
	char dni[50];
};


static int generarId(void);
int initLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad);
int buscarLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad);
int buscarEmpleadoPorId(struct sEmpleado *aArray, int cantidad,int id);
int imprimirDatosEmpleadoPorId(struct sEmpleado *aArray, int cantidad, int id);
int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int bajaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,int id);
int modificarEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado);
int modificacionEmpleadoPorIdCamposPuntuales(struct sEmpleado *aArray, int cantidad, struct sEmpleado empleadoNuevo);
int altaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado);

int altaForzadaEmpleados(struct sEmpleado *aArray,int cantidad);
int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);



#endif /* EMPLEADOS_H_ */
