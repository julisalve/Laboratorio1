/*
 * cachorros.h
 *
 *  Created on: 21 nov. 2019
 *      Author: alumno
 */

#ifndef CACHORROS_H_
#define CACHORROS_H_

#include "LinkedList.h"
#include "general.h"
typedef struct
{
    int id;
    char nombre[128];
    int dias;
    char raza [128];
    char reservado [3];
    char genero [3];
}Cachorro;

Cachorro* cachorro_new();
Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* diasStr, char* razaStr, char* reservadoStr, char*generoStr);
void cachorro_delete(Cachorro *this);

int cachorro_setId(Cachorro* this,int id);
int cachorro_getId(Cachorro* this,int* id);

int cachorro_setNombre(Cachorro* this,char* nombre);
int cachorro_getNombre(Cachorro* this,char* nombre);

int cachorro_setDias(Cachorro* this,int dias);
int cachorro_getDias(Cachorro* this,int* dias);

int cachorro_setRaza(Cachorro* this,char *raza);
int cachorro_getRaza(Cachorro* this,char* raza);

int cachorro_setReservado(Cachorro* this,char* reservado);
int cachorro_getReservado(Cachorro* this,char* reservado);

int cachorro_setGenero(Cachorro* this,char* genero);
int cachorro_getGenero(Cachorro* this,char* genero);

//int cachorro_setSueldo(Cachorro* this,int sueldo);
//int cachorro_getSueldo(Cachorro* this,int* sueldo);

int Cachorro_pFuncMenos45Dias(void* cachorro);
int Cachorro_pFuncMachos(void* cachorro);
int Cachorro_pFuncCallejeros(void* cachorro);

//int cachorro_sortPorId( void * datoUno, void *datoDos);
//int cachorro_sortPorNombre( void * datoUno, void *datoDos);
//int cachorro_sortPorHorasTrabajadas( void * datoUno, void *datoDos);
//int cachorro_sortPorSueldo( void * datoUno, void *datoDos);
//
//
//void cachorro_pFuncMapSueldo(void* cachorro);


#endif /* CACHORROS_H_ */
