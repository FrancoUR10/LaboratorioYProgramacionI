#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define MALE 0
#define FEMALE 1

void inicializarArray(eSillas unArray[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i].arraySillas=-1;
        unArray[i].legajo=-1;
        unArray[i].edadDelAlumno=-1;
        unArray[i].generoDelAlumno=-1;
        unArray[i].estado=1;
    }
}
void hardcodearArray(eSillas unArray[],int indice,int arraySillas, int legajo,int edad,int genero, int estadoVacio)
{
    unArray[indice].arraySillas=arraySillas;
    unArray[indice].legajo=legajo;
    unArray[indice].edadDelAlumno=edad;
    unArray[indice].generoDelAlumno=genero;
    unArray[indice].estado=estadoVacio;
}
int dameElMaximo(int parametroArray[],int cant)
{
    int flagPrimerValor=1;
    int maximoNumero;
    int indice;
    for(indice=0;indice<cant;indice++)
    {
        if(flagPrimerValor==1 || parametroArray[indice] > maximoNumero)
        {
            maximoNumero=parametroArray[indice];
            flagPrimerValor=0;
        }
    }
    return maximoNumero;
}
void dameElIndiceMaximo(int parametroArray[],int cant, int outArrayIndices[])
{
    int indice;
    int indiceIndex = 0;
    int maximoNumero;
    for(indice = 0;indice<cant;indice++)
    {
        outArrayIndices[indice] = -1;
    }
    maximoNumero=dameElMaximo(parametroArray,cant);
    for(indice=0;indice<cant;indice++)
    {
        if(parametroArray[indice] == maximoNumero)
        {
            outArrayIndices[indiceIndex]=indice;
            indiceIndex++;
        }
    }
}
void mostrarArray(eSillas unArray[],int tam)
{
    int maximoIndice[256];
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estado==0)
        {
            printf("\nSilla: %d -- Edad: %d -- Legajo: %d\n",unArray[i].arraySillas,unArray[i].edadDelAlumno,unArray[i].legajo);
        }
    }
    contarCantSillasOcupadas(unArray,tam);
    contarCantSillasLibres(unArray,tam);
    contarCantidadDeVaronesYMujeres(unArray,tam);
    buscarIndiceDeMaximaEdad(unArray,tam,maximoIndice);

}
void ocuparSilla(eSillas unArray[],int tam)
{
    char auxSillasStr[256];
    char auxLegajoStr[256];
    char auxGeneroStr[256];
    char auxEdadStr[256];
    int auxSillasInt;
    int auxLegajoInt;
    int auxEdadInt;
    int auxGeneroInt;

    int indiceLibre;
    indiceLibre=buscarLugarLibre(unArray,tam,-1,1);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan sillas libres\n");
    }
    else
    {
        getStrNumeros("Ingrese el legajo de la silla: ",auxLegajoStr);
        auxLegajoInt=atoi(auxLegajoStr);
        while(auxLegajoInt==0)
        {
            printf("\nSolo se permiten numeros\n");
            getStrNumeros("Ingrese el legajo de la silla: ",auxLegajoStr);
            auxLegajoInt=atoi(auxLegajoStr);
        }
        if(buscarLugarLibre(unArray,tam,auxLegajoInt,0)!=-1)
        {
            printf("\nYa existe una silla con ese legajo\n");
        }
        else
        {
            getStrNumeros("Ingrese el numero de la silla: ",auxSillasStr);
            auxSillasInt=atoi(auxSillasStr);
            while(auxSillasInt==0)
            {
                printf("\nSolo se permiten numeros\n");
                getStrNumeros("Ingrese el numero de la silla: ",auxSillasStr);
                auxSillasInt=atoi(auxSillasStr);
            }
            getStrNumeros("Ingrese la edad del alumno: ",auxEdadStr);
            auxEdadInt=atoi(auxEdadStr);
            while(auxEdadInt==0)
            {
                printf("\nSolo se permiten numeros\n");
                getStrNumeros("Ingrese la edad del alumno: ",auxEdadStr);
                auxEdadInt=atoi(auxEdadStr);
            }
            getStrNumeros("Ingrese el genero del alumno (F:1/M:0): ",auxGeneroStr);
            auxGeneroInt=atoi(auxGeneroStr);
            while(auxGeneroInt==0)
            {
                printf("\nSolo se permiten numeros\n");
                getStrNumeros("Ingrese el genero del alumno (F:1/M:0): ",auxGeneroStr);
                auxGeneroInt=atoi(auxGeneroStr);
            }

            unArray[indiceLibre].arraySillas=auxSillasInt;
            unArray[indiceLibre].legajo=auxLegajoInt;
            unArray[indiceLibre].edadDelAlumno=auxEdadInt;
            unArray[indiceLibre].generoDelAlumno=auxGeneroInt;
            unArray[indiceLibre].estado=0;
        }

    }
}
int buscarLugarLibre(eSillas unArray[],int tam,int valorABuscar,int estado)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estado==estado)
        {
            if(unArray[i].legajo==valorABuscar)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}
