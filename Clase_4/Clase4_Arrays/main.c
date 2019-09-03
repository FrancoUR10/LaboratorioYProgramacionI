#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX 10

//Pre compilador: se ejecuta antes de ejecutarse el compilador, para analizar errores
// Directiva del pre compilador: Algo que quiero que se haga antes que se compile, include es una directiva del compilador



int main()
{
    //int numeroUno,numeroDos,........,numeroDiez == int arrayNumeros[10];
    int arrayNumeros[MAX]={8,7,1,3,-8,9,9,-7,10,5}; //Hardcodear datos
    int opcionMenu;
    char continuarMenu='s';

    do
    {
        opcionMenu=getInt("1.CARGAR NUMEROS\n2.MOSTRAR TODO\n3.MOSTRAR NEGATIVOS\n4.MOSTRAR PROMEDIO POSITIVOS\n5.MOSTRAR MAXIMO\n6.MOSTRAR MINIMO\n7.SALIR\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                cargarVector("Ingrese un numero: ",arrayNumeros,MAX);
                break;
            case 2:
                mostrarVector(arrayNumeros,MAX);
                break;
            case 3:
                mostrarVectorNegativos(arrayNumeros,MAX);
                break;
            case 4:
                mostrarPromedioPositivos(arrayNumeros,MAX);
                break;
            case 5:
                mostrarMaximo(arrayNumeros,MAX);
                break;
            case 6:
                mostrarMinimo(arrayNumeros,MAX);
                break;
            case 7:
                continuarMenu='n';
                break;
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');





    return 0;
}
