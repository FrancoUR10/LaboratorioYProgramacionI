#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    printf("Ejemplos de arrays\n");

    //int numeroUno,numeroDos,........,numeroDiez == int arrayNumeros[10];
    int arrayNumeros[10]={8,7,1,3,-8,9,9,-7,10,5}; //Hardcodear datos
    int acumuladorNumerosPositivos=0;
    int contadorNumerosPositivos=0;
    int flagPrimerValor=1;
    int maximo;
    int posicionMaximoValor;
    int minimo;
    int posicionMinimoValor;
    float promedioDeNumerosPositivos;

    //numero=0;
    int i;
    /*
    //Inicializar datos
    for(i=0;i<10;i++)
    {
        arrayNumeros[i]=0;
    }
    */
    /*
    //Pedir datos
    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&arrayNumeros[i]);
        fflush(stdin);
    }
    */
    // Mostrar datos
    for(i=0;i<10;i++)
    {
        printf("%d\n",arrayNumeros[i]);
    }
    printf("Solo negativos:\n");
    for(i=0;i<10;i++)
    {
        if(arrayNumeros[i] < 0)
        {
            printf("%d\n",arrayNumeros[i]);
        }
    }
    printf("Promedio de numeros positivos:\n");
    for(i=0;i<10;i++)
    {
        if(arrayNumeros[i] > 0)
        {
            acumuladorNumerosPositivos+=arrayNumeros[i];
            contadorNumerosPositivos++;
        }
    }

    promedioDeNumerosPositivos=(float)acumuladorNumerosPositivos/contadorNumerosPositivos; //Casteo de datos int a float
    printf("%.2f",promedioDeNumerosPositivos);

    printf("\nMaximo y minimo valor:\n");

    for(i=0;i<10;i++)
    {
        if(flagPrimerValor==1)
        {
            maximo=arrayNumeros[i];
            minimo=arrayNumeros[i];
            posicionMaximoValor=i+1;
            posicionMinimoValor=i+1;
            flagPrimerValor=0;
        }
        if(arrayNumeros[i] > maximo)
        {
            maximo=arrayNumeros[i];
            posicionMaximoValor=i+1;
        }
        if(arrayNumeros[i] < minimo)
        {
            minimo=arrayNumeros[i];
            posicionMinimoValor=i+1;
        }
    }
    printf("Maximo: %d En posicion: %d\nMinimo: %d En posicion: %d\n",maximo,posicionMaximoValor,minimo,posicionMinimoValor);










    return 0;
}
