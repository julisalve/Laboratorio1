#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "general.h"
void em_calcularSueldo(void* p)
{
	((Empleado*)p)->sueldo=0;
int sueldo=0;
int horas =((Empleado*)p)->horasTrabajadas;
if(horas<=120)
{
	sueldo=sueldo +180*horas;
}
else
{
	sueldo=sueldo + 120*180;
}
if(horas>120 && horas<=160)
{
	sueldo=sueldo +240*(horas-120);
}
else if(horas>160)
{
	sueldo=sueldo + 240*(160-120);
}
if(horas>160 && horas<=240)
		{
	sueldo=sueldo +350*(horas-160);
		}
else if (horas>240)
{
	sueldo=sueldo + 350*(240-160);
}

((Empleado*)p)->sueldo=sueldo;
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
}





/** \brief Pide espacio en memoria para un nuevo empleado
 *
 * \param
 * \return Puntero a Employee
 *
 */

Empleado* employee_new()
{
	Empleado *this;
	this= malloc(sizeof(Empleado));
	if(this!=NULL)
	{
		this->id=0;
		this->horasTrabajadas=0;
		this->sueldo=0;
		strcpy(this->nombre,"");
	}
	else
	{
		printf("NO hay lugar libre \n");
	}
	return this;
}


/** \brief Setea parametros a un empleado nuevo
 *
 * \param idStr
 * \param nombreStr
 * \param horasTrabajadasStr
 * \param sueldoStr
 * \return el nuevo empleado con sus campos completos
 *
 */
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Empleado *retorno=NULL;
	Empleado* this;
	int id;
	int horasTrabajadas;
	int sueldo;
	this= employee_new();
	if(this!=NULL)
	{
	if(pasarANumeroInt(idStr, &id)!=0)
	{
		printf("ERROR, el id no es un numero \n");
	}
	if(pasarANumeroInt(horasTrabajadasStr,&horasTrabajadas)!=0)
	{
		printf("ERROR, las horas trabajadas no es un valor numerico \n");
	}
	if(pasarANumeroInt(sueldoStr,&sueldo)!=0)
	{
		printf("ERROR, el sueldo no es un valor numerico \n");
	}
	if( employee_setId(this,id)==0 && employee_setNombre(this, nombreStr)==0 && employee_setHorasTrabajadas(this, horasTrabajadas)==0 && employee_setSueldo(this, sueldo)==0)
	{
		retorno=this;
	}
	else
	{
		employee_delete(this);
	}
	}
	return retorno;
}


/** \brief BOrra de la memoria a un empleado
 *
 * \param this
 * \return el espacio liberado
 *
 */
void employee_delete(Empleado*this)
{
	free(this);
}


/** \brief Setea id a un empleado
 *
 * \param this
 * \param item es el id pasado
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setId(Empleado* this,int item)
{
	int retorno =-1;
	if(this!=NULL)
		{
			this->id=item;
			retorno=0;
		}

		return retorno;
}


/** \brief Obtiene id de un empleado
 *
 * \param this
 * \param id
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getId(Empleado* this,int* id)
{
	int retorno=-1;

	if(this!=NULL && id>=0)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}


/** \brief Setea nombre a un empleado
 *
 * \param this
 * \param nombre
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setNombre(Empleado* this,char* nombre)
{
	int retorno =-1;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}


/** \brief Obtiene el nombre de un empleado
 *
 * \param this
 * \param nombre
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getNombre(Empleado* this,char* nombre)
{
	int retorno=-1;

		if(this!=NULL && nombre!=NULL)
		{
			strcpy(nombre,this->nombre);
			retorno=0;
		}
		return retorno;
}


/** \brief Setea horas trabajadas a un empleado
 *
 * \param this
 * \param horasTrabajadas
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
	int retorno =-1;
		if(this!=NULL)
		{
			this->horasTrabajadas=horasTrabajadas;
			retorno=0;
		}
		return retorno;
}


/** \brief Obtiene horas trabajads de un empleado
 *
 * \param this
 * \param horasTrabajadas
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL && horasTrabajadas>0)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}


/** \brief Setea sueldo a un empleado
 *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_setSueldo(Empleado* this,int sueldo)
{
	int retorno =-1;
		if(this!=NULL )
		{
			this->sueldo=sueldo;
			retorno=0;
		}

		return retorno;
}



/** \brief Obtiene sueldo de un empleado
 *
 * \param this
 * \param sueldo
 * \return devuelve 0 en caso de exito o -1 en caso de error
 *
 */
int employee_getSueldo(Empleado* this,int* sueldo)
{
	int retorno=-1;

	if(this!=NULL && sueldo>0)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}



/** \brief Busca un empleado por id
 *
 * \param pArrayListEmployee
 * \param id
 * \return devuelve NULL en caso de que no exista empleado con el id indicado, o develve el empleado en caso de exito
 *
 */


/** \brief Ordena ID de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
int employee_sortPorId( void * datoUno, void *datoDos)
{
	int idUno;
	int idDos;
	idUno=((Empleado*)datoUno)->id;
	idDos=((Empleado*)datoDos)->id;
	if(idUno > idDos)
	{
		return 1;
	}
	else if(idUno < idDos)
	{
		return -1;
	}
	return 0;
}


/** \brief Ordena por NOmbre de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
int employee_sortPorNombre( void * datoUno, void *datoDos)
{

	if(strncmp(((Empleado *)datoUno)->nombre,((Empleado *)datoDos)->nombre,50)>0)
	{
		return 1;
	}
	else if(strncmp(((Empleado *)datoUno)->nombre,((Empleado *)datoDos)->nombre,50)<0)
	{
		return -1;
	}
	return 0;
}

/** \brief Ordena horas trabajadas de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
int employee_sortPorHorasTrabajadas( void * datoUno, void *datoDos)
{
	int horasUno;
	int horasDos;
	horasUno=((Empleado*)datoUno)->horasTrabajadas;
	horasDos=((Empleado*)datoDos)->horasTrabajadas;
	if(horasUno > horasDos)
	{
		return 1;
	}
	else if(horasUno < horasDos)
	{
		return -1;
	}
	return 0;
}



/** \brief Ordena sueldo de manera ascendente
 *
 * \param datoUno
 * \param datoDos
 * \return devuelve 1 en caso de orden ascendente, -1 en orden descendente, o -1 en caso contrario
 *
 */
int employee_sortPorSueldo( void * datoUno, void *datoDos)
{
	int sueldoUno;
	int sueldoDos;
	sueldoUno=((Empleado*)datoUno)->sueldo;
	sueldoDos=((Empleado*)datoDos)->sueldo;
	if(sueldoUno > sueldoDos)
	{
		return 1;
	}
	else if(sueldoUno < sueldoDos)
	{
		return -1;
	}
	return 0;
}


void Employee_pFuncMapSueldo(void* empleado)
{
	int sueldo;
	sueldo=((Empleado*)empleado)->sueldo;
//	Employee *empleado;
//	empleado= ((Employee*)elemento);

	if(empleado!=NULL && sueldo<70)
	{
		printf("Datos originales empleado: \nID: %d - Nombre: %s - Sueldo %d\n",((Empleado*)empleado)->id,((Empleado*)empleado)->nombre,sueldo);
		sueldo=sueldo*1.20;
		printf("Datos nuevos: \nID: %d - Nombre: %s - Sueldo %d\n",((Empleado*)empleado)->id,((Empleado*)empleado)->nombre,sueldo);
	}
}
