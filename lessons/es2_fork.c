#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
  int c2 = 0;
  c1 = fork(); // fork 1
  if (c1 == 0)
    c2 = fork(); // fork 2
  fork(); // fork 3
  if (c2 > 0)
    fork(); // fork 4
}