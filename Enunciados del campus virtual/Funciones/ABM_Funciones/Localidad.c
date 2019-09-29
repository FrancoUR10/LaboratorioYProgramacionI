#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Localidad.h"
#include "Validaciones.h"
#define LOCALIDAD_LIBRE 1
#define LOCALIDAD_OCUPADA 0

int buscarUnaLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        if((unaLocalidad[i].estado==LOCALIDAD_OCUPADA) && (unaLocalidad[i].id==idABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int buscarSoloEstadoLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int estadoLocalidad)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        if(unaLocalidad[i].estado==estadoLocalidad)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void harcodearLocalidades(eLocalidad unaLocalidad[],int tamLocalidad)
{
    int codigoPostal[3]={1000,1500,2062};
    char nombreLocalidad[3][51]={"Avellaneda","Banfield","Lomas"};
    int id[3]={100,200,300};
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        unaLocalidad[i].codigoPostal=codigoPostal[i];
        strcpy(unaLocalidad[i].nombreLocalidad,nombreLocalidad[i]);
        unaLocalidad[i].id=id[i];
        unaLocalidad[i].estado=LOCALIDAD_OCUPADA;
    }
}
void mostrarListaDeLocalidades(eLocalidad listaLocalidades[],int tamLocalidad)
{
    int indiceLibre;
    int i;
    indiceLibre=buscarSoloEstadoLocalidad(listaLocalidades,tamLocalidad,LOCALIDAD_OCUPADA);
    if(indiceLibre==-1)
    {
        printf("\nNo existe ninguna localidad a mostrar\n");
    }
    else
    {
        printf("\nLOCALIDAD\tID\n");
        for(i=0;i<tamLocalidad;i++)
        {
            if(listaLocalidades[i].estado==LOCALIDAD_OCUPADA)
            {
                mostrarUnaLocalidad(listaLocalidades,i);
            }
        }

    }
}
void mostrarUnaLocalidad(eLocalidad unaLocalidad[],int indiceLocalidad)
{
    printf("\n%s\t",unaLocalidad[indiceLocalidad].nombreLocalidad);
    printf("%d\n",unaLocalidad[indiceLocalidad].id);
}
