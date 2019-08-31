#include <stdio.h>
#include <stdlib.h>


#define EXIT_ERROR -1

float getFloat(float *resultado,
               char *mensaje,
               char *mensajeError);

float sumarFloat(float primerNumero, float segundoNumero,float *suma);



int main()
{
    float primerOperando;
    float segundoOperando;
    int opcionMenu;
    int flagPrimerOperando=0;
    int flagSegundoOperando=0;
    float suma;

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


        while(opcionMenu!=1 && opcionMenu!=2&&(flagPrimerOperando==0 || flagSegundoOperando==0))
        {
            if(opcionMenu==3 || opcionMenu==4)
            {
                printf("Aun no hay datos cargados. Por favor elija otra opcion del Menu \n");
                scanf("%d",&opcionMenu);
            }

            else if(opcionMenu>5)
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
        }
        if(opcionMenu==4)
        {
            printf("El resultado de A + B es: %.2f \n",&suma);
        }
    }while(opcionMenu!=5);


if(opcionMenu==5)
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


float sumarFloat(float primerNumero, float segundoNumero,float *suma)
{
    //int retorno=EXIT_SUCCESS
    *suma=primerNumero+segundoNumero;
}
