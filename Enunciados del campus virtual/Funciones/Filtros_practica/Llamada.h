#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"
#include "Problema.h"
typedef struct
{
    int id_llamada;
    char fecha[51];
    int numero_cliente;
    int id_problema;
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

/** \brief Setea el id a un llamada
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param id int El id a setear
 * \return int Si seteo el id [1] si no [0]
 *
 */
int llamada_setIdLlamada(eLlamada* llamada,int idLlamada);

/** \brief Setea el nombre a un llamada
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param nombre char* El nombre a setear
 * \return int Si seteo el nombre [1] si no [0]
 *
 */
int llamada_setFecha(eLlamada* llamada,char* fecha);

/** \brief Setea el apellido a un llamada
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param apellido char* El apellido a setear
 * \return int Si seteo el apellido [1] si no [0]
 *
 */
int llamada_setNumeroCliente(eLlamada* llamada,int numeroCliente);

/** \brief Setea la edad a un llamada
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param edad int La edad a setear
 * \return int Si seteo la edad [1] si no [0]
 *
 */
int llamada_setIdProblema(eLlamada* llamada,int idProblema);

/** \brief Setea el sueldo a un llamada
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param sueldo float El elSueldo a setear
 * \return int Si seteo el sueldo [1] si no [0]
 *
 */
int llamada_setSolucionado(eLlamada* llamada,char* solucionado);

/** \brief Obtiene el id de un llamada por parametros
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param id int* El id a obtener
 * \return int Si se obtuvo el id [1] si no [0]
 *
 */
int llamada_getIdLlamada(eLlamada* llamada,int* idLlamada);

/** \brief Obtiene el nombre de un llamada por parametros
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param nombre char* El nombre a obtener
 * \return int Si se obtuvo el nombre [1] si no [0]
 *
 */
int llamada_getFecha(eLlamada* llamada,char* fecha);

/** \brief Obtiene el apellido de un llamada por parametros
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param apellido char* El apellido a obtener
 * \return int Si se obtuvo el apellido [1] si no [0]
 *
 */
int llamada_getNumeroCliente(eLlamada* llamada,int* numeroCliente);

/** \brief Obtiene la edad de un llamada por parametros
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param edad int* La edad a obtener
 * \return int Si se obtuvo la edad [1] si no [0]
 *
 */
int llamada_getIdProblema(eLlamada* llamada,int* idProblema);

/** \brief Obtiene el sueldo de un llamada por parametros
 *
 * \param llamada eLlamada* El puntero a un llamada
 * \param sueldo float* El sueldo a obtener
 * \return int Si se obtuvo el sueldo [1] si no [0]
 *
 */
int llamada_getSolucionado(eLlamada* llamada,char* solucionado);

/** \brief Recerba espacio en memoria para un llamada y setea todos sus campos pasados por parametros
 *
 * \param id char* El id tipo string a setear
 * \param nombre char* El nombre a setear
 * \param apellido char* El apellido a setear
 * \param edad char* La edad tipo string a setear
 * \param sueldo char* El sueldo tipo string a setear
 * \return eLlamada* [NULL] si no encontro espacio o la direccion de memoria si encontro espacio
 *
 */
eLlamada* llamada_nuevollamadaParametros(char* idLlamada,char* fecha,char* numeroCliente,char* idProblema,char* solucionado);

/** \brief Muestra los datos de un solo llamada
 *
 * \param unllamada eLlamada* El puntero a un llamada
 * \return int Si el puntero es nulo [0] si se mostraron los datos [1]
 *
 */
int llamada_mostrarUnllamada(eLlamada* unllamada,eProblema* unProblema);

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
int llamada_buscarPorId(LinkedList* listallamadas,int idABuscar);

/** \brief Carga los datos de los llamadas que fueron guardados en modo texto
 *
 * \param archivo FILE* El archivo en donde se guardaron los datos
 * \param listallamadas LinkedList* La lista de llamadas
 * \param contAltas int* El contador de altas a obtener desde la segunda posicion del archivo
 * \return int Si se pudo cargar los datos [1] si no [-1]
 *
 */
int llamada_cargarDatosModoTexto(FILE* archivo,LinkedList* listallamadas);
int llamada_filtrarPorProblema(void* unaLlamada,int idProblema);
int llamada_filtrarPorProblemaUno(void* unaLlamada);
int llamada_filtrarPorProblemaDos(void* unaLlamada);
int llamada_filtrarPorProblemaTres(void* unaLlamada);
int llamada_filtrarPorProblemaCuatro(void* unaLlamada);
int llamada_filtrarPorProblemaCinco(void* unaLlamada);
int llamada_guardarDatosPorFiltro(FILE* archivo,LinkedList* listallamadas);
#endif // LLAMADA_H_INCLUDED
