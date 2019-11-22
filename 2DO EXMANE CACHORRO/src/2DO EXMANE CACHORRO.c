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
//    LinkedList* listaFiltrada;


    do{
                printf("\n\nMENU\n\n");
                printf("1. Cargar archivo cachorros.csv (modo texto). \n");
                printf("2. Agregar cachorro\n");
                printf("3. Listar cachorros\n");
                printf("4. Filtrar cachorros menores de 45 dias\n");
                printf("5. Filtrar machos\n");
                printf("6. Listado callejeros\n");
                printf("7. Guardar los datos de los cachorros en el archivo data.csv (modo texto).\n");
                //printf("9. Guardar los datos de los cachorros en el archivo data.bin (modo binario).\n");
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
              		controller_loadFromText("data.csv",listaCachorros);
              		break;
                  case 2:
                	  controller_addCachorro(listaCachorros);
                	  //  controller_loadFromBinary("data.bin", listaCachorros);// incompleto
                      break;
                  case 3:
                	  controller_ListCachorro(listaCachorros);
                      break;
                  case 4:
//                      controller_editEmployee(listaCachorros);
                      controller_filtter(listaCachorros);
                       break;
                  case 5:
                	  controller_filtterMachos(listaCachorros);
//                      controller_removeEmployee(listaCachorros);
                      break;
                  case 6:
                	  controller_filtterCallejeros(listaCachorros);
                      break;
//                  case 7:
//                      controller_sortEmployee(listaCachorros);
//                      break;
//                  case 8:
                      controller_saveAsText("data.csv",listaCachorros);
                      break;
//                  case 9:
//                      controller_saveAsBinary("data.bin",listaCachorros);
                      break;
                  case 10:
                  	ll_deleteLinkedList(listaCachorros);
                  	printf("Aplicacion cerrada \n");
                      break;

                }
          }while(opcion != 10);

      }

