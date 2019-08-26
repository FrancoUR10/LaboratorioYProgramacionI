#include <stdio.h>
#include <stdlib.h>
int main()
{
    int numeros;
    int maximo;
    int minimo;
    int acumulador=0;
    float promedio;

    printf("Ingrese un numero: ");
    scanf("%d",&numeros);
    maximo=numeros;
    minimo=numeros;
    acumulador=numeros;
    int i;
    for(i=0;i<4;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numeros);
        acumulador= acumulador + numeros;
    }
    if(numeros > maximo)
    {
        maximo=numeros;
    }
    if(numeros < minimo)
    {
        minimo=numeros;
    }
    promedio=acumulador / 5;
    printf("El maximo: %d\n",maximo);
    printf("El minimo: %d\n",minimo);
    printf("El promedio: %.2f\n",promedio);
    system("pause");
    return 0;
}
