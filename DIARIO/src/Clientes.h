#ifndef CLIENTES_H_
#define CLIENTES_H_

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

#include "general.h"

typedef struct
		{
		int id;
		int status;
		char nombre[50];
		char apellido[50];
		char cuit[50];
		}Clientes;




static int generarId();
int initLugarLibreClientes(Clientes *aArray, int cantidad);
int imprimirArrayClientes(Clientes *aArray, int cantidad);
int buscarLugarCliente(Clientes *aArray, int cantidad);
int altaClientePorId(Clientes *aArray, int cantidad,Clientes buffer);
int buscarClientePorId(Clientes *aArray, int cantidad, int id);
int imprimirDatosClientePorId(Clientes *aArray, int cantidad, int id);
int modificacionClientePorIdCamposPuntuales(Clientes *aArray, int cantidad, int index);
//int imprimirDatosEstructuraPorCoincidenciaIdConOtraEtructura(Clientes *aArray, int cantidad,ArrayEnteros *auxArray, int cantAuxArray);

#endif /* CLIENTES_H_ */
