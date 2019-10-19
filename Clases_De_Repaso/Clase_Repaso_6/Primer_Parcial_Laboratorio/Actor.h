#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo[51];
    int estado;
}eActor;
void menuGestionarActores(eActor listaActores[],int tamActor,int* contAltas);
void inicializarActores(eActor listaActores[],int tamActor);
void harcodearActores(eActor listaActores[],int tamActor);
int buscarSoloUnEstado(eActor listaActores[],int tamActor,int estadoDelLugar);
void darDeAlta(eActor listaActores[],int tamActor,int* contDeAltas);
int pedirDatosSecuenciales(eActor listaActores[],int tamActor,int indice);
void pedirDatosAEleccion(eActor listaActores[],int tamActor,int indice);
void modificarActor(eActor listaActores[],int tamActor);

void mostrarListadoDeActores(eActor listaActores[],int tamActor);
void mostrarSoloUnActor(eActor unActor);
int buscarActorPorCodigo(eActor listaActores[],int tamActor,int valorABuscar,int estadoDelLugar);
void darDeBaja(eActor listaActores[],int tamActor);
void ordenarListadoDeActores(eActor listadoActores[],int tamActor);

void mostrarSoloUnActorTest(eActor unActor);

#endif // ACTOR_H_INCLUDED
