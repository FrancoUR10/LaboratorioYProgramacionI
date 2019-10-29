#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int contAltas=1;
    int len;
    int i;
    Employee* aux;
    LinkedList* listaEmpleados = ll_newLinkedList();
    pedirDatosSecuenciales(listaEmpleados,&contAltas);
    len=ll_len(listaEmpleados);
    for(i=0;i<len;i++)
    {
        aux=(Employee*)ll_get(listaEmpleados,i);
        mostrarEmpleado(aux);
    }
    /*
    Employee* aux;

    Employee* e1 = employee_newParametros("5","Maria","10","5000");
    Employee* e2 = employee_newParametros("2","Carlos","15","6500");
    Employee* e3 = employee_newParametros("6","Jose","12","6000");
    Employee* e4 = employee_newParametros("7","Juan","7","6");

    int x;
    int len;
    ll_add(listaEmpleados,e1);

    ll_add(listaEmpleados,e2);
    ll_add(listaEmpleados,e3);
    //ll_set(listaEmpleados,1,e4);
    ll_push(listaEmpleados,1,e4);
    //ll_remove(listaEmpleados,1);
    aux=(Employee*)ll_pop(listaEmpleados,1);
    printf("Elimine a este\n");
    mostrarEmpleado(aux);
    printf("\n");
    len=ll_len(listaEmpleados);
    for(x=0;x<len;x++)
    {
        aux=(Employee*)ll_get(listaEmpleados,x);
        mostrarEmpleado(aux);
    }


    ll_clear(listaEmpleados);
    //len=ll_len(listaEmpleados);
    len=ll_isEmpty(listaEmpleados);
    printf("%d",len);
    ll_deleteLinkedList(listaEmpleados);


    printf("\n");
    LinkedList* listaAux=(Employee*)ll_subList(listaEmpleados,0,2);
    len=ll_len(listaAux);
    for(x=0;x<len;x++)
    {
        aux=(Employee*)ll_get(listaAux,x);
        mostrarEmpleado(aux);
    }


    printf("Ordena:\n");
    ll_sort(listaEmpleados,compararPorLegajo,1);
    len=ll_len(listaEmpleados);
    for(x=0;x<len;x++)
    {
        aux=(Employee*)ll_get(listaEmpleados,x);
        mostrarEmpleado(aux);
    }
    */
    return 0;
}
