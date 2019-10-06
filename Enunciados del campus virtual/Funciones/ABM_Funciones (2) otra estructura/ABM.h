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
 * \param listaEmpleados[] eEmpleado El array a ser inicializado
 * \param tamEmpleado int La longitud del array
 * \return void No retorna nada
 *
 */
void inicializarArray(eEmpleado listaEmpleados[],int tamEmpleado);

/** \brief Harcodea 3 posiciones del array
 *
 * \param listaEmpleados[] eEmpleado El array a harcodear
 * \param tamEmpleado int La longitud del array
 * \return void No retorna nada
 *
 */
void harcodearArray(eEmpleado listaEmpleados[],int tamEmpleado);

/** \brief Muestra cada elemento del array que este en estado ocupado
 *
 * \param listaEmpleados[] eEmpleado El array con los elementos a mostrar
 * \param tamEmpleado int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarArray(eEmpleado listaEmpleados[],int tamEmpleado);

/** \brief Ordena los elementos de un array de menor a mayor
 *
 * \param listaEmpleados[] eEmpleado El array con los elementos a ordenar
 * \param tamEmpleado int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayAscendiente(eEmpleado listaEmpleados[],int tamEmpleado);

/** \brief Ordena los elementos de un array de mayor a menor
 *
 * \param listaEmpleados[] eEmpleado El array con los elementos a ordenar
 * \param tamEmpleado int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayDescendiente(eEmpleado listaEmpleados[],int tamEmpleado);

/** \brief Ordena los elementos de un array de forma ascendiente o descendiente
 *
 * \param listaEmpleados[] eEmpleado El array con los elementos a ordenar
 * \param tamEmpleado int La longitud del array
 * \param tipoDeOrden int Ordenar de menor a mayor [1] ordenar de mayor a menor [0]
 * \return void No retorna nada
 *
 */
void ordenarArray(eEmpleado listaEmpleados[],int tamEmpleado, int tipoDeOrden);

/** \brief Busca un valor del array que se encuentre en el estado indicado y devuelve su indice
 *
 * \param listaEmpleados[] eEmpleado El array con el valor a buscar
 * \param tamEmpleado int La longitud del array
 * \param valorABuscar int El valor a buscar en el array
 * \param estadoDelLugar int El estado en el que se encuentra el valor a buscar
 * \return int Si encontro el valor a buscar retorna el indice, si no lo encontro [-1]
 *
 */
int buscarLugarLibre(eEmpleado listaEmpleados[],int tamEmpleado,int valorABuscar,int estadoDelLugar);

/** \brief Busca solo un estado libre u ocupado del array y devuelve su indice
 *
 * \param listaEmpleados[] eEmpleado El array con el el estado a buscar
 * \param tamEmpleado int La longitud del array
 * \param valorABuscar int El estado libre u ocupado a buscar en el array (LIBRE:[1] OCUPADO:[0]
 * \return int Si encontro un solo estado de la condicion que se busca retorna el indice, si no lo encontro [-1]
 *
 */
int buscarSoloUnEstado(eEmpleado listaEmpleados[],int tamEmpleado,int estadoDelLugar);

/** \brief Pide todos los datos de un empleado y los da de alta generando un id automaticamente
 *
 * \param listaEmpleados[] eEmpleado El array en donde guardar los elementos
 * \param tamEmpleado int La longitud del array
 * \param contDeAltas int* El contador que genera un id automaticamente
 * \param listaLocalidades[] eLocalidad El array de localidades
 * \param tamLocalidad int La longitud de la localidad
 * \return void No retorna nada
 *
 */
