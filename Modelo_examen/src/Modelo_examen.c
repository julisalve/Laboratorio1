#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantallas.h"
#include "Publicidad.h"
#include "general.h"

#define QTY_PUBLICIDADES 1000
#define QTY_PANTALLAS 100

int altaForzadaPublicidad(Publicidades *aArray,int cantidad);
int altaForzadaPantalla(Pantallas *aArray,int cantidad);

int altaForzadaPantalla(Pantallas *aArray,int cantidad)
{
	int retorno;
	int id[]={1,2,3,4,5};
	int status[]={1,1,1,1,1};
	int tipo[]={1,2,1,2,2};
	char nombre[][50]={"juan","pedro","maria","eva","abrahm"};
	char direccion[][50]={" Lavalle 209","Ayolas 3429","383 2696","pellegrini y calchaqui","12 de oct 2431"};
	float precio[]={12.3,9.7,3.2,23.6,98.43};

	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].id=id[i];
		aArray[i].status=status[i];
		aArray[i].tipo=tipo[i];
		strncpy(aArray[i].nombre,nombre[i],50);
		strncpy(aArray[i].direccion,direccion[i],50);
		aArray[i].precio= precio[i];
		retorno=0;
	}
	return retorno;
}



int altaForzadaPublicidad(Publicidades *aArray,int cantidad)
{
	int retorno;
	int id[]={10,3,4,2,9};
	int status[]={1,1,1,1,1};
	int idPantalla[]={1,2,3,4,5};
	char nombreArchivo[][50]={"juan.archivo","pedro.archivo","maria.archivo","eva.archivo","abrahm.archivo"};
	int dias[]={12,12,19,2,3};
	char cuit [][50]={"33333333333","11111111111","33333333333","33333333333","444444444444"};


	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].id=id[i];
		aArray[i].status=status[i];
		aArray[i].idPantalla=idPantalla[i];
		strncpy(aArray[i].nombreArchivo,nombreArchivo[i],50);
		aArray[i].dias= dias[i];
		strncpy(aArray[i].cuit,cuit[i],50);
		retorno=0;
	}
	return retorno;
}







