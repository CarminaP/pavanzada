#include <stdio.h>
#include <omp.h>
// export OMP_NUM_THREADS=400

int main(){
  int tid;
  int gid;
  #pragma omp parallel private(tid) shared(gid)
  {
    tid = omp_get_thread_num();
    gid = tid;
    printf("Hello world\n");
  }
  return 0;
}

//gcc-7 -o openmp.exe openmp.c -fopenmp
