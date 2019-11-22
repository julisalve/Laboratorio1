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



int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
	Cachorro *pCachorro;
	int i;
	if(pArrayListCachorro!=NULL && ll_len(pArrayListCachorro)>0)
	{
		for(i=0; i<ll_len(pArrayListCachorro); i++)
		{
			pCachorro = ll_get(pArrayListCachorro, i);
			printf("%4d %15s %5d %12s %3s %3s\n", pCachorro->id, pCachorro->nombre, pCachorro->dias, pCachorro->raza, pCachorro->reservado, pCachorro->genero);
		}
	}
	else
	{
		printf("No hay datos cargados para ser listados \n");
	}
	return 1;
}



int controller_filtter(LinkedList* pArrayListCachorro)
{
int retorno =-1;
LinkedList*listaFiltrada;
if(pArrayListCachorro!=NULL)
{
		listaFiltrada=ll_filter(pArrayListCachorro, Cachorro_pFuncMenos45Dias);
	retorno = 0;
	controller_ListCachorro(listaFiltrada);
}
return retorno;
}


int controller_filtterMachos(LinkedList* pArrayListCachorro)
{
int retorno =-1;
//LinkedList* nuevaLista=NULL;
//nuevaLista=ll_newLinkedList();
if(pArrayListCachorro!=NULL)
{
	//nuevaLista=
	ll_filter(pArrayListCachorro, Cachorro_pFuncMachos);
	return 0;
	//controller_ListCachorro(nuevaLista);
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
