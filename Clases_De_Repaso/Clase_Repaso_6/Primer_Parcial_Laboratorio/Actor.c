#include "Actor.h"

void menuGestionarActores(eActor listaActores[],int tamActor,int* contAltas)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        opcionMenu=getInt("1-ALTA ACTORES\n2-MODIFICAR ACTORES\n3-BAJA ACTORES\n4-LISTAR ACTORES\n5-SALIR DEL SUBMENU\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                darDeAlta(listaActores,tamActor,contAltas);
                system("pause");
                break;
            case 2:
                modificarActor(listaActores,tamActor);
                system("pause");
                break;
            case 3:
                darDeBaja(listaActores,tamActor);
                system("pause");
                break;
            case 4:
                ordenarListadoDeActores(listaActores,tamActor);
                mostrarListadoDeActores(listaActores,tamActor);
                system("pause");
                break;
            case 5:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\a\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');

}

void inicializarActores(eActor listaActores[],int tamActor)
{
    int i;
    for(i=0;i<tamActor;i++)
    {
        strcpy(listaActores[i].nombre,"VACIO");
        strcpy(listaActores[i].apellido,"VACIO");
        listaActores[i].codigo=-1;
        strcpy(listaActores[i].sexo,"VACIO");
        listaActores[i].estado=LIBRE;
    }
}
void harcodearActores(eActor listaActores[],int tamActor)
{
    char nombre[3][51]={"Ben","Abrahm","Irene"};
    char apellido[3][51]={"Patric","Salgado","Beltran"};
    char sexo[3][51]={"Masculino","Masculino","Femenino"};
    int codigo[3]={1,2,3};
    int i;
    for(i=0;i<tamActor;i++)
    {
        strcpy(listaActores[i].nombre,nombre[i]);
        strcpy(listaActores[i].apellido,apellido[i]);
        strcpy(listaActores[i].sexo,sexo[i]);
        listaActores[i].codigo=codigo[i];
        listaActores[i].estado=OCUPADO;
    }
}
int buscarSoloUnEstado(eActor listaActores[],int tamActor,int estadoDelLugar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamActor;i++)
    {
        if(listaActores[i].estado==estadoDelLugar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void darDeAlta(eActor listaActores[],int tamActor,int* contDeAltas)
{
    int sePudo;
    int indiceLibre;
    int auxCodigoInt;
    indiceLibre=buscarSoloUnEstado(listaActores,tamActor,LIBRE);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxCodigoInt=*contDeAltas;
        sePudo=pedirDatosSecuenciales(listaActores,tamActor,indiceLibre);
        if(sePudo==-1)
        {
            printf("\nAlta del actor cancelada\n");
        }
        else if(sePudo==0)
        {
            printf("\nAlta del actor cancelada por el usuario\n");
        }
        else
        {
            listaActores[indiceLibre].codigo=auxCodigoInt;
            listaActores[indiceLibre].estado=OCUPADO;
            *contDeAltas=auxCodigoInt+1;
            printf("\nSe ha dado de alta el codigo numero %d\n",auxCodigoInt);
        }
    }
}

int pedirDatosSecuenciales(eActor listaActores[],int tamActor,int indice)
{
    int confirmacionSexoActor;
    int confirmacion;
    int retorno=-1;
    eActor auxDatos;
    int ingresoSecuencialValido=1;

    if(ingresoSecuencialValido==1)
    {
        if(!getStrLetras("\nIngrese el nombre del actor/a: ",auxDatos.nombre,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 13\a\n",1,13,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrLetras("\nIngrese el apellido del actor/a: ",auxDatos.apellido,"\nSolo se permiten letras\a\n","\nRango valido entre 1 y 13\a\n",1,13,3))
        {
            ingresoSecuencialValido=0;
        }
        if(ingresoSecuencialValido==1)
        {
            confirmacionSexoActor=validarSoloSexo("\nIngrese el sexo del actor/a ('f' o 'm'): ","\nSolo confirme con ('f' o con 'm'): ");
            if(confirmacionSexoActor==1)
            {
                strcpy(auxDatos.sexo,"Femenino");
            }
            else if(confirmacionSexoActor==0)
            {
                strcpy(auxDatos.sexo,"Masculino");
            }
        }
    }
    if(ingresoSecuencialValido==1)
    {
        confirmacion=confirmarCambios("Esta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
        if(confirmacion==1)
        {
            listaActores[indice]=auxDatos;
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

void pedirDatosAEleccion(eActor listaActores[],int tamActor,int indice)
{
    int confirmacionSexoActor;
    eActor auxDatos;
    int opcionMenu;
    char continuarMenu='s';
    int confirmacion;



    auxDatos=listaActores[indice];
    do
    {
        system("cls");

        printf("NOMBRE\tAPELLIDO\tSEXO\tCODIGO\n");
        printf("\nDatos actuales seleccionados:\n");
        mostrarSoloUnActor(listaActores[indice]);

        printf("\nDatos a modificar:\n");
        mostrarSoloUnActor(auxDatos);


        opcionMenu=getInt("\nQue dato desea modificar?\n1-NOMBRE\n2-APELLIDO\n3-SEXO\n4-CONFIRMAR CAMBIOS\n5-FINALIZAR MODIFICACION\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre a modificar: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 1 y 13\n",1,13,3))
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
                if(getStrLetras("\nIngrese el apellido a modificar: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 1 y 13\n",1,13,3))
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
                confirmacionSexoActor=validarSoloSexo("\nIngrese el sexo a modificar ('f' o 'm'): ","\nSolo confirme con ('f' o con 'm'): ");
                if(confirmacionSexoActor==1)
                {
                    strcpy(auxDatos.sexo,"Femenino");
                }
                else if(confirmacionSexoActor==0)
                {
                    strcpy(auxDatos.sexo,"Masculino");
                }
                break;
            case 4:
                confirmacion=confirmarCambios("\nEsta seguro que desea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    listaActores[indice]=auxDatos;
                    printf("\nSe han confirmado los cambios realizados\n");
                    system("pause");
                }
                else if(confirmacion==0)
                {
                    printf("\nNo se han confirmado los cambios realizados\n");
                    system("pause");
                }
                break;
            case 5:
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
void modificarActor(eActor listaActores[],int tamActor)
{
    char auxCodigoStr[256];
    int auxCodigoInt;

    int indiceLibre;
    int indiceResultadoBusqueda;
    indiceLibre=buscarSoloUnEstado(listaActores,tamActor,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        mostrarListadoDeActores(listaActores,tamActor);
        if(getStrSoloNumeroSinRango("\nIngrese el codigo a modificar: ",auxCodigoStr,"\nSolo se permiten numeros\a\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceResultadoBusqueda=buscarActorPorCodigo(listaActores,tamActor,auxCodigoInt,OCUPADO);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl codigo ingresado no existe\n");
            }
            else
            {
                pedirDatosAEleccion(listaActores,tamActor,indiceResultadoBusqueda);
            }
        }
    }
}
void mostrarListadoDeActores(eActor listaActores[],int tamActor)
{
    int indiceLibre;
    int i;
    indiceLibre=buscarSoloUnEstado(listaActores,tamActor,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        //printf("\nNOMBRE\tAPELLIDO\tSEXO\tCODIGO\n");
        for(i=0;i<tamActor;i++)
        {
            if(listaActores[i].estado==OCUPADO)
            {
                //mostrarSoloUnActor(listaActores[i]);
                mostrarSoloUnActorTest(listaActores[i]);
            }
        }
    }
}
void mostrarSoloUnActor(eActor unActor)
{
    printf("\n%s",unActor.nombre);
    printf("\t%s",unActor.apellido);
    printf("\t\t%s",unActor.sexo);
    printf("\t%d\n",unActor.codigo);
}
void mostrarSoloUnActorTest(eActor unActor)
{
    printf("\nNombre: %s",unActor.nombre);
    printf("\tApellido: %s",unActor.apellido);
    printf("\tSexo: %s",unActor.sexo);
    printf("\tCodigo: %d\n",unActor.codigo);
}
int buscarActorPorCodigo(eActor listaActores[],int tamActor,int valorABuscar,int estadoDelLugar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamActor;i++)
    {
        if((listaActores[i].estado==estadoDelLugar) && (listaActores[i].codigo==valorABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void darDeBaja(eActor listaActores[],int tamActor)
{
    int confirmacion;
    int auxCodigoInt;
    char auxCodigoStr[256];
    int indiceLibre;
    int indiceResultadoBusqueda;
    indiceLibre=buscarSoloUnEstado(listaActores,tamActor,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        mostrarListadoDeActores(listaActores,tamActor);
        if(getStrSoloNumeroSinRango("\nIngrese el codigo a dar de baja: ",auxCodigoStr,"\nSolo se permiten numeros\a\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceResultadoBusqueda=buscarActorPorCodigo(listaActores,tamActor,auxCodigoInt,OCUPADO);
            if(indiceResultadoBusqueda == -1)
            {
                printf("\nNo existe el codigo ingresado\n");
            }
            else
            {
                confirmacion=confirmarCambios("Esta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    listaActores[indiceResultadoBusqueda].estado=LIBRE;
                    printf("\nSe ha dado de baja al codigo numero %d\n",auxCodigoInt);
                }
                else if(confirmacion==0)
                {
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
    }
}
void ordenarListadoDeActores(eActor listadoActores[],int tamActor)
{
    int i;
    int j;
    eActor auxiliar;
    for(i=0;i<tamActor-1;i++)
    {
        for(j=i+1;j<tamActor;j++)
        {
            if(strcmp(listadoActores[i].apellido,listadoActores[j].apellido)==1)
            {
                auxiliar=listadoActores[i];
                listadoActores[i]=listadoActores[j];
                listadoActores[j]=auxiliar;
            }
            else if(strcmp(listadoActores[i].apellido,listadoActores[j].apellido)==0)
            if(strcmp(listadoActores[i].nombre,listadoActores[j].nombre)==1)
            {
                auxiliar=listadoActores[i];
                listadoActores[i]=listadoActores[j];
                listadoActores[j]=auxiliar;
            }
        }
    }
}
