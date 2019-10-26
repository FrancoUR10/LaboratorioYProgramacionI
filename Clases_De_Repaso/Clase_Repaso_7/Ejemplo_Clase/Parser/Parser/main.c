
#include <stdlib.h>
#include "Alumno.h"


int main()
{
    eAlumno* lista[10];
    FILE* archivo;
    int i=0;
    eAlumno* unAlumno;
    char id[10];
    char nombre[50];
    char apellido[50];
    char nota[10];

    archivo = fopen("datos.csv","r");

    fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);

    while(!feof(archivo))
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);

        unAlumno =new_Alumno_Parametros(atoi(id),
                                        nombre,
                                        apellido,
                                        atof(nota));


        setId(unAlumno,7);

        *(lista+i) = unAlumno;
        i++;

    }

    fclose(archivo);

    for(i=0; i<10; i++)
    {
        unAlumno = *(lista+i);
        printf("%d--%s--%s--%f\n",getId(unAlumno), (*(lista+i))->nombre,(*(lista+i))->apellido, (*(lista+i))->nota);

    }

    return 0;
}
