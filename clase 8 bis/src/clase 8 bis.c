/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
//#include "utn.h"
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
	char dni[50];
};


int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
int getDni(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);



int main(void)
{

	struct sEmpleado aEmpleados[1000];
	struct sEmpleado bEmpleado;
	int i;
	int idEmpleado = 0;

	for(i=0;i<3;i++){

		getString(bEmpleado.nombre,"Ingrese el nombre",
				"ERROR", 1, 49, 2);

		getString(bEmpleado.apellido,"Ingrese el apellido",
						"ERROR", 1, 49, 2);

		getDni(bEmpleado.dni,
						"Ingrese dni\n",
						"NO es un dni valido\n",
						7,
						8,
						1);

		bEmpleado.idEmpleado = idEmpleado;
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;

		aEmpleados[i] = bEmpleado;
	}
	imprimirArrayEmpleados(aEmpleados,3);

	ordenarArrayEmpleados(aEmpleados,3);
	imprimirArrayEmpleados(aEmpleados,3);

	return EXIT_SUCCESS;
}

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Id: %d - Nombre: %s - Apellido: %s - dni: %s \n",aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido,aEmpleado[i].dni);
		}
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

int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad){
	int i;
	int retorno = -1;
	if(aNombres != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Nombre: %s \n",aNombres[i]);
		}
	}
	return retorno;
}

int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad){
	int i;
	int retorno = -1;
	char buffer[QTY_CARACTERES];
	int fSwap;
	if(aNombres != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aNombres[i],aNombres[i+1],QTY_CARACTERES)>0)
				{
					fSwap = 1;
					strncpy(buffer,aNombres[i],QTY_CARACTERES);
					strncpy(aNombres[i],aNombres[i+1],QTY_CARACTERES);
					strncpy(aNombres[i+1],buffer,QTY_CARACTERES);
				}
			}
		}while(fSwap);
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
		__fpurge(stdin); //limpia el teclado
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


int getDni(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno=-1;
	char buffer[4096];
	int i=0;
	getString(&buffer,
					mensaje,
					mensajeError,
					minimo,
					maximo,
					reintentos);



	if(buffer[i] != '\0' && buffer[i] > '0' || buffer[i] < '9')
		  {
		       	  strncpy(resultado,buffer,maximo+1);
		       	  return 0;
		          i++;
		  }


	return retorno;
	}

