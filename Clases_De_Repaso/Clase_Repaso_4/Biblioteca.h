#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

/** \brief Harcodea un array con las edades de 4 personas
 *
 * \param arrayEdades[] int El array con las edades a harcodear
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void cargarEdadesTest(int arrayEdades[],int tam);

/** \brief Muestra una lista con los datos de las personas
 *
 * \param arrayEdades[] int El array con las edades
 * \param arrayNombres[][50] char El array con los nombres
 * \param arrayApellidos[][50] char El array con los apellidos
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarLista(int arrayEdades[],char arrayNombres[][50],char arrayApellidos[][50],int tam);

/** \brief Harcodea un array con los nombres de 4 personas
 *
 * \param arrayNombres[][50] char El array con los nombres a harcodear
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void cargarNombresTest(char arrayNombres[][50],int tam);

/** \brief Harcodea un array con los apellidos de 4 personas
 *
 * \param arrayApellidos[][50] char El array con los apellidos a harcodear
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void cargarApellidosTest(char arrayApellidos[][50],int tam);

/** \brief Recibe datos de arrays paralelos y los ordena por edad
 *
 * \param arrayEdades[] int El array con las edades
 * \param arrayNombres[][50] char El array con los nombres
 * \param arrayApellidos[][50] char El array con los apellidos
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayPorEdades(int arrayEdades[],char arrayNombres[][50],char arrayApellidos[][50],int tam);

/** \brief Harcodea edad, nombre y apellido, luego ordena y muestra los datos
 *
 * \param tam int La longitud del array
 * \param arrayEdades[] int El array con las edades
 * \param arrayNombre[][50] char El array con los nombres
 * \param arrayApellidos[][50] char El array con los apellidos
 * \return void No retorna nada
 *
 */
void realizarTodo(int tam, int arrayEdades[],char arrayNombre[][50],char arrayApellidos[][50]);
#endif // BIBLIOTECA_H_INCLUDED
