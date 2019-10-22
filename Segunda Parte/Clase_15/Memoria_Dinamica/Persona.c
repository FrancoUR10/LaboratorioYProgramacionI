#include "Persona.h"
ePersona* new_Persona()
{
    ePersona* puntero;

    puntero = (ePersona*) malloc(sizeof(ePersona));

    return puntero;
}
void mostrarPersona(ePersona* puntero)
{
    if(puntero!=NULL)
    {
        printf("La persona es:\n");
        printf("%d--%c--%.2f",puntero->legajo,puntero->sexo,puntero->altura);
    }
}
void delete_Persona(ePersona* puntero)
{
    free(puntero);
    puntero=NULL;
}
ePersona* new_Persona_Parametros(int legajo,char sexo,float altura)
{
    ePersona* puntero;
    puntero =new_Persona();
    if(puntero!=NULL)
    {
        puntero->legajo=legajo;
        puntero->sexo=sexo;
        puntero->altura=altura;
    }
    return puntero;
}

void setLegajo(ePersona* unaPersona,int legajo)
{
    if(legajo>0)
    {
        unaPersona->legajo=legajo;
    }
}
int getLegajo(ePersona* unaPersona)
{
    return unaPersona->legajo;
}
