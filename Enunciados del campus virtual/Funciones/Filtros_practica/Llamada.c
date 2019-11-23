#include "Llamada.h"

eLlamada* llamada_nuevollamada()
{
    eLlamada* unllamada=(eLlamada*)malloc(sizeof(eLlamada));
    return unllamada;
}
int llamada_borrarllamada(eLlamada* llamada)
{
    int seLibero=0;
    if(llamada!=NULL)
    {
        free(llamada);
        seLibero=1;
    }
    return seLibero;
}
int llamada_setIdLlamada(eLlamada* llamada,int idLlamada)
{
    int retorno=0;
    if((llamada!=NULL) && (idLlamada > 0))
    {
        llamada->id_llamada=idLlamada;
        retorno=1;
    }
    return retorno;
}
int llamada_setFecha(eLlamada* llamada,char* fecha)
{
    int retorno=0;
    if((llamada!=NULL) && (strlen(fecha) > 0))
    {
        strcpy(llamada->fecha,fecha);
        retorno=1;
    }
    return retorno;
}
int llamada_setNumeroCliente(eLlamada* llamada,int numeroCliente)
{
    int retorno=0;
    if((llamada!=NULL) && (numeroCliente > 0))
    {
        llamada->numero_cliente=numeroCliente;
        retorno=1;
    }
    return retorno;
}
int llamada_setIdProblema(eLlamada* llamada,int idProblema)
{
    int retorno=0;
    if((llamada!=NULL) && (idProblema > 0))
    {
        llamada->id_problema=idProblema;
        retorno=1;
    }
    return retorno;
}
int llamada_setSolucionado(eLlamada* llamada,char* solucionado)
{
    int retorno=0;
    if((llamada!=NULL) && (strlen(solucionado) > 0))
    {
        strcpy(llamada->solucionado,solucionado);
        retorno=1;
    }
    return retorno;
}
int llamada_getIdLlamada(eLlamada* llamada,int* idLlamada)
{
    int retorno=0;
    if(llamada!=NULL && idLlamada!=NULL)
    {
        *idLlamada=llamada->id_llamada;
        retorno=1;
    }
    return retorno;
}
int llamada_getFecha(eLlamada* llamada,char* fecha)
{
    int retorno=0;
    if(llamada!=NULL && fecha!=NULL)
    {
        strcpy(fecha,llamada->fecha);
        retorno=1;
    }
    return retorno;
}
int llamada_getNumeroCliente(eLlamada* llamada,int* numeroCliente)
{
    int retorno=0;
    if(llamada!=NULL && numeroCliente!=NULL)
    {
        *numeroCliente=llamada->numero_cliente;
        retorno=1;
    }
    return retorno;
}
int llamada_getIdProblema(eLlamada* llamada,int* idProblema)
{
    int retorno=0;
    if(llamada!=NULL && idProblema!=NULL)
    {
        *idProblema=llamada->id_problema;
        retorno=1;
    }
    return retorno;
}
int llamada_getSolucionado(eLlamada* llamada,char* solucionado)
{
    int retorno=0;
    if(llamada!=NULL && solucionado!=NULL)
    {
        strcpy(solucionado,llamada->solucionado);
        retorno=1;
    }
    return retorno;
}
eLlamada* llamada_nuevollamadaParametros(char* idLlamada,char* fecha,char* numeroCliente,char* idProblema,char* solucionado)
{
    eLlamada* unllamada=NULL;
    if((idLlamada!=NULL) && (fecha!=NULL) && (numeroCliente!=NULL) && (idProblema!=NULL) && (solucionado!=NULL))
    {
        unllamada=llamada_nuevollamada();
        if(unllamada!=NULL)
        {
            if(!llamada_setIdLlamada(unllamada,atoi(idLlamada)) || !llamada_setFecha(unllamada,fecha) || !llamada_setNumeroCliente(unllamada,atoi(numeroCliente)) || !llamada_setIdProblema(unllamada,atoi(idProblema)) || !llamada_setSolucionado(unllamada,solucionado))
            {
                llamada_borrarllamada(unllamada);
                unllamada=NULL;
            }
        }
    }
    return unllamada;
}
int llamada_mostrarUnllamada(eLlamada* unllamada,eProblema* unProblema)
{
    int seMostro=0;
    if(unllamada!=NULL && unProblema!=NULL)
    {
        printf("\n%d",unllamada->id_llamada);
        printf("%22s",unllamada->fecha);
        printf("%6d\t",unllamada->numero_cliente);
        printf("%28s",unProblema->descripcion);
        printf("%12s\n",unllamada->solucionado);
        seMostro=1;
    }
    return seMostro;
}
void llamada_mostrarListallamadas(LinkedList* listallamadas,LinkedList* listaProblemas)
{
    int indiceProblema;
    eLlamada* auxLlamada;
    eProblema* auxProblema;
    int i;
    int len=ll_len(listallamadas);
    if(listallamadas!=NULL)
    {
        if(listallamadas!=NULL && ll_isEmpty(listallamadas)==1)
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            printf("\nID_LLAMADA       FECHA      NUMERO_CLIENTE     PROBLEMA         SOLUCIONADO\n");
            for(i=0;i<len;i++)
            {
                auxLlamada=(eLlamada*)ll_get(listallamadas,i);
                indiceProblema=problema_buscarPorId(listaProblemas,auxLlamada->id_problema);
                if(indiceProblema!=-1)
                {
                    auxProblema=(eProblema*)ll_get(listaProblemas,indiceProblema);
                    if(auxLlamada->id_problema==auxProblema->id)
                    {
                        llamada_mostrarUnllamada(auxLlamada,auxProblema);
                    }
                }
            }
        }
    }
}
int llamada_buscarPorId(LinkedList* listallamadas,int idABuscar)
{
    int retorno=-1;
    eLlamada* aux;
    int i;
    int len=ll_len(listallamadas);
    if(listallamadas!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eLlamada*)ll_get(listallamadas,i);
            if(aux->id_llamada==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int llamada_cargarDatosModoTexto(FILE* archivo,LinkedList* listallamadas)
{
    char nombreArchivo[256];
    char auxIdLlamadaStr[256];
    char auxFechaStr[256];
    char auxNumeroClienteStr[256];
    char auxIdProblemaStr[256];
    char auxSolucionadoStr[256];
    eLlamada* auxDatos;
    int sePudo=-1;
    if(getStrLetras("\nIngrese el nombre del archivo a cargar: ",nombreArchivo,"\nSolo se permiten letras\n","\nRango valido entre 1 y 16\n",1,16,3))
    {
        archivo=fopen(nombreArchivo,"r");
        if(archivo!=NULL)
        {
            ll_clear(listallamadas);
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdLlamadaStr,auxFechaStr,auxNumeroClienteStr,auxIdProblemaStr,auxSolucionadoStr);
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdLlamadaStr,auxFechaStr,auxNumeroClienteStr,auxIdProblemaStr,auxSolucionadoStr);
                auxDatos=llamada_nuevollamadaParametros(auxIdLlamadaStr,auxFechaStr,auxNumeroClienteStr,auxIdProblemaStr,auxSolucionadoStr);
                ll_add(listallamadas,auxDatos);
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
int llamada_filtrarPorProblema(void* unaLlamada,int idProblema)
{
    int filtro=0;
    eLlamada* llamada=(eLlamada*)unaLlamada;
    if(llamada->id_problema==idProblema)
    {
        filtro=1;
    }
    return filtro;
}
int llamada_filtrarPorProblemaUno(void* unaLlamada)
{
    return llamada_filtrarPorProblema(unaLlamada,1);
}
int llamada_filtrarPorProblemaDos(void* unaLlamada)
{
    return llamada_filtrarPorProblema(unaLlamada,2);
}
int llamada_filtrarPorProblemaTres(void* unaLlamada)
{
    return llamada_filtrarPorProblema(unaLlamada,3);
}
int llamada_filtrarPorProblemaCuatro(void* unaLlamada)
{
    return llamada_filtrarPorProblema(unaLlamada,4);
}
int llamada_filtrarPorProblemaCinco(void* unaLlamada)
{
    return llamada_filtrarPorProblema(unaLlamada,5);
}
int llamada_guardarDatosPorFiltro(FILE* archivo,LinkedList* listallamadas)
{
    char nombreArchivo[256];
    char auxProblemaStr[256];
    int auxProblemaInt;
    char auxIdLlamadaStr[256];
    char auxFechaStr[256];
    char auxNumeroClienteStr[256];
    char auxIdProblemaStr[256];
    char auxSolucionadoStr[256];
    int sePudo=-1;
    LinkedList* nuevaLista;
    eLlamada* auxDatos;
    int i;
    int len;
    if(listallamadas!=NULL && ll_isEmpty(listallamadas)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        if(getStrLetras("\nIngrese el nombre del nuevo archivo a crear: ",nombreArchivo,"\nSolo se permiten letras\n","\nRango valido entre 1 y 16\n",1,16,3))
        {
            printf("\n1-NO ENCIENDE PC\n");
            printf("2-NO FUNCIONA MOUSE\n");
            printf("3-NO FUNCIONA TECLADO\n");
            printf("4-NO HAY INTERNET\n");
            printf("5-NO FUNCIONA TELEFONO\n");
            if(getStrNumeros("\nIngrese el id del problema: ",auxProblemaStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y el 5\n",1,5,3))
            {
                auxProblemaInt=atoi(auxProblemaStr);
                archivo=fopen(nombreArchivo,"w");
                if(archivo!=NULL)
                {
                    switch(auxProblemaInt)
                    {
                        case 1:
                            nuevaLista=ll_filter(listallamadas,llamada_filtrarPorProblemaUno);
                            break;
                        case 2:
                            nuevaLista=ll_filter(listallamadas,llamada_filtrarPorProblemaDos);
                            break;
                        case 3:
                            nuevaLista=ll_filter(listallamadas,llamada_filtrarPorProblemaTres);
                            break;
                        case 4:
                            nuevaLista=ll_filter(listallamadas,llamada_filtrarPorProblemaCuatro);
                            break;
                        case 5:
                            nuevaLista=ll_filter(listallamadas,llamada_filtrarPorProblemaCinco);
                            break;
                    }
                    if(nuevaLista!=NULL)
                    {
                        len=ll_len(nuevaLista);
                        fprintf(archivo,"ID_LLAMADA,FECHA,NUMERO_CLIENTE,ID_PROBLEMA,SOLUCIONADO\n");
                        for(i=0;i<len;i++)
                        {
                            auxDatos=(eLlamada*)ll_get(nuevaLista,i);
                            itoa(auxDatos->id_llamada,auxIdLlamadaStr,10);
                            llamada_getFecha(auxDatos,auxFechaStr);
                            itoa(auxDatos->numero_cliente,auxNumeroClienteStr,10);
                            itoa(auxDatos->id_problema,auxIdProblemaStr,10);
                            llamada_getSolucionado(auxDatos,auxSolucionadoStr);
                            fprintf(archivo,"%s,%s,%s,%s,%s\n",auxIdLlamadaStr,auxFechaStr,auxNumeroClienteStr,auxIdProblemaStr,auxSolucionadoStr);
                        }
                    }
                    fclose(archivo);
                    printf("\nSe han guardado los datos\n");
                    sePudo=1;
                }
            }
        }
    }
    return sePudo;
}
