#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "Validaciones.h"
#include "Localidad.h"
#define MAX 5

int main()
{
    eGenerica arrayEmpleado[MAX];
    int contAltas=4;

    int opcionMenu;
    char continuarMenu='s';

    inicializarArray(arrayEmpleado,MAX);

    harcodearArray(arrayEmpleado,0,3,"A","A",20,50.4);
    harcodearArray(arrayEmpleado,1,1,"B","B",30,60.5);
    harcodearArray(arrayEmpleado,2,2,"C","C",35,70.6);
    do
    {
        opcionMenu=getInt("1-ALTA\n2-BAJA\n3-MODIFICAR\n4-MOSTRAR\n5-SALIR\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                darDeAlta(arrayEmpleado,MAX,&contAltas);
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
