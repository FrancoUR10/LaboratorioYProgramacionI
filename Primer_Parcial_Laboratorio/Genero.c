#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Pelicula.h"
#include "Genero.h"
#include "Actor.h"
#include "Elenco.h"

void harcodearGenero(eGenero listaGeneros[],int tamGeneros)
{

    int id[4]={100,200,300,400};
    char descripcion[4][51]={"Accion","Terror","Romance","Suspenso"};
    int i;
    for(i=0;i<tamGeneros;i++)
    {
        listaGeneros[i].id=id[i];
        strcpy(listaGeneros[i].descripcion,descripcion[i]);
    }
}
