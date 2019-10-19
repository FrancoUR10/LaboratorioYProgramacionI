#include <stdio.h>
#include <string.h>

#include "localidad.h"

eLocalidad construirLocalidad();
int cargarLocalidades(int cantidadRegistros, eLocalidad listado[]);
void mostrarLocalidad(eLocalidad localidad);
void mostrarListadoLocalidades(int cantidadRegistros, eLocalidad listado[]);


eLocalidad construirLocalidad()
{
    eLocalidad retornarLocalidad;
    printf("Ingrese el id: ");
    scanf("%d", &retornarLocalidad.id);

    printf("Ingrese la descripcion: ");
    fflush(stdin);
    gets(retornarLocalidad.descripcion);

    return retornarLocalidad;
}

int cargarLocalidades(int cantidadRegistros, eLocalidad listado[])
{
    int i;
    for(i=0; i<cantidadRegistros; i++)
    {
       listado[i]=construirLocalidad();
    }
    return 1;
}

void mostrarListadoLocalidades(int cantidadRegistros, eLocalidad listado[])
{
    int i;
    for(i=0; i<cantidadRegistros; i++)
    {
      mostrarLocalidad(listado[i]);
    }
}

void mostrarLocalidad(eLocalidad localidad)
{
    printf("\nCodigo :\t %d",localidad.id);
    printf("\nNombre :\t %s",localidad.descripcion);
    printf("\n------------------------");
}


