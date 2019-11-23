#include "Problema.h"
/*
1 No enciende PC
2 No funciona mouse
3 No funciona teclado
4 No hay internet
5 No funciona teléfono
*/
eProblema* problema_nuevoProblema()
{
    eProblema* unProblema=(eProblema*)malloc(sizeof(eProblema));
    return unProblema;
}
void problema_harcodearProblemas(LinkedList* listaProblemas)
{
    eProblema* aux;
    int id[5]={1,2,3,4,5};
    char descripcion[5][51]={"No enciende PC","NO funciona mouse","No funciona teclado","No hay internet","No funciona telefono"};
    int i;
    for(i=0;i<5;i++)
    {
        aux=problema_nuevoProblema();
        if(aux!=NULL)
        {
            aux->id=id[i];
            strcpy(aux->descripcion,descripcion[i]);
            ll_add(listaProblemas,aux);
        }
    }
}
int problema_buscarPorId(LinkedList* listaProblemas,int idABuscar)
{
    int retorno=-1;
    eProblema* aux;
    int i;
    int len=ll_len(listaProblemas);
    if(listaProblemas!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eProblema*)ll_get(listaProblemas,i);
            if(aux->id==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
