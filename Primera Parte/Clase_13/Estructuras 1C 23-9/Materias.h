#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED
typedef struct
{
    int estadoMateria;
    int idMateria;
    char descripcion[51];
    int cargaHoraria;
} eMateria;

void harcodearMaterias(eMateria listaMaterias[],int tamMaterias);
void mostrarMaterias(eMateria listaMaterias[],int tamMaterias);
void mostrarUnaMateria(eMateria unaMateria[],int indiceMateria);
int buscarMateriaLibre(eMateria listaMaterias[], int tamMaterias);

#endif // MATERIAS_H_INCLUDED
