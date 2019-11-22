/*
 ============================================================================
 Name        : 2DO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "cachorros.h"
#include "LinkedList.h"
#include "Parser.h"
#include "general.h"
#include "Controller.h"

int main()
{
	int opcion;

    LinkedList* listaCachorros;
    listaCachorros=ll_newLinkedList();
    char nombreArc[128];


    do{
                printf("\n\nMENU\n\n");
                printf("1. Cargar archivo cachorros.csv (modo texto). \n");
                printf("2. Agregar cachorro\n");
                printf("3. Listar cachorros\n");
                printf("4. Filtrar cachorros menores de 45 dias\n");
                printf("5. Filtrar machos\n");
                printf("6. Listado callejeros\n");
                printf("7. Guardar los datos de los cachorros en el archivo data.csv (modo texto).\n");
                printf("8. Salir\n");

                getInt(&opcion,
                		  "Elija una opcion\n",
                		  "No es una opcion valida \n",
                		  1,
                		  8,
                		  2);
       switch(opcion)
             {
       	   	   case 1:
       	   		   getString(nombreArc,"Ingrese archivo a abrir\n","no es valido \n",1,127,2);
              		controller_loadFromText(nombreArc,listaCachorros);
              		break;
                  case 2:
                	  controller_addCachorro(listaCachorros);
                     break;
                  case 3:
                	  controller_ListCachorro(listaCachorros);
                      break;
                  case 4:
                      controller_filtter(listaCachorros);
                       break;
                  case 5:
                	  controller_filtterMachos(listaCachorros);
                      break;
                  case 6:
                	  controller_filtterCallejeros(listaCachorros);
                      break;
                  case 7:
                      controller_saveAsText("cachorros.csv",listaCachorros);
                      break;
                  case 8:
                  	ll_deleteLinkedList(listaCachorros);
                  	printf("Aplicacion cerrada \n");
                      break;
                }
          }while(opcion != 8);

      }

