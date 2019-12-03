#ifndef DIRECCION_H_INCLUDED
#define DIRECCION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

typedef struct
{
    char calle[51];
    int altura;
    char localidad[51];
}eDireccion;

/** \brief Harcodea los datos de una direccion
 *
 * \param listadireccion[] eDireccion La lista de direcciones
 * \return void No retorna nada
 *
 */
void direccion_harcodearDatos(eDireccion listadireccion[]);

/** \brief Muestra los datos de una direccion
 *
 * \param unadireccion eDireccion Una direccion
 * \return void No retorna nada
 *
 */
void direccion_mostrarUnoSolo(eDireccion unadireccion);

/** \brief Muestra la lista de direcciones
 *
 * \param listadireccion[] eDireccion La lista de direcciones
 * \param tamdireccion int La longitud del array
 * \return void No retorna nada
 *
 */
void direccion_mostrarLista(eDireccion listadireccion[],int tamdireccion);

/** \brief Busca un id y retorna su indice
 *
 * \param listadireccion[] eDireccion La lista de direcciones
 * \param tamdireccion int La longitud del array
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int direccion_buscarPorAltura(eDireccion listadireccion[],int tamdireccion,int alturaABuscar);

/** \brief Busca una descripcion y retorna su indice
 *
 * \param listadireccion[] eDireccion La lista de direcciones
 * \param tamdireccion int La longitud del array
 * \param descripcionABuscar char* La descripcion a buscar
 * \return int Si encontro la descripcion retorna su indice, si no la encontro [-1]
 *
 */
int direccion_buscarAlturaPorLocalidad(eDireccion listadireccion[],int tamdireccion,char* localidadABuscar);
#endif // DIRECCION_H_INCLUDED
