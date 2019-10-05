#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED
#include "Localidad.h"
typedef struct
{
    int estado;
    int id;
    char nombre[51];
    char apellido[51];
    int edad;
    float salario;
    int idLocalidad;
} eEmpleado;

/** \brief Inicializa cada elemento del array en estado libre
 *
 * \param unArray[] eEmpleado El array a ser inicializado
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void inicializarArray(eEmpleado unArray[],int tam);

/** \brief Harcodea 3 posiciones del array
 *
 * \param unArray[] eEmpleado El array a harcodear
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void harcodearArray(eEmpleado unArray[],int tam);

/** \brief Muestra cada elemento del array que este en estado ocupado
 *
 * \param unArray[] eEmpleado El array con los elementos a mostrar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarArray(eEmpleado unArray[],int tam);

/** \brief Ordena los elementos de un array de menor a mayor
 *
 * \param unArray[] eEmpleado El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayAscendiente(eEmpleado unArray[],int tam);

/** \brief Ordena los elementos de un array de mayor a menor
 *
 * \param unArray[] eEmpleado El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayDescendiente(eEmpleado unArray[],int tam);

/** \brief Ordena los elementos de un array de forma ascendiente o descendiente
 *
 * \param unArray[] eEmpleado El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \param tipoDeOrden int Ordenar de menor a mayor [1] ordenar de mayor a menor [0]
 * \return void No retorna nada
 *
 */
void ordenarArray(eEmpleado unArray[],int tam, int tipoDeOrden);

/** \brief Busca un valor del array que se encuentre en el estado indicado y devuelve su indice
 *
 * \param unArray[] eEmpleado El array con el valor a buscar
 * \param tam int La longitud del array
 * \param valorABuscar int El valor a buscar en el array
 * \param estadoDelLugar int El estado en el que se encuentra el valor a buscar
 * \return int Si encontro el valor a buscar retorna el indice, si no lo encontro [-1]
 *
 */
int buscarLugarLibre(eEmpleado unArray[],int tam,int valorABuscar,int estadoDelLugar);

/** \brief Busca solo un estado libre u ocupado del array y devuelve su indice
 *
 * \param unArray[] eEmpleado El array con el el estado a buscar
 * \param tam int La longitud del array
 * \param valorABuscar int El estado libre u ocupado a buscar en el array (LIBRE:[1] OCUPADO:[0]
 * \return int Si encontro un solo estado de la condicion que se busca retorna el indice, si no lo encontro [-1]
 *
 */
int buscarSoloUnEstado(eEmpleado unArray[],int tam,int estadoDelLugar);

/** \brief Pide todos los datos de un empleado y los da de alta generando un id automaticamente
 *
 * \param unArray[] eEmpleado El array en donde guardar los elementos
 * \param tam int La longitud del array
 * \param contDeAltas int* El contador que genera un id automaticamente
 * \param listaLocalidades[] eLocalidad El array de localidades
 * \param tamLocalidades int La longitud de la localidad
 * \return void No retorna nada
 *
 */
void darDeAlta(eEmpleado unArray[],int tam,int* contDeAltas,eLocalidad listaLocalidades[],int tamLocalidades);

/** \brief Pide cada elemento del array de forma secuencial
 *
 * \param unArray[] eEmpleado El array en donde guardar los elementos
 * \param tam int La longitud del array
 * \param indice int El indice del array en el que se guardaran los elementos
 * \param listaLocalidades[] eLocalidad El array de localidades
 * \param tamLocalidades int La longitud de la localidad
 * \return int Si se ingresaron todos los datos correctamente [1] si no [0]
 *
 */
int pedirDatosSecuenciales(eEmpleado unArray[],int tam,int indice,eLocalidad listaLocalidades[],int tamLocalidades);

/** \brief Pide un id del empleado y lo da de baja
 *
 * \param unArray[] eEmpleado El array con el id a dar de baja
 * \param tam int La longitud del array
 * \param unaLocalidad[] eLocalidad El array con la localidad
 * \param tamLocalidad int La longitud de la localidad
 * \return void No retorna nada
 *
 */
void darDeBaja(eEmpleado unArray[],int tam,eLocalidad unaLocalidad[],int tamLocalidad);

/** \brief Muestra un menu de opciones preguntando solo por los datos a modificar
 *
 * \param unArray[] eEmpleado El array en donde se guardaran los datos
 * \param tam int La longitud del array
 * \param indice int El indice del array en donde guardar los elementos
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidades int La longitud de las localidades
 * \return void No retorna nada
 *
 */
void pedirDatosAEleccion(eEmpleado unArray[],int tam,int indice,eLocalidad listaLocalidades[],int tamLocalidades);

/** \brief Pide un id del empleado y pregunta por los datos que se desean modificar
 *
 * \param unArray[] eEmpleado El array en donde se modificaran los datos
 * \param tam int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidades int La longitud de las localidades
 * \return void No retorna nada
 *
 */
void modificarArray(eEmpleado unArray[],int tam,eLocalidad listaLocalidades[],int tamLocalidades);

/** \brief Muestra solo un dato
 *
 * \param unArray eEmpleado El empleado a mostrar
 * \return void No retorna nada
 *
 */
void mostrarSoloUno(eEmpleado unArray);

/** \brief Muestra un elemento del array junto con su localidad
 *
 * \param unArray[] eEmpleado El array con los elementos a mostrar
 * \param unaLocalidad[] eLocalidad El array con la localidad a mostrar
 * \param indiceLocalidad int El indice de la localidad
 * \return void No retorna nada
 *
 */
void mostrarSoloUnoConSuLocalidad(eEmpleado unEmpleado,eLocalidad unaLocalidad[],int indiceLocalidad);

/** \brief Muestra cada elemento ocupado del array con su localidad
 *
 * \param listaArray[] eEmpleado El array con los elementos a mostrar
 * \param tam int La longitud del array
 * \param listaLocalidad[] eLocalidad El array con las localidades a mostrar
 * \param tamLocalidad int La longitud de las localidades
 * \return void No retorna nada
 *
 */
void mostrarArrayConSusLocalidades(eEmpleado listaArray[],int tam,eLocalidad listaLocalidad[],int tamLocalidad);
#endif // ABM_H_INCLUDED
