/*
1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"

#define MAX 200

int main()
{
    char arrayNombres[MAX][50];
    char arrayApellidos[MAX][50];
    int arrayLegajos[MAX] ;

    char auxNombreStr[50];
    char auxApellidoStr[50];
    char auxLegajoStr[50];
    int auxLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;

    int opcionIngresada;
    char continuarMenu='s';
    int i;
    int j;

    inicializarArray(arrayLegajos,MAX,-1);
    do
    {
        switch(opcionIngresada=getInt("1.Alta\n2.Baja\n3.Modificar\n4.Listar\n5.Ordenar\n6.Salir\nIngrese una opcion: "))
        {
            case 1:
                indiceLugarLibre=buscarPrimerOcurrencia(arrayLegajos,MAX,-1);
                if(indiceLugarLibre == -1)
                {
                    printf("\nNo hay un lugar libre\n");
                    break;
                }
                if(!getStringLetras("Ingrese el nombre a dar de alta: ",auxNombreStr))
                {
                    printf("\nEl nombre solo se permite ingresarse con letras\n");
                    break;
                }
                if(!getStringLetras("Ingrese el apellido a dar de alta: ",auxApellidoStr))
                {
                    printf("\nEl apellido solo se permite ingresarse con letras\n");
                    break;
                }
                if(!getStringNumeros("Ingrese el legajo: ",auxLegajoStr))
                {
                    printf("\nEl legajo debe ser un numero\n");
                    break;
                }
                auxLegajo=atoi(auxLegajoStr);
                if(buscarPrimerOcurrencia(arrayLegajos,MAX,auxLegajo) != -1)
                {
                    printf("\nEl legajo ingresado ya esta ocupado\n");
                    break;
                }

                strcpy(arrayNombres[indiceLugarLibre],auxNombreStr);
                strcpy(arrayApellidos[indiceLugarLibre],auxApellidoStr);
                arrayLegajos[indiceLugarLibre]=auxLegajo;
                break;
            case 2:
                if(!getStringNumeros("Ingrese el legajo a dar de baja: ",auxLegajoStr))
                {
                    printf("\nEl legajo debe ser un numero\n");
                    break;
                }
                auxLegajo=atoi(auxLegajoStr);
                indiceResultadoBusqueda=buscarPrimerOcurrencia(arrayLegajos,MAX,auxLegajo);
                if(indiceResultadoBusqueda == -1)
                {
                    printf("\nEl legajo no se encuentra\n");
                    break;
                }
                arrayLegajos[indiceResultadoBusqueda]=-1;
                break;
            case 3:
                if(!getStringNumeros("Ingrese el legajo: ",auxLegajoStr))
                {
                    printf("\nEl legajo debe ser un numero\n");
                    break;
                }
                auxLegajo=atoi(auxLegajoStr);
                indiceResultadoBusqueda=buscarPrimerOcurrencia(arrayLegajos,MAX,auxLegajo);
                if(indiceResultadoBusqueda == -1)
                {
                    printf("\nEl legajo no se encuentra\n");
                    break;
                }
                if(!getStringLetras("Ingrese el nombre a modificar: ",auxNombreStr))
                {
                    printf("\nEl nombre solo se permite ingresarse con letras\n");
                    break;
                }
                if(!getStringLetras("Ingrese el apellido a modificar: ",auxApellidoStr))
                {
                    printf("\nEl apellido solo se permite ingresarse con letras\n");
                    break;
                }
                strcpy(arrayNombres[indiceResultadoBusqueda],auxNombreStr);
                strcpy(arrayApellidos[indiceResultadoBusqueda],auxApellidoStr);

                break;
            case 4:
                for(i=0;i<MAX;i++)
                {
                    if(arrayLegajos[i] != -1)
                    {
                        printf("\nNombre: %s Apellido: %s Legajo: %d\n",arrayNombres[i],arrayApellidos[i],arrayLegajos[i]);
                    }
                }
                break;
            case 5:
                for(i=1;i<MAX;i++)
                {
                    strcpy(auxApellidoStr,arrayApellidos[i]);
                    strcpy(auxNombreStr,arrayNombres[i]);
                    auxLegajo=arrayLegajos[i];
                    j=i-1;
                    while(j >= 0 && auxApellidoStr < arrayApellidos[j])
                    {
                        strcpy(arrayApellidos[j+1],arrayApellidos[j]);
                        strcpy(arrayNombres[j+1],arrayNombres[j]);
                        arrayLegajos[j+1]=arrayLegajos[j];
                        j--;
                    }
                    strcpy(arrayApellidos[j+1],auxApellidoStr);
                    strcpy(arrayNombres[j+1],auxNombreStr);
                    arrayLegajos[j+1]=auxLegajo;
                }
                printf("\nSe ordeno la lista por apellidos\n");
                break;
            case 6:
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
