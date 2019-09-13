/*
 ============================================================================
 Name        : clase8.c
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

#define QTY_ELEMENTOS 5
#define QTY_CARACTERES 300
#define CANT_NUMEROS_DNI 8
#define EXIT_ERROR -1
#define CANT_DNI 5
#define




int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

char imprimeArrayString(char array[][QTY_CARACTERES],int limite);
char imprimeArrayStringDatosPuntuales(char array[][QTY_CARACTERES],int limite);
char ordenarStringDescendente(char array[][QTY_CARACTERES],int limite);

struct sEmpleado
{
	int idEmpleado; //siempre se usa
	int status;//siempre se usa
	char nombre [50];
	char apellido[50];
	char dni [50];//alfanumerico por las dudas es preferible exagerar.

};

int main()
{
	struct sEmpleado aEmpleados[1000];
	aEmpleados.idEmpleado =0;
	strncpy(aEmpleados[14].nombre,"Juan,50");
	aEmpleados[0]=aEmpleados[14];//copio todo lo del empleado.
	bEmpleado=aEmpleados[14];
	aEmpleados[14]=aEmpleados[11];



	getString(bEmpleado.nombre,
					"Ingrese un nombre \n",
					"NO es un nombre valido \n",
					2,
					QTY_CARACTERES-1,
					2);



	char nombres[QTY_ELEMENTOS][QTY_CARACTERES];
	char dni[CANT_DNI][CANT_NUMEROS_DNI];
	char nombre [QTY_CARACTERES];

	long dniBuffer[CANT_NUMEROS_DNI];
	int retorno;
	int i;
	for(i=0;i<QTY_ELEMENTOS;i++)
	{
		//__fpurge(stdin);
		getString(nombre,
				"Ingrese un nombre \n",
				"NO es un nombre valido \n",
				2,
				QTY_CARACTERES-1,
				2);

		strncpy(nombres[i],nombre,QTY_CARACTERES);

		getString(dniBuffer,
						"Ingrese un numero de dni \n",
						"NO es un dni valido \n",
						7,
						CANT_NUMEROS_DNI,
						2);

		//dni=atoi (dni[]);


	}

	imprimeArrayString(nombres,QTY_ELEMENTOS);
	//imprimeArrayStringDatosPuntuales(nombres,QTY_ELEMENTOS);
	//imprimeArrayString(dni,CANT_DNI);
	ordenarStringDescendente(nombres,QTY_ELEMENTOS);
	imprimeArrayString(nombres,QTY_ELEMENTOS);
	//int j;
//	for(j=0;j<QTY_ELEMENTOS;j++)
//	{
//
//		printf("nombre: %s \n",nombres[j]);
//	}
//	printf("%s ",nombres[0]);
	retorno=0;
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


char imprimeArrayString(char array[][QTY_CARACTERES],int limite)
{
	int retorno = -1;
	int i;
	if(array != NULL && limite > 0) //!=NULL implica que esta apuntando a algo, Se aplica para punteros.
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("%s\n",array[i]);
		}

	}
	return retorno;
}


char imprimeArrayStringDatosPuntuales(char array[][QTY_CARACTERES],int limite)
{
	int retorno = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(i==1 || i==3)
			printf("%s\n",array[i]);
		}

	}
	return retorno;
}

char ordenarStringDescendente(char array[][QTY_CARACTERES],int limite)
{
	int i;
	int retorno = EXIT_ERROR;
	char bufferString[QTY_CARACTERES];
	int flagSwap;
	if(array != NULL && limite > 0)
	{
		retorno=EXIT_SUCCESS;
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
				{
					if(strncmp(array[i],array[i+1],QTY_CARACTERES)<0)
					{
						flagSwap=1;
						strncpy(bufferString,array[i],QTY_CARACTERES);
						strncpy(array[i],array[i+1],QTY_CARACTERES);
						strncpy(array[i+1],bufferString,QTY_CARACTERES);
						}
					}
			}while(flagSwap==1);
		}return retorno;
}



