#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[51];
    int edad;
}ePersona;

ePersona* persona_newPersona(void);
int persona_liberarPersona(ePersona* unaPersona);
int persona_setIdPersona(ePersona* unaPersona,int id);
int persona_setNombrePersona(ePersona* unaPersona,char* nombre);
int persona_setEdadPersona(ePersona* unaPersona,int edad);
int persona_getIdPersona(ePersona* unaPersona,int* id);
int persona_getNombrePersona(ePersona* unaPersona,char* nombre);
int persona_getEdadPersona(ePersona* unaPersona,int* edad);
ePersona* persona_newPersonaParametros(char* id,char* nombre,char* edad);
int mostrarUnaPersona(ePersona* unaPersona);
#endif // PERSONA_H_INCLUDED
