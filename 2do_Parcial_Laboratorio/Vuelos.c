#include "Vuelos.h"

eVuelo* vuelo_nuevovuelo()
{
    eVuelo* unvuelo=(eVuelo*)malloc(sizeof(eVuelo));
    return unvuelo;
}
int vuelo_borrarvuelo(eVuelo* vuelo)
{
    int seLibero=0;
    if(vuelo!=NULL)
    {
        free(vuelo);
        seLibero=1;
    }
    return seLibero;
}
int vuelo_setIdVuelo(eVuelo* vuelo,int idVuelo)
{
    int retorno=0;
    if((vuelo!=NULL) && (idVuelo > 0))
    {
        vuelo->idVuelo=idVuelo;
        retorno=1;
    }
    return retorno;
}
int vuelo_setIdAvion(eVuelo* vuelo,int idAvion)
{
    int retorno=0;
    if((vuelo!=NULL) && (idAvion > 0))
    {
        vuelo->idAvion=idAvion;
        retorno=1;
    }
    return retorno;
}
int vuelo_setIdPiloto(eVuelo* vuelo,int idPiloto)
{
    int retorno=0;
    if((vuelo!=NULL) && (idPiloto > 0))
    {
        vuelo->idPiloto=idPiloto;
        retorno=1;
    }
    return retorno;
}
int vuelo_setFecha(eVuelo* vuelo,char* fecha)
{
    int retorno=0;
    if((vuelo!=NULL) && (strlen(fecha) > 0))
    {
        strcpy(vuelo->fecha,fecha);
        retorno=1;
    }
    return retorno;
}
int vuelo_setDestino(eVuelo* vuelo,char* destino)
{
    int retorno=0;
    if((vuelo!=NULL) && (strlen(destino) > 0))
    {
        strcpy(vuelo->destino,destino);
        retorno=1;
    }
    return retorno;
}
int vuelo_setCantPasajeros(eVuelo* vuelo,int cantPasajeros)
{
    int retorno=0;
    if((vuelo!=NULL) && (cantPasajeros > 0))
    {
        vuelo->cantPasajeros=cantPasajeros;
        retorno=1;
    }
    return retorno;
}
int vuelo_setHoraDespegue(eVuelo* vuelo,int horaDespegue)
{
    int retorno=0;
    if((vuelo!=NULL) && (horaDespegue > 0))
    {
        vuelo->horaDespegue=horaDespegue;
        retorno=1;
    }
    return retorno;
}
int vuelo_setHoraLlegada(eVuelo* vuelo,int horaLlegada)
{
    int retorno=0;
    if((vuelo!=NULL) && (horaLlegada > 0))
    {
        vuelo->horaLlegada=horaLlegada;
        retorno=1;
    }
    return retorno;
}
int vuelo_getIdVuelo(eVuelo* vuelo,int* idVuelo)
{
    int retorno=0;
    if(vuelo!=NULL && idVuelo!=NULL)
    {
        *idVuelo=vuelo->idVuelo;
        retorno=1;
    }
    return retorno;
}
int vuelo_getIdAvion(eVuelo* vuelo,int* idAvion)
{
    int retorno=0;
    if(vuelo!=NULL && idAvion!=NULL)
    {
        *idAvion=vuelo->idAvion;
        retorno=1;
    }
    return retorno;
}
int vuelo_getIdPiloto(eVuelo* vuelo,int* idPiloto)
{
    int retorno=0;
    if(vuelo!=NULL && idPiloto!=NULL)
    {
        *idPiloto=vuelo->idPiloto;
        retorno=1;
    }
    return retorno;
}
int vuelo_getFecha(eVuelo* vuelo,char* fecha)
{
    int retorno=0;
    if(vuelo!=NULL && fecha!=NULL)
    {
        strcpy(fecha,vuelo->fecha);
        retorno=1;
    }
    return retorno;
}
int vuelo_getDestino(eVuelo* vuelo,char* destino)
{
    int retorno=0;
    if(vuelo!=NULL && destino!=NULL)
    {
        strcpy(destino,vuelo->destino);
        retorno=1;
    }
    return retorno;
}
int vuelo_getCantPasajeros(eVuelo* vuelo,int* cantPasajeros)
{
    int retorno=0;
    if(vuelo!=NULL && cantPasajeros!=NULL)
    {
        *cantPasajeros=vuelo->cantPasajeros;
        retorno=1;
    }
    return retorno;
}
int vuelo_getHoraDespegue(eVuelo* vuelo,int* horaDespegue)
{
    int retorno=0;
    if(vuelo!=NULL && horaDespegue!=NULL)
    {
        *horaDespegue=vuelo->horaDespegue;
        retorno=1;
    }
    return retorno;
}
int vuelo_getHoraLlegada(eVuelo* vuelo,int* horaLlegada)
{
    int retorno=0;
    if(vuelo!=NULL && horaLlegada!=NULL)
    {
        *horaLlegada=vuelo->horaLlegada;
        retorno=1;
    }
    return retorno;
}
eVuelo* vuelo_nuevovueloParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
    eVuelo* unvuelo=NULL;
    if((idVuelo!=NULL) && (idAvion!=NULL) && (idPiloto!=NULL) && (fecha!=NULL) && (destino!=NULL) && (cantPasajeros!=NULL) && (horaDespegue!=NULL) && (horaLlegada!=NULL))
    {
        unvuelo=vuelo_nuevovuelo();
        if(unvuelo!=NULL)
        {
            if(!vuelo_setIdVuelo(unvuelo,atoi(idVuelo)) || !vuelo_setIdAvion(unvuelo,atoi(idAvion)) || !vuelo_setIdPiloto(unvuelo,atoi(idPiloto)) || !vuelo_setFecha(unvuelo,fecha) || !vuelo_setDestino(unvuelo,destino) || !vuelo_setCantPasajeros(unvuelo,atoi(cantPasajeros)) || !vuelo_setHoraDespegue(unvuelo,atoi(horaDespegue)) || !vuelo_setHoraLlegada(unvuelo,atoi(horaLlegada)))
            {
                vuelo_borrarvuelo(unvuelo);
                unvuelo=NULL;
            }
        }
    }
    return unvuelo;
}
int vuelo_mostrarUnvuelo(eVuelo* unvuelo,ePiloto* unPiloto)
{
    int idVuelo;
    int idAvion;
    char nombreYApellido[256];
    char fecha[256];
    char destino[256];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

    vuelo_getIdVuelo(unvuelo,&idVuelo);
    vuelo_getIdAvion(unvuelo,&idAvion);
    piloto_getNombreYApellido(unPiloto,nombreYApellido);
    vuelo_getFecha(unvuelo,fecha);
    vuelo_getDestino(unvuelo,destino);
    vuelo_getCantPasajeros(unvuelo,&cantPasajeros);
    vuelo_getHoraDespegue(unvuelo,&horaDespegue);
    vuelo_getHoraLlegada(unvuelo,&horaLlegada);
    int seMostro=0;
    if(unvuelo!=NULL && unPiloto!=NULL)
    {
        printf("\n%d",idVuelo);
        printf("%7d\t",idAvion);
        printf("%8s\t",nombreYApellido);
        printf("%4s",fecha);
        printf("%10s",destino);
        printf("%8d",cantPasajeros);
        printf("%8d",horaDespegue);
        printf("%8d\n",horaLlegada);
        seMostro=1;
    }
    return seMostro;
}
void vuelo_mostrarListavuelos(LinkedList* listavuelos,LinkedList* listaPiloto)
{
    int auxIdPilotoVuelos;
    int auxIdPiloto;
    int indiceBusqueda;
    eVuelo* auxvuelo;
    ePiloto* auxPiloto;
    int i;
    int len=ll_len(listavuelos);
    if(listavuelos!=NULL && listaPiloto!=NULL)
    {
        if(listavuelos!=NULL && ll_isEmpty(listavuelos)==1)
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            printf("\nIDVUELO--IDAVION--PILOTO--FECHA--DESTINO--C.PASAJEROS--H.DESPEGUE--H.LLEGADA\n");
            for(i=0;i<len;i++)
            {
                auxvuelo=(eVuelo*)ll_get(listavuelos,i);
                indiceBusqueda=piloto_buscarPorId(listaPiloto,auxvuelo->idPiloto);
                if(indiceBusqueda!=-1)
                {
                    auxPiloto=(ePiloto*)ll_get(listaPiloto,indiceBusqueda);
                    vuelo_getIdPiloto(auxvuelo,&auxIdPilotoVuelos);
                    piloto_getId(auxPiloto,&auxIdPiloto);
                    if(auxIdPilotoVuelos==auxIdPiloto)
                    {
                        vuelo_mostrarUnvuelo(auxvuelo,auxPiloto);
                    }
                }
            }
        }
    }
}
int vuelo_buscarPorId(LinkedList* listavuelos,int idABuscar)
{
    int auxIdVuelo;
    int retorno=-1;
    eVuelo* aux;
    int i;
    int len=ll_len(listavuelos);
    if(listavuelos!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eVuelo*)ll_get(listavuelos,i);
            vuelo_getIdVuelo(aux,&auxIdVuelo);
            if(auxIdVuelo==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int vuelo_cargarDatosModoTexto(FILE* archivo,LinkedList* listaVuelos)
{
    char nombreArchivo[256];
    char auxIdVueloStr[256];
    char auxIdAvionStr[256];
    char auxIdPilotoStr[256];
    char auxFechaStr[256];
    char auxDestinoStr[256];
    char auxCantPasajerosStr[256];
    char auxHoraDespegueStr[256];
    char auxHoraLlegadaStr[256];
    eVuelo* auxDatos;
    int sePudo=-1;
    if(getStrLetras("\nIngrese el nombre del archivo a cargar: ",nombreArchivo,"\nSolo se permiten letras\n","\nRango valido entre 1 y 16\n",1,16,3))
    {
        archivo=fopen(nombreArchivo,"r");
        if(archivo!=NULL)
        {
            ll_clear(listaVuelos);
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdVueloStr,auxIdAvionStr,auxIdPilotoStr,auxFechaStr,auxDestinoStr,auxCantPasajerosStr,auxHoraDespegueStr,auxHoraLlegadaStr);
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdVueloStr,auxIdAvionStr,auxIdPilotoStr,auxFechaStr,auxDestinoStr,auxCantPasajerosStr,auxHoraDespegueStr,auxHoraLlegadaStr);
                auxDatos=vuelo_nuevovueloParametros(auxIdVueloStr,auxIdAvionStr,auxIdPilotoStr,auxFechaStr,auxDestinoStr,auxCantPasajerosStr,auxHoraDespegueStr,auxHoraLlegadaStr);
                ll_add(listaVuelos,auxDatos);
                if(feof(archivo))
                {
                    break;
                }
            }
            fclose(archivo);
            printf("\nSe han cargado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int vuelo_filtrarPorVuelosCortos(void* unvuelo)
{
    int filtro=0;
    int horaDespegue;
    int horaLlegada;
    int horasDelViaje;
    eVuelo* vuelo=(eVuelo*)unvuelo;
    vuelo_getHoraDespegue(vuelo,&horaDespegue);
    vuelo_getHoraLlegada(vuelo,&horaLlegada);
    horasDelViaje=horaLlegada-horaDespegue;
    if(horasDelViaje < 3)
    {
        filtro=1;
    }
    return filtro;
}
int vuelo_guardarDatosPorFiltro(FILE* archivo,LinkedList* listavuelos)
{
    char nombreArchivo[256];
    char auxIdVueloStr[256];
    char auxIdAvionStr[256];
    char auxIdPilotoStr[256];
    char auxFechaStr[256];
    char auxDestinoStr[256];
    char auxCantPasajerosStr[256];
    char auxHoraDespegueStr[256];
    char auxHoraLlegadaStr[256];
    int auxIdVuelo;
    int auxIdAvion;
    int auxIdPiloto;
    int auxCantPasajeros;
    int auxHoraDespegue;
    int auxHoraLlegada;
    int sePudo=-1;
    LinkedList* nuevaLista;
    eVuelo* auxDatos;
    int i;
    int len;
    if(listavuelos!=NULL && ll_isEmpty(listavuelos)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        if(getStrLetras("\nIngrese el nombre del nuevo archivo a crear: ",nombreArchivo,"\nSolo se permiten letras\n","\nRango valido entre 1 y 16\n",1,16,3))
        {
            archivo=fopen(nombreArchivo,"w");
            if(archivo!=NULL)
            {
                nuevaLista=ll_filter(listavuelos,vuelo_filtrarPorVuelosCortos);
                if(nuevaLista!=NULL)
                {
                    len=ll_len(nuevaLista);
                    fprintf(archivo,"ID_VUELO,ID_AVION,ID_PILOTO,FECHA,DESTINO,CANT.PASAJEROS_H.DESPEGUE,H.LLEGADA\n");
                    for(i=0;i<len;i++)
                    {
                        auxDatos=(eVuelo*)ll_get(nuevaLista,i);
                        vuelo_getIdVuelo(auxDatos,&auxIdVuelo);
                        itoa(auxIdVuelo,auxIdVueloStr,10);
                        vuelo_getIdAvion(auxDatos,&auxIdAvion);
                        itoa(auxIdAvion,auxIdAvionStr,10);
                        vuelo_getIdPiloto(auxDatos,&auxIdPiloto);
                        itoa(auxIdPiloto,auxIdPilotoStr,10);
                        vuelo_getFecha(auxDatos,auxFechaStr);
                        vuelo_getDestino(auxDatos,auxDestinoStr);
                        vuelo_getCantPasajeros(auxDatos,&auxCantPasajeros);
                        itoa(auxCantPasajeros,auxCantPasajerosStr,10);
                        vuelo_getHoraDespegue(auxDatos,&auxHoraDespegue);
                        itoa(auxHoraDespegue,auxHoraDespegueStr,10);
                        vuelo_getHoraLlegada(auxDatos,&auxHoraLlegada);
                        itoa(auxHoraLlegada,auxHoraLlegadaStr,10);
                        fprintf(archivo,"%s,%s,%s,%s,%s,%s,%s,%s\n",auxIdVueloStr,auxIdAvionStr,auxIdPilotoStr,auxFechaStr,auxDestinoStr,auxCantPasajerosStr,auxHoraDespegueStr,auxHoraLlegadaStr);
                    }
                }
                fclose(archivo);
                printf("\nSe han guardado los datos\n");
                sePudo=1;
            }
        }
    }
    return sePudo;
}
int vuelo_filtrarPorDestinoPortugal(void* unvuelo)
{
    int filtro=0;
    char auxDestino[256];
    eVuelo* vuelo=(eVuelo*)unvuelo;
    vuelo_getDestino(vuelo,auxDestino);
    if(strcmp(auxDestino,"Portugal")==0)
    {
        filtro=1;
    }
    return filtro;
}
void vuelo_mostrarListaDeVuelosAPortugal(LinkedList* listavuelos,LinkedList* listaPiloto)
{
    LinkedList* listaFiltro=ll_filter(listavuelos,vuelo_filtrarPorDestinoPortugal);
    if(listaFiltro!=NULL)
    {
        vuelo_mostrarListavuelos(listaFiltro,listaPiloto);
    }
}
/*
int vuelo_buscarPorNombrePil(LinkedList* listavuelos,int idABuscar)
{
    int auxIdVuelo;
    int retorno=-1;
    eVuelo* aux;
    int i;
    int len=ll_len(listavuelos);
    if(listavuelos!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eVuelo*)ll_get(listavuelos,i);
            vuelo_getIdVuelo(aux,&auxIdVuelo);
            if(auxIdVuelo==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
*/
/*
vuelo_filtrarPorVuelosSinAlexLifeson(void* unVuelo)
{
    int filtro=0;
    int auxIdPiloto;
    eVuelo* vuelo=(eVuelo*)unvuelo;
    vuelo_getIdPiloto(vuelo,&auxIdPiloto);
    if(auxIdPiloto!=1)
}
*/
/*
void vuelo_mostrarListaDeVuelosSinAlexLifeson(LinkedList* listavuelos,LinkedList* listaPiloto)
{
    LinkedList* listaFiltro=ll_filter(listavuelos,vuelo_filtrarPorVuelosSinAlexLifeson);
    if(listaFiltro!=NULL)
    {
        vuelo_mostrarListavuelos(listaFiltro,listaPiloto);
    }
}
*/
