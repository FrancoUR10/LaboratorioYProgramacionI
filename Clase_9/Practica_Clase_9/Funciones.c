#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define LIBRE 1
#define OCUPADO 0

int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
void inicializarArray(eAlumno unArray[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i].legajo=-1;
        unArray[i].nota=-1;
        strcpy(unArray[i].nombre,"VACIO");
        unArray[i].estaVacio=LIBRE;
    }
}
void ordenarInsercion(eAlumno unArray[],int tam)
{
    int i;
    int j;
    eAlumno auxArray;

    for(i=1;i<tam;i++)
    {
        auxArray=unArray[i];
        j=i-1;
        while((j >= 0) && (strcmp(auxArray.nombre,unArray[j].nombre)==-1))
        {
            unArray[j+1]=unArray[j];
            j--;
        }
        unArray[j+1]=auxArray;
    }
}
void harcodearAlumnos(eAlumno unArray[])
{
    char nombre[][256]={"Paulo","Abrahm","Beltran"};
    int nota[]={6,8,7};
    int legajo[]={55,88,64};
    int i;
    for(i=0;i<3;i++)
    {
        strcpy(unArray[i].nombre,nombre[i]);
        unArray[i].nota=nota[i];
        unArray[i].legajo=legajo[i];
        unArray[i].estaVacio=OCUPADO;
    }
}
void mostrarLista(eAlumno unArray[],int tam)
{
    int i;
    int indiceLibre;
    indiceLibre=buscarSoloEstado(unArray,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        printf("\nNOMBRE\tNOTA\tLEGAJO\n");
        for(i=0;i<tam;i++)
        {
            if(unArray[i].estaVacio==OCUPADO)
            {
                mostrarUnSoloAlumno(unArray,i);
            }
        }
    }
}
int buscarSoloEstado(eAlumno unArray[],int tam,int estado)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estaVacio==estado)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void mostrarUnSoloAlumno(eAlumno unAlumno[],int indice)
{
    printf("\n%s\t",unAlumno[indice].nombre);
    printf("%d\t",unAlumno[indice].nota);
    printf("%d\n",unAlumno[indice].legajo);
}
void cargarDatos(eAlumno unArray[],int tam)
{
    int auxLegajo;
    int indiceLibre;
    indiceLibre=buscarSoloEstado(unArray,tam,LIBRE);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxLegajo=getInt("Ingrese el legajo: ");
        if(buscarLegajo(unArray,tam,auxLegajo)!=-1)
        {
            printf("\nYa existe el legajo ingresado\n");
        }
        else
        {
            printf("Ingrese el nombre: ");
            gets(unArray[indiceLibre].nombre);
            fflush(stdin);

            unArray[indiceLibre].nota=getInt("Ingrese la nota: ");

            unArray[indiceLibre].estaVacio=OCUPADO;
            unArray[indiceLibre].legajo=auxLegajo;
        }
    }
}
void borrarDatos(eAlumno unArray[],int tam)
{
    int auxLegajo;
    int indiceResultadoDeBusqueda;
    int indiceLibre;
    indiceLibre=buscarSoloEstado(unArray,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        auxLegajo=getInt("Ingrese el legajo a borrar: ");
        indiceResultadoDeBusqueda=buscarLegajo(unArray,tam,auxLegajo);
        if(indiceResultadoDeBusqueda==-1)
        {
            printf("\nEl legajo ingresado no existe\n");
        }
        else
        {
            unArray[indiceResultadoDeBusqueda].estaVacio=LIBRE;
        }
    }
}
int buscarLegajo(eAlumno unArray[],int tam,int legajo)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if((unArray[i].legajo==legajo) && (unArray[i].estaVacio==OCUPADO))
        {
            retorno=i;
            break;
        }
    }
    return retorno;

}
void modificarDatos(eAlumno unArray[],int tam)
{
    int indiceResultadoDeBusqueda;
    int indiceLibre;
    indiceLibre=buscarSoloEstado(unArray,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        int auxLegajo;
        auxLegajo=getInt("Ingrese el legajo a modificar: ");
        indiceResultadoDeBusqueda=buscarLegajo(unArray,tam,auxLegajo);
        if(indiceResultadoDeBusqueda==-1)
        {
            printf("\nEl legajo ingresado no existe\n");
        }
        else
        {
            printf("Ingrese el nombre: ");
            gets(unArray[indiceLibre].nombre);
            fflush(stdin);

            unArray[indiceLibre].nota=getInt("Ingrese la nota: ");
        }
    }
}
