#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Fecha.h"
#include "Genero.h"
typedef struct
{
    int codigo;
    char descripcion[51];
    int duracion;
    int idGenero;
    eFecha fechaEstreno;
} ePelicula;
void inicializarPelicula(ePelicula listaPeliculas[],int tamPelicula);
void harcodearPelicula(ePelicula listaPeliculas[],int tamPelicula);
void mostrarListadoPeliculas(ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGeneros);
void mostrarUnaPelicula(ePelicula unaPelicula,eGenero listaGeneros[],int indiceGenero);
int buscarCodigoPelicula(ePelicula listaPeliculas[],int tamPelicula,int valorABuscar);
void ordenarListadoDePeliculas(ePelicula listaPeliculas[],int tamPelicula);
void mostrarPeliculaTerrorDespuesDe2002(ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero);

#endif // PELICULA_H_INCLUDED
