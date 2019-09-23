#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    int estaVacio;
    int legajo;
    int nota;
    char nombre[51];
}eAlumno;

int getInt(char mensaje[]);
void inicializarArray(eAlumno unArray[],int tam);
void ordenarInsercion(eAlumno unArray[],int tam);
void harcodearAlumnos(eAlumno unArray[]);
int buscarSoloEstado(eAlumno unArray[],int tam,int estado);
void mostrarUnSoloAlumno(eAlumno unAlumno[],int indice);
void mostrarLista(eAlumno unArray[],int tam);
void cargarDatos(eAlumno unArray[],int tam);
void borrarDatos(eAlumno unArray[],int tam);
int buscarLegajo(eAlumno unArray[],int tam,int legajo);
void modificarDatos(eAlumno unArray[],int tam);
void mostrarDatosAuxiliares(eAlumno auxAlumno);

#endif // FUNCIONES_H_INCLUDED
