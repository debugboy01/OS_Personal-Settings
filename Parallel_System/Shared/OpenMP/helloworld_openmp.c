#include <stdio.h>
#include <omp.h>
int
main(int argc, char *argv[])
{
  int thid;
  omp_set_num_threads(12);
  #pragma omp parallel private(thid)
  {
    thid = omp_get_thread_num();
    printf("Hello, world from thread %d\n",thid);
  }
  return 0;
}

