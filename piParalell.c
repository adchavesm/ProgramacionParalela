#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>


#define ITERATIONS 2e09
#define THREADS 16

int calculatePi(double *piTotal ,int ID){
    int start, end;
    start= (ITERATIONS/omp_get_num_threads())*ID;
    end= (ITERATIONS/omp_get_num_threads())*(ID+1);
    int i=start;
    while(i < end-2){
        *(piTotal+ID)= *(piTotal+ID) + (double) (4.0/((i*2)+1));
        i++;
        *(piTotal+ID)= *(piTotal+ID) - (double) (4.0/((i*2)+1));
        i++;
    }
    return 0;
}

int main()
{
    int i = THREADS;    
    int threads= THREADS;
    double pi[threads];

    struct timeval tval_before, tval_after, tval_result;

    gettimeofday(&tval_before, NULL);

    for(i=0; i< threads;i++){
        pi[i]=0;
    }

    #pragma omp parallel num_threads(threads)
    {
        int ID= omp_get_thread_num();
        calculatePi(pi,ID);
    }

    for ( i = 1; i < threads; i++)
    {
        pi[0]=pi[0]+pi[i];
    }
    gettimeofday(&tval_after, NULL);

    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
    
    
    printf("Valor de pi: %2.20f \n",pi[0]);
    return 0;

}
    