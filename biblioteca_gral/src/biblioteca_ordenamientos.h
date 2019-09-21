/*
 * biblioteca_ordenamientos.h
 *
 *  Created on: 21 sep. 2019
 *      Author: juliana
 */

#ifndef BIBLIOTECA_ORDENAMIENTOS_H_
#define BIBLIOTECA_ORDENAMIENTOS_H_

int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);

int ordenarArrayIntAscendente(int array[],int limite);

int ordenarArrayIntDescendente(int array[],int limite);

int ordenarInsertionDescendente(int array[],int limite);

int ordenarInsertionAscentende(int array[],int limite);

int maximoArrayInt(int array[],int limite,int *pResultadoPosMax, int *pResultadoMax);








int sumaEnteros(int primerValorSumar, int segundoValorSumar, int *resultado);

int calcularNumeroMax(int numero, int *numeroMax);

int calcularMinimo(int numero, int *numeroMin,int *contador);






#endif /* BIBLIOTECA_ORDENAMIENTOS_H_ */
