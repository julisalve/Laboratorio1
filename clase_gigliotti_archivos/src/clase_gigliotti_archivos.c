
#include <stdio.h>
#include <stdlib.h>
#include "CLIENTES.h"


int main(void)
{
	Cliente *listaClientes[1000];//array de punteros
	int posicion=0;
	int i;

	for(i=0;i<1000;i++)
		{
		listaClientes[i]=NULL;
		}

	FILE *pFile;
	int r;
	char var1[50],var3[50],var2[50],var4[50], var5[50];
	pFile = fopen("clientes.txt","r");
	if(pFile == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
		if(r==5)
			{
			printf("Lei: %s %s %s %s %s \n",var1,var2,var3,var4,var5);
			//hace run new para generar un cliente
			// cargar los campos con lso datos
			//guardar la direcion en el array( lista)
			int id=atoi(var1);
			Cliente *pCliente = new_Cliente_Parametros(var2,var4,var5,var3,var1);
			if(pCliente!=NULL)
			{
				listaClientes[posicion] = pCliente;
				posicion++;
				if(posicion>=100)
					break;
			}
			}
		else
			break;
	}while(!feof(pFile));
	fclose(pFile);
	exit(EXIT_SUCCESS);
}

//int main(void)
//{
//	FILE *pFile;
//	int r;
//	char var1[50],var3[50],var2[50],var4[50];
//	pFile = fopen("hola.txt","r");
//	if(pFile == NULL)
//	{
//		printf("El archivo no existe");
//		exit(EXIT_FAILURE);
//	}
//	do
//	{
//		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
//		if(r==4)
//			printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
//		else
//			break;
//	}while(!feof(pFile));
//	fclose(pFile);
//	exit(EXIT_SUCCESS);
//}