void darDeAlta(eEmpleado listaEmpleados[],int tamEmpleado,int* contDeAltas,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Pide cada elemento del array de forma secuencial
 *
 * \param listaEmpleados[] eEmpleado El array en donde guardar los elementos
 * \param tamEmpleado int La longitud del array
 * \param indice int El indice del array en el que se guardaran los elementos
 * \param listaLocalidades[] eLocalidad El array de localidades
 * \param tamLocalidad int La longitud de la localidad
 * \return int Si se ingresaron todos los datos correctamEmpleadoente [1] si no [0]
 *
 */
int pedirDatosSecuenciales(eEmpleado listaEmpleados[],int tamEmpleado,int indice,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Pide un id del empleado y lo da de baja
 *
 * \param listaEmpleados[] eEmpleado El array con el id a dar de baja
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con la localidad
 * \param tamLocalidad int La longitud de la localidad
 * \return void No retorna nada
 *
 */
void darDeBaja(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Muestra un menu de opciones preguntando solo por los datos a modificar
 *
 * \param listaEmpleados[] eEmpleado El array en donde se guardaran los datos
 * \param tamEmpleado int La longitud del array
 * \param indice int El indice del array en donde guardar los elementos
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de las localidades
 * \return void No retorna nada
 *
 */
void pedirDatosAEleccion(eEmpleado listaEmpleados[],int tamEmpleado,int indice,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Pide un id del empleado y pregunta por los datos que se desean modificar
 *
 * \param listaEmpleados[] eEmpleado El array en donde se modificaran los datos
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de las localidades
 * \return void No retorna nada
 *
 */
void modificarArray(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Muestra solo un dato
 *
 * \param unEmpleado eEmpleado El empleado a mostrar
 * \return void No retorna nada
 *
 */
void mostrarSoloUno(eEmpleado unEmpleado);

/** \brief Muestra un elemento del array junto con su localidad
 *
 * \param unEmpleado[] eEmpleado El array con los elementos a mostrar
 * \param listaLocalidades[] eLocalidad El array con la localidad a mostrar
 * \param indiceLocalidad int El indice de la localidad
 * \return void No retorna nada
 *
 */
void mostrarSoloUnoConSuLocalidad(eEmpleado unEmpleado,eLocalidad listaLocalidades[],int indiceLocalidad);

/** \brief Muestra cada elemento ocupado del array con su localidad
 *
 * \param listaEmpleados[] eEmpleado El array con los elementos a mostrar
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades a mostrar
 * \param tamLocalidad int La longitud de las localidades
 * \return void No retorna nada
 *
 */
void mostrarArrayConSusLocalidades(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Muestra por cada localidad sus empleados
 *
 * \param listaEmpleados[] eEmpleado El array con los empleados
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \return void No retorna nada
 *
 */
void mostrarCadaLocalidadConSusEmpleados(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Muestra la cantidad de empleados que viven solamente en avellaneda
 *
 * \param listaEmpleados[] eEmpleado El array con los empleados
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \return void No retorna nada
 *
 */
void mostrarSoloEmpleadosDeAvellaneda(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad);

/** \brief Cuenta por cada localidad la cantidad de habitantes que residen en ella
 *
 * \param listaEmpleados[] eEmpleado El array con los residentes
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \param auxLocalidad[] eAuxLocalidad El array auxiliar de localidad
 * \return void No retorna nada
 *
 */
void contarPorCant(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[]);

/** \brief Compara cada elemento y devuelve el minimo valor
 *
 * \param listaEmpleados[] eEmpleado El array con los empleados
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \param auxLocalidad[] eAuxLocalidad El array auxiliar de localidad
 * \return int El numero minimo
 *
 */
int dameElMinimo(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[]);

/** \brief Muestra la localidad que contenga la menor cantidad de empleados
 *
 * \param listaEmpleados[] eEmpleado El array con los empleados
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \param auxLocalidad[] eAuxLocalidad El array auxiliar de localidad
 * \return void No retorna nada
 *
 */
void mostrarLocalidadConMenosEmpleados(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[]);

/** \brief Compara cada elemento y devuelve el maximo valor
 *
 * \param listaEmpleados[] eEmpleado El array con los empleados
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \param auxLocalidad[] eAuxLocalidad El array auxiliar de localidad
 * \return int El numero maximo
 *
 */
int dameElMaximo(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[]);

/** \brief Muestra la localidad que contenga la mayor cantidad de empleados
 *
 * \param listaEmpleados[] eEmpleado El array con los empleados
 * \param tamEmpleado int La longitud del array
 * \param listaLocalidades[] eLocalidad El array con las localidades
 * \param tamLocalidad int La longitud de la localidad
 * \param auxLocalidad[] eAuxLocalidad El array auxiliar de localidad
 * \return void No retorna nada
 *
 */
void mostrarLocalidadConMasEmpleados(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[]);
#endif // ABM_H_INCLUDED
