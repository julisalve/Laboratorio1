/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
	{
		int i;
		int swap;
		int auxiliar;
		int seguir;
		int retorno =0;
		int limite=10;
		int array[5]={1,5,3};
		limite=limite-1;

		for(i=0;i<limite;i++)
		{
			while(seguir==0 && (array[i]>array[i+1]))
			{
				auxiliar=array[i];
				array[i]=array[i+1];
				array[i+1]=array[i];
				swap++;
				if(swap>0)
				{
					seguir=0;
				}

			}

		}
		return retorno;
	}

