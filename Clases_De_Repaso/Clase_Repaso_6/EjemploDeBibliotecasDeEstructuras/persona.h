#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int edad;
    int idLocalidad;
    int estado;

} ePersona;

#endif // PERSONA_H_INCLUDED

ePersona construirPersona(int idLocalidad);
void mostrarListadoPersonas(int cantidadRegistros, ePersona listado[]);
void mostrarPersona(ePersona persona);
void inicializarListado(int cantidadRegistros, ePersona listado[]);
int buscarLugar(int cantidadRegistros, ePersona listado[]);
int cargarPersona(int cantidadRegistros, ePersona listado[]);
int borrarPersona(int cantidadRegistros, ePersona listado[], ePersona persona);
int buscarPersona(int cantidadRegistros, ePersona listado[], ePersona persona);
