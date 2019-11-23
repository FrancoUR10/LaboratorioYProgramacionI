#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Problemas.h"
#include "llamada.h"

int main()
{
    FILE* archivoDatos=NULL;
    FILE* archivoFiltro=NULL;
    LinkedList* listaLlamadas=ll_newLinkedList();
    LinkedList* listaProblemas=ll_newLinkedList();
    problema_harcodearProblemas(listaProblemas);
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-CARGAR ARCHIVO\n");
        printf("2-IMPRIMIR LLAMADAS\n");
        printf("3-GENERAR ARCHIVO DE LLAMADAS\n");
        printf("4-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                //llamada_cargarDatos(archivoDatos,listaLlamadas);
                llamada_cargarDatosModoTexto(archivoDatos,listaLlamadas);
                break;
            case 2:
                llamada_mostrarListallamadas(listaLlamadas,listaProblemas);
                break;
            case 3:
                llamada_guardarDatosPorFiltro(archivoFiltro,listaLlamadas);
                break;
            case 4:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');
    ll_deleteLinkedList(listaLlamadas);
    ll_deleteLinkedList(listaProblemas);
    return 0;
}