int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    scanf("%d",&auxInt);
    fflush(stdin);
    return auxInt;
}
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
void getString(char mensaje[],char cadena[])
{
    printf("%s",mensaje);
    gets(cadena);
}
void contarCantSillasOcupadas(eSillas unArray[],int tam)
{
    int contadorSillasOcupadas=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estado==0)
        {
            contadorSillasOcupadas++;
        }
    }
    printf("\nCantidad de sillas ocupadas: %d\n",contadorSillasOcupadas);
}
void contarCantSillasLibres(eSillas unArray[],int tam)
{
    int contadorSillasLibres=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estado==1)
        {
            contadorSillasLibres++;
        }
    }
    printf("\nCantidad de sillas libres: %d\n",contadorSillasLibres);
}
void desocuparSilla(eSillas unArray[],int tam)
{
    char auxLegajoStr[256];
    int auxLegajoInt;

    int indiceResultadoBusqueda;
    getStrNumeros("Ingrese el legajo de la silla: ",auxLegajoStr);
    auxLegajoInt=atoi(auxLegajoStr);
    while(auxLegajoInt==0)
    {
        printf("\nSolo se permiten numeros\n");
        getStrNumeros("Ingrese el legajo de la silla: ",auxLegajoStr);
        auxLegajoInt=atoi(auxLegajoStr);
    }
    indiceResultadoBusqueda=buscarLugarLibre(unArray,tam,auxLegajoInt,0);
    if(indiceResultadoBusqueda==-1)
    {
        printf("\nEl legajo de la silla ingresada no existe\n");
    }
    else
    {
        unArray[indiceResultadoBusqueda].legajo=-1;
        unArray[indiceResultadoBusqueda].estado=1;
    }
}
void contarCantidadDeVaronesYMujeres(eSillas unArray[],int tam)
{
    int contadorCantVarones=0;
    int contadorCantMujeres=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estado==0)
        {
            if(unArray[i].generoDelAlumno==MALE)
            {
                contadorCantVarones++;
            }
            if(unArray[i].generoDelAlumno==FEMALE)
            {
                contadorCantMujeres++;
            }
        }
    }
    printf("\nCantidad de varones en sillas ocupadas: %d\n",contadorCantVarones);
    printf("\nCantidad de mujeres en sillas ocupadas: %d\n",contadorCantMujeres);
}
int buscarMaximaEdad(eSillas unArray[],int tam)
{
    int maximo;
    int flagPrimerValor=1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(flagPrimerValor ==1 || unArray[i].edadDelAlumno > maximo)
        {
            maximo=unArray[i].edadDelAlumno;
            flagPrimerValor=0;
        }
    }
    return maximo;
}
void buscarIndiceDeMaximaEdad(eSillas unArray[],int tam,int arrayIndiceMaximo[])
{
    int maximo;
    maximo=buscarMaximaEdad(unArray,tam);
    int i;
    int auxIndice=0;
    for(i=0;i<tam;i++)
    {
        arrayIndiceMaximo[i]=-1;
    }
    for(i=0;i<tam;i++)
    {
        if(unArray[i].edadDelAlumno==maximo)
        {
            arrayIndiceMaximo[auxIndice]=i;
            auxIndice++;
        }
    }
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estado==0 && arrayIndiceMaximo[i]!=-1)
        {
            printf("\nIndice de maxima edad: %d\n",arrayIndiceMaximo[i]+1);
        }
    }
}
