#ifndef PEDIDOS_H_
#define PEDIDOS_H_

typedef struct
{
	int id;
	int status;
	int idCliente;
	float kilosTotales;
	float kilosTipo_1;
	float kilosTipo_2;
	float kilosTipo_3;
}Pedido;

Pedido* new_Pedido();
Pedido new_Pedido_Parametros( float kilosTotales, float kilosTipo_1,float kilosTipo_2,float kilosTipo_3);
void delete_Pedidos(Pedido* this);
int ped_setKilosTotales(Pedido * this,float kilosTotales);
int ped_getKilosTotales(Pedido *this, float *kilosTotales);
int ped_setKilosTipo_1(Pedido * this,float kilosTipo_1);
int ped_getKilosTipo_1(Pedido *this, float *kilosTipo_1);
int ped_setKilosTipo_2(Pedido * this,float kilosTipo_2);
int ped_getKilosTipo_2(Pedido *this, float *kilosTipo_2);
int ped_setKilosTipo_3(Pedido * this,float kilosTipo_3);
int ped_getKilosTipo_3(Pedido *this, float *kilosTipo_3);

#endif /* PEDIDOS_H_ */
