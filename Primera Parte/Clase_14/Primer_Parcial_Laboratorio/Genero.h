#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char descripcion[51];
}eGenero;

void harcodearGenero(eGenero listaGeneros[],int tamGeneros);
int buscarGeneroDeTerror(eGenero listaGeneros[],int tamGenero);
#endif // GENERO_H_INCLUDED
