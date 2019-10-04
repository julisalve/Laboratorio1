/*
 ============================================================================
 Name        : MODELO_EXAMEN_PANTALLAS.c
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
#include "Pantallas.h"
#include "Publicidad.h"
#include "general.h"

#define QTY_PUBLICIDADES 1000
#define QTY_PANTALLAS 100



int main(void) {

	Publicidades aPublicidad[QTY_PUBLICIDADES];
	Publicidades bPublicidad;
	Publicidades auxPublicidad[QTY_PUBLICIDADES];
	Pantallas aPantalla[QTY_PANTALLAS];
	Pantallas bPantalla;
	int opcion;
	//int i=0;
	int id;
	int index;
	char respuesta[4];
	char confirmacion [3];
	char cuit[50];
	initLugarLibrePublicidad(aPublicidad,QTY_PUBLICIDADES);
	initLugarLibrePantallas(aPantalla,QTY_PANTALLAS);
	do
	{
		system("clear");
		printf("1)ALTA PANTALLA.\n2)MODIFICACION PANTALLA\n3)BAJA PANTALLA. \n4)CONTRATAR PUBLICIDAD. \n5) MODIFICAR PUBLICIDAD.\n 6) CANCELAR PUBLICIDAD. \n7) CONSULTA FACTURACION. \n8) LISTA CONTRATACIONES.\n9) LISTAR PANTALLAS.\n10) INFORMAR:\n  a)LIsta de cada cliente con cantidad de contrataciones e importe a pagar.\n  b)Cliente con importe mas alto a facturar.\n");
		if(getInt(&opcion, "Ingrese una opcion del menu \n", "NO es una opcion valida \n",1,10,3)!=0)
		{
			printf("ERROR.\n ");
			break;
		}
		switch(opcion)
		{
		case 1:
			if(buscarLugarPantalla(aPantalla,QTY_PANTALLAS)==-1)
			{
				printf("NO hay lugar libre.\n");
				break;
			}
			if(getDatoSoloLetras(bPantalla.nombre,"Ingrese un nombre\n","NO es un nombre valido\n",1,100,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			if(getDatoAlfaNumerico(bPantalla.direccion,"Indique la direccion\n","NO es una direccion valida \n",1,100,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			if(getFloat(&bPantalla.precio,"Ingrese precio \n","NO es un precio valido \n",0.01,1000000.0,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			if(getInt(&bPantalla.tipo,"INgrese un tipo de pantalla 1)LED, 2)LCD \n","NO es un tipo valido \n",1,2,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			bPantalla.status=STATUS_NOT_EMPTY;
			altaPantallaPorId(aPantalla,QTY_PANTALLAS,bPantalla);
			break;

		case 2:
			imprimirArrayPantallas(aPantalla,QTY_PANTALLAS);
			if(getInt(&id,"Indique el id que desea modificar\n", "NO es un id valido\n", 1,100,2)!=0)
			{
				printf("ERROR. \n");
				break;
			}

			while(buscarPantallaPorId(aPantalla, QTY_PANTALLAS,id)==-1)
			{
				getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

			}
			imprimirDatosPantallaPorId(aPantalla,QTY_PANTALLAS,id);
			index=buscarPantallaPorId(aPantalla, QTY_PANTALLAS,id);
			if(esSiONo(confirmacion,"¿Desea modificar este id?\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
				printf("ERROR. \n");
				break;
				}
			if(strncmp(confirmacion,"si",3)==0)
			{
				do
				{
					modificacionPantallaPorIdCamposPuntuales(aPantalla,QTY_PANTALLAS,index);
					if(esSiONo(respuesta,"¿Desea seguir modificando este id?\n","No es una respuesta valida. \n",2,3,2)!=0)
									{
									printf("ERROR. \n");
									break;
									}

				}while(strncmp(respuesta,"si",3)==0);
				printf("MODIFICACION EXITOSA. \n");
			}
			break;
		case 3:
			imprimirArrayPantallas(aPantalla,QTY_PANTALLAS);
						if(getInt(&id,"Indique el id que desea dar de baja\n", "NO es un id valido\n", 1,100,2)!=0)
						{
							printf("ERROR. \n");
							break;
						}

						while(buscarPantallaPorId(aPantalla, QTY_PANTALLAS,id)==-1)
						{
							getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

						}
						imprimirDatosPantallaPorId(aPantalla,QTY_PANTALLAS,id);
						if(esSiONo(confirmacion,"¿Desea dar de baja este id?\n","No es una respuesta valida. \n",2,3,2)!=0)
							{
							printf("ERROR. \n");
							break;
							}
						if(strncmp(confirmacion,"si",3)==0)
						{

								bajaPantallaPorId(aPantalla,QTY_PANTALLAS,aPublicidad,QTY_PUBLICIDADES,id);
								printf("BAJA EXITOSA. \n");
			}
						break;

		case 4:
			if(buscarLugarPublicidad(aPublicidad,QTY_PUBLICIDADES)==-1)
			{
				printf("NO hay lugar libre.\n");
				break;
			}
			imprimirArrayPantallas(aPantalla,QTY_PANTALLAS);
			getInt(&id,"Indique el ID de la pantalla en la cual quiere publicitar.\n","NO es un id valido\n", 1,100,2);
			while(buscarPantallaPorId(aPantalla, QTY_PANTALLAS,id)==-1)
			{
				getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

			}
			imprimirDatosPantallaPorId(aPantalla,QTY_PANTALLAS,id);
			if(esSiONo(confirmacion,"Ha seleccionado esta pantalla para poner una publicidad¿COntinuar? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
			{
				printf("ERROR. \n");
				break;
			}
			if(strncmp(confirmacion,"si",3)==0)
			{
				if(getSoloNumeros(bPublicidad.cuit,"INgrese numero de cuit \n","NO es un cuit valido \n",10,17,2)!=0)
				{
						printf("ERROR.\n");
							break;
				}

				if(getInt(&bPublicidad.dias,"Indique cantidad de dias\n","NO es un numero valido \n",1,100000,2)!=0)
											{
												printf("ERROR.\n");
												break;
											}
				if(getDatoAlfaNumerico(bPublicidad.nombreArchivo,"Indique nombre del archivo\n","NO es un nombre valido \n",1,100,2)!=0)
							{
								printf("ERROR.\n");
								break;
							}

				index=buscarPantallaPorId(aPantalla,QTY_PANTALLAS,id);
				altaPublicidad(aPublicidad, QTY_PUBLICIDADES, bPublicidad, aPantalla, QTY_PUBLICIDADES,index);

			}
break;
		case 5:

			if(getSoloNumeros(cuit,"Ingrese numero de cuit para realizar la busqueda \n","NO es un cuit valido \n",10,17,2)!=0)
							{
									printf("ERROR.\n");
										break;
							}
			buscarPublicidadIdPantallaPorCuit(aPublicidad,QTY_PUBLICIDADES,cuit, auxPublicidad);
			imprimirDatosPantallasPorCuitPublicidades(aPantalla,QTY_PANTALLAS,auxPublicidad,QTY_PUBLICIDADES);






		}

		if(esSiONo(respuesta,"¿Desea seguir haciendo otra operacion?\n","No es una respuesta valida. \n",2,3,2)!=0)
														{
														printf("ERROR. \n");
														break;
														}


	}while(strncmp(respuesta,"si",4)==0);
}


