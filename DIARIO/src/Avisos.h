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
					int idCliente;
		}typedef auxContador;


static int generarId();
int initLugarLibreAvisos(Avisos *aArray, int cantidad);
int imprimirArrayAvisos(Avisos *aArray, int cantidad);
int bajaClientePorId(Clientes *aArray, int cantidad,Avisos *aArrayAv, int cantAv, int id);
int buscarClientePorIdEnAviso(Avisos *aArray, int cantidad, int idPant);
int buscarLugarAviso(Avisos *aArray, int cantidad);
int altaAviso(Avisos *aArrayAv, int cantidad, Avisos buffer);
int buscarDatoIntValido(Avisos *aArray, int cantidad, int idAv, ArrayEnteros *auxArray, int cantAuxArray);
int imprimirDatosAvisoPorId(Avisos *aArray, int cantidad, int id);
//int imprimirArrayAvisosCoincidenteConUnDatoIngresadoPorUsuario(Avisos *aArray, int cantidad, int idAv);
//int buscarPantallaPorIdPublicidad(Avisos*aArray, int cantidad, int id);
int buscarAvisoPorId(Avisos *aArray,int cantidad,int id);
int modificacionAvisoPorIdCamposPuntuales(Avisos *aArray, int cantidad, int index, int caso);
int imprimirArrayAvisosPausados(Avisos *aArray, int cantidad);








//int buscarPublicidadPorIdYCuit(Avisos *aArray,int cantidad,int id,char *item);
//int buscarPublicidadIdPantallaPorCuit(Avisos *aArray, int cantidad, char *cuit, Avisos *aArayAux);
//int buscarPublicidadPorCuit(Avisos *aArray, int cantidad, char *item, Avisos *auxPubl, int cantAux);
//int imprimirPrecioPublicidad(Avisos *auxArray, int cantAux, Clientes *aArrayPant,int cantPant);
//int buscarImporteMasAltoDeFacturacion(Avisos *aArray, int cantidad);
//int buscarLugarPublicidadLleno(Avisos *aArray, int cantidad);
//int calcularPrecioPublicidadCompleto(Avisos *aArray, int cantPub, Clientes *aArrayPant,int cantPant);
int ordenarPorIdCliente (Avisos *aArray, int cantidad);
int cantidadAvisosPorCliente(Avisos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,int caso);
int initLugarLibreContador(auxContador *aArray, int cantidad);
int imprimirArrayAvisosCompletos(Avisos *aArray, int cantidad);




#endif /* AVISOS_H_ */
