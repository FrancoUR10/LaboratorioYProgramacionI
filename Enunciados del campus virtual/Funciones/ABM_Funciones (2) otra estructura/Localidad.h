#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED
typedef struct
{
    int codigoPostal;
    char nombreLocalidad[51];
    int id;
} eLocalidad;

/** \brief Busca un id en el array y retorna su indice
 *
 * \param unaLocalidad[] eLocalidad El array con la localidad a buscar
 * \param tamLocalidad int La longitud del array
 * \param idABuscar int El id a buscar en el array
 * \return int Si encontro el id devuelve su indice, si no lo encontro [-1]
 *
 */
int buscarUnaLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int idABuscar);

/** \brief Busca solo el estado en el cual se encuentra la localidad
 *
 * \param unaLocalidad[] eLocalidad El array con el estado a buscar
 * \param tamLocalidad int La longitud del array
 * \param estadoLocalidad int El estado a buscar en el array
 * \return int Si encontro el estado retorna el indice, si no lo encontro [-1]
 *
 */
int buscarSoloEstadoLocalidad(eLocalidad unaLocalidad[],int tamLocalidad,int estadoLocalidad);

/** \brief Harcodea 3 localidades
 *
 * \param unaLocalidad[] eLocalidad El array con las localidades a harcodear
 * \param tamLocalidad int La longitud del array
 * \return void No retorna nada
 *
 */
void harcodearLocalidades(eLocalidad unaLocalidad[],int tamLocalidad);

/** \brief Muestra todas las localidades que se encuentren en alta
 *
 * \param listaLocalidades[] eLocalidad El array con los datos a mostrar
 * \param tamLocalidad int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarListaDeLocalidades(eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Muestra solo una locadidad de un indice
 *
 * \param unaLocalidad[] eLocalidad El array con un solo dato a mostrar
 * \param indiceLocalidad int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarUnaLocalidad(eLocalidad unaLocalidad[],int indiceLocalidad);
#endif // LOCALIDAD_H_INCLUDED
