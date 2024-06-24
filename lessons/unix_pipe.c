/**
 * Programma di esempio: pipe convenzionali in UNIX.
 * Gagne, Galvin, Silberschatz
 * Operating System Concepts
 **/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
	char write_msg[BUFFER_SIZE] = "Salve";
	char read_msg[BUFFER_SIZE];
	pid_t pid;
	int fd[2];

	/** crea la pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Errore nella creazione della pipe");
		return 1;
	}

	/** crea un nuovo processo */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Errore nella fork");
		return 1;
	}

	if (pid > 0) {  /* processo padre */
		/* chiude l'estremità non utilizzata della pipe */
		close(fd[READ_END]);

		/* scrive nella pipe */
	    write(fd[WRITE_END], write_msg, strlen(write_msg)+1); 

		/* chiude l'estremità di scrittura della pipe */
		close(fd[WRITE_END]);
	}
	else { /* processo figlio */
		/* chiude l'estremità non utilizzata della pipe */
		close(fd[WRITE_END]);

		/* legge dalla pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("Lettura del figlio %s\n",read_msg);

		/* chiude l'estremità di lettura della pipe */
		close(fd[READ_END]);
	}

	return 0;
}