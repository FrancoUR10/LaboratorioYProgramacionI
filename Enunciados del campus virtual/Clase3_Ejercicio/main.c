#include <stdio.h>
#include <stdlib.h>

void muestra(int x,int y);
int main()
{
int x,y;
printf("Ingrese un numero entero");
 scanf("%d",&x);
printf("Ingrese un numero entero");
scanf("%d",&y);
muestra(x,y);
printf("\n-----valores dentro de main----");
printf("\nx vale %d \ny vale %d",x,y);
}
void muestra(int x,int y)
{
x=y;
printf("\n-----valores dentro de la funcion----");
printf("\nx vale %d \ny vale %d",x,y);
}


int utn_getNumero(int* pResultado,
 char* mensaje,
 char* mensajeError,
 int minimo,
 int maximo,
 int reintentos)
 {
 int ret;
 int num;
 while(reintentos>0)
 {
 printf(mensaje);
 if(getInt(&num)==1)
 {
 if(num<=maximo && num>=minimo)
 break;
 }
 fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
 reintentos--;
 printf(mensajeError);
 }
 if(reintentos==0)
 {
 ret=-1;
 }
 else
 {
 ret=0;
 *pResultado = num;
 }
 return ret;
 }


 static int getInt(int* pResultado)
 {
 char buffer[64];
 scanf("%s",buffer);
 *pResultado = atoi(buffer);
 return 1;
 }
