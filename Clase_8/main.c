#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX 5

int main()
{
    eAlumno listadoDeAlumnos[MAX];
    inicializarListadoAlumnos(listadoDeAlumnos,MAX);
    //eAlumno unAlumno;
    //eAlumno otroAlumno;

/*
    scanf("%d",&unAlumno.nota);
    fflush(stdin);
    printf("\nLa nota es: %d\n",unAlumno.nota);

    gets(unAlumno.nombre);
    fflush(stdin);
    printf("\nEl nombre es: %s\n",unAlumno.nombre);

    otroAlumno=unAlumno;
    printf("\nUn alumno: %s %d --Es igual a otro alumno: %s %d\n",unAlumno.nombre,unAlumno.nota,otroAlumno.nombre,otroAlumno.nota);

    otroAlumno.nota=999;
    printf("\nEl actual es: %d\n",otroAlumno.nota);
*/
    //harcodearListaDeAlumnos(listadoDeAlumnos,0);
    cargarDatosTest(listadoDeAlumnos,MAX);
    listarAlumnos(listadoDeAlumnos,MAX);





    return 0;
}
