#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  pid_t pid;
  fork();
  fork();
  pid = fork();
  if (!pid)
    printf("Hello world \n");
  return 0;
}