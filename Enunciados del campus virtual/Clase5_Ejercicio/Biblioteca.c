#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int getInt(char mensaje[])
{
    int aux;
    printf(mensaje);
    scanf("%d",&aux);
    fflush(stdin);
    return aux;
}
