#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char sexo;
    float altura;
} ePersona;

ePersona* new_Persona();//Constructor por defecto
ePersona* new_Persona_Parametros(int,char,float);//Constructor parametrizado

void setLegajo(ePersona*,int);
int getLegajo(ePersona*);

void mostrarPersona(ePersona*);
void delete_Persona(ePersona*);//Destructor


#endif // PERSONA_H_INCLUDED
