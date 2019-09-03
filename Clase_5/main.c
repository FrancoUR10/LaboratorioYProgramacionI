#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

//Tarea: Completar el ejercicio de vectores, crear una funcion factorial sin recursividad,.


//Calculo del numero "figurachi"(pronunciacion)
//Recursividad: Es llamar a una funcion en el scoope de esa misma funcion

int main()
{
/*
    int numero=4;
    printf("El numero antes de modificar es: %d\n",numero);
    funcion(&numero);
    printf("El numero despues de modificar es: %d\n",numero);
*/
/*
int unNumero=5;
int resultadoFactorial=1;
int i;

for(i=unNumero;i>=1;i--)
{
    resultadoFactorial=resultadoFactorial * i;
}
printf("Factorial es: %d",resultadoFactorial);
*/
int resultado;
int unNumero=5;
resultado=factorial(unNumero);
printf("Factorial es: %d",resultado);




    return 0;
}
