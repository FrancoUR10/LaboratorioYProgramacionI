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
    int minimoBitCoin;
    int primerBitCoin=1;
    int sumaDePesos=0;
    int contadorDePesosIngresados=0;
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
        if(tipo=='b')
        {
            if(primerBitCoin==1)
            {
                minimoBitCoin=dinero;
                primerBitCoin=0;
            }
            if(dinero < minimoBitCoin)
            {
                minimoBitCoin=dinero;
            }
        }
        if(tipo=='p')
        {
            contadorDePesosIngresados++;
            sumaDePesos+=dinero;
            if(primerPeso==1)
            {
                primerPeso=0;
            }
        }
    }
    if(primerDolar!=1)
    {
        printf("\nMayor importe en dolares: %d\n",maximoDolar);
    }
    else
    {
        printf("\nNo se han ingresado dolares\n");
    }
    if(primerBitCoin!=1)
    {
        printf("\nMenor importe en bitcoins: %d\n",minimoBitCoin);
    }
    else
    {
        printf("\nNo se han ingresado bitcoins\n");
    }
    if(primerPeso!=1)
    {
        promedioDePesos=(float)sumaDePesos/contadorDePesosIngresados;
        printf("\nPromedio de pesos: %.2f\n",promedioDePesos);
    }
    else
    {
        printf("\nNo se han ingresado pesos\n");
    }

















    return 0;
}
