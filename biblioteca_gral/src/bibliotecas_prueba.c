/*
 ============================================================================
 Name        : biblioteca_gral.c
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

#include "biblioteca_get.h"
#include "biblioteca_validaciones.h"
#include "biblioteca_imprimir.h"
#include "biblioteca_ordenamientos.h"
#include "biblioteca_solicitud_datos.h"

int main()
{
	struct sEmpleado aEmpleados[100];
	struct sEmpleado bEmpleado;
	int i;
	int idEmpleado=0;

	for(i=0;i<3;i++)
	{
//		getNombre(bEmpleado.nombre,
//						"Ingrese nombre del empleado. \n",
//						"NO es un nombre valido.\n",
//						2,
//						15,
//						2);
//		getNombre(bEmpleado.apellido,
//						"Ingrese apellido \n",
//						"No es un apellido valido\n",
//						2,
//						20,
//						2);
//		getDni(bEmpleado.dni,
//						"Ingrese DNI \n",
//						"No es un dni valido \n",
//						3,
//						8,
//						2);
//		getDomicilio(bEmpleado.domicilio,
//						"Ingrese su domicilio \n",
//						"NO es un domicilio valido \n",
//						2,
//						200,
//						2);
//		getTelefono(bEmpleado.telefono,
//						"Ingrese su numero de telefono con un guion \n",
//						"No es un numero de telefono valido \n",
//						9,
//						11,
//						2);

		bEmpleado.idEmpleado = idEmpleado;
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;
		aEmpleados[i] = bEmpleado;
	}

	printfEmployees(aEmpleados, 3);
}

