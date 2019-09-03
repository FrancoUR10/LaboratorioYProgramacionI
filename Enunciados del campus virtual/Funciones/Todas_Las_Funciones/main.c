#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    char continuarMenu='s';
    int opcionMenu;
    do
    {
        opcionMenu=getInt("1.OPCION\n2.SALIR\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                printf("\nMenu general\n");
                break;
            case 2:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');






    return 0;
}
