#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#define T 4

int main()
{
    //Manipulacion de arrays paralelos y ordenamiento de arrays paralelos
    //char letra;
    //char palabra[T];

    int arrayEdades[T];
    char arrayNombres[T][50];
    char arrayApellidos[T][50];
/*
    cargarNombresTest(arrayNombres,T);
    cargarApellidosTest(arrayApellidos,T);
    cargarEdadesTest(arrayEdades,T);
    ordenarArrayPorEdades(arrayEdades,arrayNombres,arrayApellidos,T);
    mostrarLista(arrayEdades,arrayNombres,arrayApellidos,T);
*/
    realizarTodo(T,arrayEdades,arrayNombres,arrayApellidos);







    return 0;
}
