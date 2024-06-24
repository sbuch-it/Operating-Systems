/* programma per il calcolo della somma dei primi n interi */

#include <pthread.h> /* include per la libreria Pthreads */
#include <stdio.h>
#include <stdlib.h>

int sum; /* variabile globale (condivisa) */
void *somma(char *param); /* funzione del nuovo thread */

int main(int argc, char *argv[]) {
  pthread_t tid; /* identificatore del thread */
  pthread_attr_t attr; /* attributi del thread */
  /* dimensione dello stack, informazioni per lo scheduling, etc */
  if (argc != 2) {
    fprintf(stderr, "occorreva inserire N!");
    exit(1);
  }
  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "%d deve essere >=0\n", atoi(argv[1]));
    exit(1);
  }
  pthread_attr_init(&attr); /* reperisce attributi predefiniti */
  pthread_create(&tid,&attr,somma,argv[1]); /* crea il thread */
  /* il padre attende la terminazione del nuovo thread */
  pthread_join(tid, NULL);
  printf("somma = %d\n", sum);
  exit(0);
}

 /* Il nuovo thread assume il controllo da questa funzione */
void *somma(char *param) {
  int i, upper=atoi(param);
  sum = 0;

  for (i=1, i<=upper; i++)
    sum += i;
    
  pthread_exit(0);
}