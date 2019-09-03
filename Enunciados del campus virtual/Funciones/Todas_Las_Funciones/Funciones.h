#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide un numero entero y lo retorna
 *
 * \param mensaje[] char El mensaje pidiendo un numero
 * \return int El numero ingresado
 *
 */
int getInt(char mensaje[]);

/** \brief Pide un numero flotante y lo retorna
 *
 * \param mensaje[] char El mensaje pidiendo un numero flotante
 * \return float El numero ingresado
 *
 */
float getFloat(char mensaje[]);

/** \brief Pide un caracter y lo retorna
 *
 * \param mensaje[] char El mensaje pidiendo una letra
 * \return char Un caracter
 *
 */
char getChar(char mensaje[]);

/** \brief Pide una cadena de caracteres y guarda el valor en un array
 *
 * \param mensaje[] char El mensaje pidiendo una palabra
 * \param cadena[] char El array donde se guarda la palabra ingresada
 * \return void No retorna nada
 *
 */
void getString(char mensaje[],char cadena[]);

/** \brief Genera un numero aleatorio y lo retorna
 *
 * \param desde int Rango minimo del numero aleatorio
 * \param hasta int Rango maximo del numero aleatorio
 * \param iniciar int Valor en el que inicializa el numero
 * \return char Caracter de el numero aleatorio entre el rango seleccionado
 *
 * Se requiere utilizar: #include <time.h>
 */
char getNumeroAleatorio(int desde,int hasta, int iniciar);

/** \brief Valida si el array ingresado solo contiene numeros
 *
 * \param cadena[] char La cadena de caracteres ingresada
 * \return int Si contiene solo numeros retorna [1] si no [0]
 *
 */
int validarSoloNumeros(char cadena[]);

/** \brief Recibe un array y valida si contiene solo letras
 *
 * \param cadena[] char La cadena de caracteres ingresada
 * \return int Si contiene solo letras retorna [1] si no [0]
 *
 */
int validarSoloLetras(char cadena[]);

/** \brief Recibe un array y valida si es alfa numerico
 *
 * \param cadena[] char La cadena de caracteres ingresada
 * \return int Si contiene caracteres alfa numericos retorna [1] si no [0]
 *
 */
int validarAlfaNumericos(char cadena[]);

/** \brief Recibe un array y valida si es un numero de telefono
 *
 * \param cadena[] char la cadena de caracteres ingresada
 * \return int Si contiene numeros y un solo guion retorna [1] si no [0]
 *
 */
int validarNumeroTelefono(char cadena[]);

/** \brief Pide un array y devuelve el valor si contiene solo numeros
 *
 * \param mensaje[] char El mensaje pidiendo un numero
 * \param unArray[] char El array donde se guardan los numeros
 * \return int Si contiene solo numeros retorna [1] si no [0]
 *
 * Utiliza la funcion: validarSoloNumeros
 * Utiliza la funcion: getString
 * Se requiere utilizar: #include <string.h>
 */
int getStrNumeros(char mensaje[],char unArray[]);

/** \brief Pide un array y devuelve el valor si contiene solo letras
 *
 * \param mensaje[] char El mensaje pidiendo una palabra
 * \param unArray[] El array donde se guardan las palabras
 * \return int Si contiene solo letras retorna [1] si no [0]
 *
 * Utiliza la funcion: validarSoloLetras
 * Utiliza la funcion: getString
 * Se requiere utilizar: #include <string.h>
 */
int getStrLetras(char mensaje[],char unArray[]);

/** \brief Recorre cada lugar del array y lo inicializa con un valor
 *
 * \param unArray[] int El array usado como legajo
 * \param tam int La longitud del array
 * \param valor El valor a inicializar cada legajo
 * \return void No retorna nada
 *
 */
void inicializarLegajo(int unArray[],int tam,int valor);

/** \brief Recore cada lugar del array hasta que encuentra el valor indicado
 *
 * \param unArray[] int El array usado como legajo
 * \param tam int La longitud del array
 * \param valorABuscar int El valor que se quiere encontrar
 * \return int El indice en donde se encontro el valor o [-1] si no se encontro
 *
 */
int buscarLugarLibre(int unArray[],int tam,int valorABuscar);








#endif // FUNCIONES_H_INCLUDED
