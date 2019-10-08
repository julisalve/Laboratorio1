#include "Avisos.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>



/**
 * \brief Inicializa todas las posiciones del array con el estado "vacio".
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o el 0 (EXIT_SUCCESS) en caso de exito.
 *
 */

int initLugarLibreAvisos(Avisos *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
	{
		aArray[i].status=STATUS_EMPTY;
	}
		}
		return retorno;
}

/**
 * \brief Imprime un array de string, devolviendo el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int imprimirArrayAvisos(Avisos *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY)
			{
				printf("Id: %d - Status %d - ID Cliente: %d - Texto: %s - numero de rubro: %d \n",aArray[i].id,aArray[i].status,aArray[i].idCliente,aArray[i].texto,aArray[i].rubro);
			}

		}
	}
	return retorno;
}

/**\brief Remove an employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Poniter to array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (EXIT_ERROR -1) if Error [Invalid length or NULL pointer or employee not found] or (EXIT_SUCCESS 0) if OK.
 *
 */

int bajaClientePorId(Clientes *aArray, int cantidad,Avisos *aArrayAv, int cantAv, int id)
{
	int retorno =EXIT_ERROR;
	int posicionCliente= buscarClientePorId(aArray, cantidad,id);
	int posicionClienteEnAviso =buscarClientePorIdEnAviso(aArrayAv,cantAv,id);
	if(aArray != NULL && cantidad > 0 && posicionCliente >=0)
			{
				aArray[posicionCliente].status= STATUS_EMPTY;
				aArrayAv[posicionClienteEnAviso].status=STATUS_EMPTY;
				retorno=EXIT_SUCCESS;
			}
	return retorno;
}

/**
 * \brief Busca la posicion de un id ingresado por un usuario
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param id
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el id buscado
 *
 */
int buscarClientePorIdEnAviso(Avisos *aArray, int cantidad, int idPant)
{
	int retorno =EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
	{
		if(idPant==aArray[i].idCliente)
		{
			retorno = i;
			break;
		}
	}
	}
	return retorno;
}

/**
 * \brief BUsca el primer lugar libre y devuelve el fracaso o la posicion
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o la posicion del array con espacio libre, para ser utilizado
 *
 */

int buscarLugarAviso(Avisos *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int i;
	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Carga datos en un array, cambiandole el estado a NO vacio y asignandole un id irrepetible, devuelve el fracaso o el exito
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param buffer
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya lugar libre o devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int altaAviso(Avisos *aArrayAv, int cantidad, Avisos buffer)
{
	int retorno = EXIT_ERROR;
	int i;
	i = buscarLugarAviso(aArrayAv,cantidad);

		if(aArrayAv != NULL && cantidad > 0 && i!=EXIT_ERROR)
		{
			aArrayAv[i]=buffer;
			aArrayAv[i].id = generarId();
			aArrayAv[i].status = STATUS_NOT_EMPTY;
			retorno = EXIT_SUCCESS;
		}
	return retorno;

}

/**
 * \brief Genera ID irrepetiblre
 *
 * \return devuelve el numero de ID
 *
 */
static int generarId()
{
	static int contadorId=0; //es como seria global pero solo aplica para el scoup.
	contadorId++;
	return contadorId;
}

/**
 * \brief Busca las posiciones de array en las que se encuentra un dato
 * \param *aArray array que se le pasa a la funcion
 * \param cantidad tamaño del array
 * \param item dato a buscar en el array
 * \param auxArray array de enteros
 * \param cantAuxArray tamaño del array auxiliar
 * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o que no haya coincidencia entra dato buscado y dato del array devuelve 0 (EXIT_SUCCESS) en caso de exito
 *
 */
int buscarDatoIntValido(Avisos *aArray, int cantidad, int idAv, ArrayEnteros *auxArray, int cantAuxArray)
{
	int retorno= EXIT_ERROR;
	int i;
	int j=0;
	if(aArray != NULL && cantidad>0)
		{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].id==idAv)
			{
				retorno=EXIT_SUCCESS;
				auxArray[j].entero=aArray[i].idCliente;
				auxArray[j].status=STATUS_NOT_EMPTY;
				j++;
			}
		}
		}

	return retorno;
}

int imprimirArrayAvisosCoincidenteConUnDatoIngresadoPorUsuario(Avisos *aArray, int cantidad, int idAv)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY && aArray[i].id==idAv)
			{
				printf("Id: %d - Status %d - ID Cliente: %d - Texto: %s - rubro %d \n",aArray[i].id,aArray[i].status,aArray[i].idCliente,aArray[i].texto,aArray[i].rubro);
			}

		}
	}
	return retorno;
}

