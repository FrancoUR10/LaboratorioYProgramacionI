#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"


int main()
{
    int edad;
    int nota;
    getInt(&edad,"Ingrese su edad: ",18,100);
    printf("Su edad es: %d\n",edad);
    getInt(&nota,"Ingrese una nota: ",1,10);//Reutilizacion
    printf("Usted se saco un: %d\n",nota);














    return 0;
}
