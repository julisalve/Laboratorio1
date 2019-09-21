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

int main (void)
{
	int retorno;
	int opcion;
	char respuesta[3];
	struct sEmpleado aEmpleados[QTY_EMPLEADOS];

//	system("clear");
	do
	{


	printf("Elija una opción \n");
	printf("1) Alta \n");
	printf("2) Baja \n");
	printf("3) Modificacion de datos \n");
	printf("4) Informes \n");
//	switch(opcion)
//	{
//	case 1:
//
//
//	}


	esSiONo(respuesta,
			"¿Desea seguir cargando datos? s/n \n",
				  "NO es una respuesta valida \n",
				  2,
				  4,
				  3);
		retorno= EXIT_SUCCESS;
	}while(strncmp(respuesta,"si",3)==0);//(respuesta=='s');
	return retorno;
}


//int main(void)
//{
//	struct sEmpleado aEmpleados[QTY_EMPLEADOS];
//	int retorno;
//	initLugarLibreEmpleado(aEmpleados, QTY_EMPLEADOS);
//	altaForzadaEmpleados(aEmpleados,QTY_EMPLEADOS);
//	buscarLugarLibreEmpleado(aEmpleados, QTY_EMPLEADOS);
//	struct sEmpleado emp;
//	strncpy(emp.apellido,"perez",49);
//	strncpy(emp.nombre,"mariela",49);
//	//strncpy(emp.dni,"36291716",49);  // o se puede escrbir asi struct sEmpleados unEmpleado = {5, STATUS_NOT_EMPTY_"mARIA","gOMEZ","36291716"}
//	altaEmpleadoPorId(aEmpleados, QTY_EMPLEADOS, emp);
//
//		imprimirArrayEmpleados(aEmpleados, QTY_EMPLEADOS);
//
//
////	if(buscarEmpleadoPorId(aEmpleados, QTY_EMPLEADOS, idEmpl)==0)
////	{
////
////
////	}
//
//
//	return retorno;
//
//}
