#include <stdio.h>
#include <stdlib.h>
//Las flechas se usan solamente con las estructuras.
int main()
{
    int* pVec;
    int* aux;
    int i;
    //Equivalentes:

    //int vector[5]; Estatico.

    pVec = (int*) malloc(sizeof(int)*5); //Dinamico.

    if(pVec!=NULL)
    {
        for(i=0;i<5;i++)
        {
            printf("Ingrese un numero:\n");
            scanf("%d",(pVec+i));
            //*(pVec+i)=i+1;
        }
        for(i=0;i<5;i++)
        {
            printf("\n%d\n",*(pVec+i));
        }
        //Para aumentar:
        printf("\nAgrego 5 mas\n");
        aux = (int*) realloc(pVec,sizeof(int)*10);
        if(aux!=NULL)
        {
            pVec = aux;
        }

        for(i=5;i<10;i++)
        {
            printf("\nIngrese un numero: ");
            scanf("%d",(pVec+i));
            //*(pVec+i)=i+1;
        }
        for(i=0;i<10;i++)
        {
            printf("\n%d\n",*(pVec+i));
        }
        //Para disminuir:
        printf("Lo achico\n");
        pVec= (int*) realloc(pVec,sizeof(int)*4);
        for(i=0;i<4;i++)
        {
            printf("\n%d\n",*(pVec+i));
        }

        pVec = (int*) calloc(sizeof(int),5); //Inicializa todos los valores en cero.


    }


    return 0;
}
