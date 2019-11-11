#include "Empleado.h"

eEmpleado* empleado_nuevoEmpleado()
{
    eEmpleado* unEmpleado=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(unEmpleado!=NULL)
    {
        unEmpleado->id=0;
        strcpy(unEmpleado->nombre,"VACIO");
        strcpy(unEmpleado->apellido,"VACIO");
        unEmpleado->edad=-1;
        unEmpleado->sueldo=-1;
    }
    return unEmpleado;
}
int empleado_borrarEmpleado(eEmpleado* empleado)
{
    int seLibero=0;
    if(empleado!=NULL)
    {
        free(empleado);
        seLibero=1;
    }
    return seLibero;
}
int empleado_setId(eEmpleado* empleado,int id)
{
    int retorno=0;
    if((empleado!=NULL) && (id > 0))
    {
        empleado->id=id;
        retorno=1;
    }
    return retorno;
}
int empleado_setNombre(eEmpleado* empleado,char* nombre)
{
    int retorno=0;
    if((empleado!=NULL) && (strlen(nombre) > 2))
    {
        strcpy(empleado->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int empleado_setApellido(eEmpleado* empleado,char* apellido)
{
    int retorno=0;
    if((empleado!=NULL) && (strlen(apellido) > 2))
    {
        strcpy(empleado->apellido,apellido);
        retorno=1;
    }
    return retorno;
}
int empleado_setEdad(eEmpleado* empleado,int edad)
{
    int retorno=0;
    if((empleado!=NULL) && (edad > 0))
    {
        empleado->edad=edad;
        retorno=1;
    }
    return retorno;
}
int empleado_setSueldo(eEmpleado* empleado,float sueldo)
{
    int retorno=0;
    if((empleado!=NULL) && (sueldo > 0))
    {
        empleado->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}
int empleado_getId(eEmpleado* empleado,int* id)
{
    int retorno=0;
    if(empleado!=NULL && id!=NULL)
    {
        *id=empleado->id;
        retorno=1;
    }
    return retorno;
}
int empleado_getNombre(eEmpleado* empleado,char* nombre)
{
    int retorno=0;
    if(empleado!=NULL && nombre!=NULL)
    {
        strcpy(nombre,empleado->nombre);
        retorno=1;
    }
    return retorno;
}
int empleado_getApellido(eEmpleado* empleado,char* apellido)
{
    int retorno=0;
    if(empleado!=NULL && apellido!=NULL)
    {
        strcpy(apellido,empleado->apellido);
        retorno=1;
    }
    return retorno;
}
int empleado_getEdad(eEmpleado* empleado,int* edad)
{
    int retorno=0;
    if(empleado!=NULL && edad!=NULL)
    {
        *edad=empleado->edad;
        retorno=1;
    }
    return retorno;
}
int empleado_getSueldo(eEmpleado* empleado,float* sueldo)
{
    int retorno=0;
    if(empleado!=NULL && sueldo!=NULL)
    {
        *sueldo=empleado->sueldo;
        retorno=1;
    }
    return retorno;
}
eEmpleado* empleado_nuevoEmpleadoParametros(char* id,char* nombre,char* apellido,char* edad,char* sueldo)
{
    eEmpleado* unEmpleado=NULL;
    if((id!=NULL) && (nombre!=NULL) && (apellido!=NULL) && (edad!=NULL) && (sueldo!=NULL))
    {
        unEmpleado=empleado_nuevoEmpleado();
        if(unEmpleado!=NULL)
        {
            if(!empleado_setId(unEmpleado,atoi(id)) || !empleado_setNombre(unEmpleado,nombre) || !empleado_setApellido(unEmpleado,apellido) || !empleado_setEdad(unEmpleado,atoi(edad)) || !empleado_setSueldo(unEmpleado,atof(sueldo)))
            {
                empleado_borrarEmpleado(unEmpleado);
                unEmpleado=NULL;
            }
        }
    }
    return unEmpleado;
}
int empleado_mostrarUnEmpleado(eEmpleado* unEmpleado)
{
    int seMostro=0;
    if(unEmpleado!=NULL)
    {
        printf("%d\t",unEmpleado->id);
        printf("%s\t",unEmpleado->nombre);
        printf("%s\t",unEmpleado->apellido);
        printf("%d\t",unEmpleado->edad);
        printf("%.2f\n",unEmpleado->sueldo);
        seMostro=1;
    }
    return seMostro;
}
void empleado_mostrarListaEmpleados(LinkedList* listaEmpleados)
{
    eEmpleado* aux;
    int i;
    int len=ll_len(listaEmpleados);
    if(listaEmpleados!=NULL)
    {
        if(ll_isEmpty(listaEmpleados)==1)
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            for(i=0;i<len;i++)
            {
                aux=ll_get(listaEmpleados,i);
                empleado_mostrarUnEmpleado(aux);
            }
        }
    }
}
int empleado_buscarPorId(LinkedList* listaEmpleados,int idABuscar)
{
    int retorno=-1;
    eEmpleado* aux;
    int i;
    int len=ll_len(listaEmpleados);
    if(listaEmpleados!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=ll_get(listaEmpleados,i);
            if(aux->id==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
void empleado_darDeAlta(LinkedList* listaEmpleados,int* contAltas)
{
    int confirmacion;
    int auxIdInt;
    char auxNombre[256];
    char auxApellido[256];
    char auxEdadStr[256];
    char auxSueldoStr[256];
    char auxIdStr[256];
    auxIdInt=*contAltas;
    eEmpleado* auxDatos=NULL;
    int ingresoSecuencialValido=1;
    if(listaEmpleados!=NULL)
    {
        if(ingresoSecuencialValido==1)
        {
            if(!getStrLetras("\nIngrese el nombre: ",auxNombre,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
            {
                ingresoSecuencialValido=0;
            }
            else if(!getStrLetras("\nIngrese el apellido: ",auxApellido,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
            {
                ingresoSecuencialValido=0;
            }
            else if(!getStrNumeros("\nIngrese la edad: ",auxEdadStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 20 y el 67\n",20,67,3))
            {
                ingresoSecuencialValido=0;
            }
            else if(!getStrNumerosFlotantes("\nIngrese el sueldo: ",auxSueldoStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre el 1000 y el 10000\n",1000,10000,3))
            {
                ingresoSecuencialValido=0;
            }
        }
        if(ingresoSecuencialValido==1)
        {
            confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n')");
            if(confirmacion==1)
            {
                itoa(auxIdInt,auxIdStr,10);
                *contAltas=auxIdInt+1;
                auxDatos=empleado_nuevoEmpleadoParametros(auxIdStr,auxNombre,auxApellido,auxEdadStr,auxSueldoStr);
                ll_add(listaEmpleados,auxDatos);
                printf("\nSe ha dado de alta al id numero %d\n",auxIdInt);
            }
            else if(confirmacion==0)
            {
                printf("\nAlta cancelada por el usuario\n");
            }
        }
        else
        {
            printf("\nAlta cancelada\n");
        }
    }
}
