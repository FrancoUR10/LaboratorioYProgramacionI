#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    int opcionIngresada;
    do
    {
        opcionIngresada=sacarNumeroEntero("1. Sumar\n2. Baja\n3. Modificar\n4.Informar\n5. Salir\nIngrese una opcion: ");
        switch(opcionIngresada)
        {
            case 1:
                numeroUno=sacarNumeroEntero("\nIngrese un numero: ");
                numeroDos=sacarNumeroEntero("\nIngrese otro numero: ");
                suma=sacarSuma(numeroUno,numeroDos);
                printf("\nLa suma de %d y %d es: %d\n",numeroUno,numeroDos,suma);
                break;
            case 2:
                printf("\nBaja realizada\n");
                break;
            case 3:
                printf("\nModificacion realizada\n");
                break;
            case 4:
                printf("\nLista: n/a\n");
                break;
            default:
                if(opcionIngresada!=5)
                {
                    printf("\nOpcion ingresada no valida\n");
                }
        }
        system("pause");
        system("cls");
    }
    while(opcionIngresada!=5);










    return 0;
}
