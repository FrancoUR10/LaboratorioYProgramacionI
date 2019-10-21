#include "Genero.h"


void harcodearGenero(eGenero listaGeneros[],int tamGeneros)
{

    int id[4]={100,200,300,400};
    char descripcion[4][51]={"Accion","Terror","Romance","Suspenso"};
    int i;
    for(i=0;i<tamGeneros;i++)
    {
        listaGeneros[i].id=id[i];
        strcpy(listaGeneros[i].descripcion,descripcion[i]);
    }
}
int buscarGeneroDeTerror(eGenero listaGeneros[],int tamGenero)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamGenero;i++)
    {
        if(strcmp(listaGeneros[i].descripcion,"Terror")==0)
        {
            retorno=listaGeneros[i].id;
            break;
        }
    }
    return retorno;
}
