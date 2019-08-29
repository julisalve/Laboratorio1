/*
 ============================================================================
 Name        : clase4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void)
{
//	saludarAlUsuario();
	int resultado;
	if(getIn(&resultado, "Edad \n", "Error \n", 0,150,2)==0)
	{
	printf("El resultado es: %d", resultado);

	}
	return EXIT_SUCCESS;
}



