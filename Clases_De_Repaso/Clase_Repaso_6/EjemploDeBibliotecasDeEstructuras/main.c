#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "localidad.h"
#include "persona.h"


int main()
{
    eLocalidad unaLocalidadAux;
    strcpy(unaLocalidadAux.descripcion,"tandil");
    printf("Hola %s",unaLocalidadAux.descripcion);

    eFecha hoy ;
    hoy= construirFecha(19,10,2019);
    return 0;
}
