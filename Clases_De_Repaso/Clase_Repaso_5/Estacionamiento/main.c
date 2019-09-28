#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labibliopa.h"
#define MAX_PERSONAS 4
#define MAX_VEHICULOS 8

int main()
{
    sPersona ListadoDePersonas[MAX_PERSONAS];
    hardcodePersonas(ListadoDePersonas,MAX_PERSONAS);
    //ordenarPorNombreYFecha(ListadoDePersonas,MAX_PERSONAS); //A
    mostrarPersonas(ListadoDePersonas,MAX_PERSONAS);

    sVehiculo ListadoDeVehiculos[MAX_VEHICULOS];
    hardcodeoAutos(ListadoDeVehiculos,MAX_VEHICULOS);

    ordenarVehiculosPorNombreYPatente(ListadoDePersonas,MAX_PERSONAS,ListadoDeVehiculos,MAX_VEHICULOS); //B

    mostrarPersonasConSusAutos(ListadoDePersonas,MAX_PERSONAS,ListadoDeVehiculos,MAX_VEHICULOS);
    printf("\n Estacionamiento!\n");

    //mostrarAutosConSuDuenio(ListadoDeVehiculos,ListadoDePersonas,MAX_VEHICULOS,MAX_PERSONAS); // c
    //mostrarSoloEstacionadosConSuDuenio(ListadoDeVehiculos,ListadoDePersonas,MAX_VEHICULOS,MAX_PERSONAS); //d
    //mostrarAutosPorDuenio("Ingrese el nombre del duenio: ",ListadoDePersonas,ListadoDeVehiculos,MAX_PERSONAS,MAX_VEHICULOS); //e
    calcularEstadiaPorHora(ListadoDeVehiculos,MAX_VEHICULOS);
    return 0;
}

