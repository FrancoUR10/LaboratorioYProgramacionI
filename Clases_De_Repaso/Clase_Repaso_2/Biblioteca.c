#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

void saludar()
{
    printf("\nBienvenidos a las funciones!\n");
}
void sumarYMostrar(int numeroUno,int numeroDos)
{
    int suma;
    suma=numeroUno+numeroDos;
    printf("\nResultado: %d\n",suma);
}
int sumar(int numeroUno,int numeroDos)
{
    int suma;
    suma=numeroUno+numeroDos;
    saludar("\nSe realizo la suma\n");
    return suma;
}
int calcularDivision(int numeroDividendo,int numeroDivisor,float *resultadoDivision)
{
    int retorno=0;
    if(numeroDivisor != 0)
    {
        *resultadoDivision=(float)numeroDividendo/numeroDivisor;
        retorno=1;
    }
    return retorno;
}
void getString(char mensaje[],char cadena[])
{
    printf("%s",mensaje);
    gets(cadena);
}
int validarSoloNumeros(char unArray[])
{
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if(unArray[i] < '0' || unArray[i] > '9')
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int getStrNumeros(char mensaje[],char unArray[])
{
    int longitudArray;
    int retorno=0;
    char auxArray[256];
    getString(mensaje,auxArray);
    longitudArray=strlen(auxArray);
    if(longitudArray > 0 && longitudArray < 21)
    {
        if(validarSoloNumeros(auxArray))
        {
            strcpy(unArray,auxArray);
            retorno=1;
        }
    }
    return retorno;
}
