#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Localidad.h"
#include "Validaciones.h"

int buscarUnaLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        if(unaLocalidad[i].id==idABuscar)
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
    }
}
void mostrarListaDeLocalidades(eLocalidad listaLocalidades[],int tamLocalidad)
{
    int i;
    printf("\nLOCALIDAD\tCODIGO POSTAL\tID\n");
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
