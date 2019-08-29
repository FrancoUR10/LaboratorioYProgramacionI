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
void getString(char mensaje[], char cadena[])
{
    printf(mensaje);
    gets(cadena);
}


int esNumerico(char cadena[])
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

int esSoloLetras(char cadena[])
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
int esAlfaNumerico(char cadena[])
{
    int retorno=1;
    int i=0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != ' ') && (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

int esTelefono(char cadena[])
{
    int retorno=1;
    int i=0;
    int contadorGuiones=0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != ' ') && (cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno=0;
        }
        if(cadena[i]=='-')
        {
            contadorGuiones++;
        }
        i++;
    }
    if(retorno==1)
    {
        if(contadorGuiones != 1)
        {
            retorno=0;
        }
    }
    return retorno;
}
int getStringLetras(char mensaje[], char cadena[])
{
    int retorno=0;
    char auxStr[256];
    getString(mensaje,auxStr);
    if(esSoloLetras(auxStr))
    {
        strcpy(cadena,auxStr);
        retorno=1;
    }
    return retorno;
}
int getStringNumeros(char mensaje[], char cadena[])
{
    int retorno=0;
    char auxStr[256];
    getString(mensaje,auxStr);
    if(esNumerico(auxStr))
    {
        strcpy(cadena,auxStr);
        retorno=1;
    }
    return retorno;
}
void inicializarArray(int unArray[], int cantClientes, int valor)
{
    int i;
    for(i=0;i<cantClientes;i++)
    {
        unArray[i]=valor;
    }
}
int buscarPrimerOcurrencia(int unArray[], int cantClientes, int valor)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantClientes;i++)
    {
        if(unArray[i]==valor)
        {
            retorno=i;
        }
    }
    return retorno;
}
