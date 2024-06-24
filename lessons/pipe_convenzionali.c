#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void) {
  char write_msg[BUFFER_SIZE] = "Salve";
  char read_msg[BUFFER_SIZE];
  pid_t pid;
  int fd[2];

  // crea la pipe
  if (pipe(fd) == -1) {
    fprintf(stderr, "Errore nella creazione della pipe");
    return 1;
  }

  // crea un nuovo processo
  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Errore nella fork");
    return 1;
  }

  if (pid > 0) { // processo padre
    close(fd[READ_END]);
    // chiude l'estremità non utilizzata della pipe
    write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
    // scrive nella pipe
    close(fd[WRITE_END]);
    // chiude l'estremità di scrittura della pipe
  } else { // processo figlio
    close(fd[WRITE_END]);
    // chiude l'estremità non utilizzata della pipe
    read(fd[READ_END], read_msg, BUFFER_SIZE);
    // legge dalla pipe
    printf("Lettura del figlio %s\n", read_msg);
    // stampa il messaggio letto dalla pipe
    close(fd[READ_END]);
    // chiude l'estremità di lettura della pipe
  }
  return 0;
}