/*
 * general.h
 *
 *  Created on: 2 oct. 2019
 *      Author: juliana
 */

#ifndef GENERAL_H_
#define GENERAL_H_

int getInt(int *resultado,
		  char *mensaje,
		  char *mensajeError,
		  int minimo,
		  int maximo,
		  int reintentos);

int getString(char *resultado,
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

int getDatoSoloLetras(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);

int esAlfaNumerico(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getDatoAlfaNumerico(char *resultado,
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
int getTipo(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

#endif /* GENERAL_H_ */
