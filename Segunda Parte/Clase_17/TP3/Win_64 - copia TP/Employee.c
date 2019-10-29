#include <stdlib.h>
#include <string.h>
#include "Employee.h"



int employee_setId(Employee* this,int id)
{

    int todoOk = 0;

    if( this != NULL && id > 0)
    {

        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{

    int todoOk = 0;

    if( this != NULL && id != NULL )
    {

        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}


int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL && strlen(nombre) > 3)
    {

        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;

}
int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;

    if( this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* this;

        if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
        {
            this  = employee_new();

            if( this != NULL){

            if( !employee_setId(this, atoi(idStr))||

                !employee_setNombre(this, nombreStr) ||

                !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||

                !employee_setSueldo(this, atoi(sueldoStr)))
                       {
                            free(this);
                            this = NULL;
                       }
            }
        }

    return this;
}


void mostrarEmpleado(Employee* emp){
    if(emp != NULL){
    printf("%d  %s  %d  %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
    else{
        printf("es nulo");
    }
}
int compararPorLegajo(void* e1,void* e2)
{
    int comparacion=-1;
    int id1;
    int id2;
    Employee* empleado1=(Employee*)e1;
    Employee* empleado2=(Employee*)e2;
    employee_getId(empleado1,&id1);
    employee_getId(empleado2,&id2);
    if( id1 > id2)
    {
        comparacion=1;
    }
    else if( id1 == id2)
    {
        comparacion=0;
    }
    return comparacion;
}
int compararPorSueldo(void* e1,void* e2)
{
    int comparacion=-1;
    int sueldo1;
    int sueldo2;

    Employee* empleado1=(Employee*)e1;
    Employee* empleado2=(Employee*)e2;
    employee_getSueldo(empleado1,&sueldo1);
    employee_getSueldo(empleado2,&sueldo2);
    if( sueldo1 > sueldo2)
    {
        comparacion=1;
    }
    else if( sueldo1 == sueldo2)
    {
        comparacion=0;
    }
    return comparacion;
}
int compararPorNombre(void* e1,void* e2)
{
    int comparacion=-1;

    Employee* empleado1=(Employee*)e1;
    Employee* empleado2=(Employee*)e2;

    char* n1;
    char* n2;
    employee_getNombre(empleado1,n1);
    employee_getNombre(empleado2,n2);
    comparacion=strcmp(n1,n2);
    return comparacion;
}
/*
void darDeAlta(Employee* listaEmpleado,int tamEmpleado,int* contAltas)
{
    int sePudo;
    int auxIdInt;
    int indiceLibre;
    indiceLibre=buscarUnEstado(listaEmpleado,tamEmpleado,1);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxIdInt=*contAltas;
        sePudo=pedirDatosSecuenciales(listaEmpleado,tamEmpleado,indiceLibre);
        if(sePudo==1)
        {
            *contAltas=auxIdInt+1;
            listaEmpleado[indiceLibre].id=auxIdInt;
            listaEmpleado[indiceLibre].estado=OCUPADO;
            printf("\nSe ha dado de alta al id numero %d\n",auxIdInt);
        }
        else if(sePudo==0)
        {
            printf("\nAlta cancelada por el usuario\n");
        }
        else
        {
            printf("\nAlta cancelada\n");
        }
    }
}
*/
int pedirDatosSecuenciales(LinkedList* listaEmpleado,int* contAltas)
{
    int sePudo=-1;
    int auxIdInt=*contAltas;
    char auxHorasStr[256];
    char auxSueldoStr[256];
    char auxNombreStr[256];
    char confirmacion;
    Employee* auxDatos;
    int ingresoSecuencialValido=1;

    if(ingresoSecuencialValido==1)
    {
        if(!getStrLetras("\nIngrese el nombre: ",auxNombreStr,"\nSolo se permiten letras\n","\nRango valido entre 1 y 12\n",1,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese la cant. de horas trabajadas: ",auxHorasStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y el 10\n",1,10,3))
            {
                ingresoSecuencialValido=0;
            }
        else if(!getStrNumeros("\nIngrese el sueldo: ",auxSueldoStr,"\nSolo se permiten numeros\n","Numero valido entre el 800 y el 10000",800,10000,3))
        {
            ingresoSecuencialValido=0;
        }
    }
    if(ingresoSecuencialValido==1)
    {
        char auxIdChar[50];
        itoa(auxIdInt, auxIdChar, 10);

        auxDatos=employee_newParametros("1","aaa","5","801");
        mostrarEmpleado(auxDatos);
        //auxDatos->id=auxIdInt;
        //printf("%d\n", auxIdInt);
        //printf("%d--%s--%d%--d\n",auxDatos->id,auxDatos->nombre,auxDatos->id,auxDatos->id);
        confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? ('s' o 'n'): ","\nSolo confirme con ('s' o con 'n'): ");
        if(confirmacion==1)
        {
            sePudo=1;
            ll_add(listaEmpleado,auxDatos);
            *contAltas=auxIdInt+1;
        }
        else
        {
            sePudo=0;
        }
        //free(auxDatos);
    }
    return sePudo;
}
