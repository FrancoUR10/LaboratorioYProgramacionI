#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void funcion(int* numero)
{
    printf("Ingrese un numero: ");
    scanf("%d",numero);
    //*numero=100;
}
unsigned int sacarFactorial(int numero)
{
    unsigned int resultado;
    if (numero == 0)
    {
        resultado=1;
    }
    else
    {
        resultado=numero*sacarFactorial(numero-1);
    }
    return resultado;
}

void factorial(int numero)
{
    unsigned int resultadoFactorial=1;
    int i;
    for(i=numero;i>=1;i--)
    {
        resultadoFactorial=resultadoFactorial*i;
    }
    if(numero >= 0)
    {
        printf("\nEl factorial de %d es: %d\n",numero,resultadoFactorial);
    }
    else
    {
        printf("\nEl factorial de %d no existe\n",numero);
    }
}
