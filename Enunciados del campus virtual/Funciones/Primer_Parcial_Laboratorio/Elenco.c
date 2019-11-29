#include "Elenco.h"

void elenco_inicializarDatos(eElenco listaElenco[],int tamElenco)
{
    int i;
    for(i=0;i<tamElenco;i++)
    {
        listaElenco[i].codigoDeReparto=-1;
        listaElenco[i].codigoPelicula=-1;
        listaElenco[i].codigoActor=-1;
        listaElenco[i].valorContrato=-1;
    }
}
void elenco_harcodearDatos(eElenco listaelenco[])
{
    int codigoDeReparto[5]={1,2,3,4,5};
    int codigoPelicula[5]={3,2,3,4,5};
    int codigoActor[5]={3,2,4,1,1};
    float valorContrato[5]={5000,6000,8000,2000,3000};
    int i;
    for(i=0;i<5;i++)
    {
        listaelenco[i].codigoDeReparto=codigoDeReparto[i];
        listaelenco[i].codigoPelicula=codigoPelicula[i];
        listaelenco[i].codigoActor=codigoActor[i];
        listaelenco[i].valorContrato=valorContrato[i];
    }
}
void elenco_mostrarUnoSolo(eElenco unaelenco,eActor unActor[],int indiceActor,ePelicula unaPelicula[],int indicePelicula)
{
    printf("\n%d",unaelenco.codigoDeReparto);
    printf("%s",unActor[indiceActor].nombre);
    printf("%s",unaPelicula[indicePelicula].descripcion);
    printf("%.2f\n",unaelenco.valorContrato);
}
void elenco_mostrarLista(eElenco listaelenco[],int tamelenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula)
{
    int indiceBusquedaActor;
    int indiceBusquedaPelicula;
    int i;
    printf("\nID            DESCRIPCION\n");
    for(i=0;i<tamelenco;i++)
    {
        indiceBusquedaActor=actor_buscarPorCodigo(listaActor,tamActor,listaelenco[i].codigoActor);
        indiceBusquedaPelicula=pelicula_buscarPorCodigo(listaPelicula,tamPelicula,listaelenco[i].codigoPelicula);
        if((listaActor[indiceBusquedaActor].estado==OCUPADO) && (listaelenco[i].codigoActor==listaActor[indiceBusquedaActor].codigo) && (listaelenco[i].codigoPelicula==listaPelicula[indiceBusquedaPelicula].codigo))
        {
            elenco_mostrarUnoSolo(listaelenco[i],listaActor,indiceBusquedaActor,listaPelicula,indiceBusquedaPelicula);
        }
    }
}
int elenco_buscarPorCodigoDeReparto(eElenco listaelenco[],int tamelenco,int codigoRepartoABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamelenco;i++)
    {
        if(listaelenco[i].codigoDeReparto==codigoRepartoABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
