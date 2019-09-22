#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
float getFloat(char mensaje[])
{
    float auxFloat;
    printf("%s",mensaje);
    scanf("%f",&auxFloat);
    fflush(stdin);
    return auxFloat;
}
char getChar(char mensaje[])
{
    char auxChar;
    printf("%s",mensaje);
    scanf("%c",&auxChar);
    fflush(stdin);
    return auxChar;
}
void getString(char mensaje[],char unArray[])
{
    printf("%s",mensaje);
    gets(unArray);
    fflush(stdin);
}
int validarSoloNumeros(char unArray[])
{
    int retorno=1;
    int i=0;
    while(unArray[i]!='\0')
    {
        if(unArray[i] < '0' || unArray[i] > '9')
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int validarSoloNumerosFlotantes(char unArray[])
{
    int contadorPuntos=0;
    int retorno=1;
    int i=0;
    while(unArray[i]!='\0')
    {
        if((unArray[i] != '.') && (unArray[i] < '0' || unArray[i] > '9'))
        {
            retorno=0;
        }
        if(unArray[i]=='.')
        {
            contadorPuntos++;
        }
        i++;
    }
    if(retorno==1 && contadorPuntos > 1)
    {
        retorno=0;
    }
    return retorno;
}
int validarSoloLetras(char unArray[])
{
    int retorno=1;
    int i=0;
    while(unArray[i]!='\0')
    {
        if((unArray[i] != ' ') && (unArray[i] < 'a' || unArray[i] > 'z') && (unArray[i] < 'A' || unArray[i] > 'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int getStrNumeros(char mensaje[],char unArray[],char mensajeErrorNumeros[],char mensajeErrorRango[],int min,int max,int intentos)
{
    int contadorIntentos=0;
    int retorno;
    char auxString[256];
    int longitud;
    getString(mensaje,auxString);
    longitud=strlen(auxString);
    if((validarSoloNumeros(auxString) == 0) || (longitud < min || longitud > max))
    {
        contadorIntentos++;
    }
    while(((validarSoloNumeros(auxString) == 0) || (longitud < min || longitud > max)) && (contadorIntentos != intentos))
    {
        if(longitud < min || longitud > max)
        {
            printf("%s",mensajeErrorRango);
        }
        if(validarSoloNumeros(auxString) == 0)
        {
            printf("%s",mensajeErrorNumeros);
        }
        getString(mensaje,auxString);
        longitud=strlen(auxString);
        if((validarSoloNumeros(auxString) == 0) || (longitud < min || longitud > max))
        {
            contadorIntentos++;
        }
    }
    if(contadorIntentos==intentos)
    {
        printf("\nSe acabaron los intentos\a\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
        retorno=1;
    }
    return retorno;
}
int getStrNumerosFlotantes(char mensaje[],char unArray[],char mensajeErrorNumerosFlotantes[],char mensajeErrorRango[],int min,int max,int intentos)
{
    int contadorIntentos=0;
    int retorno;
    char auxString[256];
    int longitud;
    getString(mensaje,auxString);
    longitud=strlen(auxString);
    if((validarSoloNumerosFlotantes(auxString) == 0) || (longitud < min || longitud > max))
    {
        contadorIntentos++;
    }
    while(((validarSoloNumerosFlotantes(auxString) == 0) || (longitud < min || longitud > max)) && (contadorIntentos != intentos))
    {
        if(longitud < min || longitud > max)
        {
            printf("%s",mensajeErrorRango);
        }
        if(validarSoloNumerosFlotantes(auxString) == 0)
        {
            printf("%s",mensajeErrorNumerosFlotantes);
        }
        getString(mensaje,auxString);
        longitud=strlen(auxString);
        if((validarSoloNumerosFlotantes(auxString) == 0) || (longitud < min || longitud > max))
        {
            contadorIntentos++;
        }
    }
    if(contadorIntentos==intentos)
    {
        printf("\nSe acabaron los intentos\a\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
        retorno=1;
    }
    return retorno;
}
int getStrLetras(char mensaje[],char unArray[],char mensajeErrorLetras[],char mensajeErrorRango[],int min,int max,int intentos)
{
    int contadorIntentos=0;
    int retorno;
    char auxString[256];
    int longitud;
    getString(mensaje,auxString);
    longitud=strlen(auxString);
    if((validarSoloLetras(auxString) == 0) || (longitud < min || longitud > max))
    {
        contadorIntentos++;
    }
    while(((validarSoloLetras(auxString) == 0) || (longitud < min || longitud > max)) && (contadorIntentos != intentos))
    {
        if(longitud < min || longitud > max)
        {
            printf("%s",mensajeErrorRango);
        }
        if(validarSoloLetras(auxString) == 0)
        {
            printf("%s",mensajeErrorLetras);
        }
        getString(mensaje,auxString);
        longitud=strlen(auxString);
        if((validarSoloLetras(auxString) == 0) || (longitud < min || longitud > max))
        {
            contadorIntentos++;
        }
    }
    if(contadorIntentos==intentos)
    {
        printf("\nSe acabaron los intentos\a\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
        retorno=1;
    }
    return retorno;
}
int getStringSoloEdad(char mensaje[],char unArray[],char mensajeErrorNumeros[],char mensajeErrorEdadPermitida[],int minEdad,int maxEdad,int intentos)
{
    int contadorIntentos=0;
    int retorno;
    char auxString[256];
    int auxEdadInt;
    getString(mensaje,auxString);
    auxEdadInt=atoi(auxString);

    if((validarSoloNumeros(auxString) == 0) || (auxEdadInt < minEdad || auxEdadInt > maxEdad))
    {
        contadorIntentos++;
    }
    while(((validarSoloNumeros(auxString) == 0) || (auxEdadInt < minEdad || auxEdadInt > maxEdad)) && (contadorIntentos != intentos))
    {
        if(auxEdadInt < minEdad || auxEdadInt > maxEdad)
        {
            printf("%s",mensajeErrorEdadPermitida);
        }
        if(validarSoloNumeros(auxString) == 0)
        {
            printf("%s",mensajeErrorNumeros);
        }
        getString(mensaje,auxString);
        auxEdadInt=atoi(auxString);
        if((validarSoloNumeros(auxString) == 0) || (auxEdadInt < minEdad || auxEdadInt > maxEdad))
        {
            contadorIntentos++;
        }
    }
    if(contadorIntentos==intentos)
    {
        printf("\nSe acabaron los intentos\a\n");
        retorno=0;
    }
    else
    {
        strcpy(unArray,auxString);
        retorno=1;
    }
    return retorno;
}
