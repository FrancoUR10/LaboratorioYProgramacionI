#include "ABM.h"

void empleado_inicializarDatos(eEmpleado listaEmpleado[],int tamEmpleado)
{
    int i;
    for(i=0;i<tamEmpleado;i++)
    {
        listaEmpleado[i].id=-1;
        strcpy(listaEmpleado[i].nombre,"VACIO");
        strcpy(listaEmpleado[i].apellido,"VACIO");
        strcpy(listaEmpleado[i].genero,"VACIO");
        listaEmpleado[i].edad=-1;
        listaEmpleado[i].sueldo=-1;
        listaEmpleado[i].idLocalidad=-1;
        listaEmpleado[i].estado=LIBRE;
    }
}
void empleado_harcodearDatos(eEmpleado listaEmpleado[])
{
    int id[5]={1,2,3,4,5};
    char nombre[5][51]={"Carlos","Irene","Juan","Maria","Marcos"};;
    char apellido[5][51]={"Salgado","Beltran","Cruz","Josefina","Perez"};;
    char genero[5][51]={"Masculino","Femenino","Masculino","Femenino","Masculino"};;
    int edad[5]={18,45,25,50,65};;
    float sueldo[5]={1000,5000,5648,8487,10000};;
    int idLocalidad[5]={200,300,500,100,400};;
    int i;
    for(i=0;i<5;i++)
    {
        listaEmpleado[i].id=id[i];
        strcpy(listaEmpleado[i].nombre,nombre[i]);
        strcpy(listaEmpleado[i].apellido,apellido[i]);
        strcpy(listaEmpleado[i].genero,genero[i]);
        listaEmpleado[i].edad=edad[i];
        listaEmpleado[i].sueldo=sueldo[i];
        listaEmpleado[i].idLocalidad=idLocalidad[i];
        listaEmpleado[i].estado=OCUPADO;
    }
}
void empleado_mostrarUnoSolo(eEmpleado unEmpleado,eLocalidad unaLocalidad[],int indiceLocalidad)
{
    printf("\n%d\t",unEmpleado.id);
    printf("%8s",unEmpleado.nombre);
    printf("%12s",unEmpleado.apellido);
    printf("%14s",unEmpleado.genero);
    printf("%9d",unEmpleado.edad);
    printf("%10.2f",unEmpleado.sueldo);
    printf("%14s\n",unaLocalidad[indiceLocalidad].descripcion);
}
void empleado_mostrarLista(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad)
{
    int indiceBusqueda;
    int i;
    if(empleado_buscarPorEstado(listaEmpleado,tamEmpleado,OCUPADO)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        empleado_ordenarDatos(listaEmpleado,tamEmpleado);
        printf("\nID        NOMBRE      APELLIDO     GENERO      EDAD    SUELDO     LOCALIDAD\n");
        for(i=0;i<tamEmpleado;i++)
        {
            indiceBusqueda=localidad_buscarPorId(listaLocalidad,tamLocalidad,listaEmpleado[i].idLocalidad);
            if((listaEmpleado[i].estado==OCUPADO) && (listaEmpleado[i].idLocalidad==listaLocalidad[indiceBusqueda].id))
            {
                empleado_mostrarUnoSolo(listaEmpleado[i],listaLocalidad,indiceBusqueda);
            }
        }
    }
}
int empleado_buscarPorEstado(eEmpleado listaEmpleado[],int tamEmpleado,int estadoABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamEmpleado;i++)
    {
        if(listaEmpleado[i].estado==estadoABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int empleado_buscarPorId(eEmpleado listaEmpleado[],int tamEmpleado,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamEmpleado;i++)
    {
        if((listaEmpleado[i].estado==OCUPADO) && (listaEmpleado[i].id==idABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int empleado_darDeAlta(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad,int* contAltas)
{
    int confirmacion;
    int sePudo=-1;
    int indiceLibre;
    int ingresoSecuencialValido=1;
    int auxIdInt=*contAltas;
    char auxEdadStr[256];
    char auxSueldoStr[256];
    char auxIdLocalidadStr[256];
    eEmpleado auxDatos;
    indiceLibre=empleado_buscarPorEstado(listaEmpleado,tamEmpleado,LIBRE);
    if(indiceLibre==-1)
    {
        printf("\nNo hay lugar libre en la lista\n");
    }
    else
    {
        if(!getStrLetras("\nIngrese el nombre: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrLetras("\nIngrese el apellido: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
        {
            ingresoSecuencialValido=0;
        }
        if(ingresoSecuencialValido==1)
        {
            confirmacion=validarGenero("\nIngrese el genero (m/f): ","\nSolo confirme el genero con ('m' o con 'f'): ");
            if(confirmacion==1)
            {
                strcpy(auxDatos.genero,"Masculino");
            }
            else if(confirmacion==0)
            {
                strcpy(auxDatos.genero,"Femenino");
            }
            if(!getStrNumeros("\nIngrese la edad: ",auxEdadStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 18 y el 65\n",18,65,3))
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
            localidad_mostrarLista(listaLocalidad,tamLocalidad);
            if(getStrNumerosSinRango("\nIngrese el id de una localidad: ",auxIdLocalidadStr,"\nSolo se permiten numeros\n",3))
            {
                if(localidad_buscarPorId(listaLocalidad,tamLocalidad,atoi(auxIdLocalidadStr))==-1)
                {
                    printf("\nEl id ingresado no existe\n");
                    ingresoSecuencialValido=0;
                }
                else
                {
                    auxDatos.idLocalidad=atoi(auxIdLocalidadStr);
                }
            }
        }
        if(ingresoSecuencialValido==1)
        {
            auxDatos.edad=atoi(auxEdadStr);
            auxDatos.sueldo=atof(auxSueldoStr);
            confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
            if(confirmacion==1)
            {
                auxDatos.id=auxIdInt;
                auxDatos.estado=OCUPADO;
                listaEmpleado[indiceLibre]=auxDatos;
                *contAltas=auxIdInt+1;
                printf("\nSe ha dado de alta al id numero %d\n",auxIdInt);
                sePudo=1;
            }
            else if(confirmacion==0)
            {
                printf("\nAlta cancelada por el usuario\n");
                sePudo=0;
            }
        }
    }
    if(sePudo==-1)
    {
        printf("\nAlta cancelada\n");
    }
    return sePudo;
}
int empleado_darDeBaja(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad)
{
    int sePudo=-1;
    int confirmacion;
    int indiceBusqueda;
    char auxIdStr[256];
    int auxIdInt;
    if(empleado_buscarPorEstado(listaEmpleado,tamEmpleado,OCUPADO)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        empleado_mostrarLista(listaEmpleado,tamEmpleado,listaLocalidad,tamLocalidad);
        if(getStrNumerosSinRango("\nIngrese el id a dar de baja: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            auxIdInt=atoi(auxIdStr);
            indiceBusqueda=empleado_buscarPorId(listaEmpleado,tamEmpleado,auxIdInt);
            if(indiceBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    listaEmpleado[indiceBusqueda].estado=LIBRE;
                    printf("\nSe ha dado de baja al id numero %d\n",auxIdInt);
                    sePudo=1;
                }
                else if(confirmacion==0)
                {
                    printf("\nBaja cancelada por el usuario\n");
                    sePudo=0;
                }
            }
        }
        if(sePudo==-1)
        {
            printf("\nBaja cancelada\n");
        }
    }
    return sePudo;
}
int empleado_modificarDatos(eEmpleado listaEmpleado[],int tamEmpleado,eLocalidad listaLocalidad[],int tamLocalidad)
{
    int sePudo=0;
    int indiceBusqueda;
    char auxIdStr[256];
    int auxIdInt;
    if(empleado_buscarPorEstado(listaEmpleado,tamEmpleado,OCUPADO)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        empleado_mostrarLista(listaEmpleado,tamEmpleado,listaLocalidad,tamLocalidad);
        if(getStrNumerosSinRango("\nIngrese el id a modificar: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            auxIdInt=atoi(auxIdStr);
            indiceBusqueda=empleado_buscarPorId(listaEmpleado,tamEmpleado,auxIdInt);
            if(indiceBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                empleado_pedirDatosAModificar(listaEmpleado,listaLocalidad,tamLocalidad,indiceBusqueda);
                sePudo=1;
            }
        }
    }
    if(sePudo==0)
    {
        printf("\nModificacion cancelada\n");
    }
    return sePudo;
}
void empleado_pedirDatosAModificar(eEmpleado listaEmpleado[],eLocalidad listaLocalidad[],int tamLocalidad,int indice)
{
    int indiceBusqueda;
    int confirmacion;
    int flagPrimerCambio=0;
    int opcionMenu;
    char continuarMenu='s';
    char auxEdadStr[256];
    char auxSueldoStr[256];
    char auxIdLocalidadStr[256];
    eEmpleado proximosDatos;
    eEmpleado auxDatos;
    proximosDatos=listaEmpleado[indice];
    do
    {
        system("cls");
        printf("\nID        NOMBRE      APELLIDO     GENERO      EDAD    SUELDO     LOCALIDAD\n");

        printf("\nDatos actuales seleccionados:\n");
        indiceBusqueda=localidad_buscarPorId(listaLocalidad,tamLocalidad,listaEmpleado[indice].idLocalidad);
        empleado_mostrarUnoSolo(listaEmpleado[indice],listaLocalidad,indiceBusqueda);
        printf("\nDatos a modificar:\n");
        indiceBusqueda=localidad_buscarPorId(listaLocalidad,tamLocalidad,proximosDatos.idLocalidad);
        empleado_mostrarUnoSolo(proximosDatos,listaLocalidad,indiceBusqueda);

        printf("\nQue datos le gustaria modificar?\n");
        printf("1-NOMBRE\n");
        printf("2-APELLIDO\n");
        printf("3-GENERO\n");
        printf("4-EDAD\n");
        printf("5-SUELDO\n");
        printf("6-LOCALIDAD\n");
        printf("7-CONFIRMAR CAMBIOS\n");
        printf("8-FINALIZAR MODIFICACION\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
                {
                    strcpy(proximosDatos.nombre,auxDatos.nombre);
                    printf("\nSe ha ingresado el nombre\n");
                    flagPrimerCambio=1;
                }
                system("pause");
                break;
            case 2:
                if(getStrLetras("\nIngrese el apellido: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
                {
                    strcpy(proximosDatos.apellido,auxDatos.apellido);
                    printf("\nSe ha ingresado el apellido\n");
                    flagPrimerCambio=1;
                }
                system("pause");
                break;
            case 3:
                confirmacion=validarGenero("\nIngrese el genero (m/f): ","\nSolo ingrese el genero con ('m' o con 'f'): ");
                if(confirmacion==1)
                {
                    strcpy(proximosDatos.genero,"Masculino");
                }
                else if(confirmacion==0)
                {
                    strcpy(proximosDatos.genero,"Femenino");
                }
                printf("\nSe ha ingresado el genero\n");
                flagPrimerCambio=1;
                system("pause");
                break;
            case 4:
                if(getStrNumeros("\nIngrese la edad: ",auxEdadStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 18 y el 65\n",18,65,3))
                {
                    proximosDatos.edad=atoi(auxEdadStr);
                    printf("\nSe ha ingresado la edad\n");
                    flagPrimerCambio=1;
                }
                system("pause");
                break;
            case 5:
                if(getStrNumerosFlotantes("\nIngrese el sueldo: ",auxSueldoStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre el 1000 y el 10000\n",1000,10000,3))
                {
                    proximosDatos.sueldo=atof(auxSueldoStr);
                    printf("\nSe ha ingresado el sueldo\n");
                    flagPrimerCambio=1;
                }
                system("pause");
                break;
            case 6:
                localidad_mostrarLista(listaLocalidad,tamLocalidad);
                if(getStrNumerosSinRango("\nIngrese el id de una localidad: ",auxIdLocalidadStr,"\nSolo se permiten numeros\n",3))
                {
                    if(localidad_buscarPorId(listaLocalidad,tamLocalidad,atoi(auxIdLocalidadStr))==-1)
                    {
                        printf("\nEl id ingresado no existe\n");
                    }
                    else
                    {
                        proximosDatos.idLocalidad=atoi(auxIdLocalidadStr);
                        printf("\nSe ha ingresado la localidad\n");
                        flagPrimerCambio=1;
                    }
                }
                system("pause");
                break;
            case 7:
                if(flagPrimerCambio==1)
                {
                    confirmacion=confirmarCambios("\nDesea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        listaEmpleado[indice]=proximosDatos;
                        printf("\nSe han confirmado los cambios realizados\n");
                        flagPrimerCambio=0;
                        system("pause");
                    }
                }
                else
                {
                    printf("\nNo se han realizado nuevos cambios que confirmar\n");
                    system("pause");
                }
                break;
            case 8:
                if(flagPrimerCambio==0)
                {
                    confirmacion=1;
                }
                else
                {
                    confirmacion=confirmarCambios("\nEsta seguro que desea salir sin confirmar cambios? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                }
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
void empleado_ordenarDatos(eEmpleado listaEmpleado[],int tamEmpleado)
{
    int i;
    int j;
    eEmpleado auxDatos;
    for(i=0;i<tamEmpleado-1;i++)
    {
        for(j=i+1;j<tamEmpleado;j++)
        {
            if(strcmp(listaEmpleado[i].apellido,listaEmpleado[j].apellido)==1)
            {
                auxDatos=listaEmpleado[i];
                listaEmpleado[i]=listaEmpleado[j];
                listaEmpleado[j]=auxDatos;
            }
            else if(strcmp(listaEmpleado[i].apellido,listaEmpleado[j].apellido)==0)
            {
                if(strcmp(listaEmpleado[i].nombre,listaEmpleado[j].nombre)==1)
                {
                    auxDatos=listaEmpleado[i];
                    listaEmpleado[i]=listaEmpleado[j];
                    listaEmpleado[j]=auxDatos;
                }
            }
        }
    }
}
