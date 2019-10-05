#include "labibliopa.h"
#define EN_MARCHA 1
#define ESTACIONADO 0

void hardcodePersonas(sPersona listaPersonas[],int cant)
{
    char nombre[][51]= {"Maria","Ezequiel","German","Yanina"};
    int anio[]= {1990,1980,2000,1995};
    int mes[]= {3,4,12,11};
    int dia[]= {33,22,25,11};
    int id[]= {100,101,105,106};
    int i;

    for(i=0; i<cant; i++)
    {
        listaPersonas[i].id =id[i];
        listaPersonas[i].fechaNac.anio = anio[i];
        listaPersonas[i].fechaNac.mes = mes[i];
        listaPersonas[i].fechaNac.dia = dia[i];
        strcpy(listaPersonas[i].nombre, nombre[i]);
    }
}

void mostrarPersonas(sPersona listaPersonas[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("%04d %20s \t %02d/%02d/%4d\n", listaPersonas[i].id,
               listaPersonas[i].nombre,
               listaPersonas[i].fechaNac.dia,
               listaPersonas[i].fechaNac.mes,
               listaPersonas[i].fechaNac.anio);


    }
}

void hardcodeoAutos(sVehiculo listaAutitos[], int cant)
{
    int i;
    char patente[][8]= {"AAA111", "BBB222", "AAA222", "WWW777",
                        "AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"
                       };
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int horaIngreso[] = {10,9,8,11,10,11,9,7,7,14};
    int horaSalida[] = {11,11,11,12,14,15,12,10,11,17};
    int idPersona[]= {101,106,100,106,101,101,100,105,106,106};
    int estadoVehiculo[]= {ESTACIONADO,ESTACIONADO,ESTACIONADO,ESTACIONADO,ESTACIONADO,ESTACIONADO,ESTACIONADO,ESTACIONADO,ESTACIONADO,ESTACIONADO};

    for(i=0; i<cant; i++)
    {
        strcpy(listaAutitos[i].patente,patente[i]);
        listaAutitos[i].fechaIngreso.dia = dia;
        listaAutitos[i].fechaIngreso.mes = mes;
        listaAutitos[i].fechaIngreso.anio = anio;
        listaAutitos[i].horaIngreso = horaIngreso[i];
        listaAutitos[i].horaSalida = horaSalida[i];
        listaAutitos[i].idDuenio = idPersona[i];
        listaAutitos[i].estadoVehiculo = estadoVehiculo[i];
    }

}

void mostrarAutitos(sVehiculo listaAutitos[], int cant, sPersona listaPersonas[], int ca)
{
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarUnAutito(listaAutitos[i],listaPersonas,ca);
    }
}

int buscarPorPatente(sVehiculo listaAutitos[],int cant)
{
    int retorno=-1;
    int i;
    char patente[51];
    printf("\nIngresa la patente master : ");
    fflush(stdin);
    gets(patente);
    for(i=0; i<cant; i++)
    {
        if(strcmp(listaAutitos[i].patente, patente) == 0)
        {
            retorno = listaAutitos[i].idDuenio;
            break;
        }
    }
    return retorno;
}

void mostrarUnAutito(sVehiculo unAutito,sPersona listaPersonas[], int cp)
{
    int i;

    printf("%6s %02d %02d %02d/%02d/%4d", unAutito.patente,
           unAutito.horaIngreso,
           unAutito.horaSalida,
           unAutito.fechaIngreso.dia,
           unAutito.fechaIngreso.mes,
           unAutito.fechaIngreso.anio);

    for(i=0; i<cp; i++)
    {
        if(unAutito.idDuenio==listaPersonas[i].id)
        {
            printf(" %10s\n", listaPersonas[i].nombre);
            break;
        }
    }




}

void mostrarUnaPersona(sPersona unaPersona[],int indice)
{
    printf("ID : %d \n", unaPersona[indice].id);
    printf("Nombre : %s \n", unaPersona[indice].nombre);
    printf("Fecha de nacimiento : %d/%d/%d \n\n", unaPersona[indice].fechaNac.dia, unaPersona[indice].fechaNac.mes, unaPersona[indice].fechaNac.anio);
}

int buscarIndicePersona(sPersona unaPersona[],int cant, int id)
{
    int i;
    scanf("%d",&id);
    for(i=0; i<cant; i++)
    {
        if(id == unaPersona[i].id)
        {
            return i;
        }
    }
    return -1;
}

