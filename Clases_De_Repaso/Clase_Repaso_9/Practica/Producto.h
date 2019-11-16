#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"
#define ACTIVO 0
#define NO_ACTIVO 1
typedef struct
{
    int codigo;
    char descripcion[51];
    float importe;
    int cantidad;
    int activo;
}eProducto;

/** \brief Recerba espacio en memoria e inicializa un producto
 *
 * \return eProducto* [NULL] si no encontro espacio o la posicion de memoria del producto si encontro espacio
 *
 */
eProducto* producto_nuevoProducto();

/** \brief Libera el espacio en memoria de un producto
 *
 * \param producto eProducto* El puntero a un producto
 * \return int Si libero al producto [1] si no [0]
 *
 */
int producto_borrarProducto(eProducto* producto);

/** \brief Setea el id a un producto
 *
 * \param producto eProducto* El puntero a un producto
 * \param id int El id a setear
 * \return int Si seteo el id [1] si no [0]
 *
 */
int producto_setCodigo(eProducto* producto,int codigo);

/** \brief Setea el nombre a un producto
 *
 * \param producto eProducto* El puntero a un producto
 * \param nombre char* El nombre a setear
 * \return int Si seteo el nombre [1] si no [0]
 *
 */
int producto_setDescripcion(eProducto* producto,char* descripcion);

/** \brief Setea la edad a un producto
 *
 * \param producto eProducto* El puntero a un producto
 * \param edad int La edad a setear
 * \return int Si seteo la edad [1] si no [0]
 *
 */
int producto_setCantidad(eProducto* producto,int cantidad);

/** \brief Setea el sueldo a un producto
 *
 * \param producto eProducto* El puntero a un producto
 * \param sueldo float El elSueldo a setear
 * \return int Si seteo el sueldo [1] si no [0]
 *
 */
int producto_setImporte(eProducto* producto,float importe);

/** \brief Obtiene el id de un producto por parametros
 *
 * \param producto eProducto* El puntero a un producto
 * \param id int* El id a obtener
 * \return int Si se obtuvo el id [1] si no [0]
 *
 */
int producto_getCodigo(eProducto* producto,int* codigo);

/** \brief Obtiene el nombre de un producto por parametros
 *
 * \param producto eProducto* El puntero a un producto
 * \param nombre char* El nombre a obtener
 * \return int Si se obtuvo el nombre [1] si no [0]
 *
 */
int producto_getDescripcion(eProducto* producto,char* descripcion);

/** \brief Obtiene la edad de un producto por parametros
 *
 * \param producto eProducto* El puntero a un producto
 * \param edad int* La edad a obtener
 * \return int Si se obtuvo la edad [1] si no [0]
 *
 */
int producto_getCantidad(eProducto* producto,int* cantidad);

/** \brief Obtiene el sueldo de un producto por parametros
 *
 * \param producto eProducto* El puntero a un producto
 * \param sueldo float* El sueldo a obtener
 * \return int Si se obtuvo el sueldo [1] si no [0]
 *
 */
int producto_getImporte(eProducto* producto,float* importe);

/** \brief Recerba espacio en memoria para un producto y setea todos sus campos pasados por parametros
 *
 * \param id char* El id tipo string a setear
 * \param nombre char* El nombre a setear
 * \param apellido char* El apellido a setear
 * \param edad char* La edad tipo string a setear
 * \param sueldo char* El sueldo tipo string a setear
 * \return eProducto* [NULL] si no encontro espacio o la direccion de memoria si encontro espacio
 *
 */
eProducto* producto_nuevoProductoParametros(char* codigo,char* descripcion,char* cantidad,char* importe);

/** \brief Recibe dos productos y compara el nombre de ambos
 *
 * \param producto1 void* El puntero del primer producto
 * \param producto2 void* El puntero del segundo producto
 * \return int Si el primer producto es mayor al segundo [1], si es menor [-1] si son iguales [0]
 *
 */
int producto_compararPorDescripcion(void* producto1,void* producto2);

/** \brief Muestra los datos de un solo producto
 *
 * \param unproducto eProducto* El puntero a un producto
 * \return int Si el puntero es nulo [0] si se mostraron los datos [1]
 *
 */
