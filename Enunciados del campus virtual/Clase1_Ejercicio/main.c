#include <stdio.h>
#include <stdlib.h>

/*
Solicite al usuario 10 números !
Calcule cuántos son negativos y cuantos son positivos !
Muestre por pantalla la cantidad de negativos y la cantidad de positivos !
*/

int main()
{
    int numeros;
    int cantPositivos=0;
    int cantNegativos=0;
    int cantCeros=0;
    int i;
    for(i=0;i<10;i++)
    {

        printf("Ingrese 10 numeros: ");
        scanf("%d",&numeros);
        system("cls");
        if(numeros > 0)
        {
            cantPositivos++;
        }
        else if(numeros < 0)
        {
            cantNegativos++;
        }
        else
        {
            cantCeros++;
        }
    }
    printf("Cantidad de numeros positivos: %d\nCantidad de numeros negativos %d\nCantidad de ceros %d\n",cantPositivos,cantNegativos,cantCeros);
    system("pause");
    return 0;
}
