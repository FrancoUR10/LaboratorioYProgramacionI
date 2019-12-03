#include "Actor.h"

void actor_gestionarActores(eActor listaActor[],int tamActor,ePais listaPais[],int tamPais,int* contAltas,eDireccion listaDireccion[],int tamDireccion)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("1-ALTA ACTORES\n");
        printf("2-MODIFICAR ACTORES\n");
        printf("3-BAJA ACTORES\n");
        printf("4-LISTAR ACTORES\n");
        printf("5-SALIR DEL SUB-MENU\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                actor_darDeAlta(listaActor,tamActor,listaPais,tamPais,contAltas,listaDireccion,tamDireccion);
                system("pause");
                break;
            case 2:
                actor_modificarDatos(listaActor,tamActor,listaPais,tamPais,listaDireccion,tamDireccion);
                system("pause");
                break;
            case 3:
                actor_darDeBaja(listaActor,tamActor,listaPais,tamPais,listaDireccion,tamDireccion);
                system("pause");
                break;
            case 4:
                actor_mostrarLista(listaActor,tamActor,listaPais,tamPais);
                system("pause");
                break;
            case 5:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
void actor_inicializarDatos(eActor listaactor[],int tamactor)
{
    int i;
    for(i=0;i<tamactor;i++)
    {
        listaactor[i].codigo=-1;
        strcpy(listaactor[i].nombre,"VACIO");
        strcpy(listaactor[i].apellido,"VACIO");
        strcpy(listaactor[i].sexo,"VACIO");
        listaactor[i].estado=LIBRE;
        listaactor[i].idNacionalidad=-1;
    }
}
void actor_harcodearDatos(eActor listaactor[])
{
    int codigo[5]={1,2,3,4,5};
    char nombre[5][51]={"Carlos","Irene","Juan","Maria","Marcos"};
    char apellido[5][51]={"Salgado","Beltran","Cruz","Josefina","Perez"};
    char sexo[5][51]={"Masculino","Femenino","Masculino","Femenino","Masculino"};
    int idNacionalidad[5]={1,2,3,4,5};
    char calle[5][51]={"Lautaro","Pasco","Tarija","Finki","Mitre"};
    int altura[5]={1000,2000,3000,4000,5000};
    char localidad[5][51]={"Temperley","Avellaneda","Wilde","Banfield","Lomas"};
    int cantPremios[5]={5,6,8,2,3};
    int dia[5]={6,2,3,20,3};
    int mes[5]={7,5,4,6,8};
    int anio[5]={1960,1980,1978,2000,1989};
    int i;
    for(i=0;i<5;i++)
    {
        listaactor[i].codigo=codigo[i];
        strcpy(listaactor[i].nombre,nombre[i]);
        strcpy(listaactor[i].apellido,apellido[i]);
        strcpy(listaactor[i].sexo,sexo[i]);
        listaactor[i].idNacionalidad=idNacionalidad[i];
        strcpy(listaactor[i].direccion.calle,calle[i]);
        listaactor[i].direccion.altura=altura[i];
        strcpy(listaactor[i].direccion.localidad,localidad[i]);
        listaactor[i].cantPremios=cantPremios[i];
        listaactor[i].fechaNacimiento.dia=dia[i];
        listaactor[i].fechaNacimiento.mes=mes[i];
        listaactor[i].fechaNacimiento.anio=anio[i];
        listaactor[i].estado=OCUPADO;
    }
}
void actor_mostrarUnoSolo(eActor unactor,ePais unPais[],int indicePais)
{
    printf("\n%d\t",unactor.codigo);
    printf("%10s",unactor.nombre);
    printf("%16s",unactor.apellido);
    printf("%17s",unactor.sexo);
    printf("%17s\n",unPais[indicePais].descripcion);
}
void actor_mostrarUnoSoloConNuevosCampos(eActor unactor,ePais unPais[],int indicePais)
{
    printf("\n%d\t",unactor.codigo);
    printf("%10s",unactor.nombre);
    printf("%16s",unactor.apellido);
    printf("%17s",unactor.sexo);
    printf("%14s",unPais[indicePais].descripcion);
    printf("%14s\n",unactor.direccion.localidad);
}
void actor_mostrarLista(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais)
{
    int indiceBusquedaPais;
    int i;
    if(actor_buscarPorEstado(listaactor,tamactor,OCUPADO)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        actor_ordenarDatos(listaactor,tamactor);
        printf("\nCODIGO      NOMBRE      APELLIDO          GENERO     NACIONALIDAD    LOCALIDAD\n");
        for(i=0;i<tamactor;i++)
        {
            indiceBusquedaPais=pais_buscarPorId(listaPais,tamPais,listaactor[i].idNacionalidad);
            if((listaactor[i].estado==OCUPADO))
            {
                actor_mostrarUnoSoloConNuevosCampos(listaactor[i],listaPais,indiceBusquedaPais);
            }
        }
    }
}
int actor_buscarPorEstado(eActor listaactor[],int tamactor,int estadoABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamactor;i++)
    {
        if(listaactor[i].estado==estadoABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int actor_buscarPorCodigo(eActor listaactor[],int tamactor,int codigoABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamactor;i++)
    {
        if((listaactor[i].estado==OCUPADO) && (listaactor[i].codigo==codigoABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int actor_darDeAlta(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais,int* contAltas,eDireccion listaDireccion[],int tamDireccion)
{
    int confirmacion;
    int sePudo=-1;
    int indiceLibre;
    int ingresoSecuencialValido=1;
    int auxCodigoInt=*contAltas;
    eActor auxDatos;
    char auxIdPaisStr[256];
    char auxCantPremiosStr[256];
    char auxAlturaDireccionStr[256];
    char auxDiaStr[256];
    char auxMesStr[256];
    char auxAnioStr[256];
    char auxCalleStr[256];
    char auxLocalidadStr[256];
    indiceLibre=actor_buscarPorEstado(listaactor,tamactor,LIBRE);
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
        else if(!getStrNumeros("\nIngrese la cantidad de premios: ",auxCantPremiosStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y 2000\n",1,2000,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese el dia de nacimiento: ",auxDiaStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y 31\n",1,31,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese el mes de nacimiento: ",auxMesStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y 12\n",1,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese el anio de nacimiento: ",auxAnioStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1900 y 2019\n",1900,2019,3))
        {
            ingresoSecuencialValido=0;
        }
        if(ingresoSecuencialValido==1)
        {
            confirmacion=validarGenero("\nIngrese el genero (m/f): ","\nSolo confirme el genero con ('m' o con 'f'): ");
            if(confirmacion==1)
            {
                strcpy(auxDatos.sexo,"Masculino");
            }
            else if(confirmacion==0)
            {
                strcpy(auxDatos.sexo,"Femenino");
            }
        }
        if(ingresoSecuencialValido==1)
        {
            pais_mostrarLista(listaPais,tamPais);
            if(getStrNumerosSinRango("\nIngrese el id de un pais: ",auxIdPaisStr,"\nSolo se permiten numeros\n",3))
            {
                if(pais_buscarPorId(listaPais,tamPais,atoi(auxIdPaisStr))==-1)
                {
                    printf("\nEl id ingresado no existe\n");
                    ingresoSecuencialValido=0;
                }
            }
            else
            {
                ingresoSecuencialValido=0;
            }
        }
        if(ingresoSecuencialValido==1)
        {
            if(!getStrNumeros("\nIngrese la altura de una direccion: ",auxAlturaDireccionStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1000 y el 10000\n",1000,10000,3))
            {
                ingresoSecuencialValido=0;
            }
            else if(!getStrLetras("\nIngrese la calle: ",auxCalleStr,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
            {
                ingresoSecuencialValido=0;
            }
            else if(!getStrLetras("\nIngrese la localidad: ",auxLocalidadStr,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
            {
                ingresoSecuencialValido=0;
            }
        }
        if(ingresoSecuencialValido==1)
        {
            confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
            if(confirmacion==1)
            {
                auxDatos.cantPremios=atoi(auxCantPremiosStr);
                auxDatos.fechaNacimiento.dia=atoi(auxDiaStr);
                auxDatos.fechaNacimiento.mes=atoi(auxMesStr);
                auxDatos.fechaNacimiento.anio=atoi(auxAnioStr);
                auxDatos.codigo=auxCodigoInt;
                auxDatos.estado=OCUPADO;
                listaactor[indiceLibre]=auxDatos;
                listaactor[indiceLibre].direccion.altura=atoi(auxAlturaDireccionStr);
                strcpy(listaactor[indiceLibre].direccion.calle,auxCalleStr);
                strcpy(listaactor[indiceLibre].direccion.localidad,auxLocalidadStr);
                listaactor[indiceLibre].idNacionalidad=atoi(auxIdPaisStr);
                *contAltas=auxCodigoInt+1;
                printf("\nSe ha dado de alta al codigo numero %d\n",auxCodigoInt);
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
int actor_darDeBaja(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais,eDireccion listaDireccion[],int tamDireccion)
{
    int sePudo=-1;
    int confirmacion;
    int indiceBusqueda;
    char auxCodigoStr[256];
    int auxCodigoInt;
    if(actor_buscarPorEstado(listaactor,tamactor,OCUPADO)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        actor_mostrarLista(listaactor,tamactor,listaPais,tamPais);
        if(getStrNumerosSinRango("\nIngrese el codigo a dar de baja: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceBusqueda=actor_buscarPorCodigo(listaactor,tamactor,auxCodigoInt);
            if(indiceBusqueda==-1)
            {
                printf("\nEl codigo ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    listaactor[indiceBusqueda].estado=LIBRE;
                    printf("\nSe ha dado de baja al codigo numero %d\n",auxCodigoInt);
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
int actor_modificarDatos(eActor listaactor[],int tamactor,ePais listaPais[],int tamPais,eDireccion listaDireccion[],int tamDireccion)
{
    int sePudo=0;
    int indiceBusqueda;
    char auxCodigoStr[256];
    int auxCodigoInt;
    if(actor_buscarPorEstado(listaactor,tamactor,OCUPADO)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        actor_mostrarLista(listaactor,tamactor,listaPais,tamPais);
        if(getStrNumerosSinRango("\nIngrese el codigo a modificar: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceBusqueda=actor_buscarPorCodigo(listaactor,tamactor,auxCodigoInt);
            if(indiceBusqueda==-1)
            {
                printf("\nEl codigo ingresado no existe\n");
            }
            else
            {
                actor_pedirDatosAModificar(listaactor,listaPais,tamPais,indiceBusqueda);
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
void actor_pedirDatosAModificar(eActor listaactor[],ePais listaPais[],int tamPais,int indice)
{
    int indiceBusqueda;
    int confirmacion;
    int flagPrimerCambio=0;
    int opcionMenu;
    char continuarMenu='s';
    eActor proximosDatos;
    eActor auxDatos;
    char auxIdNacionalidadStr[256];
    proximosDatos=listaactor[indice];
    do
    {
        system("cls");
        printf("\nCODIGO      NOMBRE        APELLIDO        GENERO          NACIONALIDAD\n");

        printf("\nDatos actuales seleccionados:\n");
        indiceBusqueda=pais_buscarPorId(listaPais,tamPais,listaactor[indice].idNacionalidad);
        actor_mostrarUnoSolo(listaactor[indice],listaPais,indiceBusqueda);
        printf("\nDatos a modificar:\n");
        indiceBusqueda=pais_buscarPorId(listaPais,tamPais,proximosDatos.idNacionalidad);
        actor_mostrarUnoSolo(proximosDatos,listaPais,indiceBusqueda);

        printf("\nQue datos le gustaria modificar?\n");
        printf("1-NOMBRE\n");
        printf("2-APELLIDO\n");
        printf("3-GENERO\n");
        printf("4-NACIONALIDAD\n");
        printf("5-CONFIRMAR CAMBIOS\n");
        printf("6-FINALIZAR MODIFICACION\n");
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
                    strcpy(proximosDatos.sexo,"Masculino");
                }
                else if(confirmacion==0)
                {
                    strcpy(proximosDatos.sexo,"Femenino");
                }
                printf("\nSe ha ingresado el genero\n");
                flagPrimerCambio=1;
                system("pause");
                break;
            case 4:
                pais_mostrarLista(listaPais,tamPais);
                if(getStrNumerosSinRango("\nIngrese el id de una nacionalidad: ",auxIdNacionalidadStr,"\nSolo se permiten numeros\n",3))
                {
                    if(pais_buscarPorId(listaPais,tamPais,atoi(auxIdNacionalidadStr))==-1)
                    {
                        printf("\nEl id ingresado no existe\n");
                    }
                    else
                    {
                        proximosDatos.idNacionalidad=atoi(auxIdNacionalidadStr);
                        printf("\nSe ha ingresado la nacionalidad\n");
                        flagPrimerCambio=1;
                    }
                }
                system("pause");
                break;
            case 5:
                if(flagPrimerCambio==1)
                {
                    confirmacion=confirmarCambios("\nDesea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        listaactor[indice]=proximosDatos;
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
            case 6:
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
void actor_ordenarDatos(eActor listaactor[],int tamactor)
{
    int i;
    int j;
    eActor auxDatos;
    for(i=0;i<tamactor-1;i++)
    {
        for(j=i+1;j<tamactor;j++)
        {
            if(strcmp(listaactor[i].apellido,listaactor[j].apellido)==1)
            {
                auxDatos=listaactor[i];
                listaactor[i]=listaactor[j];
                listaactor[j]=auxDatos;
            }
            else if(strcmp(listaactor[i].apellido,listaactor[j].apellido)==0)
            {
                if(strcmp(listaactor[i].nombre,listaactor[j].nombre)==1)
                {
                    auxDatos=listaactor[i];
                    listaactor[i]=listaactor[j];
                    listaactor[j]=auxDatos;
                }
            }
        }
    }
}
void actor_mostrarActorMayorA30YGanoMinimoUnPremio(eActor listaActor[],int tamActor,ePais listaPais[],int tamPais)
{
    int edad;
    int indiceBusqueda;
    int i;
    printf("\nCODIGO      NOMBRE      APELLIDO          GENERO     NACIONALIDAD    LOCALIDAD\n");
    for(i=0;i<tamActor;i++)
    {
        edad=2019-listaActor[i].fechaNacimiento.anio;
        indiceBusqueda=pais_buscarPorId(listaPais,tamPais,listaActor[i].idNacionalidad);
        if((listaActor[i].idNacionalidad==listaPais[indiceBusqueda].id) && (edad > 30) && (listaActor[i].cantPremios > 0))
        {
            actor_mostrarUnoSoloConNuevosCampos(listaActor[i],listaPais,indiceBusqueda);
        }
    }
}
void actor_mostrarUnoSoloConSuEdad(eActor unactor,int edadActor)
{
    printf("\n%d\t",unactor.codigo);
    printf("%10s",unactor.nombre);
    printf("%16s",unactor.apellido);
    printf("%17d\n",edadActor);
}
void actor_listarActoresConSusEdades(eActor listaActor[],int tamActor)
{
    int i;
    int edadActor=0;
    if(actor_buscarPorEstado(listaActor,tamActor,OCUPADO)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        printf("\nCODIGO      NOMBRE      APELLIDO               EDAD\n");
        for(i=0;i<tamActor;i++)
        {

            if((listaActor[i].estado==OCUPADO))
            {   edadActor=2019-listaActor[i].fechaNacimiento.anio;
                actor_mostrarUnoSoloConSuEdad(listaActor[i],edadActor);
            }
        }
    }
}
