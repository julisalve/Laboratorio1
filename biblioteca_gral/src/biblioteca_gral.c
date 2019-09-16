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

		getDni(bEmpleado.dni,
						"Ingrese DNI \n",
						"No es un dni valido \n",
						3,
						8,
						2);

		bEmpleado.idEmpleado = idEmpleado;
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;
		aEmpleados[i] = bEmpleado;
	}

	imprimirArrayEmpleados(aEmpleados, 3);
}

