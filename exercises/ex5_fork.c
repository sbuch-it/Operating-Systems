#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  int i;
  for (i = 0; i < 3; i++) {
    if (fork() && (i == 1)) {
      break;
    }
  }
  return 0;
}