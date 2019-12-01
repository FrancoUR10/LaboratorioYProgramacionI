#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

typedef struct
{
    int id;
    char descripcion[51];
}eGenero;

/** \brief Harcodea los datos de una genero
 *
 * \param listagenero[] eGenero La lista de generoes
 * \return void No retorna nada
 *
 */
void genero_harcodearDatos(eGenero listagenero[]);

/** \brief Muestra los datos de una genero
 *
 * \param unagenero eGenero Una genero
 * \return void No retorna nada
 *
 */
void genero_mostrarUnoSolo(eGenero unagenero);

/** \brief Muestra la lista de generoes
 *
 * \param listagenero[] eGenero La lista de generoes
 * \param tamgenero int La longitud del array
 * \return void No retorna nada
 *
 */
void genero_mostrarLista(eGenero listagenero[],int tamgenero);

/** \brief Busca un id y retorna su indice
 *
 * \param listagenero[] eGenero La lista de generoes
 * \param tamgenero int La longitud del array
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int genero_buscarPorId(eGenero listagenero[],int tamgenero,int idABuscar);
#endif // GENERO_H_INCLUDED
