#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX 5

int main()
{
    eAlumno listadoDeAlumnos[MAX];
    int opcion;
    char continuar='s';

    inicializarListadoAlumnos(listadoDeAlumnos,MAX);
    do
    {
        opcion=getInt("1-MOSTRAR\n2-CARGAR\n3-BUSCAR\n4-BORRAR\n5-SALIR\n\nIngrese una opcion: ");
        switch(opcion)
        {
            case 1:
                listarAlumnos(listadoDeAlumnos,MAX);
                break;
            case 2:
                //cargarDatosTest(listadoDeAlumnos,MAX);
                harcodearListaDeAlumnos(listadoDeAlumnos,0);
                break;
            case 3:
                buscarUnNombre(listadoDeAlumnos,MAX);
                break;
            case 4:
                borrarUnAlumnoListado(listadoDeAlumnos,MAX);
                break;
            case 5:
                continuar='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuar=='s');
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






    return 0;
}
