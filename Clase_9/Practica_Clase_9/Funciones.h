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
void ordenarInsercion(char unArray[][256],int tam);

#endif // FUNCIONES_H_INCLUDED
