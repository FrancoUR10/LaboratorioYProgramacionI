#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
typedef struct
{
    int codigo;
    char descripcion[51];
    int duracion;
    int idGenero;
} ePelicula;
void inicializarPelicula(ePelicula listaPeliculas[],int tamPelicula);

#endif // PELICULA_H_INCLUDED
