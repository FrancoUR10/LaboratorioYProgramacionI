#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "Materias.h"
#include "Inscripciones.h"
#define OCUPADO 1
#define LIBRE 0

void darDeAltaInscripcion(eMateria listaMaterias[], int tamMaterias,eAlumno listaAlumno[],int tamAlumno,eInscripciones listaInscripcion[],int tamInscripcion,eLocalidad listalocalidad[],int tamLocalidad)
{
    int idInscripcion;
    int legajoAlumno;
    int idMateria;
    eFecha fechaInscripcion;
    int indiceMaterias;
    int indiceLibre;
    indiceMaterias=buscarMateriaLibre(listaMaterias,tamMaterias);
    printf("Indice: %d\n", indiceMaterias);
    if(indiceMaterias==-1)
    {
        printf("\nNo hay espacio disponible\n");
    }
    else
    {
        indiceLibre=buscarInscripcionLibre(listaInscripcion,tamInscripcion);
        printf("\nIngrese ID inscripcion: ");
        scanf("%d",&idInscripcion);
        fflush(stdin);

        mostrarListadoAlumnos(listaAlumno,tamAlumno,listalocalidad,tamLocalidad);
        printf("\nIngrese legajo del alumno: ");
        scanf("%d",&legajoAlumno);
        fflush(stdin);

        mostrarMaterias(listaMaterias,tamMaterias);
        printf("\nIngrese el id de la materia: ");
        scanf("%d",&idMateria);
        fflush(stdin);

        printf("\nIngrese la fecha de inscripcion: ");
        scanf("%d/%d/%d",&fechaInscripcion.dia,&fechaInscripcion.mes,&fechaInscripcion.anio);
        fflush(stdin);

        listaInscripcion[indiceLibre].idInscripcion=idInscripcion;
        listaInscripcion[indiceLibre].legajoAlumno=legajoAlumno;
        listaInscripcion[indiceLibre].idMateria=idMateria;
        listaInscripcion[indiceLibre].fechaInscripcion=fechaInscripcion;
        listaInscripcion[indiceLibre].estadoInscripcion=OCUPADO;

    }

}
void mostrarInscripciones(eInscripciones listaInscripcion[],int tamInscripcion,eAlumno listaAlumno[],int tamAlumno,eMateria listaMateria[],int tamMateria)
{
    int i;
    int j;
    int k;
    for(i=0;i<tamInscripcion;i++)
    {
        for(j=0;j<tamAlumno;j++)
        {
            for(k=0;k<tamMateria;k++)
            {
                if((listaInscripcion[i].estadoInscripcion==OCUPADO) && (listaInscripcion[i].legajoAlumno==listaAlumno[j].legajo) && (listaInscripcion[i].idMateria==listaMateria[k].idMateria))
                {
                    mostrarUnaInscripcion(listaInscripcion,i,listaAlumno,j,listaMateria,k);
                }
            }
        }
    }
}
void mostrarUnaInscripcion(eInscripciones unaInscripcion[],int indiceInscripcion,eAlumno unAlumno[],int indiceAlumno,eMateria unaMateria[],int indiceMateria)
{
    printf("\n%d\t",unaInscripcion[indiceInscripcion].idInscripcion);
    printf("%s\t",unAlumno[indiceAlumno].nombre);
    printf("%s\t",unaMateria[indiceMateria].descripcion);
    printf("%d/%d/%d\n",unaInscripcion[indiceInscripcion].fechaInscripcion.dia,unaInscripcion[indiceInscripcion].fechaInscripcion.mes,unaInscripcion[indiceInscripcion].fechaInscripcion.anio);
}
void inicializarInscripcion(eInscripciones listaInscripciones[],int tamInscripcion)
{
    int i;
    for(i=0;i<tamInscripcion;i++)
    {
        listaInscripciones[i].estadoInscripcion=LIBRE;
        listaInscripciones[i].idInscripcion=-1;
    }
}
int buscarInscripcionLibre(eInscripciones listaInscripciones[], int tamInscripciones)
{
    int indice = -1;
    int i;
    for(i=0; i<tamInscripciones; i++)
    {
        if(listaInscripciones[i].estadoInscripcion==LIBRE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
