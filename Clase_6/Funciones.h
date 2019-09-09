#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    int arraySillas;
    int legajo;
    int estado;
    int generoDelAlumno;
    int edadDelAlumno;
}eSillas;

/** \brief Inicializa cada dato del array
 *
 * \param unArray[] eSillas El array a inicializar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void inicializarArray(eSillas unArray[],int tam);

/** \brief Harcodea una posicion del array con el valor ingresado por parametro
 *
 * \param unArray[] eSillas El array a harcodear
 * \param indice int El indice en el cual harcodear los datos
 * \param arraySillas int El numero de la silla
 * \param legajo int El legajo de la silla
 * \param estadoVacio int El estado de la silla
 * \return void No retorna nada
 *
 */
void hardcodearArray(eSillas unArray[],int indice,int arraySillas, int legajo,int edad,int genero, int estadoVacio);

/** \brief Muestra el valor maximo en un array de enteros
 *
 * \param parametroArray[] int El array con datos para buscar el maximo
 * \param cant int La longitud del array
 * \return int El maximo valor del array
 *
 */
int dameElMaximo(int parametroArray[],int cant);

/** \brief Muestra el indice del maximo valor en un array
 *
 * \param parametroArray[] int El array con enteros
 * \param cant int La longitud del array
 * \param outArrayIndices[] int El indice del numero maximo
 * \return void No retorna nada
 *
 */
void dameElIndiceMaximo(int parametroArray[],int cant, int outArrayIndices[]);

/** \brief Muestra los datos ocupados de un array
 *
 * \param unArray[] eSillas El array con los datos a mostrar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarArray(eSillas unArray[],int tam);

/** \brief Busca un indice en el array con el dato a buscar por parametro
 *
 * \param unArray[] eSillas El array con el dato a buscar
 * \param tam int La longitud del array
 * \param valorABuscar int El valor que se desea buscar
 * \param estado int El estado del array en el que se quiere realizar la busqueda
 * \return int El indice del valor encontrado o [-1] si no se encontro el valor
 *
 */
int buscarLugarLibre(eSillas unArray[],int tam,int valorABuscar,int estado);

/** \brief Pide un numero entero y lo retorna
 *
 * \param mensaje[] char El mensaje pidiendo un numero
 * \return int Un numero entero
 *
 */
int getInt(char mensaje[]);

/** \brief Valida si el caracter ingresado contiene solo numeros y lo retorna
 *
 * \param mensaje[] char El mensaje pidiendo solo numeros
 * \param unArray[] char El array con los caracteres a validar
 * \return int Si contiene solo numeros retorna [1] si no [0]
 *
 */
int getStrNumeros(char mensaje[],char unArray[]);

/** \brief Valida si el caracter ingresado contiene solo numeros
 *
 * \param mensaje[] char El mensaje pidiendo solo numeros
 * \param unArray[] char El array con los caracteres a validar
 * \return int Si contiene solo numeros retorna [1] si no [0]
 *
 */
int validarSoloNumeros(char cadena[]);
void getString(char mensaje[],char cadena[]);

/** \brief Pide los datos sobre la silla que se ocupara
 *
 * \param unArray[] eSillas El array con las sillas a ocupar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ocuparSilla(eSillas unArray[],int tam);

/** \brief Muestra la cantidad de sillas que se encuentran actualmente ocupadas
 *
 * \param unArray[] eSillas El array con las sillas ocupadas a mostrar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void contarCantSillasOcupadas(eSillas unArray[],int tam);

/** \brief Muestra la cantidad de sillas que se encuentran actualmente libres
 *
 * \param unArray[] eSillas El array con las sillas libres a mostrar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void contarCantSillasLibres(eSillas unArray[],int tam);

/** \brief Pide el legajo de la silla y la desocupa
 *
 * \param unArray[] eSillas El array con la silla a desocupar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void desocuparSilla(eSillas unArray[],int tam);
void contarCantidadDeVaronesYMujeres(eSillas unArray[],int tam);
int buscarMaximaEdad(eSillas unArray[],int tam);
void buscarIndiceDeMaximaEdad(eSillas unArray[],int tam,int arrayIndiceMaximo[]);


#endif // FUNCIONES_H_INCLUDED
