#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"


int sacarNumeroEntero(char mensaje[])
{
    int auxNumero;
    printf(mensaje);
    scanf("%d",&auxNumero);
    fflush(stdin);
    return auxNumero;
}
int sacarSuma(int numeroUnoSumando, int numeroDosSumando)
{
    int resultadoSuma;
    resultadoSuma=numeroUnoSumando+numeroDosSumando;
    return resultadoSuma;

}
