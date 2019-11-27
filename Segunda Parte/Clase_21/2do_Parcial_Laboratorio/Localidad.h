#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char descripcion[51];
}eLocalidad;

/** \brief Recerba espacio en memoria e inicializa una localidad
 *
 * \return eLocalidad* [NULL] si no encontro espacio o la posicion de memoria de la localidad si encontro espacio
 *
 */
eLocalidad* localidad_nuevaLocalidad(void);

/** \brief Libera el espacio en memoria de una localidad
 *
 * \param empleado eEmpleado* El puntero a una localidad
 * \return int Si libero la localidad [1] si no [0]
 *
 */
int localidad_borrarLocalidad(eLocalidad* unaLocalidad);

/** \brief Harcodea los datos de una localidad
 *
 * \param listaLocalidad LinkedList* La lista de localidades
 * \return void No retorna nada
 *
 */
void localidad_harcodearDatos(LinkedList* listaLocalidad);

/** \brief Busca una localidad por su id
 *
 * \param listaLocalidad LinkedList* La lista de localidades
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int localidad_buscarPorId(LinkedList* listaLocalidad,int idABuscar);

/** \brief Muestra una localidad
 *
 * \param unaLocalidad eLocalidad* Una localidad
 * \return int Si se mostro [1] si no se pudo mostrar [0]
 *
 */
int localidad_mostrarUnaLocalidad(eLocalidad* unaLocalidad);

/** \brief Muestra la lista de localidades
 *
 * \param listaLocalidad LinkedList* La lista de localidades
 * \return void No retorna nada
 *
 */
void localidad_mostrarListaLocalidades(LinkedList* listaLocalidad);
#endif // LOCALIDAD_H_INCLUDED
