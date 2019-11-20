#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "Parser.h"

int controller_loadFromText(char * path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile != NULL && ll_len(pArrayListEmployee)==0 && pArrayListEmployee!=NULL)
	{

		parser_EmployeeFromText(pFile,pArrayListEmployee);
		printf("\n Operacion exitosa.\n");
		fclose(pFile);
	}
	else
	{
		printf("ERROR: El archivo no pudo abrirse. \n");
	}

	return 1;
}

//int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
//{
//	int retorno =-1;
//		int r;
//		char id[4096];
//		char nombre[4096];
//		char horasTrabajadas[4096];
//		char sueldo [4096] ;
//
//		int flagPrimerRenglon=0;
//		Empleado *nuevoEmpleado;
//		if(fileName!=NULL && listaEmpleados!=NULL)
//		{
//			while(!feof(fileName))
//			{
//				r=fscanf(fileName,"%[^,],%[^,],%[^\n]\n",
//						id,
//						nombre,
//						horasTrabajadas);
//				if(flagPrimerRenglon==0)
//				{
//					flagPrimerRenglon=1;
//					continue;
//				}
//				else if(flagPrimerRenglon==1 && r==3)
//				{
//					nuevoEmpleado= employee_newParametros(id,nombre,horasTrabajadas,sueldo);
//					if(nuevoEmpleado!=NULL)
//					{
//						ll_add(listaEmpleados,nuevoEmpleado);
//						retorno=1;
//					}
//				}
//			}
//		}
//
//		return retorno;
//
//}

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)// recibe un elemento, lo construye y lo agrega al array.
{
	int retorno =-1;
	int r;
	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo[4096];
	int flagPrimerRenglon=0;
	Empleado *nuevoEmpleado;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			strncpy(sueldo,"0",4096);
			r=fscanf(pFile,"%[^,],%[^,],%[^\n]\n",
					id,
					nombre,
					horasTrabajadas);
			if(flagPrimerRenglon==0)
			{
				flagPrimerRenglon=1;
				continue;
			}
			else if(flagPrimerRenglon==1 && r==3)
			{
				nuevoEmpleado= employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(nuevoEmpleado!=NULL)
				{
					ll_add(pArrayListEmployee,nuevoEmpleado);
					retorno=EXIT_SUCCESS;
				}
			}
		}
	}

	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile =NULL;
	Empleado *pEmpleado;
	int i;
	pFile=fopen(path,"w");
	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0 && pFile!=NULL)
	{
		fprintf(pFile, "Id,Nombre,HorasTrabajadas,Sueldo\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pEmpleado = ll_get(pArrayListEmployee, i);
			if(pEmpleado!=NULL)
			{
				fprintf(pFile,"%d,%s,%d,%d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
			}
		}
		printf("Archivo guardado con exito \n");
	}
	fclose(pFile);
	return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Empleado *pEmpleado;
	int i;
	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
	{
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			pEmpleado = ll_get(pArrayListEmployee, i);
//			printf("%4d %15s %4d \n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas);
			printf("%4d %15s %4d %6d\n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas, pEmpleado->sueldo);
		}
	}
	else
	{
		printf("No hay datos cargados para ser listados \n");
	}
	return 1;
}


int controller_CalcularSueldo(LinkedList* pArrayListEmployee)
{
	int retorno=-1;


	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
	{
		ll_map(pArrayListEmployee,em_calcularSueldo);
		retorno = 0;
	}
	else
	{
		printf("No existen datos cargados a mapear!\n");
	}
	return retorno;
}
Empleado* buscarIdEmpleado(LinkedList* pArrayListEmployee, int id)
{
	Empleado*this=NULL;
	int i;
	if(pArrayListEmployee!=NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee);i++)
			{
				this = ll_get(pArrayListEmployee, i);
				if(this->id == id)
				{
					return this;
				}
			}
	}
	return this;
}
