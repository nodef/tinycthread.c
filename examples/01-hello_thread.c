#include <stdio.h>
#define TINYCTHREAD_IMPLEMENTATION
#include <tinycthread.h>


int thread_func(void *arg) {
  char *msg = (char *)arg;
  printf("Thread says: %s\n", msg);
  return 0;
}


int main(void) {
  thrd_t t;
  char *msg = "Hello from the thread!";

  printf("Main: Creating thread...\n");
  if (thrd_create(&t, thread_func, msg) != thrd_success) {
    fprintf(stderr, "Error creating thread\n");
    return -1;
  }

  printf("Main: Waiting for thread to finish...\n");
  int res;
  if (thrd_join(t, &res) != thrd_success) {
    fprintf(stderr, "Error joining thread\n");
    return -1;
  }

  printf("Main: Thread finished with result code %d.\n", res);
  return 0;
}
