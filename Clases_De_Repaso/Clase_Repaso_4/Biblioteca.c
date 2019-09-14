#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

void cargarEdadesTest(int arrayEdades[],int tam)
{
    int i;
    int auxArrayEdades[]={22,33,18,55};
    for(i=0;i<tam;i++)
    {
        arrayEdades[i]=auxArrayEdades[i];
    }
}

void mostrarLista(int arrayEdades[],char arrayNombres[][50],char arrayApellidos[][50],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\nUsted es: %s %s y tiene: %d anios de edad\n",arrayNombres[i],arrayApellidos[i],arrayEdades[i]);
    }
}
void cargarNombresTest(char arrayNombres[][50],int tam)
{
    char auxArrayNombres[][50]={"A","B","C","D"};
    int i;
    for(i=0;i<tam;i++)
    {
        strcpy(arrayNombres[i],auxArrayNombres[i]);
    }
}
void cargarApellidosTest(char arrayApellidos[][50],int tam)
{
    char auxArrayApellidos[][50]={"a","b","c","d"};
    int i;
    for(i=0;i<tam;i++)
    {
        strcpy(arrayApellidos[i],auxArrayApellidos[i]);
    }
}

void ordenarArrayPorEdades(int arrayEdades[],char arrayNombres[][50],char arrayApellidos[][50],int tam)
{
    int i;
    int j;
    int auxEdades;
    char auxNombres[50];
    char auxApellidos[50];
    for(i=1;i<tam;i++)
    {
        auxEdades=arrayEdades[i];
        strcpy(auxNombres,arrayNombres[i]);
        strcpy(auxApellidos,arrayApellidos[i]);
        j=i-1;
        while((j >= 0) && (auxEdades < arrayEdades[j]))
        {
            arrayEdades[j+1]=arrayEdades[j];
            strcpy(arrayNombres[j+1],arrayNombres[j]);
            strcpy(arrayApellidos[j+1],arrayApellidos[j]);
            j--;
        }
        arrayEdades[j+1]=auxEdades;
        strcpy(arrayNombres[j+1],auxNombres);
        strcpy(arrayApellidos[j+1],auxApellidos);
    }
}
void realizarTodo(int tam, int arrayEdades[],char arrayNombre[][50],char arrayApellidos[][50])
{
    cargarEdadesTest(arrayEdades,tam);
    cargarNombresTest(arrayNombre,tam);
    cargarApellidosTest(arrayApellidos,tam);
    ordenarArrayPorEdades(arrayEdades,arrayNombre,arrayApellidos,tam);
    mostrarLista(arrayEdades,arrayNombre,arrayApellidos,tam);
}
