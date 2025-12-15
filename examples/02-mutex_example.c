#include <stdio.h>
#define TINYCTHREAD_IMPLEMENTATION
#include <tinycthread.h>

#define NUM_THREADS 5
#define ITERATIONS 10000

mtx_t mutex;
long shared_counter = 0;


int thread_func(void *arg) {
  int id = *(int *)arg;

  for (int i = 0; i < ITERATIONS; i++) {
    mtx_lock(&mutex);
    shared_counter++;
    mtx_unlock(&mutex);
  }

  return 0;
}


int main(void) {
  thrd_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];

  printf("Initializing mutex...\n");
  if (mtx_init(&mutex, mtx_plain) != thrd_success) {
    fprintf(stderr, "Could not create mutex\n");
    return -1;
  }

  printf("Spawning %d threads, each incrementing counter %d times...\n",
         NUM_THREADS, ITERATIONS);

  for (int i = 0; i < NUM_THREADS; ++i) {
    thread_ids[i] = i;
    if (thrd_create(&threads[i], thread_func, &thread_ids[i]) != thrd_success) {
      fprintf(stderr, "Error creating thread %d\n", i);
      return -1;
    }
  }

  printf("Waiting for threads to finish...\n");
  for (int i = 0; i < NUM_THREADS; ++i) {
    thrd_join(threads[i], NULL);
  }

  mtx_destroy(&mutex);

  long expected = (long)NUM_THREADS * ITERATIONS;
  printf("Final counter value: %ld\n", shared_counter);
  printf("Expected value:      %ld\n", expected);

  if (shared_counter == expected) {
    printf("Success! The counter matches the expected value.\n");
  } else {
    printf("Failure! Race condition occurred or logic error.\n");
  }

  return 0;
}
