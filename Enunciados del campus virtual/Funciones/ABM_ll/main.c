#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Empleado.h"
int main()
{
    LinkedList* listaEmpleados=ll_newLinkedList();
    int contAltas=1;
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-ALTA\n");
        printf("2-BAJA\n");
        printf("3-MODIFICAR\n");
        printf("4-ORDENAR\n");
        printf("5-INFORMAR\n");
        printf("6-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                empleado_darDeAlta(listaEmpleados,&contAltas);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                empleado_mostrarListaEmpleados(listaEmpleados);
                break;
            case 6:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
