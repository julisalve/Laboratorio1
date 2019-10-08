#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

#include "general.h"
#include "Pantallas.h"

typedef struct
		{

	float precioFinal;
	int dias;
			char cuit [50];
		int id;
		int status;
		int idPantalla;
		char nombreArchivo[50];



		}Publicidades;


		struct
		{
					int status;
					int contador;
					char cuit [50];
		}typedef auxContador;


static int generarId();
int initLugarLibrePublicidad(Publicidades *aArray, int cantidad);
int buscarLugarPublicidad(Publicidades *aArray, int cantidad);
int buscarPantallaPorIdEnPublicidad(Publicidades *aArray, int cantidad, int idPant);
int altaPublicidad(Publicidades *aArrayPub, int cantidad, Publicidades buffer);
int imprimirArrayPublicidad(Publicidades *aArray, int cantidad);
int buscarPublicidadPorIdPantalla(Publicidades*aArray, int cantidad, int id);
int imprimirDatosPublicidadPorId(Publicidades *aArray, int cantidad, int id,int caso);
int modificacionPublicidadPorIdCamposPuntuales(Publicidades *aArray, int cantidad, int index, int caso);
int imprimirArrayPublicidadCoincidenteConUnDatoIngresadoPorUsuario(Publicidades *aArray, int cantidad, char *item);
int buscarPublicidadPorIdYCuit(Publicidades *aArray,int cantidad,int id,char *item);
int buscarDatoStringValido(Publicidades *aArray, int cantidad, char *item, ArrayEnteros *auxArray, int cantAuxArray);
int buscarPublicidadIdPantallaPorCuit(Publicidades *aArray, int cantidad, char *cuit, Publicidades *aArayAux);
int buscarPublicidadPorCuit(Publicidades *aArray, int cantidad, char *item, Publicidades *auxPubl, int cantAux);
int imprimirPrecioPublicidad(Publicidades *auxArray, int cantAux, Pantallas *aArrayPant,int cantPant);
int buscarImporteMasAltoDeFacturacion(Publicidades *aArray, int cantidad);
int buscarLugarPublicidadLleno(Publicidades *aArray, int cantidad);
int calcularPrecioPublicidadCompleto(Publicidades *aArray, int cantPub, Pantallas *aArrayPant,int cantPant);
int ordenarCuit (Publicidades *aArray, int cantidad);
int cantidadPublicacionesPorCuit(Publicidades *aArray, int cantidad, auxContador *aArrayCont, int cantCont);
int initLugarLibreContador(auxContador *aArray, int cantidad);
int bajaPantallaPorId(Pantallas *aArray, int cantidad,Publicidades *aArrayPub, int cantPub, int id);
#endif /* PUBLICIDAD_H_ */
