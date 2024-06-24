#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

int main(int argc, char *argv[]) {
  int i, scope;
  pthread_t tid[NUM_THREADS];
  pthread_attr_t attr;
  // ottiene gli attributi di default
  pthread_attr_init(&attr);
  // per prima cosa, appura l'ambito della contesa
  if (pthread_attr_getscope(&attr, &scope) != 0) {
    // se restituisce un valore diverso da 0 allora
    // la funzione non è stata eseguita correttamente
    fprintf(stderr, "Impossibile stabilire l'ambito della contesa\n");
  } else {
    if (scope == PTHREAD_SCOPE_PROCESS)
      printf("PTHREAD_SCOPE_PROCESS");
    else if (scope == PTHREAD_SCOPE_SYSTEM)
      printf("PTHREAD_SCOPE_SYSTEM");
    else
      printf(stderr, "Valore non ammesso.\n");
  }
  // imposta l'algoritmo di scheduling a SCS
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  // genera i thread
  for (i = 0; i < NUM_THREADS; i++)
    pthread_create(&tid[i], &attr, runner, NULL);
  // il processo padre aspetta la terminazione di tutti i thread
  for (i = 0; i < NUM_THREADS; i++)
    pthread_join(tid[i], NULL);
}

// ciascun thread inizia l'esecuzione da questa funzione
void *runner(void *param) {
  // fai qualcosa
  pthread_exit(0);
}