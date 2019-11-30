#include "Localidad.h"

void localidad_harcodearDatos(eLocalidad listaLocalidad[])
{
    int id[5]={100,200,300,400,500};
    char descripcion[5][51]={"Avellaneda","Lomas","Temperley","Belgrano","Wilde"};;
    int i;
    for(i=0;i<5;i++)
    {
        listaLocalidad[i].id=id[i];
        strcpy(listaLocalidad[i].descripcion,descripcion[i]);
    }
}
void localidad_mostrarUnoSolo(eLocalidad unaLocalidad)
{
    printf("\n%d",unaLocalidad.id);
    printf("%21s\n",unaLocalidad.descripcion);
}
void localidad_mostrarLista(eLocalidad listaLocalidad[],int tamLocalidad)
{
    int i;
    printf("\nID            DESCRIPCION\n");
    for(i=0;i<tamLocalidad;i++)
    {
        localidad_mostrarUnoSolo(listaLocalidad[i]);
    }
}
int localidad_buscarPorId(eLocalidad listaLocalidad[],int tamLocalidad,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        if(listaLocalidad[i].id==idABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
