#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Pilotos.h"
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[51];
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelo;

eVuelo* vuelo_nuevovuelo();

/** \brief Libera el espacio en memoria de un vuelo
 *
 * \param vuelo eVuelo* El puntero a un vuelo
 * \return int Si libero al vuelo [1] si no [0]
 *
 */
int vuelo_borrarvuelo(eVuelo* vuelo);

int vuelo_setIdVuelo(eVuelo* vuelo,int idVuelo);
int vuelo_setIdAvion(eVuelo* vuelo,int idAvion);
int vuelo_setIdPiloto(eVuelo* vuelo,int idPiloto);
int vuelo_setFecha(eVuelo* vuelo,char* fecha);
int vuelo_setDestino(eVuelo* vuelo,char* destino);
int vuelo_setCantPasajeros(eVuelo* vuelo,int cantPasajeros);
int vuelo_setHoraDespegue(eVuelo* vuelo,int horaDespegue);
int vuelo_setHoraLlegada(eVuelo* vuelo,int horaLlegada);

int vuelo_getIdVuelo(eVuelo* vuelo,int* idVuelo);
int vuelo_getIdAvion(eVuelo* vuelo,int* idAvion);
int vuelo_getIdPiloto(eVuelo* vuelo,int* idPiloto);
int vuelo_getFecha(eVuelo* vuelo,char* fecha);
int vuelo_getDestino(eVuelo* vuelo,char* destino);
int vuelo_getCantPasajeros(eVuelo* vuelo,int* cantPasajeros);
int vuelo_getHoraDespegue(eVuelo* vuelo,int* horaDespegue);
int vuelo_getHoraLlegada(eVuelo* vuelo,int* horaLlegada);

/** \brief Recerba espacio en memoria para un vuelo y setea todos sus campos pasados por parametros
 *
 * \param id char* El id tipo string a setear
 * \param nombre char* El nombre a setear
 * \param apellido char* El apellido a setear
 * \param edad char* La edad tipo string a setear
 * \param sueldo char* El sueldo tipo string a setear
 * \param idLocalidad char* El id localidad tipo string a setear
 * \return eVuelo* [NULL] si no encontro espacio o la direccion de memoria si encontro espacio
 *
 */
eVuelo* vuelo_nuevovueloParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada);

/** \brief Muestra los datos de un solo vuelo
 *
 * \param unvuelo eVuelo* El puntero a un vuelo
 * \param unaLocalidad eLocalidad* El puntero a una localidad
 * \return int Si el puntero es nulo [0] si se mostraron los datos [1]
 *
 */
int vuelo_mostrarUnvuelo(eVuelo* unvuelo,ePiloto* unPiloto);

/** \brief Muestra la lista con todos los vuelos
 *
 * \param listavuelos LinkedList* La lista de vuelos
 * \param listaLocalidad LinkedList* la lista de localidades
 * \return void No retorna nada
 *
 */
void vuelo_mostrarListavuelos(LinkedList* listavuelos,LinkedList* listaLocalidad);

/** \brief Busca el indice de un vuelo por su id
 *
 * \param listavuelos LinkedList* La lista de vuelos
 * \param idABuscar int El id a buscar en la lista
 * \return int Si lo encontro retorna el indice, si no lo encontro [-1]
 *
 */
int vuelo_buscarPorId(LinkedList* listavuelos,int idABuscar);

/** \brief Carga los datos de los empleados que fueron guardados en modo texto
 *
 * \param archivo FILE* El archivo en donde se guardaron los datos
 * \param listaEmpleados LinkedList* La lista de empleados
 * \param contAltas int* El contador de altas a obtener desde la segunda posicion del archivo
 * \return int Si se pudo cargar los datos [1] si no [-1]
 *
 */
int vuelo_cargarDatosModoTexto(FILE* archivo,LinkedList* listaVuelos);
int vuelo_filtrarPorVuelosCortos(void* unvuelo);
int vuelo_guardarDatosPorFiltro(FILE* archivo,LinkedList* listavuelos);
int vuelo_filtrarPorDestinoPortugal(void* unvuelo);
void vuelo_mostrarListaDeVuelosAPortugal(LinkedList* listavuelos,LinkedList* listaPiloto);
int vuelo_filtrarPorVuelosSinAlexLifeson(void* unVuelo);
void vuelo_mostrarListaDeVuelosSinAlexLifeson(LinkedList* listavuelos,LinkedList* listaPiloto);
#endif // VUELOS_H_INCLUDED
