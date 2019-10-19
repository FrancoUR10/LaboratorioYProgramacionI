#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Pelicula.h"
#include "Genero.h"
#include "Actor.h"
#include "Elenco.h"
#define MAX_PELICULA 1000
#define MAX_GENERO 4
#define MAX_ACTOR 1000
#define MAX_ELENCO 1000

int main()
{
    ePelicula listaPeliculas[MAX_PELICULA];
    eGenero listaGeneros[MAX_GENERO];
    eActor listaActores[MAX_ACTOR];
    eElenco listaElencos[MAX_ELENCO];
    int contAltasActores=4;
    int contAltasElencos=4;
    int opcionMenu;
    char continuarMenu='s';

    inicializarPelicula(listaPeliculas,MAX_PELICULA);
    inicializarActores(listaActores,MAX_ACTOR);
    inicializarElenco(listaElencos,MAX_ELENCO);

    harcodearPelicula(listaPeliculas,4);
    harcodearActores(listaActores,3);
    harcodearGenero(listaGeneros,MAX_GENERO);
    harcodearElenco(listaElencos,3);


    do
    {
        opcionMenu=getInt("1-GESTION DE ACTORES\n2-GESTION DE ELENCOS\n3-SALIR\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                menuGestionarActores(listaActores,MAX_ACTOR,&contAltasActores);
                break;
            case 2:
                menuGestionarElencos(listaElencos,MAX_ELENCO,listaActores,MAX_ACTOR,listaPeliculas,MAX_PELICULA,listaGeneros,MAX_GENERO,&contAltasElencos);
                break;
            case 3:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\a\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');


    return 0;
}
