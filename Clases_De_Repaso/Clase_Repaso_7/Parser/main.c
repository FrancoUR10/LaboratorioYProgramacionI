#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Archivos.h"
// https://mockaroo.com/
// archivo=fopen("Path",""); "w escribe", "r lee", wb escribe en binario" "rb lee en binario" "a anexar datos"
// fgets(string,cant de caracteres menos uno,archivo); Lee el mensaje de un archivo.
// fprintf(archivo,"Mensaje",...); Imprime el mensaje escrito a un archivo.
// fscanf(archivo,"%[^,],.....%[^\n]\n",...); Lee el contenido de un archivo.
// 'w' si no existe lo crea y si existe lo pisa

int main()
{
    int i=0;
    FILE* archivo;
    eAlumno* listaAlumnos[10];
    eAlumno* unAlumno;
    //char mensaje[50];

    char id[10];
    char nombre[50];
    char apellido[50];
    char nota[10];

    archivo=fopen("datos.csv","r");
    if(archivo!=NULL)
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota); //Falsa lectura para omitir la primera linea.
        while(!feof(archivo))
        {
            if(feof(archivo))
            {
                break;
            }
            unAlumno=new_Alumno();
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);
            unAlumno=new_Alumno_Parametros(atoi(id),nombre,apellido,atof(nota));

            *(listaAlumnos+i)=unAlumno;
            i++;
        }
        for(i=0;i<10;i++)
        {
            printf("%s---%s---%.2f---%d\n",(*(listaAlumnos+i))->nombre,(*(listaAlumnos+i))->apellido,(*(listaAlumnos+i))->nota,(*(listaAlumnos+i))->id);
        }
        //fprintf(archivo,"Chau");
        //fgets(mensaje,49,archivo);
        //while(!feof(archivo))
        //{
            /*
            if(feof(archivo))
            {
                break;
            }
            */
            /*
            fgets(mensaje,49,archivo);
            printf("%s",mensaje);
            i++;
            */
        //}
        cerrarArchivo(archivo);
        liberarMemoria(unAlumno);
    }
    return 0;
}
