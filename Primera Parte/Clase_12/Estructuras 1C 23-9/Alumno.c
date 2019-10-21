#include "Alumno.h"

int buscarLibre(eAlumno listadoDeAlumnos[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int legajo[]= {101,102,105};
    float promedio[]= {6.66, 4,7.66};
    char nombre[][25]= {"Juan","Maria josefina","Maria"};
    int localidad[]={1,2,2};
    for(i=0; i<3; i++)
    {
        listadoDeAlumnos[i].legajo = legajo[i];
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].nombre, nombre[i]);
        listadoDeAlumnos[i].estado = OCUPADO;
        listadoDeAlumnos[i].idLocalidad=localidad[i];

    }
}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam,eLocalidad listadoLocalidad [],int tamLocalidad)
{
    int i;
    int indiceBusqueda;
    int auxId;

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            auxId=listadoDeAlumnos[i].idLocalidad;
            indiceBusqueda=buscarUnaLocalidad(listadoLocalidad,tamLocalidad,auxId);
            if(indiceBusqueda!=-1)
            {
                //mostrarUnAlumno(listadoDeAlumnos,listadoLocalidad,i,indiceBusqueda);
                printf("\n%d %s %.2f %s\n",listadoDeAlumnos[i].legajo,listadoDeAlumnos[i].nombre,listadoDeAlumnos[i].promedio,listadoLocalidad[indiceBusqueda].localidad);
            }
        }

    }
}

void cargarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int indice;

    indice = buscarLibre(listadoDeAlumnos, tam);
    printf("Indice: %d\n", indice);
    if(indice!=-1)
    {
        //hay lugar
        listadoDeAlumnos[indice] = cargarAlumno();
    }
    else
    {
        printf("No hay espacio disponible");
    }

}

eAlumno cargarAlumno(void)
{
    eAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);
    printf("En que localidad vive?");
    scanf("%d", &miAlumno.idLocalidad);


    miAlumno.estado = OCUPADO;

    return miAlumno;
}
void mostrarUnAlumno(eAlumno miAlumno[], eLocalidad suLocalidad[],int indice,int indiceLocalidad)
{
    printf("%04d %25s %8.2f %25s\n",miAlumno[indice].legajo,miAlumno[indice].nombre, miAlumno[indice].promedio,suLocalidad[indiceLocalidad].localidad);
}

void sortStudentsByNameAndAverage(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0)
            {
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }

            else
            {
                if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)==0)
                {
                    if(listadoDeAlumnos[i].promedio>listadoDeAlumnos[j].promedio)
                    {
                        auxAlumno = listadoDeAlumnos[i];
                        listadoDeAlumnos[i] = listadoDeAlumnos[j];
                        listadoDeAlumnos[j] = auxAlumno;
                    }
                }
            }
        }

    }
}


int buscarAlumnoPorLegajo(eAlumno* listaDeAlumnos, int cant, int legajo)
{
    int i;
    int retorno = -1;


    if(listaDeAlumnos!=NULL && cant>0)
    {

     for(i=0; i<cant; i++)
    {
        if(listaDeAlumnos[i].legajo==legajo && listaDeAlumnos[i].estado==OCUPADO)
        {
            retorno = i;
            break;
        }
    }
    }


    return retorno;
}

