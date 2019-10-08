#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Pelicula.h"
#include "Genero.h"
#include "Actor.h"
#include "Elenco.h"

void inicializarElenco(eElenco listaElencos[],int tamElenco)
{
    int i;
    for(i=0;i<tamElenco;i++)
    {
        listaElencos[i].codigoPelicula=-1;
        listaElencos[i].codigoActor=-1;
        listaElencos[i].valorContrato=0;
    }
}

void ordenarElencos(eElenco listaElencos[],int tamElencos)
{
    int i;
    int j;
    eElenco auxiliar;
    for(i=0;i<tamElencos-1;i++)
    {
        for(j=i+1;j<tamElencos;j++)
        {
            if(listaElencos[i].codigoPelicula>listaElencos[j].codigoPelicula)
            {
                auxiliar=listaElencos[i];
                listaElencos[i]=listaElencos[j];
                listaElencos[j]=auxiliar;
            }
            else if(listaElencos[i].codigoPelicula==listaElencos[j].codigoPelicula)
            {
                if(listaElencos[i].codigoActor>listaElencos[j].codigoActor)
                {
                    auxiliar=listaElencos[i];
                    listaElencos[i]=listaElencos[j];
                    listaElencos[j]=auxiliar;
                }
            }
        }
    }
}
