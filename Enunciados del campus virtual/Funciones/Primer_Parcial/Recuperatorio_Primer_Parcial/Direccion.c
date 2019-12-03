#include "Direccion.h"

void direccion_harcodearDatos(eDireccion listadireccion[])
{
    char calle[4][51]={"Lautaro","Pasco","Tarija","Finki"};
    int altura[4]={1,2,3,4};
    char localidad[4][51]={"Temperley","Avellaneda","Wilde","Banfield"};
    int i;
    for(i=0;i<4;i++)
    {
        strcpy(listadireccion[i].calle,calle[i]);
        listadireccion[i].altura=altura[i];
        strcpy(listadireccion[i].localidad,localidad[i]);
    }
}
void direccion_mostrarUnoSolo(eDireccion unadireccion)
{
    printf("\n%d",unadireccion.altura);
    printf("%21s",unadireccion.calle);
    printf("%21s\n",unadireccion.localidad);
}
void direccion_mostrarLista(eDireccion listadireccion[],int tamdireccion)
{
    int i;
    printf("\nALTURA       CALLE       LOCALIDAD\n");
    for(i=0;i<tamdireccion;i++)
    {
        direccion_mostrarUnoSolo(listadireccion[i]);
    }
}
int direccion_buscarPorAltura(eDireccion listadireccion[],int tamdireccion,int alturaABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamdireccion;i++)
    {
        if(listadireccion[i].altura==alturaABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int direccion_buscarAlturaPorLocalidad(eDireccion listadireccion[],int tamdireccion,char* localidadABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamdireccion;i++)
    {
        if(strcmp(listadireccion[i].localidad,localidadABuscar)==0)
        {
            retorno=listadireccion[i].altura;
            break;
        }
    }
    return retorno;
}
