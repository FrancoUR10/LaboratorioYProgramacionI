#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED
typedef struct
{
    int idInscripcion;
    int legajoAlumno;
    int idMateria;
    eFecha fechaInscripcion;
    int estadoInscripcion;
} eInscripciones;

typedef struct
{
    int estadoMateria;
    int idMateria;
    char descripcion[51];
    int cargaHoraria;
} eMateria;

void harcodearMaterias(eMateria listaMaterias[],int tamMaterias);
void mostrarMaterias(eMateria listaMaterias[],int tamMaterias);
void mostrarUnaMateria(eMateria unaMateria[],int indiceMateria);
int buscarMateriaLibre(eMateria listaMaterias[], int tamMaterias);
void darDeAltaInscripcion(eMateria listaMaterias[], int tamMaterias,eAlumno listaAlumno[],int tamAlumno,eInscripciones listaInscripcion[],int tamInscripcion,eLocalidad listalocalidad[],int tamLocalidad);
void mostrarInscripciones(eInscripciones listaInscripcion[],int tamInscripcion,eAlumno listaAlumno[],int tamAlumno,eMateria listaMateria[],int tamMateria);
void mostrarUnaInscripcion(eInscripciones unaInscripcion[],int indiceInscripcion,eAlumno unAlumno[],int indiceAlumno,eMateria unaMateria[],int indiceMateria);
void inicializarInscripcion(eInscripciones listaInscripciones[],int tamInscripcion);

#endif // MATERIAS_H_INCLUDED
