#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

typedef struct
{
    int id;
    char descripcion[51];
}ePais;

/** \brief Harcodea los datos de una pais
 *
 * \param listapais[] ePais La lista de paises
 * \return void No retorna nada
 *
 */
void pais_harcodearDatos(ePais listapais[]);

/** \brief Muestra los datos de una pais
 *
 * \param unapais ePais Una pais
 * \return void No retorna nada
 *
 */
void pais_mostrarUnoSolo(ePais unapais);

/** \brief Muestra la lista de paises
 *
 * \param listapais[] ePais La lista de paises
 * \param tampais int La longitud del array
 * \return void No retorna nada
 *
 */
void pais_mostrarLista(ePais listapais[],int tampais);

/** \brief Busca un id y retorna su indice
 *
 * \param listapais[] ePais La lista de paises
 * \param tampais int La longitud del array
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int pais_buscarPorId(ePais listapais[],int tampais,int idABuscar);
#endif // PAIS_H_INCLUDED
