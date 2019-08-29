#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[],char cadena[]);
char getNumeroAleatorio(int desde,int hasta, int iniciar);

int validarSoloNumeros(char cadena[]);
int validarSoloLetras(char cadena[]);
int validarAlfaNumericos(char cadena[]);
int validarNumeroTelefono(char cadena[]);

int getStrNumeros(char mensaje[],char unArray[]);
int getStrLetras(char mensaje[],char unArray[]);

void inicializarLegajo(int unArray[],int tam,int valor);
int buscarLugarLibre(int unArray[],int tam,int valorABuscar);








#endif // FUNCIONES_H_INCLUDED