int modificarAlumno(eAlumno listaDeAlumnos[], int cant, int legajo)
{
    int index;
    //char nombre[30];
    int quePaso = -1;
    char respuesta;
    eAlumno aux;

    index = buscarAlumnoPorLegajo(listaDeAlumnos,cant, legajo);
    if(index!=-1)
    {
        aux = listaDeAlumnos[index];
        //mostrarUnAlumno(aux);
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        gets(aux.nombre);
        printf("Esta seguro que desea modificar este alumno? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            listaDeAlumnos[index] = aux;
            quePaso = 1;
        }
        else
        {
            quePaso = 0;
        }

    }
    return quePaso;
}
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam)
{
    int legajo;
    int i;
    //int flag = 0 ;
    char respuesta;

    int quePaso = -1;

    //mostrarListadoAlumnos(listadoDeAlumnos,tam);

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].legajo==legajo && listadoDeAlumnos[i].estado==OCUPADO)
        {
            //mostrarUnAlumno(listadoDeAlumnos[i]);
            printf("Esta seguro que desea eliminar este alumno? :");
            respuesta = getche();
            if(respuesta=='s')
            {
                listadoDeAlumnos[i].estado = LIBRE;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
            break;
        }

    }

    return quePaso;

}
int buscarUnaLocalidad(eLocalidad listaLocalidades[], int tam,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(listaLocalidades[i].idLocalidad==idABuscar)
        {
            retorno=i;
        }
    }
    return retorno;
}
void mostrarSoloLocalidad(eLocalidad listaLocalidad[],int tamLocalidad)
{
    int i;
    for(i=0;i<tamLocalidad;i++)
    {
        printf("%s\n",listaLocalidad[i].localidad);
    }
}
int buscarLocalidadDelAlumno(eAlumno listaAlumno[],int tamAlumno,int idLocalidadBusqueda)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamAlumno;i++)
    {
        if((listaAlumno[i].estado==OCUPADO) && (listaAlumno[i].idLocalidad==idLocalidadBusqueda))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
/*
int buscarElMinimo(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad,eAuxLocalidad contadorAlumnos[])
{
    int i;
    int minimo;
    int flagPrimerAlumno=1;
    contarCantAlumnos(listaAlumnos,tamAlumnos,listaLocalidad,tamLocalidad,contadorAlumnos);
    for(i=0;i<tamLocalidad;i++)
    {
        if((flagPrimerAlumno==1) || (contadorAlumnos[i].cantAlumnos < minimo))
        {
            minimo=contadorAlumnos[i].idLocalidad;
            flagPrimerAlumno=0;
        }
    }
    return minimo;
}
*/
/*
void mostrarLocalidadConMenosAlumnos(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad,eAuxCont contadorAlumnos[])
{
    int i;
    int j;
    int elMinimo;
    elMinimo=buscarElMinimo(listaAlumnos,tamAlumnos,listaLocalidad,tamLocalidad,contadorAlumnos);
    for(i=0;i<tamLocalidad;i++)
    {
        for(j=0;j<tamLocalidad;j++)
        {
            if((listaLocalidad[j].idLocalidad==contadorAlumnos[i].idLocalidad) && (elMinimo==contadorAlumnos[i].idLocalidad))
            {
                printf("%s\n",listaLocalidad[j].localidad);
            }
        }
    }
}
*/
void contarCantDeAlumnos(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidades[],int tamLocalidades,eAuxLocalidad auxliliarLocalidad[])
{
    int i;
    int j;
    for(i=0;i<tamLocalidades;i++)
    {
        auxliliarLocalidad[i].idLocalidad=listaLocalidades[i].idLocalidad;
        auxliliarLocalidad[i].cantAlumnos=0;
    }
    for(i=0;i<tamLocalidades;i++)
    {
        for(j=0;j<tamAlumnos;j++)
        {
            if((listaAlumnos[j].estado==OCUPADO) && (auxliliarLocalidad[i].idLocalidad==listaAlumnos[j].idLocalidad))
            {
                auxliliarLocalidad[i].cantAlumnos++;
            }
        }
    }
}
int dameElMinimo(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidades[],int tamLocalidad,eAuxLocalidad auxiliarLocalidades[])
{
    int elMinimo;
    int flagPrimerDato=1;
    int i;
    contarCantDeAlumnos(listaAlumnos,tamAlumnos,listaLocalidades,tamLocalidad,auxiliarLocalidades);
    for(i=0;i<tamLocalidad;i++)
    {
        if((flagPrimerDato==1) || (auxiliarLocalidades[i].cantAlumnos < elMinimo))
        {
            elMinimo=auxiliarLocalidades[i].cantAlumnos;
            flagPrimerDato=0;
        }
    }
    return elMinimo;
}
void mostrarLocalidadConMenosAlumnos(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidades[],int tamLocalidades,eAuxLocalidad auxLocalidad[])
{
    int i;
    int j;
    int elMinimo;
    contarCantDeAlumnos(listaAlumnos,tamAlumnos,listaLocalidades,tamLocalidades,auxLocalidad);
    elMinimo=dameElMinimo(listaAlumnos,tamAlumnos,listaLocalidades,tamLocalidades,auxLocalidad);
    for(i=0;i<tamLocalidades;i++)
    {
        for(j=0;j<tamLocalidades;j++)
        {
            if((listaLocalidades[i].idLocalidad==auxLocalidad[j].idLocalidad) && (auxLocalidad[j].cantAlumnos==elMinimo))
            {
                printf("%s\n",listaLocalidades[i].localidad);
            }
        }
    }
}
void mostrarCadaLocalidadConSusAlumnos(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad)
{
    int i;
    int j;
    for(i=0;i<tamLocalidad;i++)
    {
        printf("Localidad: %s\n",listaLocalidad[i].localidad);
        for(j=0;j<tamAlumnos;j++)
        {
            if((listaAlumnos[j].estado==OCUPADO) && (listaAlumnos[j].idLocalidad==listaLocalidad[i].idLocalidad))
            {
                mostrarUnAlumno(listaAlumnos,listaLocalidad,j,i);
            }
        }
    }
}
void mostrarAlumnosEnAvellaneda(eAlumno listaAlumnos[],int tamAlumnos,eLocalidad listaLocalidad[],int tamLocalidad)
{
    int i;
    int j;
    for(i=0;i<tamLocalidad;i++)
    {
        for(j=0;j<tamAlumnos;j++)
        {
            if((listaAlumnos[j].estado==OCUPADO) && (listaAlumnos[j].idLocalidad==listaLocalidad[i].idLocalidad) && (listaLocalidad[i].idLocalidad==1))
            {
                mostrarUnAlumno(listaAlumnos,listaLocalidad,j,i);
            }
        }
    }
}
