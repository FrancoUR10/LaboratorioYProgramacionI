#include "Persona.h"

ePersona* persona_newPersona()
{
    ePersona* unaPersona=(ePersona*)malloc(sizeof(ePersona));
    if(unaPersona!=NULL)
    {
        unaPersona->id=0;
        strcpy(unaPersona->nombre,"VACIO");
        unaPersona->edad=0;
    }
    return unaPersona;
}
int persona_liberarPersona(ePersona* unaPersona)
{
    int seLibero=0;
    if(unaPersona!=NULL)
    {
        free(unaPersona);
        seLibero=1;
    }
    return seLibero;
}
int persona_setIdPersona(ePersona* unaPersona,int id)
{
    int retorno=0;
    if((unaPersona != NULL) && (id > 0))
    {
        unaPersona->id=id;
        retorno=1;
    }
    return retorno;
}
int persona_setNombrePersona(ePersona* unaPersona,char* nombre)
{
    int retorno=0;
    if((unaPersona != NULL) && (strlen(nombre) > 2))
    {
        strcpy(unaPersona->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int persona_setEdadPersona(ePersona* unaPersona,int edad)
{
    int retorno=0;
    if((unaPersona != NULL) && (edad > 0))
    {
        unaPersona->edad=edad;
        retorno=1;
    }
    return retorno;
}
int persona_getIdPersona(ePersona* unaPersona,int* id)
{
    int retorno=0;
    if(unaPersona!=NULL)
    {
        *id=unaPersona->id;
        retorno=1;
    }
    return retorno;
}
int persona_getNombrePersona(ePersona* unaPersona,char* nombre)
{
    int retorno=0;
    if(unaPersona!=NULL)
    {
        strcpy(nombre,unaPersona->nombre);
        retorno=1;
    }
    return retorno;
}
int persona_getEdadPersona(ePersona* unaPersona,int* edad)
{
    int retorno=0;
    if(unaPersona!=NULL)
    {
        *edad=unaPersona->edad;
        retorno=1;
    }
    return retorno;
}
ePersona* persona_newPersonaParametros(char* id,char* nombre,char* edad)
{
    ePersona* unaPersona=NULL;
    if((id != NULL) && (nombre!= NULL) && (edad != NULL))
    {
        unaPersona=persona_newPersona();
        if(unaPersona!=NULL)
        {
            if(!persona_setIdPersona(unaPersona,atoi(id)) || !persona_setNombrePersona(unaPersona,nombre) || !persona_setEdadPersona(unaPersona,atoi(edad)))
            {
                persona_liberarPersona(unaPersona);
                unaPersona=NULL;
            }
        }
    }
    return unaPersona;
}
int mostrarUnaPersona(ePersona* unaPersona)
{
    int seMostro=0;
    if(unaPersona!=NULL)
    {
        printf("%d\t",unaPersona->id);
        printf("%s\t",unaPersona->nombre);
        printf("%d\n",unaPersona->edad);
        seMostro=1;
    }
    return seMostro;
}
