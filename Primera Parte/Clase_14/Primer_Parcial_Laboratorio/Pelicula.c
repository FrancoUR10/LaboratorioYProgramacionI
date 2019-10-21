#include "Pelicula.h"

void inicializarPelicula(ePelicula listaPeliculas[],int tamPelicula)
{
    int i;
    for(i=0;i<tamPelicula;i++)
    {
        listaPeliculas[i].codigo=-1;
        strcpy(listaPeliculas[i].descripcion,"VACIO");
        listaPeliculas[i].duracion=0;
        listaPeliculas[i].idGenero=-1;
    }
}
void harcodearPelicula(ePelicula listaPeliculas[],int tamPelicula)
{
    int codigo[4]={100,200,300,400};
    char descripcion[4][51]={"Avengers","Misery","Iron Man","Orgullo y prejuicio"};
    int duracion[4]={2,4,2,3};
    int idGenero[4]={100,200,100,300};
    int dia[4]={16,11,20,18};
    int mes[4]={4,6,8,10};
    int anio[4]={2019,2004,2014,2015};
    int i;
    for(i=0;i<tamPelicula;i++)
    {
        listaPeliculas[i].codigo=codigo[i];
        strcpy(listaPeliculas[i].descripcion,descripcion[i]);
        listaPeliculas[i].duracion=duracion[i];
        listaPeliculas[i].idGenero=idGenero[i];
        listaPeliculas[i].fechaEstreno.dia=dia[i];
        listaPeliculas[i].fechaEstreno.mes=mes[i];
        listaPeliculas[i].fechaEstreno.anio=anio[i];
    }
}
void mostrarListadoPeliculas(ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGeneros)
{
    int i;
    int j;
    for(i=0;i<tamPelicula;i++)
    {
        for(j=0;j<tamGeneros;j++)
        {
            if(listaPeliculas[i].idGenero==listaGeneros[j].id)
            {
                mostrarUnaPelicula(listaPeliculas[i],listaGeneros,j);
            }
        }
    }
}
void mostrarUnaPelicula(ePelicula unaPelicula,eGenero listaGeneros[],int indiceGenero)
{
    printf("\n%s",unaPelicula.descripcion);
    printf("\t%s",listaGeneros[indiceGenero].descripcion);
    printf("\t%d",unaPelicula.duracion);
    printf("\t%d\n",unaPelicula.codigo);
}
int buscarCodigoPelicula(ePelicula listaPeliculas[],int tamPelicula,int valorABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamPelicula;i++)
    {
        if(listaPeliculas[i].codigo==valorABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void ordenarListadoDePeliculas(ePelicula listaPeliculas[],int tamPelicula)
{
    int i;
    int j;
    ePelicula auxiliar;
    for(i=0;i<tamPelicula-1;i++)
    {
        for(j=i+1;j<tamPelicula;j++)
        {
            if(strcmp(listaPeliculas[i].descripcion,listaPeliculas[j].descripcion)==1)
            {
                auxiliar=listaPeliculas[i];
                listaPeliculas[i]=listaPeliculas[j];
                listaPeliculas[j]=auxiliar;
            }
        }
    }
}
void mostrarPeliculaTerrorDespuesDe2002(ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero)
{
    int idPeliculaTerror;
    idPeliculaTerror=buscarGeneroDeTerror(listaGeneros,tamGenero);
    int i;
    for(i=0;i<tamPelicula;i++)
    {
        if((listaPeliculas[i].idGenero==idPeliculaTerror) && (listaPeliculas[i].fechaEstreno.anio > 2002))
            {
                printf("%s\n",listaPeliculas[i].descripcion);
            }
    }
}
