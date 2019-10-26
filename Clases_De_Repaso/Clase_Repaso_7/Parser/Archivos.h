#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nombre[50];
    char apellido[50];
    float nota;
    int id;
}eAlumno;

int cerrarArchivo(FILE* unArchivo);
void liberarMemoria(eAlumno* unAlumno);
eAlumno* new_Alumno();
eAlumno* new_Alumno_Parametros(int id, char* nombre,char* apellido,float nota);
int getId(eAlumno* unAlumno);
void setId(eAlumno* unAlumno,int id);
#endif // ARCHIVOS_H_INCLUDED
