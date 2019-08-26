#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#define TAM 5

int main()
{
    int dinero;
    char tipo;
    int primerDolar=1;
    int primerPeso=1;
    int maximoDolar;
    int sumaDePesos=0;
    int contador=0;
    float promedioDePesos;

    int i;
    for(i=0;i<TAM;i++)
    {
        printf("Ingrese dinero: ");
        scanf("%d",&dinero);
        fflush(stdin);
        printf("Ingrese el tipo de dinero: ");
        scanf("%c",&tipo);
        fflush(stdin);

        if(tipo=='d')
        {
            if(primerDolar==1)
            {
                maximoDolar=dinero;
                primerDolar=0;
            }
            if(dinero > maximoDolar)
            {
                maximoDolar=dinero;
            }
        }
        if(tipo=='p')
        {
            contador++;
            sumaDePesos+=dinero;
            if(primerPeso==1)
            {
                primerPeso=0;
            }
        }
    }
    promedioDePesos=(float)sumaDePesos/contador;
    if(primerDolar!=1)
    {
        printf("\nMayor importe en dolares: %d\n",maximoDolar);
    }
    else
    {
        printf("No se han ingresado dolares");
    }
    if(primerPeso!=1)
    {
        printf("Promedio de pesos: %.2f",promedioDePesos);
    }
    else
    {
        printf("No se han ingresado pesos");
    }

















    return 0;
}
