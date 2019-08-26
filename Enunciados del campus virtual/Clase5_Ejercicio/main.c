/*
Solicitar al usuario 5 números, permitir listarlos por pantalla
indicando el máximo, el mínimo y el promedio.
Permitir Modificar el valor de cualquiera de los números
cargados indicando el índice del mismo y su nuevo valor.
*/


#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#define TAM 5

int main()
{
    int indice;
    int primerEdad=1;
    int maximaEdad;
    int minimaEdad;
    int acumulador;
    int contador;
    float promedio;
    char seguir='s';
    int numeroIngresado;
    int edad[TAM];
    int edadAModificar;
    int seModifico=1;
    int i;
    for(i=0;i<TAM;i++)
    {
        edad[i]=getInt("Ingrese la edad: ");
    }
    system("pause");
    system("cls");
    do
    {
        numeroIngresado=getInt("\n1.Listarlos\n2.Modificar\n3.Salir\nIngrese una opcion: ");
        switch(numeroIngresado)
        {
            case 1:
                acumulador=0;
                contador=0;
                for(i=0;i<TAM;i++)
                {
                    if(primerEdad==1)
                    {
                        maximaEdad=edad[i];
                        minimaEdad=edad[i];
                        primerEdad=0;
                    }
                    if(edad[i]>maximaEdad)
                    {
                        maximaEdad=edad[i];
                    }
                    if(edad[i]<minimaEdad)
                    {
                        minimaEdad=edad[i];
                    }
                    contador++;
                    acumulador+=edad[i];
                    printf("Edades: %d\n",edad[i]);
                }
                promedio=(float)acumulador/contador;
                printf("\nMaximo: %d\nMinimo: %d\nPromedio: %.2f\n",maximaEdad,minimaEdad,promedio);
                break;

            case 2:
                indice=getInt("Ingrese el indice a modificar: ");
                if(indice > 0 && indice <= TAM)
                {
                    edadAModificar=getInt("Ingrese la edad a modificar: ");
                    seModifico=0;
                }
                else
                {
                    printf("El indice esta fuera del rango");
                }
                if(seModifico==0)
                {
                    edad[indice-1]=edadAModificar;
                    seModifico=1;
                    primerEdad=1;
                }
                break;
            case 3:
                seguir='n';
                break;
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');


















    return 0;
}
