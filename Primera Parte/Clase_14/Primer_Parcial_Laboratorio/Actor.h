#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Pais.h"
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo[51];
    int estado;
    int idNacionalidad;
}eActor;
void menuGestionarActores(eActor listaActores[],int tamActor,int* contAltas,ePais listaPaises[],int tamPais);
void inicializarActores(eActor listaActores[],int tamActor);
void harcodearActores(eActor listaActores[],int tamActor);
int buscarSoloUnEstado(eActor listaActores[],int tamActor,int estadoDelLugar);
void darDeAlta(eActor listaActores[],int tamActor,int* contDeAltas,ePais listaPais[],int tamPais);
int pedirDatosSecuenciales(eActor listaActores[],int tamActor,int indice,ePais listaPais[],int tamPais);
void pedirDatosAEleccion(eActor listaActores[],int tamActor,int indice,ePais listaPais[],int tamPais);
void modificarActor(eActor listaActores[],int tamActor,ePais listaPais[],int tamPais);

void mostrarListadoDeActores(eActor listaActores[],int tamActor,ePais listaPais[],int tamPais);
void mostrarSoloUnActor(eActor unActor,ePais listaPais[],int indicePais);
int buscarActorPorCodigo(eActor listaActores[],int tamActor,int valorABuscar,int estadoDelLugar);
void darDeBaja(eActor listaActores[],int tamActor,ePais listaPais[],int tamPais);
void ordenarListadoDeActores(eActor listadoActores[],int tamActor);

int buscarNacionalidadDelActor(eActor listaActor[],int tamActor,ePais listaPais[],int tamPais);
#endif // ACTOR_H_INCLUDED
