#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s=0;
    int arreglo[4];
    for (int i = 0; i < 4; i++)
    {
        arreglo[i]=s++;
    }
    int arreglo2[4];
    for (int i = 0; i < 4; i++)
    {
        arreglo2[i]=s++;
    }
    *arreglo=*arreglo+*arreglo2;
    printf("\npi: %2i  %2i  %2i  %2i \n",arreglo[0],arreglo[1],arreglo[2], arreglo[3]);
}