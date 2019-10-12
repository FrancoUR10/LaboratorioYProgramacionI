#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#include "Materias.h"
#include "Inscripciones.h"
#define A 5
#define MAX_MATERIAS 4
//1.Mostrar nombre del alumno y nombre de materia en lugar del id
//2.Ingresar una materia y mostrar todos los alumnos de esa materia
//3.Listar cant de inscripciones por localidad (Ejemplo:Para avellaneda cuantos alumnos se inscribieron),(buscar id alumno en localidad, comparar si id alumno se encuentra en inscripciones, si se encuentra sumar 1 al contador auxiliar),(Se puede usar la estructura auxLocalidad)(Serian 3 for anindados, si el codigo estuviera en una sola funcion)
//4.La localidad con mayor inscripcion a programacionI
//5.Total de horas que estudia un alumno seleccionado
//6.Las inscripciones por fecha determinada

//De uno a muchos en el parcial

// 1ºParcial: Programacion: 7/10 Laboratorio: 8/10 Laboratorio: 15/10

// 2ºParcial: Programacion: 25/11) Laboratorio: 26/11

// 3/12 recuperatorio 1 parcial laboratorio
// 2/12 recuperatorio 1 parcial programacion
int main()
{
    eAlumno listaDeAlumnos[A];
    eLocalidad listaLocalidades[3]={{1,"Avellaneda",1870},{2,"Wilde",1872},{3,"Lomas de Zamora",1700}};
    eAuxLocalidad auxContador[3];
    eMateria listaMaterias[20];
    eInscripciones listaInscripciones[A*4];
    int i;
    /*for(i=0;i<3;i++)
    {
        printf("%d - %s - %d\n", listaLocalidades[i].idLocalidad,listaLocalidades[i].localidad,listaLocalidades[i].codigoPostal);
    }*/


    int respuesta;
    int opcion;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

    hardCodearAlumnos(listaDeAlumnos,A);
    harcodearMaterias(listaMaterias,MAX_MATERIAS);
    inicializarInscripcion(listaInscripciones,A*4);

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n6.ALTA INSCRIPCION\n7.MOSTRAR INSCRIPCIONES\n8.SALIR\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarListadoAlumnos(listaDeAlumnos,A);

            break;
        case 2:
            //mostrarListadoAlumnos(listaDeAlumnos, A,listaLocalidades,3); //1
            //mostrarSoloLocalidad(listaLocalidades,3); //2
            //mostrarCadaLocalidadConSusAlumnos(listaDeAlumnos,A,listaLocalidades,3); //3
            //mostrarAlumnosEnAvellaneda(listaDeAlumnos,A,listaLocalidades,3); //4
            mostrarLocalidadConMenosAlumnos(listaDeAlumnos,A,listaLocalidades,3,auxContador); //5
            break;
        case 3:
            sortStudentsByNameAndAverage(listaDeAlumnos,A);
            break;
        case 4:
            respuesta = eliminarAlumno(listaDeAlumnos,A);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno eliminado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }

            break;
        case 5:

            respuesta = modificarAlumno(listaDeAlumnos,A,102);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno modificado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }
            break;
        case 6:
            darDeAltaInscripcion(listaMaterias,MAX_MATERIAS,listaDeAlumnos,A,listaInscripciones,A*4,listaLocalidades,3);
            break;
        case 7:
            mostrarInscripciones(listaInscripciones,A*4,listaDeAlumnos,A,listaMaterias,MAX_MATERIAS);
            break;

        }
    }
    while(opcion!=8);
    return 0;
}


