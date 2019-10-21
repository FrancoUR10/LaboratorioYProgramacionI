#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide un numero y lo retorna por puntero
 *
 * \param  int* Un numero a ingresar
 * \return void No retorna nada
 * Ejemplo de punteros
 */
void funcion(int* numero);

/** \brief Calcula el factorial de un numero
 *
 * \param int El numero sobre el que se calcula el factorial
 * \return int El factorial
 * Es una funcion recursiva
 */
unsigned int sacarFactorial(int numero);
/** \brief Recibe un numero y muestra el factorial del mismo
 *
 * \param numero int El numero a realizarle el factorial
 * \return void No retorna nada
 *
 */
void factorial(int numero);

#endif // FUNCIONES_H_INCLUDED