int buscarAvisoPorId(Avisos *aArray,int cantidad,int id)
{
	int retorno =EXIT_ERROR;
		int i;
		if(aArray != NULL && cantidad > 0)
		{
			for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status== STATUS_NOT_EMPTY && id==aArray[i].id)
			{
				retorno = i;
			}
		}
		}
		return retorno;
}

/**\brief Imprime datos de un id en particular
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param id es el id solicitado
 * \return int DEvuelve(EXIT_ERROR -1) en caso de que el array sea nulo o sea invalido el tamaño o devuelve la posicion del id en caso de exito
 *
 */
int imprimirDatosAvisoPorId(Avisos *aArray, int cantidad, int id)
{
	int retorno =EXIT_ERROR;
	int index;
	index= buscarAvisoPorId(aArray,cantidad,id);
	if(aArray != NULL && cantidad > 0)
	{
		if(index>=0)
		{

			retorno = EXIT_SUCCESS;
			printf("Id Cliente %d - Id aviso %d - Status %d - Rubro %d - texto %s:\n",aArray[index].idCliente,aArray[index].id,aArray[index].status,aArray[index].rubro,aArray[index].texto);

		}

	}

	return retorno;
}

/**\brief Modifica el dato que se desee de los campos de la estructura del srray
 *
 * \param list Employee*
 * \param len int tamaño del aray
 * \param index posicion del array
 * \return int DEvuelve(EXIT_ERROR -1) en caso de error o EXIT SUCCESS (0) en caso de exito
 *
 */
int modificacionAvisoPorIdCamposPuntuales(Avisos *aArray, int cantidad, int index, int caso)
{
	int retorno =EXIT_ERROR;
	Avisos bAviso;
	switch(caso)
	{
	case 1:
		if(getInt(&bAviso.rubro,"Ingrese el nuevo rubro \n","NO es un dato valido \n",1,1000000,2)!=0)
	{
		printf ("Error\n");
	}
		else
		{
			aArray[index].rubro=bAviso.rubro;
								retorno =EXIT_SUCCESS;

		}
		break;
	case 2:
		if(aArray[index].status==STATUS_NOT_EMPTY)
		{
			aArray[index].status=STATUS_PAUSADO;
						retorno =EXIT_SUCCESS;
						printf("status aviso %d\n" ,aArray[index].status);
		}
		else
		{
			printf("Error \n");
		}
		break;
	case 3:
	if(aArray[index].status==STATUS_PAUSADO)
			{
				aArray[index].status=STATUS_NOT_EMPTY;
							retorno =EXIT_SUCCESS;
			}
			else
			{
				printf("Error \n");
			}

break;
	}

					return retorno;
		}

int imprimirArrayAvisosPausados(Avisos *aArray, int cantidad)

{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_PAUSADO)
			{
				printf("Id: %d - Status %d - ID Cliente: %d - Texto: %s - numero de rubro: %d \n",aArray[i].id,aArray[i].status,aArray[i].idCliente,aArray[i].texto,aArray[i].rubro);
			}

		}
	}
	return retorno;
}










