#include <assert.h>
#include "operations.h"

#define MAX_INT 2147483647
/**
* Use long addition to catch overflow
*/

int add(int a, int b)
{
  //Do the addition and check if there is an overflow
  long c = (long) a + b;

  assert(c <= MAX_INT && c > -MAX_INT);

  return (int)c;
}

int substraction(int d, int e)
{
  //Do the addition and check if there is an overflow
  long f = (long) d - e;

  assert(f <= MAX_INT && f > -MAX_INT);

  return (int)f;
}
