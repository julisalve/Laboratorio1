#include <stdio.h>
#include <stdlib.h>


#define EXIT_ERROR -1

float getFloat(float *resultado,
               char *mensaje,
               char *mensajeError);

int sumarFloat(float primerNumero, float segundoNumero,float *suma);
int restarFloat(float primerNumero, float segundoNumero,float *resta);
int dividirFloat(float primerNumero, float segundoNumero,float *division);
int multiplicarFloat(float primerNumero, float segundoNumero,float *multiplicacion);
int factorialDeFloat(float primerNumero, float segundoNumero,float *factorialPrimerNumero, float *factorialSegundoNumero);

int main()
{
    float primerOperando;
    float segundoOperando;
    int opcionMenu;
    int flagPrimerOperando=0;
    int flagSegundoOperando=0;
    int flagCalculosRealizados=0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorialPrimerNumero;
    float factorialSegundoNumero;

    do
    {
        system("cls");
        printf ("MENU \n\n");
        printf("1. Ingresar 1er operando (A=%.2f)\n",primerOperando);
        printf("2. Ingresar 2do operando (B=%.2f)\n",segundoOperando);
        printf("3. Calcular todas las operaciones.\n");
        printf("a) Calcular la suma \n");
        printf("b) Calcular la resta \n");
        printf("c) Calcular la division \n");
        printf("d) Calcular la multiplicacion \n");
        printf("e) Calcular el factorial \n");
        printf("4.Informar resultados \n");
        printf("5. Salir \n \n");
        printf("Ingrese una opcion del MENU \n");
        scanf("%d",&opcionMenu);


        while(opcionMenu!=1 && opcionMenu!=2 && opcionMenu!=5 && (flagPrimerOperando==0 || flagSegundoOperando==0))
        {
            if(opcionMenu==3 || opcionMenu==4)
            {
                printf("Aun no hay datos cargados. Por favor elija otra opcion del Menu \n");
                scanf("%d",&opcionMenu);
            }

            else if(opcionMenu>5 || opcionMenu<1)
            {
                printf("No es una opcion valida del Menu. Reingrese otra opcion. \n");
                scanf("%d",&opcionMenu);
            }
        }
        if(opcionMenu==1)
        {
            getFloat(&primerOperando,
                     "Ingrese el primer operando \n",
                     "No es un numero valido. Error. \n");
            flagPrimerOperando=1;
        }
        if(opcionMenu==2)
        {
            getFloat(&segundoOperando,
                     "Ingrese el segundo operando \n",
                     "No es un numero valido. Error. \n");
            flagSegundoOperando=1;
        }

//    while(flagPrimerOperando!=0 && flagSegundoOperando!=0)
//    {
        if(opcionMenu==3)
        {
            sumarFloat(primerOperando, segundoOperando,&suma);
            restarFloat(primerOperando,segundoOperando,&resta);
            dividirFloat(primerOperando, segundoOperando,&division);
            multiplicarFloat(primerOperando, segundoOperando,&multiplicacion);
            factorialDeFloat(primerOperando, segundoOperando,&factorialPrimerNumero, &factorialSegundoNumero);
            printf("Calculos realizados con exitos. \n \n");
            system("pause");
            flagCalculosRealizados=1;
        }
        if(opcionMenu==4 && flagCalculosRealizados==1)
        {
            printf("El resultado de A + B es: %.2f \n",suma);
            printf("El resultado de A - B es: %.2f \n",resta);
            if(dividirFloat(primerOperando, segundoOperando,&division)==0)
            {
                    printf("El resultado de A/B es: %.2f \n",division);
            }
            else
            {
                printf("No es posible dividir por cero. \n");
            }
            printf("El resultado de A * B es: %.2f \n",multiplicacion);
            printf("El factorial de %.2f es: %.2f y el factorial de %.2f es: %.2f\n",primerOperando,factorialPrimerNumero,segundoOperando,factorialSegundoNumero);
            system("pause");
        }
        else if(opcionMenu==4 && flagCalculosRealizados==0)
        {
            printf("Error. Primero debe realizar los calculos. \n");
            system("pause");
        }
    }
    while(opcionMenu!=5);


    if(opcionMenu==5) //si pongo 1er operando, 2 do y luego salgo ok printf. Si pongo mal las opciones primero y quiero salir no me toma el pritf.
    {
        printf("Calculadora apagada \n");
    }

    return 0;
}



float getFloat(float *resultado,
               char *mensaje,
               char *mensajeError)
{
    int retorno= EXIT_ERROR;
    float buffer;
    while(resultado != NULL &&
            mensaje != NULL &&
            mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin); //__fpurge. REEMPLAZAR EN LINUX
        if(scanf("%f",&buffer)==1)
        {
            retorno =EXIT_SUCCESS;
            *resultado=buffer;
            break;
        }
        printf("%s",mensajeError);
    }


    return retorno;
}


int sumarFloat(float primerNumero, float segundoNumero,float *suma)
{
    int retorno=EXIT_SUCCESS;
    *suma=primerNumero+segundoNumero;//no entienod el warning.
    return retorno;
}

int restarFloat(float primerNumero, float segundoNumero,float *resta)
{
    int retorno=EXIT_SUCCESS;
    *resta=primerNumero-segundoNumero;//no entienod el warning.
    return retorno;
}

int dividirFloat(float primerNumero, float segundoNumero,float *division)
{
    int retorno = EXIT_ERROR;

    if(segundoNumero!=0)
    {
        retorno=EXIT_SUCCESS;
        *division=primerNumero/segundoNumero;

    }
    return retorno;


}

int multiplicarFloat(float primerNumero, float segundoNumero,float *multiplicacion)
{
    int retorno = EXIT_SUCCESS;
    *multiplicacion=primerNumero*segundoNumero;
    return retorno;

}

int factorialDeFloat(float primerNumero, float segundoNumero,float *factorialPrimerNumero, float *factorialSegundoNumero)
{
    int retorno= EXIT_SUCCESS;
    int i;
    int j;
    if (primerNumero<0)
    {
        primerNumero=primerNumero*(-1);

    }
    if(segundoNumero<0)
    {
        segundoNumero=segundoNumero*(-1);
    }
    *factorialPrimerNumero=1;
    *factorialSegundoNumero=1;
    for(i=1; i<=primerNumero; i++)
    {
        *factorialPrimerNumero=*factorialPrimerNumero*i;
    }
    for(j=1; j<=segundoNumero; j++)
    {
        *factorialSegundoNumero=*factorialSegundoNumero*j;
    }
    return retorno;
}
