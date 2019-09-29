/*
 ============================================================================
 Name        : case.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int opcion;
	int flag=0;
	printf("opcion:");
	scanf("%d",&opcion);

	switch(opcion)
	{
	case 1:
		flag=1;
		break;
	case 2:
	case 3:
if(flag!=1)
{
	printf("error");
}
else
	{case 1:
		printf("ok case 2");
		break;
	case 2:
		printf("ok case 3");
		break;
	}

	return EXIT_SUCCESS;
}
