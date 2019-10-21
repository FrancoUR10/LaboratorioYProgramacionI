#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char descripcion[51];
}ePais;

void harcodearPaises(ePais listaPais[],int tamPais);
int buscarPaisPorId(ePais listaPais[],int tamPais,int idABuscar);
void mostrarSoloUnPais(ePais unPais);
void mostrarListadoDePaises(ePais listaPais[],int tamPais);
int buscarNacionalidadArgentina(ePais listaPais[],int tamPais);
#endif // PAIS_H_INCLUDED
