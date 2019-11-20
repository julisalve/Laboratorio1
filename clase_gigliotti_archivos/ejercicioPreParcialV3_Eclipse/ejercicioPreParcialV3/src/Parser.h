#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_CalcularSueldo(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
Empleado* buscarIdEmpleado(LinkedList* pArrayListEmployee, int id);
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
#endif // PARSER_H_INCLUDED
