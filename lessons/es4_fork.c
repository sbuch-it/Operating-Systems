#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int num = 0;

int main(int argc, char **argv) {
  int n, pid;
  n = atoi(*++argv);
  pid = fork();
  printf("%d", num);
  if (pid == 0 && n) {
    num = 3;
  } else if (pid > 0) {
    num = 8;
  }
  printf("%d", num);
}