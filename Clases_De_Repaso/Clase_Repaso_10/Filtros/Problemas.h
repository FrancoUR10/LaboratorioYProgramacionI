#ifndef PROBLEMAS_H_INCLUDED
#define PROBLEMAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char descripcion[51];
}eProblemas;

eProblemas* problema_nuevoProblema(void);
void problema_harcodearProblemas(LinkedList* listaProblemas);
int problema_buscarPorId(LinkedList* listaProblemas,int idABuscar);
#endif // PROBLEMAS_H_INCLUDED
