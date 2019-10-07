#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED
typedef struct
{
    int idLocalidad;
    int contadores;
} eAuxLocalidad;

typedef struct
{
    int codigoPostal;
    char nombreLocalidad[51];
    int id;
} eLocalidad;

/** \brief Busca el id de una localidad y retorna su indice
 *
 * \param listaLocalidades[] eLocalidad El array con la localidad a buscar
 * \param tamLocalidad int La longitud del array
 * \param idABuscar int El id a buscar en el array
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int buscarUnaLocalidadPorId(eLocalidad listaLocalidades[],int tamLocalidad,int idABuscar);

/** \brief Busca solo el estado en el cual se encuentra la localidad
 *
 * \param listaLocalidades[] eLocalidad El array con el estado a buscar
 * \param tamLocalidad int La longitud del array
 * \param estadoLocalidad int El estado a buscar en el array
 * \return int Si encontro el estado retorna el indice, si no lo encontro [-1]
 *
 */
int buscarSoloEstadoLocalidad(eLocalidad listaLocalidades[],int tamLocalidad,int estadoLocalidad);

/** \brief Harcodea 3 localidades
 *
 * \param listaLocalidades[] eLocalidad El array con las localidades a harcodear
 * \param tamLocalidad int La longitud del array
 * \return void No retorna nada
 *
 */
void harcodearLocalidades(eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Muestra todas las localidades que se encuentren en alta
 *
 * \param listaLocalidades[] eLocalidad El array con los datos a mostrar
 * \param tamLocalidad int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarListaDeLocalidades(eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Muestra solo una locadidad
 *
 * \param unaLocalidad eLocalidad La localidad a mostrar
 * \return void No retorna nada
 *
 */
void mostrarUnaLocalidad(eLocalidad unaLocalidad);

/** \brief Busca una localidad por su nombre
 *
 * \param listaLocalidades[] eLocalidad Elarray con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \param nombreLocalidad[] char El nombre de la localidad a buscar
 * \return int Si encontro la localidad retorna su indice, si no [-1]
 *
 */
int buscarLocalidadPorNombre(eLocalidad listaLocalidades[],int tamLocalidad,char nombreLocalidad[]);
#endif // LOCALIDAD_H_INCLUDED
