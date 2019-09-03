#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX 10

//Pre compilador: se ejecuta antes de ejecutarse el compilador, para analizar errores
// Directiva del pre compilador: Algo que quiero que se haga antes que se compile, include es una directiva del compilador



int main()
{
    printf("Ejemplos de arrays\n");

    //int numeroUno,numeroDos,........,numeroDiez == int arrayNumeros[10];
    int arrayNumeros[MAX]={8,7,1,3,-8,9,9,-7,10,5}; //Hardcodear datos
    int acumuladorNumerosPositivos=0;
    int contadorNumerosPositivos=0;
    int flagPrimerValor;
    int minimo;
    float promedioDeNumerosPositivos;
    int opcionMenu;
    char continuarMenu='s';
    int i;

    do
    {
        opcionMenu=getInt("1.CARGAR NUMEROS\n2.MOSTRAR TODO\n3.MOSTRAR NEGATIVOS\n4.MOSTRAR PROMEDIO POSITIVOS\n5.MOSTRAR MAXIMO\n6.MOSTRAR MINIMO\n7.SALIR\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                cargarVector("Ingrese un numero: ",arrayNumeros,MAX);
                break;
            case 2:
                // Mostrar datos
                for(i=0;i<MAX;i++)
                {
                    printf("%d\n",arrayNumeros[i]);
                }
                break;
            case 3:
                for(i=0;i<MAX;i++)
                {
                    if(arrayNumeros[i] < 0)
                    {
                        printf("%d\n",arrayNumeros[i]);
                    }
                }
                break;
            case 4:
                for(i=0;i<MAX;i++)
                {
                    if(arrayNumeros[i] > 0)
                    {
                        acumuladorNumerosPositivos+=arrayNumeros[i];
                        contadorNumerosPositivos++;
                    }
                }
                promedioDeNumerosPositivos=(float)acumuladorNumerosPositivos/contadorNumerosPositivos; //Casteo de datos int a float
                printf("%.2f",promedioDeNumerosPositivos);
                break;
            case 5:
                mostrarMaximo(arrayNumeros,MAX);
                break;
            case 6:
                flagPrimerValor=1;
                for(i=0;i<MAX;i++)
                {
                    if(flagPrimerValor==1 || arrayNumeros[i]<minimo)
                    {
                        minimo=arrayNumeros[i];
                    }
                    flagPrimerValor=0;
                }

                printf("Minimo: %d\n",minimo);
                for(i=0;i<MAX;i++)
                {
                    if(arrayNumeros[i]==minimo)
                    {
                        printf("En la posicion: %d-",i);
                    }
                }
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
