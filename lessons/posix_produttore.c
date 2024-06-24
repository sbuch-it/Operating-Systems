#include <stdio.h>
#include <unistd.h>

int main() {
  const int SIZE = 4096;
  // dimensione, in byte, del segmento di memoria condivisa
  const char *name = "OS";
  // nome del segmento di memoria condivisa
  const char *message0 = "Studiare ";
  const char *message1 = "Sistemi Operativi ";
  const char *message2 = "è divertente!";
  // stringa scritta nella memoria condivisa
  int shm_fd;
  // descrittore del file di memoria condivisa
  void *ptr;
  // puntatore al segmento di memoria condivisa
  shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
  // crea il segmento di memoria condivisa
  ftruncate(shm_fd, SIZE);
  // configura la dimensione del segmento di memoria condivisa
  ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  // mappa in memoria il segmento di memoria condivisa
  sprintf(ptr, "%s", message0);
  ptr += strlen(message0);
  sprintf(ptr, "%s", message1);
  ptr += strlen(message1);
  sprintf(ptr, "%s", message2);
  // scrive sul segmento di memoria condivisa
  return 0;
}