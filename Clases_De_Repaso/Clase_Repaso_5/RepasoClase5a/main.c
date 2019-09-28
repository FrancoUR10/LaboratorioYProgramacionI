#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX 5

int main()
{
    eAlumno arrayAlumnos[MAX];
    eLocalidad arrayLocalidades[3];

    inicializarAlumnos(arrayAlumnos,MAX);
    harcodearAlumnos(arrayAlumnos,3);
    harcodearLocalidad(arrayLocalidades,3);

    mostrarListaAlumnos(arrayAlumnos,MAX,arrayLocalidades,3);
    printf(" \n");
    return 0;
}
