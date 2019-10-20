#include "abm.h"

void inicializarEntidad(eEntidad listaEntidad[],int tamEntidad)
{
    int i;
    for(i=0;i<tamEntidad;i++)
    {
        strcpy(listaEntidad[i].nombre,"VACIO");
        strcpy(listaEntidad[i].apellido,"VACIO");
        strcpy(listaEntidad[i].genero,"VACIO");
        listaEntidad[i].salario=0;
        listaEntidad[i].sector=-1;
        listaEntidad[i].id=-1;
        listaEntidad[i].estado=LIBRE;
    }
}
void harcodearEntidad(eEntidad listaEntidad[],int tamEntidad)
{
    char nombre[3][51]={"Franco","Abrahm","Irene"};
    char apellido[3][51]={"Acquisto","Salgado","Beltran"};
    char genero[3][51]={"Masculino","Masculino","Femenino"};
    float salario[3]={300,400,500};
    int sector[3]={2,3,4};
    int id[3]={1,2,3};
    int i;
    for(i=0;i<tamEntidad;i++)
    {
        strcpy(listaEntidad[i].nombre,nombre[i]);
        strcpy(listaEntidad[i].apellido,apellido[i]);
        strcpy(listaEntidad[i].genero,genero[i]);
        listaEntidad[i].salario=salario[i];
        listaEntidad[i].sector=sector[i];
        listaEntidad[i].id=id[i];
        listaEntidad[i].estado=OCUPADO;

    }
}
void mostrarUnEntidad(eEntidad listaEntidad)
{
    printf("\n%15s",listaEntidad.nombre);
    printf("\t%10s",listaEntidad.apellido);
    printf("\t%10s",listaEntidad.genero);
    printf("\t%.2f",listaEntidad.salario);
    printf("\t%4d",listaEntidad.sector);
    printf("\t%8d\n",listaEntidad.id);
}
void mostrarListaEntidad(eEntidad listaEntidad[],int tamEntidad)
{
    int i;
    if(buscarUnEstado(listaEntidad,tamEntidad,OCUPADO)==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        printf("\n\tNOMBRE------APELLIDO------GENERO------SALARIO------SECTOR------ID\n");
        ordenarArray(listaEntidad,tamEntidad);
        for(i=0;i<tamEntidad;i++)
        {
            if(listaEntidad[i].estado==OCUPADO)
            {
                mostrarUnEntidad(listaEntidad[i]);
            }
        }
    }
}
void ordenarArray(eEntidad listaEntidad[],int tamEntidad)
{
    int i;
    int j;
    eEntidad auxDatos;
    for(i=0;i<tamEntidad-1;i++)
    {
        for(j=i+1;j<tamEntidad;j++)
        {
            if(strcmp(listaEntidad[i].apellido,listaEntidad[j].apellido)==1)
            {
                auxDatos=listaEntidad[i];
                listaEntidad[i]=listaEntidad[j];
                listaEntidad[j]=auxDatos;
            }
            else if(strcmp(listaEntidad[i].apellido,listaEntidad[j].apellido)==0)
            {
                if(strcmp(listaEntidad[i].nombre,listaEntidad[j].nombre)==1)
                {
                    auxDatos=listaEntidad[i];
                    listaEntidad[i]=listaEntidad[j];
                    listaEntidad[j]=auxDatos;
                }
            }
        }
    }
}
int buscarUnEstado(eEntidad listaEntidad[],int tamEntidad,int busquedaEstado)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamEntidad;i++)
    {
        if(listaEntidad[i].estado==busquedaEstado)
        {
            retorno=i;
        }
    }
    return retorno;
}
int buscarUnLugar(eEntidad listaEntidad[],int tamEntidad,int busquedaValor)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamEntidad;i++)
    {
        if((listaEntidad[i].estado==OCUPADO) && (listaEntidad[i].id==busquedaValor))
        {
            retorno=i;
        }
    }
    return retorno;
}

