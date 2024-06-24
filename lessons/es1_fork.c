#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
  pid_t res; // pid_t in UNIX è il tipo del PID
  int x = 1;
  res = fork();
  if (res < 0) {
    printf("La fork è fallita.\n");
    exit(-1);
  }
  x++; // istruzione 1
  x = ((res) ? (x - 1) : (x + 8));
  printf("x = %d.\n", x);
  return;
}