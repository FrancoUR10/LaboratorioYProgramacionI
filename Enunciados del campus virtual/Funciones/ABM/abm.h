#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int estado;
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    char genero[10];
}eEntidad;

/** \brief Inicializa todos los datos de una entidad
 *
 * \param listaEntidad[] eEntidad El array con los datos a inicializar
 * \param tamEntidad int La longitud del array
 * \return void No retorna nada
 *
 */
void inicializarEntidad(eEntidad listaEntidad[],int tamEntidad);

/** \brief Harcodea los datos de una entidad
 *
 * \param listaEntidad[] eEntidad El array con los datos a harcodear
 * \param tamEntidad int La cantidad de datos a harcodear
 * \return void No retorna nada
 *
 */
void harcodearEntidad(eEntidad listaEntidad[],int tamEntidad);

/** \brief Muestra los datos de una sola entidad
 *
 * \param listaEntidad eEntidad El array con un dato a mostrar
 * \return void No retorna nada
 *
 */
void mostrarUnEntidad(eEntidad listaEntidad);

/** \brief Muestra todos los datos ocupados de una entidad
 *
 * \param listaEntidad[] eEntidad El array con los datos a mostrar
 * \param tamEntidad int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarListaEntidad(eEntidad listaEntidad[],int tamEntidad);

/** \brief Ordena los elementos de un array
 *
 * \param listaEntidad[] eEntidad El array con los elementos a ordenar
 * \param tamEntidad int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArray(eEntidad listaEntidad[],int tamEntidad);

/** \brief Busca en el array un lugar con el estado indicado
 *
 * \param listaEntidad[] eEntidad El array con un lugar a buscar
 * \param tamEntidad int La longitud del array
 * \param estadoBusqueda int El estado a buscar
 * \return int Si encontro el estado retorna el indice, si no [-1]
 *
 */
int buscarUnEstado(eEntidad listaEntidad[],int tamEntidad,int estadoBusqueda);

/** \brief Busca en el array un valor a buscar
 *
 * \param listaEntidad[] eEntidad El array con un valor a buscar
 * \param tamEntidad int La longitud del array
 * \param busquedaValor int El valor a buscar
 * \return int Si encontro el valor retorna el indice, si no [-1]
 *
 */
int buscarUnLugar(eEntidad listaEntidad[],int tamEntidad,int busquedaValor);

/** \brief Da de alta los datos de una entidad
 *
 * \param listaEntidad[] eEntidad El array con los datos a dar de alta
 * \param tamEntidad int La longitud del array
 * \param contAltas int* El contador para generar un id automaticamente
 * \return void No retorna nada
 *
 */
void darDeAlta(eEntidad listaEntidad[],int tamEntidad,int* contAltas);

/** \brief Pide todos los datos de una entidad de manera secuencial
 *
 * \param listaEntidad[] eEntidad El array en donde guardar los datos
 * \param tamEntidad int La longitud del array
 * \param indice int El indice en donde guardar los datos
 * \return int Si un dato no pudo ingresarse [-1] si confirmo el alta [1] si cancelo el alta [0]
 *
 */
int pedirDatosSecuenciales(eEntidad listaEntidad[],int tamEntidad,int indice);

/** \brief Da de baja logica un elemento en el array
 *
 * \param listaEntidad[] eEntidad El array con un dato a dar de baja
 * \param tamEntidad int La longitud del array
 * \return void No retorna nada
 *
 */
void darDeBaja(eEntidad listaEntidad[],int tamEntidad);

/** \brief Modifica un elemento en el array
 *
 * \param listaEntidad[] eEntidad El array con un elemento a modificar
 * \param tamEntidad int La longitud del array
 * \return void No retorna nada
 *
 */
void modificarDatos(eEntidad listaEntidad[],int tamEntidad);

/** \brief Pide en un menu de opciones los datos a ingresar
 *
 * \param listaEntidad[] eEntidad El array en donde guardar los datos
 * \param tamEntidad int La longitud del array
 * \param indice int El indice en donde guardar los datos
 * \return void No retorna nada
 *
 */
void pedirDatosAEleccion(eEntidad listaEntidad[],int tamEntidad,int indice);
#endif // ABM_H_INCLUDED
