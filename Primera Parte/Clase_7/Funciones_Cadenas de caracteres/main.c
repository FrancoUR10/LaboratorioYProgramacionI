#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

//Cadenas de caracteres
int main()
{
    //char palabra[10];
    //char otraPalabra[100];
    //int longitud;
    //int comp;
    //char letra;



    //printf("Ingrese una palabra: ");
    //gets(palabra);//Para windows
    //scanf("%[^\n]",palabra);//Para windows y linux
    //fgets(palabra,10,stdin);// Para windows y linux
    //fflush(stdin);

    //longitud=strlen(palabra);
    //palabra[longitud-1]='\0';
    //longitud=strlen(palabra);
    //printf("El largo es: %d",longitud);

    //strcpy(palabra,otraPalabra);
    //comp=stricmp(palabra,otraPalabra);
    //printf("Compara: %d",comp);
    //strupr(palabra); // Cambia cada letra a mayusculas
    //strlwr(palabra);// Cambia cada letra a minusculas
    //printf("La palabra es: %s\n",palabra);

    //letra=tolower(letra); //cambia a letras minusculas solo por parametro por valor
    //printf("La letra es: %s\n",palabra);

    //strcat(palabra,otraPalabra); //Concatena la primer variable con el contenido de la segunda variable
    //printf("%s",palabra);

    char nombre[15];
    char apellido[15];
    char apellidoNombre[50];

    pedirNombreYApellido(nombre,"Ingrese el nombre: ");
    pedirNombreYApellido(apellido,"Ingrese el apellido: ");

    strcpy(apellidoNombre,apellido);
    strcat(apellidoNombre,nombre);
    printf("\nApellido y nombre: %s\n",apellidoNombre);

    //En include ctype
    //isSpace
    //isDigit
    //isAlpha

    return 0;
}
