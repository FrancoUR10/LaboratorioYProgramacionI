#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

int main()
{
    int seLibero;
    ePersona* unaPersona=NULL;
    unaPersona=persona_newPersonaParametros("1","Juan","18");
    mostrarUnaPersona(unaPersona);
    seLibero=persona_liberarPersona(unaPersona);
    printf("\nSe libero la memoria: %d\n",seLibero);
    return 0;
}
