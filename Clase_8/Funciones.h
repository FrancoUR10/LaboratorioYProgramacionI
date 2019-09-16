#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    char nombre[50];
    int nota;
    int legajo;
    int estaVacio;
}eAlumno;

void inicializarListadoAlumnos(eAlumno listaAlumnos[],int tam);
void listarAlumnos(eAlumno listaAlumnos[],int tam);
int buscarSoloEstado(eAlumno listaAlumnos[],int tam,int estadoActual);
void harcodearListaDeAlumnos(eAlumno listaAlumnos[],int indice);
int buscarPorLegajo(eAlumno listaAlumnos[],int tam, int valorABuscar);
void cargarDatosTest(eAlumno listaAlumnos[],int tam);
void borrarUnAlumnoListado(eAlumno listaAlumnos[],int tam);
int getInt(char mensaje[]);
void buscarUnNombre(eAlumno listaAlumnos[],int tam);

#endif // FUNCIONES_H_INCLUDED
