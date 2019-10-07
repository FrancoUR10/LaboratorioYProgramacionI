#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "Validaciones.h"
#define MAX 1000

int main()
{
    eEmpleado arrayEmpleado[MAX];
    int contDeAltas=4;
    int opcionMenu;
    char continuarMenu='s';

    inicializarArray(arrayEmpleado,MAX);

    harcodearArray(arrayEmpleado,3);

    do
    {
        opcionMenu=getInt("1-ALTA\n2-BAJA\n3-MODIFICAR\n4-MOSTRAR\n5-SALIR\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                darDeAlta(arrayEmpleado,MAX,&contDeAltas);
                break;
            case 2:
                darDeBaja(arrayEmpleado,MAX);
                break;
            case 3:
                modificarArray(arrayEmpleado,MAX);
                break;
            case 4:
                mostrarArray(arrayEmpleado,MAX);
                break;
            case 5:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\a\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');


    return 0;
}
