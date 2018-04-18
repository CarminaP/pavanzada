#include <stdio.h>
#include <stdbool.h>

//to return the position of the first zero in a given number
int firstZero(int num) {
  int count = 0;
  //Binary AND Operator copies a bit to the result if it exists in both operands.
  while ((num & 128) != 0) {
    count++;
    //Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand.
    num = num << 1;
  }
  return count > 4 ? -1 : count;
}

bool utf8Validation(int* data) {
  int dataSize = sizeof(data)/sizeof(int);
    int count = 0;
    for(int i = 0; i < dataSize; i++){
      int zero = firstZero(data[i]);
      if (zero == -1){
        //invalid number
        return false;
      }
      else if (zero == 1 && count-- <= 0){
        //more than enough 10 continuations
        return false;
      }
      else if (zero > 1) {
        //not enough 10 continuations
        if (count > 0){
          return false;
        }
        count = zero - 1;
      }
      if (i == dataSize - 1 && count != 0){
        //not enough 10 continuations
        return false;
      }
    }
    return true;
}

int main() {
  int data1[] = {197,130,1};
  bool result = utf8Validation(data1);
  printf("[197,130,1] Result: %s \n", result ? "true" : "false");

  int data2[] = {235,140,4};
  result = utf8Validation(data2);
  printf("[235,140,4] Result: %s \n", result ? "true" : "false");

  return 0;
}
