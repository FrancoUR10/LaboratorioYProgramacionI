#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    char array[50];
    if(!getStrLetras("Ingrese letras: ",array))
    {
        printf("No se acepta\n");
    }
    return 0;
}
