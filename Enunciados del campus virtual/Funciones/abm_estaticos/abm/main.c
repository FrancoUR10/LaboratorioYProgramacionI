#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#define MAX 1000

int main()
{
    eEmpleado listaEmpleados[MAX];
    int contAltas=6;
    int opcionMenu;
    char continuarMenu='s';

    empleado_inicializarDatos(listaEmpleados,MAX);
    empleado_harcodearDatos(listaEmpleados);

    do
    {
        printf("1-ALTA\n");
        printf("2-BAJA\n");
        printf("3-MODIFICAR\n");
        printf("4-INFORMAR\n");
        printf("5-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                empleado_darDeAlta(listaEmpleados,MAX,&contAltas);
                break;
            case 2:
                empleado_darDeBaja(listaEmpleados,MAX);
                break;
            case 3:
                empleado_modificarDatos(listaEmpleados,MAX);
                break;
            case 4:
                empleado_mostrarLista(listaEmpleados,MAX);
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
