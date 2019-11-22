#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cachorros.h"
#include "Parser.h"



int parser_cachorroFromText(FILE* pFile , LinkedList* pArrayListCachorro)// recibe un elemento, lo construye y lo agrega al array.
{
	int retorno =-1;
	int r;
	char id[4096];
	char nombre[4096];
	char dias[4096];
	char raza[4096];
	char reservado[4096];
	char genero[4096];
	int flagPrimerRenglon=0;
	Cachorro *nuevoCachorro;
	if(pFile!=NULL && pArrayListCachorro!=NULL)
	{
		while(!feof(pFile))
		{
			//strncpy(sueldo,"0",4096);
			r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					id,
					nombre,
					dias,
					raza,
					reservado,
					genero);
			if(flagPrimerRenglon==0)
			{
				flagPrimerRenglon=1;
				continue;
			}
			else if(flagPrimerRenglon==1 && r==6)
			{
				nuevoCachorro= cachorro_newParametros(id,nombre,dias,raza,reservado,genero);
				if(nuevoCachorro!=NULL)
				{
					ll_add(pArrayListCachorro,nuevoCachorro);
					retorno=EXIT_SUCCESS;
				}
			}
		}
	}

	return retorno;
}






//int controller_CalcularSueldo(LinkedList* pArrayListEmployee)
//{
//	int retorno=-1;
//
//
//	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
//	{
//		ll_map(pArrayListEmployee,em_calcularSueldo);
//		retorno = 0;
//	}
//	else
//	{
//		printf("No existen datos cargados a mapear!\n");
//	}
//	return retorno;
//}
//Empleado* buscarIdEmpleado(LinkedList* pArrayListEmployee, int id)
//{
//	Empleado*this=NULL;
//	int i;
//	if(pArrayListEmployee!=NULL)
//	{
//		for(i=0; i<ll_len(pArrayListEmployee);i++)
//			{
//				this = ll_get(pArrayListEmployee, i);
//				if(this->id == id)
//				{
//					return this;
//				}
//			}
//	}
//	return this;
//}
