#include "Producto.h"

eProducto* producto_nuevoProducto()
{
    eProducto* unproducto=(eProducto*)malloc(sizeof(eProducto));
    if(unproducto!=NULL)
    {
        unproducto->codigo=-1;
        strcpy(unproducto->descripcion,"VACIO");
        unproducto->cantidad=-1;
        unproducto->importe=-1;
        unproducto->activo=-1;
    }
    return unproducto;
}
int producto_borrarProducto(eProducto* producto)
{
    int seLibero=0;
    if(producto!=NULL)
    {
        free(producto);
        seLibero=1;
    }
    return seLibero;
}
int producto_setCodigo(eProducto* producto,int codigo)
{
    int retorno=0;
    if((producto!=NULL) && (codigo > 0))
    {
        producto->codigo=codigo;
        retorno=1;
    }
    return retorno;
}
int producto_setDescripcion(eProducto* producto,char* descripcion)
{
    int retorno=0;
    if((producto!=NULL) && (strlen(descripcion) > 0))
    {
        strcpy(producto->descripcion,descripcion);
        retorno=1;
    }
    return retorno;
}
int producto_setCantidad(eProducto* producto,int cantidad)
{
    int retorno=0;
    if((producto!=NULL) && (cantidad > 0))
    {
        producto->cantidad=cantidad;
        retorno=1;
    }
    return retorno;
}
int producto_setImporte(eProducto* producto,float importe)
{
    int retorno=0;
    if((producto!=NULL) && (importe > 0))
    {
        producto->importe=importe;
        retorno=1;
    }
    return retorno;
}
int producto_getCodigo(eProducto* producto,int* codigo)
{
    int retorno=0;
    if(producto!=NULL && codigo!=NULL)
    {
        *codigo=producto->codigo;
        retorno=1;
    }
    return retorno;
}
int producto_getDescripcion(eProducto* producto,char* descripcion)
{
    int retorno=0;
    if(producto!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,producto->descripcion);
        retorno=1;
    }
    return retorno;
}
int producto_getCantidad(eProducto* producto,int* cantidad)
{
    int retorno=0;
    if(producto!=NULL && cantidad!=NULL)
    {
        *cantidad=producto->cantidad;
        retorno=1;
    }
    return retorno;
}
int producto_getImporte(eProducto* producto,float* importe)
{
    int retorno=0;
    if(producto!=NULL && importe!=NULL)
    {
        *importe=producto->importe;
        retorno=1;
    }
    return retorno;
}
eProducto* producto_nuevoProductoParametros(char* codigo,char* descripcion,char* cantidad,char* importe)
{
    eProducto* unproducto=NULL;
    if((codigo!=NULL) && (descripcion!=NULL) && (cantidad!=NULL) && (importe!=NULL))
    {
        unproducto=producto_nuevoProducto();
        if(unproducto!=NULL)
        {
            if(!producto_setCodigo(unproducto,atoi(codigo)) || !producto_setDescripcion(unproducto,descripcion) || !producto_setCantidad(unproducto,atoi(cantidad)) || !producto_setImporte(unproducto,atof(importe)))
            {
                producto_borrarProducto(unproducto);
                unproducto=NULL;
            }
        }
    }
    return unproducto;
}
int producto_compararPorDescripcion(void* producto1,void* producto2)
{
    int comparacion=-1;
    char descripcion1[256];
    char descripcion2[256];
    eProducto* pro1=(eProducto*)producto1;
    eProducto* pro2=(eProducto*)producto2;
    producto_getDescripcion(pro1,descripcion1);
    producto_getDescripcion(pro2,descripcion2);
    if(strcmp(descripcion1,descripcion2)==1)
    {
        comparacion=1;
    }
    else if(strcmp(descripcion1,descripcion2)==0)
    {
        comparacion=0;
    }
    return comparacion;
}
int producto_mostrarUnProducto(eProducto* unproducto)
{
    int seMostro=0;
    if(unproducto!=NULL)
    {
        printf("\n%d",unproducto->codigo);
        printf("%16s",unproducto->descripcion);
        printf("%14d",unproducto->cantidad);
        printf("%14.2f\n",unproducto->importe);
        seMostro=1;
    }
    return seMostro;
}
void producto_mostrarListaProductos(LinkedList* listaProductos)
{
    int indiceEncontrado;
    eProducto* aux;
    int i;
    int len=ll_len(listaProductos);
    if(listaProductos!=NULL)
    {
        indiceEncontrado=producto_buscarPorEstado(listaProductos,ACTIVO);
        if(listaProductos!=NULL && (indiceEncontrado==-1 || ll_isEmpty(listaProductos)==1))
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            printf("\nCODIGO    DESCRIPCION     CANTIDAD    IMPORTE\n");
            for(i=0;i<len;i++)
            {
                aux=(eProducto*)ll_get(listaProductos,i);
                if(aux->activo==ACTIVO)
                {
                    producto_mostrarUnProducto(aux);
                }
            }
        }
    }
}
int producto_buscarPorCodigo(LinkedList* listaproductos,int codigoABuscar)
{
    int retorno=-1;
    eProducto* aux;
    int i;
    int len=ll_len(listaproductos);
    if(listaproductos!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eProducto*)ll_get(listaproductos,i);
            if(aux->activo==ACTIVO && aux->codigo==codigoABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int producto_buscarPorEstado(LinkedList* listaproductos,int estadoABuscar)
{
    int retorno=-1;
    eProducto* aux;
    int i;
    int len=ll_len(listaproductos);
    if(listaproductos!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eProducto*)ll_get(listaproductos,i);
            if(aux->activo==estadoABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int producto_darDeAlta(LinkedList* listaproductos,int* contAltas)
{
    int sePudo=-1;
    int confirmacion;
    int auxCodigoInt;
    char auxCodigoStr[256];
    char auxDescripcion[256];
    char auxCantidadStr[256];
    char auxImporteStr[256];
    auxCodigoInt=*contAltas;
    eProducto* auxDatos=NULL;
    int ingresoSecuencialValido=1;
    if(listaproductos!=NULL)
    {
        if(!getStrLetras("\nIngrese la descripcion: ",auxDescripcion,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese la cantidad: ",auxCantidadStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y el 2000\n",1,2000,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumerosFlotantes("\nIngrese el importe: ",auxImporteStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre el 80 y el 2000\n",20,2000,3))
        {
            ingresoSecuencialValido=0;
        }

        if(ingresoSecuencialValido==1)
        {
            confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
            if(confirmacion==1)
            {
                itoa(auxCodigoInt,auxCodigoStr,10);
                *contAltas=auxCodigoInt+1;
                auxDatos=producto_nuevoProductoParametros(auxCodigoStr,auxDescripcion,auxCantidadStr,auxImporteStr);
                auxDatos->activo=ACTIVO;
                ll_add(listaproductos,auxDatos);
                printf("\nSe ha dado de alta al codigo numero %d\n",auxCodigoInt);
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
int producto_darDeBajaLogica(LinkedList* listaproductos)
{
    eProducto* auxDato=NULL;
    int sePudo=-1;
    int confirmacion;
    int indiceResultadoBusqueda;
    char auxCodigoStr[256];
    int auxCodigoInt;
    int indiceEncontrado;
    indiceEncontrado=producto_buscarPorEstado(listaproductos,ACTIVO);
    if(listaproductos!=NULL && (indiceEncontrado==-1 || ll_isEmpty(listaproductos)==1))
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        producto_mostrarListaProductos(listaproductos);
        if(getStrNumerosSinRango("\nIngrese el codigo a dar de baja: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceResultadoBusqueda=producto_buscarPorCodigo(listaproductos,auxCodigoInt);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    auxDato=(eProducto*)ll_get(listaproductos,indiceResultadoBusqueda);
                    auxDato->activo=NO_ACTIVO;
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
int producto_darDeBajaFisica(LinkedList* listaproductos)
{
    int sePudo=-1;
    int confirmacion;
    int indiceResultadoBusqueda;
    char auxCodigoStr[256];
    int auxCodigoInt;
    int indiceEncontrado;
    indiceEncontrado=producto_buscarPorEstado(listaproductos,ACTIVO);
    if(listaproductos!=NULL && (indiceEncontrado==-1 || ll_isEmpty(listaproductos)==1))
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        producto_mostrarListaProductos(listaproductos);
        if(getStrNumerosSinRango("\nIngrese el codigo a dar de baja: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceResultadoBusqueda=producto_buscarPorCodigo(listaproductos,auxCodigoInt);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    ll_remove(listaproductos,indiceResultadoBusqueda);
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
int producto_modificarDatos(LinkedList* listaproductos)
{
    int sePudo=-1;
    int indiceResultadoBusqueda;
    char auxCodigoStr[256];
    int auxCodigoInt;
    int indiceEncontrado;
    indiceEncontrado=producto_buscarPorEstado(listaproductos,ACTIVO);
    if(listaproductos!=NULL && (indiceEncontrado==-1 || ll_isEmpty(listaproductos)==1))
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        producto_mostrarListaProductos(listaproductos);
        if(getStrNumerosSinRango("\nIngrese el codigo a modificar: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceResultadoBusqueda=producto_buscarPorCodigo(listaproductos,auxCodigoInt);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                producto_pedirDatosAModificar(listaproductos,indiceResultadoBusqueda);
                sePudo=1;
            }
        }
        if(sePudo==-1)
        {
            printf("\nModificacion cancelada\n");
        }
    }
    return sePudo;
}
void producto_pedirDatosAModificar(LinkedList* listaproductos,int indiceEncontrado)
{
    int confirmacion;
    int flagDatoIngresado=0;
    char auxCantidadStr[256];
    char auxImporteStr[256];
    eProducto* datosActuales=(eProducto*)ll_get(listaproductos,indiceEncontrado);
    eProducto auxDatos=*datosActuales;
    eProducto* proximosDatos=NULL;
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("\nCODIGO    DESCRIPCION     CANTIDAD    IMPORTE\n");
        printf("\nDatos actuales seleccionados:\n");
        producto_mostrarUnProducto(datosActuales);
        printf("\nDatos a modificar:\n");
        producto_mostrarUnProducto(&auxDatos);

        printf("\nQue datos desea modificar?\n");
        printf("1-DESCRIPCION\n");
        printf("2-CANTIDAD\n");
        printf("3-IMPORTE\n");
        printf("4-CONFIRMAR CAMBIOS\n");
        printf("5-FINALIZAR MODIFICACION\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese la descripcion: ",auxDatos.descripcion,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
                {
                    printf("\nSe ha ingresado la descripcion\n");
                    flagDatoIngresado=1;
                }
                system("pause");
                break;
            case 2:
                if(getStrNumeros("\nIngrese la cantidad: ",auxCantidadStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y el 2000\n",1,2000,3))
                {
                    auxDatos.cantidad=atoi(auxCantidadStr);
                    printf("\nSe ha ingresado la cantidad\n");
                    flagDatoIngresado=1;
                }
                system("pause");
                break;
            case 3:
                if(getStrNumerosFlotantes("\nIngrese el importe: ",auxImporteStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre el 80 y el 2000\n",20,2000,3))
                {
                    auxDatos.importe=atof(auxImporteStr);
                    printf("\nSe ha ingresado el importe\n");
                    flagDatoIngresado=1;
                }
                system("pause");
                break;
            case 4:
                if(flagDatoIngresado==1)
                {
                    confirmacion=confirmarCambios("\nDesea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        proximosDatos=producto_nuevoProducto();
                        if(proximosDatos!=NULL)
                        {
                            *proximosDatos=auxDatos;
                            ll_set(listaproductos,indiceEncontrado,proximosDatos);
                            datosActuales=(eProducto*)ll_get(listaproductos,indiceEncontrado);
                            printf("\nSe han confirmado los cambios realizados\n");
                            flagDatoIngresado=0;
                        }
                    }
                }
                else
                {
                    printf("\nNo se ha realizado ningun cambio que confirmar\n");
                }
                system("pause");
                break;
            case 5:
                if(flagDatoIngresado==1)
                {
                    confirmacion=confirmarCambios("\nEsta seguro que desea salir sin confirmar cambios? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        printf("\nModificacion finalizada sin confirmar cambios\n");
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
int producto_guardarDatos(FILE* archivo,LinkedList* listaproductos,int* contAltas)
{
    int sePudo=-1;
    int i;
    int len=ll_len(listaproductos);
    eProducto* auxDatos;
    int indiceEncontrado;
    indiceEncontrado=producto_buscarPorEstado(listaproductos,ACTIVO);
    if(listaproductos!=NULL && (indiceEncontrado==-1 || ll_isEmpty(listaproductos)==1))
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        archivo=fopen("datos.csv","wb");
        if(archivo!=NULL)
        {
            fwrite(contAltas,sizeof(int),1,archivo);
            for(i=0;i<len;i++)
            {
                auxDatos=ll_get(listaproductos,i);
                fwrite(auxDatos,sizeof(eProducto),1,archivo);
            }
            fclose(archivo);
            printf("\nSe han guardado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int producto_cargarDatos(FILE* archivo,LinkedList* listaproductos,int* contAltas)
{
    int sePudo=-1;
    eProducto* auxDatos;
    {
        archivo=fopen("datos.csv","rb");
        if(archivo!=NULL)
        {
            fread(contAltas,sizeof(int),1,archivo);
            ll_clear(listaproductos);
            while(!feof(archivo))
            {
                auxDatos=producto_nuevoProducto();
                if(auxDatos!=NULL)
                {
                    fread(auxDatos,sizeof(eProducto),1,archivo);
                    if(feof(archivo))
                    {
                        break;
                    }
                    ll_add(listaproductos,auxDatos);
                }
            }
            fclose(archivo);
            printf("\nSe han cargado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
void producto_informarDatos(LinkedList* listaProductos)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("1-LISTA DE PRODUCTOS\n");
        printf("2-LISTA DE PRODUCTOS NO ACTIVOS\n");
        printf("3-SALIR DEL SUBMENU\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                ll_sort(listaProductos,producto_compararPorDescripcion,1);
                producto_mostrarListaProductos(listaProductos);
                system("pause");
                break;
            case 2:
                ll_sort(listaProductos,producto_compararPorDescripcion,1);
                producto_mostrarListaProductosNoActivos(listaProductos);
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
void producto_mostrarListaProductosNoActivos(LinkedList* listaProductos)
{
    int indiceEncontrado;
    eProducto* aux;
    int i;
    int len=ll_len(listaProductos);
    if(listaProductos!=NULL)
    {
        indiceEncontrado=producto_buscarPorEstado(listaProductos,NO_ACTIVO);
        if(listaProductos!=NULL && (indiceEncontrado==-1 || ll_isEmpty(listaProductos)==1))
        {
            printf("\nNo hay ningun elemento no activo en la lista\n");
        }
        else
        {
            printf("\nCODIGO    DESCRIPCION     CANTIDAD    IMPORTE\n");
            for(i=0;i<len;i++)
            {
                aux=(eProducto*)ll_get(listaProductos,i);
                if(aux->activo==NO_ACTIVO)
                {
                    producto_mostrarUnProducto(aux);
                }
            }
        }
    }
}
