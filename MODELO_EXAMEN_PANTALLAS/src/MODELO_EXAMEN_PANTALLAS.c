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
	//Publicidades bPublicidad;
	Pantallas aPantalla[QTY_PANTALLAS];
	Pantallas bPantalla;
	int opcion;
	int i=0;
	char respuesta[4];
	initLugarLibrePublicidad(aPublicidad,QTY_PUBLICIDADES);
	initLugarLibrePantallas(aPantalla,QTY_PANTALLAS);
	do
	{
		system("clear");
		printf("1)ALTA PANTALLA.\n2) MODIFICACION PANTALLA\n3) BAJA PANTALLA. \n4) CONTRATAR PUBLICIDAD. \n5) MODIFICAR PUBLICIDAD.\n 6) CANCELAR PUBLICIDAD. \n7) CONSULTA FACTURACION. \n8) LISTA CONTRATACIONES.\n9) LISTAR PANTALLAS.\n10) INFORMAR:\n  a)LIsta de cada cliente con cantidad de contrataciones e importe a pagar.\n  b)Cliente con importe mas alto a facturar.\n");
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
//			if(getTipo(&bPantalla.tipo,"INgrese un tipo de pantalla a)LED, b)LCD \n","NO es un tipo valido \n",'a','z',2)!=0)
//			{
//				printf("ERROR.\n");
//				break;
//			}

			altaPantallaPorId(aPantalla,QTY_PANTALLAS,bPantalla);

			imprimirArrayPantallas(aPantalla,QTY_PANTALLAS);
			break;
		}
	}while(strncmp(respuesta,"si",4)==0);
}