int producto_mostrarUnProducto(eProducto* unproducto);

/** \brief Muestra la lista con todos los productos
 *
 * \param listaproductos LinkedList* La lista de productos
 * \return void No retorna nada
 *
 */
void producto_mostrarListaProductos(LinkedList* listaproductos);

/** \brief Busca el indice de un producto por su id
 *
 * \param listaproductos LinkedList* La lista de productos
 * \param idABuscar int El id a buscar en la lista
 * \return int Si lo encontro retorna el indice, si no lo encontro [-1]
 *
 */
int producto_buscarPorCodigo(LinkedList* listaproductos,int codigoABuscar);

/** \brief Busca el indice de un producto por su estado
 *
 * \param listaproductos LinkedList* La lista de productos
 * \param estadoABuscar int El estado a buscar en la lista
 * \return int Si lo encontro retorna el indice, si no lo encontro [-1]
 *
 */
int producto_buscarPorEstado(LinkedList* listaproductos,int estadoABuscar);

/** \brief Da de alta a un nuevo producto en la lista
 *
 * \param listaproductos LinkedList* La lista de productos
 * \param contAltas int* El contador para generar un nuevo id automaticamente
 * \return int Si se dio de alta [1] si cancelo el usuario [0] si no se logro el alta [-1]
 *
 */
int producto_darDeAlta(LinkedList* listaproductos,int* contAltas);

/** \brief Da de baja a un producto en la lista de manera logica
 *
 * \param listaproductos LinkedList* La lista de productos
 * \return int Si se dio de baja [1] si cancelo el usuario [0] si no se logro la baja [-1]
 *
 */
int producto_darDeBajaLogica(LinkedList* listaproductos);

/** \brief Da de baja a un producto en la lista de manera fisica
 *
 * \param listaproductos LinkedList* La lista de productos
 * \return int Si se dio de baja [1] si cancelo el usuario [0] si no se logro la baja [-1]
 *
 */
int producto_darDeBajaFisica(LinkedList* listaproductos);

/** \brief Modifica a un producto en la lista
 *
 * \param listaproductos LinkedList* La lista de productos
 * \return int Si se accedio al menu de modificaciones [1] si no se logro obtener al producto [-1]
 *
 */
int producto_modificarDatos(LinkedList* listaproductos);

/** \brief Recibe el indice de un producto y pregunta por los datos a modificar
 *
 * \param listaproductos LinkedList* La lista de productos
 * \param indiceEncontrado int El indice del producto a modificar
 * \return void No retorna nada
 *
 */
void producto_pedirDatosAModificar(LinkedList* listaproductos,int indiceEncontrado);

/** \brief Guarda los datos de los productos en modo binario
 *
 * \param archivo FILE* El archivo en donde guardar los datos
 * \param listaproductos LinkedList* La lista de productos
 * \param contAltas int* El contador de altas a guardar en la primer posicion del archivo
 * \return int Si se pudo guardar los datos [1] si no [-1]
 *
 */
int producto_guardarDatos(FILE* archivo,LinkedList* listaproductos,int* contAltas);

/** \brief Carga los datos de los productos que fueron guardados en modo binario
 *
 * \param archivo FILE* El archivo en donde se guardaron los datos
 * \param listaproductos LinkedList* La lista de productos
 * \param contAltas int* El contador de altas a obtener desde la primer posicion del archivo
 * \return int Si se pudo cargar los datos [1] si no [-1]
 *
 */
int producto_cargarDatos(FILE* archivo,LinkedList* listaproductos,int* contAltas);

/** \brief Informa sobre los productos en la lista
 *
 * \param listaProductos LinkedList* La lista de productos
 * \return void No retorna nada
 *
 */
void producto_informarDatos(LinkedList* listaProductos);

/** \brief Muestra la lista de los productos no activos
 *
 * \param listaProductos LinkedList* La lista de productos
 * \return void No retorna nada
 *
 */
void producto_mostrarListaProductosNoActivos(LinkedList* listaProductos);
#endif // PRODUCTO_H_INCLUDED
