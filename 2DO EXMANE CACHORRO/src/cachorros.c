/*
 * cachorros.c
 *
 *  Created on: 21 nov. 2019
 *      Author: alumno
 */

#include "cachorros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/** \brief Pide espacio en memoria para un nuevo cachorro
 *
 * \param
 * \return Puntero a Employee
 *
 */

Cachorro* cachorro_new()
{
	Cachorro *this;
	this= malloc(sizeof(Cachorro));
	if(this!=NULL)
	{
		this->id=0;
		this->dias=0;
		strcpy(this->nombre,"");
		strcpy(this->raza,"");
		strcpy(this->reservado,"");
		strcpy(this->genero,"");
	}
	else
	{
		printf("NO hay lugar libre \n");
	}
	return this;
}


/** \brief Setea parametros a un cachorro nuevo
 *
 * \param idStr
 * \param nombreStr
 * \param horasTrabajadasStr
 * \param sueldoStr
 * \return el nuevo cachorro con sus campos completos
 *
 */
Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* diasStr, char* razaStr, char* reservadoStr, char*generoStr)
{
	 Cachorro*retorno=NULL;
	Cachorro* this;
	int id;
	int dias;
	this= cachorro_new();
	if(this!=NULL)
	{
	if(pasarANumeroInt(idStr, &id)!=0)
	{
		printf("ERROR, el id no es un numero \n");
	}
	if(pasarANumeroInt(diasStr,&dias)!=0)
	{
		printf("ERROR, los dias no es un valor numerico \n");
	}

	if( cachorro_setId(this,id)==0 && cachorro_setNombre(this, nombreStr)==0 && cachorro_setDias(this, dias)==0 && cachorro_setRaza(this, razaStr)==0 && cachorro_setReservado(this, reservadoStr)==0 && cachorro_setGenero(this, generoStr)==0)
	{
		retorno=this;
	}
	}
	return retorno;
}


/** \brief BOrra de la memoria a un cachorro
 *
 * \param this
 * \return el espacio liberado
 *
 */
void employee_delete(Cachorro*this)
{
	free(this);
}


/** \brief Setea id a un cachorro
 *
 * \param this
 * \param item es el id pasado
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_setId(Cachorro* this,int item)
{
	int retorno =-1;
	if(this!=NULL)
		{
			this->id=item;
			retorno=0;
		}

		return retorno;
}


/** \brief Obtiene id de un cachorro
 *
 * \param this
 * \param id
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_getId(Cachorro* this,int* id)
{
	int retorno=-1;

	if(this!=NULL && id>=0)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}


/** \brief Setea nombre a un cachorro
 *
 * \param this
 * \param nombre
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_setNombre(Cachorro* this,char* nombre)
{
	int retorno =-1;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}


/** \brief Obtiene el nombre de un cachorro
 *
 * \param this
 * \param nombre
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_getNombre(Cachorro* this,char* nombre)
{
	int retorno=-1;

		if(this!=NULL && nombre!=NULL)
		{
			strcpy(nombre,this->nombre);
			retorno=0;
		}
		return retorno;
}


/** \brief Setea dias trabajadas a un cachorro
 *
 * \param this
 * \param horasTrabajadas
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_setDias(Cachorro* this,int dias)
{
	int retorno =-1;
		if(this!=NULL)
		{
			this->dias=dias;
			retorno=0;
		}
		return retorno;
}


/** \brief Obtiene dias trabajads de un cachorro
 *
 * \param this
 * \param horasTrabajadas
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_getDias(Cachorro* this,int* dias)
{
	int retorno=-1;

	if(this!=NULL && dias>0)
	{
		*dias=this->dias;
		retorno=0;
	}
	return retorno;
}


/** \brief Setea raza a un cachorro
 *  *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_setRaza(Cachorro* this,char *raza)
{
	int retorno =-1;
		if(this!=NULL )
		{
			strcpy(this->raza,raza);
			retorno=0;
		}

		return retorno;
}



/** \brief Obtiene raza de un cachorro
 *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_getRaza(Cachorro* this,char* raza)
{
	int retorno=-1;

	if(this!=NULL )
	{
		strcpy(raza,this->raza);
		retorno=0;
	}
	return retorno;
}


/** \brief Setea reservado a un cachorro
 *  *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_setReservado(Cachorro* this,char *reservado)
{
	int retorno =-1;
		if(this!=NULL )
		{
			strcpy(this->reservado,reservado);
			retorno=0;
		}

		return retorno;
}



/** \brief Obtiene reservado de un cachorro
 *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_getReservado(Cachorro* this,char* reservado)
{
	int retorno=-1;

	if(this!=NULL )
	{
		strcpy(reservado,this->reservado);
		retorno=0;
	}
	return retorno;
}



/** \brief Setea genero a un cachorro
 *  *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_setGenero(Cachorro* this,char *genero)
{
	int retorno =-1;
		if(this!=NULL )
		{
			strcpy(this->genero,genero);
			retorno=0;
		}
		return retorno;
}



/** \brief Obtiene genero de un cachorro
 *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int cachorro_getGenero(Cachorro* this,char* genero)
{
	int retorno=-1;

	if(this!=NULL )
	{
		strcpy(genero,this->genero);
		retorno=0;
	}
	return retorno;
}



 int Cachorro_pFuncMenos45Dias(void* cachorro)
{
	int dias;
	cachorro_getDias(cachorro, &dias);
	//dias=((Cachorro*)cachorro)->dias;
	int retorno =-1;

	if(cachorro!=NULL && dias>45)
	{
		//((Cachorro*)cachorro)->dias=dias;
		retorno=1;
	}
	return retorno;

}



 int Cachorro_pFuncMachos(void* cachorro)
 {
 	char genero[3];
 	strncpy(genero,((Cachorro*)cachorro)->genero,3);
 	int retorno =-1;

 	if(cachorro!=NULL && strcmp(genero,"H")==0)
 	{
 		strcpy(((Cachorro*)cachorro)->genero,genero);
 		retorno=1;
 	}
 	return retorno;

 }


 int Cachorro_pFuncCallejeros(void* cachorro)
 {
 	char raza[128];
 	strcpy(raza,((Cachorro*)cachorro)->raza);
 	int retorno =-1;
 	if(cachorro!=NULL && strcmp(raza,"Callejero")==0)
 	{
 		strcpy(((Cachorro*)cachorro)->raza,raza);
 		retorno=1;
 	}
 	return retorno;

 }
