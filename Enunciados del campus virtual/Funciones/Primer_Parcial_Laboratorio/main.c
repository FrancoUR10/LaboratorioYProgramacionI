#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Genero.h"
#include "Pelicula.h"
#include "Actor.h"
#include "Elenco.h"
#include "Pais.h"
#define MAX_GENERO 4
#define MAX_PELICULA 5
#define MAX_ACTOR 100
#define MAX_PAIS 5
int main()
{
    eActor listaActores[MAX_ACTOR];
    eGenero listaGeneros[MAX_GENERO];
    ePelicula listaPeliculas[MAX_PELICULA];
    eElenco listaElencos[MAX_ACTOR*MAX_PELICULA];
    ePais listaPaises[MAX_PAIS];


    actor_inicializarDatos(listaActores,MAX_ACTOR);
    elenco_inicializarDatos(listaElencos,MAX_ACTOR*MAX_PELICULA);
    actor_harcodearDatos(listaActores);
    genero_harcodearDatos(listaGeneros);
    pelicula_harcodearDatos(listaPeliculas);
    elenco_harcodearDatos(listaElencos);
    pais_harcodearDatos(listaPaises);

    int contAltas=6;

    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-GESTION DE ACTORES\n");
        printf("2-GESTION DE ELENCOS\n");
        printf("3-INFORMES\n");
        printf("4-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                actor_gestionarActores(listaActores,MAX_ACTOR,listaPaises,MAX_PAIS,&contAltas);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');

    return 0;
}
