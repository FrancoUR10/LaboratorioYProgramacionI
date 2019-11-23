#include "llamada.h"

eLlamada* llamada_nuevollamada()
{
    eLlamada* unllamada=(eLlamada*)malloc(sizeof(eLlamada));
    if(unllamada!=NULL)
    {
        unllamada->id_Llamada=-1;
        strcpy(unllamada->fecha,"VACIO");
        unllamada->numero_Cliente=-1;
        unllamada->id_Problema=-1;
        strcpy(unllamada->solucionado,"NO");
    }
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
int llamada_mostrarUnllamada(eLlamada* unllamada,eProblemas* elProblema)
{
    int seMostro=0;
    if(unllamada!=NULL && elProblema!=NULL)
    {
        printf("\n%d\t",unllamada->id_Llamada);
        printf("%12s",unllamada->fecha);
        printf("%8d\t",unllamada->numero_Cliente);
        printf("%22s",elProblema->descripcion);
        printf("%16s\n",unllamada->solucionado);
        seMostro=1;
    }
    return seMostro;
}
void llamada_mostrarListallamadas(LinkedList* listallamadas,LinkedList* listaProblemas)
{
    int indiceProblema;
    eLlamada* aux;
    eProblemas* auxProblema;
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
            printf("\nID_LLAMADA    FECHA     NUMERO_CLIENTE    PROBLEMA    SOLUCIONADO\n");
            for(i=0; i<len; i++)
            {
                aux=(eLlamada*)ll_get(listallamadas,i);
                indiceProblema=problema_buscarPorId(listaProblemas,aux->id_Problema);
                if(indiceProblema!=-1)
                {
                    auxProblema=(eProblemas*)ll_get(listaProblemas,indiceProblema);
                    if(aux->id_Problema==auxProblema->id)
                    {
                        llamada_mostrarUnllamada(aux,auxProblema);
                    }
                }
            }
        }
    }
}
int llamada_buscarPorIdLlamada(LinkedList* listallamadas,int id_llamadaABuscar)
{
    int retorno=-1;
    eLlamada* aux;
    int i;
    int len=ll_len(listallamadas);
    if(listallamadas!=NULL)
    {
        for(i=0; i<len; i++)
        {
            aux=(eLlamada*)ll_get(listallamadas,i);
            if(aux->id_Llamada==id_llamadaABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int llamada_guardarDatosPorFiltro(FILE* archivo,LinkedList* listallamadas)
{
    LinkedList* nuevaLista=NULL;
    char nombreArchivo[256];
    char filtroProblemaStr[256];
    int filtroProblemaInt;
    int sePudo=0;
    int i;
    int len;
    char auxId_LlamadaStr[256];
    char auxFechaStr[256];
    char auxNumeroClienteStr[256];
    char auxId_ProblemaStr[256];
    char auxSolucionadoStr[256];
    eLlamada* auxDatos;
    if(listallamadas!=NULL && ll_isEmpty(listallamadas)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        if(getStrLetras("\nIngrese el nombre del nuevo archivo que desea crear: ",nombreArchivo,"\nSolo se permiten letras\n","Rango valido entre el 1 y el 10",1,10,3))
        {
            if(getStrNumeros("\nIngrese el id del problema a filtrar: ",filtroProblemaStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y el 5\n",1,5,3))
            {
                filtroProblemaInt=atoi(filtroProblemaStr);
                archivo=fopen(nombreArchivo,"w");
                if(archivo != NULL)
                {
                    fseek(archivo,1L,SEEK_SET);
                    switch(filtroProblemaInt)
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
                        for(i=0;i<len;i++)
                        {
                            auxDatos=(eLlamada*)ll_get(nuevaLista,i);
                            itoa(auxDatos->id_Llamada,auxId_LlamadaStr,10);
                            llamada_getFecha(auxDatos,auxFechaStr);
                            itoa(auxDatos->numero_Cliente,auxNumeroClienteStr,10);
                            itoa(auxDatos->id_Problema,auxId_ProblemaStr,10);
                            llamada_getSolucionado(auxDatos,auxSolucionadoStr);
                            fprintf(archivo,"%s,%s,%s,%s,%s\n",auxId_LlamadaStr,auxFechaStr,auxNumeroClienteStr,auxId_ProblemaStr,auxSolucionadoStr);
                        }
                    }
                    fclose(archivo);
                    sePudo=1;
                }
            }
        }
    }
    return sePudo;
}
int llamada_cargarDatos(FILE* archivo,LinkedList* listallamadas)
{
    int sePudo=-1;
    eLlamada* auxDatos;
    char nombreArchivo[256];
    if(getStrLetras("\nIngrese el nombre del archivo que desea cargar",nombreArchivo,"\nSolo se permiten letras\n","Rango valido entre el 1 y el 10",1,10,3))
    {
        archivo=fopen(nombreArchivo,"rb");
        if(archivo!=NULL)
        {
            ll_clear(listallamadas);
            while(!feof(archivo))
            {
                auxDatos=llamada_nuevollamada();
                if(auxDatos!=NULL)
                {
                    fread(auxDatos,sizeof(eLlamada),1,archivo);
                    if(feof(archivo))
                    {
                        break;
                    }
                    ll_add(listallamadas,auxDatos);
                }
            }
            fclose(archivo);
            printf("\nSe han cargado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int llamada_cargarDatosModoTexto(FILE* archivo,LinkedList* listaLlamadas)
{
    char id_LlamadaStr[256];
    char auxFechaStr[256];
    char auxNumeroClienteStr[256];
    char auxIdProblemaStr[256];
    char auxSolucionadoStr[256];
    int sePudo=-1;
    eLlamada* auxDatos;
    char nombreArchivo[256];
    if(getStrLetras("\nIngrese el nombre del archivo que desea cargar: ",nombreArchivo,"\nSolo se permiten letras\n","Rango valido entre el 1 y el 10",1,10,3))
    {
        archivo=fopen(nombreArchivo,"r");
        if(archivo!=NULL)
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_LlamadaStr,auxFechaStr,auxNumeroClienteStr,auxIdProblemaStr,auxSolucionadoStr);
            ll_clear(listaLlamadas);
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_LlamadaStr,auxFechaStr,auxNumeroClienteStr,auxIdProblemaStr,auxSolucionadoStr);
                auxDatos=llamada_nuevaLlamadaParametros(id_LlamadaStr,auxFechaStr,auxNumeroClienteStr,auxIdProblemaStr,auxSolucionadoStr);
                //  printf("\n%d\n",auxDatos->id_Problema);
                ll_add(listaLlamadas,auxDatos);
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
eLlamada* llamada_nuevaLlamadaParametros(char* idLlamada,char* fecha,char* numeroCliente,char* idProblema,char* solucionado)
{
    eLlamada* unaLlamada=NULL;
    if((idLlamada!=NULL) && (fecha!=NULL) && (numeroCliente!=NULL) && (idProblema!=NULL) && (solucionado!=NULL))
    {
        unaLlamada=llamada_nuevollamada();
        if(unaLlamada!=NULL)
        {
            if(!llamada_setIdLlamada(unaLlamada,atoi(idLlamada)) || !llamada_setFecha(unaLlamada,fecha) || !llamada_setNumeroCliente(unaLlamada,atoi(numeroCliente)) || !llamada_setIdProblema(unaLlamada,atoi(idProblema)) || !llamada_setSolucionado(unaLlamada,solucionado))
            {
                llamada_borrarllamada(unaLlamada);
                unaLlamada=NULL;
            }
        }
    }
    return unaLlamada;
}
int llamada_setIdLlamada(eLlamada* llamada,int idLlamada)
{
    int retorno=0;
    if((llamada!=NULL) && (idLlamada > 0))
    {
        llamada->id_Llamada=idLlamada;
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
        llamada->numero_Cliente=numeroCliente;
        retorno=1;
    }
    return retorno;
}
int llamada_setIdProblema(eLlamada* llamada,int idProblema)
{
    int retorno=0;
    if((llamada!=NULL) && (idProblema > 0))
    {
        llamada->id_Problema=idProblema;
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
        *idLlamada=llamada->id_Llamada;
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
        *numeroCliente=llamada->numero_Cliente;
        retorno=1;
    }
    return retorno;
}
int llamada_getIdProblema(eLlamada* llamada,int* idProblema)
{
    int retorno=0;
    if(llamada!=NULL && idProblema!=NULL)
    {
        *idProblema=llamada->id_Problema;
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
/*
int leerFecha(char* fechaStr)
{
    int sePudo=0;
    int len=strlen(fechaStr);
    int i;

    char dia[50];
    int contDia = 0;
    char mes[50];
    int contMes = 0;
    char anio[50];
    int contAnio = 0;


    for(i=0;i<len;i++)
    {

        if(fechaStr[i] != '/' && i <= contDia)
        {
            contDia++;
            dia[i] fechaStr i
            //strcpy(dia, fechaStr[i]);
        }

        if(len < 2)
        {
            fecha.dia=atoi(fechaStr[i]);
        }
        else if(len > 2 && len < 5)
        {
            fecha.mes=atoi(fechaStr[i]);
        }
        else if(len > 5)
        {
            fecha.anio=atoi(fechaStr[i]);
        }
    }

    printf("%s", dia);
    return sePudo;
}
*/
int llamada_filtrarPorProblema(void* unaLlamada, int id_problema)
{
    int filtro=0;
    if(unaLlamada!=NULL)
    {
        eLlamada* llamada=(eLlamada*)unaLlamada;
        if(llamada->id_Problema==id_problema)
        {
            filtro=1;
        }
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
