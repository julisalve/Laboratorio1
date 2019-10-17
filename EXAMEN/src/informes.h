#ifndef INFORMES_H_
#define INFORMES_H_

#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000
#include "general.h"
#include "Clientes.h"
#include "Pedidos.h"

int menuInformes(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes, auxContador *aArrayCont, int cantCont);
int buscarPrimerLugarPedidoCompletoProcesado(Pedidos *aArray, int cantidad);
int buscarPedidoConMasDesechos(Pedidos *aArray, int cantidad);
int buscarCuitConMasDesechos (Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPedidos, int cantPed);
float sumaTotalesDeDesechos(Pedidos *aArrayPed, int cantPed, float *acumulador);
float sumaTotalesDeResiduosPorTipo(Pedidos *aArrayPed, int cantPed, int opcion, float *acumulador);
float cantidadKilosPorTipoPorCuit(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes, int opcion);
int imprimirCantidadKilosPorTipoPorPorCuit(auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes, int opcion);
float sumaTotalesDeResiduosPorIdClienteIngresado(Pedidos *aArrayPed, int cantPed, int opcion,float *acumulador, int id);
float promedioDeDesechos(Pedidos *aArrayPed, int cantPed);
int ordenarPorLocalidadCliente (Clientes *aArray, int cantidad);
float cantidadKilosPorTipoPorLocalidad(Pedidos *aArray, int cantidad, auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes, int opcion);
int imprimirCantidadKilosPorTipoPorPorLocalidad(auxContador *aArrayCont, int cantCont,Clientes *aArrayClientes, int cantClientes, int opcion);

#endif /* INFORMES_H_ */
