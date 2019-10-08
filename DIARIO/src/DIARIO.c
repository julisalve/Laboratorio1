#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Avisos.h"
#include "Clientes.h"
#include "general.h"

#define QTY_AVISOS 1000
#define QTY_CLIENTES 100



int altaForzadaClientes(Clientes *aArray,int cantidad)
{
	int retorno;
	int id[]={1,2,3,4,5};
	int status[]={1,1,1,1,1};
//	int tipo[]={1,2,1,2,2};
	char nombre[][50]={"juan","pedro","maria","eva","abrahm"};
	char apellido[][50]={" Lavalle","Ayolas","af","calchaqui","eoct"};
//	float precio[]={12.3,9.7,3.2,23.6,98.43};

	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].id=id[i];
		aArray[i].status=status[i];
		//aArray[i].tipo=tipo[i];
		strncpy(aArray[i].nombre,nombre[i],50);
		strncpy(aArray[i].apellido,apellido[i],50);
		//aArray[i].precio= precio[i];
		retorno=0;
	}
	return retorno;
}



int altaForzadaAvisos(Avisos *aArray,int cantidad)
{
	int retorno;
	int id[]={10,3,4,2,9};
	int status[]={1,0,1,2,2};
	int idCliente[]={1,2,3,4,5};
	char texto[][50]={"juan.archivo","pedro.archivo","maria.archivo","eva.archivo","abrahm.archivo"};
	int rubro[]={2,1,3,2,3};
	//char cuit [][50]={"33333333333","11111111111","33333333333","33333333333","444444444444"};


	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].id=id[i];
		aArray[i].status=status[i];
		aArray[i].idCliente=idCliente[i];
		strncpy(aArray[i].texto,texto[i],50);
		aArray[i].rubro= rubro[i];
//		strncpy(aArray[i].cuit,cuit[i],50);
		retorno=0;
	}
	return retorno;
}







