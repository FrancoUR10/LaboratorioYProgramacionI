#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

int esNumerico(char cadena[]);
int esSoloLetras(char cadena[]);
int esAlfaNumerico(char cadena[]);
int esTelefono(char cadena[]);

void getString(char mensaje[], char cadena[]);
int getStringLetras(char mensaje[], char cadena[]);
int getStringNumeros(char mensaje[], char cadena[]);
void inicializarArray(int unArray[], int cantClientes, int valor);
int buscarPrimerOcurrencia(int unArray[], int cantClientes, int valor);

#endif // ABM_H_INCLUDED
