#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void mostrarArray(int parametroArray[], int cant)
{
    int indice;
    for(indice=0;indice<cant;indice++)
    {
        printf("\nNumeros: %d",parametroArray[indice]);
    }
}
void inicializarArray(int parametroArray[], int cant)
{
    int indice;
    for(indice=0;indice<cant;indice++)
    {
        parametroArray[indice]=0;
    }
}
void cargarArray(char mensaje[],int parametroArray[], int cant)
{
    int indice;
    for(indice=0;indice<cant;indice++)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%d",&parametroArray[indice]);
    }
}
int dameElMaximo(int parametroArray[],int cant)
{
    int flagPrimerValor=1;
    int maximoNumero;
    int indice;
    for(indice=0;indice<cant;indice++)
    {
        if(flagPrimerValor==1 || parametroArray[indice] > maximoNumero)
        {
            maximoNumero=parametroArray[indice];
            flagPrimerValor=0;
        }
    }
    return maximoNumero;
}
void dameElIndiceMaximo(int parametroArray[],int cant, int outArrayIndices[])
{
    int indice;
    int indiceIndex = 0;
    int maximoNumero;
    for(indice = 0;indice<cant;indice++)
    {
        outArrayIndices[indice] = -1;
    }
    maximoNumero=dameElMaximo(parametroArray,cant);
    for(indice=0;indice<cant;indice++)
    {
        if(parametroArray[indice] == maximoNumero)
        {
            outArrayIndices[indiceIndex]=indice;
            indiceIndex++;
        }
    }
}
