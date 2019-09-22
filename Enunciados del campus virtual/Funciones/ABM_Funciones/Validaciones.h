#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Pide un numero entero y lo retorna
 *
 * \param mensaje[] char El mensaje pidiendo un numero
 * \return int Un numero entero
 *
 */
int getInt(char mensaje[]);

/** \brief Pide un numero flotante y lo retorna
 *
 * \param mensaje[] char El mensaje pidiendo un numero
 * \return float Un numero flotante
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

/** \brief Pide una cadena de caracteres y la guarda por referencia
 *
 * \param mensaje[] char El mensaje pidiendo una palabra
 * \param unArray[] char El array en donde guardar la cadena de caracteres
 * \return void No retorna nada
 *
 */
void getString(char mensaje[],char unArray[]);
/** \brief Valida si una cadena de caracteres contiene solo numeros
 *
 * \param unArray[] char El array con la cadena de caracteres a validar
 * \return int Si contiene solo numeros [1] si no [0]
 *
 */
int validarSoloNumeros(char unArray[]);

/** \brief Valida si una cadena de caracteres contiene solo numeros y no mas de un solo punto
 *
 * \param unArray[] char El array con la cadena de caracteres a validar
 * \return int Si contiene solo numeros y no mas de un solo punto [1] si no [0]
 *
 */
int validarSoloNumerosFlotantes(char unArray[]);

/** \brief Valida si una cadena de caracteres contiene solo letras o espacios
 *
 * \param unArray[] char El array con la cadena de caracteres a validar
 * \return int Si contiene solo letras o espacios [1] si no [0]
 *
 */
int validarSoloLetras(char unArray[]);

/** \brief Pide una cadena de caracteres validando si contiene solo numeros y el rango indicado
 *
 * \param mensaje[] char El mensaje pidiendo un numero
 * \param unArray[] char El array en donde guardar la cadena de caracteres
 * \param mensajeErrorNumeros[] char El mensaje informando que solo se permiten numeros
 * \param mensajeErrorRango[] char El mensaje informando el rango minimo y maximo valido
 * \param min int El rango minimo valido
 * \param max int El rango maximo valido
 * \param intentos int La cantidad de intentos permitidos para ingresar numeros
 * \return int Si se ingresaron solo numeros [1] si se agoto la cantidad de intentos [0]
 *
 */
int getStrNumeros(char mensaje[],char unArray[],char mensajeErrorNumeros[],char mensajeErrorRango[],int min,int max,int intentos);

/** \brief Pide una cadena de caracteres validando si contiene solo numeros, no mas de un solo punto y el rango indicado
 *
 * \param mensaje[] char El mensaje pidiendo un numero del tipo float
 * \param unArray[] char El array en donde guardar la cadena de caracteres
 * \param mensajeErrorNumerosFlotantes[] char El mensaje informando que solo se permiten numeros y como minimo un punto
 * \param mensajeErrorRango[] char El mensaje informando el rango minimo y maximo valido
 * \param min int El rango minimo valido
 * \param max int El rango maximo valido
 * \param intentos int La cantidad de intentos permitidos para ingresar numeros
 * \return int Si se ingresaron solo numeros flotantes validos [1] si se agoto la cantidad de intentos [0]
 *
 */
int getStrNumerosFlotantes(char mensaje[],char unArray[],char mensajeErrorNumerosFlotantes[],char mensajeErrorRango[],int min,int max,int intentos);

/** \brief Pide una cadena de caracteres validando si contiene solo numeros y espacios, ademas del rango indicado
 *
 * \param mensaje[] char El mensaje pidiendo el ingreso de letras
 * \param unArray[] char El array en donde guardar la cadena de caracteres
 * \param mensajeErrorLetras[] char El mensaje informando que solo se permiten letras
 * \param mensajeErrorRango[] char El mensaje informando el rango minimo y maximo valido
 * \param min int El rango minimo valido
 * \param max int El rango maximo valido
 * \param intentos int La cantidad de intentos permitidos para ingresar letras
 * \return int Si se ingresaron solo letras o espacios [1] si se agoto la cantidad de intentos [0]
 *
 */
int getStrLetras(char mensaje[],char unArray[],char mensajeErrorLetras[],char mensajeErrorRango[],int min,int max,int intentos);

/** \brief Pide una cadena de caracteres y valida si contiene solo numeros y la edad permitida
 *
 * \param mensaje[] char El mensaje pidiendo una edad
 * \param unArray[] char La cadena de caracteres en donde guardar la edad
 * \param mensajeErrorNumeros[] char El mensaje de error informando que solo se permiten numeros
 * \param mensajeErrorEdadPermitida[] char El mensaje de error informando la edad permitida
 * \param minEdad int La edad minima permitida
 * \param maxEdad int La edad maxima permitida
 * \param intentos int La cantidad de intentos permitidos para ingresar una edad
 * \return int Si contiene solo numeros y la edad permitida [1] si se agoto la cantidad de intentos [0]
 *
 */
int getStringSoloEdad(char mensaje[],char unArray[],char mensajeErrorNumeros[],char mensajeErrorEdadPermitida[],int minEdad,int maxEdad,int intentos);
#endif // VALIDACIONES_H_INCLUDED
