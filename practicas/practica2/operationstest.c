#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *);
int testAddition(void);
int testSubstraction(void);

int main() {

  // Test add
  printTestMessage(testAddition(),
                   "add test passed",
                   "add test failed");

  //Test substraction
  printTestMessage(testSubstraction(),
                   "substraction test passed",
                   "substraction test failed");

  return 0;
}

void printTestMessage(int condition, char *messagePassed, char *messageFailed)
{
  if(condition)
  {
    printf("%s\n", messagePassed);
  }
  else
  {
    printf("%s\n", messageFailed);
  }
}

int testAddition(void){
  int a = 5;
  int b = -7;

  int result = add(a,b);
  int expected = a + b;
  return result == expected;
}

int testSubstraction(void){
  int c = 10;
  int d = -5;

  int resultSubs = substraction(c,d);
  int expectedSubs = c - d;
  return resultSubs == expectedSubs;
}
