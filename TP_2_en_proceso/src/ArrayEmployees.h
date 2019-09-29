/*
 * Empleados.h
 *
 *  Created on: 17 sep. 2019
 *      Author: alumno
 */
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


#define TRUE 1
#define FALSE 0
#define EXIT_ERROR -1
#define EXIT_SUCCESS 0

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;


//static int generarId();
int initEmployees(Employee *list, int len);
int addEmployee(Employee *list, int len,int id, char name [], char lastName [], float salary, int sector);
int findFirstEmptyPosition(Employee *list, int len);
int findEmployeeById(Employee *list, int len, int id);
int removeEmployee(Employee *list, int len,int id);
int imprimirArrayEmpleados(Employee*list, int len);
int imprimirDatosEmpleadoPorId(Employee *list, int len, int id);
int modificacionEmpleadoPorIdCamposPuntuales(Employee *list, int len, int index);
//int ordenarArrayEmpleadosPorApellidoYSector(Employee *list, int len);
float sumaSalariosYPromedio(Employee *list,int len,float *suma, int *contadorIsEmptyFalso);
int cantidadEmpleadosQueSuperanPromedioSalario(Employee *list,int len,float promedio);
int sortEmployees(Employee *list, int len, int order);
int sortEmployeesUp(Employee *list, int len);
int sortEmployeesDown(Employee *list, int len);

int getNombre(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
int getApellido(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
float getFloat(float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos);
int getInt(int *resultado,
		  char *mensaje,
		  char *mensajeError,
		  int minimo,
		  int maximo,
		  int reintentos);
int getString(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);
char getChar (char *resultadoChar,
			  char *mensajeChar,
			  char *mensajeErrorChar,
			  char minimo,
			  char maximo,
			  int reintentos);

int esLetra(char *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);
int esSiONo(char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos);



int imprimirArrayEmpleadosCompleto(Employee*list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
