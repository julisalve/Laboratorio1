#ifndef INFORMES_H_
#define INFORMES_H_

#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000
#include "general.h"
#include "Clientes.h"
#include "Pedidos.h"

int menuInformes(Pedidos *aArrayPed, int cantPed, Clientes *aArrayClientes, int cantClientes);
int buscarPrimerLugarPedidoCompletoProcesado(Pedidos *aArray, int cantidad);
int buscarPedidoConMasDesechos(Pedidos *aArray, int cantidad);
int buscarCuitConMasDesechos (Clientes *aArrayClientes, int cantClientes, Pedidos *aArrayPedidos, int cantPed);
int sumaTotalesDeDesechos(Pedidos *aArrayPed, int cantPed);


#endif /* INFORMES_H_ */
