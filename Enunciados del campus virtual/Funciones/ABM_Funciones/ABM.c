#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Validaciones.h"
#include "Localidad.h"
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
void harcodearArray(eGenerica unArray[],int tam)
{
    char nombre[3][51]={"A","B","C"};
    char apellido[3][51]={"A","B","C"};
    int edad[3]={20,30,35};
    int salario[3]={50.4,60.5,70.6};
    int id[3]={3,1,2};
    int i;
    for(i=0;i<tam;i++)
    {
        strcpy(unArray[i].nombre,nombre[i]);
        strcpy(unArray[i].apellido,apellido[i]);
        unArray[i].edad=edad[i];
        unArray[i].salario=salario[i];
        unArray[i].id=id[i];
        unArray[i].estado=OCUPADO;
    }
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
        ordenarArray(unArray,tam,1);
        for(i=0;i<tam;i++)
        {
            if(unArray[i].estado==OCUPADO)
            {
                mostrarSoloUno(unArray[i]);
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
            break;
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
            break;
        }
    }
    return retorno;
}
void darDeAlta(eGenerica unArray[],int tam,int* contDeAltas)
{
    int sePudo;
    int indiceLibre;
    int auxIdInt;
    indiceLibre=buscarSoloUnEstado(unArray,tam,LIBRE);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxIdInt=*contDeAltas;
        sePudo=pedirDatosSecuenciales(unArray,tam,indiceLibre);
        if(sePudo==-1)
        {
            printf("\nAlta del empleado cancelada\n");
        }
        else if(sePudo==0)
        {
            printf("\nAlta del empleado cancelada por el usuario\n");
        }
        else
        {
            unArray[indiceLibre].id=auxIdInt;
            unArray[indiceLibre].estado=OCUPADO;
            *contDeAltas=auxIdInt+1;
            printf("\nSe ha dado de alta el id numero %d\n",auxIdInt);
        }
    }
}
int pedirDatosSecuenciales(eGenerica unArray[],int tam,int indice)
{
    int confirmacion;
    int retorno=-1;
    eGenerica auxDatos;
    char auxEdadStr[256];
    char auxSalarioStr[256];
    int ingresoSecuencialValido=1;

    if(ingresoSecuencialValido==1)
    {
        if(!getStrLetras("\nIngrese el nombre del empleado: ",auxDatos.nombre,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 7\a\n",1,7,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrLetras("\nIngrese el apellido del empleado: ",auxDatos.apellido,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 7\a\n",1,7,3))
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
        auxDatos.edad=atoi(auxEdadStr);
        auxDatos.salario=atof(auxSalarioStr);
    }
    if(ingresoSecuencialValido==1)
    {
        confirmacion=confirmarCambios("Esta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
        if(confirmacion==1)
        {
            unArray[indice]=auxDatos;
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}
void darDeBaja(eGenerica unArray[],int tam)
{
    int confirmacion;
    int auxIdInt;
    char auxIdStr[256];
    int indiceLibre;
    int indiceResultadoBusqueda;
    indiceLibre=buscarSoloUnEstado(unArray,tam,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        mostrarArray(unArray,tam);
        if(getStrSoloNumeroSinRango("\nIngrese el id a dar de baja: ",auxIdStr,"\nSolo se permiten numeros\a\n",3))
        {
            auxIdInt=atoi(auxIdStr);
            indiceResultadoBusqueda=buscarLugarLibre(unArray,tam,auxIdInt,OCUPADO);
            if(indiceResultadoBusqueda == -1)
            {
                printf("\nNo existe el legajo ingresado\n");
            }
            else
            {
                confirmacion=confirmarCambios("Esta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    unArray[indiceResultadoBusqueda].estado=LIBRE;
                    printf("\nSe ha dado de baja al id numero %d\n",auxIdInt);
                }
                else if(confirmacion==0)
                {
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
    }
}
void pedirDatosAEleccion(eGenerica unArray[],int tam,int indice)
{
    eGenerica auxDatos;
    char auxSalarioStr[256];
    char auxEdadStr[256];
    int opcionMenu;
    char continuarMenu='s';
    int confirmacion;



    auxDatos=unArray[indice];
    do
    {
        system("cls");

        printf("NOMBRE\tAPELLIDO\tEDAD\tSUELDO\tID\n");
        printf("\nDatos actuales seleccionados:\n");
        mostrarSoloUno(unArray[indice]);
        printf("\nDatos a modificar:\n");
        mostrarSoloUno(auxDatos);

        opcionMenu=getInt("\nQue dato desea modificar?\n1-NOMBRE\n2-APELLIDO\n3-EDAD\n4-SALARIO\n5-CONFIRMAR CAMBIOS\n6-FINALIZAR MODIFICACION\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre a modificar: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 1 y 7\n",1,7,3))
                {
                    printf("\nSe ha modificado el nombre\n");
                }
                else
                {
                    printf("\nNo se pudo modificar el nombre\n");
                }
                system("pause");
                break;
            case 2:
                if(getStrLetras("\nIngrese el apellido a modificar: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 1 y 7\n",1,7,3))
                {
                    printf("\nSe ha modificado el apellido\n");
                }
                else
                {
                    printf("\nNo se pudo modificar el apellido\n");
                }
                system("pause");
                break;
            case 3:
                if(getStringSoloEdad("\nIngrese la edad a modificar: ",auxEdadStr,"\nSolo se permiten numeros\n","\nEdad permitida entre 18 y 65\n",18,65,3))
                {
                    printf("\nSe ha modificado la edad\n");
                    auxDatos.edad=atoi(auxEdadStr);
                }
                else
                {
                    printf("\nNo se pudo modificar la edad\n");
                }
                system("pause");
                break;            case 4:
                if(getStrNumerosFlotantes("\nIngrese el salario a modificar: ",auxSalarioStr,"\nSolo se permiten numeros y un solo punto\n","Rango valido entre 1 y 8",1,8,3))
                {
                    printf("\nSe ha modificado el salario\n");
                    auxDatos.salario=atof(auxSalarioStr);
                }
                else
                {
                    printf("\nNo se pudo modificar el salario\n");
                }
                system("pause");
                break;
            case 5:
                confirmacion=confirmarCambios("\nEsta seguro que desea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    unArray[indice]=auxDatos;
                    printf("\nSe han confirmado los cambios realizados\n");
                    system("pause");
                }
                else if(confirmacion==0)
                {
                    printf("\nNo se han confirmado los cambios realizados\n");
                    system("pause");
                }
                break;
            case 6:
                confirmacion=confirmarCambios("\nEsta seguro que desea finalizar la modificacion? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    printf("\nModificacion finalizada\n");
                    continuarMenu='n';
                }
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
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
    else
    {
        mostrarArray(unArray,tam);
        if(getStrSoloNumeroSinRango("\nIngrese el id a modificar: ",auxIdStr,"\nSolo se permiten numeros\a\n",3))
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
}
void mostrarSoloUno(eGenerica unArray)
{
    printf("\n%s",unArray.nombre);
    printf("\t%s",unArray.apellido);
    printf("\t\t%d",unArray.edad);
    printf("\t%.2f",unArray.salario);
    printf("\t%d\n",unArray.id);
}
