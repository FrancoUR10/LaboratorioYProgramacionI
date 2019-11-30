#include "Genero.h"

void genero_harcodearDatos(eGenero listagenero[])
{
    int id[4]={1,2,3,4};
    char descripcion[4][51]={"Accion","Terror","Romance","Suspenso"};
    int i;
    for(i=0;i<4;i++)
    {
        listagenero[i].id=id[i];
        strcpy(listagenero[i].descripcion,descripcion[i]);
    }
}
void genero_mostrarUnoSolo(eGenero unagenero)
{
    printf("\n%d",unagenero.id);
    printf("%21s\n",unagenero.descripcion);
}
void genero_mostrarLista(eGenero listagenero[],int tamgenero)
{
    int i;
    printf("\nID            GENERO\n");
    for(i=0;i<tamgenero;i++)
    {
        genero_mostrarUnoSolo(listagenero[i]);
    }
}
int genero_buscarPorId(eGenero listagenero[],int tamgenero,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamgenero;i++)
    {
        if(listagenero[i].id==idABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
