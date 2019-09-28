#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED
typedef struct
{
    int codigoPostal;
    char nombreLocalidad;
    int id;
} eLocalidad;

int buscarUnaLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int idABuscar);

#endif // LOCALIDAD_H_INCLUDED
