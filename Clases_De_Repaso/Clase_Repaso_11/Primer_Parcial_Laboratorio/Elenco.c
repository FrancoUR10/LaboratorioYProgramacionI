#include "Elenco.h"

void elenco_gestionarElencos(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eGenero listaGenero[],int tamGenero,ePais listaPais[],int tamPais,int* contAltas)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("1-GENERAR ELENCOS\n");
        printf("2-LISTAR ELENCOS\n");
        printf("3-SALIR DEL SUB-MENU\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                elenco_darDeAlta(listaElenco,tamElenco,listaActor,tamActor,listaPelicula,tamPelicula,listaGenero,tamGenero,listaPais,tamPais,contAltas);
                system("pause");
                break;
            case 2:
                elenco_mostrarLista(listaElenco,tamElenco,listaActor,tamActor,listaPelicula,tamPelicula);
                system("pause");
                break;
            case 3:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
void elenco_inicializarDatos(eElenco listaElenco[],int tamElenco)
{
    int i;
    for(i=0;i<tamElenco;i++)
    {
        listaElenco[i].codigoDeReparto=-1;
        listaElenco[i].codigoPelicula=-1;
        listaElenco[i].codigoActor=-1;
        listaElenco[i].valorContrato=-1;
    }
}
void elenco_harcodearDatos(eElenco listaelenco[])
{
    int codigoDeReparto[5]={1,2,3,4,5};
    int codigoPelicula[5]={3,2,3,4,5};
    int codigoActor[5]={3,2,4,1,1};
    float valorContrato[5]={5000,6000,8000,2000,3000};
    int i;
    for(i=0;i<5;i++)
    {
        listaelenco[i].codigoDeReparto=codigoDeReparto[i];
        listaelenco[i].codigoPelicula=codigoPelicula[i];
        listaelenco[i].codigoActor=codigoActor[i];
        listaelenco[i].valorContrato=valorContrato[i];
    }
}
void elenco_mostrarUnoSolo(eElenco unaelenco,eActor unActor[],int indiceActor,ePelicula unaPelicula[],int indicePelicula)
{
    printf("\n%d",unaelenco.codigoDeReparto);
    printf("%30s",unaPelicula[indicePelicula].descripcion);
    printf("%16s",unActor[indiceActor].nombre);
    printf("%14.2f\n",unaelenco.valorContrato);
}
void elenco_mostrarLista(eElenco listaelenco[],int tamelenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula)
{
    int indiceBusquedaActor;
    int indiceBusquedaPelicula;
    int i;
    printf("\nCODIGO_REPARTO      PELICULA            ACTOR        VALOR_CONTRATO\n");
    elenco_ordenarDatos(listaelenco,tamelenco,listaPelicula,tamPelicula,listaActor,tamActor);
    for(i=0;i<tamelenco;i++)
    {
        indiceBusquedaActor=actor_buscarPorCodigo(listaActor,tamActor,listaelenco[i].codigoActor);
        indiceBusquedaPelicula=pelicula_buscarPorCodigo(listaPelicula,tamPelicula,listaelenco[i].codigoPelicula);
        if((listaActor[indiceBusquedaActor].estado==OCUPADO) && (listaelenco[i].codigoActor==listaActor[indiceBusquedaActor].codigo) && (listaelenco[i].codigoPelicula==listaPelicula[indiceBusquedaPelicula].codigo))
        {
            elenco_mostrarUnoSolo(listaelenco[i],listaActor,indiceBusquedaActor,listaPelicula,indiceBusquedaPelicula);
        }
    }
}
int elenco_buscarPorCodigoDeReparto(eElenco listaelenco[],int tamelenco,int codigoRepartoABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamelenco;i++)
    {
        if(listaelenco[i].codigoDeReparto==codigoRepartoABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int elenco_darDeAlta(eElenco listaElenco[],int tamElenco,eActor listaActor[],int tamActor,ePelicula listaPelicula[],int tamPelicula,eGenero listaGenero[],int tamGenero,ePais listaPais[],int tamPais,int* contAltas)
{
    int confirmacion;
    eElenco auxDatos;
    int auxCodigoRepartoInt;
    int flagIngresoValido=1;
    int indiceBusqueda;
    char auxCodigoPeliculaStr[256];
    char auxCodigoActorStr[256];
    char auxValorContratoStr[256];
    int sePudo=-1;
    auxCodigoRepartoInt=*contAltas;
    indiceBusqueda=elenco_buscarPorCodigoDeReparto(listaElenco,tamElenco,-1);
    if(indiceBusqueda==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        pelicula_mostrarLista(listaPelicula,tamPelicula,listaGenero,tamGenero);
        if(getStrNumerosSinRango("\nIngrese el codigo de una pelicula: ",auxCodigoPeliculaStr,"\nSolo se permiten numeros\n",3))
        {
            if(pelicula_buscarPorCodigo(listaPelicula,tamPelicula,atoi(auxCodigoPeliculaStr))==-1)
            {
                printf("\nEl id de la pelicula ingresada no existe\n");
                flagIngresoValido=0;
            }
        }
        else
        {
            flagIngresoValido=0;
        }
        if(flagIngresoValido==1)
        {
            actor_mostrarLista(listaActor,tamActor,listaPais,tamPais);
            if(getStrNumerosSinRango("\nIngrese el codigo de un actor: ",auxCodigoActorStr,"\nSolo se permiten numeros\n",3))
            {
                if(actor_buscarPorCodigo(listaActor,tamActor,atoi(auxCodigoActorStr))==-1)
                {
                    printf("\nEl id del actor ingresado no existe\n");
                    flagIngresoValido=0;
                }
                else if(elenco_buscarUnElenco(listaElenco,tamElenco,atoi(auxCodigoActorStr),atoi(auxCodigoPeliculaStr))!=-1)
                {
                    printf("\nEl par pelicula actor ingresado ya existe\n");
                    flagIngresoValido=0;
                }
            }
            else
            {
                flagIngresoValido=0;
            }
        }
        if(flagIngresoValido==1)
        {
            if(!getStrNumerosFlotantes("\nIngrese el valor del contrato: ",auxValorContratoStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre el 1000 y el 10000\n",1000,10000,3))
            {
                flagIngresoValido=0;
            }
        }
        if(flagIngresoValido==1)
        {
            confirmacion=confirmarCambios("\nDesea dar de alta al elenco? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
            if(confirmacion==1)
            {
                auxDatos.codigoDeReparto=auxCodigoRepartoInt;
                auxDatos.codigoPelicula=atoi(auxCodigoPeliculaStr);
                auxDatos.codigoActor=atoi(auxCodigoActorStr);
                auxDatos.valorContrato=atof(auxValorContratoStr);
                listaElenco[indiceBusqueda]=auxDatos;
                *contAltas=auxCodigoRepartoInt+1;
                printf("\nSe ha dado de alta al codigo numero %d\n",auxCodigoRepartoInt);
                sePudo=1;
            }
            else if(confirmacion==0)
            {
                printf("\nAlta cancelada por el usuario\n");
                sePudo=0;
            }
        }
        if(sePudo==-1)
        {
            printf("\nAlta cancelada\n");
        }
    }
    return sePudo;
}
int elenco_buscarUnElenco(eElenco listaElenco[],int tamElenco,int codigoActorABuscar,int codigoPeliculaABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamElenco;i++)
    {
        if((listaElenco[i].codigoDeReparto!=-1) && (listaElenco[i].codigoActor==codigoActorABuscar) && (listaElenco[i].codigoPelicula==codigoPeliculaABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void elenco_ordenarDatos(eElenco listaElenco[],int tamElenco,ePelicula listaPelicula[],int tamPelicula,eActor listaActor[],int tamActor)
{
    int indiceBusquedaI;
    int indiceBusquedaJ;
    int i;
    int j;
    eElenco auxDatos;
    for(i=0;i<tamElenco-1;i++)
    {
        for(j=i+1;j<tamElenco;j++)
        {
            indiceBusquedaI=pelicula_buscarPorCodigo(listaPelicula,tamPelicula,listaElenco[i].codigoPelicula);
            indiceBusquedaJ=pelicula_buscarPorCodigo(listaPelicula,tamPelicula,listaElenco[j].codigoPelicula);
            if(strcmp(listaPelicula[indiceBusquedaI].descripcion,listaPelicula[indiceBusquedaJ].descripcion)==1)
            {
                auxDatos=listaElenco[i];
                listaElenco[i]=listaElenco[j];
                listaElenco[j]=auxDatos;
            }
            else if(strcmp(listaPelicula[indiceBusquedaI].descripcion,listaPelicula[indiceBusquedaJ].descripcion)==0)
            {
                indiceBusquedaI=actor_buscarPorCodigo(listaActor,tamActor,listaElenco[i].codigoActor);
                indiceBusquedaJ=actor_buscarPorCodigo(listaActor,tamActor,listaElenco[j].codigoActor);
                if(strcmp(listaActor[indiceBusquedaI].nombre,listaActor[indiceBusquedaJ].nombre)==1)
                {
                    auxDatos=listaElenco[i];
                    listaElenco[i]=listaElenco[j];
                    listaElenco[j]=auxDatos;
                }
            }
        }
    }
}
