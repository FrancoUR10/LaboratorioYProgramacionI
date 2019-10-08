#ifndef ELENCO_H_INCLUDED
#define ELENCO_H_INCLUDED
typedef struct
{
    int codigoPelicula;
    int codigoActor;
    float valorContrato;
}eElenco;

void inicializarElenco(eElenco listaElencos[],int tamElenco);
void ordenarElencos(eElenco listaElencos[],int tamElencos);
#endif // ELENCO_H_INCLUDED
