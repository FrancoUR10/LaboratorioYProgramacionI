#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define OCUPADO 0
#define LIBRE 1

void inicializarListadoAlumnos(eAlumno listaAlumnos[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        listaAlumnos[i].estaVacio=LIBRE;
        listaAlumnos[i].legajo=-1;
        strcpy(listaAlumnos[i].nombre,"VACIO");
        listaAlumnos[i].nota=-1;
    }
}
void listarAlumnos(eAlumno listaAlumnos[],int tam)
{
    int indiceLibre;
    int i;
    indiceLibre=buscarSoloEstado(listaAlumnos,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nNo hay ningun alumno en la lista\n");
    }
    else
    {
        for(i=0;i<tam;i++)
        {
            if(listaAlumnos[i].estaVacio==OCUPADO)
            {
                printf("\nLegajo: %d --Nombre: %s --Nota: %d\n",listaAlumnos[i].legajo,listaAlumnos[i].nombre,listaAlumnos[i].nota);
            }
        }
    }
}
int buscarSoloEstado(eAlumno listaAlumnos[],int tam,int estadoActual)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(listaAlumnos[i].estaVacio==estadoActual)
        {
            retorno=i;
        }
    }
    return retorno;
}
void harcodearListaDeAlumnos(eAlumno listaAlumnos[],int indice)
{
    strcpy(listaAlumnos[indice].nombre,"Paulo");
    listaAlumnos[indice].nota=5;
    listaAlumnos[indice].legajo=55;
    listaAlumnos[indice].estaVacio=OCUPADO;
}
int buscarPorLegajo(eAlumno listaAlumnos[],int tam, int valorABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(listaAlumnos[i].legajo==valorABuscar)
        {
            retorno=i;
        }
    }
    return retorno;
}
void cargarDatosTest(eAlumno listaAlumnos[],int tam) //Carga datos sin validarlos
{
    int indiceLibre;
    indiceLibre=buscarPorLegajo(listaAlumnos,tam,-1);
    if(indiceLibre==-1)
    {
        printf("\nNo hay lugar libre\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d",&listaAlumnos[indiceLibre].legajo);
        fflush(stdin);

        printf("Ingrese nombre: ");
        gets(listaAlumnos[indiceLibre].nombre);
        fflush(stdin);

        printf("Ingrese nota: ");
        scanf("%d",&listaAlumnos[indiceLibre].nota);
        fflush(stdin);

        listaAlumnos[indiceLibre].estaVacio=OCUPADO;
    }
}
