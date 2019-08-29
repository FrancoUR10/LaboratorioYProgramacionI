#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[],char cadena[]);

int validarSoloNumeros(char cadena[]);
int validarSoloLetras(char cadena[]);

int getStringNumeros(char mensaje[],char cadena[]);
int getStringLetras(char mensaje[],char cadena[]);

void inicializarLegajoArray(int unArray[],int tam,int valor);
int buscarLugarLibre(int unArray[],int tam,int valor);

#endif // ABM_H_INCLUDED
