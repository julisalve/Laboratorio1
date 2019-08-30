/*
 * utn.h
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
//int saludarAlUsuario(void);

#define EXIT_ERROR -1

int getIn(int *resultado,
		  char *mensaje,
		  char *mensajeError,
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


