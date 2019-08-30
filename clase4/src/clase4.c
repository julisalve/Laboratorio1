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
	float resultadoFloat;
	char resultadoChar;


	if(getIn(&resultado, "Edad \n", "Error \n", 0,150,2)==0)
	{
	printf("El resultado es: %d \n", resultado);

	}
	if(getFloat(&resultadoFloat,"Kilos \n","Error \n",0.01,99.99,2)==0)
	{
		printf("El resultado es: %.2f \n",resultadoFloat);
	}

	if(getChar(&resultadoChar,"Ingrese una letra \n","Error \n",'b','y',2)==0)
	{
		printf("El resultado es: %c \n",resultadoChar);
	}





		return EXIT_SUCCESS;
}



