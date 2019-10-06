#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Localidad.h"
#include "Validaciones.h"

int buscarUnaLocalidadPorId(eLocalidad listaLocalidades[],int tamLocalidad,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        if(listaLocalidades[i].id==idABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void harcodearLocalidades(eLocalidad listaLocalidades[],int tamLocalidad)
{
    int codigoPostal[3]={1000,1500,2062};
    char nombreLocalidad[3][51]={"Avellaneda","Banfield","Lomas"};
    int id[3]={100,200,300};
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        listaLocalidades[i].codigoPostal=codigoPostal[i];
        strcpy(listaLocalidades[i].nombreLocalidad,nombreLocalidad[i]);
        listaLocalidades[i].id=id[i];
    }
}
void mostrarListaDeLocalidades(eLocalidad listaLocalidades[],int tamLocalidad)
{
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        mostrarUnaLocalidad(listaLocalidades[i]);
    }
}
void mostrarUnaLocalidad(eLocalidad unaLocalidad)
{
    printf("\n%s\t",unaLocalidad.nombreLocalidad);
    printf("%d\t",unaLocalidad.codigoPostal);
    printf("\t%d\n",unaLocalidad.id);
}
int buscarLocalidadPorNombre(eLocalidad listaLocalidades[],int tamLocalidad,char nombreLocalidad[])
{
    int retorno=-1;
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        if(strcmp(listaLocalidades[i].nombreLocalidad,nombreLocalidad)==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
