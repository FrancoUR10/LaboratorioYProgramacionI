#include "Localidad.h"

eLocalidad* localidad_nuevaLocalidad()
{
    eLocalidad* unaLocalidad=(eLocalidad*)malloc(sizeof(eLocalidad));
    return unaLocalidad;
}
int localidad_borrarLocalidad(eLocalidad* unaLocalidad)
{
    int seBorro=0;
    if(unaLocalidad!=NULL)
    {
        free(unaLocalidad);
        seBorro=1;
    }
    return seBorro;
}
void localidad_harcodearDatos(LinkedList* listaLocalidad)
{
    eLocalidad* auxDatos=NULL;
    int id[5]={100,200,300,400,500};
    char descripcion[5][51]={"Avellaneda","Banfield","Lomas","Wilde","Temperley"};
    int i;
    for(i=0;i<5;i++)
    {
        auxDatos=localidad_nuevaLocalidad();
        if(auxDatos!=NULL)
        {
            auxDatos->id=id[i];
            strcpy(auxDatos->descripcion,descripcion[i]);
            ll_add(listaLocalidad,auxDatos);
        }
    }
}
int localidad_buscarPorId(LinkedList* listaLocalidad,int idABuscar)
{
    int retorno=-1;
    eLocalidad* auxDatos;
    int i;
    int len=ll_len(listaLocalidad);
    if(listaLocalidad!=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxDatos=ll_get(listaLocalidad,i);
            if(auxDatos->id==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int localidad_mostrarUnaLocalidad(eLocalidad* unaLocalidad)
{
    int seMostro=0;
    if(unaLocalidad!=NULL)
    {
        printf("\n%s",unaLocalidad->descripcion);
        printf("%14d\n",unaLocalidad->id);
        seMostro=1;
    }
    return seMostro;
}
void localidad_mostrarListaLocalidades(LinkedList* listaLocalidad)
{
    eLocalidad* auxDatos;
    int i;
    int len=ll_len(listaLocalidad);
    if(listaLocalidad!=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxDatos=(eLocalidad*)ll_get(listaLocalidad,i);
            localidad_mostrarUnaLocalidad(auxDatos);
        }
    }
}
