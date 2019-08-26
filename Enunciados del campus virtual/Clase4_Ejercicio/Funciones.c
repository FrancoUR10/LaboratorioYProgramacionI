#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones.h"

/** \brief Pide al usuario un numero del tipo int
 *
 * \param El mensaje pidiendo el igreso del numero
 * \return El valor del tipo int ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf(mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/** \brief Pide al usuario un numero del tipo float
 *
 * \param El mensaje pidiendo el igreso del numero
 * \return El valor del tipo float ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf(mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/** \brief Pide al usuario un solo caracter
 *
 * \param El mensaje pidiendo el ingreso del caracter
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf(mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

char getNumeroAleatorio(int desde,int hasta, int iniciar)
{
    if(iniciar)
    {
        srand (time(NULL));
    }
    return desde + (rand() % (hasta + 1 - desde));
}
