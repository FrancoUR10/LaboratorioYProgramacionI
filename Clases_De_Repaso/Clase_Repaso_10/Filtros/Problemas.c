#include "Problemas.h"
eProblemas* problema_nuevoProblema()
{
    eProblemas* listaProblemas=(eProblemas*)malloc(sizeof(eProblemas));
    return listaProblemas;
}
void problema_harcodearProblemas(LinkedList* listaProblemas)
{
    eProblemas* auxDatos=NULL;
    int id[5]={1,2,3,4,5};
    char descripcion[5][51]={"No enciende PC","No funciona mouse","No funciona teclado","No hay internet","No funciona telefono"};
    int i;
    if(listaProblemas!=NULL)
    {
        for(i=0;i<5;i++)
        {
            auxDatos=problema_nuevoProblema();
            if(auxDatos!=NULL)
            {
                auxDatos->id=id[i];
                strcpy(auxDatos->descripcion,descripcion[i]);
                ll_add(listaProblemas,auxDatos);
            }
        }
    }
}
int problema_buscarPorId(LinkedList* listaProblemas,int idABuscar)
{
    int retorno=-1;
    eProblemas* aux;
    int i;
    int len=ll_len(listaProblemas);
    if(listaProblemas!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eProblemas*)ll_get(listaProblemas,i);
            if(aux->id==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
