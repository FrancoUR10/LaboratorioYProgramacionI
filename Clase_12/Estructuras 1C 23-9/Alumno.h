#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    int idLocalidad;
    int cantAlumnos;
}eAuxCont;

typedef struct
{

    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idLocalidad;
    char localidad[30];
    int codigoPostal;
} eLocalidad;
typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int idLocalidad;
    int estado;
} eAlumno;

eAlumno cargarAlumno(void);
void mostrarUnAlumno(eAlumno miAlumno[], eLocalidad suLocalidad[],int indice,int indiceLocalidad);
int buscarLibre(eAlumno*, int);
void cargarListadoAlumnos(eAlumno[], int);
void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam,eLocalidad listadoLocalidad [],int tamLocalidad);
void hardCodearAlumnos(eAlumno[], int);
void sortStudentsByNameAndAverage(eAlumno[], int);

int eliminarAlumno(eAlumno[], int);
int modificarAlumno(eAlumno[], int, int);

int buscarAlumnoPorLegajo(eAlumno[], int, int);
int buscarUnaLocalidad(eLocalidad listaLocalidades[], int tam,int idABuscar);
void mostrarSoloLocalidad(eLocalidad listaLocalidad[],int tamLocalidad);

int buscarLocalidadDelAlumno(eAlumno listaAlumno[],int tamAlumno,int idLocalidadBusqueda);
void contarCantAlumnos(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad,eAuxCont contadorAlumnos[]);
int buscarElMinimo(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad,eAuxCont contadorAlumnos[]);
void mostrarLocalidadConMenosAlumnos(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad,eAuxCont contadorAlumnos[]);
void mostrarCadaLocalidadConSusAlumnos(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad);
void mostrarAlumnosEnAvellaneda(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad);
