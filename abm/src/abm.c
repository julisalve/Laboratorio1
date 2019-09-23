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
	int i=0;
	int flagOpcionUno=0;
	char respuesta[3];
	struct sEmpleado aEmpleados[QTY_EMPLEADOS];
	struct sEmpleado bEmpleado;

	initLugarLibreEmpleado(aEmpleados, QTY_EMPLEADOS);


	do
	{
		printf("1) Alta \n");
		printf("2) Baja \n");
		printf("3) Modificacion de datos \n");
		printf("4) Informes \n");
		printf("5) Salir \n");
		getInt(&opcion,
			  "Elija una opcion \n",
			  "NO es una opcion valida\n",
			  0,
			  5,
			  2);


	switch(opcion)
	{
	case 1:
		{
			getNombre(bEmpleado.nombre,
							"Ingrese el nombre \n",
							"NO es un nombre valido \n",
							2,
							16,
							2);

			getNombre(bEmpleado.apellido,
						"Ingrese apellido \n",
						"NO es un apellido valido \n",
						2,
						16,
						2);
			getDni(bEmpleado.dni,
							"Ingrese dni \n",
							"NO es un dni valido \n",
							2,
							16,
							2);
			aEmpleados[i]=bEmpleado;
			aEmpleados[i].status=STATUS_NOT_EMPTY;
			//altaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS ,bEmpleado);
			imprimirArrayEmpleados(aEmpleados,10);
			i++;
			flagOpcionUno=1;


			break;
		}

	case 2:
	{
		if (flagOpcionUno==1)
		{

		}
		else
		{
			getInt(&opcion,
						  "NO hay empleados cargados. Solo se puede elegir opcion 1. Elija opcion \n",
						  "NO es una opcion valida\n",
						  0,
						  5,
						  2);
		}
		break;
	}
	case 3:
		{
			if (flagOpcionUno==1)
			{

			}
			else
			{
				getInt(&opcion,
							  "NO hay empleados cargados. Solo se puede elegir opcion 1. Elija opcion \n",
							  "NO es una opcion valida\n",
							  0,
							  5,
							  2);
			}
			break;
		}


//	default:
//	{
//		getInt(&opcion,
//				 "NO es una opcion valida.Reingrese opcion \n",
//				 "NO es una opcion valida.Reingrese opcion \n",
//				 0,
//				 5,
//				 2);
//	}

	}


//	esSiONo(respuesta,
//			"¿Desea seguir cargando datos? si o no \n",
//			"NO es una respuesta valida \n",
//				  2,
//				  4,
//				  2);
//		retorno= EXIT_SUCCESS;
//	}while(strncmp(respuesta,"si",3)==0);//(respuesta=='s');

}while(opcion!=5);
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


