#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "general.h"
/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en una LinkedList de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca LinkedList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

//int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
	int opcion;
	// Definir lista de empleados
    LinkedList* listaEmpleados;
    listaEmpleados=ll_newLinkedList();

    do{
                printf("\n\nMENU\n\n");
                printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
                printf("2. Calcular el sueldo de cada empleado. \n");
                printf("3. Guardar empleados y sueldos\n");
                printf("4. Listar empleados\n");
//                printf("5. Baja de empleado\n");
//                printf("6. Listar empleados\n");
//                printf("7. Ordenar empleados\n");
//                printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
//                printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
//                printf("10. Salir\n");

                getInt(&opcion,
                		  "Elija una opcion\n",
                		  "No es una opcion valida \n",
                		  1,
                		  10,
                		  2);
       switch(opcion)
             {
       // Crear lista empledos
       // Leer empleados de archivo data.csv
       case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
       case 2:
    	   controller_ListEmployee(listaEmpleados);
    	   controller_CalcularSueldo(listaEmpleados);
    	   printf("Espere mientras se calculan los sueldos \n");
    	   controller_ListEmployee(listaEmpleados);
    	   break;
       case 3:
    	   controller_saveAsText("data.csv",listaEmpleados);
    	   break;
       case 4:
    	   controller_ListEmployee(listaEmpleados);
    	   break;
             }
    }while(opcion != 10);
}
//
//
//
//
//
//
//        // Generar archivo de salida
//        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
//        {
//            printf("Archivo generado correctamente\n");
//        }
//        else
//            printf("Error generando archivo\n");
//    }
//    else
//        printf("Error leyendo empleados\n");
//
//
//    return 0;
//}

//int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
//{
//    return 1;
//}
