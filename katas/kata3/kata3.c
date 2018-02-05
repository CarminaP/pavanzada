#include <stdio.h>
#include <string.h>

int judgeRouteCircle(char *moves) {

  int vertical = 0, horizontal = 0, size = strlen(moves);

  for (int i = 0; i < size; i++) {
    switch (moves[i]) {
      case 'U':
        vertical++;
        break;
      case 'D':
        vertical--;
        break;
      case 'R':
        horizontal++;
        break;
      case 'L':
        horizontal--;
        break;
      default:
        printf("Invalid Input\n");
    }
  }

  if(vertical == 0 && horizontal == 0){
    printf("true\n");
  } else {
    printf("false\n");
  }
  return 0;
}

int main(){
  char moves[] = "UDLR";
  judgeRouteCircle(moves);
}
