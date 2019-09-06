/*
 ============================================================================
 Name        : Clase_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#define QTY_EMPLEADOS 10
int imprimeArrayInt(int array[],int limite);
int initArrayInt(int array[],int limite,int valor);
int getArrayInt(	int array[],
					int limite,
					char *mensaje,
					char *mensajeError,
					int minimo,
					int maximo,
					int reintentos);
int maximoArrayInt(int array[],int limite,int *pResultado);
int minimoArrayInt(int array[],int limite,int *pResultado);
int promedioArrayInt(int array[],int limite,float *pResultado);
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);
int ordenarArrayInt(int array[],int limite);

int ordenar(int array[],int limite);

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);



int main(void)
{
	int edadesEmpleados[QTY_EMPLEADOS] =  {22,1,44,2,1};
	int cantidadDatos = 5 ;
	int test;


	//cantidadDatos = getArrayInt(edadesEmpleados,QTY_EMPLEADOS,"Edad?\n","Error\n",0,200,2);
	if(cantidadDatos > 0)
	{
		imprimeArrayInt(edadesEmpleados,cantidadDatos);
		//ordenarArrayInt(edadesEmpleados,cantidadDatos);
		//imprimeArrayInt(edadesEmpleados,cantidadDatos);
		//maximoArrayInt(edadesEmpleados,cantidadDatos,&test);
		ordenar(edadesEmpleados,cantidadDatos);
		imprimeArrayInt(edadesEmpleados,cantidadDatos);



	}


/*
	if(initArrayInt(edadesEmpleados,QTY_EMPLEADOS,10) == 0)
	{
		imprimeArrayInt(edadesEmpleados,QTY_EMPLEADOS);
	}
*/
	return EXIT_SUCCESS;
}

int initArrayInt(int array[],int limite,int valor )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i]=valor+i;
		}

	}
	return retorno;
}

int imprimeArrayInt(int array[],int limite )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		printf("\n\n-------\n");
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}

	}
	return retorno;
}

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}


int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int i=0;
	int buffer;
	char respuesta = 'n';
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		do
		{
			if(getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				array[i] = buffer;
				i++;
				limite--;
			}
			printf("Continuar? (s/n)");
			__fpurge(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = i;
	}
	return retorno;
}


int maximoArrayInt(int array[],int limite,int *pResultado)
{
	int i;
	int retorno = -1;
	int maximo;
	int posMaximo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		maximo = array[0];
		posMaximo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]>maximo)
			{
				maximo = array[i];
				posMaximo=i;
			}
		}
		*pResultado = posMaximo;
	}
	return retorno;
}

int ordenarArrayInt(int array[],int limite)
{
	int i;
	int retorno = -1;
	int posMaximo;
	int auxiliar;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			maximoArrayInt(array+i,limite-i,&posMaximo);
			auxiliar = array[i];
			array[i]=array[posMaximo+i];
			array[posMaximo+i] = auxiliar;
		}
	}
	return retorno;
}




int ordenar(int array[],int limite)
{
	int i;
	int retorno = -1;
	//int posMaximo;
	int bufferInt;
	int flagSwap;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
				{
						if(array[i]>array[i+1])
					{
						flagSwap=1;
						bufferInt=array[i];
						array[i]=array[i+1];
						array[i+1]=bufferInt;
						}
					}

			}while(flagSwap);
		}


	return retorno;

}


int ordenarInsertion(int array[],int limite)
{
 int i;
 int retorno =-1;
 int flag=1;
 int bufferInt;

 while(flag==1)
 {flag=0;
 for(i=limite;i<limite;i--)
 {
	 if(array[i]<array[i-1])
	 {
		 bufferInt=array[i-1];
		 array[i-1]=array[i];
		 array[i]=bufferInt;

	 }
 }
}
}

//char buffer[50]; //va a permitir cargar hasta 49, ya que la posicion 50 cierra con \0. Igualmente se puede usar menos lugares
//fgets(buffer,sizeof(buffer),stdin)//lee un string desde un archivo. permite leer de manera segura lo que ingresa el usuario. se pone lo mismo que mide el array
//lee un array, se pone el tamaño limite del array. el fgets reemplaza al scanf.

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
