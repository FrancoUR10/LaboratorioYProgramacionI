#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"

int getInt(int* valor,char mensaje[],int min,int max)
{
    int retorno=0;
    printf("%s",mensaje);
    scanf("%d",valor);
    fflush(stdin);

    while(*valor < min || *valor > max)
    {
        printf("Error\n");
        printf("%s",mensaje);
        scanf("%d",valor);
        fflush(stdin);
    }

    return retorno;
}
