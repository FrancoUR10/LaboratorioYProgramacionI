#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

typedef struct
{
    int id;
    char descripcion[51];
}eLocalidad;

/** \brief Harcodea los datos de una localidad
 *
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \return void No retorna nada
 *
 */
void localidad_harcodearDatos(eLocalidad listaLocalidad[]);

/** \brief Muestra los datos de una localidad
 *
 * \param unaLocalidad eLocalidad Una localidad
 * \return void No retorna nada
 *
 */
void localidad_mostrarUnoSolo(eLocalidad unaLocalidad);

/** \brief Muestra la lista de localidades
 *
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \param tamLocalidad int La longitud del array
 * \return void No retorna nada
 *
 */
void localidad_mostrarLista(eLocalidad listaLocalidad[],int tamLocalidad);

/** \brief Busca un id y retorna su indice
 *
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \param tamLocalidad int La longitud del array
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int localidad_buscarPorId(eLocalidad listaLocalidad[],int tamLocalidad,int idABuscar);
#endif // LOCALIDAD_H_INCLUDED
