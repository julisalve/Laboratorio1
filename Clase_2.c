/*
 ============================================================================
 Name        : Clase_2.c
 Author      : juliana
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 65535
int sumaEnteros(int primerValorSumar, int segundoValorSumar, int *resultado); //solo le indico que trae y que devuelve, en este caso enteros. Esto es el prototipo

int main(void)
{
	int primerValor;
	int segundoValor;
	int resultado;
	printf("Ingrese un valor \n");
	scanf("%d", &primerValor); //el ampersan pasa la direccion de memoria  del mismo scout. El ampesçrsan le da acceso total a la direccion de memoria, le paso la direccion de memoria, le da zona para escribir. Para RECIBIR EL ACCESO va *
	printf("Ingrese otro valor \n");
	scanf("%d", &segundoValor);
	if(sumaEnteros(primerValor, segundoValor, &resultado)==0)
	{
	printf("El resultado es %d \n",resultado);
	}
	else
	{
		printf("Error");
	}
}

int sumaEnteros(int primerValorSumar, int segundoValorSumar, int *resultado) // int* llama a direccion de memoria. LAS FUNCIONES, SUMAR, CALCULAR, ETC NO INTERACTUAN CON EL USUARIO
{

	int retorno =-1; //inicializo en retorno con error
	long resultadoLong;
	int resultadoInt;
	resultadoLong =primerValorSumar + segundoValorSumar;
	if (resultadoLong <= MAX_INT)
	{
		retorno =0;
		*resultado = (int)resultadoLong; //esto se llama casting, cuando queres guardar un tipo de dato en otro tipo de dato, esto es para evitar que salga el warning
	}

	return retorno; //EL VALOR DE RETORNO TIENE QEU SER SI SALIO BIEN 0 O NUMERO POSITIVO, SI SALIO MAL NUMEROS NEGATIVOS.

}

