
int controller_loadFromText(char* path , LinkedList* pArrayListCachorro);
int controller_saveAsText(char* path , LinkedList* pArrayListCachorro);
int controller_addCachorro(LinkedList* pArrayCachorro);



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

//int controller_editEmployee(LinkedList* pArrayListEmployee);
//int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListCachorro(LinkedList* pArrayListCachorro);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_filtter(LinkedList* pArrayListCachorro);
int controller_filtterMachos(LinkedList* pArrayListCachorro);
int controller_filtterCallejeros(LinkedList* pArrayListCachorro);


int buscarMaximoIdGenerado(LinkedList *pArrayListEmployee);

int controller_mapEmployee(LinkedList* pArrayListEmployee);
