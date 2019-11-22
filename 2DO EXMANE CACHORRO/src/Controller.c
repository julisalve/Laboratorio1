#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cachorros.h"
#include "Parser.h"


int controller_loadFromText(char * path , LinkedList* pArrayListCachorro)
{
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile != NULL &&  pArrayListCachorro!=NULL)// ll_len(pArrayListCachorro)==0 &&
	{

		parser_cachorroFromText(pFile,pArrayListCachorro);
		printf("\n Operacion exitosa.\n");
		fclose(pFile);
	}
	else
	{
		printf("ERROR: El archivo no pudo abrirse. \n");
	}

	return 1;
}



int controller_saveAsText(char* path , LinkedList* pArrayListCachorro)
{
	FILE *pFile =NULL;
	Cachorro *pCachorro;
	int i;
	pFile=fopen(path,"w");
	if(pArrayListCachorro != NULL && ll_len(pArrayListCachorro)>0 && pFile!=NULL)
	{
		fprintf(pFile, "Id,Nombre,Dias,Raza,Reservado,Genero\n");
		for(i=0;i<ll_len(pArrayListCachorro);i++)
		{
			pCachorro = ll_get(pArrayListCachorro, i);
			if(pCachorro!=NULL)
			{
				fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",pCachorro->id,pCachorro->nombre,pCachorro->dias,pCachorro->raza,pCachorro->reservado,pCachorro->genero);
			}
		}
		printf("Archivo guardado con exito \n");
	}
	fclose(pFile);
	return 1;
}










/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addCachorro(LinkedList* pArrayCachorro)
{
	int id;
	char idStr[4096];
	char nombreStr[4096];
	char diasStr[4096];
	char raza [4096];
	char reservado [4096];
	char genero [4096];
	Cachorro *nuevoCachorro;
	if(pArrayCachorro!=NULL)
	{
		id=buscarMaximoIdGenerado(pArrayCachorro)+1;
		sprintf(idStr,"%d",id);
		getDatoSoloLetras(nombreStr,"Ingrese un nombre \n","NO es un nombre valido \n",2,100,2);
		getSoloNumeros(diasStr,"Ingrese dias del cachorro \n","NO es un dato valido \n",1,1000,2);
		getDatoSoloLetras(raza,"Ingrese raza \n","NO es una raza valido \n",2,100,2);
		esSiONo(reservado,"Ingrese estado si o no (reservado)\n","NO es un dato valido \n",2,3,2);
		getDatoSoloLetras(genero,"Ingrese genero \n","NO es un genero valido \n",1,100,2);
		nuevoCachorro=cachorro_newParametros(idStr,nombreStr,diasStr,raza,reservado,genero);
		ll_add(pArrayCachorro,nuevoCachorro);
		printf("Alta exitosa: \n Id: %s \n Nombre: %s \n Dias: %s \n Raza: %s\n Reservado: %s\n Genero: %s\n",idStr,nombreStr,diasStr,raza,reservado,genero);
	}
	return 1;
}

