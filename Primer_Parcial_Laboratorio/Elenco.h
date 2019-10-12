#ifndef ELENCO_H_INCLUDED
#define ELENCO_H_INCLUDED
typedef struct
{
    int estado;
    int codigoElenco;
    int codigoPelicula;
    int codigoActor;
    float valorContrato;
}eElenco;

void menuGestionarElencos(eElenco listaElencos[],int tamElenco,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero,int* contadorDeAltasElencos);
void inicializarElenco(eElenco listaElencos[],int tamElenco);
void harcodearElenco(eElenco listaElencos[],int tamElenco);
int pedirDatosDeElencos(eElenco listaElencos[],int tamElenco,int indice,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero);
void ordenarElencos(eElenco listaElencos[],int tamElenco);
void mostrarListaElencos(eElenco listaElencos[],int tamElenco,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula);
void mostrarUnSoloElenco(eElenco unElenco,eActor listaActores[],int indiceActor);
void darDeAltaElencos(eElenco listaElencos[],int tamElenco,int* contadorDeAltasElencos,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero);
int buscarCodigoElenco(eElenco listaElencos[],int tamElenco,int codigoElenco);
int buscarActorEnElElenco(eElenco listaElencos[],int tamElenco,int codigoActorEnElenco);
#endif // ELENCO_H_INCLUDED
