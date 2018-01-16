#include <stdio.h>
#include <float.h>

int main() {
  int a = 4;
  int j;
  int *p; //apuntador de tipo entero
  float f = 7.5;
  int max = 2147483647;
  long d;
  int b = a + (int)f;
  float c = a * f;
  //arreglos -> tipo de dato + nombre + [tamaño]
  // = {0} -> inicializa todos los valores en 0
  // = {0,2} -> inicializa los dos primeros y los demás en 0
  //nombre de arreglo solo es un apuntador
  int arreglo[5] = {0,2};

  d = (long)max * max;

  p = arreglo;

  for(int k = 0; k < sizeof(arreglo)/sizeof(arreglo[0]); k++){
    //lo mismo que *p++ = 67 pero es dificil de leer
    //lo mismo que arreglo[k] = 67 o p[k] = 67; p +k
    *p = 67;
    p++;
  }

  //char+% indica tipo de dato que va a convertir
  printf(" p = %p, a = %d, j = %d, b = %d, d = %ld \n", p, a, b, d); // %i & %d -> entero
  printf(" f = %f, c = %f, arreglo[1] = %d \n", f, c, arreglo[1]); // %f -> flotante
  return 0;
}
/*RESULTADO con d = max * max;
a = 4, b = 11, d = 1
f = 7.500000, c = 30.000000
*/

/*RESULTADO con d = (long)max * (long)max y d = %ld;
            o  long d = (long)max * max y d = %ld;
a = 4, b = 11, d = 461168601432420609
f = 7.500000, c = 30.000000
*/

/*RESULTADO con a = %p -> pointer -> hexadecimal
a = 0x4, b = 11, d = 461168601432420609
f = 7.500000, c = 30.000000
*/

/*RESULTADO con a = %p, &a -> operador de direccion
            o   p = &a, *p =7 y (p = %p, a = %d,.... , p, a,)
a = 0x60fef8, b = 11, d = 461168601432420609
f = 7.500000, c = 30.000000
*/

/*RESULTADO con int j y j = %d, j
a = 0x60fef8, j = 0, b = 11, d = 461168601432420609
f = 7.500000, c = 30.000000
*/

/*RESULTADO con int arreglo[5] = {0,2}; y *(arreglo + 1) = 250;
a = 0x60fef8, j = 0, b = 11, d = 461168601432420609
f = 7.500000, c = 30.000000, arreglo[1] = 250
*/