//
//
//
///**
// * \brief Busca la posicion de un cuit ingresado por un usuario
// * \param *aArray array que se le pasa a la funcion
// * \param cantidad tamaño del array
// * \param id
// * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el id buscado
// *
// */
//int buscarPublicidadIdPantallaPorCuit(Avisos *aArray, int cantidad, char *cuit, Avisos *aArayAux)
//{
//	int retorno =EXIT_ERROR;
//	int i;
//	int j=0;
//	if(aArray != NULL && cantidad > 0)
//	{
//		for(i=0;i<cantidad;i++)
//	{
//		if(aArray[i].status== STATUS_NOT_EMPTY && cuit==aArray[i].cuit)
//		{
//			aArayAux[j].idPantalla = aArray[i].idPantalla;
//			j++;
//			retorno=EXIT_SUCCESS;
//		}
//	}
//	}
//	return retorno;
//}
//
//
//
//
//
//
//
///**
// * \brief Busca la posicion de un id ingresado por un usuario
// * \param *aArray array que se le pasa a la funcion
// * \param cantidad tamaño del array
// * \param id
// * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o devuelve la posicion en donde se encuentra el id buscado
// *
// */
//int buscarPublicidadPorIdPantalla(Avisos*aArray, int cantidad, int id)
//{
//	int retorno =EXIT_ERROR;
//	int i;
//	if(aArray != NULL && cantidad > 0)
//	{
//		for(i=0;i<cantidad;i++)
//	{
//		if(aArray[i].status== STATUS_NOT_EMPTY && id==aArray[i].idPantalla)
//		{
//			retorno = i;
//			break;
//		}
//	}
//	}
//	return retorno;
//}
//
//
//
//
//
//
//
//
//
//
//
//int buscarPublicidadPorIdYCuit(Avisos *aArray,int cantidad,int id,char *item)
//{
//	int retorno =EXIT_ERROR;
//		int i;
//		if(aArray != NULL && cantidad > 0)
//		{
//			for(i=0;i<cantidad;i++)
//		{
//			if(aArray[i].status== STATUS_NOT_EMPTY && id==aArray[i].idPantalla && strncmp(item,aArray[i].cuit,50)==0)
//			{
//				retorno = EXIT_SUCCESS;
//			}
//		}
//		}
//		return retorno;
//}
//
//
//
//
//int buscarPublicidadPorCuit(Avisos *aArray, int cantidad, char *item, Avisos *auxPubl, int cantAux)
//{
//	int retorno= EXIT_ERROR;
//	int i;
//	int j=0;
//	cantAux=4;
//	initLugarLibrePublicidad(auxPubl,cantAux);
//	if(aArray != NULL && cantidad>0)
//	{
//		for(i=0;i<cantidad;i++)
//		{
//			if(strncmp(aArray[i].cuit,item,50)==0 && aArray[i].status==STATUS_NOT_EMPTY) //
//			{
//				retorno=EXIT_SUCCESS;
//				auxPubl[j]=aArray[i];
//				j++;
//			}
//		}
//		for(j=0;j<cantAux;j++)
//		{
//			if(auxPubl[j].status==STATUS_NOT_EMPTY)
//			{
//				printf("nombre archivo %s - dias %d\n",auxPubl[j].nombreArchivo,auxPubl[j].dias);
//			}
//		}
//	}
//	return retorno;
//}
//
//int imprimirPrecioPublicidad(Avisos *auxArray, int cantAux, Clientes *aArrayPant,int cantPant)
//{
//	int retorno= EXIT_ERROR;
//	int i;
//	int j=0;
//
//	if(auxArray != NULL && cantAux>0 && aArrayPant != NULL && cantPant>0)
//		{
//		for(i=0;i<cantPant;i++)
//		{
//			for(j=0;j<cantAux;j++)
//			{
//				if(aArrayPant[i].id==auxArray[j].idPantalla && auxArray[j].status==STATUS_NOT_EMPTY)
//							{
//								retorno=EXIT_SUCCESS;
//								auxArray[j].precioFinal=aArrayPant[i].precio*auxArray[j].dias;
//								printf("status : %d, NOmbre del archivo : %s - Cantidad de dias %d - Precio %.2f \n",auxArray[j].status,auxArray[j].nombreArchivo,auxArray[j].dias,auxArray[j].precioFinal);
//
//							}
//			}
//
//		}
//		}
//
//	return retorno;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int buscarImporteMasAltoDeFacturacion(Avisos *aArray, int cantidad)
//{
//	int retorno=EXIT_ERROR;
//	float maximoImporte;
//	char maximoCuit[50];
//	int primerPosicionOcupada= buscarLugarPublicidadLleno(aArray,cantidad);
//	int i;
//	if(aArray != NULL && cantidad > 0)
//	{
//		maximoImporte=aArray[primerPosicionOcupada].precioFinal;
//		strncpy(maximoCuit,aArray[primerPosicionOcupada].cuit,50);
//		retorno=EXIT_SUCCESS;
//		for(i=0;i<cantidad;i++)
//		{
//			if(aArray[i].precioFinal>maximoImporte && aArray[i].status==STATUS_NOT_EMPTY)
//			{
//				maximoImporte=aArray[i].precioFinal;
//				strncpy(maximoCuit,aArray[i].cuit,50);
//
//			}
//
//		}
//printf("El importe maximo a facturar es de %.2f , y el cuit del cliente es %s \n",maximoImporte,maximoCuit);
//	}
//
//	return retorno;
//}
//

