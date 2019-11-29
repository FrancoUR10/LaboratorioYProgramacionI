#ifndef ELENCO_H_INCLUDED
#define ELENCO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Actor.h"
#include "Pelicula.h"

typedef struct
{
    int codigoDeReparto;
    int codigoPelicula;
    int codigoActor;
    float valorContrato;
}eElenco;

/** \brief Inicializa los datos de un array
 *
 * \param listaElenco eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \return void No retorna nada
 *
 */
void elenco_inicializarDatos(eElenco listaElenco[],int tamElenco);

/** \brief Harcodea los datos de una elenco
 *
 * \param listaelenco[] eElenco La lista de elencoes
 * \return void No retorna nada
 *
 */
void elenco_harcodearDatos(eElenco listaelenco[]);

/** \brief Muestra los datos de un elenco
 *
 * \param unaelenco eElenco Un elenco
 * \param unActor[] eActor Un actor
 * \param indiceActor int El indice de un actor
 * \param unaPelicula[] ePelicula Una pelicula
 * \param indicePelicula int El indice de una pelicula
 * \return void No retorna nada
 *
 */
void elenco_mostrarUnoSolo(eElenco unaelenco,eActor unActor[],int indiceActor,ePelicula unaPelicula[],int indicePelicula);

/** \brief Muestra la lista de elencoes
 *
 * \param listaelenco[] eElenco La lista de elencoes
 * \param tamelenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \return void No retorna nada
 *
 */
void elenco_mostrarLista(eElenco listaelenco[],int tamelenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula);

/** \brief Busca un codigo de reparto y retorna su indice
 *
 * \param listaelenco[] eElenco La lista de elencos
 * \param tamelenco int La longitud de la lista elencos
 * \param idABuscar int El codigo de reparto a buscar
 * \return int Si encontro el codigo de reparto retorna su indice, si no lo encontro [-1]
 *
 */
int elenco_buscarPorCodigoDeReparto(eElenco listaelenco[],int tamelenco,int codigoRepartoABuscar);
#endif // ELENCO_H_INCLUDED