/** \brief Busca el id maximo
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int buscarMaximoIdGenerado(LinkedList *pArrayListCachorro)
{
	int retorno=-1;
	int maximoId=0;
	int i;
	Cachorro *pCachorro;
	if(pArrayListCachorro!=NULL)
	{
		for(i=0;i<ll_len(pArrayListCachorro); i++)
		{
			pCachorro = ll_get(pArrayListCachorro, i);
			if(pCachorro->id>maximoId)
			{
				maximoId=pCachorro->id;
			}
		}retorno=maximoId;
	}
	return retorno;
}

///** \brief Modificar datos de empleado
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int controller_editEmployee(LinkedList* pArrayListEmployee)
//{
//	Employee *this;
//	int id;
//	int horasTrabajadas;
//	int sueldo;
//	char nombre[50];
//	char bufferNombre[50];
//	int bufferHorasTrabajadas;
//	int bufferSueldo;
//	char modificacion[3];
//	int opcion;
//	char respuesta[3];
//	int maximoId;
//	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
//	{
//		maximoId=buscarMaximoIdGenerado(pArrayListEmployee);
//		getInt(&id,"Ingrese ID que desea modificar\n","NO es un id valido\n",1,maximoId,2);
//		this=buscarIdEmpleado(pArrayListEmployee,id);
//		while(this==NULL)
//		{
//			getInt(&id,"No existe el id ingresado. Seleccione un ID\n","NO es un id valido\n",1,1000000000,2);
//		}
//		do
//		{
//			printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d \n",this->id, this->nombre, this->horasTrabajadas, this->sueldo);
//			getInt(&opcion,"Indique la opcion que desea modificar: \n 1) Nombre \n 2) Horas Trabajadas, \n 3) Sueldo. \n","No es una opcion valida",1,3,2);
//			switch(opcion)
//			{
//			case 1:
//				employee_getNombre(this,nombre);
//				getDatoSoloLetras(bufferNombre,"Ingrese un nombre\n","NO es un nombre valido \n",1,50,2);
//				esSiONo(modificacion,"Confirma modificacion de nombre? si / no \n","NO es una respuesta valida\n",1,3,2);
//				if(strncmp(modificacion,"si",3)==0)
//				{
//					employee_setNombre(this,bufferNombre);
//					printf("Modificacion realizada con exito\n");
//				}
//				break;
//			case 2:
//				employee_getHorasTrabajadas(this,&horasTrabajadas);
//				getInt(&bufferHorasTrabajadas,"Ingrese horas trabajadas\n","NO es un dato valido \n",1,10000,2);
//				esSiONo(modificacion,"Confirma modificacion de horas trabajadas? si / no \n","NO es una respuesta valida\n",1,3,2);
//				if(strncmp(modificacion,"si",3)==0)
//				{
//					employee_setHorasTrabajadas(this,bufferHorasTrabajadas);
//					printf("Modificacion realizada con exito\n");
//				}
//				break;
//			case 3:
//				employee_getSueldo(this,&sueldo);
//				getInt(&bufferSueldo,"Ingrese sueldo\n","NO es un dato valido \n",1,10000,2);
//				esSiONo(modificacion,"Confirma modificacion de sueldo? si / no \n","NO es una respuesta valida\n",1,3,2);
//				if(strncmp(modificacion,"si",3)==0)
//				{
//					employee_setSueldo(this,bufferSueldo);
//					printf("Modificacion realizada con exito\n");
//				}
//				break;
//			}
//			esSiONo(respuesta,"Desea seguir modificando datos? si / no \n","NO es una respuesta valida\n",1,3,2);
//		}while(strncmp(respuesta,"si",3)==0);
//
//	}
//	else
//	{
//		printf("No hay datos cargados para ser modificados \n");
//	}
//	return 1;
//}
//
//

//
///** \brief Baja de empleado
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int controller_removeEmployee(LinkedList* pArrayListEmployee)
//{
//	Employee *this;
//	int id;
//	int maximoId;
//	int index;
//	char respuesta[3];
//	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
//	{
//		maximoId=buscarMaximoIdGenerado(pArrayListEmployee);
//		getInt(&id,"Ingrese ID que desea dar de baja \n","NO es un id valido\n",1,maximoId,2);
//		this=buscarIdEmpleado(pArrayListEmployee,id);
//		while(this==NULL)
//		{
//			getInt(&id,"No existe el id ingresado. Seleccione un ID\n","NO es un id valido\n",1,1000000000,2);
//		}
//		printf("Id: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %d \n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
//		esSiONo(respuesta,"Realmente quiere dar de baja a este empleado? si / no \n","NO es una respuesta valida",1,3,2);
//		if(strncmp(respuesta,"si",3)==0)
//		{
//			index=ll_indexOf(pArrayListEmployee,this);
//			ll_remove(pArrayListEmployee,index);
//			printf("Baja realizada con exito. \n");
//		}
//	}
//	else
//	{
//		printf("No hay datos cargados para ser dados de baja \n");
//	}
//	return 1;
//}

int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
	Cachorro *pCachorro;
	int i;
	if(pArrayListCachorro!=NULL && ll_len(pArrayListCachorro)>0)
	{
		for(i=0; i<ll_len(pArrayListCachorro); i++)
		{
//			printf("tamaño %d\n",ll_len(pArrayListCachorro));
			pCachorro = ll_get(pArrayListCachorro, i);
//			printf("%4d %15s %4d \n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas);
			printf("%4d %15s %5d %12s %3s %3s\n", pCachorro->id, pCachorro->nombre, pCachorro->dias, pCachorro->raza, pCachorro->reservado, pCachorro->genero);
		}
	}
	else
	{
		printf("No hay datos cargados para ser listados \n");
	}
	return 1;
}

///** \brief Ordenar empleados
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int controller_sortEmployee(LinkedList* pArrayListEmployee)
//{
//	int opcion;
//	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
//	{
//		getInt(&opcion,"Ingrese una opcion: \n 1)Ordenamiento por id \n 2)Ordenamiento por nombre \n 3)Ordenamiento por horas trabajadas \n 4)Ordenamiento por sueldo \n","NO es una opcion valida",1,4,2);
//
//		switch(opcion)
//		{
//		case 1:
//			printf("Espere mientras se procesa la informacion. \n");
//			ll_sort(pArrayListEmployee,employee_sortPorId,1);
//			printf("Ordenamiento por id realizado con exito\n");
//			break;
//		case 2:
//			printf("Espere mientras se procesa la informacion. \n");
//			ll_sort(pArrayListEmployee,employee_sortPorNombre,1);
//			printf("Ordenamiento por nombre realizado con exito\n");
//			break;
//		case 3:
//			printf("Espere mientras se procesa la informacion. \n");
//			ll_sort(pArrayListEmployee,employee_sortPorHorasTrabajadas,1);
//			printf("Ordenamiento por horas trabajadas realizado con exito\n");
//			break;
//		case 4:
//			printf("Espere mientras se procesa la informacion. \n");
//			ll_sort(pArrayListEmployee,employee_sortPorSueldo,1);
//			printf("Ordenamiento por sueldo realizado con exito\n");
//			break;
//		}
//	}
//	else
//	{
//		printf("No hay datos cargados para ser ordenados \n");
//	}
//	return 1;
//}
//
//
//
///** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
//{
//	FILE *pFileBin =NULL;
//	Employee *pEmpleado;
//	int i;
//
//	pFileBin=fopen(path,"wb");
//	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0 && pFileBin!=NULL)
//	{
//		for(i=0;i<ll_len(pArrayListEmployee);i++)
//		{
//			pEmpleado = ll_get(pArrayListEmployee, i);
//		//	printf("id %d  nombre %s horas %d \n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas);
//			if(pEmpleado!=NULL)
//			{
//				fwrite(pEmpleado,sizeof(Employee),1,pFileBin);
//			}
//		}
//		printf("Archivo guardado con exito \n");
//		fclose(pFileBin);
//	}
//
//	return 1;
//}
//
//
//
//int controller_mapEmployee(LinkedList* pArrayListEmployee)
//{
//int retorno =-1;
//if(pArrayListEmployee!=NULL)
//{
//	printf("controller map");
//	ll_map(pArrayListEmployee, Employee_pFuncMapSueldo);
//	return 0;
//}
//return retorno;
//}
//
//
//
//
//
//
//
///** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
//{
//	FILE * pFileBin;
//	pFileBin = fopen(path,"rb");
//	if(pFileBin != NULL)
//	{
//		if( pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)==0 )//
//		{
//			parser_EmployeeFromBinary(pFileBin,pArrayListEmployee);
//			printf("\n Operacion exitosa.\n");
//		}
//		fclose(pFileBin);
//	}
////	else
////	{
////		pFileBin=fopen(path,"wb");
////		if(pFileBin!=NULL)
////		{
////			printf("Se ha creado un archivo binario. \n");
////		}
////		else
////		{
////			printf("ERROR: El archivo no pudo abrirse. \n");
////		}
////	}
//
//	return 1;
//}




int controller_filtter(LinkedList* pArrayListCachorro)
{
int retorno =-1;
if(pArrayListCachorro!=NULL)
{
		ll_filter(pArrayListCachorro, Cachorro_pFuncMenos45Dias);
	return 0;
}
return retorno;
}


int controller_filtterMachos(LinkedList* pArrayListCachorro)
{
int retorno =-1;
if(pArrayListCachorro!=NULL)
{
		ll_filter(pArrayListCachorro, Cachorro_pFuncMachos);
	return 0;
}
return retorno;
}


int controller_filtterCallejeros(LinkedList* pArrayListCachorro)
{
int retorno =-1;
if(pArrayListCachorro!=NULL)
{
		ll_filter(pArrayListCachorro, Cachorro_pFuncCallejeros);
	return 0;
}
return retorno;
}
