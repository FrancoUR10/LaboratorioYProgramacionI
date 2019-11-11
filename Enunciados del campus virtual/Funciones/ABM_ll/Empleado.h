#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int edad;
    float sueldo;
}eEmpleado;

eEmpleado* empleado_nuevoEmpleado();
int empleado_borrarEmpleado(eEmpleado* empleado);
int empleado_setId(eEmpleado* empleado,int id);
int empleado_setNombre(eEmpleado* empleado,char* nombre);
int empleado_setApellido(eEmpleado* empleado,char* apellido);
int empleado_setEdad(eEmpleado* empleado,int edad);
int empleado_setSueldo(eEmpleado* empleado,float sueldo);
int empleado_getId(eEmpleado* empleado,int* id);
int empleado_getNombre(eEmpleado* empleado,char* nombre);
int empleado_getApellido(eEmpleado* empleado,char* apellido);
int empleado_getEdad(eEmpleado* empleado,int* edad);
int empleado_getSueldo(eEmpleado* empleado,float* sueldo);
eEmpleado* empleado_nuevoEmpleadoParametros(char* id,char* nombre,char* apellido,char* edad,char* sueldo);
void empleado_mostrarListaEmpleados(LinkedList* listaEmpleados);
int empleado_buscarPorId(LinkedList* listaEmpleados,int idABuscar);

void empleado_darDeAlta(LinkedList* listaEmpleados,int* contAltas);
int empleado_modificarDatos(LinkedList* listaEmpleados);
void menuPedirDatosAModificar(LinkedList* listaEmpleados,int indiceEncontrado);

#endif // EMPLEADO_H_INCLUDED
