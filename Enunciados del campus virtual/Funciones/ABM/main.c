#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#define MAX 5

int main()
{
    int opcionMenu;
    char continuarMenu='s';
    eEntidad listaEntidades[MAX];
    int contAltas=4;

    inicializarEntidad(listaEntidades,MAX);
    harcodearEntidad(listaEntidades,3);
    do
    {
        printf("1-ALTA\n");
        printf("2-BAJA\n");
        printf("3-MODIFICAR\n");
        printf("4-MOSTRAR\n");
        printf("5-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                darDeAlta(listaEntidades,MAX,&contAltas);
                break;
            case 2:
                darDeBaja(listaEntidades,MAX);
                break;
            case 3:
                modificarDatos(listaEntidades,MAX);
                break;
            case 4:
                mostrarListaEntidad(listaEntidades,MAX);
                break;
            case 5:
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
