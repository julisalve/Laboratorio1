#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 65535
#define MAX_LONG 4294967295

int esNumeroInt (long *numeroLong, int *numeroInt);
int calcularNumeroMaximo (int numero, int *numeroMaximo, int *contador);
int calcularNumeroMinimo (int numero, int *numeroMinimo, int *contador);

int main(void)
{
    int respuesta;
    int numeroInt;
    long numeroLongIngresado;
    int numeroMaximo;
    int numeroMinimo;
    int contadorMaximo=0;
    int contadorMinimo=0;



    do
    {

        printf("Indique un numero \n");
        scanf("%ld", &numeroLongIngresado);

        if(esNumeroInt (&numeroLongIngresado, &numeroInt)==0)
        {
            printf("Desea ingresar otro numero? Presione 0 para continuar \n");
            scanf("%d",&respuesta);
        }
        else
        {
            printf("Error, ingrese otro numero");
            scanf("%ld", &numeroLongIngresado);
        }

        if(calcularNumeroMaximo(numeroInt,&numeroMaximo,&contadorMaximo)==0)
        {

        }

        if(calcularNumeroMinimo(numeroInt,&numeroMinimo,&contadorMinimo)==0)
        {

        }



    }

    while(respuesta==0);

    printf("El numero maximo es: %d \n",numeroMaximo);
    printf("El numero minimo es: %d \n",numeroMinimo);
    //printf("El promedio es: %d \n", promedio);



}



int esNumeroInt (long *numeroLong, int *numeroInt)
{
    int retorno;


    if (*numeroLong<=MAX_INT)
    {
        retorno=0;
        *numeroInt=(int)*numeroLong;

    }

    else if(*numeroLong>MAX_INT)
    {
        retorno=-1;
    }

    else if(*numeroLong>MAX_LONG)
    {
        retorno=-1;
    }

    return retorno;
}





int calcularNumeroMaximo (int numero, int *numeroMaximo, int *contador)
{
    int retorno=-1;

    if ((*contador)==0 || numero>*numeroMaximo)
    {
        retorno=0;
        *numeroMaximo=numero;

    }

    *contador=1;

    return retorno;
}


int calcularNumeroMinimo (int numero, int *numeroMinimo, int *contador)
{
    int retorno=-1;

    if ((*contador)==0 || numero<*numeroMinimo)
    {
        retorno=0;
        *numeroMinimo=numero;

    }

    *contador=1;

    return retorno;
}



//int calcularPromedio (int )
