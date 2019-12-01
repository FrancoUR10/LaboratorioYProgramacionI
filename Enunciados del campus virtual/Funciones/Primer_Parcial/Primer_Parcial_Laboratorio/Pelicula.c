#include "Pelicula.h"

void pelicula_harcodearDatos(ePelicula listapelicula[])
{
    int codigo[5]={1,2,3,4,5};
    char descripcion[5][51]={"Avengers","El Aro","Orgullo y prejuicio","Iron Man","Misery"};
    int duracion[5]={3,4,3,2,2};
    int idGenero[5]={1,2,3,1,4};
    int dia[5]={22,15,18,6,11};
    int mes[5]={12,5,4,3,6};
    int anio[5]={2011,2005,1989,2007,2001};
    int i;
    for(i=0;i<5;i++)
    {
        listapelicula[i].codigo=codigo[i];
        strcpy(listapelicula[i].descripcion,descripcion[i]);
        listapelicula[i].duracion=duracion[i];
        listapelicula[i].idGenero=idGenero[i];
        listapelicula[i].fechaEstreno.dia=dia[i];
        listapelicula[i].fechaEstreno.mes=mes[i];
        listapelicula[i].fechaEstreno.anio=anio[i];
    }
}
void pelicula_mostrarUnoSolo(ePelicula unapelicula,eGenero unGenero[],int indiceGenero)
{
    printf("\n%d",unapelicula.codigo);
    printf("%26s",unapelicula.descripcion);
    printf("%16d",unapelicula.duracion);
    printf("%15s\t",unGenero[indiceGenero].descripcion);
    printf("%d/%d/%d\n",unapelicula.fechaEstreno.dia,unapelicula.fechaEstreno.mes,unapelicula.fechaEstreno.anio);
}
void pelicula_mostrarLista(ePelicula listapelicula[],int tampelicula,eGenero listaGenero[],int tamGenero)
{
    int indiceBusqueda;
    int i;
    printf("\nCODIGO            DESCRIPCION      DURACION        GENERO      FECHA_ESTRENO\n");
    for(i=0;i<tampelicula;i++)
    {
        indiceBusqueda=genero_buscarPorId(listaGenero,tamGenero,listapelicula[i].idGenero);
        if(listapelicula[i].idGenero==listaGenero[indiceBusqueda].id)
        {
            pelicula_mostrarUnoSolo(listapelicula[i],listaGenero,indiceBusqueda);
        }
    }
}
int pelicula_buscarPorCodigo(ePelicula listapelicula[],int tampelicula,int codigoABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tampelicula;i++)
    {
        if(listapelicula[i].codigo==codigoABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
