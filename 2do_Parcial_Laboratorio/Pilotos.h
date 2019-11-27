#ifndef PILOTOS_H_INCLUDED
#define PILOTOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Validaciones.h"
typedef struct
{
    int id;
    char nombreYApellido[51];
}ePiloto;

/** \brief Recerba espacio en memoria e inicializa una piloto
 *
 * \return ePiloto* [NULL] si no encontro espacio o la posicion de memoria de la piloto si encontro espacio
 *
 */
ePiloto* piloto_nuevapiloto(void);

/** \brief Libera el espacio en memoria de una piloto
 *
 * \param empleado eEmpleado* El puntero a una piloto
 * \return int Si libero la piloto [1] si no [0]
 *
 */
int piloto_borrarpiloto(ePiloto* unapiloto);

/** \brief Harcodea los datos de una piloto
 *
 * \param listapiloto LinkedList* La lista de pilotoes
 * \return void No retorna nada
 *
 */
void piloto_harcodearDatos(LinkedList* listapiloto);

/** \brief Busca una piloto por su id
 *
 * \param listapiloto LinkedList* La lista de pilotos
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int piloto_buscarPorId(LinkedList* listapiloto,int idABuscar);

/** \brief Busca una piloto por su nombre y apellido
 *
 * \param listapiloto LinkedList* La lista de pilotos
 * \param nombreYApellidoABuscar char* El nombre y apellido a buscar
 * \return int Si encontro el nombre y apellido retorna su indice, si no lo encontro [-1]
 *
 */
int piloto_buscarPorNombreYApellido(LinkedList* listapiloto,char* nombreYApellidoABuscar);

/** \brief Muestra una piloto
 *
 * \param unapiloto ePiloto* Una piloto
 * \return int Si se mostro [1] si no se pudo mostrar [0]
 *
 */
int piloto_mostrarUnapiloto(ePiloto* unapiloto);

/** \brief Muestra la lista de pilotoes
 *
 * \param listapiloto LinkedList* La lista de pilotoes
 * \return void No retorna nada
 *
 */
void piloto_mostrarListapilotoes(LinkedList* listapiloto);
int piloto_getId(ePiloto* piloto,int* id);
int piloto_getNombreYApellido(ePiloto* piloto,char* nombreYApellido);
#endif // PILOTOS_H_INCLUDED
