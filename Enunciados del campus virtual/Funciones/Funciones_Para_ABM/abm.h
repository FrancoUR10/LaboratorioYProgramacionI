#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[],char cadena[]);

int validarSoloNumeros(char cadena[]);
int validarSoloLetras(char cadena[]);

int getStrNumeros(char mensaje[],char unArray[]); // Se requiere utilizar: #include <string.h>
int getStrLetras(char mensaje[],char unArray[]); // Se requiere utilizar: #include <string.h>

void inicializarLegajo(int unArray[],int tam,int valor);
int buscarLugarLibre(int unArray[],int tam,int valorABuscar);



#endif // ABM_H_INCLUDED
