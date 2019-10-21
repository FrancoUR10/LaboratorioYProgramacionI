#include "Pais.h"

void harcodearPaises(ePais listaPais[],int tamPais)
{
    char descripcion[3][51]={"Argentina","Peru","Paraguay"};
    int id[3]={1,2,3};
    int i;
    for(i=0;i<tamPais;i++)
    {
        strcpy(listaPais[i].descripcion,descripcion[i]);
        listaPais[i].id=id[i];
    }
}
int buscarPaisPorId(ePais listaPais[],int tamPais,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamPais;i++)
    {
        if(listaPais[i].id==idABuscar)
        {
            retorno=i;
            break;
        }

    }
    return retorno;
}
void mostrarSoloUnPais(ePais unPais)
{
    printf("\n%10s",unPais.descripcion);
    printf("\t%4d",unPais.id);
}
void mostrarListadoDePaises(ePais listaPais[],int tamPais)
{
    int i;
    printf("\nNACION\t          ID\n");
    for(i=0;i<tamPais;i++)
    {
        mostrarSoloUnPais(listaPais[i]);
    }
}
int buscarNacionalidadArgentina(ePais listaPais[],int tamPais)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamPais;i++)
    {
        if(strcmp(listaPais[i].descripcion,"Argentina")==0)
        {
            retorno=listaPais[i].id;
            break;
        }
    }
    return retorno;
}
