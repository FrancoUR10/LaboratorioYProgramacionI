#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define CANTIDAD 3

int main()
{
    int miArray[CANTIDAD];
    int elMaximo;
    int indiceMaximo[CANTIDAD];

    inicializarArray(miArray,CANTIDAD);
    cargarArray("Ingrese numeros: ",miArray,CANTIDAD);
    mostrarArray(miArray,CANTIDAD);

    elMaximo=dameElMaximo(miArray,CANTIDAD);
    printf("\nEl maximo: %d",elMaximo);

    dameElIndiceMaximo(miArray,CANTIDAD,indiceMaximo);
    int i = 0;
    for( ; i<CANTIDAD;i++)
    {
        if(indiceMaximo[i] != -1)
        {
            printf("\nIndice del valor maximo: %d",indiceMaximo[i]);
        }
    }









    return 0;
}
