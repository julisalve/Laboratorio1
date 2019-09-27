/*
 ============================================================================
 Name        : PARCIAL_PANTALLAS.c
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
#include "utn.c"
#include "Publicidad.h"
#include "Pantallas.h"
#define QTY_PANTALLAS 100
#define QTY_PUBLICIDAD 1000


int main (void)
{
	int retorno;
	int opcion;
	//int i=0;
	int flagOpcionUno=0;
	int id;
	int posicionIdBuscado;
	int posicionPantallaLibre;
	char confirmacion[3];
	char respuesta[3];
	struct sPantallas aPantalla[QTY_PANTALLAS];
	struct sPantallas bPantalla;
	struct sPantallas datosPantallaAModificar;
	int posicionPantallaAModificar;
	char datoAModificar;
	initLugarLibre(aPantalla, QTY_PANTALLAS);
	do
	{
		system("clear");
		printf("1) Alta pantalla \n");
		printf("2) Modificacion datos pantalla \n");
		printf("3) Baja de pantalla \n");
		printf("4) Alta de publicidad \n");
		printf("5) Modificar condiciones publicidad\n");
		printf("6) Cancelar publicidad\n");
		printf("7) Consultar facturacion \n");
		printf("8) Listar publicidades \n");
		printf("9) Listar pantallas \n");
		printf("10) Informes \n");
		printf("11) Salir \n");
		if(getInt(&opcion,
				"Elija una opcion \n",
				"NO es una opcion valida\n",
				0,
				11,
				2)!=0)
		{
			printf("ERROR");
		}
		switch(opcion)
		{
		case 1://ALTA PANTALLA
			posicionPantallaLibre=buscarLugarLibre(aPantalla, QTY_PANTALLAS);
			if (posicionPantallaLibre == -1)
			{
				printf("Error no hay mas lugar para pantallas\n");
				break;
			}
			if(getTipo(bPantalla.tipoPantalla,
					"Ingrese el tipo de pantalla:a) LED o b) LCD\n",
					"NO es un tipo valido \n",
					'a',
					'a',
					2)!=0)
			{
				printf("ERROR");
			}
			if(getNombre(bPantalla.nombrePantalla,
					"Ingrese el nombre \n",
					"NO es un nombre valido \n",
					2,
					16,
					2)!=0)
			{
				printf("ERROR");
			}
			if(getDireccion(bPantalla.direccionPantalla,
					"Ingrese direccion \n",
					"NO es una direccion valida \n",
					2,
					16,
					2)!=0)
			{
				printf("ERROR");
			}
			if(getFloat()(bPantalla.precioPantalla,
					"Ingrese un precio \n",
					"NO es un precio valida \n",
					0.1,
					100000.0),
					2)!=0)
			{
				printf("ERROR");
			}
			aPantalla[posicionPantallaLibre]=bPantalla;
			altaPorId(aPantalla,QTY_PANTALLAS ,bPantalla);
			//i++;
			flagOpcionUno=1;
			break;
		case 2://MODIFICAR DATOS PANTALLA

			if (flagOpcionUno==1)
			{
				imprimirArray(aPantalla,QTY_PANTALLAS);
				getInt(&id,
						"SEleccione un ID para modificar\n",
						"NO es un ID valido",
						0,
						100,
						2);
				//				imprimirDatosEmpleadoPorId(aEmpleados,QTY_EMPLEADOS, id);
				//				posicionEmpleadoAModificar=buscarEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,id);
				//
				//
				esSiONo(confirmacion,
						"¿Desea modificar este id? si o no? \n",
						"NO es una respuesta valida \n",
						2,
						4,
						2);
				//				if(strncmp(confirmacion,"si",4)==0)
				//				{
				//					modificacionEmpleadoPorIdCamposPuntuales(aEmpleados, QTY_EMPLEADOS, posicionEmpleadoAModificar);
				//				}
				//				else{
				//					break;
				//				}
				//				//						default:
				//				//							{
				//				//							getString(datoAModificar,
				//				//									"NO es un campo valido. Seleccione dato a modificar: nombre, apellido, dni \n",
				//				//									"NO es una opcion valida",
				//				//									0,
				//				//									11,
				//				//									2);
				//				//							break;
				//				//							}
				//				//	}
				//
				//			}else
				//			{
				//				getInt(&opcion,
				//						"NO hay empleados cargados. Solo se puede elegir opcion 1. Elija opcion \n",
				//						"NO es una opcion valida\n",
				//						0,
				//						5,
				//						2);
				//			}
				//			break;
				//		case 3:
				//					if (flagOpcionUno==1)
				//					{
				//
				//						imprimirArrayEmpleados(aEmpleados,10);
				//						getInt(&id,
				//								"Seleccione un ID para dar de baja\n",
				//								"NO es un ID valido",
				//								0,
				//								100,
				//								2);
				//
				//						if(buscarEmpleadoPorId(aEmpleados, QTY_EMPLEADOS, id)!=-1)
				//						{
				//							imprimirDatosEmpleadoPorId(aEmpleados,QTY_EMPLEADOS, id);
				//							esSiONo(confirmacion,
				//									"¿Desea dar la baja si o no? \n",
				//									"No es una respuesta valida \n",
				//									2,
				//									4,
				//									2);
				//							if(strncmp(confirmacion,"si",4)==0)
				//							{
				//								bajaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,id);
				//								printf("Baja realizada con exito \n");
				//							}
				//							else
				//							{
				//								break;
				//							}
				//						}else
				//						{
				//							printf("NO hay empleados cargados en ese id");
				//						}
				//
				//					}
				//					else
				//					{
				//						getInt(&opcion,
				//								"NO hay empleados cargados. Solo se puede elegir opcion 1. Elija opcion \n",
				//								"NO es una opcion valida\n",
				//								0,
				//								5,
				//								2);
				//					}
				//					break;
				//
				//		case 4:
				//
				//			if (flagOpcionUno==1)
				//			{
				//				imprimirArrayEmpleados(aEmpleados,10);
				//			}
				//			else{
				//				getInt(&opcion,
				//						"NO hay empleados cargados. Solo se puede elegir opcion 1. Elija opcion \n",
				//						"NO es una opcion valida\n",
				//						0,
				//						5,
				//						2);
				//			}printf("%d",flagOpcionUno);
				//			break;
				//
				//		}
				//
				//		esSiONo(respuesta,
				//				"¿Desea realizar otra operacion? si o no \n",
				//				"NO es una respuesta valida \n",
				//				2,
				//				4,
				//				2);
				retorno= EXIT_SUCCESS;
			}
		}while(strncmp(respuesta,"si",3)==0);//(respuesta=='s');
		return retorno;
	}
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



	//}
