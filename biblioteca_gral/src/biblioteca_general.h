
#ifndef BIBLIOTECA_GENERAL_H_
#define BIBLIOTECA_GENERAL_H_
#endif /* BIBLIOTECA_GENERAL_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define CANTIDAD_NUMEROS 5
#define MAX_INT 65535
#define EXIT_ERROR -1
//#define
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
	char domicilio[50];
	char codigoPostal[50];
	char dni[50];
	char cuil[50];
	char telefono[50];
	char fechaNacimiento[50];
	char correoElectronico[50];
	long sueldo;
};

int getInt(int *resultado,
		  char *mensaje,
		  char *mensajeError,//se declara como puntero el char
		  int minimo,
		  int maximo,
		  int reintentos);

float getFloat(float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos);

char getChar (char *resultadoChar,
			  char *mensajeChar,
			  char *mensajeErrorChar,
			  char minimo,
			  char maximo,
			  int reintentos);

int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

int isNumber(char *resultado,
		char *mensaje,
		char *mensajeError,
		int minimo,
		int maximo,
		int reintentos);

int esLetra(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getNombre(char *resultado,
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

int initArrayInt(int array[],int limite,int valor );

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);

int imprimeArrayInt(int array[],int limite );

int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);

int sumaEnteros(int primerValorSumar, int segundoValorSumar, int *resultado);

int calcularNumeroMax(int numero, int *numeroMax);

int calcularMinimo(int numero, int *numeroMin,int *contador);

int maximoArrayInt(int array[],int limite,int *pResultadoPosMax, int *pResultadoMax);

int ordenarArrayIntAscendente(int array[],int limite);

int ordenarArrayIntDescendente(int array[],int limite);

int ordenarInsertionDescendente(int array[],int limite);

int ordenarInsertionAscentende(int array[],int limite);
