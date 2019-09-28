#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Localidad.h"

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
