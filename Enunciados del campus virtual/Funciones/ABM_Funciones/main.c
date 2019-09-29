#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "Validaciones.h"
#include "Localidad.h"
#define MAX 5
#define MAX_LOCALIDADES 3

int main()
{
    eGenerica arrayEmpleado[MAX];
    eLocalidad arrayLocalidades[MAX_LOCALIDADES];
    int contAltas=4;

    int opcionMenu;
    char continuarMenu='s';

    inicializarArray(arrayEmpleado,MAX);
    harcodearArray(arrayEmpleado,3);

    harcodearLocalidades(arrayLocalidades,3);

    do
    {
        opcionMenu=getInt("1-ALTA\n2-BAJA\n3-MODIFICAR\n4-MOSTRAR\n5-SALIR\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                darDeAlta(arrayEmpleado,MAX,&contAltas,arrayLocalidades,MAX_LOCALIDADES);
                break;
            case 2:
                darDeBaja(arrayEmpleado,MAX);
                break;
            case 3:
                modificarArray(arrayEmpleado,MAX,arrayLocalidades,MAX_LOCALIDADES);
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
