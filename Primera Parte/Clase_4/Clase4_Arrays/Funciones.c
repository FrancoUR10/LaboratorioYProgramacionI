#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
void cargarVector(char mensaje[],int unArray[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%s",mensaje);
        scanf("%d",&unArray[i]);
        fflush(stdin);
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
void mostrarVector(int vector[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\n",vector[i]);
    }
}
void mostrarVectorNegativos(int vector[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vector[i] < 0)
        {
            printf("%d\n",vector[i]);
        }
    }
}
//Quick sort

//Metodo Burbujeo->
void ordenarVector(int vector[],int tam)
{
    int i;
    int j;
    int aux;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(vector[i] > vector[j]) // Criterio de ordenamiento
            {
                aux=vector[i];
                vector[i]=vector[j]; //Swaping
                vector[j]=aux;
            }
        }
    }
}
void mostrarPromedioPositivos(int vector[],int tam)
{
    float promedioPositivos;
    int sumaDePositivos=0;
    int contadorDePositivos=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(vector[i] > 0)
        {
            sumaDePositivos+=vector[i];
            contadorDePositivos++;
        }
    }
    promedioPositivos=(float)sumaDePositivos/contadorDePositivos; //Casteo de datos int a float
    printf("\nPromedio de numeros positivos: %.2f\n",promedioPositivos);
}