//
///**
// * \brief BUsca el primer lugar lleno y devuelve el fracaso o la posicion
// * \param *aArray array que se le pasa a la funcion
// * \param cantidad tamaño del array
// * \return devuelve el -1 (EXIT_ERROR) en caso de que el array sea nulo o que su tamaño sea invalido o la primer posicion del array ocupada, para ser utilizado
// *
// */
//
//int buscarLugarPublicidadLleno(Avisos *aArray, int cantidad)
//{
//	int retorno = EXIT_ERROR;
//	int i;
//	if(aArray != NULL && cantidad > 0)
//	{
//		for(i=0;i<cantidad;i++)
//		{
//			if(aArray[i].status == STATUS_NOT_EMPTY)
//			{
//				retorno = i;
//				break;
//			}
//		}
//
//	}
//	return retorno;
//}
//
//
//
//
//
//
//
//
//int calcularPrecioPublicidadCompleto(Avisos *aArray, int cantPub, Clientes *aArrayPant,int cantPant)
//{
//	int retorno= EXIT_ERROR;
//	int i;
//	int j=0;
//
//	if(aArray != NULL && cantPub>0 && aArrayPant != NULL && cantPant>0)
//		{
//		for(i=0;i<cantPant;i++)
//		{
//			for(j=0;j<cantPub;j++)
//			{
//				if(aArrayPant[i].id==aArray[j].idPantalla && aArray[j].status==STATUS_NOT_EMPTY)
//							{
//								retorno=EXIT_SUCCESS;
//								aArray[j].precioFinal=aArrayPant[i].precio*aArray[j].dias;
//							}
//			}
//		}
//		}
//
//	return retorno;
//}
//
//
//
//
int cantidadAvisosPorCliente(Avisos *aArray, int cantidad, auxContador *aArrayCont, int cantCont, int caso)
{
	int retorno=EXIT_ERROR;
	int i;
	int j;

	initLugarLibreContador(aArrayCont,cantCont);
	if(aArray != NULL && cantidad>0 && aArrayCont != NULL && cantCont>0)
	{
		for(i=0;i<cantCont;i++)
		{
			aArrayCont[i].idCliente=aArray[i].idCliente;
			aArrayCont[i].contador =0;
		}
		switch(caso)
		{
		case 1:
			for(i=0;i<cantidad;i++)
			{
				for(j=0;j<cantidad;j++)
				{
					if(aArray[j].status == STATUS_NOT_EMPTY && aArrayCont[i].idCliente==aArray[j].idCliente)
					{
						aArrayCont[i].contador++;
						aArrayCont[i].status=STATUS_NOT_EMPTY;
					}
				}
			}
			break;
		case 2:
			for(i=0;i<cantidad;i++)
			{
				for(j=0;j<cantidad;j++)
				{
					if(aArray[j].status == STATUS_PAUSADO && aArrayCont[i].idCliente==aArray[j].idCliente)
					{
						aArrayCont[i].contador++;
						aArrayCont[i].status=STATUS_PAUSADO;}
				}
			}
			break;
		case 3:
			for(i=0;i<cantidad;i++)
			{
				for(j=0;j<cantidad;j++)
				{
					if(aArrayCont[i].idCliente==aArray[j].idCliente)
					{
						aArrayCont[i].contador++;
						//aArrayCont[i].status=STATUS_NOT_EMPTY;
					}
				}
			}
			break;

		}
		switch(caso)
		{
		case 1:
			for(i=0;i<cantCont;i++)
			{

				if(aArrayCont[i].status==STATUS_NOT_EMPTY && aArrayCont[i].idCliente==aArrayCont[i+1].idCliente)
				{
					printf("El idCliente %s tiene %d avisos activos \n",aArrayCont[i].idCliente,aArrayCont[i].contador);
				}
			}
			break;
		case 2:
			for(i=0;i<cantCont;i++)
			{

				if(aArrayCont[i].status==STATUS_PAUSADO && aArrayCont[i].idCliente==aArrayCont[i+1].idCliente)
				{
					printf("El idCliente %d tiene %d avisos pausados \n",aArrayCont[i].idCliente,aArrayCont[i].contador);
				}
			}
			break;
		case 3:
			for(i=0;i<cantCont;i++)
			{

				if(aArrayCont[i].idCliente==aArrayCont[i+1].idCliente)
				{
					printf("El idCliente %d tiene %d avisos  \n",aArrayCont[i].idCliente,aArrayCont[i].contador);
				}
			}
			break;

		}
	}
	return retorno;
}



int ordenarPorIdCliente (Avisos *aArray, int cantidad)
{
	int retorno =EXIT_ERROR;
	int i;
	Avisos bAviso;
	int j;
	 if(aArray != NULL && cantidad > 0)
	 {
		 retorno=EXIT_SUCCESS;

	for(i=0;i<cantidad;i++)
	{
		j=i;
		while (aArray[j].idCliente<aArray[j-1].idCliente && j>0) //ordena de menor a mayor
		{
							bAviso=aArray[j-1];
							aArray[j-1]=aArray[j];
							aArray[j]=bAviso;
							j--;
		}
	}

	 }

	return retorno;
}


int initLugarLibreContador(auxContador *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
	{
		aArray[i].status=STATUS_EMPTY;
	}
		}
		return retorno;
}


int imprimirArrayAvisosCompletos(Avisos *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{

				printf("Id: %d - Status %d - ID Cliente: %d - Texto: %s - numero de rubro: %d \n",aArray[i].id,aArray[i].status,aArray[i].idCliente,aArray[i].texto,aArray[i].rubro);


		}
	}
	return retorno;
}
