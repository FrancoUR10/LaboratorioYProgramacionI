#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Pelicula.h"
#include "Genero.h"
#include "Actor.h"
#include "Elenco.h"

void inicializarPelicula(ePelicula listaPeliculas[],int tamPelicula)
{
    int i;
    for(i=0;i<tamPelicula;i++)
    {
        listaPeliculas[i].codigo=-1;
        strcpy(listaPeliculas[i].descripcion,"VACIO");
        listaPeliculas[i].duracion=0;
        listaPeliculas[i].idGenero=-1;
    }
}
