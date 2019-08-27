#include <stdio.h>
#include <stdlib.h>
#include "CadenasCaracteres.h"
#include <string.h>

int main()
{
    char caracteresIngresados[50];
    printf("Ingrese cualquier cosa: ");
    gets(caracteresIngresados);
    if(esNumerico(caracteresIngresados))
    {
        printf("\nSe ingresaron numeros\n");
    }
    if(esSoloLetras(caracteresIngresados))
    {
        printf("\nSe ingresaron letras\n");
    }
    if(esAlfaNumerico(caracteresIngresados))
    {
        printf("\nSe ingreso un dato alfa numerico\n");
    }
    if(esTelefono(caracteresIngresados))
    {
        printf("\nSe ingreso un numero de telefono\n");
    }



















    return 0;
}
