#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
//Polimorfismo, encapsulamiento.
//Ver puntero a estructura, operador flecha.
/*
    ePersona p;
    ePersona* puntero= &p;
*/

int main()
{
    ePersona* puntero=new_Persona_Parametros(1000,'M',1.98);
    //setter//puntero->altura=1.70;
    setLegajo(puntero,1001);
    mostrarPersona(puntero);
    delete_Persona(puntero);

    if(puntero!=NULL)
    {
        printf("La persona es:\n");
        if(getLegajo(puntero)>1000)
        {
            mostrarPersona(puntero);
        }
    }

    return 0;
}
