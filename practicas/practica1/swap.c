#include <stdio.h>

//esta funcion no funciona en C por su paso por valor
int swap_no(int a, int b){
  int t;
  t = a;
  a = b;
  b = t;
  return 0;
}

int swap(int *a, int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
  return 0;
}

int main(){
  int j = 27, k = 34;

  swap_no(j,k);
  printf("j = %d, k = %d \n", j, k);

  swap(&j,&k);
  printf("j = %d, k = %d \n", j, k);
  return 0;
}

/*RESULTADO
j = 27, k = 34
j = 34, k =27
*/
