/*
 ============================================================================
 Name        : abm.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Empleados.h"

#define QTY_EMPLEADOS 10

int main(void)
{
	struct sEmpleado aEmpleados[QTY_EMPLEADOS];
	int retorno;
	initLugarLibreEmpleado(aEmpleados, QTY_EMPLEADOS);
	altaForzadaEmpleados(aEmpleados,QTY_EMPLEADOS);
	buscarLugarLibreEmpleado(aEmpleados, QTY_EMPLEADOS);
	struct sEmpleado emp;
	strncpy(emp.apellido,"perez",49);
	strncpy(emp.nombre,"mariela",49);
	//strncpy(emp.dni,"36291716",49);  // o se puede escrbir asi struct sEmpleados unEmpleado = {5, STATUS_NOT_EMPTY_"mARIA","gOMEZ","36291716"}
	altaEmpleadoPorId(aEmpleados, QTY_EMPLEADOS, emp);

		imprimirArrayEmpleados(aEmpleados, QTY_EMPLEADOS);


//	if(buscarEmpleadoPorId(aEmpleados, QTY_EMPLEADOS, idEmpl)==0)
//	{
//
//
//	}


	return retorno;

}
