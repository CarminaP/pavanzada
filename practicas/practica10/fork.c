#include <stdio.h>
#include <unistd.h>

int int main() {
  int pid;

  pid = fork();
  if(pid == 0){
    execl("/bin/echo", "echo", "test2", NULL);
  } else {
    printf("2\n");
  }
  return 0;
}
