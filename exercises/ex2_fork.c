#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  int val = 5;
  if (fork())
    wait(&val);
  else
    return val;
  val++;
  printf("%d", val);
  return val;
}