#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void mostrarArray(int parametroArray[], int cant);
void inicializarArray(int parametroArray[], int cant,int inicializacion);
void cargarArray(char mensaje[],int parametroArray[], int cant);
int dameElMaximo(int parametroArray[],int cant);
void dameElIndiceMaximo(int parametroArray[],int cant, int outArrayIndices[]);
void ordenarDesc(int parametroArray[],int cant);
void ordenarAsc(int parametroArray[],int cant);


#endif // FUNCIONES_H_INCLUDED
