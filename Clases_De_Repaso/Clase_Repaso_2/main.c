#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

int main()
{
    char arrayNumeros[50];
    saludar();
    int numeroUno=2;
    int numeroDos=2;
    int resultadoDeLaSuma;
    sumarYMostrar(numeroUno,numeroDos);
    resultadoDeLaSuma=sumar(333,222);

    float division;
    printf("\nResultado es: %d\n",resultadoDeLaSuma);

    if(calcularDivision(5,2,&division))
    {
        printf("\nSe realizo la operacion\nResultado operacion: %.2f\n",division);
    }
    else
    {
        printf("\nNo se realizo la operacion\n");
    }

    if(getStrNumeros("Ingrese solo numeros: ",arrayNumeros))
    {
        printf("\nSe ingresaron solo numeros: %s\n",arrayNumeros);
    }
    else
    {
        printf("\nDatos ingresados no validos\n");
    }










    return 0;
}
