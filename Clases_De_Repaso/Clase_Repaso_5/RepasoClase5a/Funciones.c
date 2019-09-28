#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define LIBRE 1
#define OCUPADO 0

int getInt(char* mensaje)
{
    int auxInt;
    printf("%s",mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
float getFloat(char* mensaje)
{
    float auxFloat;
    printf("%s",mensaje);
    scanf("%f",&auxFloat);
    fflush(stdin);
    return auxFloat;
}
char getChar(char* mensaje)
{
    char auxChar;
    printf("%s",mensaje);
    scanf("%c",&auxChar);
    fflush(stdin);
    return auxChar;
}
void getString(char* mensaje,char array[])
{
    printf("%s",mensaje);
    gets(array);
    fflush(stdin);
}
void inicializarAlumnos(eAlumno listaAlumnos[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        listaAlumnos[i].legajo=-1;
        strcpy(listaAlumnos[i].nombre,"VACIO");
        listaAlumnos[i].nota=0;
        listaAlumnos[i].idLocalidad=-1;
        listaAlumnos[i].estado=LIBRE;
    }
}
void harcodearAlumnos(eAlumno listaAlumnos[],int tam)
{
    int i;
    char nombre[3][51]={"A","B","C"};
    int nota[3]={4,5,6};
    int legajo[3]={1,2,3};
    int idLocalidad[3]={200,300,400};
    for(i=0;i<tam;i++)
    {
        strcpy(listaAlumnos[i].nombre,nombre[i]);
        listaAlumnos[i].nota=nota[i];
        listaAlumnos[i].legajo=legajo[i];
        listaAlumnos[i].idLocalidad=idLocalidad[i];
        listaAlumnos[i].estado=OCUPADO;
    }
}
void mostrarListaAlumnos(eAlumno listaAlumnos[],int tam,eLocalidad listaLocalidades[],int tamLocalidades)
{
    int i;
    int j;
    int indiceLibre;
    indiceLibre=buscarSoloEstado(listaAlumnos,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nNo hay ningun alumno en la lista\n");
    }
    else
    {
        indiceLocalidad=buscarIdLocalidad(listaLocalidades,tamLocalidades,0);
        printf("\nNOMBRE\tNOTA\tLEGAJO\tLOCALIDAD\n");
        for(i=0;i<tam;i++)
        {
            if(listaAlumnos[i].estado==OCUPADO)
            {
                mostrarUnAlumno(listaAlumnos,i,listaLocalidades,j);
            }
        }
    }
}
void mostrarUnAlumno(eAlumno unAlumno[],int indice,eLocalidad unaLocalidad[],int indiceLocalidad)
{
    printf("%s\t",unAlumno[indice].nombre);
    printf("%d\t",unAlumno[indice].nota);
    printf("%d\t",unAlumno[indice].legajo);
    //printf("%d\n",unAlumno[indice].idLocalidad);
    printf("%s\n",unaLocalidad[indiceLocalidad].localidad);
}
void harcodearLocalidad(eLocalidad listaLocalidades[],int tamLocalidades)
{
    char nombreLocalidad[3][51]={"Avellaneda","Lomas","Banfield"};
    int codigoPostal[3]={1065,1003,1900};
    int idLocalidad[3]={200,300,400};
    int i;
    for(i=0;i<tamLocalidades;i++)
    {
        strcpy(listaLocalidades[i].localidad,nombreLocalidad[i]);
        listaLocalidades[i].codigoPostal=codigoPostal[i];
        listaLocalidades[i].id=idLocalidad[i];
    }
}
int buscarLugarLibre(eAlumno unAlumno[],int tam,int valorABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if((unAlumno[i].estado==OCUPADO) && (unAlumno[i].legajo==valorABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int buscarSoloEstado(eAlumno unAlumno[],int tam,int estado)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if((unAlumno[i].estado==estado))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int buscarIdLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        if((unaLocalidad[i].id==idABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
