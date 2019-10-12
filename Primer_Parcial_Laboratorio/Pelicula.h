#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include "Genero.h"
typedef struct
{
    int codigo;
    char descripcion[51];
    int duracion;
    int idGenero;
} ePelicula;
void inicializarPelicula(ePelicula listaPeliculas[],int tamPelicula);
void harcodearPelicula(ePelicula listaPeliculas[],int tamPelicula);
void mostrarListadoPeliculas(ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGeneros);
void mostrarUnaPelicula(ePelicula unaPelicula,eGenero listaGeneros[],int indiceGenero);
int buscarCodigoPelicula(ePelicula listaPeliculas[],int tamPelicula,int valorABuscar);

#endif // PELICULA_H_INCLUDED
