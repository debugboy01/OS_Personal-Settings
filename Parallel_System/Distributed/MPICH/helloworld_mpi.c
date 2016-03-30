#include <stdio.h>
#include <mpi.h>

int
main(int argc, char *argv[])
{
  int rank, size;
  int i;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if(rank==0)
    for(i=0;i<10;i++) printf("el %i proc es %i\n",i,proc_map(i,size,10));
  MPI_Barrier(MPI_COMM_WORLD);
  printf("Hola! Soy el %d de %d\n", rank, size);
  
//  MPI_Get_processor_name(processor_name,&namelen);
//  fprintf(stderr,"Process %d on %s\n",myid, processor_name);
  
  MPI_Finalize();
  return 0;
}
