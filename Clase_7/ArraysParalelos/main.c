#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
#define LEN 20

//mostrar cuales son los mas viejos, agregar el nombre de cada alumno, mostrar el nombre del maximo alumno,ordene todos los alumnos que estan sentados por nombre
//Leer la clase de estructuras
int main()
{
    int legajo[T];
    char nombre[T][LEN];
    int i;
    int j;
    int auxInt;
    char auxString[LEN];
    for(i=0;i<T;i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d",&legajo[i]);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);
    }
    for(i=0;i<T-1;i++)
    {
        for(j=i+1;j<T;j++)
        {
            if(legajo[i]>legajo[j])
            {
                auxInt=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=auxInt;

                strcpy(auxString,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxString);
            }
        }
    }
    for(i=0;i<T;i++)
    {
        printf("\nLegajo: %d -- Nombre: %s\n",legajo[i],nombre[i]);
    }


    return 0;
}
