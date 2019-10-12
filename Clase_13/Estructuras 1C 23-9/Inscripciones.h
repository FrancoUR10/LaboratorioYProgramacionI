#ifndef INSCRIPCIONES_H_INCLUDED
#define INSCRIPCIONES_H_INCLUDED
typedef struct
{
    int idInscripcion;
    int legajoAlumno;
    int idMateria;
    eFecha fechaInscripcion;
    int estadoInscripcion;
} eInscripciones;

void darDeAltaInscripcion(eMateria listaMaterias[], int tamMaterias,eAlumno listaAlumno[],int tamAlumno,eInscripciones listaInscripcion[],int tamInscripcion,eLocalidad listalocalidad[],int tamLocalidad);
void mostrarInscripciones(eInscripciones listaInscripcion[],int tamInscripcion,eAlumno listaAlumno[],int tamAlumno,eMateria listaMateria[],int tamMateria);
void mostrarUnaInscripcion(eInscripciones unaInscripcion[],int indiceInscripcion,eAlumno unAlumno[],int indiceAlumno,eMateria unaMateria[],int indiceMateria);
void inicializarInscripcion(eInscripciones listaInscripciones[],int tamInscripcion);
int buscarInscripcionLibre(eInscripciones listaInscripciones[], int tamInscripciones);


#endif // INSCRIPCIONES_H_INCLUDED
