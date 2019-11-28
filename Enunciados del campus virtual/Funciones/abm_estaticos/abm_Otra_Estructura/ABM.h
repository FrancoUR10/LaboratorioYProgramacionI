#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Localidad.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char genero[51];
    int edad;
    float sueldo;
    int idLocalidad;
    int estado;
}eEmpleado;

/** \brief Inicializa los datos de un array
 *
 * \param listaEmpleado eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud del array
 * \return void No retorna nada
 *
 */
void empleado_inicializarDatos(eEmpleado listaEmpleado[],int tamEmpleado);

/** \brief Harcodea los datos de un array
 *
 * \param listaEmpleado eEmpleado La lista de empleados
 * \return void No retorna nada
 *
 */
void empleado_harcodearDatos(eEmpleado listaEmpleado[]);

/** \brief Muestra los datos de un empleado
 *
 * \param unEmpleado eEmpleado Un empleado
 * \param unaLocalidad[] eLocalidad Una localidad
 * \param indiceLocalidad int El indice de una localidad
 * \return void No retorna nada
 *
 */
void empleado_mostrarUnoSolo(eEmpleado unEmpleado,eLocalidad unaLocalidad[],int indiceLocalidad);

/** \brief Muestra todos los datos de la lista
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud de la lista empleados
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \param tamLocalidad int La longitud de la lista localidades
 * \return void No retorna nada
 *
 */
void empleado_mostrarLista(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad);

/** \brief Busca un estado en la lista y retorna su indice
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud de la lista empleados
 * \param estadoABuscar int El estado a buscar
 * \return int Si encontro el estado retorna su indice, si no lo encontro [-1]
 *
 */
int empleado_buscarPorEstado(eEmpleado listaEmpleado[],int tamEmpleado,int estadoABuscar);

/** \brief Busca un id en la lista y retorna su indice
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud de la lista empleados
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int empleado_buscarPorId(eEmpleado listaEmpleado[],int tamEmpleado,int idABuscar);

/** \brief Da de alta a un empleado
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud de la lista empleados
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \param tamLocalidad int La longitud de la lista localidades
 * \param contAltas int* El contador de altas
 * \return int Si dio de alta [1] si cancelo el usuario [0] si no se logro el alta [-1]
 *
 */
int empleado_darDeAlta(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad,int* contAltas);

/** \brief Da de baja a un empleado
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud de la lista empleados
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \param tamLocalidad int La longitud de la lista localidades
 * \return int Si dio de baja [1] si cancelo el usuario [0] si no se logro la baja [-1]
 *
 */
int empleado_darDeBaja(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad);

/** \brief Modifica los datos de un empleado
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud de la lista empleados
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \param tamLocalidad int La longitud de la lista localidades
 * \return int Si se encontro el indice a modificar [1] si no se encontro [0]
 *
 */
int empleado_modificarDatos(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad);

/** \brief Pide los datos de un empleado a modificar
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param listaLocalidad[] eLocalidad La lista de localidades
 * \param tamLocalidad int La longitud de la lista localidades
 * \param indice int El indice encontrado a modificar
 * \return void No retorna nada
 *
 */
void empleado_pedirDatosAModificar(eEmpleado listaEmpleado[],eLocalidad listaLocalidad[],int tamLocalidad,int indice);

/** \brief Ordena la lista de empleados
 *
 * \param listaEmpleado[] eEmpleado La lista de empleados
 * \param tamEmpleado int La longitud de la lista empleados
 * \return void No retorna nada
 *
 */
void empleado_ordenarDatos(eEmpleado listaEmpleado[],int tamEmpleado);
#endif // ABM_H_INCLUDED
