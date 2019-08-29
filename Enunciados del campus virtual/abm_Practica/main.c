#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"

#define MAX 100
#define LIBRE -1
#define BORRADO -2

int main()
{
    char arrayNombre[MAX][50];
    char arrayApellido[MAX][50];
    int arrayLegajo[MAX];

    char auxNombre[50];
    char auxApellido[50];
    char auxLegajoStr[50];
    int auxLegajo;

    int indiceLibre;
    int indiceBusqueda;

    int opcionIngresadaMenu;
    char continuarMenu='s';
    int i;
    inicializarLegajoArray(arrayLegajo,MAX,LIBRE);
    do
    {
        opcionIngresadaMenu=getInt("1.ALTA\n2.BAJA\n3.MODIFICAR\n4.LISTAR\n5.SALIR\nIngrese una opcion: ");
        switch(opcionIngresadaMenu)
        {
            case 1:
                indiceLibre=buscarLugarLibre(arrayLegajo,MAX,-1);
                if(indiceLibre == -1)
                {
                    printf("\nNo hay mas lugares Libres\n");
                }
                if(!getStringLetras("Ingrese el nombre a dar de alta: ",auxNombre))
                {
                    printf("\nSolo se permiten letras\n");
                    break;
                }
                if(!getStringLetras("Ingrese el apellido a dar de alta: ",auxApellido))
                {
                    printf("\nSolo se permiten letras\n");
                    break;
                }
                if(!getStringNumeros("Ingrese el legajo a dar de alta: ",auxLegajoStr))
                {
                    printf("\nSolo se permiten numeros\n");
                    break;
                }
                auxLegajo=atoi(auxLegajoStr);
                if(buscarLugarLibre(arrayLegajo,MAX,auxLegajo) != -1)
                {
                    printf("\nEl legajo ingresado ya esta ocupado\n");
                    break;
                }
                strcpy(arrayNombre[indiceLibre],auxNombre);
                strcpy(arrayApellido[indiceLibre],auxApellido);
                arrayLegajo[indiceLibre]=auxLegajo;
                break;
            case 2:
                if(!getStringNumeros("Ingrese el legajo a dar de baja: ",auxLegajoStr))
                {
                    printf("\nEl legajo debe ser un numero\n");
                    break;
                }
                auxLegajo=atoi(auxLegajoStr);
                indiceBusqueda=buscarLugarLibre(arrayLegajo,MAX,auxLegajo);
                if(indiceBusqueda == -1)
                {
                    printf("\nEl legajo ingresado no existe\n");
                    break;
                }
                arrayLegajo[indiceBusqueda]=BORRADO;
                break;
            case 3:
                if(!getStringNumeros("Ingrese el legajo a modificar: ",auxLegajoStr))
                {
                    printf("\nEl legajo debe ser un numero\n");
                    break;
                }
                auxLegajo=atoi(auxLegajoStr);
                indiceBusqueda=buscarLugarLibre(arrayLegajo,MAX,auxLegajo);
                if(indiceBusqueda == -1)
                {
                    printf("\nEl legajo ingresado no existe\n");
                    break;
                }
                if(!getStringLetras("Ingrese el nombre a modificar: ",auxNombre))
                {
                    printf("\nEl nombre solo debe tener letras\n");
                    break;
                }
                if(!getStringLetras("Ingrese el apellido a modificar: ",auxApellido))
                {
                    printf("\nEl apellido solo debe tener letras\n");
                    break;
                }
                strcpy(arrayNombre[indiceBusqueda],auxNombre);
                strcpy(arrayApellido[indiceBusqueda],auxApellido);
                break;
            case 4:
                for(i=0;i<MAX;i++)
                {
                    if((arrayLegajo[i] != LIBRE) && (arrayLegajo[i] != BORRADO))
                    {
                        printf("\nNombre: %s\nApellido: %s\nLegajo: %d\n",arrayNombre[i],arrayApellido[i],arrayLegajo[i]);
                    }
                }
                break;
            case 5:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');





    return 0;
}
