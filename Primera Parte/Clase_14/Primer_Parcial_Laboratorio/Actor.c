#include "Actor.h"

void menuGestionarActores(eActor listaActores[],int tamActor,int* contAltas,ePais listaPaises[],int tamPais)
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
                darDeAlta(listaActores,tamActor,contAltas,listaPaises,tamPais);
                system("pause");
                break;
            case 2:
                modificarActor(listaActores,tamActor,listaPaises,tamPais);
                system("pause");
                break;
            case 3:
                darDeBaja(listaActores,tamActor,listaPaises,tamPais);
                system("pause");
                break;
            case 4:
                ordenarListadoDeActores(listaActores,tamActor);
                mostrarListadoDeActores(listaActores,tamActor,listaPaises,tamPais);
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
    int idNacionalidad[3]={1,2,3};
    int i;
    for(i=0;i<tamActor;i++)
    {
        strcpy(listaActores[i].nombre,nombre[i]);
        strcpy(listaActores[i].apellido,apellido[i]);
        strcpy(listaActores[i].sexo,sexo[i]);
        listaActores[i].codigo=codigo[i];
        listaActores[i].idNacionalidad=idNacionalidad[i];
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

void darDeAlta(eActor listaActores[],int tamActor,int* contDeAltas,ePais listaPais[],int tamPais)
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
        sePudo=pedirDatosSecuenciales(listaActores,tamActor,indiceLibre,listaPais,tamPais);
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

int pedirDatosSecuenciales(eActor listaActores[],int tamActor,int indice,ePais listaPais[],int tamPais)
{
    int confirmacionSexoActor;
    int confirmacion;
    int retorno=-1;
    eActor auxDatos;
    char auxIdNacionalidadStr[256];
    int indicePaisEncontrado;
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
        if(ingresoSecuencialValido==1)
        {
            printf("Paises disponibles:\n");
            mostrarListadoDePaises(listaPais,tamPais);
            if(getStrSoloNumeroSinRango("\nIngrese el id de un pais: ",auxIdNacionalidadStr,"\nSolo se permiten numeros\n",3))
            {
                auxDatos.idNacionalidad=atoi(auxIdNacionalidadStr);
                indicePaisEncontrado=buscarPaisPorId(listaPais,tamPais,auxDatos.idNacionalidad);
                if(indicePaisEncontrado==-1)
                {
                    printf("\nEl id del pais ingresado no existe\n");
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

void pedirDatosAEleccion(eActor listaActores[],int tamActor,int indice,ePais listaPais[],int tamPais)
{
    int flagPrimerCambio=1;
    int confirmacionSexoActor;
    eActor auxDatos;
    int indicePaisEncontrado;
    int indicePaisAux;
    char auxIdNacionalidadStr[256];
    int auxIdNacionalidadInt;
    int opcionMenu;
    char continuarMenu='s';
    int confirmacion;



    auxDatos=listaActores[indice];
    do
    {
        system("cls");

        printf("\nNOMBRE    APELLIDO      SEXO           NACIONALIDAD        CODIGO\n");
        printf("\nDatos actuales seleccionados:\n");
        indicePaisEncontrado=buscarPaisPorId(listaPais,tamPais,listaActores[indice].idNacionalidad);
        mostrarSoloUnActor(listaActores[indice],listaPais,indicePaisEncontrado);

        printf("\nDatos a modificar:\n");
        indicePaisAux=buscarPaisPorId(listaPais,tamPais,auxDatos.idNacionalidad);
        mostrarSoloUnActor(auxDatos,listaPais,indicePaisAux);


        opcionMenu=getInt("\nQue dato desea modificar?\n1-NOMBRE\n2-APELLIDO\n3-SEXO\n4-PAIS\n5-CONFIRMAR CAMBIOS\n6-FINALIZAR MODIFICACION\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre a modificar: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 1 y 13\n",1,13,3))
                {
                    printf("\nSe ha modificado el nombre\n");
                    flagPrimerCambio=0;
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
                    flagPrimerCambio=0;
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
                printf("\nSe ha modificado el genero\n");
                flagPrimerCambio=0;
                system("pause");
                break;
            case 4:
                printf("\nPaises disponibles:\n");
                mostrarListadoDePaises(listaPais,tamPais);
                if(getStrSoloNumeroSinRango("\nIngrese el id del pais: ",auxIdNacionalidadStr,"\nSolo se permiten numeros\n",3))
                {
                    auxIdNacionalidadInt=atoi(auxIdNacionalidadStr);
                    indicePaisEncontrado=buscarPaisPorId(listaPais,tamPais,auxIdNacionalidadInt);
                    if(indicePaisEncontrado!=-1)
                    {
                        printf("\nSe ha modificado la nacionalidad\n");
                        auxDatos.idNacionalidad=auxIdNacionalidadInt;
                        flagPrimerCambio=0;
                    }
                    else
                    {
                        printf("\nLa nacionalidad a modificar no existe\n");
                    }
                }
                else
                {
                    printf("\nNo se pudo modificar la nacionalidad\n");
                }
                system("pause");
                break;
            case 5:
                if(flagPrimerCambio==0)
                {
                    confirmacion=confirmarCambios("\nEsta seguro que desea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        listaActores[indice]=auxDatos;
                        printf("\nSe han confirmado los cambios realizados\n");
                        flagPrimerCambio=1;
                    }
                    else if(confirmacion==0)
                    {
                        printf("\nNo se han confirmado los cambios realizados\n");
                    }
                }
                else
                {
                    printf("\nNo se han realizado nuevos cambios que confirmar\n");
                }
                system("pause");
                break;
            case 6:
                if(flagPrimerCambio==0)
                {
                    confirmacion=confirmarCambios("\nEsta seguro que desea salir del menu sin confirmar los cambios? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        printf("\nModificacion finalizada\n");
                        continuarMenu='n';
                    }
                }
                else
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
void modificarActor(eActor listaActores[],int tamActor,ePais listaPais[],int tamPais)
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
        mostrarListadoDeActores(listaActores,tamActor,listaPais,tamPais);
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
                pedirDatosAEleccion(listaActores,tamActor,indiceResultadoBusqueda,listaPais,tamPais);
            }
        }
    }
}
void mostrarListadoDeActores(eActor listaActores[],int tamActor,ePais listaPais[],int tamPais)
{
    int indiceLibre;
    int i;
    int j;
    indiceLibre=buscarSoloUnEstado(listaActores,tamActor,OCUPADO);
    if(indiceLibre==-1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        printf("\nNOMBRE    APELLIDO      SEXO           NACIONALIDAD        CODIGO\n");
        for(i=0;i<tamActor;i++)
        {
            for(j=0;j<tamPais;j++)
            {
                if((listaActores[i].estado==OCUPADO) && (listaActores[i].idNacionalidad==listaPais[j].id))
                {
                    mostrarSoloUnActor(listaActores[i],listaPais,j);
                }
            }
        }
    }
}
void mostrarSoloUnActor(eActor unActor,ePais listaPais[],int indicePais)
{
    printf("\n%s\t",unActor.nombre);
    printf("%10s\t",unActor.apellido);
    printf("%5s\t",unActor.sexo);
    printf("%8s\t",listaPais[indicePais].descripcion);
    printf("%6d\n",unActor.codigo);
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
void darDeBaja(eActor listaActores[],int tamActor,ePais listaPais[],int tamPais)
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
        mostrarListadoDeActores(listaActores,tamActor,listaPais,tamPais);
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
