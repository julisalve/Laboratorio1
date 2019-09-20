/*
 * Empleados.c
 *
 *  Created on: 17 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Empleados.h"


static int generarId(void)
{
	static int contadorId=0; //es como seria global pero solo aplica para el scoup.
	contadorId++;
	return contadorId;
}



int initLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
	{
		aArray[i].status=STATUS_EMPTY;
	}
		}
		return retorno;
}

int buscarLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int buscarEmpleadoPorId(struct sEmpleado *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(aArray[i].idEmpleado== STATUS_NOT_EMPTY && id==aArray[i].idEmpleado)
		{
			retorno = i;
			break;
		}
	}
	}
	return retorno;
}

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=-1;
	char buffer[4096];
	if(resultado!=NULL &&
		mensaje !=NULL &&
		mensajeError !=NULL &&
		maximo>minimo &&
		reintentos>0)
	{
	do
	{
		printf("%s", mensaje);
		__fpurge(stdin); //fflush(stdin) EN WINDOWS . limpia el teclado
		fgets(buffer,sizeof(buffer),stdin); //toma lo del teclado de manera segura
		buffer[strlen(buffer)-1]='\0'; //en buffer se toma hasta lo anterior en \0
		if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
		{
			strncpy(resultado,buffer,maximo+1);
			retorno =0;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);
	}
	return retorno;
}

int ImprimirDatosEmpleadoPorId(struct sEmpleado *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int indice =buscarEmpleadoPorId( aArray,cantidad, id);
	if(aArray != NULL && cantidad > 0)
	{

		if(indice>=0)
		{
			retorno = indice;
			printf("Id: %d - Nombre: %s - Apellido: %s  \n",aArray[indice].idEmpleado,aArray[indice].nombre,aArray[indice].apellido);
			break;
		}
	}
	return retorno;
}

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aEmpleado[i].status== STATUS_NOT_EMPTY)
			{
				printf("status %d - Id: %d - Nombre: %s - Apellido: %s  \n",aEmpleado[i].status,aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido);
			}

		}
	}
	return retorno;
}
int bajaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,int id)
{
	int retorno =EXIT_ERROR;
	char respuesta;
	int posicionEmpleado= buscarEmpleadoPorId(aArray, cantidad,id);

	if(aArray != NULL && cantidad > 0 && posicionEmpleado >=0)
			{
				aArray[posicionEmpleado].status= STATUS_EMPTY;
				retorno=EXIT_SUCCESS;
			}

	return retorno;
}

int modificacionEmpleadoPorId(struct sEmpleado *aArray, int cantidad, struct sEmpleado empleadoNuevo)
{
	int retorno =EXIT_ERROR;
	int id =empleadoNuevo
	int posicionEmpleado= buscarEmpleadoPorId(aArray, cantidad,id);

	if(aArray != NULL && cantidad > 0 && posicionEmpleado >=0)
			{
					aArray[posicionEmpleado]=empleadoNuevo;
					retorno = EXIT_SUCCESS;
			}

	return retorno;
}

int modificacionEmpleadoPorIdCamposPuntuales(struct sEmpleado *aArray, int cantidad, struct sEmpleado empleadoNuevo)
{
	int retorno =EXIT_ERROR;
	int id;
	int posicionEmpleado= buscarEmpleadoPorId(aArray, cantidad,id);

	if(aArray != NULL && cantidad > 0 && posicionEmpleado >=0)
			{
					aArray[posicionEmpleado]=empleadoNuevo;
					retorno = EXIT_SUCCESS;
			}

	return retorno;
}


pantalla panux
switch(opcion)
{
case 3:
{

	pedirDAtosPAntalla(&panaux)
	sPantalla p;
	getInt(&p.idpantalla,"ingrese id");
	getString(p.nombre,"ingrese nombre");
	getString(p.apellido,"ingrese apellido");
	modificarPAntalla(lista,len,p);
	break;
}
}

int pedirDAtoPAntalla(struct sPAntalla * pPAtalla)
{
	sPantalla p;
		getInt(&p.idpantalla,"ingrese id");
		getString(p.nombre,"ingrese nombre");
		getString(p.apellido,"ingrese apellido");
		modificarPAntalla(lista,len,p);

		p.status =NOT_EMPTY;
		*pPAntalla = p;
}


//char opcionElegida(char *resultado,
//				char *mensaje,
//				char *mensajeError,
//				int minimo,
//				int maximo,
//				int reintentos)
//{
//
//}


int altaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado)
{
	int retorno = -1;
	int i;
	i = buscarLugarLibreEmpleado(aArray,cantidad);
		if(aArray != NULL && cantidad > 0 && i>=0)
		{
			aArray[i]=empleado;
			aArray[i].status= STATUS_NOT_EMPTY;
			aArray[i].idEmpleado = generarId();
			retorno = EXIT_SUCCESS;
		}
	return retorno;
}

int altaForzadaEmpleados(struct sEmpleado *aArray,int cantidad)
{
	int retorno;
	int id[]={1,5,6,7,8};
	char nombre [][25]= {"juan","pedro","maria","eva","abrahm"};
	char apellido[][25]={"gomez","perez","lopez","rodrigguez","peron"};
	int i;
	for(i=0;i<5;i++)
	{
		aArray[i].status=STATUS_NOT_EMPTY;
		aArray[i].idEmpleado=id[i];
		strncpy(aArray[i].nombre,nombre[i],25);
		strncpy(aArray[i].apellido,apellido[i],25);
		retorno=0;

	}
	return retorno;
}




int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	struct sEmpleado bEmpleados;
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,50)>0)
				{
					fSwap = 1;
					bEmpleados=aEmpleado[i];
					aEmpleado[i]=aEmpleado[i+1];
					aEmpleado[i+1]=bEmpleados;
				}
				else if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,50)==0)

				{
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,50)>0)
						{
							fSwap = 1;
							bEmpleados=aEmpleado[i];
							aEmpleado[i]=aEmpleado[i+1];
							aEmpleado[i+1]=bEmpleados;
						}
				}
			}
		}while(fSwap);
	}
	return retorno;
}
