#include <stdio.h>
#include <stdlib.h>
#include "Localidad.h"
#include "ABM.h"
#define MAX_EMPLEADO 1000
#define MAX_LOCALIDAD 5

int main()
{
    eEmpleado listaEmpleados[MAX_EMPLEADO];
    eLocalidad listaLocalidades[MAX_LOCALIDAD];
    int contAltas=6;
    int opcionMenu;
    char continuarMenu='s';

    empleado_inicializarDatos(listaEmpleados,MAX_EMPLEADO);
    empleado_harcodearDatos(listaEmpleados);
    localidad_harcodearDatos(listaLocalidades);

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
                empleado_darDeAlta(listaEmpleados,MAX_EMPLEADO,listaLocalidades,MAX_LOCALIDAD,&contAltas);
                break;
            case 2:
                empleado_darDeBaja(listaEmpleados,MAX_EMPLEADO,listaLocalidades,MAX_LOCALIDAD);
                break;
            case 3:
                empleado_modificarDatos(listaEmpleados,MAX_EMPLEADO,listaLocalidades,MAX_LOCALIDAD);
                break;
            case 4:
                empleado_mostrarLista(listaEmpleados,MAX_EMPLEADO,listaLocalidades,MAX_LOCALIDAD);
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