int main(void) {

	Avisos aAviso[QTY_AVISOS];
	Avisos bAviso;
	//Avisos auxPublicidad[QTY_AVISOS];
	Clientes aClientes[QTY_CLIENTES];
	Clientes bCliente;
	auxContador aContador[QTY_AVISOS];
	int opcion;
	int flagOpcionUno=0;
	int flagDos=0;
	//ArrayEnteros aArrayEnterosId[QTY_CLIENTES];
	int id;
	int idCliente;
	int index;
	char respuesta[4];
	char confirmacion [3];
	//char cuit[50];
	int idAviso;
	initLugarLibreAvisos(aAviso,QTY_AVISOS);
	initLugarLibreClientes(aClientes,QTY_CLIENTES);
	do
	{
		altaForzadaClientes(aClientes,QTY_CLIENTES);
		imprimirArrayClientes(aClientes,QTY_CLIENTES);
		altaForzadaAvisos(aAviso,QTY_AVISOS);
		imprimirArrayAvisos(aAviso,QTY_AVISOS);




		system("clear");
		printf("1)ALTA CLIENTE.\n2)MODIFICACION CLIENTE\n3)BAJA CLIENTE. \n4)ALTA AVISO. \n5)PAUSAR AVISO.\n6)REABRIR AVISO. \n7)IMPRIMIR CLIENTES\n8)IMPRIMIR AVISOS\n9)INFORMAR CLIENTES\n   a)Cliente con mas avisos activos.\n   b)Cliente con mas avisos pausados.\n   c)Cliente con mas avisos\n10)INFORMAR AVISOS:\n  a)Cantidad de avisos por rubro.\n  b)Rubro con mas avisos activos\n   c)Rubro con menos avisos activos");
		if(getInt(&opcion, "Ingrese una opcion del menu \n", "NO es una opcion valida \n",1,10,3)!=0)
		{
			printf("ERROR.\n ");
			break;
		}
		switch(opcion)
		{
		case 1:
			if(buscarLugarCliente(aClientes,QTY_CLIENTES)==-1)
			{
				printf("NO hay lugar libre.\n");
				break;
			}
			if(getDatoSoloLetras(bCliente.nombre,"Ingrese un nombre\n","NO es un nombre valido\n",1,100,2)!=0)
			{
				printf("ERROR.\n");
				break;
			}
			if(getDatoSoloLetras(bCliente.apellido,"Ingrese un apellido\n","NO es un apellido valido\n",1,100,2)!=0)
						{
							printf("ERROR.\n");
							break;
						}
			if(getSoloNumeros(bCliente.cuit,"INgrese numero de cuit \n","NO es un cuit valido \n",10,17,2)!=0)
								{
									printf("ERROR.\n");
									break;
								}

			bCliente.status=STATUS_NOT_EMPTY;
			altaClientePorId(aClientes,QTY_CLIENTES,bCliente);
			flagOpcionUno=1;
			break;

		case 2:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar cliente\n");

			}
			else
			{
				imprimirArrayClientes(aClientes,QTY_CLIENTES);
				if(getInt(&id,"Indique el id que desea modificar\n", "NO es un id valido\n", 1,100,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}

				while(buscarClientePorId(aClientes, QTY_CLIENTES,id)==-1)
				{
					getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

				}
				imprimirDatosClientePorId(aClientes,QTY_CLIENTES,id);
				index=buscarClientePorId(aClientes, QTY_CLIENTES,id);
				if(esSiONo(confirmacion,"¿Desea modificar este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					do
					{
						modificacionClientePorIdCamposPuntuales(aClientes,QTY_CLIENTES,index);
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
				imprimirArrayClientes(aClientes,QTY_CLIENTES);
				if(getInt(&id,"Indique el id que desea dar de baja\n", "NO es un id valido\n", 1,100,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}

				while(buscarClientePorId(aClientes, QTY_CLIENTES,id)==-1)
				{
					getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

				}
				imprimirDatosClientePorId(aClientes,QTY_CLIENTES,id);
				if(esSiONo(confirmacion,"¿Desea dar de baja este id? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{

					bajaClientePorId(aClientes,QTY_CLIENTES,aAviso,QTY_AVISOS,id);
					printf("BAJA EXITOSA. \n");
				}}
			break;

		case 4:
			if(flagOpcionUno!=1)
			{
				printf("Error, primero debe cargar cliente\n");

			}
			else
			{
				if(buscarLugarAviso(aAviso,QTY_AVISOS)==-1)
				{
					printf("NO hay lugar libre.\n");
					break;
				}
				imprimirArrayClientes(aClientes,QTY_CLIENTES);
				getInt(&id,"Indique el ID del cliente para contratar aviso.\n","NO es un id valido\n", 1,100,2);
				while(buscarClientePorId(aClientes, QTY_CLIENTES,id)==-1)
				{
					getInt(&id,"NO es un id valido, reingrese\n", "NO es un id valido\n", 1,100,2);

				}
				imprimirDatosClientePorId(aClientes,QTY_CLIENTES,id);
				if(esSiONo(confirmacion,"Ha seleccionado este cliente para dar de alta un aviso ¿Continuar? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					bAviso.idCliente=id;

								if(getInt(&bAviso.rubro,"INgrese un rubro 1)clasificados 2)hogar , 3) construccion 4) varios\n","NO es un tipo valido \n",1,4,2)!=0)
								{
									printf("ERROR.\n");
									break;
								}



					if(getString(bAviso.texto,"Indique texto a ingresar\n","NO es un texto valido valido \n",1,64,2)!=0)
					{
						printf("ERROR.\n");
						break;
					}

					//				index=buscarPantallaPorId(aPantalla,QTY_CLIENTES,id);
					altaAviso(aAviso, QTY_AVISOS, bAviso);
					imprimirArrayAvisos(aAviso, QTY_AVISOS);
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
				imprimirArrayAvisos(aAviso,QTY_AVISOS);
				if(getInt(&idAviso,"Ingrese id aviso para realizar la busqueda \n","NO es un id valido \n",1,1000,2)!=0)
				{
					printf("ERROR.\n");
					break;
				}
				index=buscarAvisoPorId(aAviso,QTY_AVISOS,idAviso);
				while(index==-1)
				{
					if(getInt(&idAviso,"NO es un id valido. Reingrese \n","NO es un id valido \n",10,17,2)!=0)
					{
						printf("ERROR.\n");
						break;
					}
				}
				idCliente=aAviso[index].idCliente;
				printf("Cliente: \n");
				imprimirDatosClientePorId(aClientes,QTY_CLIENTES,idCliente);
				printf("Aviso \n");
//				printf("id aviso %d \n",idAviso);
				imprimirDatosAvisoPorId(aAviso,QTY_AVISOS, idAviso);
//				getInt(&id,"Indique el ID de la pantalla que quiere modificar.\n","NO es un id valido\n", 1,100,2);
//				while(buscarPublicidadPorIdYCuit(aPublicidad, QTY_AVISOS,id,cuit)==-1)
//				{
//					getInt(&id,"NO es un id valido para este cuit, reingrese\n", "NO es un id valido\n", 1,100,2);
//
//				}
//
//				index=buscarPublicidadPorIdPantalla(aPublicidad,QTY_AVISOS,id);
//				opcion=1;
//				imprimirDatosPublicidadPorId(aPublicidad, QTY_AVISOS, index,opcion);
				if(esSiONo(confirmacion,"Ha seleccionado modificar este aviso para PAUSARLO ¿Continuar? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
				{
					printf("ERROR. \n");
					break;
				}
				if(strncmp(confirmacion,"si",3)==0)
				{
					opcion=2;
					modificacionAvisoPorIdCamposPuntuales(aAviso,QTY_AVISOS,index,opcion);
				}
				printf("MODIFICACION REALIZADA CON EXITO \n");

//				printf("Sus nuevas publicidades activas son: \n");
//				imprimirArrayAvisosCoincidenteConUnDatoIngresadoPorUsuario()PublicidadCoincidenteConUnDatoIngresadoPorUsuario(aPublicidad,QTY_AVISOS, cuit);
				//						imprimirArrayPublicidad(aPublicidad, QTY_AVISOS);
				//buscarPublicidadIdPantallaPorCuit(aPublicidad,QTY_AVISOS,cuit, auxPublicidad);
				//			imprimirDatosPantallasPorCuitPublicidades(aPantalla,QTY_CLIENTES,auxPublicidad,QTY_AVISOS);
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
							imprimirArrayAvisosPausados(aAviso,QTY_AVISOS);
							if(getInt(&idAviso,"Ingrese id aviso pausado para realizar la busqueda \n","NO es un id valido \n",1,1000,2)!=0)
							{
								printf("ERROR.\n");
								break;
							}
							index=buscarAvisoPorId(aAviso,QTY_AVISOS,idAviso);
							while(index==-1)
							{
								if(getInt(&idAviso,"NO es un id valido. Reingrese \n","NO es un id valido \n",10,17,2)!=0)
								{
									printf("ERROR.\n");
									break;
								}
							}
							idCliente=aAviso[index].idCliente;
							printf("Cliente: \n");
							imprimirDatosClientePorId(aClientes,QTY_CLIENTES,idCliente);
							printf("Aviso \n");
							imprimirDatosAvisoPorId(aAviso,QTY_AVISOS, idAviso);
							if(esSiONo(confirmacion,"Ha seleccionado modificar este aviso para PAUSARLO ¿Continuar? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
							{
								printf("ERROR. \n");
								break;
							}
							if(strncmp(confirmacion,"si",3)==0)
							{
								opcion=3;
								modificacionAvisoPorIdCamposPuntuales(aAviso,QTY_AVISOS,index,opcion);
							}
							printf("MODIFICACION REALIZADA CON EXITO \n");


						}
						break;

		case 7:
						imprimirArrayClientes(aClientes,QTY_CLIENTES);
						break;
		case 8:
			imprimirArrayAvisos(aAviso, QTY_AVISOS);
			break;
		case 9:
//			for(opcion=1;opcion<4;opcion++)
//			{
				ordenarPorIdCliente (aAviso,QTY_AVISOS);
				imprimirArrayAvisos(aAviso,QTY_AVISOS);
				cantidadAvisosPorCliente(aAviso,QTY_AVISOS, aContador,QTY_AVISOS,opcion);
//		imprimirArrayAvisosCompletos(aContador,QTY_AVISOS );
//			}

//			printf("Las pantallas existentes son:");
//			imprimirArrayPantallas(aPantalla,QTY_CLIENTES);
//			break;
//
//		case 10:
//			printf("  1)");
//			ordenarCuit (aPublicidad,QTY_AVISOS);
//			//			imprimirArrayPublicidad(aPublicidad,QTY_AVISOS);
//			cantidadPublicacionesPorCuit(aPublicidad,QTY_AVISOS, aContador,QTY_AVISOS);
//
//			printf("  2)");
//			calcularPrecioPublicidadCompleto(aPublicidad,QTY_AVISOS,aPantalla,QTY_CLIENTES);
//			imprimirArrayPublicidad(aPublicidad,QTY_AVISOS);
//			buscarImporteMasAltoDeFacturacion(aPublicidad,QTY_AVISOS);
//
//			break;





		}

		if(esSiONo(respuesta,"¿Desea seguir haciendo otra operacion? si o no\n","No es una respuesta valida. \n",2,3,2)!=0)
		{
			printf("ERROR. \n");
			break;
		}


	}while(strncmp(respuesta,"si",4)==0);
}
