#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    int id;
    char localidad[51];
    int codigoPostal;
}eLocalidad;
typedef struct
{
    int estado;
    int legajo;
    char nombre[51];
    int nota;
    int idLocalidad;
}eAlumno;

int getInt(char* mensaje);
float getFloat(char* mensaje);
char getChar(char* mensaje);
void getString(char* mensaje,char array[]);
void inicializarAlumnos(eAlumno listaAlumnos[],int tam);
void harcodearAlumnos(eAlumno listaAlumnos[],int tam);
void mostrarListaAlumnos(eAlumno listaAlumnos[],int tam,eLocalidad listaLocalidades[],int tamLocalidades);
void mostrarUnAlumno(eAlumno unAlumno[],int indice,eLocalidad unaLocalidad[],int indiceLocalidad);
void harcodearLocalidad(eLocalidad listaLocalidades[],int tamLocalidades);

int buscarLugarLibre(eAlumno unAlumno[],int tam,int valorABuscar);
int buscarSoloEstado(eAlumno unAlumno[],int tam,int estado);
int buscarIdLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int idABuscar);

#endif // FUNCIONES_H_INCLUDED
