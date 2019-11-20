#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);

Empleado* employee_new();
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete(Empleado *this);

int employee_setId(Empleado* this,int id);
int employee_getId(Empleado* this,int* id);

int employee_setNombre(Empleado* this,char* nombre);
int employee_getNombre(Empleado* this,char* nombre);

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int employee_setSueldo(Empleado* this,int sueldo);
int employee_getSueldo(Empleado* this,int* sueldo);



int employee_sortPorId( void * datoUno, void *datoDos);
int employee_sortPorNombre( void * datoUno, void *datoDos);
int employee_sortPorHorasTrabajadas( void * datoUno, void *datoDos);
int employee_sortPorSueldo( void * datoUno, void *datoDos);


void Employee_pFuncMapSueldo(void* empleado);
#endif // EMPLEADO_H_INCLUDED
