#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int dia;
    int mes;
    int anio;

} sFecha;

typedef struct
{
    char patente[50];
    sFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
    int estadoVehiculo;
} sVehiculo;

typedef struct
{
    int id;
    char nombre[51];
    sFecha fechaNac;

} sPersona;

void hardcodePersonas(sPersona [],int);
void hardcodeoAutos(sVehiculo [],int);

void mostrarPersonas(sPersona [],int);
void mostrarAutitos(sVehiculo [],int, sPersona[],int);

int buscarPorPatente(sVehiculo [],int);

void mostrarUnAutito(sVehiculo, sPersona[], int);
void mostrarUnaPersona(sPersona unaPersona[],int indice);

int buscarIndicePersona(sPersona[], int, int);

void mostrarPersonasConSusAutos(sPersona[], int, sVehiculo[], int);

//Enunciados:
void ordenarPorNombreYFecha(sPersona listaPersonas[], int tamPersonas);
void ordenarVehiculosPorNombreYPatente(sPersona listaPersonas[], int tamPersonas,sVehiculo listaVehiculos[], int tamVehiculos);
void mostrarUnSoloAuto(sVehiculo unVehiculo[],int indiceVehiculo);
void mostrarAutosConSuDuenio(sVehiculo listaVehiculo[],sPersona listaPesonas[],int tamAutos,int tamPersonas);
void mostrarSoloEstacionadosConSuDuenio(sVehiculo listaVehiculos[],sPersona listaPersonas[],int tamVehiculo,int tamPersonas);

void getString(char* mensaje,char array[]);
int buscarDuenioPorNombre(sPersona listaPersonas[],int tamPersonas,char nombreABuscar[]);
void mostrarAutosPorDuenio(char* mensaje,sPersona unDuenio[],sVehiculo listaVehiculos[],int tamPersona,int tamVehiculo);
void calcularEstadiaPorHora(sVehiculo listaVehiculos[],int tamVehiculos);
