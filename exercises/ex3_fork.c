#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  printf("Hello, ");
  fork();
  printf("bye ");
  return 0;
}