void darDeAlta(eEntidad listaEntidad[],int tamEntidad,int* contAltas)
{
    int sePudo;
    int auxIdInt;
    int indiceLibre;
    indiceLibre=buscarUnEstado(listaEntidad,tamEntidad,LIBRE);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxIdInt=*contAltas;
        sePudo=pedirDatosSecuenciales(listaEntidad,tamEntidad,indiceLibre);
        if(sePudo==1)
        {
            *contAltas=auxIdInt+1;
            listaEntidad[indiceLibre].id=auxIdInt;
            listaEntidad[indiceLibre].estado=OCUPADO;
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
int pedirDatosSecuenciales(eEntidad listaEntidad[],int tamEntidad,int indice)
{
    int sePudo=-1;
    char auxSalarioStr[256];
    char auxSectorStr[256];
    char confirmacionGenero;
    char confirmacion;
    eEntidad auxDatos;
    int ingresoSecuencialValido=1;
    if(ingresoSecuencialValido==1)
    {
        if(!getStrLetras("\nIngrese el nombre: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 1 y 12\n",1,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrLetras("\nIngrese el apellido: ",auxDatos.apellido,"\nSolo se permiten letras\n","Rango valido entre 1 y 12",1,12,3))
        {
            ingresoSecuencialValido=0;
        }
        if(ingresoSecuencialValido==1)
        {
            confirmacionGenero=validarGenero("\nIngrese el genero: ('m' o 'f'): ","\nSolo valide con ('m' o con 'f'): ");
            if(confirmacionGenero==1)
            {
                strcpy(auxDatos.genero,"Masculino");
            }
            else if(confirmacionGenero==0)
            {
                strcpy(auxDatos.genero,"Femenino");
            }
        }
        if(ingresoSecuencialValido==1)
        {
            if(!getStrNumerosFlotantes("\nIngrese el salario: ",auxSalarioStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre 1 y 999999\n",1,999999,3))
            {
                ingresoSecuencialValido=0;
            }
            else if(!getStrNumeros("\nIngrese el sector: ",auxSectorStr,"\nSolo se permiten numeros\n","\nNumero valido entre 1 y 999999\n",1,999999,3))
            {
                ingresoSecuencialValido=0;
            }
        }
    }
    if(ingresoSecuencialValido==1)
    {
        auxDatos.salario=atof(auxSalarioStr);
        auxDatos.sector=atoi(auxSectorStr);
        confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? ('s' o 'n'): ","\nSolo confirme con ('s' o con 'n'): ");
        if(confirmacion==1)
        {
            sePudo=1;
            listaEntidad[indice]=auxDatos;
        }
        else
        {
            sePudo=0;
        }
    }
    return sePudo;
}
void darDeBaja(eEntidad listaEntidad[],int tamEntidad)
{
    int confirmacion;
    int indiceResultadoBusqueda;
    char auxIdStr[256];
    eEntidad auxDatos;
    if(buscarUnEstado(listaEntidad,tamEntidad,OCUPADO)==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        mostrarListaEntidad(listaEntidad,tamEntidad);
        if(!getStrNumerosSinRango("\nIngrese el id a dar de baja: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            printf("\nBaja cancelada\n");
        }
        else
        {
            auxDatos.id=atoi(auxIdStr);
            indiceResultadoBusqueda=buscarUnLugar(listaEntidad,tamEntidad,auxDatos.id);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    printf("\nSe ha dado de baja al id %d\n",auxDatos.id);
                    listaEntidad[indiceResultadoBusqueda].estado=LIBRE;
                }
                else if(confirmacion==0)
                {
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
    }
}
void modificarDatos(eEntidad listaEntidad[],int tamEntidad)
{
    int indiceResultadoBusqueda;
    char auxIdStr[256];
    eEntidad auxDatos;
    if(buscarUnEstado(listaEntidad,tamEntidad,OCUPADO)==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        mostrarListaEntidad(listaEntidad,tamEntidad);
        if(!getStrNumerosSinRango("\nIngrese el id a modificar: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            printf("\nModificacion cancelada\n");
        }
        else
        {
            auxDatos.id=atoi(auxIdStr);
            indiceResultadoBusqueda=buscarUnLugar(listaEntidad,tamEntidad,auxDatos.id);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                pedirDatosAEleccion(listaEntidad,tamEntidad,indiceResultadoBusqueda);
            }
        }
    }
}
void pedirDatosAEleccion(eEntidad listaEntidad[],int tamEntidad,int indice)
{
    char confirmacionCambios;
    char auxSalarioStr[256];
    char auxSectorStr[256];
    int confirmacionGenero;
    eEntidad proximosDatos;
    eEntidad auxDatos;
    proximosDatos=listaEntidad[indice];
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("\n\tNOMBRE------APELLIDO------GENERO------SALARIO------SECTOR------ID\n");
        printf("\nDatos actuales seleccionados:\n");
        mostrarUnEntidad(listaEntidad[indice]);
        printf("\nDatos a modificar:\n");
        mostrarUnEntidad(proximosDatos);

        printf("\nQue dato desea modificar?:\n");
        printf("1-NOMBRE\n");
        printf("2-APELLIDO\n");
        printf("3-GENERO\n");
        printf("4-SALARIO\n");
        printf("5-SECTOR\n");
        printf("6-CONFIRMAR CAMBIOS\n");
        printf("7-FINALIZAR MODIFICACION\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre a modificar: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 1 y 12\n",1,12,3))
                {
                    strcpy(proximosDatos.nombre,auxDatos.nombre);
                    printf("\nSe ha ingresado correctamente el nombre\n");
                }
                system("pause");
                break;
            case 2:
                if(getStrLetras("\nIngrese el apellido a modificar: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 1 y 12\n",1,12,3))
                {
                    strcpy(proximosDatos.apellido,auxDatos.apellido);
                    printf("\nSe ha ingresado correctamente el apellido\n");
                }
                system("pause");
                break;
            case 3:
                confirmacionGenero=validarGenero("\nIngrese el genero a modificar ('m' o 'f'): ","\nSolo valide con ('m' o con 'f'): ");
                if(confirmacionGenero==1)
                {
                    strcpy(proximosDatos.genero,"Masculino");
                }
                else if(confirmacionGenero==0)
                {
                    strcpy(proximosDatos.genero,"Femenino");
                }
                system("pause");
                break;
            case 4:
                if(getStrNumerosFlotantes("\nIngrese el salario a modificar: ",auxSalarioStr,"\nSolo se permiten numeros y un solo punto\n","\nRango valido entre 1 y 999999\n",1,999999,3))
                {
                    proximosDatos.salario=atof(auxSalarioStr);
                }
                system("pause");
                break;
            case 5:
                if(getStrNumeros("\nIngrese el sector a modificar: ",auxSectorStr,"\nSolo se permiten numeros\n","\nRango valido entre 1 y 999999\n",1,999999,3))
                {
                    proximosDatos.sector=atoi(auxSectorStr);
                }
                system("pause");
                break;
            case 6:
                confirmacionCambios=confirmarCambios("\nDesea confirmar los cambios realizados? ('s' o 'n'): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacionCambios==1)
                {
                    listaEntidad[indice]=proximosDatos;
                    printf("\nSe han confirmado los cambios realizados\n");
                }
                system("pause");
                break;
            case 7:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
