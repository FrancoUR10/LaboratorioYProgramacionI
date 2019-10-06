#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Validaciones.h"
#include "Localidad.h"
#define LIBRE 1
#define OCUPADO 0

void inicializarArray(eEmpleado listaEmpleados[],int tamEmpleado)
{
    int i;
    for(i=0;i<tamEmpleado;i++)
    {
        listaEmpleados[i].id=-1;
        listaEmpleados[i].estado=1;
        strcpy(listaEmpleados[i].nombre,"VACIO");
        strcpy(listaEmpleados[i].apellido,"VACIO");
        listaEmpleados[i].edad=0;
        listaEmpleados[i].salario=0;
        listaEmpleados[i].idLocalidad=-1;
    }
}
void harcodearArray(eEmpleado listaEmpleados[],int tamEmpleado)
{
    char nombre[3][51]={"A","B","C"};
    char apellido[3][51]={"A","B","C"};
    int edad[3]={20,30,35};
    int salario[3]={50.4,60.5,70.6};
    int id[3]={3,1,2};
    int idLocalidad[3]={300,200,100};
    int i;
    for(i=0;i<tamEmpleado;i++)
    {
        strcpy(listaEmpleados[i].nombre,nombre[i]);
        strcpy(listaEmpleados[i].apellido,apellido[i]);
        listaEmpleados[i].edad=edad[i];
        listaEmpleados[i].salario=salario[i];
        listaEmpleados[i].id=id[i];
        listaEmpleados[i].idLocalidad=idLocalidad[i];
        listaEmpleados[i].estado=OCUPADO;
    }
}
void mostrarArray(eEmpleado listaEmpleados[],int tamEmpleado)
{
    int indiceLibre;
    int i;
    indiceLibre=buscarSoloUnEstado(listaEmpleados,tamEmpleado,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        printf("\nNOMBRE\tAPELLIDO\tEDAD\tSUELDO\tID\tLOCALIDAD\n");
        ordenarArray(listaEmpleados,tamEmpleado,1);
        for(i=0;i<tamEmpleado;i++)
        {
            if(listaEmpleados[i].estado==OCUPADO)
            {
                mostrarSoloUno(listaEmpleados[i]);
            }
        }
    }
}
void ordenarArrayAscendiente(eEmpleado listaEmpleados[],int tamEmpleado)
{
    int i;
    int j;
    eEmpleado auxiliar;
    for(i=1;i<tamEmpleado;i++)
    {
        auxiliar=listaEmpleados[i];
        j=i-1;
        while((j >= 0) && (auxiliar.id < listaEmpleados[j].id))
        {
            listaEmpleados[j+1]=listaEmpleados[j];
            j--;
        }
        listaEmpleados[j+1]=auxiliar;
    }
}
void ordenarArrayDescendiente(eEmpleado listaEmpleados[],int tamEmpleado)
{
    int i;
    int j;
    eEmpleado auxiliar;
    for(i=1;i<tamEmpleado;i++)
    {
        auxiliar=listaEmpleados[i];
        j=i-1;
        while((j >= 0) && (auxiliar.id > listaEmpleados[j].id))
        {
            listaEmpleados[j+1]=listaEmpleados[j];
            j--;
        }
        listaEmpleados[j+1]=auxiliar;
    }
}
void ordenarArray(eEmpleado listaEmpleados[],int tamEmpleado, int tipoDeOrden)
{
    if(tipoDeOrden==1)
    {
        ordenarArrayAscendiente(listaEmpleados,tamEmpleado);
    }
    else
    {
        ordenarArrayDescendiente(listaEmpleados,tamEmpleado);
    }
}
int buscarLugarLibre(eEmpleado listaEmpleados[],int tamEmpleado,int valorABuscar,int estadoDelLugar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamEmpleado;i++)
    {
        if((listaEmpleados[i].estado==estadoDelLugar) && (listaEmpleados[i].id==valorABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int buscarSoloUnEstado(eEmpleado listaEmpleados[],int tamEmpleado,int estadoDelLugar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamEmpleado;i++)
    {
        if(listaEmpleados[i].estado==estadoDelLugar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void darDeAlta(eEmpleado listaEmpleados[],int tamEmpleado,int* contDeAltas,eLocalidad listaLocalidades[],int tamLocalidad)
{
    int sePudo;
    int indiceLibre;
    int auxIdInt;
    indiceLibre=buscarSoloUnEstado(listaEmpleados,tamEmpleado,LIBRE);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxIdInt=*contDeAltas;
        sePudo=pedirDatosSecuenciales(listaEmpleados,tamEmpleado,indiceLibre,listaLocalidades,tamLocalidad);
        if(sePudo==-1)
        {
            printf("\nAlta del empleado cancelada\n");
        }
        else if(sePudo==0)
        {
            printf("\nAlta del empleado cancelada por el usuario\n");
        }
        else
        {
            listaEmpleados[indiceLibre].id=auxIdInt;
            listaEmpleados[indiceLibre].estado=OCUPADO;
            *contDeAltas=auxIdInt+1;
            printf("\nSe ha dado de alta el id numero %d\n",auxIdInt);
        }
    }
}
int pedirDatosSecuenciales(eEmpleado listaEmpleados[],int tamEmpleado,int indice,eLocalidad listaLocalidades[],int tamLocalidad)
{
    int indiceLocalidadEncontrada;
    int confirmacion;
    int retorno=-1;
    eEmpleado auxDatos;
    char auxEdadStr[256];
    char auxSalarioStr[256];
    char auxIdLocalidadStr[256];
    int ingresoSecuencialValido=1;

    if(ingresoSecuencialValido==1)
    {
        if(!getStrLetras("\nIngrese el nombre del empleado: ",auxDatos.nombre,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 7\a\n",1,7,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrLetras("\nIngrese el apellido del empleado: ",auxDatos.apellido,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 7\a\n",1,7,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStringSoloEdad("\nIngrese la edad del empleado: ",auxEdadStr,"\nSolo se permiten numeros\a\n","\nEdad permitida entre 18 y 65\a\n",18,65,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumerosFlotantes("\nIngrese el salario del empleado: ",auxSalarioStr,"\nSolo se permiten numeros y solo un punto\a\n","\nRango valido entre 1 y 8\a\n",1,8,3))
        {
            ingresoSecuencialValido=0;
        }
        auxDatos.edad=atoi(auxEdadStr);
        auxDatos.salario=atof(auxSalarioStr);
        if(ingresoSecuencialValido==1)
        {
            printf("Localidades disponibles:\n");
            mostrarListaDeLocalidades(listaLocalidades,tamLocalidad);
            if(getStrSoloNumeroSinRango("\nIngrese el id de una localidad: ",auxIdLocalidadStr,"\nSolo se permite el numero de una localidad\n",3))
            {
                auxDatos.idLocalidad=atoi(auxIdLocalidadStr);
                indiceLocalidadEncontrada=buscarUnaLocalidadPorId(listaLocalidades,tamLocalidad,auxDatos.idLocalidad);
                if(indiceLocalidadEncontrada==-1)
                {
                    printf("\nEl id de la localidad ingresada no existe\n");
                    ingresoSecuencialValido=0;
                }
            }
            else
            {
                ingresoSecuencialValido=0;
            }
        }
    }
    if(ingresoSecuencialValido==1)
    {
        confirmacion=confirmarCambios("Esta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
        if(confirmacion==1)
        {
            listaEmpleados[indice]=auxDatos;
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}
void darDeBaja(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad)
{
    int confirmacion;
    int auxIdInt;
    char auxIdStr[256];
    int indiceLibre;
    int indiceResultadoBusqueda;
    indiceLibre=buscarSoloUnEstado(listaEmpleados,tamEmpleado,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        mostrarArrayConSusLocalidades(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad);
        if(getStrSoloNumeroSinRango("\nIngrese el id a dar de baja: ",auxIdStr,"\nSolo se permiten numeros\a\n",3))
        {
            auxIdInt=atoi(auxIdStr);
            indiceResultadoBusqueda=buscarLugarLibre(listaEmpleados,tamEmpleado,auxIdInt,OCUPADO);
            if(indiceResultadoBusqueda == -1)
            {
                printf("\nNo existe el legajo ingresado\n");
            }
            else
            {
                confirmacion=confirmarCambios("Esta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    listaEmpleados[indiceResultadoBusqueda].estado=LIBRE;
                    printf("\nSe ha dado de baja al id numero %d\n",auxIdInt);
                }
                else if(confirmacion==0)
                {
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
    }
}
void pedirDatosAEleccion(eEmpleado listaEmpleados[],int tamEmpleado,int indice,eLocalidad listaLocalidades[],int tamLocalidad)
{
    int auxIdLocalidad;
    int indiceLocalidadEncontrada;
    int indiceLocalidadAux;
    eEmpleado auxDatos;
    char auxSalarioStr[256];
    char auxEdadStr[256];
    char auxIdLocalidadStr[256];
    int opcionMenu;
    char continuarMenu='s';
    int confirmacion;



    auxDatos=listaEmpleados[indice];
    do
    {
        system("cls");

        printf("NOMBRE\tAPELLIDO\tEDAD\tSUELDO\tID\tLOCALIDAD\n");
        printf("\nDatos actuales seleccionados:\n");
        indiceLocalidadEncontrada=buscarUnaLocalidadPorId(listaLocalidades,tamLocalidad,listaEmpleados[indice].idLocalidad);
        mostrarSoloUnoConSuLocalidad(listaEmpleados[indice],listaLocalidades,indiceLocalidadEncontrada);

        printf("\nDatos a modificar:\n");
        indiceLocalidadAux=buscarUnaLocalidadPorId(listaLocalidades,tamLocalidad,auxDatos.idLocalidad);
        mostrarSoloUnoConSuLocalidad(auxDatos,listaLocalidades,indiceLocalidadAux);


        opcionMenu=getInt("\nQue dato desea modificar?\n1-NOMBRE\n2-APELLIDO\n3-EDAD\n4-SALARIO\n5-LOCALIDAD\n6-CONFIRMAR CAMBIOS\n7-FINALIZAR MODIFICACION\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre a modificar: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 1 y 7\n",1,7,3))
                {
                    printf("\nSe ha modificado el nombre\n");
                }
                else
                {
                    printf("\nNo se pudo modificar el nombre\n");
                }
                system("pause");
                break;
            case 2:
                if(getStrLetras("\nIngrese el apellido a modificar: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 1 y 7\n",1,7,3))
                {
                    printf("\nSe ha modificado el apellido\n");
                }
                else
                {
                    printf("\nNo se pudo modificar el apellido\n");
                }
                system("pause");
                break;
            case 3:
                if(getStringSoloEdad("\nIngrese la edad a modificar: ",auxEdadStr,"\nSolo se permiten numeros\n","\nEdad permitida entre 18 y 65\n",18,65,3))
                {
                    printf("\nSe ha modificado la edad\n");
                    auxDatos.edad=atoi(auxEdadStr);
                }
                else
                {
                    printf("\nNo se pudo modificar la edad\n");
                }
                system("pause");
                break;            case 4:
                if(getStrNumerosFlotantes("\nIngrese el salario a modificar: ",auxSalarioStr,"\nSolo se permiten numeros y un solo punto\n","Rango valido entre 1 y 8",1,8,3))
                {
                    printf("\nSe ha modificado el salario\n");
                    auxDatos.salario=atof(auxSalarioStr);
                }
                else
                {
                    printf("\nNo se pudo modificar el salario\n");
                }
                system("pause");
                break;
            case 5:
                printf("\nLocalidades disponibles:\n");
                mostrarListaDeLocalidades(listaLocalidades,tamLocalidad);
                if(getStrSoloNumeroSinRango("\nIngrese el id de la localidad: ",auxIdLocalidadStr,"\nSolo se permite el numero de la localidad\n",3))
                {
                    auxIdLocalidad=atoi(auxIdLocalidadStr);
                    indiceLocalidadEncontrada=buscarUnaLocalidadPorId(listaLocalidades,tamLocalidad,auxIdLocalidad);
                    if(indiceLocalidadEncontrada!=-1)
                    {
                        printf("\nSe ha modificado la localidad\n");
                        auxDatos.idLocalidad=auxIdLocalidad;
                    }
                    else
                    {
                        printf("\nLa localidad a modificar no existe\n");
                    }
                }
                else
                {
                    printf("\nNo se pudo modificar la localidad\n");
                }
                system("pause");
                break;
            case 6:
                confirmacion=confirmarCambios("\nEsta seguro que desea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    listaEmpleados[indice]=auxDatos;
                    printf("\nSe han confirmado los cambios realizados\n");
                    system("pause");
                }
                else if(confirmacion==0)
                {
                    printf("\nNo se han confirmado los cambios realizados\n");
                    system("pause");
                }
                break;
            case 7:
                confirmacion=confirmarCambios("\nEsta seguro que desea finalizar la modificacion? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    printf("\nModificacion finalizada\n");
                    continuarMenu='n';
                }
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
void modificarArray(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad)
{
    char auxIdStr[256];
    int auxIdInt;

    int indiceLibre;
    int indiceResultadoBusqueda;
    indiceLibre=buscarSoloUnEstado(listaEmpleados,tamEmpleado,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        mostrarArrayConSusLocalidades(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad);
        if(getStrSoloNumeroSinRango("\nIngrese el id a modificar: ",auxIdStr,"\nSolo se permiten numeros\a\n",3))
        {
            auxIdInt=atoi(auxIdStr);
            indiceResultadoBusqueda=buscarLugarLibre(listaEmpleados,tamEmpleado,auxIdInt,OCUPADO);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                pedirDatosAEleccion(listaEmpleados,tamEmpleado,indiceResultadoBusqueda,listaLocalidades,tamLocalidad);
            }
        }
    }
}
void mostrarSoloUno(eEmpleado unEmpleado)
{
    printf("\n%s",unEmpleado.nombre);
    printf("\t%s",unEmpleado.apellido);
    printf("\t\t%d",unEmpleado.edad);
    printf("\t%.2f",unEmpleado.salario);
    printf("\t%d\n",unEmpleado.id);
}
void mostrarSoloUnoConSuLocalidad(eEmpleado unEmpleado,eLocalidad listaLocalidades[],int indiceLocalidad)
{
    printf("\n%s\t",unEmpleado.nombre);
    printf("%4s\t",unEmpleado.apellido);
    printf("%7d\t",unEmpleado.edad);
    printf("%9.2f\t",unEmpleado.salario);
    printf("%d\t",unEmpleado.id);
    printf("%s\n",listaLocalidades[indiceLocalidad].nombreLocalidad);
}
void mostrarArrayConSusLocalidades(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad)
{
    int i;
    int j;
    int indiceLibre;
    indiceLibre=buscarSoloUnEstado(listaEmpleados,tamEmpleado,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        printf("\nNOMBRE    APELLIDO   EDAD   SUELDO\tID\tLOCALIDAD\n");
        ordenarArray(listaEmpleados,tamEmpleado,1);
        for(i=0;i<tamEmpleado;i++)
        {
            for(j=0;j<tamLocalidad;j++)
            {
                if((listaEmpleados[i].estado==OCUPADO) && (listaLocalidades[j].id==listaEmpleados[i].idLocalidad))
                {
                    mostrarSoloUnoConSuLocalidad(listaEmpleados[i],listaLocalidades,j);
                }
            }
        }
    }
}
void mostrarCadaLocalidadConSusEmpleados(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad)
{
    int i;
    int j;
    int indiceLibre;
    indiceLibre=buscarSoloUnEstado(listaEmpleados,tamEmpleado,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nNo hay ningun empleado por mostrar\n");
    }
    else
    {
        for(i=0;i<tamLocalidad;i++)
        {
            printf("\nLocalidad: %s\n",listaLocalidades[i].nombreLocalidad);
            for(j=0;j<tamEmpleado;j++)
            {
                if((listaEmpleados[j].estado==OCUPADO) && (listaEmpleados[j].idLocalidad==listaLocalidades[i].id))
                {
                    printf("\nNOMBRE\tAPELLIDO\tEDAD\tSUELDO\tID\n");
                    mostrarSoloUno(listaEmpleados[j]);
                }
            }
        }
    }
}
void mostrarSoloEmpleadosDeAvellaneda(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad)
{
    int i;
    int j;
    int indiceLibre;
    indiceLibre=buscarSoloUnEstado(listaEmpleados,tamEmpleado,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nNo hay ningun empleado que mostrar\n");
    }
    else
    {
        printf("\nEmpleados en avellaneda:\n");
        printf("\nNOMBRE\tAPELLIDO\tEDAD\tSUELDO\tID\n");
        for(i=0;i<tamLocalidad;i++)
        {
            for(j=0;j<tamEmpleado;j++)
            {
                if((listaEmpleados[j].estado==OCUPADO) && (listaEmpleados[j].idLocalidad==listaLocalidades[i].id) && (listaLocalidades[i].id==100))
                {
                    mostrarSoloUno(listaEmpleados[j]);
                }
            }
        }
    }
}
void contarPorCant(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[])
{
    int i;
    int j;
    for(i=0;i<tamLocalidad;i++)
    {
        auxLocalidad[i].idLocalidad=listaLocalidades[i].id;
        auxLocalidad[i].contadores=0;
    }
    for(i=0;i<tamLocalidad;i++)
    {
        for(j=0;j<tamEmpleado;j++)
        {
            if((listaEmpleados[j].estado==OCUPADO) && (auxLocalidad[i].idLocalidad==listaEmpleados[j].idLocalidad))
            {
                auxLocalidad[i].contadores++;
            }
        }
    }
}
int dameElMinimo(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[])
{
    int elMinimo;
    int flagPrimerDato=1;
    int i;
    contarPorCant(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad,auxLocalidad);
    for(i=0;i<tamLocalidad;i++)
    {
        if((flagPrimerDato==1) || (auxLocalidad[i].contadores < elMinimo))
        {
            elMinimo=auxLocalidad[i].contadores;
            flagPrimerDato=0;
        }
    }
    return elMinimo;
}
void mostrarLocalidadConMenosEmpleados(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[])
{
    int i;
    int j;
    int elMinimo;
    contarPorCant(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad,auxLocalidad);
    elMinimo=dameElMinimo(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad,auxLocalidad);
    for(i=0;i<tamLocalidad;i++)
    {
        for(j=0;j<tamLocalidad;j++)
        {
            if((listaLocalidades[i].id==auxLocalidad[j].idLocalidad) && (auxLocalidad[j].contadores==elMinimo))
            {
                printf("\nLocalidad con menos empleados: %s\n",listaLocalidades[i].nombreLocalidad);
            }
        }
    }
}
int dameElMaximo(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[])
{
    int elMaximo;
    int flagPrimerDato=1;
    int i;
    contarPorCant(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad,auxLocalidad);
    for(i=0;i<tamLocalidad;i++)
    {
        if((flagPrimerDato==1) || (auxLocalidad[i].contadores > elMaximo))
        {
            elMaximo=auxLocalidad[i].contadores;
            flagPrimerDato=0;
        }
    }
    return elMaximo;
}
void mostrarLocalidadConMasEmpleados(eEmpleado listaEmpleados[],int tamEmpleado,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxLocalidad[])
{
    int i;
    int j;
    int elMaximo;
    contarPorCant(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad,auxLocalidad);
    elMaximo=dameElMaximo(listaEmpleados,tamEmpleado,listaLocalidades,tamLocalidad,auxLocalidad);
    for(i=0;i<tamLocalidad;i++)
    {
        for(j=0;j<tamLocalidad;j++)
        {
            if((listaLocalidades[i].id==auxLocalidad[j].idLocalidad) && (auxLocalidad[j].contadores==elMaximo))
            {
                printf("\nLocalidad con mas empleados: %s\n",listaLocalidades[i].nombreLocalidad);
            }
        }
    }
}
