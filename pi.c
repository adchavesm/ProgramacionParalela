#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 2e09

int calculatePi(double *piTotal){
    int i=0;
    do{
        *piTotal = *piTotal + (double)(4.0/((i*2)+1));
        i++;
        *piTotal = *piTotal - (double)(4.0/((i*2)+1));
        i++;
    }while(i<ITERATIONS);
    return 0;
}

int main()
{
    double pi;
    pi=0;
    calculatePi(&pi);
    printf("\npi: %2.20f \n",pi);
}