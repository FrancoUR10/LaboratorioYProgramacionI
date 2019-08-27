#include <stdio.h>
#include <stdlib.h>
#include "CadenasCaracteres.h"

int getInt(char mensaje[])
{
    int auxEntero;
    printf(mensaje);
    scanf("%d",&auxEntero);
    fflush(stdin);
    return auxEntero;
}
float getFloat(char mensaje[])
{
    float auxFlotante;
    printf(mensaje);
    scanf("%f",&auxFlotante);
    fflush(stdin);
    return auxFlotante;
}
char getChar(char mensaje[])
{
    char auxCaracter;
    printf(mensaje);
    scanf("%c",&auxCaracter);
    fflush(stdin);
    return auxCaracter;
}

int esNumerico(char str[])
{
    int retorno=1;
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int esAlfaNumerico(char str[])
{
    int retorno=1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

int esSoloLetras(char str[])
{
    int retorno=1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

int esTelefono(char str[])
{
    int retorno=1;
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
        {
            retorno=0;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;
        }
        i++;
    }
    if(retorno==1)
    {
        if(contadorGuiones!=1)
        {
            retorno=0;
        }
    }
    return retorno;
}
