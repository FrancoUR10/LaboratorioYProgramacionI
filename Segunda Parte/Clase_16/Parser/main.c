#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Parseo o split.
//Setter y geter.
typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    float salario;
}eEmpleado;

eEmpleado* new_Empleado();

int main()
{
    int i=0;
    eEmpleado* lista[50];
    eEmpleado* unEmpleado;
    FILE* pArchivo;
    char legajo[20];
    char nombre[20];
    char apellido[20];
    char salario[20];
    pArchivo=fopen("empleado.csv","r");
    fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,salario);
    while(!feof(pArchivo))
    {
        while(feof(pArchivo))
        {
            break;
        }
        unEmpleado=new_Empleado();
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,salario);
        unEmpleado->legajo=atoi(legajo);
        unEmpleado->salario=atof(salario);
        strcpy(unEmpleado->nombre,nombre);
        strcpy(unEmpleado->apellido,apellido);
        *(lista+i)=unEmpleado;
        i++;
    }
    fclose(pArchivo);
    for(i=0;i<50;i++)
    {
        printf("%d--%s--%s--%.2f\n",(*(lista+i))->legajo,(*(lista+i))->nombre,(*(lista+i))->apellido,(*(lista+i))->salario);
    }
    return 0;
}
eEmpleado* new_Empleado()
{
    eEmpleado* unEmpleado;
    unEmpleado=(eEmpleado*)malloc(sizeof(eEmpleado));
    return unEmpleado;
}
