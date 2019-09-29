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

#define QTY_EMPLEADOS 1000


int main (void)
{
	int retorno;
	int opcion;
	int i=0;
	int flagOpcionUno=0;
	int id;
	int posicionIdBuscado;
	char confirmacion[3];
	char respuesta[3];
	struct sEmpleado aEmpleados[QTY_EMPLEADOS];
	struct sEmpleado bEmpleado;
	struct sEmpleado datosEmpleadoAModificar;
	int posicionEmpleadoAModificar;
	char datoAModificar;
	initLugarLibreEmpleado(aEmpleados, QTY_EMPLEADOS);
	do
	{
		//system("clear");
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
			altaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS ,bEmpleado);
			i++;
			flagOpcionUno=1;
			break;

		case 2:

			if (flagOpcionUno!=0)
			{

				printfEmployees(aEmpleados,10);
				getInt(&id,
						"Seleccione un ID para dar de baja\n",
						"NO es un ID valido",
						0,
						100,
						2);

				if(buscarEmpleadoPorId(aEmpleados, QTY_EMPLEADOS, id)!=-1)
				{
					imprimirDatosEmpleadoPorId(aEmpleados,QTY_EMPLEADOS, id);
					esSiONo(confirmacion,
							"¿Desea dar la baja si o no? \n",
							"No es una respuesta valida \n",
							2,
							4,
							2);
					if(strncmp(confirmacion,"si",4)==0)
					{
						bajaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,id);
						printf("Baja realizada con exito \n");
					}
					else
					{
						break;
					}
				}else
				{
					printf("NO hay empleados cargados en ese id");
				}

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

		case 3:

			if (flagOpcionUno!=0)
			{
				printfEmployees(aEmpleados,10);
				getInt(&id,
						"SEleccione un ID para modificar\n",
						"NO es un ID valido",
						0,
						100,
						2);
				imprimirDatosEmpleadoPorId(aEmpleados,QTY_EMPLEADOS, id);
				posicionEmpleadoAModificar=buscarEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,id);


				esSiONo(confirmacion,
						"¿Desea modificar este id? si o no? \n",
						"NO es una respuesta valida \n",
						2,
						4,
						2);
				if(strncmp(confirmacion,"si",4)==0)
				{
					modificacionEmpleadoPorIdCamposPuntuales(aEmpleados, QTY_EMPLEADOS, posicionEmpleadoAModificar);
				}
				else{
					break;
				}
				//						default:
				//							{
				//							getString(datoAModificar,
				//									"NO es un campo valido. Seleccione dato a modificar: nombre, apellido, dni \n",
				//									"NO es una opcion valida",
				//									0,
				//									11,
				//									2);
				//							break;
				//							}
				//	}

			}else
			{
				getInt(&opcion,
						"NO hay empleados cargados. Solo se puede elegir opcion 1. Elija opcion \n",
						"NO es una opcion valida\n",
						0,
						5,
						2);
			}
			break;

		case 4:

			if (flagOpcionUno!=0)
			{
				printfEmployees(aEmpleados,10);
			}
			else{
				getInt(&opcion,
						"NO hay empleados cargados. Solo se puede elegir opcion 1. Elija opcion \n",
						"NO es una opcion valida\n",
						0,
						5,
						2);
			}printf("%d",flagOpcionUno);
			break;

		}

		esSiONo(respuesta,
				"¿Desea realizar otra operacion? si o no \n",
				"NO es una respuesta valida \n",
				2,
				4,
				2);
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


