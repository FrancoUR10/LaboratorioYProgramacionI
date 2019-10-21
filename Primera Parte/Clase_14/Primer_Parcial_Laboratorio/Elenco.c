#include "Elenco.h"

void menuGestionarElencos(eElenco listaElencos[],int tamElenco,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero,int* contadorDeAltasElencos,ePais listaPais[],int tamPais)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        opcionMenu=getInt("1-GENERAR ELENCO\n2-MOSTRAR ELENCO\n3-SALIR DEL SUBMENU\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                darDeAltaElencos(listaElencos,tamElenco,contadorDeAltasElencos,listaActores,tamActor,listaPeliculas,tamPelicula,listaGeneros,tamGenero,listaPais,tamPais);
                system("pause");
                break;
            case 2:
                //ordenarElencos(listaElencos,tamElenco);
                mostrarListaElencos(listaElencos,tamElenco,listaActores,tamActor,listaPeliculas,tamPelicula);
                system("pause");
                break;
            case 3:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\a\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');

}
void inicializarElenco(eElenco listaElencos[],int tamElenco)
{
    int i;
    for(i=0;i<tamElenco;i++)
    {
        listaElencos[i].codigoPelicula=-1;
        listaElencos[i].codigoActor=-1;
        listaElencos[i].valorContrato=0;
        listaElencos[i].codigoElenco=-1;
        listaElencos[i].estado=LIBRE;
    }
}
void harcodearElenco(eElenco listaElencos[],int tamElenco)
{
    int codigoElenco[3]={1,2,3};
    int codigoActor[3]={1,1,3};
    int codigoPelicula[3]={100,200,400};
    float valorContrato[3]={500,600.54,700.50};
    int i;
    for(i=0;i<tamElenco;i++)
    {
        listaElencos[i].codigoElenco=codigoElenco[i];
        listaElencos[i].codigoActor=codigoActor[i];
        listaElencos[i].codigoPelicula=codigoPelicula[i];
        listaElencos[i].valorContrato=valorContrato[i];
        listaElencos[i].estado=OCUPADO;
    }
}
int pedirDatosDeElencos(eElenco listaElencos[],int tamElenco,int indice,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero,ePais listaPais[],int tamPais)
{
    int indicePelicula;
    int indiceActor;
    char auxCodigoPeliculaStr[256];
    char auxCodigoActorStr[256];
    char auxValorContratoStr[256];
    int confirmacion;
    int retorno=-1;
    eElenco auxDatos;
    int ingresoSecuencialValido=1;

    if(ingresoSecuencialValido==1)
    {
        if(ingresoSecuencialValido==1)
        {
            printf("Peliculas disponibles:\n");
            mostrarListadoPeliculas(listaPeliculas,tamPelicula,listaGeneros,tamGenero);
            if(getStrSoloNumeroSinRango("\nIngrese el codigo de una pelicula: ",auxCodigoPeliculaStr,"\nSolo se permite el numero de una pelicula\n",3))
            {
                auxDatos.codigoPelicula=atoi(auxCodigoPeliculaStr);
                indicePelicula=buscarCodigoPelicula(listaPeliculas,tamPelicula,auxDatos.codigoPelicula);
                if(indicePelicula==-1)
                {
                    printf("\nEl codigo de la pelicula no existe en el elenco\n");
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
            printf("Actores disponibles:\n");
            mostrarListadoDeActores(listaActores,tamActor,listaPais,tamPais);
            if(getStrSoloNumeroSinRango("\nIngrese el codigo de un actor/a: ",auxCodigoActorStr,"\nSolo se permite el numero de un actor/a\n",3))
            {
                auxDatos.codigoActor=atoi(auxCodigoActorStr);
                indiceActor=buscarActorPorCodigo(listaActores,tamActor,auxDatos.codigoActor,OCUPADO);
                if(indiceActor==-1)
                {
                    printf("\nEl codigo del actor ingresado no existe\n");
                    ingresoSecuencialValido=0;
                }
                else
                {
                    indiceActor=buscarActorEnElElenco(listaElencos,tamElenco,auxDatos.codigoActor,auxDatos.codigoPelicula);
                    if((indiceActor!=-1) && (indicePelicula!=-1))
                    {
                        printf("\nEl actor ingresado ya se encuentra en el elenco\n");
                        ingresoSecuencialValido=0;
                    }
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
        if(!getStrNumerosFlotantes("\nIngrese el valor del contrato\n",auxValorContratoStr,"\nSolo se permiten numeros y un solo punto\n","Rango valido entre 1 y 8",1,8,3))
        {
            ingresoSecuencialValido=0;
        }
    }
    auxDatos.valorContrato=atof(auxValorContratoStr);
    if(ingresoSecuencialValido==1)
    {
        confirmacion=confirmarCambios("Esta seguro que desea dar de alta al elenco? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
        if(confirmacion==1)
        {
            listaElencos[indice]=auxDatos;
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}
void mostrarListaElencos(eElenco listaElencos[],int tamElenco,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula)
{
    int i;
    int j;
    int k;
    ordenarListadoDePeliculas(listaPeliculas,tamPelicula);
    ordenarListadoDeActores(listaActores,tamActor);
    for(i=0;i<tamPelicula;i++)
    {
        if(listaPeliculas[i].codigo!=-1)
        {
            printf("\nPelicula: %s\n",listaPeliculas[i].descripcion);
        }
        for(j=0;j<tamActor;j++)
        {
            for(k=0;k<tamElenco;k++)
            {
                if((listaActores[j].estado==OCUPADO) && (listaElencos[k].estado==OCUPADO) && (listaElencos[k].codigoActor==listaActores[j].codigo) && (listaElencos[k].codigoPelicula==listaPeliculas[i].codigo))
                {
                    mostrarUnSoloElenco(listaElencos[k],listaActores,j);
                }
            }
        }
    }
}
void mostrarUnSoloElenco(eElenco unElenco,eActor listaActores[],int indiceActor)
{
    printf("\nActor: %s %s",listaActores[indiceActor].nombre,listaActores[indiceActor].apellido);
    printf("\tValor del contrato: %.2f\n",unElenco.valorContrato);
}
void darDeAltaElencos(eElenco listaElencos[],int tamElenco,int* contadorDeAltasElencos,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero,ePais listaPais[],int tamPais)
{
    int sePudo;
    int indiceLibre;
    int auxCodigoInt;
    indiceLibre=buscarCodigoElenco(listaElencos,tamActor,-1);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxCodigoInt=*contadorDeAltasElencos;
        sePudo=pedirDatosDeElencos(listaElencos,tamElenco,indiceLibre,listaActores,tamActor,listaPeliculas,tamPelicula,listaGeneros,tamGenero,listaPais,tamPais);
        if(sePudo==-1)
        {
            printf("\nAlta del elenco cancelada\n");
        }
        else if(sePudo==0)
        {
            printf("\nAlta del elenco cancelada por el usuario\n");
        }
        else if(sePudo==1)
        {
            listaElencos[indiceLibre].codigoElenco=auxCodigoInt;
            listaElencos[indiceLibre].estado=OCUPADO;
            *contadorDeAltasElencos=auxCodigoInt+1;
            printf("\nSe ha dado de alta el codigo numero %d\n",auxCodigoInt);
        }
    }
}
int buscarCodigoElenco(eElenco listaElencos[],int tamElenco,int codigoElenco)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamElenco;i++)
    {
        if(listaElencos[i].codigoElenco==codigoElenco)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int buscarActorEnElElenco(eElenco listaElencos[],int tamElenco,int codigoActorEnElenco,int codigoPeliculaEnElenco)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamElenco;i++)
    {
        if((listaElencos[i].estado==OCUPADO) && ((listaElencos[i].codigoActor==codigoActorEnElenco) && (listaElencos[i].codigoPelicula==codigoPeliculaEnElenco)))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void mostrarPeliculasConUnActorArgentino(eElenco listaElencos[],int tamElenco,eActor listaActores[],int tamActor,ePelicula listaPelicula[],int tamPelicula,ePais listaPaises[],int tamPais)
{
    int idNacionalidadArgentina;
    int flagPrimerActorArgentino=1;
    int i;
    int j;
    int k;
    idNacionalidadArgentina=buscarNacionalidadArgentina(listaPaises,tamPais);
    printf("\nPeliculas con un actor argentino:\n");
    for(i=0;i<tamElenco;i++)
    {
        for(j=0;j<tamActor;j++)
        {
            for(k=0;k<tamPelicula;k++)
            {
                if((listaActores[j].idNacionalidad==idNacionalidadArgentina) && ((listaElencos[i].codigoActor==listaActores[j].codigo) && (listaElencos[i].codigoPelicula==listaPelicula[k].codigo)))
                {
                    printf("%s\n",listaPelicula[k].descripcion);
                    flagPrimerActorArgentino=0;
                }
            }
        }
    }
    if(flagPrimerActorArgentino==1)
    {
        printf("\nNo hay ninguna pelicula con un actor argentino\n");
    }
}
void menuInformarDatos(eElenco listaElencos[],int tamElenco,eActor listaActores[],int tamActor,ePelicula listaPeliculas[],int tamPelicula,eGenero listaGeneros[],int tamGenero,ePais listaPais[],int tamPais)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("1-PELICULAS DE TERROR CUYO ANIO SEA DESPUES DEL 2002\n");
        printf("2-PELICULAS EN DONDE PARTICIPA UN ACTOR ARGENTINO\n");
        printf("3-SALIR DEL SUBMENU\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                mostrarPeliculaTerrorDespuesDe2002(listaPeliculas,tamPelicula,listaGeneros,tamGenero);
                system("pause");
                break;
            case 2:
                mostrarPeliculasConUnActorArgentino(listaElencos,tamElenco,listaActores,tamActor,listaPeliculas,tamPelicula,listaPais,tamPais);
                system("pause");
                break;
            case 3:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\a\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