void mostrarPersonasConSusAutos(sPersona listaPersonas[], int tp, sVehiculo listaVehiculos[], int tv)
{
    int i;
    int j;

    for(i=0; i<tp; i++)
    {
        printf("%s:\n", listaPersonas[i].nombre);
        for(j=0; j<tv; j++)
        {
            if(listaPersonas[i].id==listaVehiculos[j].idDuenio)
            {

                printf("  %6s %02d %02d %02d/%02d/%4d\n", listaVehiculos[j].patente,
                       listaVehiculos[j].horaIngreso,
                       listaVehiculos[j].horaSalida,
                       listaVehiculos[j].fechaIngreso.dia,
                       listaVehiculos[j].fechaIngreso.mes,
                       listaVehiculos[j].fechaIngreso.anio);
            }
           // printf("\n");
        }
       printf("\n");
    }

}
void ordenarPorNombreYFecha(sPersona listaPersonas[], int tamPersonas)
{
    int i;
    int j;
    sPersona auxPersona;
    for(i=0;i<tamPersonas-1;i++)
    {
        for(j=i+1;j<tamPersonas;j++)
        {
            if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)==1)
            {
                auxPersona=listaPersonas[i];
                listaPersonas[i]=listaPersonas[j];
                listaPersonas[j]=auxPersona;
            }
            else if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)==0)
            {
                if(listaPersonas[i].fechaNac.anio>listaPersonas[j].fechaNac.anio)
                {
                    auxPersona=listaPersonas[i];
                    listaPersonas[i]=listaPersonas[j];
                    listaPersonas[j]=auxPersona;
                }
            }
        }
    }
}
void ordenarVehiculosPorNombreYPatente(sPersona listaPersonas[], int tamPersonas,sVehiculo listaVehiculos[], int tamVehiculos)
{
    int i;
    int j;
    sPersona auxPersona;
    sVehiculo auxVehiculo;
    for(i=0;i<tamPersonas-1;i++)
    {
        for(j=i+1;j<tamPersonas;j++)
        {
            if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)==1)
            {
                auxPersona=listaPersonas[i];
                listaPersonas[i]=listaPersonas[j];
                listaPersonas[j]=auxPersona;

                auxVehiculo=listaVehiculos[i];
                listaVehiculos[i]=listaVehiculos[j];
                listaVehiculos[j]=auxVehiculo;
            }
            else if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)==0)
            {
                if(strcmp(listaVehiculos[i].patente,listaVehiculos[j].patente)==1)
                {
                    auxPersona=listaPersonas[i];
                    listaPersonas[i]=listaPersonas[j];
                    listaPersonas[j]=auxPersona;

                    auxVehiculo=listaVehiculos[i];
                    listaVehiculos[i]=listaVehiculos[j];
                    listaVehiculos[j]=auxVehiculo;
                }
            }
        }
    }
}
void mostrarAutosConSuDuenio(sVehiculo listaVehiculo[],sPersona listaPesonas[],int tamAutos,int tamPersonas)
{
    int i;
    int j;
    for(i=0;i<tamPersonas;i++)
    {
        printf("Duenio: %s\n",listaPesonas[i].nombre);
        for(j=0;j<tamAutos;j++)
        {
            if(listaVehiculo[j].idDuenio==listaPesonas[i].id)
            {
                mostrarUnSoloAuto(listaVehiculo[j]);
            }
        }
    }
}
void mostrarUnSoloAuto(sVehiculo unVehiculo)
{
    printf("\n%6s %02d %02d %02d/%02d/%4d\n", unVehiculo.patente,
    unVehiculo.horaIngreso,
    unVehiculo.horaSalida,
    unVehiculo.fechaIngreso.dia,
    unVehiculo.fechaIngreso.mes,
    unVehiculo.fechaIngreso.anio);
}
void mostrarSoloEstacionadosConSuDuenio(sVehiculo listaVehiculos[],sPersona listaPersonas[],int tamVehiculo,int tamPersonas)
{
    int i;
    int j;
    for(i=0;i<tamPersonas;i++)
    {
        printf("%s\n",listaPersonas[i].nombre);
        for(j=0;j<tamVehiculo;j++)
        {
            if((listaVehiculos[j].estadoVehiculo==ESTACIONADO) && (listaVehiculos[j].idDuenio==listaPersonas[i].id))
            {
                mostrarUnSoloAuto(listaVehiculos[j]);
            }
        }
    }
}
void getString(char* mensaje,char array[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(array);
}
int buscarDuenioPorNombre(sPersona listaPersonas[],int tamPersonas,char nombreABuscar[])
{
    int retorno=-1;
    int i;
    for(i=0;i<tamPersonas;i++)
    {
        if(strcmp(listaPersonas[i].nombre,nombreABuscar)==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void mostrarAutosPorDuenio(char* mensaje,sPersona unDuenio[],sVehiculo listaVehiculos[],int tamPersona,int tamVehiculo)
{
    char nombreDuenio[256];
    int i;
    int seEncontro;
    getString(mensaje,nombreDuenio);
    seEncontro=buscarDuenioPorNombre(unDuenio,tamPersona,nombreDuenio);
    if(seEncontro!=-1)
    {
        printf("Duenio: %s\n",unDuenio[seEncontro].nombre);
        for(i=0;i<tamVehiculo;i++)
        {
            if(listaVehiculos[i].idDuenio==unDuenio[seEncontro].id)
            {
                mostrarUnSoloAuto(listaVehiculos[i]);
            }
        }
    }
    else
    {
        printf("\nDuenio no encontrado\n");
    }

}
void calcularEstadiaPorHora(sVehiculo listaVehiculos[],int tamVehiculos)
{
    float horasACobrar;
    int busquedaPatente;
    busquedaPatente=buscarPorPatente(listaVehiculos,tamVehiculos);
    if(busquedaPatente!=-1)
    {
        if(listaVehiculos[busquedaPatente].estadoVehiculo==ESTACIONADO)
        {
            horasACobrar=(listaVehiculos[busquedaPatente].horaSalida-listaVehiculos[busquedaPatente].horaIngreso)*100;
            printf("\nPrecio a cobrar: %.2f",horasACobrar);
        }
        else
        {
            printf("\nEl auto no se encuentra estacionado\n");
        }
    }
    else
    {
        printf("\nNo se encontro la patente\n");
    }
}
//Calcular: salida-ingreso*importePorHora // y calcular si la patente existe
