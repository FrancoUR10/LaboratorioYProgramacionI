#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Producto.h"

int main()
{
    FILE* archivoProductos=NULL;
    LinkedList* listaProductos=ll_newLinkedList();
    int contAltas=1;
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-ALTA\n");
        printf("2-MODIFICAR\n");
        printf("3-BAJA LOGICA\n");
        printf("4-BAJA FISICA\n");
        printf("5-INFORMAR\n");
        printf("6-SALIR\n");
        printf("7-CARGAR DATOS\n");
        printf("8-GUARDAR DATOS\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                producto_darDeAlta(listaProductos,&contAltas);
                break;
            case 2:
                producto_modificarDatos(listaProductos);
                break;
            case 3:
                producto_darDeBajaLogica(listaProductos);
                break;
            case 4:
                producto_darDeBajaFisica(listaProductos);
                break;
            case 5:
                producto_informarDatos(listaProductos);
                break;
            case 6:
                continuarMenu='n';
                break;
            case 7:
                producto_cargarDatos(archivoProductos,listaProductos,&contAltas);
                break;
            case 8:
                producto_guardarDatos(archivoProductos,listaProductos,&contAltas);
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');
    ll_deleteLinkedList(listaProductos);
    return 0;
}
