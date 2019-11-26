#include "Pilotos.h"

ePiloto* piloto_nuevapiloto()
{
    ePiloto* unapiloto=(ePiloto*)malloc(sizeof(ePiloto));
    return unapiloto;
}
int piloto_borrarpiloto(ePiloto* unapiloto)
{
    int seBorro=0;
    if(unapiloto!=NULL)
    {
        free(unapiloto);
        seBorro=1;
    }
    return seBorro;
}
void piloto_harcodearDatos(LinkedList* listapiloto)
{
    ePiloto* auxDatos=NULL;
    int id[5]={1,2,3,4,5};
    char nombreYApellido[5][51]={"Alex Lifeson","Richard Bach","John Kerry","Erwin Rommel","Stephen Coonts"};
    int i;
    for(i=0;i<5;i++)
    {
        auxDatos=piloto_nuevapiloto();
        if(auxDatos!=NULL)
        {
            auxDatos->id=id[i];
            strcpy(auxDatos->nombreYApellido,nombreYApellido[i]);
            ll_add(listapiloto,auxDatos);
        }
    }
}
int piloto_buscarPorId(LinkedList* listapiloto,int idABuscar)
{
    int retorno=-1;
    ePiloto* auxDatos;
    int i;
    int len=ll_len(listapiloto);
    if(listapiloto!=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxDatos=ll_get(listapiloto,i);
            if(auxDatos->id==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int piloto_mostrarUnapiloto(ePiloto* unapiloto)
{
    int seMostro=0;
    if(unapiloto!=NULL)
    {
        printf("\n%s",unapiloto->nombreYApellido);
        printf("%14d\n",unapiloto->id);
        seMostro=1;
    }
    return seMostro;
}
void piloto_mostrarListapilotoes(LinkedList* listapiloto)
{
    ePiloto* auxDatos;
    int i;
    int len=ll_len(listapiloto);
    if(listapiloto!=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxDatos=(ePiloto*)ll_get(listapiloto,i);
            piloto_mostrarUnapiloto(auxDatos);
        }
    }
}
int piloto_getId(ePiloto* piloto,int* id)
{
    int retorno=0;
    if(piloto!=NULL && id!=NULL)
    {
        *id=piloto->id;
        retorno=1;
    }
    return retorno;
}
int piloto_getNombreYApellido(ePiloto* piloto,char* nombreYApellido)
{
    int retorno=0;
    if(piloto!=NULL && nombreYApellido!=NULL)
    {
        strcpy(nombreYApellido,piloto->nombreYApellido);
        retorno=1;
    }
    return retorno;
}
