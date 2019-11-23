#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "Problemas.h"
#include "Validaciones.h"
#include "LinkedList.h"
typedef struct
{
    int id_Llamada;
    char fecha[51];
    int numero_Cliente;
    int id_Problema;
    char solucionado[51];
}eLlamada;

/** \brief Recerba espacio en memoria e inicializa un llamada
 *
 * \return eLlamada* [NULL] si no encontro espacio o la posicion de memoria del llamada si encontro espacio
 *
 */
eLlamada* llamada_nuevollamada();

/** \brief Libera el espacio en memoria de un llamada
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \return int Si libero al llamada [1] si no [0]
 *
 */
int llamada_borrarllamada(eLlamada* llamada);

/** \brief Muestra los datos de un solo llamada
 *
 * \param unllamada eLlamada* El puntero a un llamada
 * \return int Si el puntero es nulo [0] si se mostraron los datos [1]
 *
 */
int llamada_mostrarUnllamada(eLlamada* unllamada,eProblemas* elProblema);

/** \brief Muestra la lista con todos los llamadas
 *
 * \param listallamadas LinkedList* La lista de llamadas
 * \return void No retorna nada
 *
 */
void llamada_mostrarListallamadas(LinkedList* listallamadas,LinkedList* listaProblemas);

/** \brief Busca el indice de un llamada por su id
 *
 * \param listallamadas LinkedList* La lista de llamadas
 * \param idABuscar int El id a buscar en la lista
 * \return int Si lo encontro retorna el indice, si no lo encontro [-1]
 *
 */
int llamada_buscarPorIdLlamada(LinkedList* listallamadas,int id_llamadaABuscar);

/** \brief Guarda los datos de los llamadas en modo binario
 *
 * \param archivo FILE* El archivo en donde guardar los datos
 * \param listallamadas LinkedList* La lista de llamadas
 * \param contAltas int* El contador de altas a guardar en la primer posicion del archivo
 * \return int Si se pudo guardar los datos [1] si no [-1]
 *
 */
int llamada_guardarDatos(FILE* archivo,LinkedList* listallamadas,int* contAltas);

/** \brief Carga los datos de los llamadas que fueron guardados en modo binario
 *
 * \param archivo FILE* El archivo en donde se guardaron los datos
 * \param listallamadas LinkedList* La lista de llamadas
 * \param contAltas int* El contador de altas a obtener desde la primer posicion del archivo
 * \return int Si se pudo cargar los datos [1] si no [-1]
 *
 */
int llamada_cargarDatos(FILE* archivo,LinkedList* listallamadas);
int llamada_cargarDatosModoTexto(FILE* archivo,LinkedList* listaLlamadas);
int llamada_guardarDatosPorFiltro(FILE* archivo,LinkedList* listallamadas);
eLlamada* llamada_nuevaLlamadaParametros(char* idLlamada,char* fecha,char* numeroCliente,char* idProblema,char* solucionado);
int llamada_setIdLlamada(eLlamada* llamada,int idLlamada);
int llamada_setFecha(eLlamada* llamada,char* fecha);
int llamada_setNumeroCliente(eLlamada* llamada,int numeroCliente);
int llamada_setIdProblema(eLlamada* llamada,int idProblema);
int llamada_setSolucionado(eLlamada* llamada,char* solucionado);
int llamada_getIdLlamada(eLlamada* llamada,int* idLlamada);
int llamada_getFecha(eLlamada* llamada,char* fecha);
int llamada_getNumeroCliente(eLlamada* llamada,int* numeroCliente);
int llamada_getIdProblema(eLlamada* llamada,int* idProblema);
int llamada_getSolucionado(eLlamada* llamada,char* solucionado);
int llamada_filtrarPorProblema(void* unaLlamada, int id_problema);
int llamada_filtrarPorProblemaUno(void* unaLlamada);
int llamada_filtrarPorProblemaDos(void* unaLlamada);
int llamada_filtrarPorProblemaTres(void* unaLlamada);
int llamada_filtrarPorProblemaCuatro(void* unaLlamada);
int llamada_filtrarPorProblemaCinco(void* unaLlamada);
#endif // LLAMADA_H_INCLUDED
