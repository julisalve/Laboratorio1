#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

//int controller_CalcularSueldo(LinkedList* pArrayListEmployee);
//int controller_ListCachorro(LinkedList* pArrayListCachorro);
Cachorro* buscarIdCachorro(LinkedList* pArrayListCachorro, int id);
int parser_cachorroFromText(FILE* pFile , LinkedList* pArrayListCachorro);
#endif // PARSER_H_INCLUDED
