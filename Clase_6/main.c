#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX 5
// 7/10 Lunes: 1°er Parcial de programacion
// 1/10 Martes: 1°er Parcial de laboratorio (I) ABM (Parte de cargar los datos)
// 8/10 Martes: 1°er Parcial de laboratorio (II) FILTROS (Parte de consulta)
int main()
{
    eSillas arrayDeSillas[MAX];

    inicializarArray(arrayDeSillas,MAX);
    hardcodearArray(arrayDeSillas,0,5,5,22,1,0);
    hardcodearArray(arrayDeSillas,1,1,1,20,1,0);
    hardcodearArray(arrayDeSillas,2,2,2,35,0,0);
    hardcodearArray(arrayDeSillas,3,3,3,30,1,0);
    hardcodearArray(arrayDeSillas,4,4,4,29,0,0);

    buscarLugarLibre(arrayDeSillas,MAX,-1,1);
    char continuarMenu='s';
    int opcionMenu;
    do
    {
        opcionMenu=getInt("1.ALTA\n2.BAJA\n3.MODIFICAR\n4.MOSTRAR\n5.SALIR\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                ocuparSilla(arrayDeSillas,MAX);
                break;
            case 2:
                desocuparSilla(arrayDeSillas,MAX);
                break;
            case 3:
                break;
            case 4:
                mostrarArray(arrayDeSillas,MAX);
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
