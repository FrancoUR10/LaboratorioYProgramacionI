#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[51];
}eGenero;

void harcodearGenero(eGenero listaGeneros[],int tamGeneros);

#endif // GENERO_H_INCLUDED
