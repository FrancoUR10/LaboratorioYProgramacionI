#include <stdio.h>
#include <string.h>
#include "persona.h"

ePersona construirPersona(int idLocalidad)
{
    ePersona retornarPersona;

    printf("Ingrese el id: ");
    scanf("%d", &retornarPersona.id);

    printf("Ingrese la nombre: ");
    fflush(stdin);
    gets(retornarPersona.nombre);

    printf("Ingrese la apellido: ");
    fflush(stdin);
    gets(retornarPersona.apellido);

    printf("Ingrese la edad: ");
    scanf("%d", &retornarPersona.edad);

    retornarPersona.idLocalidad = idLocalidad;

    return retornarPersona;

}

void mostrarListadoPersonas(int cantidadRegistros, ePersona listado[])
{
    int i;
    for(i=0; i<cantidadRegistros; i++)
    {
      mostrarPersona(listado[i]);
    }
}

void mostrarPersona(ePersona persona)
{
    printf("\nId :\t %d",persona.id);
    printf("\nNombre :\t %s",persona.nombre);
    printf("\nApellido :\t %s",persona.apellido);
    printf("\nEdad :\t %s",persona.edad);
    printf("\nLocalidad :\t %s",persona.idLocalidad);
    printf("\n------------------------");
}

void inicializarListado(int cantidadRegistros, ePersona listado[])
{
    int i;
    for(i=0; i<cantidadRegistros; i++)
    {
      listado[i].estado = 0;
    }
}

int buscarLugar(int cantidadRegistros, ePersona listado[])
{
    int i;
    int retorno = -1;
    for(i=0; i<cantidadRegistros; i++)
    {
      if (listado[i].estado == 0) {
         return i;
      }
    }

    return retorno;
}

int cargarPersona(int cantidadRegistros, ePersona listado[])
{
    int indice;
    indice=buscarLugar(cantidadRegistros, listado);
    if(indice!=-1) {
        listado[indice] = construirPersona(3);
    }
    return indice;
}
int borrarPersona(int cantidadRegistros, ePersona listado[], ePersona persona)
{
    int indice;
    indice=buscarPersona(cantidadRegistros, listado, persona);
    if(indice!=-1) {
        listado[indice].estado = 1;
    }
    return indice;
}
int buscarPersona(int cantidadRegistros, ePersona listado[], ePersona persona)
{
    int i;
    for(i=0; i<cantidadRegistros; i++) {
      if (listado[i].id == persona.id) {
         return i;
      }
    }
    return -1;
}
