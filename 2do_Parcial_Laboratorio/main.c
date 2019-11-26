#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Vuelos.h"
#include "Pilotos.h"
/*
3)	Filtrar vuelos cortos: Generar un archivo de iguales características que el original, con los datos de los vuelos cuya duración sea inferior a 3 horas.
4)	Listar vuelos a Portugal: Generar un listado que solo incluya los vuelos con destino a Portugal
5)	Filtrar a Alex Lifeson: Necesitamos un listado de vuelos que no incluya al chofer Alex Lifeson
6)	Salir.
*/

int main()
{
    FILE* archivoTexto=NULL;
    FILE* archivoFiltro=NULL;
    LinkedList* listaVuelos=ll_newLinkedList();
    LinkedList* listaPilotos=ll_newLinkedList();
    piloto_harcodearDatos(listaPilotos);
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-CARGAR DATOS(modo texto)\n");
        printf("2-MOSTRAR LISTA DE VUELOS\n");
        printf("3-FILTRAR VUELOS CORTOS\n");
        printf("4-LISTAR VUELOS A PORTUGAL\n");
        printf("5-FILTRAR A ALEX LIFESON\n");
        printf("6-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                vuelo_cargarDatosModoTexto(archivoTexto,listaVuelos);
                break;
            case 2:
                vuelo_mostrarListavuelos(listaVuelos,listaPilotos);
                break;
            case 3:
                vuelo_guardarDatosPorFiltro(archivoFiltro,listaVuelos);
                break;
            case 4:
                vuelo_mostrarListaDeVuelosAPortugal(listaVuelos,listaPilotos);
                break;
            case 5:
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
    ll_deleteLinkedList(listaVuelos);
    ll_deleteLinkedList(listaPilotos);
    return 0;
}
