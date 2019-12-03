#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Fecha.h"
#include "Direccion.h"
#include "Pais.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo[51];
    int estado;
    int idNacionalidad;
    eDireccion direccion;
    int cantPremios;
    eFecha fechaNacimiento;
}eActor;

/** \brief Muestra en un menu la gestion de actores
 *
 * \param listaActor[] eActor La lista de actores
 * \param tamActor int La longitud de la lista actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \param contAltas int* El contador de altas
 * \return void No retorna nada
 *
 */
void actor_gestionarActores(eActor listaActor[],int tamActor,ePais listaPais[],int tamPais,int* contAltas,eDireccion listaDireccion[],int tamDireccion);

/** \brief Inicializa los datos de un array
 *
 * \param listaactor eActor La lista de actors
 * \param tamactor int La longitud del array
 * \return void No retorna nada
 *
 */
void actor_inicializarDatos(eActor listaactor[],int tamactor);

/** \brief Harcodea los datos de un array
 *
 * \param listaactor eActor La lista de actors
 * \return void No retorna nada
 *
 */
void actor_harcodearDatos(eActor listaactor[]);

/** \brief Muestra los datos de un actor
 *
 * \param unactor eActor Un actor
 * \param unPais[] ePais Un pais
 * \param indicePais int El indice de un pais
 * \return void No retorna nada
 *
 */
void actor_mostrarUnoSolo(eActor unactor,ePais unPais[],int indicePais);

/** \brief Muestra los datos de un actor con sus nuevos campos
 *
 * \param unactor eActor Un actor
 * \param unPais[] ePais Un pais
 * \param indicePais int El indice de un pais
 * \return void No retorna nada
 *
 */
void actor_mostrarUnoSoloConNuevosCampos(eActor unactor,ePais unPais[],int indicePais);

/** \brief Muestra la lista de actores
 *
 * \param listaactor[] eActor La lista de actores
 * \param tamactor int La longitud de la lista actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \return void No retorna nada
 *
 */
void actor_mostrarLista(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais);

/** \brief Busca un estado y retorna su indice
 *
 * \param listaactor[] eActor La lista de actors
 * \param tamactor int La longitud de la lista
 * \param estadoABuscar int Es estado a buscar
 * \return int Si encontro el estado retorna su indice, si no lo encontro [-1]
 *
 */
int actor_buscarPorEstado(eActor listaactor[],int tamactor,int estadoABuscar);

/** \brief Busca un codigo y retorna su indice
 *
 * \param listaactor[] eActor La lista de actors
 * \param tamactor int La longitud de la lista
 * \param idABuscar int El codigo a buscar
 * \return int Si encontro el codigo retorna su indice, si no lo encontro [-1]
 *
 */
int actor_buscarPorCodigo(eActor listaactor[],int tamactor,int codigoABuscar);

/** \brief Da de alta a un actor
 *
 * \param listaactor[] eActor La lista de actores
 * \param tamactor int La longitud de la lista actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \param contAltas int* El contador de altas
 * \return int Si se dio de alta [1] si cancelo el usuario [0] si no se logro el alta [-1]
 *
 */
int actor_darDeAlta(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais,int* contAltas,eDireccion listaDireccion[],int tamDireccion);

/** \brief Da de baja a un actor
 *
 * \param listaactor[] eActor La lista de actores
 * \param tamactor int La longitud de la lista actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \return int Si se dio de baja [1] si cancelo el usuario [0] si no se logro la baja [-1]
 *
 */
int actor_darDeBaja(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais,eDireccion listaDireccion[],int tamDireccion);

/** \brief Modifica los datos de un actor
 *
 * \param listaactor[] eActor La lista de actores
 * \param tamactor int La longitud de la lista actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \return int Si se accedio al indice a modificar [1] si no se pudo acceder [0]
 *
 */
int actor_modificarDatos(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais,eDireccion listaDireccion[],int tamDireccion);

/** \brief Pide los datos de un actor a modificar
 *
 * \param listaactor[] eActor La lista de actores
 * \param listaPais[] ePais La lista de paises
 * \param tamPais int La longitud de la lista paises
 * \param indice int El indice encontrado a modificar
 * \return void No retorna nada
 *
 */
void actor_pedirDatosAModificar(eActor listaactor[],ePais listaPais[],int tamPais,int indice);

/** \brief Ordena la lista de actors
 *
 * \param listaactor[] eActor La lista de actors
 * \param tamactor int La longitud de la lista
 * \return void No retorna nada
 *
 */
void actor_ordenarDatos(eActor listaactor[],int tamactor);
void actor_mostrarActorMayorA30YGanoMinimoUnPremio(eActor listaActor[],int tamPelicula,ePais listaPais[],int tamPais);
void actor_mostrarUnoSoloConSuEdad(eActor unactor,int edadActor);
void actor_listarActoresConSusEdades(eActor listaActor[],int tamActor);
#endif // ACTOR_H_INCLUDED
