#include "fecha.h"

#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[50];
    eFecha fundacion;

} eLocalidad;

#endif // LOCALIDAD_H_INCLUDED
eLocalidad construirLocalidad();
int cargarLocalidades(int cantidadRegistros, eLocalidad listado[]);
void mostrarLocalidad(eLocalidad localidad);
void mostrarListadoLocalidades(int cantidadRegistros, eLocalidad listado[]);
