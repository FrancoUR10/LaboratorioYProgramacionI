#include "Pais.h"

void pais_harcodearDatos(ePais listapais[])
{
    int id[5]={1,2,3,4,5};
    char descripcion[5][51]={"Argentina","Peru","Bolivia","Paraguay","Brasil"};;
    int i;
    for(i=0;i<5;i++)
    {
        listapais[i].id=id[i];
        strcpy(listapais[i].descripcion,descripcion[i]);
    }
}
void pais_mostrarUnoSolo(ePais unapais)
{
    printf("\n%d",unapais.id);
    printf("%21s\n",unapais.descripcion);
}
void pais_mostrarLista(ePais listapais[],int tampais)
{
    int i;
    printf("\nID            DESCRIPCION\n");
    for(i=0;i<tampais;i++)
    {
        pais_mostrarUnoSolo(listapais[i]);
    }
}
int pais_buscarPorId(ePais listapais[],int tampais,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tampais;i++)
    {
        if(listapais[i].id==idABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
