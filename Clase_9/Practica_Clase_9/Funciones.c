#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
void inicializarArray(eAlumno unArray[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i].legajo=-1;
        unArray[i].nota=-1;
        strcpy(unArray[i].nombre,"VACIO");
        unArray[i].estaVacio=0;
    }
}
void ordenarInsercion(char unArray[][256],int tam)
{
    int i;
    int j;
    char auxArray[256];

    for(i=1;i<tam;i++)
    {
        strcpy(auxArray,unArray[i]);
        j=i-1;
        while((j >= 0) && (strcmp(auxArray,unArray[j])==1))
        {
            strcpy(unArray[j+1],unArray[j]);
            j--;
        }
        strcpy(unArray[j+1],auxArray);
    }
}
