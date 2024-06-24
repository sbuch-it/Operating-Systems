#include <stdio.h>
#include <unistd.h>

int main() {
  const int SIZE = 4096;
  // dimensione, in byte, del segmento di memoria condivisa
  const char *name = "OS";
  // nome del segmento di memoria condivisa
  int shm_fd;
  // descrittore del file di memoria condivisa
  void *ptr;
  // puntatore al segmento di memoria condivisa
  shm_fd = shm_open(name, O_RDONLY, 0666);
  // apre il segmento di memoria condivisa
  ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  // mappa in memoria il segmento di memoria condivisa
  printf("%s", (char *)ptr);
  // legge dal segmento di memoria condivisa e stampa il contenuto
  shm_unlink(name);
  // rimuove il segmento di memoria condivisa
  return 0;
}