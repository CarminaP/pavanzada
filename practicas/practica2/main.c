#include <stdio.h>
#include "operations.h"
#include "messages.h"

#define MAX_STRING_LENG 100
#define LANG "en"

typedef struct {
  char *operationName;
  int(* operation) (int,int);
} Operation;

int main()
{
  char operation[MAX_STRING_LENG];
  int operatorOne, operatorTwo;
  char **messages;

  if (!strcmp(LANG, "en"))
  {
    messages = message_EN;
  }

  if (!strcmp(LANG, "es"))
  {
    messages = message_ES;
  }

  printf("%s\n", messages[0]);
  scanf("%s", operation);
  scanf("%d %d",&operatorOne, &operatorTwo);

  if (!strcmp(operation, "add"))
  {
    printf("%s: %d\n", message[2], add(operatorOne,operatorTwo));
  }
  else if (!strcmp(operation, "substraction"))
  {
    printf("%s: %d\n", message[2], substraction(operatorOne,operatorTwo));
  }
  else{
    printf("%s\n", messages[1]);
  }

  return 0;
}
