#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funciones.h"

int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxInt);
    return auxInt;
}

float getFloat(char mensaje[])
{
    float auxFloat;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxFloat);
    return auxFloat;
}
char getChar(char mensaje[])
{
    char auxChar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxChar);
    return auxChar;
}
void getString(char mensaje[],char cadena[])
{
    printf("%s",mensaje);
    gets(cadena);
}
char getNumeroAleatorio(int desde,int hasta, int iniciar)
{
    if(iniciar)
    {
        srand (time(NULL));
    }
    return desde + (rand() % (hasta + 1 - desde));
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
int validarAlfaNumericos(char cadena[])
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
int validarNumeroTelefono(char cadena[])
{
    int retorno=1;
    int i=0;
    int contadorGuiones=0;
    while(cadena[i] != '\0')
    {
        if(cadena[i]=='-')
        {
            contadorGuiones++;
        }
        if((cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno=0;
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
int getStrNumeros(char mensaje[],char unArray[])
{
    int retorno=0;
    char auxArray[50];
    getString(mensaje,auxArray);
    if(validarSoloNumeros(auxArray))
    {
        strcpy(unArray,auxArray);
        retorno=1;
    }
    return retorno;
}
int getStrLetras(char mensaje[],char unArray[])
{
    int retorno=0;
    char auxArray[50];
    getString(mensaje,auxArray);
    if(validarSoloLetras(auxArray))
    {
        strcpy(unArray,auxArray);
        retorno=1;
    }
    return retorno;
}

void inicializarLegajo(int unArray[],int tam,int valor)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i]=valor;
    }
}
int buscarLugarLibre(int unArray[],int tam,int valorABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i] == valorABuscar)
        {
            retorno=i;
        }
    }
    return retorno;
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
void ordenarVector(int vector[],int tam)
{
    int i;
    int j;
    int aux;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(vector[i] > vector[j])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}
void mostrarMaximo(int vector[],int tam)
{
    int maximo;
    int i;
    maximo=calcularMaximo(vector,tam);

    printf("\nMaximo: %d\n",maximo);
    for(i=0;i<tam;i++)
    {
        if(vector[i] == maximo)
            {
                printf("En la posicion: %d-",i);
            }
    }
}
int calcularMaximo(int vector[],int tam)
{
    int i;
    int maximo;
    int flagPrimerValor;
    flagPrimerValor=1;
    for(i=0;i<tam;i++)
    {
        if(flagPrimerValor==1 || vector[i]>maximo)
        {
            maximo=vector[i];
        }
            flagPrimerValor=0;
    }
    return maximo;
}
int calcularMinimo(int vector[],int tam)
{
    int i;
    int minimo;
    int flagPrimerValor;
    flagPrimerValor=1;
    for(i=0;i<tam;i++)
    {
        if(flagPrimerValor==1 || vector[i]<minimo)
        {
            minimo=vector[i];
        }
            flagPrimerValor=0;
    }
    return minimo;
}
void mostrarMinimo(int vector[],int tam)
{
    int minimo;
    int i;
    minimo=calcularMinimo(vector,tam);

    printf("\nMinimo: %d\n",minimo);
    for(i=0;i<tam;i++)
    {
        if(vector[i] == minimo)
            {
                printf("En la posicion: %d-",i);
            }
    }
}
void cargarVector(char mensaje[],int vector[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%s",mensaje);
        scanf("%d",&vector[i]);
        fflush(stdin);
    }
}
