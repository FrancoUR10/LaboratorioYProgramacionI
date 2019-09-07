#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int main()
{
    char arrayNombres[MAX][256]={"E","C","A","C","A"};
    int arraySector[MAX]={4,3,1,2,5};


    int i;
    int j;
    char auxNombres[MAX];
    int auxSector;
    for(i=0;i<MAX-1;i++)
    {
        for(j=i+1;j<MAX;j++)
        {
            if(strcmp(arrayNombres[i],arrayNombres[j])==1)
            {
                strcpy(auxNombres,arrayNombres[i]);
                strcpy(arrayNombres[i],arrayNombres[j]);
                strcpy(arrayNombres[j],auxNombres);

                auxSector=arraySector[i];
                arraySector[i]=arraySector[j];
                arraySector[j]=auxSector;
            }
            else if(strcmp(arrayNombres[i],arrayNombres[j])==0)
            {
                if(arraySector[i]>arraySector[j])
                {
                    strcpy(auxNombres,arrayNombres[i]);
                    strcpy(arrayNombres[i],arrayNombres[j]);
                    strcpy(arrayNombres[j],auxNombres);

                    auxSector=arraySector[i];
                    arraySector[i]=arraySector[j];
                    arraySector[j]=auxSector;

                }
            }
        }
    }
    for(i=0;i<MAX;i++)
    {
        printf("%s:%d--",arrayNombres[i],arraySector[i]);
    }





    return 0;
}
