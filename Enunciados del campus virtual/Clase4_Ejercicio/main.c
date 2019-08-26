#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones.h"

int main()
{
    int numeroOculto;
    int numeroIngresado;
    char teclaIngresada;
    int cantIntentos=5;
    int jugar;

    printf("Bienvenido!\nTienes 5 intentos para adivinar el numero aleatorio\nIngresa -1 para abandonar la partida\n");
    system("pause");
    system("cls");

    teclaIngresada='s';

    while(teclaIngresada=='s')
    {
        numeroOculto=getNumeroAleatorio(1,100,1);
        //printf("Numero oculto: %d\n",numeroOculto);
        cantIntentos=5;
        jugar=1;
        while(jugar==1)
        {
            numeroIngresado=getInt("Ingrese un numero del 1 a 100: ");
            if(numeroIngresado < 0)
                {
                    printf("Abandonaste la partida actual!\n");
                    jugar=0;
                }
            else if(numeroIngresado == numeroOculto)
                {
                    printf("\nFelicidades ganaste!\n");
                    jugar=0;
                }
            else if(numeroIngresado < numeroOculto)
                {
                    printf("NUMERO DEMASIADO CHICO!\n");
                    cantIntentos--;
                }
            else if(numeroIngresado > numeroOculto)
                {
                    printf("NUMERO DEMASIADO GRANDE!\n");
                    cantIntentos--;
                }
            if(cantIntentos == 0)
            {
                printf("\nSe acabaron los intentos!\n");
                printf("\nEl numero oculto era el: %d\n",numeroOculto);
                jugar=0;
            }
        }
        teclaIngresada=getChar("Desea jugar nuevamente? (s/n): ");
        system("cls");
    }







    return 0;
}

