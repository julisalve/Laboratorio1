///*
// ============================================================================
// Name        : practica.c
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
// ============================================================================
// */
//
#include <stdio.h>
#include <stdlib.h>
//
//
//
//int main(void)
//{
//int *a;
//int *aAux;
//	int i;
//		a=malloc(sizeof(int)*5);
//		if(a==NULL)
//		{
//			printf("NO hay lugar \n");
//		}
//		else
//		{
//	for(i=0;i<5;i++)
//	{

//			*(a+i)=i+1;
//		}
////		printf("vector %d \n",*(a+i));
////	}
//aAux=realloc(a,sizeof(int)*10);
//if(aAux==NULL)
//{
//	printf("NO hay lugar \n");
//}
//else
//{
//	a=aAux;
//}
//for(i=5;i<10;i++)
//{
//	*(a+i)=i+1;
//	printf("vector %d \n",*(a+i));
//}
// free(a)
//return EXIT_SUCCESS;
//}
//
//
//
//typedef struct
//{
//	int codigo;
//	char marca[20];
//	char modelo[20];
//	int capacidad;
//}ePendrive;
//

//
//int guardarEnArchivoBinario(ePendrive* ,char *path)
//{
//FILE *pFileBin =NULL;
//ePendrive* pPenDrive;
//int i;
//pFileBin=fopen(path,"wb");
//if(pFileBin!=NULL && pPenDrive!=NULL)
//{
//	for(i=0;i<ll_len())
//}
//
//
//}


int main()
{
int x;
int *pEntero =NULL;
int *pEnt2;

x=7;
pEntero=&x;
pEnt2=&x;

//*pEntero=7;
printf("  %d\n",x);
printf(" pEntero %d\n",*pEntero);
printf(" &x %p\n",&x);
printf(" pEntero %p\n",pEntero);
printf(" &pEntero %p\n",&pEntero);

*pEntero=x;


printf("  %d\n",x);
printf(" pEntero %d\n",*pEntero);
printf(" &x %p\n",&x);
printf(" pEntero %p\n",pEntero);
printf(" &pEntero %p\n",&pEntero);
//
//int vector[5];
//pEntero=vector;
//printf("%d",vector);

}
