#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void funcion(int* numero)
{
    printf("Ingrese un numero: ");
    scanf("%d",numero);
    //*numero=100;
}
unsigned int factorial(int numero)
{
    unsigned int resultado;
    if (numero == 0)
    {
        resultado=1;
    }
    else
    {
        resultado=numero*factorial(numero-1);
    }
    return resultado;
}
