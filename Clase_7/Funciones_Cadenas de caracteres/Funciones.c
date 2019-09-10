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
void getString(char mensaje[],char string[])
{
    printf("%s",mensaje);
    gets(string);
}
int validarNombreYApellido(char unArray[])
{
    int contadorMayusculas=0;
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if((unArray[i+1] < 'a' || unArray[i+1] > 'z') && (unArray[0] < 'A' || unArray[0] > 'Z'))
        {
            retorno=0;
        }
        if(unArray[i] >= 'A' && unArray[i] <= 'Z')
        {
            contadorMayusculas++;
        }
        i++;
    }
    if(retorno==1)
    {
        if(contadorMayusculas > 1)
        {
            retorno=0;
        }
    }
    return retorno;
}
void pedirNombreYApellido(char unArray[],char mensaje[])
{
    getString(mensaje,unArray);

    while(!validarNombreYApellido(unArray))
    {
        printf("\nError: Solo se permite una letra Mayuscula inicial\n");
        getString(mensaje,unArray);
    }
}
