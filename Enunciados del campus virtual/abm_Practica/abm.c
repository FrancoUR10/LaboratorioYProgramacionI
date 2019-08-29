#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"

int getInt(char mensaje[])
{
    int auxInt;
    printf(mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
float getFloat(char mensaje[])
{
    float auxFloat;
    printf(mensaje);
    scanf("%f",&auxFloat);
    fflush(stdin);
    return auxFloat;
}
char getChar(char mensaje[])
{
    char auxChar;
    printf(mensaje);
    scanf("%c",&auxChar);
    fflush(stdin);
    return auxChar;
}
void getString(char mensaje[],char cadena[])
{
    printf(mensaje);
    gets(cadena);
}
int validarSoloNumeros(char cadena[])
{
    int retorno=1;
    int i=0;
    while(cadena[i] != '\0')
    {
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int validarSoloLetras(char cadena[])
{
    int retorno=1;
    int i=0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int getStringNumeros(char mensaje[],char cadena[])
{
    int retorno=0;
    char auxCadena[50];
    getString(mensaje,auxCadena);
    if(validarSoloNumeros(auxCadena))
    {
        strcpy(cadena,auxCadena);
        retorno=1;
    }
    return retorno;
}
int getStringLetras(char mensaje[],char cadena[])
{
    int retorno=0;
    char auxCadena[50];
    getString(mensaje,auxCadena);
    if(validarSoloLetras(auxCadena))
    {
        strcpy(cadena,auxCadena);
        retorno=1;
    }
    return retorno;
}
void inicializarLegajoArray(int unArray[],int tam,int valor)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i]=valor;
    }
}
int buscarLugarLibre(int unArray[],int tam,int valor)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i] == valor)
        {
            retorno=i;
        }
    }
    return retorno;
}
