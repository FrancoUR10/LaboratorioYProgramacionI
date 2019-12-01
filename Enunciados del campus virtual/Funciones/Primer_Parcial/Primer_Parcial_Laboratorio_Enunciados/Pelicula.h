#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Fecha.h"
#include "Genero.h"

typedef struct
{
    int codigo;
    char descripcion[256];
    int duracion;
    int idGenero;
    eFecha fechaEstreno;
}ePelicula;

/** \brief Harcodea los datos de una pelicula
 *
 * \param listapelicula[] ePelicula La lista de peliculaes
 * \return void No retorna nada
 *
 */
void pelicula_harcodearDatos(ePelicula listapelicula[]);

/** \brief Muestra los datos de una pelicula
 *
 * \param unapelicula ePelicula Una pelicula
 * \param unGenero[] eGenero Un genero
 * \param indiceGenero int El indice de un genero
 * \return void No retorna nada
 *
 */
void pelicula_mostrarUnoSolo(ePelicula unapelicula,eGenero unGenero[],int indiceGenero);

/** \brief Muestra la lista de peliculas
 *
 * \param listapelicula[] ePelicula La lista de peliculas
 * \param tampelicula int La longitud de la lista peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \return void No retorna nada
 *
 */
void pelicula_mostrarLista(ePelicula listapelicula[],int tampelicula,eGenero listaGenero[],int tamGenero);

/** \brief Busca un codigo y retorna su indice
 *
 * \param listapelicula[] ePelicula La lista de peliculas
 * \param tampelicula int La longitud del array
 * \param idABuscar int El codigo a buscar
 * \return int Si encontro el codigo retorna su indice, si no lo encontro [-1]
 *
 */
int pelicula_buscarPorCodigo(ePelicula listapelicula[],int tampelicula,int codigoABuscar);

/** \brief Muestra la lista de peliculas estrenadas despues del anio 2002
 *
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \return void No retorna nada
 *
 */
void pelicula_mostrarPeliculasDespuesDel2002(ePelicula listaPelicula[],int tamPelicula,eGenero listaGenero[],int tamGenero);
#endif // PELICULA_H_INCLUDED
