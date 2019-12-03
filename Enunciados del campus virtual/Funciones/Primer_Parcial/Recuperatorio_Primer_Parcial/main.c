#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Direccion.h"
#include "Genero.h"
#include "Pelicula.h"
#include "Actor.h"
#include "Elenco.h"
#include "Pais.h"
#define MAX_GENERO 4
#define MAX_PELICULA 5
#define MAX_ACTOR 100
#define MAX_PAIS 5
#define MAX_DIRECCIONES 4

int main()
{
    eActor listaActores[MAX_ACTOR];
    eGenero listaGeneros[MAX_GENERO];
    ePelicula listaPeliculas[MAX_PELICULA];
    eElenco listaElencos[MAX_ACTOR*MAX_PELICULA];
    ePais listaPaises[MAX_PAIS];
    eDireccion listaDirecciones[MAX_DIRECCIONES];


    actor_inicializarDatos(listaActores,MAX_ACTOR);
    elenco_inicializarDatos(listaElencos,MAX_ACTOR*MAX_PELICULA);
    actor_harcodearDatos(listaActores);
    genero_harcodearDatos(listaGeneros);
    pelicula_harcodearDatos(listaPeliculas);
    elenco_harcodearDatos(listaElencos);
    pais_harcodearDatos(listaPaises);
    direccion_harcodearDatos(listaDirecciones);

    int contAltasActores=6;
    int contAltasElencos=6;

    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-GESTION DE ACTORES\n");
        printf("2-GESTION DE ELENCOS\n");
        printf("3-INFORMES\n");
        printf("4-INFORMES FINALES\n");
        printf("5-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                actor_gestionarActores(listaActores,MAX_ACTOR,listaPaises,MAX_PAIS,&contAltasActores,listaDirecciones,MAX_DIRECCIONES);
                break;
            case 2:
                elenco_gestionarElencos(listaElencos,MAX_ACTOR*MAX_PELICULA,listaActores,MAX_ACTOR,listaPeliculas,MAX_PELICULA,listaGeneros,MAX_GENERO,listaPaises,MAX_PAIS,&contAltasElencos,listaDirecciones,MAX_DIRECCIONES);
                break;
            case 3:
                elenco_informarDatos(listaElencos,MAX_ACTOR*MAX_PELICULA,listaActores,MAX_ACTOR,listaPeliculas,MAX_PELICULA,listaGeneros,MAX_GENERO,listaPaises,MAX_PAIS,listaDirecciones,MAX_DIRECCIONES);
                break;
            case 4:
                elenco_informesFinales(listaElencos,MAX_ACTOR*MAX_PELICULA,listaActores,MAX_ACTOR,listaPeliculas,MAX_PELICULA,listaGeneros,MAX_GENERO,listaPaises,MAX_PAIS,listaDirecciones,MAX_DIRECCIONES);
                break;
            case 5:
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
