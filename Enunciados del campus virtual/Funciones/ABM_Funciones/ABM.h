#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED
typedef struct
{
    int estado;
    int id;
    char nombre[51];
    char apellido[51];
    int edad;
    float salario;
    int idLocalidad;
} eGenerica;

/** \brief Inicializa cada elemento del array en estado libre
 *
 * \param unArray[] eGenerica El array a ser inicializado
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void inicializarArray(eGenerica unArray[],int tam);

/** \brief Harcodea una posicion del array con valores pasados por parametros
 *
 * \param unArray[] eGenerica El array a harcodear
 * \param indice int El indice en donde se harcodearan los valores
 * \param id int El numero de id a harcodear
 * \param nombre[] char El nombre a harcodear
 * \param apellido[] char El apellido a harcodear
 * \param edad int La edad a harcodear
 * \param salario float El salario a harcodear
 * \return void No retorna nada
 *
 */
void harcodearArray(eGenerica unArray[],int indice,int id,char nombre[],char apellido[],int edad,float salario);

/** \brief Muestra cada elemento del array que este en estado ocupado
 *
 * \param unArray[] eGenerica El array con los elementos a mostrar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarArray(eGenerica unArray[],int tam);

/** \brief Ordena los elementos de un array de menor a mayor
 *
 * \param unArray[] eGenerica El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayAscendiente(eGenerica unArray[],int tam);

/** \brief Ordena los elementos de un array de mayor a menor
 *
 * \param unArray[] eGenerica El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayDescendiente(eGenerica unArray[],int tam);

/** \brief Ordena los elementos de un array de forma ascendiente o descendiente
 *
 * \param unArray[] eGenerica El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \param tipoDeOrden int Ordenar de menor a mayor [1] ordenar de mayor a menor [0]
 * \return void No retorna nada
 *
 */
void ordenarArray(eGenerica unArray[],int tam, int tipoDeOrden);

/** \brief Busca un valor del array que se encuentre en el estado indicado y devuelve su indice
 *
 * \param unArray[] eGenerica El array con el valor a buscar
 * \param tam int La longitud del array
 * \param valorABuscar int El valor a buscar en el array
 * \param estadoDelLugar int El estado en el que se encuentra el valor a buscar
 * \return int Si encontro el valor a buscar retorna el indice, si no lo encontro [-1]
 *
 */
int buscarLugarLibre(eGenerica unArray[],int tam,int valorABuscar,int estadoDelLugar);

/** \brief Busca solo un estado libre u ocupado del array y devuelve su indice
 *
 * \param unArray[] eGenerica El array con el el estado a buscar
 * \param tam int La longitud del array
 * \param valorABuscar int El estado libre u ocupado a buscar en el array (LIBRE:[1] OCUPADO:[0]
 * \return int Si encontro un solo estado de la condicion que se busca retorna el indice, si no lo encontro [-1]
 *
 */
int buscarSoloUnEstado(eGenerica unArray[],int tam,int estadoDelLugar);

/** \brief Pide todos los datos de un empleado y los da de alta generando un id automaticamente
 *
 * \param unArray[] eGenerica El array en donde guardar los elementos
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void darDeAlta(eGenerica unArray[],int tam,int* contDeAltas);

/** \brief Pide cada elemento del array de forma secuencial
 *
 * \param unArray[] eGenerica El array en donde guardar los elementos
 * \param tam int La longitud del array
 * \param indice int El indice del array en el que se guardaran los elementos
 * \return int Si se ingresaron todos los datos correctamente [1] si no [0]
 *
 */
int pedirDatosSecuenciales(eGenerica unArray[],int tam,int indice);

/** \brief Pide un id del empleado y lo da de baja
 *
 * \param unArray[] eGenerica El array con el id a dar de baja
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void darDeBaja(eGenerica unArray[],int tam);

/** \brief Muestra un menu de opciones preguntando solo por un dato a modificar
 *
 * \param unArray[] eGenerica El array en donde se guardaran los datos
 * \param tam int La longitud del array
 * \param indice int El indice del array en donde guardar los elementos
 * \return void No retorna nada
 *
 */
void pedirDatosAEleccion(eGenerica unArray[],int tam,int indice);

/** \brief Pide un id del empleado y pregunta por un dato a modificar
 *
 * \param unArray[] eGenerica El array en donde se modificara un dato
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void modificarArray(eGenerica unArray[],int tam);

/** \brief Muestra solo un dato relacionado con un indice
 *
 * \param unArray[] eGenerica El array con un dato a mostrar
 * \param indice int El indice con un dato a mostrar
 * \return void No retorna nada
 *
 */
void mostrarUnoSoloEnElIndice(eGenerica unArray[],int indice);

/** \brief Muestra solo un dato que no dispone de un indice
 *
 * \param unArray[] eGenerica El array con un dato a mostrar
 * \return void No retorna nada
 *
 */
void mostrarSoloUno(eGenerica unArray);
#endif // ABM_H_INCLUDED
