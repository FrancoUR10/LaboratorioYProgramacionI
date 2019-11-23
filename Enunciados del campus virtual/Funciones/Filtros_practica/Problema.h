#ifndef PROBLEMA_H_INCLUDED
#define PROBLEMA_H_INCLUDED
#include "LinkedList.h"
#include "Validaciones.h"
typedef struct
{
    int id;
    char descripcion[51];
}eProblema;

eProblema* problema_nuevoProblema(void);
void problema_harcodearProblemas(LinkedList* listaProblemas);
int problema_buscarPorId(LinkedList* listaProblemas,int idABuscar);

#endif // PROBLEMA_H_INCLUDED
