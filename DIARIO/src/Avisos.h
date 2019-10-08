#ifndef AVISOS_H_
#define AVISOS_H_

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define STATUS_PAUSADO 2

#include "general.h"
#include "Clientes.h"

typedef struct
		{
		int rubro;
		int id;
		int status;
		int idCliente;
		char texto[65];
		}Avisos;






		struct
		{
					int status;
					int contador;
					char cuit [50];
		}typedef auxContador;


static int generarId();
int initLugarLibrePublicidad(Avisos *aArray, int cantidad);
int buscarLugarPublicidad(Avisos *aArray, int cantidad);
int buscarPantallaPorIdEnPublicidad(Avisos *aArray, int cantidad, int idPant);
int altaPublicidad(Avisos *aArrayPub, int cantidad, Avisos buffer);
int imprimirArrayPublicidad(Avisos *aArray, int cantidad);
int buscarPublicidadPorIdPantalla(Avisos*aArray, int cantidad, int id);
int imprimirDatosPublicidadPorId(Avisos *aArray, int cantidad, int id,int caso);
int modificacionPublicidadPorIdCamposPuntuales(Avisos *aArray, int cantidad, int index, int caso);
int imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(Avisos *aArray, int cantidad, char *item);
int buscarPublicidadPorIdYCuit(Avisos *aArray,int cantidad,int id,char *item);
int buscarDatoStringValido(Avisos *aArray, int cantidad, char *item, ArrayEnteros *auxArray, int cantAuxArray);
int buscarPublicidadIdPantallaPorCuit(Avisos *aArray, int cantidad, char *cuit, Avisos *aArayAux);
int buscarPublicidadPorCuit(Avisos *aArray, int cantidad, char *item, Avisos *auxPubl, int cantAux);
int imprimirPrecioPublicidad(Avisos *auxArray, int cantAux, Pantallas *aArrayPant,int cantPant);
int buscarImporteMasAltoDeFacturacion(Avisos *aArray, int cantidad);
int buscarLugarPublicidadLleno(Avisos *aArray, int cantidad);
int calcularPrecioPublicidadCompleto(Avisos *aArray, int cantPub, Pantallas *aArrayPant,int cantPant);
int ordenarCuit (Avisos *aArray, int cantidad);
int cantidadPublicacionesPorCuit(Avisos *aArray, int cantidad, auxContador *aArrayCont, int cantCont);
int initLugarLibreContador(auxContador *aArray, int cantidad);

int bajaPantallaPorId(Pantallas *aArray, int cantidad,Avisos *aArrayPub, int cantPub, int id);
#endif /* AVISOS_H_ */