int main(void) {

	Publicidades aPublicidad[QTY_PUBLICIDADES];
	Publicidades bPublicidad;
	Publicidades auxPublicidad[QTY_PUBLICIDADES];
	Pantallas aPantalla[QTY_PANTALLAS];
	Pantallas bPantalla;
	auxContador aContador[QTY_PUBLICIDADES];
	int opcion;
	int flagOpcionUno=0;
	int flagDos=0;
	ArrayEnteros aArrayEnterosId[QTY_PANTALLAS];
	int id;
	int index;
	char respuesta[4];
	char confirmacion [3];
	char cuit[50];
	initLugarLibrePublicidad(aPublicidad,QTY_PUBLICIDADES);
	initLugarLibrePantallas(aPantalla,QTY_PANTALLAS);
	do
	{
		//altaForzadaPantalla(aPantalla,QTY_PANTALLAS);
		imprimirArrayPantallas(aPantalla,QTY_PANTALLAS);
		//altaForzadaPublicidad(aPublicidad,QTY_PUBLICIDADES);
		imprimirArrayPublicidad(aPublicidad,QTY_PUBLICIDADES);




		system("clear");
		printf("1)ALTA PANTALLA.\n2)MODIFICACION PANTALLA\n3)BAJA PANTALLA. \n4)CONTRATAR PUBLICIDAD. \n5) MODIFICAR PUBLICIDAD.\n6) CANCELAR PUBLICIDAD. \n7) CONSULTA FACTURACION. \n8) LISTA CONTRATACIONES.\n9) LISTAR PANTALLAS.\n10) INFORMAR:\n  a)LIsta de cada cliente con cantidad de contrataciones e importe a pagar.\n  b)Cliente con importe mas alto a facturar.\n");
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
			flagOpcionUno=1;
			break;

		case 2:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar pantalla\n");

			}
			else
			{
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
				if(esSiONo(confirmacion,"¿Desea modificar este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					do
					{
						modificacionPantallaPorIdCamposPuntuales(aPantalla,QTY_PANTALLAS,index);
						if(esSiONo(respuesta,"¿Desea seguir modificando este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
						{
							printf("ERROR. \n");
							break;
						}

					}while(strncmp(respuesta,"si",3)==0);
					printf("MODIFICACION EXITOSA. \n");
				}}
			break;
		case 3:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar pantalla\n");

			}
			else
			{
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
				if(esSiONo(confirmacion,"¿Desea dar de baja este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{

					bajaPantallaPorId(aPantalla,QTY_PANTALLAS,aPublicidad,QTY_PUBLICIDADES,id);
					printf("BAJA EXITOSA. \n");
				}}
			break;

		case 4:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar pantalla\n");

			}
			else
			{
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
					bPublicidad.idPantalla=id;
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

					//				index=buscarPantallaPorId(aPantalla,QTY_PANTALLAS,id);
					altaPublicidad(aPublicidad, QTY_PUBLICIDADES, bPublicidad);
					imprimirArrayPublicidad(aPublicidad, QTY_PUBLICIDADES);
					flagDos=1;
				}}
			break;
		case 5:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar pantalla\n");

			}
			else if(flagDos!=1)
			{
				printf("Error, primero debe contratar una publicidad\n");
			}
			else
			{
				if(getSoloNumeros(cuit,"Ingrese numero de cuit para realizar la busqueda \n","NO es un cuit valido \n",10,17,2)!=0)
				{
					printf("ERROR.\n");
					break;
				}
				while(buscarDatoStringValido(aPublicidad,QTY_PUBLICIDADES,cuit,aArrayEnterosId, QTY_PANTALLAS)==-1)
				{
					if(getSoloNumeros(cuit,"NO es un cuit valido. Reingrese \n","NO es un cuit valido \n",10,17,2)!=0)
					{
						printf("ERROR.\n");
						break;
					}
				}

				printf("Pantalllas contratadas \n");
				imprimirDatosEstructuraPorCoincidenciaIdConOtraEtructura(aPantalla,QTY_PANTALLAS,aArrayEnterosId,QTY_PANTALLAS);
				printf("Publicidades contratadas \n");
				imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(aPublicidad,QTY_PUBLICIDADES, cuit);
//				getInt(&id,"Indique el ID de la pantalla que quiere modificar.\n","NO es un id valido\n", 1,100,2);
				while(buscarPublicidadPorIdYCuit(aPublicidad, QTY_PUBLICIDADES,id,cuit)==-1)
				{
					getInt(&id,"NO es un id valido para este cuit, reingrese\n", "NO es un id valido\n", 1,100,2);

				}

				index=buscarPublicidadPorIdPantalla(aPublicidad,QTY_PUBLICIDADES,id,cuit);
				opcion=1;
				imprimirDatosPublicidadPorId(aPublicidad, QTY_PUBLICIDADES, index,opcion);
				if(esSiONo(confirmacion,"Ha seleccionado modificar este dato ¿Continuar? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					opcion=1;
					modificacionPublicidadPorIdCamposPuntuales(aPublicidad,QTY_PUBLICIDADES,index,opcion);
				}
				printf("MODIFICACION REALIZADA CON EXITO \n");

				printf("Sus nuevas publicidades son: \n");
				imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(aPublicidad,QTY_PUBLICIDADES, cuit);
				//						imprimirArrayPublicidad(aPublicidad, QTY_PUBLICIDADES);
				//buscarPublicidadIdPantallaPorCuit(aPublicidad,QTY_PUBLICIDADES,cuit, auxPublicidad);
				//			imprimirDatosPantallasPorCuitPublicidades(aPantalla,QTY_PANTALLAS,auxPublicidad,QTY_PUBLICIDADES);
			}
			break;

		case 6:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar pantalla\n");

			}
			else if(flagDos!=1)
			{
				printf("Error, primero debe contratar una publicidad\n");
			}
			else
			{
				if(getSoloNumeros(cuit,"Ingrese numero de cuit para realizar la busqueda \n","NO es un cuit valido \n",10,17,2)!=0)
				{
					printf("ERROR.\n");
					break;
				}
				while(buscarDatoStringValido(aPublicidad,QTY_PUBLICIDADES,cuit,aArrayEnterosId, QTY_PANTALLAS)==-1)
				{
					if(getSoloNumeros(cuit,"NO es un cuit valido. Reingrese \n","NO es un cuit valido \n",10,17,2)!=0)
					{
						printf("ERROR.\n");
						break;
					}
				}

				printf("Pantallas contratadas\n");
				imprimirDatosEstructuraPorCoincidenciaIdConOtraEtructura(aPantalla,QTY_PANTALLAS,aArrayEnterosId,QTY_PANTALLAS);
				printf("Publicidades contratadas \n");
				imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(aPublicidad,QTY_PUBLICIDADES, cuit);
				getInt(&id,"Indique la publicacion que quiere dar de baja eligiendo el ID de la pantalla .\n","NO es un id valido\n", 1,100,2);
				while(buscarPublicidadPorIdYCuit(aPublicidad, QTY_PUBLICIDADES,id,cuit)==-1)
				{
					getInt(&id,"NO es un id valido para este cuit, reingrese\n", "NO es un id valido\n", 1,100,2);

				}

				index=buscarPublicidadPorIdPantalla(aPublicidad,QTY_PUBLICIDADES,id,cuit);

				opcion=2;
				imprimirDatosPublicidadPorId(aPublicidad, QTY_PUBLICIDADES, index,opcion);
				if(esSiONo(confirmacion,"Ha seleccionado dar de baja esta publicacion ¿Continuar? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					opcion=2;
					modificacionPublicidadPorIdCamposPuntuales(aPublicidad,QTY_PUBLICIDADES,index,opcion);
					printf("BAJA REALIZADA CON EXITO \n");
					printf("Sus nuevas publicidades son: \n");
									imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(aPublicidad,QTY_PUBLICIDADES, cuit);
				}

			}break;

		case 7:
			if(getSoloNumeros(cuit,"Ingrese numero de cuit para realizar la busqueda \n","NO es un cuit valido \n",10,17,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			while(buscarDatoStringValido(aPublicidad,QTY_PUBLICIDADES,cuit,aArrayEnterosId, QTY_PANTALLAS)==-1)
			{
				if(getSoloNumeros(cuit,"NO es un cuit valido. Reingrese \n","NO es un cuit valido \n",10,17,2)!=0)
				{
					printf("ERROR.\n");
					break;
				}
			}
			buscarPublicidadPorCuit(aPublicidad,QTY_PUBLICIDADES,cuit,auxPublicidad,QTY_PUBLICIDADES);

			imprimirPrecioPublicidad(auxPublicidad,QTY_PUBLICIDADES,aPantalla,QTY_PANTALLAS);
			break;

		case 8:
			imprimirArrayPublicidad(aPublicidad, QTY_PUBLICIDADES);
			break;
		case 9:
			printf("Las pantallas existentes son:");
			imprimirArrayPantallas(aPantalla,QTY_PANTALLAS);
			break;

		case 10:
			printf("  1)");
			ordenarCuit (aPublicidad,QTY_PUBLICIDADES);
			//			imprimirArrayPublicidad(aPublicidad,QTY_PUBLICIDADES);
			cantidadPublicacionesPorCuit(aPublicidad,QTY_PUBLICIDADES, aContador,QTY_PUBLICIDADES);

			printf("  2)");
			calcularPrecioPublicidadCompleto(aPublicidad,QTY_PUBLICIDADES,aPantalla,QTY_PANTALLAS);
			imprimirArrayPublicidad(aPublicidad,QTY_PUBLICIDADES);
			buscarImporteMasAltoDeFacturacion(aPublicidad,QTY_PUBLICIDADES);
			//ePantalla_cantidadFacturada (aPantalla,QTY_PANTALLAS, aPublicidad,QTY_PUBLICIDADES, char *cuit)

			break;





		}

		if(esSiONo(respuesta,"¿Desea seguir haciendo otra operacion? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
		{
			printf("ERROR. \n");
			break;
		}


	}while(strncmp(respuesta,"si",4)==0);
}
