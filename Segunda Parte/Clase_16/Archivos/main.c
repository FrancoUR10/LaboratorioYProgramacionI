#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
typedef struct
{
    int id;
    char nombre;
    int edad;
}eDato;
int main()
{
    FILE* pArchivo;
    int vector[5];
    int k=9;
    char palabra[]="Hola";
    pArchivo=fopen("empleado","wb");
    if(pArchivo!=NULL)
    {
        //fprintf(pArchivo,"Palabra: %s\nEl dia esta nublado",palabra); Solo permite escribir datos en formato texto
        fwrite(&miDato,sizeof(int),5,pArchivo);
        fclose(pArchivo);
    }


/*
    int i;
    int vector[5];
    int x;
    char palabra[50];
    pArchivo=fopen("miArchivo","rb");
    if(pArchivo!=NULL)
    {
        fread(&x,sizeof(int),1,pArchivo);
        for(i=0;i<5;i++)
        {
            printf("%d\n",vector[i]);
        }



        fclose(pArchivo);
    }
*/
    return 0;
}
