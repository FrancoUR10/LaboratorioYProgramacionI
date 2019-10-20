#include "Biblioteca_arrays.h"

int mostrarArrayUno(int array[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}

int mostrarArrayDos(int array[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\t",*(array+i));
    }
    printf("\n");
    return 0;
}
int mostrarArrayTres(int* array,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}
int mostrarArrayCuatro(int* array,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\t",*(array+i));
    }
    printf("\n");
    return 0;
}
