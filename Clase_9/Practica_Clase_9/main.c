#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX 5

//Cambiar la carga de datos para que el id se genere de manera automatica
//Crear una estructura llamada Localidad
//Cuando se muestra a un alumno, en vez de mostrar el numero, mostrar la descripcion de la localidad
int main()
{
    eAlumno listaAlumnos[MAX];
    int opcion;
    char continuar='s';

    inicializarArray(listaAlumnos,MAX);
    harcodearAlumnos(listaAlumnos);
    do
    {
        opcion=getInt("1-Cargar Alumno\n2-Borrar Alumno\n3-Modificar Alumno\n4-Mostrar Listado Alumnos\n5-Salir del menu\n\nIngrese una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarDatos(listaAlumnos,MAX);
                break;
            case 2:
                borrarDatos(listaAlumnos,MAX);
                break;
            case 3:
                modificarDatos(listaAlumnos,MAX);
                break;
            case 4:
                ordenarInsercion(listaAlumnos,MAX);
                mostrarLista(listaAlumnos,MAX);
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


    return 0;
}
