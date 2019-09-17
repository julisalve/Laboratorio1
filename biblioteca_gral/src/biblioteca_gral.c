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
#include"biblioteca_general.h"



int main()
{
	struct sEmpleado aEmpleados[100];
	struct sEmpleado bEmpleado;
	int i;
	int idEmpleado=0;

	for(i=0;i<3;i++)
	{
		getNombre(bEmpleado.nombre,
						"Ingrese nombre del empleado. \n",
						"NO es un nombre valido.\n",
						2,
						15,
						2);
		getNombre(bEmpleado.apellido,
						"Ingrese apellido \n",
						"No es un apellido valido\n",
						2,
						20,
						2);
		getDni(bEmpleado.dni,
						"Ingrese DNI \n",
						"No es un dni valido \n",
						3,
						8,
						2);
		getDomicilio(bEmpleado.domicilio,
						"Ingrese su domicilio",
						"NO es un domicilio valido",
						2,
						200,
						2);

		getTelefono(bEmpleado.telefono,
						"Ingrese su numero de telefono con un guion",
						"No es un numero de telefono valido",
						9,
						11,
						2);

		bEmpleado.idEmpleado = idEmpleado;
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;
		aEmpleados[i] = bEmpleado;
	}

	imprimirArrayEmpleados(aEmpleados, 3);
}

