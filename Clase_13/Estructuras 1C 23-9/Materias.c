#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "Materias.h"
#define MATERIA_LIBRE 1
#define MATERIA_OCUPADA 0

void harcodearMaterias(eMateria listaMaterias[],int tamMaterias)
{
    int idMateria[4]={100,101,102,103};
    char descripcion[4][51]={"ProgramacionI","LaboratorioI","MATEMATICAI","SPD"};
    int cargaHoraria[4]={4,4,5,4};
    int i;
    for(i=0;i<tamMaterias;i++)
    {
        listaMaterias[i].idMateria=idMateria[i];
        strcpy(listaMaterias[i].descripcion,descripcion[i]);
        listaMaterias[i].cargaHoraria=cargaHoraria[i];
        listaMaterias[i].estadoMateria=MATERIA_OCUPADA;
    }
}
void mostrarMaterias(eMateria listaMaterias[],int tamMaterias)
{
    int i;
    for(i=0;i<tamMaterias;i++)
    {
        mostrarUnaMateria(listaMaterias,i);
    }
}
void mostrarUnaMateria(eMateria unaMateria[],int indiceMateria)
{
    printf("\n%d\t",unaMateria[indiceMateria].idMateria);
    printf("%s\t",unaMateria[indiceMateria].descripcion);
    printf("%d\n",unaMateria[indiceMateria].cargaHoraria);
}
int buscarMateriaLibre(eMateria listaMaterias[], int tamMaterias)
{
    int indice = -1;
    int i;
    for(i=0; i<tamMaterias; i++)
    {
        if(listaMaterias[i].estadoMateria==MATERIA_LIBRE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
