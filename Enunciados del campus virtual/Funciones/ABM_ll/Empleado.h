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


#endif // EMPLEADO_H_INCLUDED
