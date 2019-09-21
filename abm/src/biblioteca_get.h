
#ifndef BIBLIOTECA_GET_H_
#define BIBLIOTECA_GET_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_INT 65535
#define EXIT_ERROR -1

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



#endif /* BIBLIOTECA_GET_H_ */
