#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Validaciones.h"
#define LIBRE 1
#define OCUPADO 0

void inicializarArray(eGenerica unArray[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i].id=-1;
        unArray[i].estado=1;
        strcpy(unArray[i].nombre,"VACIO");
        strcpy(unArray[i].apellido,"VACIO");
        unArray[i].edad=0;
        unArray[i].salario=0;
    }
}
void harcodearArray(eGenerica unArray[],int indice,int id,char nombre[],char apellido[],int edad,float salario)
{
    unArray[indice].id=id;
    unArray[indice].estado=0;
    strcpy(unArray[indice].nombre,nombre);
    strcpy(unArray[indice].apellido,apellido);
    unArray[indice].edad=edad;
    unArray[indice].salario=salario;
}
void mostrarArray(eGenerica unArray[],int tam)
{
    int indiceLibre;
    int i;
    indiceLibre=buscarSoloUnEstado(unArray,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        printf("\nNOMBRE\tAPELLIDO\tEDAD\tSUELDO\tID\n");
        for(i=0;i<tam;i++)
        {
            if(unArray[i].estado==OCUPADO)
            {
                //printf("\nNombre: %s --apellido: %s --Edad: %d --Salario %.2f --Id: %d\n",unArray[i].nombre,unArray[i].apellido,unArray[i].edad,unArray[i].salario,unArray[i].id);
                mostrarUnoSolo(unArray,i);
            }
        }
    }
}
void ordenarArrayAscendiente(eGenerica unArray[],int tam)
{
    int i;
    int j;
    eGenerica auxiliar;
    for(i=1;i<tam;i++)
    {
        auxiliar=unArray[i];
        j=i-1;
        while((j >= 0) && (auxiliar.id < unArray[j].id))
        {
            unArray[j+1]=unArray[j];
            j--;
        }
        unArray[j+1]=auxiliar;
    }
}
void ordenarArrayDescendiente(eGenerica unArray[],int tam)
{
    int i;
    int j;
    eGenerica auxiliar;
    for(i=1;i<tam;i++)
    {
        auxiliar=unArray[i];
        j=i-1;
        while((j >= 0) && (auxiliar.id > unArray[j].id))
        {
            unArray[j+1]=unArray[j];
            j--;
        }
        unArray[j+1]=auxiliar;
    }
}
void ordenarArray(eGenerica unArray[],int tam, int tipoDeOrden)
{
    if(tipoDeOrden==1)
    {
        ordenarArrayAscendiente(unArray,tam);
    }
    else
    {
        ordenarArrayDescendiente(unArray,tam);
    }
}
int buscarLugarLibre(eGenerica unArray[],int tam,int valorABuscar,int estadoDelLugar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if((unArray[i].estado==estadoDelLugar) && (unArray[i].id==valorABuscar))
        {
            retorno=i;
        }
    }
    return retorno;
}
int buscarSoloUnEstado(eGenerica unArray[],int tam,int estadoDelLugar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estado==estadoDelLugar)
        {
            retorno=i;
        }
    }
    return retorno;
}
void darDeAlta(eGenerica unArray[],int tam)
{
    int indiceLibre;
    char auxIdStr[256];
    int auxIdInt;
    indiceLibre=buscarLugarLibre(unArray,tam,-1,LIBRE);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else if(getStrNumeros("\nIngrese el id a dar de alta: ",auxIdStr,"\nSolo se permiten numeros\a\n","\nRango valido entre 1 y 4\a\n",1,4,3))
    {
        auxIdInt=atoi(auxIdStr);
        if(buscarLugarLibre(unArray,tam,auxIdInt,OCUPADO)!=-1)
        {
            printf("\nEl id ingresado ya existe\n");
        }
        else if(!pedirDatosSecuenciales(unArray,tam,indiceLibre))
        {
            printf("\nAlta del empleado cancelada\n");
        }
        else
        {
            unArray[indiceLibre].id=auxIdInt;
            unArray[indiceLibre].estado=OCUPADO;
            printf("\nSe ha dado de alta\n");
        }
    }
}
int pedirDatosSecuenciales(eGenerica unArray[],int tam,int indice)
{
    int retorno=1;
    int ingresoSecuencialValido=1;
    char auxNombreStr[256];
    char auxApellidoStr[256];
    char auxEdadStr[256];
    char auxSalarioStr[256];

    int auxEdadInt;
    float auxSalarioFloat;
    if(ingresoSecuencialValido==1)
    {
        if(!getStrLetras("\nIngrese el nombre del empleado: ",auxNombreStr,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 8\a\n",1,8,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrLetras("\nIngrese el apellido del empleado: ",auxApellidoStr,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 8\a\n",1,8,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStringSoloEdad("\nIngrese la edad del empleado: ",auxEdadStr,"\nSolo se permiten numeros\a\n","\nEdad permitida entre 18 y 65\a\n",18,65,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumerosFlotantes("\nIngrese el salario del empleado: ",auxSalarioStr,"\nSolo se permiten numeros y solo un punto\a\n","\nRango valido entre 1 y 8\a\n",1,8,3))
        {
            ingresoSecuencialValido=0;
        }
    }
    if(ingresoSecuencialValido==1)
    {
        auxEdadInt=atoi(auxEdadStr);
        auxSalarioFloat=atof(auxSalarioStr);

        strcpy(unArray[indice].nombre,auxNombreStr);
        strcpy(unArray[indice].apellido,auxApellidoStr);
        unArray[indice].edad=auxEdadInt;
        unArray[indice].salario=auxSalarioFloat;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}
void darDeBaja(eGenerica unArray[],int tam)
{
    char auxIdStr[256];
    int auxIdInt;
    int indiceLibre;
    int indiceResultadoBusqueda;
    indiceLibre=buscarSoloUnEstado(unArray,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else if(getStrNumeros("\nIngrese el id a dar de baja: ",auxIdStr,"\nSolo se permiten numeros\a\n","\nRango valido entre 1 y 4\a\n",1,4,3))
    {
        auxIdInt=atoi(auxIdStr);
        indiceResultadoBusqueda=buscarLugarLibre(unArray,tam,auxIdInt,OCUPADO);
        if(indiceResultadoBusqueda == -1)
        {
            printf("\nNo existe el legajo ingresado\n");
        }
        else
        {
            unArray[indiceResultadoBusqueda].id=-1;
            unArray[indiceResultadoBusqueda].estado=LIBRE;
            printf("\nSe ha dado de baja\n");
        }
    }
}
void pedirDatosAEleccion(eGenerica unArray[],int tam,int indice)
{
    char auxNombreStr[256];
    char auxApellidoStr[256];
    char auxEdadStr[256];
    char auxSalarioStr[256];
    int auxEdadInt;
    float auxSalarioFloat;

    int opcionAModificar;
    char continuarModificacion='s';
    do
    {
        system("cls");
        opcionAModificar=getInt("Que dato desea modificar?\n\n1-NOMBRE\n2-APELLIDO\n3-EDAD\n4-SALARIO\n5-CANCELAR MODIFICACION\n\nIngrese una opcion: ");
        switch(opcionAModificar)
        {
            case 1:
                if(!getStrLetras("\nIngrese el nombre del empleado: ",auxNombreStr,"\nSolo se permiten letras\a\n","Rango valido entre 1 y 8",1,8,3))
                {
                    printf("\nModificacion cancelada\n");
                }
                else
                {
                    strcpy(unArray[indice].nombre,auxNombreStr);
                    printf("\nSe ha modificado el nombre\n");
                }
                continuarModificacion='n';
                break;
            case 2:
                if(!getStrLetras("\nIngrese el apellido del empleado: ",auxApellidoStr,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 8\a\n",1,8,3))
                {
                    printf("\nModificacion cancelada\n");
                }
                else
                {
                    strcpy(unArray[indice].apellido,auxApellidoStr);
                    printf("\nSe ha modificado el apellido\n");
                }
                continuarModificacion='n';
                break;
            case 3:
                if(!getStringSoloEdad("\nIngrese la edad del empleado: ",auxEdadStr,"\nSolo se permiten numeros\a\n","\nEdad permitida entre 18 y 65\a\n",18,65,3))
                {
                    printf("\nModificacion cancelada\n");
                }
                else
                {
                    auxEdadInt=atoi(auxEdadStr);
                    unArray[indice].edad=auxEdadInt;
                    printf("\nSe ha modificado la edad\n");
                }
                continuarModificacion='n';
                break;
            case 4:
                if(!getStrNumerosFlotantes("\nIngrese el salario del empleado: ",auxSalarioStr,"\nSolo se permiten numeros y solo un punto\a\n","Rango valido entre 1 y 8",1,8,3))
                {
                    printf("\nModificacion cancelada\n");
                }
                else
                {
                    auxSalarioFloat=atof(auxSalarioStr);
                    unArray[indice].salario=auxSalarioFloat;
                    printf("\nSe ha modificado el salario\n");
                }
                continuarModificacion='n';
                break;
            case 5:
                printf("\nModificacion cancelada\n");
                continuarModificacion='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\a\n");
                system("pause");
        }
    }
    while(continuarModificacion=='s');
}
void modificarArray(eGenerica unArray[],int tam)
{
    char auxIdStr[256];
    int auxIdInt;

    int indiceLibre;
    int indiceResultadoBusqueda;
    indiceLibre=buscarSoloUnEstado(unArray,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else if(getStrNumeros("\nIngrese el id a modificar: ",auxIdStr,"\nSolo se permiten numeros\a\n","\nRango valido entre 1 y 4\a\n",1,4,3))
    {
        auxIdInt=atoi(auxIdStr);
        indiceResultadoBusqueda=buscarLugarLibre(unArray,tam,auxIdInt,OCUPADO);
        if(indiceResultadoBusqueda==-1)
        {
            printf("\nEl id ingresado no existe\n");
        }
        else
        {
            pedirDatosAEleccion(unArray,tam,indiceResultadoBusqueda);
        }
    }
}
void mostrarUnoSolo(eGenerica unArray[],int indice)
{
    printf("\n%s",unArray[indice].nombre);
    printf("\t%s",unArray[indice].apellido);
    printf("\t\t%d",unArray[indice].edad);
    printf("\t%.2f",unArray[indice].salario);
    printf("\t%d\n",unArray[indice].id);
}
