#include <stdio.h>
#include <stdlib.h> //malloc

void findAnagramMap(int *a, int *b, int *p, int size)
{
    int i,j;
for (i = 0; i < size; i++) {
  for (j = 0; j < size; j++) {
    if( b[j] == a[i] ){
      p[i] = j;
      b[j] = -1;
    }
  }
 }
}

int main(){
  int a[] = {12, 28, 46, 32, 50};
  int b[] = {50, 12, 32, 46, 28};
  int size = sizeof(a)/sizeof(a[0]);
  int p[size];
  int i;
  findAnagramMap(a, b, p, size);
  printf("[");
  for (i = 0; i < size-1; i++) {
    printf("%i,",p[i]);
  }
  printf("%i]\n",p[size-1]);
  free(p);
  return 0;
}
