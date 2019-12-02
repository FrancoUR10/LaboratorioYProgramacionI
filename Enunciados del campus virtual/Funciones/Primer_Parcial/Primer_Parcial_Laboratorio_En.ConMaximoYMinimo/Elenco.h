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

/** \brief Muestra en un menu los informes
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \param listaAuxPelicula eAuxPelicula La lista auxiliar de peliculas
 * \return void No retorna nada
 *
 */
void elenco_informarDatos(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eGenero listaGenero[],int tamGenero,ePais listaPais[],int tamPais,eAuxPelicula listaAuxPelicula[]);

/** \brief Muestra en un menu la gestion de elencos
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int longitud de la lista peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int longitud de la lista generos
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int longitud de la lista paises
 * \param contAltas int* El contador de altas
 * \return void No retorna nada
 *
 */
void elenco_gestionarElencos(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eGenero listaGenero[],int tamGenero,ePais listaPais[],int tamPais,int* contAltas);

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

/** \brief Da de alta a un elenco
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \param contAltas int* El contador de altas
 * \return int Si se dio de alta [1] si cancelo el usuario [0] si no se logro el alta [-1]
 *
 */
int elenco_darDeAlta(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eGenero listaGenero[],int tamGenero,ePais listaPais[],int tamPais,int* contAltas);

/** \brief Busca el codigo del par pelicula/actor en la lista de elencos
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param codigoActorABuscar int El codigo del actor a buscar
 * \param codigoPeliculaABuscar int El codigo de la pelicula a buscar
 * \return int Si encontro el par pelicula/actor en el elenco retorna su indice, si no lo encontro -1
 *
 */
int elenco_buscarUnElenco(eElenco listaElenco[],int tamElenco,int codigoActorABuscar,int codigoPeliculaABuscar);

/** \brief Ordena los datos de la lista elencos
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \return void No retorna nada
 *
 */
void elenco_ordenarDatos(eElenco listaElenco[],int tamElenco,ePelicula listaPelicula[],int tamPelicula,eActor listaActor[],int tamActor);

/** \brief Muestra la lista de peliculas que tengan un actor argentino
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \return void No retorna nada
 *
 */
void elenco_mostrarPeliculasConActorArgentino(eElenco listaElenco[],int tamElenco,ePelicula listaPelicula[],int tamPelicula,eActor listaActor[],int tamActor,eGenero listaGenero[],int tamGenero,ePais listaPais[],int tamPais);

/** \brief Muestra la lista de peliculas que contengan un actor seleccionado
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \return void No retorna nada
 *
 */
void elenco_mostrarPeliculasConUnActorSeleccionado(eElenco listaElenco[],int tamElenco,ePelicula listaPelicula[],int tamPelicula,eActor listaActor[],int tamActor,eGenero listaGenero[],int tamGenero,ePais listaPais[],int tamPais);

/** \brief Muestra el total del valor recaudado del actor seleccionado que actuo en peliculas romanticas
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \return void No retorna nada
 *
 */
void elenco_mostrarRecaudacionEnPeliculasRomanticas(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePais listaPais[],int tamPais,ePelicula listaPelicula[],int tamPelicula,eGenero listaGenero[],int tamGenero);

/** \brief Muestra la lista de actores que no participan en ninguna pelicula
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \return void No retorna nada
 *
 */
void elenco_mostrarActoresQueNoParticipanEnPeliculas(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePais listaPais[],int tamPais);

/** \brief Busca el codigo de un actor que se encuentre en el elenco
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param codigoActorABuscar int El codigo del actor a buscar
 * \return int Si encontro el codigo del actor retorna su indice, si no lo encontro [-1]
 *
 */
int elenco_buscarActorPorCodigo(eElenco listaElenco[],int tamElenco,int codigoActorABuscar);

/** \brief Cuenta la cantidad de actores que hay en cada pelicula
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaAuxPelicula[] eAuxPelicula La lista auxiliar de peliculas
 * \return void No retorna nada
 *
 */
void elenco_contarCantidadDeActoresEnPeliculas(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eAuxPelicula listaAuxPelicula[]);

/** \brief Compara cada contador y obtiene el maximo
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaAuxPelicula[] eAuxPelicula La lista auxiliar de peliculas
 * \return int El maximo
 *
 */
int elenco_dameElMaximo(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eAuxPelicula listaAuxPelicula[]);

/** \brief Muestra las peliculas con mayor cantidad de actores
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaAuxPelicula[] eAuxPelicula La lista auxiliar de peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \return void No retorna nada
 *
 */
void elenco_mostrarPeliculaConMasActores(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eAuxPelicula listaAuxPelicula[],eGenero listaGenero[],int tamGenero);

/** \brief Compara cada contador y obtiene el minimo
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaAuxPelicula[] eAuxPelicula La lista auxiliar de peliculas
 * \return int El minimo
 *
 */
int elenco_dameElMinimo(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eAuxPelicula listaAuxPelicula[]);

/** \brief Muestra las peliculas con menor cantidad de actores
 *
 * \param listaElenco[] eElenco La lista de elencos
 * \param tamElenco int La longitud de la lista elencos
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPelicula[] ePelicula La lista de peliculas
 * \param tamPelicula int La longitud de la lista peliculas
 * \param listaAuxPelicula[] eAuxPelicula La lista auxiliar de peliculas
 * \param listaGenero[] eGenero La lista de generos
 * \param tamGenero int La longitud de la lista generos
 * \return void No retorna nada
 *
 */
void elenco_mostrarPeliculaConMenosActores(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eAuxPelicula listaAuxPelicula[],eGenero listaGenero[],int tamGenero);
#endif // ELENCO_H_INCLUDED
