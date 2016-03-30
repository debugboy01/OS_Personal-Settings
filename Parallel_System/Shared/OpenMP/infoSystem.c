#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nhilos, id, procs, maxt, inpar, dynamic, nested;

/* Start parallel region */
#pragma omp parallel private(nhilos, id)
  {

  /* Obtener numero de hilo*/
  id = omp_get_thread_num();

  /* Solo el hilo master corre esto */
  if (id == 0) 
    {
    printf("Hilo %d : sacando info del environment...\n", id);

    /* Info del Environment  */
    procs = omp_get_num_procs();
    nhilos = omp_get_num_threads();
    maxt = omp_get_max_threads();
    inpar = omp_in_parallel();
    dynamic = omp_get_dynamic();
    nested = omp_get_nested();

    /* Print environment information */
    printf("Numero de procesos = %d\n", procs);
    printf("Number of hilos = %d\n", nhilos);
    printf("Max hilos = %d\n", maxt);
    printf("En paralelo? = %d\n", inpar);
    printf("Hilos Dinamicos habilitados? = %d\n", dynamic);
    printf("Paralelismo anidado suportado? = %d\n", nested);

    }

  }  /* fin pragma omp */

}
