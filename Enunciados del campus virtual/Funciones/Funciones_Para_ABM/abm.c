#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"

/** \brief Pide un numero entero y lo retorna
 *
 * \param mensaje[] El mensaje pidiendo un numero
 * \return Un numero entero
 *
 */
int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxInt);
    return auxInt;
}
/** \brief Pide un numero flotante y lo retorna
 *
 * \param mensaje[] El mensaje pidiendo un numero flotante
 * \return Un numero flotante
 *
 */
float getFloat(char mensaje[])
{
    float auxFloat;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxFloat);
    return auxFloat;
}
/** \brief Pide un caracter y lo retorna
 *
 * \param mensaje[] El mensaje pidiendo una letra
 * \return Un caracter
 *
 */
char getChar(char mensaje[])
{
    char auxChar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxChar);
    return auxChar;
}
/** \brief Pide una cadena de caracteres y guarda el valor en un array
 *
 * \param mensaje[] El mensaje pidiendo una palabra
 * \param cadena[] El array donde se guarda la palabra ingresada
 * \return No retorna nada
 *
 */
void getString(char mensaje[],char cadena[])
{
    printf("%s",mensaje);
    gets(cadena);
}
/** \brief Valida si el array ingresado solo contiene numeros
 *
 * \param cadena[] La cadena de caracteres ingresada
 * \return 1 si es solo numeros y 0 si no contiene solo numeros
 *
 */
int validarSoloNumeros(char cadena[])
{
    int retorno=1;
    int i=0;
    while(cadena[i] != '\0')
    {
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
/** \brief Recibe un array y valida si contiene solo letras
 *
 * \param cadena[] La cadena de caracteres ingresada
 * \return 1 si es solo letras y 0 si no contiene solo letras
 *
 */
int validarSoloLetras(char cadena[])
{
    int retorno=1;
    int i=0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
/** \brief Pide un array y devuelve el valor si contiene solo numeros
 *
 * \param mensaje[] El mensaje pidiendo un numero
 * \param unArray[] El array donde se guardan los numeros
 * \return 1 si es solo numeros y 0 si no contiene solo numeros
 *
 * Se requiere utilizar: #include <string.h>
 */
int getStrNumeros(char mensaje[],char unArray[])
{
    int retorno=0;
    char auxArray[50];
    getString(mensaje,auxArray);
    if(validarSoloNumeros(auxArray))
    {
        strcpy(unArray,auxArray);
        retorno=1;
    }
    return retorno;
}
/** \brief Pide un array y devuelve el valor si contiene solo letras
 *
 * \param mensaje[] El mensaje pidiendo una letra
 * \param unArray[] El array donde se guardan las letras
 * \return 1 si es solo letras y 0 si no contiene solo letras
 *
 * Se requiere utilizar: #include <string.h>
 */
int getStrLetras(char mensaje[],char unArray[])
{
    int retorno=0;
    char auxArray[50];
    getString(mensaje,auxArray);
    if(validarSoloLetras(auxArray))
    {
        strcpy(unArray,auxArray);
        retorno=1;
    }
    return retorno;
}
/** \brief Recorre cada lugar del array y lo inicializa con un valor
 *
 * \param unArray[] El array entero usado como legajo
 * \param tam La longitud del array
 * \param valor El valor a inicializar cada legajo
 * \return Cada legajo con el valor inicializado
 *
 */
void inicializarLegajo(int unArray[],int tam,int valor)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i]=valor;
    }
}
/** \brief Recore cada lugar del array hasta que encuentra el valor indicado
 *
 * \param unArray[] El array entero usado como legajo
 * \param tam La longitud del array
 * \param valorABuscar El valor que se quiere encontrar
 * \return Retorna el indice en donde se encontro el valor y retorna -1 si no se encontro el valor
 *
 */
int buscarLugarLibre(int unArray[],int tam,int valorABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i] == valorABuscar)
        {
            retorno=i;
        }
    }
    return retorno;
}
